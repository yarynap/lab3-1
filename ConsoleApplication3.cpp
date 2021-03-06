// ConsoleApplication3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "pch.h"
#include <stdio.h>
#include <math.h>

void sortFunc(float A[5][5]);
void calcFunc(float A[5][5]);

int main() {
	/*
	float array[5][5] = { {9, 24, -2, 86, -3},
	{40, 49, -4, -3, 0},
	{27, -76, 77, -1, 69},
	{71, -89, -94, -51, 50},
	{2, 96, 42, 36, -1} };
	*/
	float array[5][5];
	for (int y = 0; y < 5; y++) {
		printf("\nRow %d\n\n", y + 1);
		for (int z = 0; z < 5; z++) {
			printf("Number %d: ", z + 1);
			scanf_s("%f", &array[y][z]);
		}
	}

	sortFunc(array);
	calcFunc(array);

	printf("\n");
	/*system("pause");*/
	return 0;
}

void sortFunc(float A[5][5]) {
	int key, i;
	// int len = sizeof(A) / sizeof(int);

	for (int n = 0; n < 5; n++) {
		//A[][n]
		for (int j = 1; j < 5; j++) {
			key = A[j][n];
			i = j - 1;
			while (i >= 0 && A[i][n] < key) {
				A[i + 1][n] = A[i][n];
				i--;
			}
			A[i + 1][n] = key;
		}
	}

	for (int k = 0; k < 5; k++) {
		for (int l = 0; l < 5; l++)
			printf("%f\t", A[k][l]);
		printf("\n");
	}
}

void calcFunc(float A[5][5]) {
	// int len = sizeof(A) / sizeof(int);
	int isCount = 0;
	float res = 1.0, count = 0, F = 0;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (i > j) {
				res *= A[i][j];
				//count = count + 1.0;
				isCount = 1;
			}
		}
		if (isCount) {
			if (res < 0)
				res *= -1.0;
			count = count + 1.0;
			res = pow(res, (1.0 / count));
			printf("Geometric mean %d: %f\n", i + 1, res);
			F += res;
			res = 1.0;
			isCount = 0;
		}

	}
	printf("Sum: %f\n", F);
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
