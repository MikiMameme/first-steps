/*ヴィジュネル暗号プログラム（暗号化・復号化対応）*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>
#include <string.h>


/*文字をシフトする関数（大文字・小文字対応）*/
char vigenere_shift(char ch, char key_ch, int encrypt) {
    if (isupper(ch)) {
        int shift = toupper(key_ch) - 'A';
        if (!encrypt) shift = -shift;
        return (ch - 'A' + shift + 26) % 26 + 'A';
    }
    else if (islower(ch)) {
        int shift = toupper(key_ch) - 'A';
        if (!encrypt) shift = -shift;
        return (ch - 'a' + shift + 26) % 26 + 'a';
    }
    return ch; /*アルファベット以外はそのまま*/
}

int main(void) {
    char text[512];
    char key[512];
    char choice;

    printf(" __     _____ _____ _____ _   _ _____ _____  _____ \n");
    printf(" \\ \\   / /_ _|  ___| ____| \\ | | ____|  __ \\| ____|\n");
    printf("  \\ \\ / / | || |  _|  _| |  \\| |  _| | |__) |  _|  \n");
    printf("   \\ V /  | || |_| | |___| |\\  | |___| | _ <| |___\n");
    printf("    \\_/  |___|____ |_____|_| \\_|_____|_|  \\_\\ ____|\n");

    printf("【ヴィジュネル暗号プログラム（暗号化・復号化対応）】\n\n");
    printf("暗号化する場合は E, 復号化する場合は D を入力してください: ");
    scanf(" %c", &choice);

    getchar(); /*改行を吸収*/

    printf("文字列を入力: ");
    fgets(text, sizeof(text), stdin);

    printf("キーを入力: ");
    fgets(key, sizeof(key), stdin);

    /*改行削除*/
    text[strcspn(text, "\n")] = '\0';
    key[strcspn(key, "\n")] = '\0';

    int key_len = strlen(key);
    int encrypt = (toupper(choice) == 'E'); /*暗号化かどうかフラグ*/

    /*処理*/
    char result[512];
    for (int i = 0; text[i] != '\0'; i++) {
        result[i] = vigenere_shift(text[i], key[i % key_len], encrypt);
    }
    result[strlen(text)] = '\0';

    if (encrypt)
        printf("暗号化: %s\n", result);
    else
        printf("復号化: %s\n", result);

    return 0;
}
