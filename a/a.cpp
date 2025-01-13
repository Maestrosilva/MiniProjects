
#include <iostream>

unsigned getLen(char* arr) {
	unsigned size = 0;
	while (arr[size++]);
	return size - 1;
}
unsigned getCount(char* arr, bool (*f) (char arr) ) {
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
		(squareroot(n - 1, dp) + n / squareroot(n - 1,dp)) / 2;
	}
	return dp[n - 1];
}
int main()
{
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
	// dp[n] = 1/2 (dp[n - 1) + n/dp[n - 1])
	double a[10] = { };
	std::cout << squareroot(10, a);
	
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
}
