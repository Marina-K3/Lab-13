#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<iomanip>
using namespace std;
int Menu();
void ArraysA( ); /*инициализация*/
void ArraysB( );
void ArraysC();  /*пяти*/
void ArraysD( );
void ArraysE( );  /*массивов*/

void FreeA( ); /*освобождение*/
void FreeB( );
void FreeC( );
void FreeD();
void FreeE(); /*памяти*/
FILE* file;
int** a, ** b, ** c, ** d, ** e;
int* A, * B, * C, * D, * E;
int rowsA, columnsA;
int rowsB, columnsB;
int rowsC, columnsC;
int rowsD, columnsD;
int rowsE, columnsE;
int flag = 0;
int flag_to_sort=0;
void swap(int*, int*);
void BubleSort();
void MinSort();
void Mix();
void fromMatrixToArray();
void fromArrayToMatrix();
void Show();
void InsertSort();
void ShellSort();
void HoorSort();
void Search();
int Searche_Binary(int arr[], int, int, int);
void file_write(int);
void MergeSort(int*, int, int);
void Merge(int*,int, int);
void ShakeSort(int *, int);
void HeapSort(int arr[], int);
int main() {
	bool cycle = 1;
	while (cycle) {
		int choice = Menu();
		while (choice > 12 || choice < 1) choice = Menu();
		switch (choice)
		{
		case 1:
			cout << "\n   Masiv A\n Rows - ";
			cin >> rowsA;
			cout << " Columns - ";
			cin >> columnsA;
			ArraysA();

			cout << "\n   Masiv B\n Rows - ";
			cin >> rowsB;
			cout << " Columns - ";
			cin >> columnsB;
			ArraysB();

			cout << "\n   Masiv C\n Rows - ";
			cin >> rowsC;
			cout << " Columns - ";
			cin >> columnsC;
			ArraysC();

			cout << "\n   Masiv D\n Rows - ";
			cin >> rowsD;
			cout << " Columns - ";
			cin >> columnsD;
			ArraysD();

			cout << "\n   Masiv E\n Rows - ";
			cin >> rowsE;
			cout << " Columns - ";
			cin >> columnsE;
			ArraysE ();
			flag = 1; /*для освобождения памяти*/
			break;
		case 2:
		{

			if (flag == 1) {
				BubleSort();
				flag_to_sort = 1;
				int type;
				cout << " Nado zapisat' v fail ?\n 1 - Da  2 - Net\n Your choice - ";
				cin >> type;
				if (type == 1) file_write(1);
			}
		}
		break;
		case 3:
			if (flag == 1) {
				MinSort();
				flag_to_sort = 1;
				int type;
				cout << " Nado zapisat' v fail ?\n 1 - Da  2 - Net\n Your choice - ";
				cin >> type;
				if (type == 1) file_write(2);
			}
			break;
		case 4:
			if (flag == 1) {
				InsertSort();
				flag_to_sort = 1;
				int type;
				cout << " Nado zapisat' v fail ?\n 1 - Da  2 - Net\n Your choice - ";
				cin >> type;
				if (type == 1) file_write(3);
			}
			break;
		case 5:
			if (flag == 1) {
				ShellSort();
				flag_to_sort = 1;
				int type;
				cout << " Nado zapisat' v fail ?\n 1 - Da  2 - Net\n Your choice - ";
				cin >> type;
				if (type == 1) file_write(4);
			}
			break;
		case 6:
			if (flag == 1) {
				HoorSort();
				flag_to_sort = 1;
				int type;
				cout << " Nado zapisat' v fail ?\n 1 - Da  2 - Net\n Your choice - ";
				cin >> type;
				if (type == 1) file_write(5);
			}
			break;
		case 7:
			if (flag == 1) {
				fromMatrixToArray();
			    MergeSort(A, 0, rowsA*columnsA-1);
			    MergeSort(B, 0, rowsB * columnsB-1);
			    MergeSort(C, 0, rowsC * columnsC-1);
			    MergeSort(D, 0, rowsD * columnsD-1);
			    MergeSort(E, 0, rowsE * columnsE-1);
			    fromArrayToMatrix();
			    Show();
			    flag_to_sort = 1;
			    int type;
				cout << " Nado zapisat' v fail ?\n 1 - Da  2 - Net\n Your choice - ";
			    cin >> type;
			    if (type == 1) file_write(6);
				free(A);
				free(B);
				free(C);
				free(D);
				free(E);
		}
			break;
		case 8:
			if (flag == 1) {
				fromMatrixToArray();
			ShakeSort(A, rowsA*columnsA);
			ShakeSort(B, rowsB * columnsB);
			ShakeSort(C, rowsC* columnsC);
			ShakeSort(D, rowsD * columnsD);
			ShakeSort(E, rowsE * columnsE);
			fromArrayToMatrix();
			Show();
			free(A);
			free(B);
			free(C);
			free(D);
			free(E);
			flag_to_sort = 1;
			int type;
			cout << " Nado zapisat' v fail ?\n 1 - Da  2 - Net\n Your choice - ";
			cin >> type;
			if (type == 1) file_write(7);
		}
			break;
		case 9:
			if (flag == 1) {
				fromMatrixToArray();
;			HeapSort(A, rowsA*columnsA);
			HeapSort(B, rowsB * columnsB);
			HeapSort(C, rowsC * columnsC);
			HeapSort(D, rowsD * columnsD);
			HeapSort(E, rowsE * columnsE);
			fromArrayToMatrix();
			Show();
			free(A);
			free(B);
			free(C);
			free(D);
			free(E);
			flag_to_sort = 1;
			int type;
			cout << " Nado zapisat' v fail ?\n 1 - Da  2 - Net\n Your choice - ";
			cin >> type;
			if (type == 1) file_write(8);
		}
			break;
		case 10:
			if (flag == 1) Search();
			break;
		case 11: 
			if (flag == 1) { 
			  flag_to_sort = 0;
			  Mix(); 
			}
			break;
		case 12: {
			if (flag == 1) {
				FreeA();
				FreeB();
				FreeC();
				FreeD();
				FreeE();
			}
			cycle = 0;
			break; }
		default:
			break;
		}
	}
}

