#pragma once
#include "stdlib.h"
#include <algorithm>


int SpawnList(int Max, int Min, int TNumber) {
	int List_1[100]={0};
	int a = 1;
	for (int i = 0; i < 100; i++) {
		List_1[i] = rand() % 100;
		if (List_1[i] > Max)
			List_1[i] = Max;
		if (List_1[i] < Min)
			List_1[i] = Min;
		//printf("%d\n",List_1[i]);
	};
	while (a) {
		int Add_Number = 0;
		for (int i = 0; i < 100; i++) {
			Add_Number += List_1[i];
		};
		float ANumber = Add_Number / static_cast<float>(100);
		printf("当前平均数为%f\n", ANumber);
		if (ANumber >= (TNumber - 1) && ANumber <= (TNumber + 1))
			a=0;
		for (int i = 0; i<100; i++) {
			if (List_1[i] < Max && ANumber <= TNumber-1) {
				List_1[i]++;
			}
			else if (List_1[i] > Min && ANumber >= TNumber + 1) {
				List_1[i]--;
			}
		}
	};
	sort(a, a + 100);
	for (int i = 0; i < 100; i++) {
		printf("%d ", List_1[i]);
	}
	return 0;
};
