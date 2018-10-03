#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#define _CRT_SECURE_NO_WARNINGS
typedef char element;


typedef struct ListNode {
	element data1[20];
	element data2[30];
	element data3[20];
	struct ListNode *link;
} ListNode;

typedef struct List {
	ListNode *head;
} List;

void print();
void error_msg(char *strMsg);
void list_init(List *pList);
void list_add(List *pList, element* item1, element* item2);
void list_delete(List *pList, element *item1);
void list_print(List *pList);
void list_search(List *pList1, List *pList2, element *item2);
void book_borrow(List *pList1, List *pList2, element *item1, element *item2);
void book_retun(List *pList, element *item1);
void book_plus(List *pList, element *item1, element *item2, element *item3);
void book_minus(List *pList, element *item1);
void save_list(List *pList);
void load_list(List *pList);
void book_print(List *pList);

void print() {
	printf("=====================도서관리프로그램====================\n");
	printf("=========================================================\n");
	printf("1.회원가입 2.회원탈퇴 3.회원조회   4.회원검색\n5.도서대여 6.도서반납 7.데이터저장 8.데이터불러오기\n9.도서관리 0.끝\n");
	printf("=========================================================\n");
}

void error_msg(char *strMsg)
{
	fprintf(stderr, "%s", strMsg);
	exit(1);
}

void list_init(List *pList)
{
	if (pList == NULL)
		error_msg("list_init: pList == NULL");

	pList->head = NULL;
}

void list_add(List *pList, element *item1, element *item2)
{
	ListNode *p1 = (ListNode*)malloc(sizeof(ListNode));
	ListNode *p2 = (ListNode*)malloc(sizeof(ListNode));
	p2 = pList->head;
	if (pList->head != NULL) {
		while (1) {
			if (strcmp(p2->data1, item2) == 0) {
				error_msg("error: 가입 되어있는 회원입니다.\n");
				return;
			}
			if (p2->link == NULL) {
				break;
			}
			p2 = p2->link;
		}
		strcpy(p1->data1, item1);
		strcpy(p1->data2, item2);
		p1->link = pList->head;
		pList->head = p1;
		printf("\n'%s'님 가입완료!\n", p1->data2);
	}
	if (pList->head == NULL)
	{
		strcpy(p1->data1, item1);
		strcpy(p1->data2, item2);
		pList->head = p1;
		p1->link = NULL;
		printf("\n'%s'님 가입완료!\n", p1->data2);
	}

}

void list_delete(List *pList, element *item1)
{
	ListNode *p1 = (ListNode*)malloc(sizeof(ListNode));
	ListNode *p2 = (ListNode*)malloc(sizeof(ListNode));
	p1 = pList->head;
	p2->link = pList->head;
	if (pList->head == NULL) {
		printf("-----ALL EMPTY-----\n");
	}
	else if (pList->head != NULL) {
		while (1) {
			if (p2->link != NULL) {
				if (strcmp(p1->data1, item1) == 0) {
					if (p2->link == pList->head) {
						p2->link = p1->link;
						pList->head = p2->link;
					}
					else {
						p2->link = p1->link;
					}
					printf("%s 님 ", p1->data2);
					printf("탈퇴완료!\n");
					free(p1);
					break;
				}
				p1 = p1->link;
				p2 = p2->link;
			}
			else if (p2->link == NULL) {
				printf("error: 등록되지 않은 회원입니다.\n");
				break;
			}
		}
	}
}

void list_print(List *pList)
{
	ListNode *p1 = (ListNode*)malloc(sizeof(ListNode));
	if (pList->head == NULL)
	{
		printf("입력된 정보가 없습니다.\n");
		return;
	}
	p1 = pList->head;
	while (1) {
		if (p1->link == NULL) {
			printf("[");
			printf("%s ", p1->data1); printf("%s", p1->data2);
			printf("]\n");
			printf("=========================================================\n");
			break;
		}
		else if (p1->link != NULL) {
			printf("[");
			printf("%s ", p1->data1); printf("%s", p1->data2);
			printf("]\n");
			p1 = p1->link;
		}
	}

}

