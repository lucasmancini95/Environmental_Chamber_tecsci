#include <stdio.h>
#include "esp_wifi.h"
#include "esp_system.h"
#include "nvs_flash.h"
#include "esp_event_loop.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_log.h"
#include "esp_websocket_client.h"
#include "esp_event.h"
#include "esp_event_loop.h"
#include "esp_system.h"
#include "esp_spi_flash.h"


#include "lwip/err.h"
#include "lwip/sockets.h"
#include "lwip/sys.h"
#include <lwip/netdb.h>


#include "driver/spi_master.h"
#include "soc/gpio_struct.h"
#include "driver/gpio.h"

#include "include/app_main.h"

//#define PORT CONFIG_EXAMPLE_PORT
#define PORT 3333
//todo: porque no lo toma del archivo sdkconfig
#define CONFIG_EXAMPLE_IPV4

spi_device_handle_t  spi_dev;
static const char *TAG = "example";

//ENVIRONMENTAL CHAMBER commands:
	static tinysh_cmd_t commandINITENVIRONMENTALCHAMBER = 						{NULL,"INIT_EC", NULL, NULL,  CommandINITENVIRONMENTALCHAMBERHandler, NULL, NULL, NULL};
	static tinysh_cmd_t commandRUNENVIRONMENTALCHAMBER = 						{NULL,"RUN_EC", NULL, NULL,  CommandRUNENVIRONMENTALCHAMBERHandler, NULL, NULL, NULL};
	static tinysh_cmd_t commandSTOPENVIRONMENTALCHAMBER = 						{NULL,"STOP_EC", NULL, NULL, CommandSTOPENVIRONMENTALCHAMBERHandler, NULL, NULL, NULL};
	static tinysh_cmd_t commandSETRH = 						{NULL,"SETRH", NULL, NULL, CommandSETRHHandler, NULL, NULL, NULL};
	static tinysh_cmd_t commandSETTEMP = 					{NULL,"SETTEMP", NULL, NULL, CommandSETTEMPHandler, NULL, NULL, NULL};
	static tinysh_cmd_t commandACTIVATEENVIRONMENTALCHAMBER ={NULL,"ACTIVATE_EC", NULL, NULL, CommandACTIVATEENVIRONMENTALCHAMBERHandler, NULL, NULL, NULL};
	static tinysh_cmd_t commandDEACTIVATEENVIRONMENTALCHAMBER ={NULL,"DEACTIVATE_EC", NULL, NULL, CommandDEACTIVATEENVIRONMENTALCHAMBERHandler, NULL, NULL, NULL};
	static tinysh_cmd_t commandMONITORENVIRONMENTALCHAMBER = 						{NULL,"MONITOR_EC", NULL, NULL, CommandMONITORENVIRONMENTALCHAMBERHandler, NULL, NULL, NULL};

void xtasktinysh(void *pvParameter) {

//	static char c = 0;
	char c = 0;
	tinysh_init();

//command initialization
	tinysh_add_command(&commandINITENVIRONMENTALCHAMBER);
	tinysh_add_command(&commandRUNENVIRONMENTALCHAMBER);
	tinysh_add_command(&commandSTOPENVIRONMENTALCHAMBER);
	tinysh_add_command(&commandSETRH);
	tinysh_add_command(&commandSETTEMP);
	tinysh_add_command(&commandACTIVATEENVIRONMENTALCHAMBER);
	tinysh_add_command(&commandDEACTIVATEENVIRONMENTALCHAMBER);
	tinysh_add_command(&commandMONITORENVIRONMENTALCHAMBER);


	while (1) {
		c = getchar();
		//Para que no devuelva basura por la consola
		if (c != 0xFF){
		tinysh_char_in(c);
		}
		vTaskDelay(20 / portTICK_RATE_MS);
	}
}

