#include <stdio.h>
#include <conio.h>

int main()
{
  int A[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int B[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

  asm
  {
    cld
    lea si, A
    lea di, B
    mov cx, 10
    rep movsw
  }

  for (int i = 0; i < 10; i++)
  {
    printf("\nA[i] = %d, B[i] = %d\n", A[i], B[i]);
  }
  getch();

  return 0;
}
