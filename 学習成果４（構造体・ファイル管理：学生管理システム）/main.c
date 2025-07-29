/* �w�K���ʂS�i�\���́A�t�@�C������F�w���Ǘ��V�X�e���j */

#include<stdio.h>
#include<string.h>

#define MAX_STUDENTS 100
#define NAME_LEN 50

/* �w�������Ǘ�����\���� */
typedef struct
{
	int id;
	char name[NAME_LEN];
	int age;
	int score;
}
Student;

int main()
{
	FILE *file;
	Student students[MAX_STUDENTS];
	int count = 0;
	int sum = 0;
	
	printf("=== �w�������̓V�X�e�� ===\n");
	printf("�w��������͂��Ă��������B\n");
	printf("�I������ꍇ�͖��O���Ɂuend�v�Ɠ��͂��Ă��������B\n\n");
	
	
/* �w�����̓��́i���I�j */
while(count < MAX_STUDENTS) {
	printf("\n �w��%d :\n", count + 1);
	students[count].id = count + 1;
	
	printf("���O:");
	scanf("%s", students[count].name);
	
	
	/* �I������ */
	if(strcmp(students[count].name, "end") == 0) {
		printf("���͂��I�����܂��B\n\n");
		break;
	}
	
	printf("�N��:");
	scanf("%d", &students[count].age);
	
	printf("�_��:");
	scanf("%d", &students[count].score);
	
	sum += students[count].score;
	count++;

}

/* ���͂��ꂽ�w�������Ȃ��ꍇ */
if(count == 0) {
	printf("�w���f-�^������܂���B\n");
	return 0;
}

/* ���ʕ\�� */
printf("\n=== ���͂��ꂽ�w����� ===\n");
for(int i = 0; i < count; i++) {
	printf("ID:%d %s (%d��) - %d�_\n",
		students[i].id, students[i].name,
		students[i].age, students[i].score);
}

float average = (float)sum / count;
printf("\n�o�^�w����: %d�l\n", count);
printf("���ϓ_: %.2f\n", average);


/* �t�@�C���o�� */
file = fopen("student_scores.txt", "w");
if(file != NULL) {
	fprintf(file, "=== �w�����шꗗ ===\n");
	fprintf(file, "�o�^�w����: %d�l\n\n", count);
	for(int i = 0; i < count; i++) {
		fprintf(file, "ID:%d %s(%d��) - %d �_\n",
		students[i].id, students[i].name,
		students[i].age, students[i].score);
	}
		fprintf(file, "\n���ϓ_: %.2f\n", average);
		fclose(file);
		printf("���ʂ��t�A�C���ɕۑ����܂����B\n");		/* �������̃@�̓_�������Ȃ��� */
}														/* �啶���̃A�ő�p���Ă��� */

return 0;

}