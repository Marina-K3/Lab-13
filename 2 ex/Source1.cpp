#define _CRT_SECURE_NO_WARNINGS
#include "My_file.h"
#include <conio.h>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

static struct work {
    float mat;
    float tech;
    float plata;
    float money;
    float tratu;
} *works;


int N=0;
void read();
extern int getN() {
   read();
   return N;
}
extern void FREE() {
    if(works!=NULL)
    free(works);
}

//читает из файла структуры в массив и считает их количество
void read() {
    setlocale(LC_ALL, "rus");
    work buf;
    int i = 0;
    int count = 0;
    FILE* file;
   file = fopen ( "WORKS.txt", "a+");
    if (file == nullptr) printf(" Ошибка работы файла");
    else {
        while (fread(&buf, sizeof(work), 1, file)) {
            count++;
        }
        N = count;
        fclose(file);
    }

    if (N == 0) {
        printf(" Запишите данные, так как файл пуст");
    }
    else {
        works = (work*)realloc(works, N * sizeof(work));
    }
    file = fopen("WORKS.txt", "r");
    if (file == nullptr) printf(" Ошибка работы файла");
    else {
        while (fread(&buf, sizeof(work), 1, file)) {
            works[i] = buf;
            i++;
        }
        fclose(file);
    }
}
extern void enter() {
    int p;
    setlocale(LC_ALL, "rus");
    printf("\n Введите кол-во проведённых работ - ");
    scanf_s("%d", &p);
    N = N + p;
    works = (work*)malloc(N * sizeof(work));
    register int i;
    FILE* file;
    file = fopen("WORKS.txt", "a+");
    if (file == nullptr) printf(" Ошибка работы файла");
    else {
        for (i = 0; i < N; i++) {
            printf("\n");
            printf("      РАБОТА № %d", i + 1);
            printf("\n******************************");
            printf("\n* Расходы на материалы - ");
            scanf_s("%f", &works[i].mat);
            printf("******************************\n");
            printf("* Обслуживание техники - ");
            scanf_s("%f", &works[i].tech);
            printf("******************************\n");
            printf("* Зарплата для рабочих - ");
            scanf_s("%f", &works[i].plata);
            printf("******************************\n");
            printf("* Выделенные деньги - ");
            scanf_s("%f", &works[i].money);
            printf("******************************\n");
            fwrite(&works[i], sizeof(work), 1, file);
        }
        fclose(file);
    }
}

extern int print() {
    setlocale(LC_ALL, "rus");
    int choice;
    int MyChoice;
    int i = 0;
    printf("\n Просмотреть всё - 1\n Просмотреть одну - 2\n Ответ - ");
    scanf_s("%d", &MyChoice);
    switch (MyChoice)
    {
    case 1:
        for (i = 0; i < N; i++) {
            printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
            printf("\n|                                         РАБОТА № %d", i + 1);
            printf("                     |");
            printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
            printf("\n| Расходы на материалы | Обслуживание техники | Зарплата для рабочих | Выделенные деньги |");
            printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("%22f%22f%22f%19f", works[i].mat, works[i].tech, works[i].plata, works[i].money);
            printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        }
        break;
    case 2:
        printf("\n Номер какой работы Вы хотите увидеть ?");
        printf("\n Ваш ответ : ");
        scanf_s("%d", &choice);
            if (choice <= N && choice > 0) {
                printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
                printf("\n|                                         РАБОТА № %d", choice);
                printf("                     |");
                printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
                printf("\n| Расходы на материалы | Обслуживание техники | Зарплата для рабочих | Выделенные деньги |");
                printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                printf("%22f%22f%22f%19f", works[choice - 1].mat, works[choice - 1].tech, works[choice-1].plata, works[choice - 1].money);
                printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            }
            else printf(" Вы ввели некорректное значение");
        
        break;
    default:
        break;
    }
    return 0;
}

