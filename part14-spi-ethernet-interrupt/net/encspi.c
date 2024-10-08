#include "../include/spi.h"

void ENC_SPI_Select(unsigned char truefalse) {
    spi_chip_select(!truefalse); // If it's true, select 0 (the ENC), if false, select 1 (i.e. deselect the ENC)
}

void ENC_SPI_SendBuf(unsigned char *server2client, unsigned char *client2server, unsigned short bufferSize) {
    spi_chip_select(0);
    spi_send_recv(server2client, client2server, bufferSize);
    spi_chip_select(1); // De-select the ENC
}

void ENC_SPI_Send(unsigned char command) {
    spi_chip_select(0);
    spi_send(&command, 1);
    spi_chip_select(1); // De-select the ENC
}

void ENC_SPI_SendWithoutSelection(unsigned char command) {
    spi_send(&command, 1);
}
