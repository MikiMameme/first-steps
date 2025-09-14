/*シーザー暗号*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>

/*文字をシーザー暗号でシフトする関数*/
char caesar_shift(char ch, int shift) {
    if (isalpha(ch)) {
        char base = isupper(ch) ? 'A' : 'a';
        return (ch - base + shift + 26) % 26 + base;
    }
    /*アルファベット以外はそのまま*/
    return ch;
}

int main(void) {
    char text[256];
    int shift;

    printf("【シーザー暗号プログラム】\n");
    printf("文字列を入力してください: ");
    fgets(text, sizeof(text), stdin);

    printf("シフト量を入力してください（例: 3）: ");
    scanf("%d", &shift);

    /*暗号化*/
    for (int i = 0; text[i] != '\0'; i++) {
        text[i] = caesar_shift(text[i], shift);
    }
    printf("暗号化: %s\n", text);

    /*復号化*/
    for (int i = 0; text[i] != '\0'; i++) {
        text[i] = caesar_shift(text[i], -shift);
    }
    printf("復号化: %s\n", text);

    return 0;
}
