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
		printf("\n   * **МЕНЮ** *\n   ввод - 1\n   вывод - 2\n   рассчёт - 3\n   добавить - 4\n   удалить - 5\n   сортировать - 6\n   выход - 7\n   * **####** *\n\n  Ваш выбор: ");
		scanf_s("%d", &menu);
		switch (menu) {
		case 1: {
		
			if (N == 0)
				enter();
			else printf(" Вы не можете ввести данные - только добавить (ввод производится при пустом файле)");
		}
			break;
		case 2: 

			if( N>0)print(); else printf("Нет записей");
			break;
		case 3: if (N>0)calculation(); else printf("Нет записей");
			break;
		case 4: if (N > 0)plus(); else printf("Нет записей");
			break;
		case 5: if (N>0)del(); else printf("Нет записей");
			break;
		case 6: {
			if (N>0) {
				int choice;
				printf("        Сортировка по сумме :\n 1 - материалов \n 2 - обслуживания техники \n 3 - зарплаты рабочих \n 4 - полученных денег\n   ");
				scanf_s("%d", &choice);
				if (choice < 1 || choice>4) {
					printf("  Попробуйте ещё раз - ");
					scanf_s("%d", &choice);
				}
				Sort(choice);
			}
			else printf("Нет записей");
		}
			break;
		case 7:
			printf("\n     ....Завершение работы.....\n");
			FREE();
			cycle = 0;
			break;
		}
	}
	return 0;
}
