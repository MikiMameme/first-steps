/* 読み込んだ月の季節と陰暦を表示 */
/* ダメ文字対策のため、2月は「きさらぎ」と表示している */

#include<stdio.h>

int main(void)
{
	int month;
	
	printf("何月ですか :");
	scanf("%d", &month);
	
														/* 季節を表示 */
	if(month >= 3 && month <= 5)
		printf("%d月は春です。\n", month);
	else if(month >= 6 && month <= 8)
		printf("%d月は夏です。\n", month);
	else if(month >= 9 && month <= 11)
		printf("%d月は秋です。\n", month);
	else if(month == 1 || month == 2 || month == 12)
		printf("%d月は冬です。\n", month);
	else {
		printf("%d月はありませんよ！！\a\n", month);
		return 0; 										/* エラーの場合はここで終了 */
	}
	
														/* 陰暦を表示 */
	printf("陰暦では");
	switch(month) {
	case 1:
		printf("睦月");
		break;
	case 2:
		printf("きさらぎ");		/* ダメ文字対策のため、2月は「きさらぎ」と表示している */
		break;
	case 3:
		printf("弥生");
		break;
	case 4:
		printf("卯月");
		break;
	case 5:
		printf("皐月");
		break;
	case 6:
		printf("水無月");
		break;
	case 7:
		printf("文月");
		break;
	case 8:
		printf("葉月");
		break;
	case 9:
		printf("長月");
		break;
	case 10:
		printf("神無月");
		break;
	case 11:
		printf("霜月");
		break;
	case 12:
		printf("師走");
		break;
	}
	printf("です。\n");
	
	return 0;
}