static void tcp_server_task(void *pvParameters)
{
    char rx_buffer[128];
    char addr_str[128];
    int addr_family;
    int ip_protocol;
    int i;

    while (1) {

#ifdef CONFIG_EXAMPLE_IPV4
        struct sockaddr_in dest_addr;
        dest_addr.sin_addr.s_addr = htonl(INADDR_ANY);
        dest_addr.sin_family = AF_INET;
        dest_addr.sin_port = htons(PORT);
        addr_family = AF_INET;
        ip_protocol = IPPROTO_IP;
        inet_ntoa_r(dest_addr.sin_addr, addr_str, sizeof(addr_str) - 1);
#else 	//IPV6
        struct sockaddr_in6 dest_addr;
        bzero(&dest_addr.sin6_addr.un, sizeof(dest_addr.sin6_addr.un));
        dest_addr.sin6_family = AF_INET6;
        dest_addr.sin6_port = htons(PORT);
        addr_family = AF_INET6;
        ip_protocol = IPPROTO_IPV6;
        inet6_ntoa_r(dest_addr.sin6_addr, addr_str, sizeof(addr_str) - 1);
#endif

        int listen_sock = socket(addr_family, SOCK_STREAM, ip_protocol);
        if (listen_sock < 0) {
            ESP_LOGE(TAG, "Unable to create socket: errno %d", errno);
            break;
        }
        ESP_LOGI(TAG, "Socket created");

        int err = bind(listen_sock, (struct sockaddr *)&dest_addr, sizeof(dest_addr));
        if (err != 0) {
            ESP_LOGE(TAG, "Socket unable to bind: errno %d", errno);
            break;
        }
        ESP_LOGI(TAG, "Socket bound, port %d", PORT);

        err = listen(listen_sock, 1);
        if (err != 0) {
            ESP_LOGE(TAG, "Error occurred during listen: errno %d", errno);
            break;
        }
        ESP_LOGI(TAG, "Socket listening");

        struct sockaddr_in6 source_addr; // Large enough for both IPv4 or IPv6
        uint addr_len = sizeof(source_addr);
//        int sock = accept(listen_sock, (struct sockaddr *)&source_addr, &addr_len);
//        int sock_global = accept(listen_sock, (struct sockaddr *)&source_addr, &addr_len);

        sock_global = accept(listen_sock, (struct sockaddr *)&source_addr, &addr_len);
        if (sock_global < 0) {
            ESP_LOGE(TAG, "Unable to accept connection: errno %d", errno);
            break;
        }
        ESP_LOGI(TAG, "Socket accepted");

        while (1) {


        	//int len = recv(sock, rx_buffer, sizeof(rx_buffer) - 1, 0);
        	int len = recv(sock_global, rx_buffer, sizeof(rx_buffer) - 1, 0);

        	// Error occurred during receiving
            if (len < 0) {
                ESP_LOGE(TAG, "recv failed: errno %d", errno);
                break;
            }
            // Connection closed
            else if (len == 0) {
                ESP_LOGI(TAG, "Connection closed");
                break;
            }
            // Data received
            else {
                // Get the sender's ip address as string
                if (source_addr.sin6_family == PF_INET) {
                    inet_ntoa_r(((struct sockaddr_in *)&source_addr)->sin_addr.s_addr, addr_str, sizeof(addr_str) - 1);
                } else if (source_addr.sin6_family == PF_INET6) {
                    inet6_ntoa_r(source_addr.sin6_addr, addr_str, sizeof(addr_str) - 1);
                }

                rx_buffer[len] = 0; // Null-terminate whatever we received and treat like a string
                ESP_LOGI(TAG, "Received %d bytes from %s:", len, addr_str);
                ESP_LOGI(TAG, "%s", rx_buffer);

                for (i=0;i<len;i++){
                tinysh_char_in(rx_buffer[i]);
                }
                //Para que  valide lo recibido!
                tinysh_char_in('\n');

                //test para devolucion de datos -- devuelvo un dato de la estructura del proceso , el index
                int err = send(sock_global, rx_buffer, len, 0);


                if (err < 0) {
                    ESP_LOGE(TAG, "Error occurred during sending: errno %d", errno);
                    break;
                }
            }
        }

        if (sock_global != -1) {
            ESP_LOGE(TAG, "Shutting down socket and restarting...");
            shutdown(sock_global, 0);
            close(sock_global);

            ////FIX sacado de internet  https://www.esp32.com/viewtopic.php?t=10335
            shutdown(listen_sock,0);
            close(listen_sock);
            vTaskDelay(5);

        }
    }
    vTaskDelete(NULL);
}

void xtaskenvironmentalchamber(void *pvParameter) {
	environmental_chamber_monitor_data_t data;

	EnvironmentalChamberInit(&environmentalChamber);

	data.actualRH=0x33;
	data.actualTemp=0x33;
	data.RH_control_state=CHAMBER_STOPPED;
	data.TEMP_control_state=CHAMBER_STOPPED;
	data.targetRH=environmentalChamber.targetRH;
	data.targetTemp=environmentalChamber.targetTemp;

	while (1) {

		//Monitor of the Environmetal Chamber
		EnvironmentalChamberMonitor(&environmentalChamber);

		if (xQueueReceive( xQueue_Environmental_Chamber_Monitor, &data, portMAX_DELAY) == pdTRUE ){
				 printf("datos a transmitir por socket:\n");
				 printf("actual RH= %f \n",data.actualRH);
				 printf("actual Temp= %f \n",data.actualTemp);
				 printf("target RH= %f \n",data.targetRH);
				 printf("target Temp= %f \n",data.targetTemp);
				 send(sock_global, &(data.actualRH), sizeof(double), 0);
				 send(sock_global, &(data.actualTemp), sizeof(double), 0);
				 send(sock_global, &(data.targetRH), sizeof(double), 0);
				 send(sock_global, &(data.targetTemp), sizeof(double), 0);
				 //send(sock_global, &(data.RH_control_state), sizeof(int), 0);
				 //send(sock_global, &(data.TEMP_control_state), sizeof(int), 0);
		}

		vTaskDelay(10000 / portTICK_RATE_MS);

	}
}



void app_main(void) {

	ESP_ERROR_CHECK(nvs_flash_init());
	tcpip_adapter_init();
	ESP_ERROR_CHECK(esp_event_loop_create_default());
	ESP_ERROR_CHECK(example_connect());

	xTaskCreate(&xtasktinysh, "Tinysh Task", 16384, NULL, 2, NULL);
	xTaskCreate(tcp_server_task, "tcp_server", 4096, NULL, 2, NULL);
	xTaskCreate(&xtaskenvironmentalchamber, "Environmental Chamber Task", 16384, NULL, 2, NULL);

}