int Menu() {
	cout << "\n   ---------- MENU ---------" << endl;
	cout << "  1.Initilization arrays\n"
		<< "  2.Result of bubble sort\n"
		<< "  3.Result of min sort\n"
		<< "  4.Result of insert sort\n"
		<< "  5.Result of Shell sort\n"
		<< "  6.Result of Hoor sort\n"
		<< "  7.Result of Merge sort\n"
		<< "  8.Result of Sheke sort\n"
		<< "  9.Result of Heap sort\n"
		<< "  10.Poisk\n"
		<< "  11.Peremechat'\n"
		<< "  12.Vuchod\n";
	int choice;
	cout << "  your choice - ";
	cin >> choice;
	return choice;
}
void ArraysA() {
	a = (int**)malloc(rowsA * sizeof(int));
	for (int i = 0; i < rowsA; i++)
		a[i] = (int*)malloc(columnsA * sizeof(int));
	srand(unsigned(time(NULL)));
	for (int i = 0; i < rowsA; i++) {
		for (int j = 0; j < columnsA; j++) {
			a[i][j] = 0 + rand() % 100;
		}
	}
	cout << " Masiv A :\n";
	for (int i = 0; i < rowsA; i++) {
		for (int j = 0; j < columnsA; j++) {
			cout << setw(4) << a[i][j];
		}
		cout << "\n";
	}
}
void ArraysB() {
	b = (int**)malloc(rowsB * sizeof(int));
	for (int i = 0; i < rowsB; i++)
		b[i] = (int*)malloc(columnsB * sizeof(int));
	srand(unsigned(time(NULL)));
	for (int i = 0; i < rowsB; i++) {
		for (int j = 0; j < columnsB; j++) {
			b[i][j] = 0 + rand() % 100;
		}
	}
	cout << " Masiv B :\n";
	for (int i = 0; i < rowsB; i++) {
		for (int j = 0; j < columnsB; j++) {
			cout << setw(4) << b[i][j];
		}
		cout << "\n";
	}
}
void ArraysC() {
	c = (int**)malloc(rowsC * sizeof(int));
	for (int i = 0; i < rowsC; i++)
		c[i] = (int*)malloc(columnsC * sizeof(int));
	srand(unsigned(time(NULL)));
	for (int i = 0; i < rowsC; i++) {
		for (int j = 0; j < columnsC; j++) {
			c[i][j] = 0 + rand() % 100;
		}
	}
	cout << " Masiv C :\n";
	for (int i = 0; i < rowsC; i++) {
		for (int j = 0; j < columnsC; j++) {
			cout << setw(4) << c[i][j];
		}
		cout << "\n";
	}
}
void ArraysD() {
	d = (int**)malloc(rowsD * sizeof(int));
	for (int i = 0; i < rowsD; i++)
		d[i] = (int*)malloc(columnsD * sizeof(int));
	srand(unsigned(time(NULL)));
	for (int i = 0; i < rowsD; i++) {
		for (int j = 0; j < columnsD; j++) {
			d[i][j] = 0 + rand() % 100;
		}
	}
	cout << " Masiv D :\n";
	for (int i = 0; i < rowsD; i++) {
		for (int j = 0; j < columnsD; j++) {
			cout << setw(4) << d[i][j];
		}
		cout << "\n";
	}
}
void ArraysE() {
	e = (int**)malloc(rowsE * sizeof(int));
	for (int i = 0; i < rowsE; i++)
		e[i] = (int*)malloc(columnsE * sizeof(int));
	srand(unsigned(time(NULL)));
	for (int i = 0; i < rowsE; i++) {
		for (int j = 0; j < columnsE; j++) {
			e[i][j] = 0 + rand() % 100;
		}
	}
	cout << " Masiv E :\n";
	for (int i = 0; i < rowsE; i++) {
		for (int j = 0; j < columnsE; j++) {
			cout << setw(4) << e[i][j];
		}
		cout << "\n";
	}
}
void FreeA() {
	for (int i = 0; i < rowsA; i++)
		free(a[i]);
	free(a);
}
void FreeB() {
	for (int i = 0; i < rowsB; i++)
		free(b[i]);
	free(b);
}
void FreeC() {
	for (int i = 0; i < rowsC; i++)
		free(c[i]);
	free(c);
}
void FreeD() {
	for (int i = 0; i < rowsD; i++)
		free(d[i]);
	free(d);
}
void FreeE() {
	for (int i = 0; i < rowsE; i++)
		free(e[i]);
	free(e);
}
void swap(int* x, int* y)
{
	int t = *x; /*промежуточная переменная*/
	/* Перемена данных местами  */
	*x = *y;
	*y = t;
}


