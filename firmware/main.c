/*
* Copyright (C) 2014-2015 Phonobo
* This code is part of the Phonobo project
* Author: Marcus Drobisch (m.drobisch@googlemail.com)
* License: http://www.gnu.org/licenses/gpl.html GPL version 2 or higher
*/

/*
 * Phonobo is a open source, open hardware project for building a electronic keypad / synthesizer / sampler / music instrument.
 *
 * Board: STM32F429 Discovery Board
 * CPU: STM32F429
 * IDE: CooCox 1.7.7
 *
 * Addtional compiler settings:
 * Following settings have to be set "STM32F429_439xx" , "__ASSEMBLY__" , "USE_STDPERIPH_DRIVER"
 */


#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"

#include "phonobo.h"


int main(void)
{

	phonobo_init();

	phonobo_start();

	return 0;

}
