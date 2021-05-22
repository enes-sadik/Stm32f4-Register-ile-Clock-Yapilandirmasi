#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

void RCC_Config(void)
{
	RCC->CR &= 0x00000083;          // CR RESET

	RCC->CR |= 1<<16;               // HSE ON
	while(!(RCC->CR & (1 << 17)));  // Wait HSE active
	RCC->CR |= 1<<19; 			    // CSS ON

	RCC->PLLCFGR =0x00000000;       // PLLCFGR Reset - PLL P = 2
	RCC->PLLCFGR |= (1 << 22);      // PLL Source HSE
	RCC->PLLCFGR |= (4 << 0);       // PLL M = 4
	RCC->PLLCFGR |= (168 << 6);     // PLL N = 168

	RCC->CR |= 1<<24;               // PLL ON
	while(!(RCC->CR & (1 << 25)));  // Wait PLL active

	RCC->CFGR &= ~(1 << 0);
	RCC->CFGR |= (1 << 1);          // System Clock is PLL

	while(!(RCC->CFGR & (1 << 1))); // Select system clock is pll clock
	// 8 000 000 -> 168 000 000
}

int main(void)
{
	RCC_Config();

	SystemCoreClockUpdate();

	systemClock = SystemCoreClock;
  while (1)
  {

  }
}


void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size){
  /* TODO, implement your code here */
  return;
}

/*
 * Callback used by stm324xg_eval_audio_codec.c.
 * Refer to stm324xg_eval_audio_codec.h for more info.
 */
uint16_t EVAL_AUDIO_GetSampleCallBack(void){
  /* TODO, implement your code here */
  return -1;
}
