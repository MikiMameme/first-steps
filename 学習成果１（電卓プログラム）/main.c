/* 電卓プログラム　ChatGPTより　乗算除算ができるように改良しました */
#include <stdio.h>

void calc(int a,int b,char op){
	if(op == '+') printf("%d\n",a + b);
	else if(op == '-') printf("%d\n",a - b);
	else if(op == '*') printf("%d\n",a * b); /* 乗算ができるように改良しました */
	else if(op == '/') printf("%d\n",a / b); /* 除算ができるように改良しました */
}

int main(){
	int a,b;
	char op;
	printf("数字　演算子　数字　の順で入力(注意：小数点はできません)　例：1 + 1 ： "); /* 説明文をわかりやすく改良しました */
	scanf("%d %c %d", &a, &op, &b);
	calc(a, b, op);
	return 0;
}