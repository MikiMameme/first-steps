/* 教訓：Cでぬるぽは危険 */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void segfault_handler(int sig) 
{
    printf("ガッ！\n");
    exit(1);
}

int main(void) 
{
    signal(SIGSEGV, segfault_handler);
    
    int *p = NULL;
    *p = 42;			/* ぬるぽ発生！セグメンテーション違反 */
    
    return 0;
}