void BubleSort() {
	/*запись из матрицы в одномерный массив(для сортировки)*/
	fromMatrixToArray();
	/*пузырьковая сортировка*/
	int i, j;
	int n = rowsA * columnsA;
	for (i = 0; i < n; i++)
		for (j = n - 1; j > i; j--)
			if (A[j - 1] > A[j]) {
				swap(&A[j - 1], &A[j]);
			}
	n = rowsB * columnsB;
	for (i = 0; i < n; i++)
		for (j = n - 1; j > i; j--)
			if (B[j - 1] > B[j]) {
				swap(&B[j - 1], &B[j]);
			}

	n = rowsC * columnsC;
	for (i = 0; i < n; i++)
		for (j = n - 1; j > i; j--)
			if (C[j - 1] > C[j]) {
				swap(&C[j - 1], &C[j]);
			}
	n = rowsD * columnsD;
	for (i = 0; i < n; i++)
		for (j = n - 1; j > i; j--)
			if (D[j - 1] > D[j]) {
				swap(&D[j - 1], &D[j]);
			}


	n = rowsE * columnsE;
	for (i = 0; i < n; i++)
		for (j = n - 1; j > i; j--)
			if (E[j - 1] > E[j]) {
				swap(&E[j - 1], &E[j]);
			}

	/*запись из одномерного в дмумерный*/
	fromArrayToMatrix();

	Show();

	free(A);
	free(B);
	free(C);
	free(D);
	free(E);
}

