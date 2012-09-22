/*
* Interrupt vector implementations go here. Just add any you need.
* A full list of possible vectors is in lib/CMSIS_CM3/startup/gcc/stm32f10x_*.s
* You can also put the interrupt vector anywhere that gets compiled in,
* including one source file per interrupt, in main.c, etc. Be sure to keep
* the ones listed here, though.
*/

#include "interrupts.h"

#ifndef STM32F10X_CL
void USB_LP_CAN1_RX0_IRQHandler(void);
#endif /* STM32F10X_CL */

#ifdef STM32F10X_CL
void OTG_FS_IRQHandler(void);
#endif /* STM32F10X_CL */


/* The following interrupts should be present, though you can of course
 * modify them as required.
 */

void NMI_Handler(void) {
}

void HardFault_Handler(void) {
	/* Go to infinite loop when Hard Fault exception occurs */
	while (1);
}


void MemManage_Handler(void) {
	/* Go to infinite loop when Memory Manage exception occurs */
	while (1);
}

void BusFault_Handler(void) {
	/* Go to infinite loop when Bus Fault exception occurs */
	while (1);
}

void UsageFault_Handler(void) {
	/* Go to infinite loop when Usage Fault exception occurs */
	while (1);
}

void SVC_Handler(void) {
}

void DebugMon_Handler(void) {
}

void PendSV_Handler(void) {
}

void SysTick_Handler(void) {
}

#ifndef STM32F10X_CL
/*******************************************************************************
* Function Name  : USB_IRQHandler
* Description    : This function handles USB Low Priority interrupts
*                  requests.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
#if defined(STM32L1XX_MD) || defined(STM32L1XX_HD)|| defined(STM32L1XX_MD_PLUS)
void USB_LP_IRQHandler(void)
#else
void USB_LP_CAN1_RX0_IRQHandler(void)
#endif
{
  USB_Istr();
}
#endif /* STM32F10X_CL */

#ifdef STM32F10X_CL
/*******************************************************************************
* Function Name  : OTG_FS_IRQHandler
* Description    : This function handles USB-On-The-Go FS global interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void OTG_FS_IRQHandler(void)
{
  STM32_PCD_OTG_ISR_Handler(); 
}
#endif /* STM32F10X_CL */
