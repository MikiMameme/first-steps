/* テストの点数を配列で保存。平均点を計算して表示、テキストファイルで保存
適切な箇所に数字を入力し5人分の処理ができるようにした */
#include <stdio.h>

int main(){
	FILE *file;
	int scores[5];/* 5人分のデータ */
	for(int i = 0; i < 5; i++){
		file = fopen("scores.txt","w");
		printf("点数%d: ", i + 1);
		scanf("%d",&scores[i]);
	}
	int sum = 0;
	for(int i = 0; i < 5; i++) sum += scores[i];
	printf("平均： %.2f\n", (float)sum / 5);/* 平均点を表示 */
	fprintf(file,"平均： %.2f\n", (float)sum / 5); /* 平均点をテキストファイルに保存 */
	fclose(file);
	return 0;
}