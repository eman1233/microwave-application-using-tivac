#include "keypad.h"


void delayUs(int n){
	int i,j;
	for(i=0;i<=n;i++){
	 for(j=0;j<=3;j++)
	 {}
 }
}
void keypad_row_init(void){
	SYSCTIL_GPIO |=0x01;
	GPIODEN_A |=(D0)|(D1)|(D2)|(D3);
	GPIODIR_A|=(D0)|(D1)|(D2)|(D3);
}

void keypad_coulnm_init(void){
	SYSCTIL_GPIO |=0x02;
	GPIODEN_B |=(D4)|(D5)|(D6)|(D7);
	GPIODIR_B&=~(unsigned long)((D4)|(D5)|(D6)|(D7));
}
unsigned char keypad_getkey(void){
   static unsigned char keymap[4][4] = {
    { '1', '2', '3', 'A'},
    { '4', '5', '6', 'B'},
    { '7', '8', '9', 'C'},
    { '*', '0', '#', 'D'},
  };
  static int r, c;

	GPIODATA_A&=~(unsigned long)((D0)|(D1)|(D2)|(D3));
	c=GPIODATA_B&((D4)|(D5)|(D6)|(D7));
  if (c == ((D4)|(D5)|(D6)|(D7)))
		return 0; 
 
  while (1){
    r = 0;
   GPIODATA_A = 0x0E; /* enable row 0 */
   delayUs(2); 
   c = GPIODATA_B&((D4)|(D5)|(D6)|(D7));
   if (c != ((D4)|(D5)|(D6)|(D7))) 
		 break;
 
   r = 1;
   GPIODATA_A= 0x0D; /* enable row 1 */
   delayUs(2); 
   c=GPIODATA_B&((D4)|(D5)|(D6)|(D7));
   if (c != ((D4)|(D5)|(D6)|(D7)))
		 break;
 
   r = 2;
   GPIODATA_A = 0x0B; /* enable row 2 */
   delayUs(2); 
   c=GPIODATA_B&((D4)|(D5)|(D6)|(D7));
   if (c != ((D4)|(D5)|(D6)|(D7))) 
		 break;
 
  r = 3;
  GPIODATA_A = 0x07; /* enable row 3 */
  delayUs(2); 
  c=GPIODATA_B&((D4)|(D5)|(D6)|(D7));
  if (c != ((D4)|(D5)|(D6)|(D7)))
		break;
  return 0;
}
 
 if (c == 0xE) 
	 return keymap[row][0]; 
 if (c== 0xD)
	 return keymap[row][1]; 
 if (c== 0xB)
	 return keymap[row][2]; 
 if (c == 0x7) 
	 return keymap[row][3]; 
 return 0;
}
unsigned char key(void){
	static int col;
	GPIODATA_A&=~(unsigned long)((D0)|(D1)|(D2)|(D3));
	col=GPIODATA_B&((D4)|(D5)|(D6)|(D7));
	if(col==((D4)|(D5)|(D6)|(D7)))
		return 0;
	else
		return 1;
}
