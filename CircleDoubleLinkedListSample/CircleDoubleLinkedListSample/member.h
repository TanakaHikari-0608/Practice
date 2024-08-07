#pragma once
//=========================================================//==========================================================
//	循環・重連結リストサンプル
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include "member.h"
#include "CircleDoubleLinkedList.h"
#include <stdio.h> // printf(),scanf()
		
typedef enum {
	TERMINATE,
	INSERT_FRONT,
	INSERT_REAR,
	REMOVE_FRONT,
	REMOVE_REAR,
	PRINT_CURRENT,
	REMOVE_CURRENT,
	SEARCH_NO,
	SEARCH_NAME,
	PRINT_ALL,
	NEXT,
	PREV,
	CLEAR,
} Menu;
	
// 関数プロトタイプ
Menu SelectMenu();
void setup(DblList *list);
	
int main()
{
	Menu menu;
	DblList list;

	Initialize(&list);
	setup(&list);
	do {
		Member x;
		DblNode* node;
		menu = SelectMenu();
		switch (menu) {
		case INSERT_FRONT:
			x = ScanMember("先頭に挿入する", MEMBER_NO + MEMBER_NAME);
			InsertFront(&list, &x);
			break;
		case INSERT_REAR:
			x = ScanMember("末尾に挿入する", MEMBER_NO + MEMBER_NAME);
			InsertRear(&list, &x);
			break;
		case REMOVE_FRONT:
			RemoveFront(&list);
			break;
		case REMOVE_REAR:
			RemoveRear(&list);
			break;
		case PRINT_CURRENT:
			PrintLnCurrent(&list);
			break;
		case REMOVE_CURRENT:
			RemoveCurrent(&list);
			break;
		case SEARCH_NO:
			x=ScanMember("検索", MEMBER_NO);
			node=Search(&list, &x, MemberNoCmp);
			if (node != nullptr) {
				PrintCurrent(&list);
				putchar('\n');
			}
			else {
				puts("その番号のデータはありません");
			}
			break;
		case SEARCH_NAME:
			x = ScanMember("検索", MEMBER_NAME);
			node = Search(&list, &x, MemberNameCmp);
			if (node != nullptr) {
				PrintCurrent(&list);
				putchar('\n');
			}
			else {
				puts("その名前のデータはありません");
			}
			break;
		case PRINT_ALL:
			Print(&list);
			break;
		case NEXT:
			Next(&list);
			break;
		case PREV:
			Prev(&list);
			break;
		case CLEAR:
			Clear(&list);
			break;
		}
		putchar('\n');
	} while (menu != TERMINATE);
	
	Terminate(&list);
	return 0;
}
	
Menu SelectMenu()
{
	int ch;
	const char* menuStr[] = {
		"先頭にノードを挿入",
		"末尾にノードを挿入",
		"先頭のノードを削除",
		"末尾のノードを削除",
		"着目ノードを表示",
		"着目ノードを削除",
		"番号で検索",
		"氏名で検索",
		"全ノードを表示",
		"注目ノードを後方へ",
		"注目ノードを前方へ",
		"全ノードを削除",
	};
	int menuStrSize = sizeof(menuStr) / sizeof(menuStr[0]);

	do {
		for (int i = 0; i < menuStrSize; i++) {
			printf("(%2d)%-18.18s  ", i + 1, menuStr[i]);
			if (i % 3 == 2) {
				putchar('\n');
			}
		}
		printf("( 0)終了\t:");
		scanf("%d", &ch);
	} while (ch < TERMINATE || CLEAR < ch);
	return (Menu)ch;
}
void setup(DblList* list)
{
	Member data[] = {
		{1,"赤尾"},
		{5,"武田"},
		{10,"小野"},
		{12,"鈴木"},
		{14,"神崎"},
	};
	int dataSize = sizeof(data) / sizeof(data[0]);
	for (int i = 0; i < dataSize; i++) {
		InsertRear(list, &data[i]);
	}
}
//	会員構造体
//==========================================================
#ifndef __MEMBER
#define __MEMBER

#define NAME_SIZE (32)

typedef struct{
	int no;               // 番号  
	char name[NAME_SIZE]; // 名前
} Member;

#define MEMBER_NO   (1<<0)  // 番号を表す整数値
#define MEMBER_NAME (1<<1)  // 名前を表す整数値

// 会員番号の比較関数
int MemberNoCmp(const Member* x, const Member* y);
// 会員名前の比較関数
int MemberNameCmp(const Member* x, const Member* y);
// 会員データの表示(改行なし)
void PrintMember(const Member* x);
// 会員データの表示(改行あり)
void PrintLnMember(const Member* x);
// 会員データの読み込み
Member ScanMember(const char *message, int sw);

#endif // __MEMBER