void MinSort() {
	/*запись двумерного массива в одномерный (для сортировки)*/
	fromMatrixToArray();
	int Min;
	int N = rowsA * columnsA;
	for(int i = 0; i < N; i++) {
		Min = i;
		for(int j = i + 1; j < N; j++) {
			if(A[Min] > A[j])
				Min = j;
		}
		swap(&A[Min], &A[i]);
	}
	 N = rowsB * columnsB;
	for (int i = 0; i < N; i++) {
		Min = i;
		for (int j = i + 1; j < N; j++) {
			if (B[Min] > B[j])
				Min = j;
		}
		swap(&B[Min], &B[i]);
	}
	 N = rowsC * columnsC;
	for (int i = 0; i < N; i++) {
		Min = i;
		for (int j = i + 1; j < N; j++) {
			if (C[Min] > C[j])
				Min = j;
		}
		swap(&C[Min], &C[i]);
	}
	 N = rowsD * columnsD;
	for (int i = 0; i < N; i++) {
		Min = i;
		for (int j = i + 1; j < N; j++) {
			if (D[Min] > D[j])
				Min = j;
		}
		swap(&D[Min], &D[i]);
	}
	 N = rowsE * columnsE;
	for (int i = 0; i < N; i++) {
		Min = i;
		for (int j = i + 1; j < N; j++) {
			if (E[Min] > E[j])
				Min = j;
		}
		swap(&E[Min], &E[i]);
	}
	/*запись из одномерного в дмумерный*/
	fromArrayToMatrix();
	/*отображение массивов*/
	Show();
	
	free(A);
	free(B);
	free(C);
	free(D);
	free(E);
}
void Mix() {
	int p, h, buf;

	for (int i = 0; i < rowsA; i++) {
		for (int j = 0; j < columnsA; j++) {
			p = rand() % rowsA;
			h = rand() % columnsA;
			buf = a[i][j];
			a[i][j] = a[p][h];
			a[p][h] = buf;
		}
	}

	for (int i = 0; i < rowsB; i++) {
		for (int j = 0; j < columnsB; j++) {
			p = rand() % rowsB;
			h = rand() % columnsB;
			buf = b[i][j];
			b[i][j] = b[p][h];
			b[p][h] = buf;
		}
	}

	for (int i = 0; i < rowsC; i++) {
		for (int j = 0; j < columnsC; j++) {
			p = rand() % rowsC;
			h = rand() % columnsC;
			buf = c[i][j];
			c[i][j] = c[p][h];
			c[p][h] = buf;
		}
	}

	for (int i = 0; i < rowsD; i++) {
		for (int j = 0; j < columnsD; j++) {
			p = rand() % rowsD;
			h = rand() % columnsD;
			buf = d[i][j];
			d[i][j] = d[p][h];
			d[p][h] = buf;
		}
	}

	for (int i = 0; i < rowsE; i++) {
		for (int j = 0; j < columnsE; j++) {
			p = rand() % rowsE;
			h = rand() % columnsE;
			buf = e[i][j];
			e[i][j] = e[p][h];
			e[p][h] = buf;
		}
	}

	Show();
}
void fromMatrixToArray() {
	/*буфферные массивы для сортировки*/
	A = (int*)malloc(rowsA * columnsA * sizeof(int));
	B = (int*)malloc(rowsB * columnsB * sizeof(int));
	C = (int*)malloc(rowsC * columnsC * sizeof(int));
	D = (int*)malloc(rowsD * columnsD * sizeof(int));
	E = (int*)malloc(rowsE * columnsE * sizeof(int));
	/*запись двумерного массива в одномерный (для сортировки)*/
	int count = 0;
	for (int i = 0; i < rowsA; i++) {
		for (int j = 0; j < columnsA; j++) {
			A[count] = a[i][j];
			count++;
		}
	}

	count = 0;
	for (int i = 0; i < rowsB; i++) {
		for (int j = 0; j < columnsB; j++) {
			B[count] = b[i][j];
			count++;
		}
	}
	count = 0;
	for (int i = 0; i < rowsC; i++) {
		for (int j = 0; j < columnsC; j++) {
			C[count] = c[i][j];
			count++;
		}
	}
	count = 0;
	for (int i = 0; i < rowsD; i++) {
		for (int j = 0; j < columnsD; j++) {
			D[count] = d[i][j];
			count++;
		}
	}
	count = 0;
	for (int i = 0; i < rowsE; i++) {
		for (int j = 0; j < columnsE; j++) {
			E[count] = e[i][j];
			count++;
		}
	}
}
void fromArrayToMatrix() {
	int count;
	count = 0;
	for (int i = 0; i < rowsA; i++) {
		for (int j = 0; j < columnsA; j++) {
			a[i][j] = A[count];
			count++;
		}
	}
	count = 0;
	for (int i = 0; i < rowsB; i++) {
		for (int j = 0; j < columnsB; j++) {
			b[i][j] = B[count];
			count++;
		}
	}
	count = 0;
	for (int i = 0; i < rowsC; i++) {
		for (int j = 0; j < columnsC; j++) {
			c[i][j] = C[count];
			count++;
		}
	}
	count = 0;
	for (int i = 0; i < rowsD; i++) {
		for (int j = 0; j < columnsD; j++) {
			d[i][j] = D[count];
			count++;
		}
	}
	count = 0;
	for (int i = 0; i < rowsE; i++) {
		for (int j = 0; j < columnsE; j++) {
			e[i][j] = E[count];
			count++;
		}
	}
}
void Show() {
	cout << " Masiv A :\n";
	for (int i = 0; i < rowsA; i++) {
		for (int j = 0; j < columnsA; j++) {
			cout << setw(4) << a[i][j];
		}
		cout << "\n";
	}
	cout << " Masiv B :\n";
	for (int i = 0; i < rowsB; i++) {
		for (int j = 0; j < columnsB; j++) {
			cout << setw(4) << b[i][j];
		}
		cout << "\n";
	}
	cout << " Masiv C :\n";
	for (int i = 0; i < rowsC; i++) {
		for (int j = 0; j < columnsC; j++) {
			cout << setw(4) << c[i][j];
		}
		cout << "\n";
	}
	cout << " Masiv D :\n";
	for (int i = 0; i < rowsD; i++) {
		for (int j = 0; j < columnsD; j++) {
			cout << setw(4) << d[i][j];
		}
		cout << "\n";
	}
	cout << " Masiv E :\n";
	for (int i = 0; i < rowsE; i++) {
		for (int j = 0; j < columnsE; j++) {
			cout << setw(4) << e[i][j];
		}
		cout << "\n";
	}
}
void InsertSort() {
	int n;
	fromMatrixToArray();
	n = rowsA * columnsA;
	for(int i = 1; i < n; i++) {
		for (int j = i; j > 0 && A[j - 1] > A[j]; j--)
			swap(&A[j - 1], &A[j]);
	}
	n = rowsB * columnsB;
	for (int i = 1; i < n; i++) {
		for (int j = i; j > 0 && B[j - 1] > B[j]; j--)
			swap(&B[j - 1], &B[j]);
	}
	n = rowsC * columnsC;
	for (int i = 1; i < n; i++) {
		for (int j = i; j > 0 && C[j - 1] > C[j]; j--)
			swap(&C[j - 1], &C[j]);
	}
	n = rowsD * columnsD;
	for (int i = 1; i < n; i++) {
		for (int j = i; j > 0 && D[j - 1] > D[j]; j--)
			swap(&D[j - 1], &D[j]);
	}
	n = rowsE * columnsE;
	for (int i = 1; i < n; i++) {
		for (int j = i; j > 0 && E[j - 1] > E[j]; j--)
			swap(&E[j - 1], &E[j]);
	}
	fromArrayToMatrix();
	Show();

	free(A);
	free(B);
	free(C);
	free(D);
	free(E);
}
void ShellSort() {
	fromMatrixToArray();

	int n, i, j;     //две переменные цикла         
	int gap;     //шаг сортировки     
	int sorted;  //флаг окончания этапа сортировки
    n = rowsA * columnsA;
	for (gap = n / 2; gap > 0; gap /= 2)//начало сортировки
		do
		{
			sorted = 0;
			for (i = 0, j = gap; j < n; i++, j++)
				if (*(A + i) > *(A + j))
				{
					swap((A + i), (A + j));
					sorted = 1;
				}
		} while (sorted);

		n = rowsB * columnsB;
		for (gap = n / 2; gap > 0; gap /= 2)//начало сортировки
			do
			{
				sorted = 0;
				for (i = 0, j = gap; j < n; i++, j++)
					if (*(B + i) > *(B + j))
					{
						swap((B + i), (B + j));
						sorted = 1;
					}
			} while (sorted);

		n = rowsC * columnsC;
			for (gap = n / 2; gap > 0; gap /= 2)//начало сортировки
				do
				{
					sorted = 0;
					for (i = 0, j = gap; j < n; i++, j++)
						if (*(C + i) > *(C + j))
						{
							swap((C + i), (C + j));
							sorted = 1;
						}
				} while (sorted);

			n = rowsD * columnsD;
				for (gap = n / 2; gap > 0; gap /= 2)//начало сортировки
					do
					{
						sorted = 0;
						for (i = 0, j = gap; j < n; i++, j++)
							if (*(D + i) > *(D + j))
							{
								swap((D + i), (D + j));
								sorted = 1;
							}
					} while (sorted);

			n = rowsE * columnsE;
					for (gap = n / 2; gap > 0; gap /= 2)//начало сортировки
						do
						{
							sorted = 0;
							for (i = 0, j = gap; j < n; i++, j++)
								if (*(E + i) > *(E + j))
								{
									swap((E + i), (E + j));
									sorted = 1;
								}
						} while (sorted);
	fromArrayToMatrix();
	Show();
	free(A);
	free(B);
	free(C);
	free(D);
	free(E);
}
void QuickSort(int a[], int left, int right)
{
	int i = left, j = right; /*Инициализируем переменные левой и
правой границами подмассива*/
	int test = a[(left + right) / 2]; /*Выбираем в качестве
	 элемента разбиения средний элемент массива*/
	do {
		while (a[i] < test)
			i++;
		/*находим элемент, больший элемента разбиения */
		while (a[j] > test)
			j--;
		/*находим элемент, меньший элемента разбиения */
		if (i <= j)
		{
			swap(&a[i], &a[j]);
			i++; j--;
		}
	} while (i <= j);   /*рекурсивно вызываем алгоритм для
                          правого и левого подмассива*/
	if (i < right)
		QuickSort(a, i, right);
	if (j > left)
		QuickSort(a, left, j);
}

