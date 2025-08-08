/*マスターマインド（演習4-2　ヒント機能付き）*/
/*新明解Ｃ言語 中級編　自由課題 演習4-2より*/

/*変更点*/
/*ヒント機能を追加*/
/*先頭の一文字ヒント give_hint_first()*/
/*ヒットした数字の最も先頭側  give_hint_hit()*/
/*ブローした数字の最も末尾側  give_hint_blow()*/
/*3回ごとの定期ヒント - give_periodic_hint()*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

/*相異なる4つの数字の並びを生成して配列xに格納*/
void make4digits(int x[])
{
	int i, j, val;
	for (i = 0; i < 4; i++) {
		do {
			val = rand() % 10;
			for (j = 0; j < i; j++)
				if (val == x[j])
					break;
		} while (j < i);
		x[i] = val;
	}
}

/*入力された文字列sの妥当性をチェック*/
int check(const char s[])
{
	int i, j;
	if (strlen(s) != 4)
		return 1;
	for (i = 0; i < 4; i++) {
		if (!isdigit(s[i]))
			return 2;
		for (j = 0; j < i; j++)
			if (s[i] == s[j])
				return 3;
	}
	return 0;
}

/*ヒットとブローの判定*/
void judge(const char s[], int no[], int* hit, int* blow)
{
	int i, j;
	*hit = *blow = 0;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (s[i] == '0' + no[j])
				if (i == j)
					(*hit)++;
				else
					(*blow)++;
		}
	}
}

/*判定結果を表示*/
void print_result(int snum, int spos)
{
	if (spos == 4)
		printf("正解です");
	else if (snum == 0)
		printf("     それらの数字は全く含まれません。\n");
	else {
		printf("    それらの数字中%d個の数字が含まれています。\n", snum);
		if (spos == 0)
			printf(" ただし位置もあっている数字はありません。\n");
		else
			printf(" その中に%d個は位置もあっています。\n", spos);
	}
	putchar('\n');
}

/*ヒント機能：先頭の一文字を教える*/
void give_hint_first(int no[])
{
	printf("ヒント: 先頭の数字は %d です\n", no[0]);
}

/*ヒント機能：ヒットした数字の最も先頭側を教える*/
void give_hint_hit(const char s[], int no[])
{
	int i;
	for (i = 0; i < 4; i++) {
		if (s[i] == '0' + no[i]) {
			printf("ヒント: %d番目の位置の数字 %d は正解です\n", i + 1, no[i]);
			return;
		}
	}
	printf("ヒント: まだヒットした数字がありません\n");
}

/*ヒント機能：ブローした数字の最も末尾側を教える*/
void give_hint_blow(const char s[], int no[])
{
	int i, j;
	for (i = 3; i >= 0; i--) {
		for (j = 0; j < 4; j++) {
			if (s[i] == '0' + no[j] && i != j) {
				printf("ヒント: 数字 %d は含まれますが、%d番目の位置ではありません\n", no[j], i + 1);
				return;
			}
		}
	}
	printf("ヒント: まだブローした数字がありません\n");
}

/*ヒント機能：3回ごとに定期的にヒントを与える*/
void give_periodic_hint(int try_no, int no[], const char last_input[])
{
	if (try_no % 3 == 0) {
		printf("\n--- %d回目なので、ヒントを差し上げます ---\n", try_no);

		switch ((try_no / 3) % 3) {
		case 1:  // 3回目
			give_hint_first(no);
			break;
		case 2:  // 6回目
			give_hint_hit(last_input, no);
			break;
		case 0:  // 9回目, 12回目...
			give_hint_blow(last_input, no);
			break;
		}
		printf("---------------------------------------\n\n");
	}
}

int main(void)
{
	int try_no = 0;
	int chk;
	int hit;
	int blow;
	int no[4];
	char buff[10];
	clock_t start, end;

	srand(time(NULL));
	puts("■　マスターマインドをしましょう。");
	puts("■　4つの数字の並びを当ててください。");
	puts("■　同じ数字が複数含まれることはありません。");
	puts("■　4307のように連続して入力してください。");
	puts("■　スペース文字などを入力してはいけません。");
	puts("■　3回ごとにヒントが出ます！");

	make4digits(no);
	start = clock();

	do {
		do {
			printf("入力してください:");
			scanf("%s", buff);
			chk = check(buff);
			switch (chk) {
			case 1: puts("\aきちんと４文字で入力してください。"); break;
			case 2: puts("\a数字以外の文字を入力しないでください。"); break;
			case 3: puts("\a同一の数字を複数入力しないでください。"); break;
			}
		} while (chk != 0);

		try_no++;
		judge(buff, no, &hit, &blow);
		print_result(hit + blow, hit);

		/* 3回ごとにヒントを表示 */
		if (hit < 4) {
			give_periodic_hint(try_no, no, buff);
		}

	} while (hit < 4);

	end = clock();
	printf("%d回かかりました。\n所要時間は%.1f秒でした。\n",
		try_no, (double)(end - start) / CLOCKS_PER_SEC);
	return 0;
}