void list_search(List *pList1, List *pList2, element *item2)
{
	ListNode *p1 = (ListNode*)malloc(sizeof(ListNode));
	ListNode *p2 = (ListNode*)malloc(sizeof(ListNode));
	ListNode *p3 = (ListNode*)malloc(sizeof(ListNode));
	p3 = pList2->head;
	p1 = pList1->head;
	p2->link = pList1->head;
	if (pList1->head == NULL) {
		printf("-----ALL EMPTY-----\n");
	}
	else if (pList1->head != NULL) {
		while (1) {
			if (p2->link != NULL) {
				if (strcmp(p1->data2, item2) == NULL) {
					printf("'%s'님은 가입된 회원입니다.\n", p1->data2);
					while (1) {
						if (pList2->head != NULL) {
							if (strcmp(p1->data3, p3->data1) == 0) {
								printf("대여 중 '%s'\n", p3->data2);
								break;
							}

							if (p3->link == NULL) {
								printf("대여 중인 도서가 없습니다.\n");
								break;
							}
							else if (p3->link != NULL) {
								p3 = p3->link;
							}
						}
						else if (pList2->head == NULL) {
							printf("대여 중인 도서가 없습니다.\n");
							break;
						}
					}
					break;
				}
				p1 = p1->link;
				p2 = p2->link;
			}
			if (p2->link == NULL) {
				printf("가입된 회원이 아닙니다.\n");
				break;
			}
		}
	}
}

void book_borrow(List *pList1, List *pList2, element *item1, element *item2)
{
	ListNode *p1 = (ListNode*)malloc(sizeof(ListNode));
	ListNode *p2 = (ListNode*)malloc(sizeof(ListNode));
	p1 = pList1->head;
	p2 = pList2->head;
	while (1) {
		if (pList1->head != NULL) {
			if (strcmp(p1->data1, item1) == 0) {
				strcpy(p1->data3, item2);
				break;
			}
		}
		p1 = p1->link;
		if (pList1->head == NULL) {
			printf("error: 등록된 회원이 없습니다.\n");
			return;
		}
	}
	while (1) {
		if (pList2->head != NULL) {
			if (strcmp(p2->data1, item2) == 0) {
				printf("'%s'님이 '%s'를 빌리셨습니다.\n", p1->data2, p2->data2);
				break;
			}
			p2 = p2->link;
		}
		if (pList2->head == NULL) {
			printf("error: 등록된 도서가 없습니다.\n");
			return;
		}
	}
}

void book_retun(List *pList, element *item1)
{
	ListNode *p1 = (ListNode*)malloc(sizeof(ListNode));
	ListNode *p2 = (ListNode*)malloc(sizeof(ListNode));
	p1 = pList->head;
	p2->link = pList->head;
	while (1) {
		if (pList->head != NULL) {
			if (p1->link != NULL) {
				if (strcmp(p1->data2, item1) == 0) {
					printf("'%s' (이)가 반납완료 되었습니다.\n", p1->data3);
					strcpy(p1->data3, NULL);
				}
			}
			else if (p1->link == NULL) {
				printf("'%s' (이)가 회원이 아닙니다.\n", item1);
			}
		}
		else if (pList->head == NULL) {
			printf("EMPTY\n");
		}
	}

}

