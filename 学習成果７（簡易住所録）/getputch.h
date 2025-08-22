/*getch/putch�p�̋��ʃw�b�_"getputch.h"*/

#ifndef __GETPUTCH

#define __GETPUTCH

#if defined(_MSC_VER) || (__TURBOC__) || (LSI_C)




/*MS-Windows/MS-DOS(Visual C++, Borland C++, LSI-C 86)*/
#include<conio.h>

static void init_getputch(void){ /* �� */ }
static void term_getputch(void){ /* �� */ }

#else




/*Curses���C�u�������񋟂����UNIX/LINUX/macOS*/

#include<curses.h>
#include<string.h>

#undef putchar
#undef puts
#undef printf
static char __buf[4096];

/*putchar: putchar�֐��Ɠ����i���s�����s�{���A�ŏo�́j*/
static int __putchar(int ch)
{
	if (ch == '\n')
		putchar('\r');
	return putchar(ch);
}

/*putch: 1�����\�����ăo�b�t�@��|���o��*/
static int putch(int ch)
{
	int result = putchar(ch);

	fflush(stdout);
	return result;
}

/*printf: printf�֐��Ɠ����i���s�����s�{���A�ŏo�́j*/
static int __printf(const char* format, ...)
{
	va_list ap;
	int count;

	va_start(ap, format);
	vsprintf(__buf, format, ap);
	va_end(ap);

	for (count = 0; __buf[count]; count++) {
		putchar(__buf[count]);
		if (__buf[count] == '\n')
			putchar('\r');
	}
	return count;
}

/*puts: puts�֐��Ɠ����i���s�����s�{���A�ŏo�́j*/
static int __puts(const char* s)
{
	int i, j;

	for (i = 0, j = 0; s[i]; i++) {
		__buf[j++] = s[i];
		if (s[i] == '\n')
			__buf[j++] = '\r';
	}
	return puts(__buf);
}

/*���C�u������������*/
static void init_getputch(void)
{
	initscr();
	cbreak();
	noecho();
	refresh();
}

/*���C�u�����I������*/
static void term_getputch(void)
{
	endwin();
}

#define putchar __putchar
#define printf __printf
#define puts __puts
#endif
#endif