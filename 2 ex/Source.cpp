#define _CRT_SECURE_NO_WARNINGS
#include "My_file.h"
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main() {
	int menu;
	int N;
	int cycle = 1;
	while (cycle) {
		N = getN();
		setlocale(LC_ALL, "rus");
		printf("\n   * **����** *\n   ���� - 1\n   ����� - 2\n   ������� - 3\n   �������� - 4\n   ������� - 5\n   ����������� - 6\n   ����� - 7\n   * **####** *\n\n  ��� �����: ");
		scanf_s("%d", &menu);
		switch (menu) {
		case 1: {
		
			if (N == 0)
				enter();
			else printf(" �� �� ������ ������ ������ - ������ �������� (���� ������������ ��� ������ �����)");
		}
			break;
		case 2: 

			if( N>0)print(); else printf("��� �������");
			break;
		case 3: if (N>0)calculation(); else printf("��� �������");
			break;
		case 4: if (N > 0)plus(); else printf("��� �������");
			break;
		case 5: if (N>0)del(); else printf("��� �������");
			break;
		case 6: {
			if (N>0) {
				int choice;
				printf("        ���������� �� ����� :\n 1 - ���������� \n 2 - ������������ ������� \n 3 - �������� ������� \n 4 - ���������� �����\n   ");
				scanf_s("%d", &choice);
				if (choice < 1 || choice>4) {
					printf("  ���������� ��� ��� - ");
					scanf_s("%d", &choice);
				}
				Sort(choice);
			}
			else printf("��� �������");
		}
			break;
		case 7:
			printf("\n     ....���������� ������.....\n");
			FREE();
			cycle = 0;
			break;
		}
	}
	return 0;
}
