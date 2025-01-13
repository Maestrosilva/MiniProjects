
#include <iostream>
//for random maps/arrays
#include <time.h>
#include <stdlib.h>
#include <vector>

unsigned getLen(char* arr) {
	unsigned size = 0;
	while (arr[size++]);
	return size - 1;
}
unsigned getCount(char* arr, bool (*f) (char arr)) {
	unsigned count = 0;
	unsigned size = getLen(arr);
	for (int i = 0; i < size; i++) {
		if (f(arr[i])) {
			count++;
		}
	}
	return count;
}
long long getFib(int n, long long* fib) {
	if (n <= 1) {
		fib[n] = n;
		return n;
	}
	if (fib[n - 1] != 0) {
		return fib[n - 1];
	}
	fib[n - 1] = getFib(n - 1, fib) + getFib(n - 2, fib);

	return fib[n - 1];
}

void print(long long* arr, int len) {
	std::cout << "["; for (int i = 0; i < len; i++) {
		std::cout << arr[i]; if (i < len - 1) {
			std::cout << ", ";
		}
	} std::cout << "]" << std::endl;
}

int getOcurrences(char* arr, char a, int index) {
	if (index >= getLen(arr)) {
		return 0;
	}
	return (arr[index] == a) + getOcurrences(arr, a, index + 1);
}

double squareroot(int n, double* dp) {
	if (n == 1) {
		return 1;
	}
	if (dp[n - 1] == 0) {
		dp[n - 1] = (squareroot(n - 1, dp) + n / squareroot(n - 1, dp)) / 2;
	}
	return dp[n - 1];
}

void printMap(short map[][5], const int X, const int Y) {
	for (int i = 0; i < X; i++) {
		for (int j = 0; j < Y; j++) {
			std::cout << map[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
void printMap(bool map[5][5], const int X, const int Y) {
	for (int i = 0; i < X; i++) {
		for (int j = 0; j < Y; j++) {
			std::cout << map[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int* findMatrixCoords(short map[5][5], int X, int Y) {
	for (int i = 0; i < X - 1; i++) {
		for (int j = 0; j < Y - 1; j++) {
			bool a = map[i][j];
			bool b = map[i + 1][j];
			bool c = map[i][j + 1];
			bool d = map[i + 1][j + 1];
			bool cond1 = a || b || c || d;
			bool cond2 = !a || !b || !c || !d;
			if (cond1 && cond2){
				int* res = new int[2];
				res[0] = i;
				res[1] = j;
				return res;
			}
		}
	}
}

int main()
{
	srand(time(0));
	//ex1
	//char arr[] = "nQk 9Kuv Str9 in9 g";
	//std::cout << "capitals: " << getCount(arr, [](char a) {
	//	return a >= 'A' && a <= 'Z'; }) << std::endl;
	//std::cout << "digits: " << getCount(arr, [](char a) {
	//	return a >= '0' && a <= '9'; }) << std::endl;
	//std::cout << "white_spaces: " << getCount(arr, [](char a) {
	//	return a == ' '; }) << std::endl;


	//ex2
	//long long fib[100] = {};
	//getFib(100, fib);
	//print(fib, 100);



	//ex3
	 //dp[n] = 1/2 (dp[n - 1) + n/dp[n - 1])
	//double a[54] = { };
	//std::cout << squareroot(54, a);

	//ex5
	const int X = 5;
	const int Y = 5;
	short map[X][Y];
	for (int i = 0; i < X; i++) {
		for (int j = 0; j < Y; j++) {
			map[i][j] = rand() % 5 ? 1 : 0;
		}
	}
	std::cout << std::endl;
	printMap(map, X, Y);
	bool dp[X][Y];
	for (int i = 0; i < X; i++) {
		for (int j = 0; j < Y; j++) {
			dp[i][j] = 0;
		}
	}
	dp[0][0] = map[0][0];

	for (int i = 1; i < X; i++) {
		dp[i][0] = dp[i - 1][0] && map[i][0];
	}
	for (int i = 1; i < Y; i++) {
		dp[0][i] = dp[0][i - 1] && map[0][i];
	}
	//printMap(dp, X, Y);
	for (int i = 1; i < X; i++) {
		for (int j = 1; j < Y; j++) {
			dp[i][j] = map[i][j] && (dp[i - 1][j] || dp[i][j - 1] || (i + 1 < X && dp[i + 1][j]) || (j + 1 < Y && dp[i][j + 1]));
		}
	}
	std::cout << std::endl;
	printMap(dp, X, Y);
	std::cout << (dp[X - 1][Y - 1] ? "YES" : "NO");

	//bonus1
	//const int X = 20;
	//const int Y = 20;
	//short map[X][Y];
	//for (int i = 0; i < X; i++) {
	//	for (int j = 0; j < Y; j++) {
	//		map[i][j] = (rand() % 5 ? 1: 0);
	//	}
	//}
	//printMap(map, X, Y);
	//map[0][0] = 1;
	//map[X - 1][Y - 1] = 0;
	//int* res = findMatrixCoords(map, X, Y);
	//std::cout << res[0] << ", " << res[1];


	//ex4
	//char str[] = "isipeqisisvirkam";
	//std::cout << getOcurrences(str, 'i', 0);

	//bonus 2
	//int a[] = {3, 6, 2, 7, 4, 8, 3, 2, 11, 7};
	//int len = 10;
	//int dp[10] = {1};
	//for (int i = 0; i < len; i++) {
	//	for (int j = i; j >= 0; j--) {
	//		if (a[i] > a[j]) {
	//			dp[i] = dp[i] > dp[j] + 1 ? dp[i] : dp[j] + 1;
	//		}
	//		else {
	//			dp[i] = dp[i] > dp[j] ? dp[i] : dp[j];
	//		}
	//	}
	//}
	//std::cout << dp[9];

	//bonus3
	//int* coordsh = new int[2];
	//int* coordsd = new int[2];
	//coordsh[0] = rand() % 8;
	//coordsh[1] = rand() % 8;
	//coordsd[0] = rand() % 8;
	//coordsd[1] = rand() % 8;
	//int chessboard[8][8];
	//chessboard[coordsh[0]][coordsh[1]] == 0;
	//int visited[8][8];
	//visited[coordsh[0]][coordsh[1]] == 0;
	//std::vector<int*> path;
	//std::vector<int*> toGo;
	//path.push_back(coordsh);
	//int* child1;
	//child1[0] = coordsh[]
	//if(inBounds()
	//std::cout << coordsh[0] << ", " << coordsh[1] << std::endl;
	//std::cout << coordsd[0] << ", " << coordsd[1] << std::endl;
}
