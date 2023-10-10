#include <stdio.h>
#include <conio.h>

int main()
{
  int far * pA = (int *)0xB8000000;
  int far * pB = (int *)0xB9000000;

  asm
  {
    cld
    lds si, pA
    les di, pB
    mov cx, 128
    rep movsw
  }
  
  getch();

  return 0;
}