extern int plus() {
    setlocale(LC_ALL, "rus");
    int h;
    printf("\n Сколько работ Вы хотите добавить ? - ");
    scanf_s("%d", &h);
    N = N + h;
    works = (work*)realloc(works, (N) * sizeof(work));
    register int i;
    FILE* file;
    file = fopen("WORKS.txt", "a+");
    if (file == nullptr) printf(" Ошибка работы файла"); 
  else{
        for (i = N - h; i < N; i++) {
            printf("\n");
            printf("      РАБОТА № %d", i + 1);
            printf("\n******************************");
            printf("\n* Расходы на материалы - ");
            scanf_s("%f", &works[i].mat);
            printf("******************************\n");
            printf("* Обслуживание техники - ");
            scanf_s("%f", &works[i].tech);
            printf("******************************\n");
            printf("* Зарплата для рабочих - ");
            scanf_s("%f", &works[i].plata);
            printf("******************************\n");
            printf("* Выделенные деньги - ");
            scanf_s("%f", &works[i].money);
            printf("******************************\n");
            fwrite(&works[i], sizeof(work), 1, file);
        }
        fclose(file); 
  }
    return 0;
}
extern int calculation() {
    setlocale(LC_ALL, "rus");
    float k;
    work buf;
    printf("\n Введите коэффициент подоходного налога - ");
    scanf_s("%f", &k);
    float sum;
    float res = 0;
    register int i;
    for (i = 0; i < N; i++) {
        works[i].tratu = works[i].mat + works[i].plata + works[i].tech;
        sum = works[i].money - works[i].tratu;
        res += sum;
    }
    printf("\n\n  ~~~~~~ ОТЧЁТ ~~~~~\n\n");
    if (res > 0)printf("\n          ДОХОД - %5.2f", res - res * k);
    else printf("\n   К сожалению затраты превысили доходы\n Ваш убыток - %5.2f", res);
    int d = 0;
    for (d = 0; d < N - 1; d++) {
        for (i = 0; i < N - d - 1; i++) {
            if (works[i].tratu < works[i + 1].tratu) {
                buf = works[i];
                works[i] = works[i + 1];
                works[i + 1] = buf;
            }
        }
    }
    float tratu = 0;
    for (i = 0; i < N; i++) {
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        printf("\n|                                         РАБОТА № %d", i + 1);
        printf("                     |");
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        printf("\n| Расходы на материалы | Обслуживание техники | Зарплата для рабочих | Выделенные деньги |");
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("%22f%22f%22f%19f", works[i].mat, works[i].tech, works[i].plata, works[i].money);
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        tratu += works[i].tratu;
    }
    printf("\n ****ОБЩИЕ ТРАТЫ - %5.2f****\n", tratu);
    return 0;

}
extern int del()
{
    setlocale(LC_ALL, "rus");
    printf(" Удалить всё ? - 1\n Удалить одну из структур - 2\n");
    int del;
    scanf_s("%d", &del);
    register int i;
    if (del == 1) { 
        N = 0;
        free(works); 
        FILE* file;
        file = fopen("WORKS.txt", "w");
        if (file == nullptr) printf(" Ошибка работы файла");
        else {
            fwrite("", 0, 1, file);
            fclose(file);
        }
    }
    else {
        printf(" Введите номер, который хотите удалить: ");
        scanf_s("%d", &del);
        for (i = del - 1; i <= N - 1; i++) {
            works[i] = works[i + 1];
        }
        N = N - 1;
        printf("\n Отформатированный список :");
        for (i = 0; i < N; i++) {
            printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
            printf("\n|                                         РАБОТА № %d", i + 1);
            printf("                     |");
            printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
            printf("\n| Расходы на материалы | Обслуживание техники | Зарплата для рабочих | Выделенные деньги |");
            printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("%22f%22f%22f%19f", works[i].mat, works[i].tech, works[i].plata, works[i].money);
            printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        }
        FILE* file;
        file = fopen("WORKS.txt", "w");
        if (file == nullptr) printf(" Ошибка работы файла"); 
        else{
            for (i = 0; i < N; i++) {
                fwrite(&works[i], sizeof(work), 1, file);
            }
            fclose(file);
        }

    }
    return 0;
}
void Merge(struct work *A, int first, int last) {

    int middle, start, final, j;
    work* mas = new work[100];
    middle = (first + last) / 2; //вычисление среднего элемента
    start = first; //начало левой части
    final = middle + 1; //начало правой части
    for (j = first; j <= last; j++) //выполнять от начала до конца
        if ((start <= middle) && ((final > last) || (A[start].mat < A[final].mat)))
        {
            mas[j] = A[start];
            start++;
        }
        else
        {
            mas[j] = A[final];
            final++;
        }
    //возвращение результата в список
    for (j = first; j <= last; j++) A[j] = mas[j];
    delete[]mas;
};
//рекурсивная процедура сортировки
void MergeSort(struct work *A, int first, int last)
{

    {
        if (first < last)
        {
            MergeSort(A, first, (first + last) / 2); //сортировка левой части
            MergeSort(A, (first + last) / 2 + 1, last); //сортировка правой части
            Merge(A, first, last); //слияние двух частей
        }
    }
}
void InsertSort() {
    work t;
    for (int i = 1; i < N; i++) {
        for (int j = i; j > 0 && works[j - 1].tech > works[j].tech; j--)
        {
            t = works[j - 1] ;
            works[j - 1] = works[j];
            works[j] = t;
        }

    }
}
void HoorSort(work a[], int left, int right) {
    float t{};
    int i = left, j = right; /*Инициализируем переменные левой и
правой границами подмассива*/
    float test = a[(left + right) / 2].plata; /*Выбираем в качестве
     элемента разбиения средний элемент массива*/
    do {
        while (a[i].plata < test)
            i++;
        /*находим элемент, больший элемента разбиения */
        while (a[j].plata > test)
            j--;
        /*находим элемент, меньший элемента разбиения */
        if (i <= j)
        {
            t = a[i].plata;
            a[i].plata = a[j].plata;
            a[j].plata = t;
            i++; j--;
        }
    } while (i <= j);   /*рекурсивно вызываем алгоритм для
                          правого и левого подмассива*/
    if (i < right)
        HoorSort(a, i, right);
    if (j > left)
        HoorSort(a, left, j);
}
void ShekeSort(work* mass, int count) {
    int left = 0, right = count - 1; // левая и правая границы сортируемой области массива
    int flag = 1;  // флаг наличия перемещений
    // Выполнение цикла пока левая граница не сомкнётся с правой
    // и пока в массиве имеются перемещения
    work t;
    while ((left < right) && flag > 0)
    {
        flag = 0;
        for (int i = left; i < right; i++)  //двигаемся слева направо
        {
            if (mass[i].money > mass[i + 1].money) // если следующий элемент меньше текущего,
            {             // меняем их местами
                 t = mass[i];
                mass[i] = mass[i + 1];
                mass[i + 1] = t;
                flag = 1;      // перемещения в этом цикле были
            }
        }
        right--; // сдвигаем правую границу на предыдущий элемент
        for (int i = right; i > left; i--)  //двигаемся справа налево
        {
            if (mass[i - 1].money > mass[i].money) // если предыдущий элемент больше текущего,
            {            // меняем их местами
                t = mass[i];
                mass[i] = mass[i - 1];
                mass[i - 1] = t;
                flag = 1;    // перемещения в этом цикле были
            }
        }
        left++; // сдвигаем левую границу на следующий элемент
    }
}

extern void Sort(int choice) {
    switch (choice)
    { case 1:
        printf("\n  результат Merge-сортировки:\n");
        MergeSort(works, 0, N-1);
        print();
        break;
    case 2:
        printf("\n  результат Insert-сортировки:\n");
        InsertSort();
        print();
        break;
    case 3:
        printf("\n  результат Quick(Hoor)-сортировки:\n");
        HoorSort(works, 0, N-1);
        print();
        break;
    case 4:
        printf("\n  результат Sheke-сортировки:\n");
        ShekeSort(works, N);
        print();
        break;
    default:
        break;
    }
}
