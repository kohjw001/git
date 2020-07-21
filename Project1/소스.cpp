#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
int main(void) {
	int i = 0, n;
	int multiply[9];

	printf("\n1=9 의 정수를 입력:");

	while (1) {
		scanf("%d", &n);
		if (n < 0 || n>9)
			if (n < 0 || n>9)
				printf("\n1=9 정수를 입력하세요");
			else
				break;
	}
}