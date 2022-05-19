/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */
#include <stdio.h>
#include <stdint.h>

/* This function execute in THREAD MODE of the processor */
void generate_interrupt()
{
	uint32_t *pSTIR = (uint32_t*)0xE000EF00; //Here I'm trigerring some software interrupt by accessing system level registers of the ARM Cortex M processor which are mapped at these addresses
	uint32_t *pISER0 = (uint32_t*)0xE000E100;

	//enable IRQ3 interrupt
	*pISER0 |= ( 1 << 3);

	//generate an interrupt from software for IRQ3
	*pSTIR = (3 & 0x1FF); //triggering an interrupt and then interrupt handler will be executed and that interrupt will be executed at 48th line of the code
}

/* This function executes in THREAD MODE of the processor */
int main(void)
{
    printf("In thread mode: before interrupt\n");

    generate_interrupt();

    printf("In thread mode: after interrupt\n");

	for(;;);
}

/* This function(ISR) executes in HANDLER MODE of the processor */
void RTC_WKUP_IRQHandler(void)
{
	printf("In handler mode : ISR\n");
}
