/* �e�X�g�̓_����z��ŕۑ��B���ϓ_���v�Z���ĕ\���A�e�L�X�g�t�@�C���ŕۑ�
�K�؂ȉӏ��ɐ�������͂�5�l���̏������ł���悤�ɂ��� */
#include <stdio.h>

int main(){
	FILE *file;
	int scores[5];/* 5�l���̃f�[�^ */
	for(int i = 0; i < 5; i++){
		file = fopen("scores.txt","w");
		printf("�_��%d: ", i + 1);
		scanf("%d",&scores[i]);
	}
	int sum = 0;
	for(int i = 0; i < 5; i++) sum += scores[i];
	printf("���ρF %.2f\n", (float)sum / 5);/* ���ϓ_��\�� */
	fprintf(file,"���ρF %.2f\n", (float)sum / 5); /* ���ϓ_���e�L�X�g�t�@�C���ɕۑ� */
	fclose(file);
	return 0;
}