void save_list(List *pList)
{
	ListNode *p1 = (ListNode*)malloc(sizeof(ListNode));
	p1 = pList->head;
	char file[50];
	printf("내용을 저장하겠습니다.\n");
	printf("파일명(.txt):");
	scanf("%s", file);
	FILE *fp = fopen(file, "w");
	if (pList->head == NULL) {
		printf("파일을 생성할 수 없습니다.\n");
	}
	if (pList->head != NULL) {
		if (fp == NULL) {
			printf("'%s'파일을 만들수 없습니다.\n", file);
			fclose(fp);
			return;
		}
		fprintf(fp, "\n");
		while (1) {
			fprintf(fp, "%s %s %s\n", p1->data1, p1->data2, p1->data3);
			if (p1->link == NULL) {
				printf("저장완료!\n");
				fclose(fp);
				break;
			}
			p1 = p1->link;
		}
	}
}

void load_list(List *pList)
{

	ListNode ffile[50];
	ListNode *p1 = (ListNode*)malloc(sizeof(ListNode));
	ListNode *p2 = (ListNode*)malloc(sizeof(ListNode));
	p2 = pList->head;
	char file[50];
	char want[40];
	int i = 0;
	printf("파일을 불러오겠습니다.\n");
	printf("파일명(.txt):");
	scanf("%s", file);
	FILE *fp = fopen(file, "r");
	fgets(want, sizeof(want), fp);
	while (1) {
		if (fp == NULL) {
			printf("'%s'파일을 열 수 없습니다!\n", file);
			break;
		}
		if (pList->head != NULL) {
			p1->link = pList->head;
			pList->head = p1;
		}
		else {
			pList->head = p1;
			p1->link = NULL;
		}
		fscanf(fp, "%s %s %s\n", &ffile[i].data1, &ffile[i].data2, &ffile[i].data3);
		printf("학번 : %s\n이름 : %s\n대여도서 : %s\n", ffile[i].data1, ffile[i].data2, ffile[i].data3);
		strcpy(p1->data1, ffile[i].data1);
		strcpy(p1->data2, ffile[i].data2);
		strcpy(p1->data3, ffile[i].data3);
		if (feof(fp) != 0) {
			printf("불러왔습니다. \n");
			fclose(fp);
			break;
		}
		i++;
	}
}


void book_plus(List *pList, element *item1, element *item2, element *item3)
{
	ListNode *p1 = (ListNode*)malloc(sizeof(ListNode));
	ListNode *p2 = (ListNode*)malloc(sizeof(ListNode));
	p2 = pList->head;
	if (pList->head != NULL) {
		while (1) {
			if (strcmp(p2->data1, item1) == 0 || strcmp(p2->data2, item2) == 0 || strcmp(p2->data3, item3) == 0) {
				printf("error: 등록되어 있는 도서입니다.\n");
				return;
			}
			if (p2->link == NULL) {
				break;
			}
			p2 = p2->link;
		}
		strcpy(p1->data1, item1);
		strcpy(p1->data2, item2);
		strcpy(p1->data3, item3);
		p1->link = pList->head;
		pList->head = p1;
		printf("'%s'(이)가 등록되었습니다.!\n", p1->data2);
	}
	if (pList->head == NULL)
	{
		strcpy(p1->data1, item1);
		strcpy(p1->data2, item2);
		strcpy(p1->data3, item3);
		pList->head = p1;
		p1->link = NULL;
		printf("'%s'(이)가 등록되었습니다.!\n", p1->data2);
	}

}

void book_minus(List *pList, element *item1)
{
	ListNode *p1 = (ListNode*)malloc(sizeof(ListNode));
	ListNode *p2 = (ListNode*)malloc(sizeof(ListNode));
	p1 = pList->head;
	p2->link = pList->head;
	if (pList->head == NULL) {
		printf("-----ALL EMPTY-----\n");
	}
	else if (pList->head != NULL) {
		while (1) {
			if (p2->link != NULL) {
				if (strcmp(p1->data1, item1) == 0) {
					if (p2->link == pList->head) {
						p2->link = p1->link;
						pList->head = p2;
					}
					else {
						p2->link = p1->link;
					}
					printf("'%s' 가 도서대장에서 삭제되었습니다.\n", p1->data2);
					free(p1);
					break;
				}
				p1 = p1->link;
				p2 = p2->link;
			}
			else if (p2->link == NULL) {
				printf("error: 등록되지 않은 도서코드입니다.\n");
				break;
			}
		}
	}
}

