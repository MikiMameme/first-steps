/* �ǂݍ��񂾌��̋G�߂ƉA���\�� */
/* �_�������΍�̂��߁A2���́u�����炬�v�ƕ\�����Ă��� */

#include<stdio.h>

int main(void)
{
	int month;
	
	printf("�����ł��� :");
	scanf("%d", &month);
	
														/* �G�߂�\�� */
	if(month >= 3 && month <= 5)
		printf("%d���͏t�ł��B\n", month);
	else if(month >= 6 && month <= 8)
		printf("%d���͉Ăł��B\n", month);
	else if(month >= 9 && month <= 11)
		printf("%d���͏H�ł��B\n", month);
	else if(month == 1 || month == 2 || month == 12)
		printf("%d���͓~�ł��B\n", month);
	else {
		printf("%d���͂���܂����I�I\a\n", month);
		return 0; 										/* �G���[�̏ꍇ�͂����ŏI�� */
	}
	
														/* �A���\�� */
	printf("�A��ł�");
	switch(month) {
	case 1:
		printf("�r��");
		break;
	case 2:
		printf("�����炬");		/* �_�������΍�̂��߁A2���́u�����炬�v�ƕ\�����Ă��� */
		break;
	case 3:
		printf("�퐶");
		break;
	case 4:
		printf("�K��");
		break;
	case 5:
		printf("�H��");
		break;
	case 6:
		printf("������");
		break;
	case 7:
		printf("����");
		break;
	case 8:
		printf("�t��");
		break;
	case 9:
		printf("����");
		break;
	case 10:
		printf("�_����");
		break;
	case 11:
		printf("����");
		break;
	case 12:
		printf("�t��");
		break;
	}
	printf("�ł��B\n");
	
	return 0;
}