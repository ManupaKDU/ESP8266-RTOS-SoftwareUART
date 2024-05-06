#include "softuart.h"
#include <stdio.h>
#include <sys/fcntl.h>
#include <sys/errno.h>
#include <sys/unistd.h>
#include <sys/select.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "esp_vfs.h"
#include "esp_vfs_dev.h"
#include "driver/uart.h"


// Define the pins you'll use for Soft UART
#define RX_PIN 4
#define TX_PIN 5

void app_main(){
  // Initialize Soft UART with a baud rate of 9600
  if (softuart_open(0, 74880, RX_PIN, TX_PIN, false) == false) {
    // Handle initialization error here
    return;
  }


while (1)
{

  // Send a message
  softuart_puts(0, "Hello from Soft UART!\n");

  // Check for received data
  if (softuart_available(0)) {
    char c = softuart_read(0);
    // Process the received byte here
    // For example, print it to the serial monitor:
    // Serial.print(c);
    // ESP_LOGI("SOFTUART", "Data entered: %c", c);
    printf("%c",c);
  }
  else
  {
    //Uncomment this or Fix it or something
    //ESP_LOGI("SOFTUART", "Cannot Contact with UART");
    
    }

  // Optionally add a delay to avoid overwhelming the receiver
  // delay(100);
  // vTaskDelay(500 / portTICK_PERIOD_MS);
}
}
