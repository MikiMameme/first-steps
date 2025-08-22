/*シンプル住所録プログラム*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getputch.h"

#define MAX_CONTACTS 100
#define MAX_NAME 50
#define MAX_ADDRESS 100
#define MAX_PHONE 20
#define MAX_EMAIL 50
#define DATA_FILE "address_book.dat"

/*連絡先構造体*/
typedef struct {
    char name[MAX_NAME];
    char address[MAX_ADDRESS];
    char phone[MAX_PHONE];
    char email[MAX_EMAIL];
} Contact;

/*メニュー*/
typedef enum {
    EXIT = 0,
    ADD = 1,
    LIST = 2,
    SEARCH = 3,
    DELETE = 4,
    SAVE = 5,
    LOAD = 6
} Menu;

/*グローバル変数*/
Contact contacts[MAX_CONTACTS];
int contact_count = 0;

/*メニュー表示・選択*/
Menu select_menu(void) {
    int choice;

    printf("\n===== 住所録システム =====\n");
    printf("1. 連絡先追加\n");
    printf("2. 全件表示\n");
    printf("3. 検索\n");
    printf("4. 削除\n");
    printf("5. ファイル保存\n");
    printf("6. ファイル読込\n");
    printf("0. 終了\n");
    printf("選択してください: ");

    do {
        scanf("%d", &choice);
        if (choice < 0 || choice > 6) {
            printf("0-6の番号を入力してください: ");
        }
    } while (choice < 0 || choice > 6);

    return (Menu)choice;
}

/*連絡先追加*/
void add_contact(void) {
    if (contact_count >= MAX_CONTACTS) {
        printf("これ以上追加できません（上限%d件）\n", MAX_CONTACTS);
        return;
    }

    printf("\n=== 連絡先追加 ===\n");
    printf("名前: ");
    scanf("%s", contacts[contact_count].name);

    printf("住所: ");
    getchar(); // バッファクリア
    fgets(contacts[contact_count].address, MAX_ADDRESS, stdin);
    // 改行文字を削除
    contacts[contact_count].address[strcspn(contacts[contact_count].address, "\n")] = '\0';

    printf("電話番号: ");
    scanf("%s", contacts[contact_count].phone);

    printf("メールアドレス: ");
    scanf("%s", contacts[contact_count].email);

    contact_count++;
    printf("追加しました。\n");
}

/*全件表示*/
void list_contacts(void) {
    if (contact_count == 0) {
        printf("登録データがありません。\n");
        return;
    }

    printf("\n=== 登録データ一覧 ===\n");
    printf("No. 名前             住所                     電話番号         メール\n");
    printf("--- ---------------- ------------------------ ---------------- --------------------\n");

    for (int i = 0; i < contact_count; i++) {
        printf("%-3d %-16s %-24s %-16s %s\n",
            i + 1, contacts[i].name, contacts[i].address,
            contacts[i].phone, contacts[i].email);
    }
}

/*名前で検索*/
void search_contact(void) {
    char search_name[MAX_NAME];
    int found = 0;

    if (contact_count == 0) {
        printf("登録データがありません。\n");
        return;
    }

    printf("\n=== 検索 ===\n");
    printf("検索する名前: ");
    scanf("%s", search_name);

    printf("\n検索結果:\n");
    printf("No. 名前             住所                     電話番号         メール\n");
    printf("--- ---------------- ------------------------ ---------------- --------------------\n");

    for (int i = 0; i < contact_count; i++) {
        if (strstr(contacts[i].name, search_name) != NULL) {
            printf("%-3d %-16s %-24s %-16s %s\n",
                i + 1, contacts[i].name, contacts[i].address,
                contacts[i].phone, contacts[i].email);
            found = 1;
        }
    }

    if (!found) {
        printf("該当するデータが見つかりませんでした。\n");
    }
}

/*削除*/
void delete_contact(void) {
    int delete_num;

    if (contact_count == 0) {
        printf("登録データがありません。\n");
        return;
    }

    list_contacts();

    printf("\n削除する番号を入力してください (0でキャンセル): ");
    scanf("%d", &delete_num);

    if (delete_num == 0) {
        printf("キャンセルしました。\n");
        return;
    }

    if (delete_num < 1 || delete_num > contact_count) {
        printf("無効な番号です。\n");
        return;
    }

    // 削除対象を表示
    printf("以下のデータを削除します:\n");
    printf("%s (%s)\n", contacts[delete_num - 1].name, contacts[delete_num - 1].phone);

    // 配列を詰める
    for (int i = delete_num - 1; i < contact_count - 1; i++) {
        contacts[i] = contacts[i + 1];
    }

    contact_count--;
    printf("削除しました。\n");
}

/*ファイル保存*/
void save_to_file(void) {
    FILE* fp;

    if ((fp = fopen(DATA_FILE, "w")) == NULL) {
        printf("ファイル保存に失敗しました。\n");
        return;
    }

    fprintf(fp, "%d\n", contact_count);

    for (int i = 0; i < contact_count; i++) {
        fprintf(fp, "%s\n%s\n%s\n%s\n",
            contacts[i].name, contacts[i].address,
            contacts[i].phone, contacts[i].email);
    }

    fclose(fp);
    printf("ファイルに保存しました。(%d件)\n", contact_count);
}

/*ファイル読込*/
void load_from_file(void) {
    FILE* fp;

    if ((fp = fopen(DATA_FILE, "r")) == NULL) {
        printf("ファイルが見つかりません。\n");
        return;
    }

    fscanf(fp, "%d", &contact_count);

    for (int i = 0; i < contact_count; i++) {
        fscanf(fp, "%s", contacts[i].name);
        getchar(); // バッファクリア
        fgets(contacts[i].address, MAX_ADDRESS, fp);
        contacts[i].address[strcspn(contacts[i].address, "\n")] = '\0';
        fscanf(fp, "%s", contacts[i].phone);
        fscanf(fp, "%s", contacts[i].email);
    }

    fclose(fp);
    printf("ファイルから読み込みました。(%d件)\n", contact_count);
}

int main(void) {
    Menu menu;

    init_getputch();

    printf("住所録プログラムを開始します。\n");

    do {
        menu = select_menu();

        switch (menu) {
        case ADD:
            add_contact();
            break;
        case LIST:
            list_contacts();
            break;
        case SEARCH:
            search_contact();
            break;
        case DELETE:
            delete_contact();
            break;
        case SAVE:
            save_to_file();
            break;
        case LOAD:
            load_from_file();
            break;
        case EXIT:
            printf("終了します。\n");
            break;
        }
    } while (menu != EXIT);

    term_getputch();
    return 0;
}
