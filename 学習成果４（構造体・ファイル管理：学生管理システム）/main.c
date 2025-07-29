/* 学習成果４（構造体、ファイル操作：学生管理システム） */

#include<stdio.h>
#include<string.h>

#define MAX_STUDENTS 100
#define NAME_LEN 50

/* 学生情報を管理する構造体 */
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
	
	printf("=== 学生情報入力システム ===\n");
	printf("学生情報を入力してください。\n");
	printf("終了する場合は名前欄に「end」と入力してください。\n\n");
	
	
/* 学生情報の入力（動的） */
while(count < MAX_STUDENTS) {
	printf("\n 学生%d :\n", count + 1);
	students[count].id = count + 1;
	
	printf("名前:");
	scanf("%s", students[count].name);
	
	
	/* 終了判定 */
	if(strcmp(students[count].name, "end") == 0) {
		printf("入力を終了します。\n\n");
		break;
	}
	
	printf("年齢:");
	scanf("%d", &students[count].age);
	
	printf("点数:");
	scanf("%d", &students[count].score);
	
	sum += students[count].score;
	count++;

}

/* 入力された学生がいない場合 */
if(count == 0) {
	printf("学生デ-タがありません。\n");
	return 0;
}

/* 結果表示 */
printf("\n=== 入力された学生情報 ===\n");
for(int i = 0; i < count; i++) {
	printf("ID:%d %s (%d歳) - %d点\n",
		students[i].id, students[i].name,
		students[i].age, students[i].score);
}

float average = (float)sum / count;
printf("\n登録学生数: %d人\n", count);
printf("平均点: %.2f\n", average);


/* ファイル出力 */
file = fopen("student_scores.txt", "w");
if(file != NULL) {
	fprintf(file, "=== 学生成績一覧 ===\n");
	fprintf(file, "登録学生数: %d人\n\n", count);
	for(int i = 0; i < count; i++) {
		fprintf(file, "ID:%d %s(%d歳) - %d 点\n",
		students[i].id, students[i].name,
		students[i].age, students[i].score);
	}
		fprintf(file, "\n平均点: %.2f\n", average);
		fclose(file);
		printf("結果をフアイルに保存しました。\n");		/* 小文字のァはダメ文字なため */
}														/* 大文字のアで代用している */

return 0;

}