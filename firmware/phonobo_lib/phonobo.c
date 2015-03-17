/*
* Copyright (C) 2014-2015 Phonobo
* This code is part of the Phonobo project
* Author: Marcus Drobisch (m.drobisch@googlemail.com)
* License: http://www.gnu.org/licenses/gpl.html GPL version 2 or higher
*/

#include "phonobo.h"

void Delay(volatile uint32_t nCount) {
  while(nCount--)
  {
  }
}

/*
 * Init phonob hardware modules, cpu and clock
 */
uint32_t phonobo_init_hardware()
{
	// init touch
	if(UB_Touch_Init() == 0) {
		return PHONOBO_ERROR_TOUCH_INIT_FAILED; // Touch error
	}

	// init systick from ub-lib
	UB_Systick_Init();

	// init leds from ub-lib
	UB_Led_Init();

	// init user-button from ub-lib
	UB_Button_Init();

	// init UART from ub-lib
	UB_Uart_Init();

	// init vom LCD and SD-RAM
	UB_LCD_Init();
	UB_LCD_LayerInit_Fullscreen();
	UB_LCD_SetMode(LANDSCAPE);
	phonobo_clear_lcd_mem_all();

	// init ADC
	ADC_Init_ALL();

	// init phonobo specific gpios
	phonobo_init_gpios();


	return PHONOBO_SUCCESS;
}

/*
 * Initialize software (
 */

uint32_t phonobo_init_software()
{


}

/*
 * Send string via uart
 */
void phonobo_send_uart(char *ptr)
{
  UB_Uart_SendString(COM1,ptr,CRLF);
}


/*
 * initialize phonobo and modules
 */
uint32_t phonobo_init(void)
{
	uint32_t result=0;

	SystemInit(); // setup microcontroller, clock and flash controller

	result = phonobo_init_hardware(); // init hardware
	phonobo_send_uart("OSZI 4 STM32F429 [UB]");
	if(result != PHONOBO_SUCCESS )
	{
	    UB_LCD_FillLayer(BACKGROUND_COL);
	    UB_Font_DrawString(10,10,"Err. while hardware init ERR",&Arial_7x10,FONT_COL,BACKGROUND_COL);
	    while(1);
	}

	phonobo_init_software();

    UB_LCD_FillLayer(BACKGROUND_COL);
    UB_Font_DrawString(10,10,"Yeah",&Arial_7x10,FONT_COL,BACKGROUND_COL);
    UB_Graphic2D_DrawFullRectDMA(50,50,24,24,RGB_COL_YELLOW);

    UB_Graphic2D_DrawFullRectDMA(50,150,48,48,RGB_COL_YELLOW);

    UB_Graphic2D_DrawFullRectDMA(150,150,64,64,RGB_COL_YELLOW);


	return PHONOBO_SUCCESS;
}

/*
 * Clear all memory buffers
 */
void phonobo_clear_lcd_mem_all(void)
{
  UB_LCD_SetLayer_2();
  UB_LCD_SetTransparency(255);
  UB_LCD_FillLayer(BACKGROUND_COL);
  UB_LCD_Copy_Layer2_to_Layer1();
  UB_LCD_SetLayer_Menu();
  UB_LCD_FillLayer(BACKGROUND_COL);
  UB_LCD_SetLayer_ADC();
  UB_LCD_FillLayer(BACKGROUND_COL);
  UB_LCD_SetLayer_Back();
}


/*
 * start phonobo mainloop
 */
void phonobo_start(void)
{
	while(1)
	{
		Delay(15000000);
		GPIOG->ODR ^= GPIO_Pin_13; // PG13 toggeln
	}

}

/*
 * Init the system / hardware
 */
void phonobo_init_gpios(void)
{

	GPIO_InitTypeDef GPIO_InitStructure;

	// Clock Enable
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOG, ENABLE);

	// Config PG13 als Digital-Ausgang
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOG, &GPIO_InitStructure);

}