void HoorSort() {
	fromMatrixToArray();
	QuickSort(A,0,rowsA*columnsA-1);
	QuickSort(B,0,rowsB*columnsB-1);
	QuickSort(C,0,  rowsC * columnsC - 1);
	QuickSort(D,0, rowsD * columnsD - 1);
	QuickSort(E,0, rowsE * columnsE - 1);
	fromArrayToMatrix();
	Show();
	free(A);
	free(B);
	free(C);
	free(D);
	free(E);
}
void linearSearch() {
	int element;
	char massiv;
	cout << "\n 1.Sredi vsex masivov\n 2.Sredi odnogo masiva\n";
	int choice;
	cin >> choice;
	if (choice > 2 || choice < 1) main();
	switch (choice)
	{
	case 1: {
		cout << " Vvedite iskomuy element - ";
		cin >> element;
		for (int i = 0; i < rowsA; i++) {
			for (int j = 0; j < columnsA; j++) {
				if (a[i][j] == element)
					cout << " Masiv A element [" << i + 1 << "][" << j + 1 << "]" << endl;
			}
		}
		for (int i = 0; i < rowsB; i++) {
			for (int j = 0; j < columnsB; j++) {
				if (b[i][j] == element)
					cout << " Masiv B element [" << i + 1 << "][" << j + 1 << "]" << endl;
			}
		}
		for (int i = 0; i < rowsC; i++) {
			for (int j = 0; j < columnsC; j++) {
				if (c[i][j] == element)
					cout << " Masiv C element [" << i + 1 << "][" << j + 1 << "]" << endl;
			}
		}
		for (int i = 0; i < rowsD; i++) {
			for (int j = 0; j < columnsD; j++) {
				if (d[i][j] == element)
					cout << " Masiv D element [" << i + 1 << "][" << j + 1 << "]" << endl;
			}
		}
		for (int i = 0; i < rowsE; i++) {
			for (int j = 0; j < columnsE; j++) {
				if (e[i][j] == element)
					cout << " Masiv E element [" << i + 1 << "][" << j + 1 << "]" << endl;
			}
		}
	}
		break;
	case 2: {
		int flag = 0;
		cout << " Vvedite iskomuy element - ";
		cin >> element;
		cout << " Vvedite nazvanie massiva (A, B, C, D, E): ";
		cin >> massiv;
		switch (massiv)
		{
		case 'A':
			for (int i = 0; i < rowsA; i++) {
				for (int j = 0; j < columnsA; j++) {
					if (a[i][j] == element)
					{
						cout << " Masiv A element [" << i + 1 << "][" << j + 1 << "]" << endl;
						flag = 1;
					}
				}
			}
			break;
		case 'B':
			for (int i = 0; i < rowsB; i++) {
				for (int j = 0; j < columnsB; j++) {
					if (b[i][j] == element)
					{
						cout << " Masiv B element [" << i + 1 << "][" << j + 1 << "]" << endl;
						flag = 1;
					}
				}
			}
			break;
		case 'C':
			for (int i = 0; i < rowsC; i++) {
				for (int j = 0; j < columnsC; j++) {
					if (c[i][j] == element)
					{
						cout << " Masiv C element [" << i + 1 << "][" << j + 1 << "]" << endl;
						flag = 1;
					}
				}
			}
			break;
		case 'D':
			for (int i = 0; i < rowsD; i++) {
				for (int j = 0; j < columnsD; j++) {
					if (d[i][j] == element)
					{
						cout << " Masiv D element [" << i + 1 << "][" << j + 1 << "]" << endl;
						flag = 1;
					}
				}
			}
			break;
		case 'E':
			for (int i = 0; i < rowsE; i++) {
				for (int j = 0; j < columnsE; j++) {
					if (e[i][j] == element)
					{
						cout << " Masiv E element [" << i + 1 << "][" << j + 1 << "]" << endl;
						flag = 1;
					}
				}
			}
			break;
		default:
			break;
		}
		if (flag == 0) cout << "\n Net takogo elementa\n";
	}
		break;
	default:
		break;
	}
}
void binarySearch() {
	int element;
	char massiv;
	cout << "\n 1.Sredi vsex masivov\n 2.Sredi odnogo masiva\n";
	int choice;
	cin >> choice;
	if (choice > 2 || choice < 1) main();
	switch (choice)
	{
	case 1: {
		fromMatrixToArray();
		cout << " Vvedite iskomuy element - ";
		cin >> element;
		int m, n;
		n = rowsA * columnsA;
		m = Searche_Binary(A, 0, n, element);
		if (m == -1) cout << " Net elementa\n";
		else cout << " Masiv A element [" << m/2 + 1 << "][" << m%2 + 1 << "]" << endl;

		n = rowsB * columnsB;
		m = Searche_Binary(B, 0, n, element); 
		if (m == -1) cout << " Net elementa\n";
		else cout << " Masiv B element [" << m / 2 + 1 << "][" << m % 2 + 1 << "]" << endl;

		n = rowsC * columnsC;
		m = Searche_Binary(C, 0, n, element);
		if (m == -1) cout << " Net elementa\n";
		else cout << " Masiv C element [" << m / 2 + 1 << "][" << m % 2 + 1 << "]" << endl;

		n = rowsD * columnsD;
		m = Searche_Binary(D, 0, n, element);
		if (m == -1) cout << " Net elementa\n";
		else cout << " Masiv D element [" << m / 2 + 1 << "][" << m % 2 + 1 << "]" << endl;

		n = rowsE * columnsE;
		m = Searche_Binary(E, 0, n, element);
		if (m == -1) cout << " Net elementa\n";
		else cout << " Masiv E element [" << m / 2 + 1 << "][" << m % 2 + 1 << "]" << endl;

		free(A);
		free(B);
		free(C);
		free(D);
		free(E);
	}
		  break;
	case 2: {
		int m, n;
		fromMatrixToArray();
		
		cout << " Vvedite iskomuy element - ";
		cin >> element;
		cout << " Vvedite nazvanie massiva (A, B, C, D, E): ";
		cin >> massiv;
		switch (massiv)
		{
		case 'A': 
			n = rowsA * columnsA;
			m = Searche_Binary(A, 0, n, element);
			if (m == -1) cout << " Net elementa";
			 else cout << " Masiv A element [" << m / 2 + 1 << "][" << m % 2 + 1 << "]" << endl;
			break;
		case 'B':
			n = rowsB * columnsB;
			m = Searche_Binary(B, 0, n, element);
			if (m == -1) cout << " Net elementa";
			else cout << " Masiv B element [" << m / 2 + 1 << "][" << m % 2 + 1 << "]" << endl;
			break;
		case 'C':
			n = rowsC * columnsC;
			m = Searche_Binary(C, 0, n, element);
			if (m == -1) cout << " Net elementa";
			else cout << " Masiv C element [" << m / 2 + 1 << "][" << m % 2 + 1 << "]" << endl;

			break;
		case 'D':
			n = rowsD * columnsD;
			m = Searche_Binary(D, 0, n, element);
			if (m == -1) cout << " Net elementa";
			else cout << " Masiv D element [" << m / 2 + 1 << "][" << m % 2 + 1 << "]" << endl;

			break;
		case 'E':
			n = rowsE * columnsE;
			m = Searche_Binary(E, 0, n, element);
			if (m == -1) cout << " Net elementa";
			else cout << " Masiv E element [" << m / 2 + 1 << "][" << m % 2 + 1 << "]" << endl;

			break;
		default:
			break;
		}
		
		free(A);
		free(B);
		free(C);
		free(D);
		free(E);
	}
		  break;
	default:
		break;
	}
}
void Search() {
	int choice;
	cout << "\n     Menu Poiska";
	cout << "\n 1.Posledovatel’nyi poisk\n 2.Binarnyi poik";
	cout << "\n Your choice - ";
	cin >> choice;
	if (choice > 2 || choice < 1) main();
	switch (choice)
	{
	case 1:
		linearSearch();
		break;
	case 2:
		if (flag_to_sort == 1)binarySearch();
		else main;
		break;
	default:
		break;
	}
}
int Searche_Binary(int arr[], int left, int right, int key)
{
	int midd = 0;
	while (1)
	{
		midd = (left + right) / 2;

		if (key < arr[midd])       // если искомое меньше значения в ячейке
			right = midd - 1;      // смещаем правую границу поиска
		else if (key > arr[midd])  // если искомое больше значения в ячейке
			left = midd + 1;    // смещаем левую границу поиска
		else                       // иначе (значения равны)
			return midd;           // функция возвращает индекс ячейки

		if (left > right)          // если границы сомкнулись 
			return -1;
	}
}
void file_write(int count)
{
	fopen_s(&file, "result_sort.txt", "a+");
		fprintf(file, "\t\tRESULTS OF SORTS\n");
	if (count == 1)
		fprintf(file, "\n   1.Bubble Sort:\n");
	if (count == 2)
		fprintf(file, "\n   2.Min Sort:\n");
	if (count == 3)
		fprintf(file, "\n   3.Insert Sort:\n");
	if (count == 4)
		fprintf(file, "\n   4.Shell Sort:\n");
	if (count == 5)
		fprintf(file, "\n   5.Hoare Sort:\n");
	if (count == 6)
		fprintf(file, "\n   5.Merge Sort:\n");
	if (count == 7)
		fprintf(file, "\n   5.Shake Sort:\n");
	if (count == 8)
		fprintf(file, "\n   5.Heap Sort:\n");
	fprintf(file, "\t\t Matrix A\n");
	for (int i = 0; i < rowsA; i++) {
		for (int j = 0; j < columnsA; j++)
			fprintf(file, "%d ", a[i][j]);
		fprintf(file, "%c", '\n');
	}
	fprintf(file, "\t\t Matrix B\n");
	for (int i = 0; i < rowsB; i++) {
		for (int j = 0; j < columnsB; j++)
			fprintf(file, "%d ", b[i][j]);
		fprintf(file, "%c", '\n');
	}
	fprintf(file, "\t\t Matrix C\n");
	for (int i = 0; i < rowsC; i++) {
		for (int j = 0; j < columnsC; j++)
			fprintf(file, "%d ", c[i][j]);
		fprintf(file, "%c", '\n');
	}
	fprintf(file, "\t\t Matrix D\n");
	for (int i = 0; i < rowsD; i++) {
		for (int j = 0; j < columnsD; j++)
			fprintf(file, "%d ", d[i][j]);
		fprintf(file, "%c", '\n');
	}
	fprintf(file, "\t\t Matrix E\n");
	for (int i = 0; i < rowsE; i++) {
		for (int j = 0; j < columnsE; j++)
			fprintf(file, "%d ", e[i][j]);
		fprintf(file, "%c", '\n');
	}
	fclose(file);
}
void Merge(int*A, int first, int last){
	
	int middle, start, final, j;
	int* mas = new int[100];
	middle = (first + last) / 2; //вычисление среднего элемента
	start = first; //начало левой части
	final = middle + 1; //начало правой части
	for (j = first; j <= last; j++) //выполнять от начала до конца
		if ((start <= middle) && ((final > last) || (A[start] < A[final])))
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
void MergeSort( int *A, int first, int last)
{
	
	{
		if (first < last)
		{
			MergeSort(A, first, (first + last) / 2); //сортировка левой части
			MergeSort(A,(first + last) / 2 + 1, last); //сортировка правой части
			Merge(A,first, last); //слияние двух частей
		}
	}
}

void ShakeSort(int*mass, int count){
	int left = 0, right = count - 1; // левая и правая границы сортируемой области массива
	int flag = 1;  // флаг наличия перемещений
	// Выполнение цикла пока левая граница не сомкнётся с правой
	// и пока в массиве имеются перемещения
	while ((left < right) && flag > 0)
	{
		flag = 0;
		for (int i = left; i < right; i++)  //двигаемся слева направо
		{
			if (mass[i] > mass[i + 1]) // если следующий элемент меньше текущего,
			{             // меняем их местами
				int t = mass[i];
				mass[i] = mass[i + 1];
				mass[i + 1] = t;
				flag = 1;      // перемещения в этом цикле были
			}
		}
		right--; // сдвигаем правую границу на предыдущий элемент
		for (int i = right; i > left; i--)  //двигаемся справа налево
		{
			if (mass[i - 1] > mass[i]) // если предыдущий элемент больше текущего,
			{            // меняем их местами
				double t = mass[i];
				mass[i] = mass[i - 1];
				mass[i - 1] = t;
				flag = 1;    // перемещения в этом цикле были
			}
		}
		left++; // сдвигаем левую границу на следующий элемент
	}
}
void heapify(int arr[], int n, int i)
{
	int largest = i;
	// Инициализируем наибольший элемент как корень
	int l = 2 * i + 1; // левый = 2*i + 1
	int r = 2 * i + 2; // правый = 2*i + 2

 // Если левый дочерний элемент больше корня
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// Если правый дочерний элемент больше, чем самый большой элемент на данный момент
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// Если самый большой элемент не корень
	if (largest != i)
	{
		swap(arr[i], arr[largest]);

		// Рекурсивно преобразуем в двоичную кучу затронутое поддерево
		heapify(arr, n, largest);
	}
}

void HeapSort(int arr[], int n){// Построение кучи (перегруппируем массив)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// Один за другим извлекаем элементы из кучи
	for (int i = n - 1; i >= 0; i--)
	{
		// Перемещаем текущий корень в конец
		swap(arr[0], arr[i]);

		// вызываем процедуру heapify на уменьшенной куче
		heapify(arr, i, 0);
	}
}