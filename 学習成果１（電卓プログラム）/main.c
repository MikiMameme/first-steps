/* �d��v���O�����@ChatGPT���@��Z���Z���ł���悤�ɉ��ǂ��܂��� */
#include <stdio.h>

void calc(int a,int b,char op){
	if(op == '+') printf("%d\n",a + b);
	else if(op == '-') printf("%d\n",a - b);
	else if(op == '*') printf("%d\n",a * b); /* ��Z���ł���悤�ɉ��ǂ��܂��� */
	else if(op == '/') printf("%d\n",a / b); /* ���Z���ł���悤�ɉ��ǂ��܂��� */
}

int main(){
	int a,b;
	char op;
	printf("�����@���Z�q�@�����@�̏��œ���(���ӁF�����_�͂ł��܂���)�@��F1 + 1 �F "); /* ���������킩��₷�����ǂ��܂��� */
	scanf("%d %c %d", &a, &op, &b);
	calc(a, b, op);
	return 0;
}