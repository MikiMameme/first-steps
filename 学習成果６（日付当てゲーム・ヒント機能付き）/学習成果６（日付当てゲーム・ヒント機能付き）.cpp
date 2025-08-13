/*学習成果６：日付当てゲーム・ヒント機能付き*/

#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* 各月の日数 */
int mday[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

/* うるう年判定 */
int is_leap(int year) {
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

/* 指定年月の日数 */
int monthdays(int year, int month) {
    if (month-- != 2) return mday[month];
    return mday[month] + is_leap(year);
}

/* 曜日計算（0:日曜 ～ 6:土曜） */
int dayofweek(int year, int month, int day) {
    if (month == 1 || month == 2) {
        year--;
        month += 12;
    }
    return (year + year / 4 - year / 100 + year / 400
        + (13 * month + 8) / 5 + day) % 7;
}

/* 月カレンダー表示 */
void print_calendar(int year, int month) {
    int wd = dayofweek(year, month, 1);
    int mdays = monthdays(year, month);
    int day;

    printf("\n      %d / %02d\n", year, month);
    printf(" 日 月 火 水 木 金 土\n");
    printf("----------------------\n");

    printf("%*s", 3 * wd, "");
    for (day = 1; day <= mdays; day++) {
        printf("%3d", day);
        if (++wd % 7 == 0) putchar('\n');
    }
    if (wd % 7 != 0) putchar('\n');
    putchar('\n');
}

int main(void) {
    int year = 2025;
    int ans_m, ans_d;
    int guess_m, guess_d;
    const char* wday_name[] = { "日", "月", "火", "水", "木", "金", "土" };

    srand(time(NULL));

    ans_m = rand() % 12 + 1;
    ans_d = rand() % monthdays(year, ans_m) + 1;

    printf("%d年の日付を当ててください！（月と日）\n\n", year);

    do {
        printf("月 : ");
        scanf("%d", &guess_m);
        printf("日 : ");
        scanf("%d", &guess_d);

        if (guess_m > ans_m) {
            printf("\aもっと早い月です。\n");
        }
        else if (guess_m < ans_m) {
            printf("\aもっと遅い月です。\n");
        }
        else { /* 月は正解*/
            if (guess_d > ans_d) {
                printf("\aもっと前の日です。\n");
            }
            else if (guess_d < ans_d) {
                printf("\aもっと後の日です。\n");
            }
            /*月が合っている場合、曜日ヒントとカレンダーを表示*/
            printf("ヒント: 正解の日は%s曜日です。\n", wday_name[dayofweek(year, ans_m, ans_d)]);
            print_calendar(year, ans_m);
        }

    } while (guess_m != ans_m || guess_d != ans_d);

    printf("正解です！ %d年%d月%d日（%s曜日）でした！\n",
        year, ans_m, ans_d, wday_name[dayofweek(year, ans_m, ans_d)]);

    return 0;
}