void book_print(List *pList)
{
	ListNode *p1 = (ListNode*)malloc(sizeof(ListNode));
	if (pList->head == NULL)
	{
		printf("입력된 도서가 없습니다.\n");
		return;
	}
	p1 = pList->head;
	while (1) {
		if (p1->link == NULL) {
			printf("[");
			printf("%s..%s (%s)", p1->data1, p1->data2, p1->data3);
			printf("]\n");
			printf("===============================\n");
			break;
		}
		else if (p1->link != NULL) {
			printf("[");
			printf("%s..%s (%s)", p1->data1, p1->data2, p1->data3);
			printf("]\n");
			p1 = p1->link;
		}
	}

}

int main()
{
	int num = 0;
	List p, b;
	char idcode[20], name[30], bcode[20], bname[30], writer[20];
	list_init(&p); list_init(&b);
	while (1)
	{
		print();
		printf("메뉴를 선택하십시오 : ");
		scanf("%d", &num); system("cls");
		print();
		if (num == 0)
		{
			printf("\n");
			printf("[Q  U  I  T]\n");
			printf("\n");
			break;
		}
		else {
			switch (num)
			{
			case 1:
				printf("[회원가입합니다.]\n");
				printf("학번을 입력하시오 : ");
				scanf("%s", idcode);
				printf("이름을 입력하시오 : ");
				scanf("%s", name);
				list_add(&p, idcode, name);
				break;
			case 2:
				printf("[회원탈퇴합니다.]\n");
				printf("학번을 입력하시오 :");
				scanf("%s", idcode);
				list_delete(&p, idcode);
				break;
			case 3:
				printf("[ 회 원 목 록 ]\n");
				list_print(&p);
				break;
			case 4:
				printf("[ 회 원 검 색 ]\n");
				printf("이름을 입력하시오 :");
				scanf("%s", name);
				list_search(&p, &b, name);
				break;
			case 5:
				printf("[ 도 서 대 여 ]\n");
				printf("학번을 입력하시오 : ");
				scanf("%s", idcode);
				printf("책 코드를 입력하시오 : ");
				scanf("%s", bcode);
				book_borrow(&p, &b, idcode, bcode);
				break;
			case 6:
				printf("[ 도 서 반 납 ]\n");
				printf("도서를 반납하실 분의 이름을 입력하시오:");
				scanf("%s", name);
				book_retun(&p, name);
				break;
			case 7:
				printf("[ 데이터 SAVE ]\n");
				save_list(&p);
				break;
			case 8:
				printf("[ 데이터 LOAD ]\n");
				load_list(&p);
				break;
			case 9:
				printf("[도서등록, 삭제, 조회]\n");
				printf("1.등록  /   2.삭제   /   3.조회\n");
				scanf("%d", &num); system("cls");
				print();
				if (num == 1) {
					printf("지정할 코드를 정하시오(예:001A):");
					scanf("%s", bcode);
					printf("책 이름을 입력하시오(공백x):");
					scanf("%s", bname);
					printf("저자를 입력하시오:");
					scanf("%s", writer);
					book_plus(&b, bcode, bname, writer);
				}
				else if (num == 2) {
					printf("삭제할 도서의 코드를 입력하시오:");
					scanf("%s", bcode);
					book_minus(&b, bcode);
				}
				else if (num == 3) {}
				printf("[ 도 서 대 장 ]\n");
				book_print(&b);
				break;
			default:
				printf("사용할 수 없는 메뉴입니다. \n+재시작합니다+\n");
				break;
			}
		}
		for (int i = 0; i < 7; i++) {
			printf(".");
			Sleep(200);
		}
		printf(".★"); Sleep(900); system("cls");
	}
	return 0;
}
