#include "st7796.h"

#include "gpio.h"
#include "spi.h"
#include "rtos.h"

static void 
st7796_send_byte(uint8_t data) {
	spi_send_byte(data);
}

static void
writecommand(uint8_t data) {
	LL_GPIO_ResetOutputPin(DC_GPIO_Port, DC_Pin);
	st7796_send_byte(data);
}

static void
writedata(uint8_t data) {
	LL_GPIO_SetOutputPin(DC_GPIO_Port, DC_Pin);
	st7796_send_byte(data);
}

static void 
st7796_send_multiple_data(uint8_t *data, uint32_t num) {
	LL_GPIO_SetOutputPin(DC_GPIO_Port, DC_Pin);

	for (uint32_t i = 0; i < num; i++) {
		writedata(*data);
		data++;
	}
}

void
st7796_init() {
	LL_GPIO_ResetOutputPin(CS_GPIO_Port, CS_Pin);

	LL_GPIO_SetOutputPin(RST_GPIO_Port, RST_Pin);
	vTaskDelay(5);
	LL_GPIO_ResetOutputPin(RST_GPIO_Port, RST_Pin);
	vTaskDelay(100);
	LL_GPIO_SetOutputPin(RST_GPIO_Port, RST_Pin);
	vTaskDelay(50);

	writecommand(0x11);
	vTaskDelay(120);

	writecommand(0x36);
	writedata(0x48);

	writecommand(0x3A);
	writedata(0x55);

	writecommand(0xF0);
	writedata(0xC3);

	writecommand(0xF0);
	writedata(0x96);

	writecommand(0xB4);
	writedata(0x01);

	writecommand(0xB7);
	writedata(0xC6);

	writecommand(0xC0);
	writedata(0x80);
	writedata(0x45);

	writecommand(0xC1);
	writedata(0x13);

	writecommand(0xC2);
	writedata(0xA7);

	writecommand(0xC5);
	writedata(0x0A);

	writecommand(0xE8);
	writedata(0x40);
	writedata(0x8A);
	writedata(0x00);
	writedata(0x00);
	writedata(0x29);
	writedata(0x19);
	writedata(0xA5);
	writedata(0x33);

	writecommand(0xE0);
	writedata(0xD0);
	writedata(0x08);
	writedata(0x0F);
	writedata(0x06);
	writedata(0x06);
	writedata(0x33);
	writedata(0x30);
	writedata(0x33);
	writedata(0x47);
	writedata(0x17);
	writedata(0x13);
	writedata(0x13);
	writedata(0x2B);
	writedata(0x31);

	writecommand(0xE1);
	writedata(0xD0);
	writedata(0x0A);
	writedata(0x11);
	writedata(0x0B);
	writedata(0x09);
	writedata(0x07);
	writedata(0x2F);
	writedata(0x33);
	writedata(0x47);
	writedata(0x38);
	writedata(0x15);
	writedata(0x16);
	writedata(0x2C);
	writedata(0x32);


	writecommand(0xF0);
	writedata(0x3C);

	writecommand(0xF0);
	writedata(0x69);

	vTaskDelay(120);

	writecommand(0x21);

	writecommand(0x29);


	writecommand(0x36);
	writedata((1<<3)|(1<<5));

	LL_GPIO_ResetOutputPin(CS_GPIO_Port, CS_Pin);

	writecommand(0x2A);
	writedata(0>>8);
	writedata(0x00FF&0);
	writedata(479>>8);
	writedata(0x00FF&479);

	writecommand(0x2B);
	writedata(0);
	writedata(0x00FF&0);
	writedata(319>>8);
	writedata(0x00FF&319);

	writecommand(0x2C);	


	for (uint32_t m=0;m<320*480;m++) {
		writedata(0x00);
		writedata(0x00);
	}
	LL_GPIO_SetOutputPin(CS_GPIO_Port, CS_Pin);
}

static void 
swap_bytes(uint8_t *s, int32_t l) {
	uint8_t v;
	while (l > 0) {
		v = *(s+1);
		*(s+1) = *s;
		*s = v;
		s += 2;
		l -= 2;
	}
}

void 
st7796_draw(uint8_t* pixels, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2) {
	LL_GPIO_ResetOutputPin(CS_GPIO_Port, CS_Pin);
	writecommand(0x2A);
	writedata(x1>>8);
	writedata(0x00FF&x1);
	writedata(x2>>8);
	writedata(0x00FF&x2);

	writecommand(0x2B);
	writedata(y1>>8);
	writedata(0x00FF&y1);
	writedata(y2>>8);
	writedata(0x00FF&y2);

	writecommand(0x2C);

	LL_GPIO_SetOutputPin(DC_GPIO_Port, DC_Pin);
	swap_bytes(pixels,(x2-x1+1)*(y2-y1+1)*2);
	st7796_send_multiple_data(pixels, (x2-x1+1)*(y2-y1+1)*2);
}

void 
st7796_draw_dma(uint8_t* pixels, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2) {
	LL_GPIO_ResetOutputPin(CS_GPIO_Port, CS_Pin);
	writecommand(0x2A);
	writedata(x1>>8);
	writedata(0x00FF&x1);
	writedata(x2>>8);
	writedata(0x00FF&x2);

	writecommand(0x2B);
	writedata(y1>>8);
	writedata(0x00FF&y1);
	writedata(y2>>8);
	writedata(0x00FF&y2);

	writecommand(0x2C);

	LL_GPIO_SetOutputPin(DC_GPIO_Port, DC_Pin);
	swap_bytes(pixels,(x2-x1+1)*(y2-y1+1)*2);
	spi_send_dma(pixels,(x2-x1+1)*(y2-y1+1)*2);
}
