/*
* Copyright (C) 2014-2015 Phonobo
* This code is part of the Phonobo project
* Author: Marcus Drobisch (m.drobisch@googlemail.com)
* License: http://www.gnu.org/licenses/gpl.html GPL version 2 or higher
*/

#ifndef __PHONOBO_H
#define __PHONOBO_H

#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"

// iclude ub_lib
#include "stm32_ub_led.h"
#include "stm32_ub_lcd_ili9341.h"
#include "stm32_ub_graphic2d.h"
#include "stm32_ub_font.h"
#include "stm32_ub_touch_stmpe811.h"
#include "stm32_ub_systick.h"
#include "stm32_ub_uart.h"
#include "stm32_ub_button.h"
/*
 * prototypes for global used functions
 */
void phonobo_start(void);
uint32_t phonobo_init(void);
void phonobo_clear_mem_all(void);

/*
 * defines for result error-codes
 */

#define PHONOBO_SUCCESS							0
#define PHONOBO_ERROR_GPIO_INIT_FAILED			1
#define PHONOBO_ERROR_TOUCH_INIT_FAILED			2
#define PHONOBO_ERROR_LCD_INIT_FAILED			3


/*
 * color defines
 */

#define  BACKGROUND_COL     RGB_COL_BLACK  // Farbe vom Hintergrund
#define  FONT_COL           RGB_COL_BLUE   // (debug Schriftfarbe)
#define  ADC_CH1_COL        RGB_COL_CYAN   // Farbe von Kanal-1
#define  ADC_CH2_COL        RGB_COL_YELLOW // Faebe von Kanal-2
#define  SCALE_COL          RGB_COL_GREY   // Farbe vom Oszi-Gitter
#define  CURSOR_COL         RGB_COL_GREEN  // Farbe vom Cursor
#define  FFT_COL            RGB_COL_MAGENTA  // Farbe der FFT





#endif
