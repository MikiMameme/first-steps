/* ���P�FC�łʂ�ۂ͊댯 */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void segfault_handler(int sig) 
{
    printf("�K�b�I\n");
    exit(1);
}

int main(void) 
{
    signal(SIGSEGV, segfault_handler);
    
    int *p = NULL;
    *p = 42;			/* �ʂ�۔����I�Z�O�����e�[�V�����ᔽ */
    
    return 0;
}