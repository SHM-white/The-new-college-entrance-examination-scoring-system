#pragma once
#include "stdlib.h"
#include <algorithm>
#include<random>
#include <chrono>
#include<ctime>
#include <fstream>
#include <format>
#include <string>
//#include <math.h>
//#include "OpenXLSX.hpp"

//using namespace OpenXLSX;

/*int main() {

	XLDocument doc;
	doc.create("Spreadsheet.xlsx");
	auto wks = doc.workbook().worksheet("Sheet1");

	wks.cell("A1").value() = "Hello, OpenXLSX!";

	doc.save();

	return 0;
}*/
/*double gaussrand()
{
	static double V1, V2, S;
	static int phase = 0;
	double X;

	if (phase == 0) {
		do {
			double U1 = (double)rand() / RAND_MAX;
			double U2 = (double)rand() / RAND_MAX;

			V1 = 2 * U1 - 1;
			V2 = 2 * U2 - 1;
			S = V1 * V1 + V2 * V2;
		} while (S >= 1 || S == 0);

		X = V1 * sqrt(-2 * log(S) / S);
	}
	else
		X = V2 * sqrt(-2 * log(S) / S);

	phase = 1 - phase;

	return X;
}*/
int SpawnList(int range, int Average_Number, int Length,int debug) {
	/*if (Length > 512) {
		printf("error");
		return 0;
	}
	double List_1[Length]={0};*/
	std::fstream file{};
	file.open("1.txt");
	if (!file.is_open()) {
		printf("error\n");
		return 0;
	};
	if (debug==2) {
		file << "debug mode\n";
		printf("done\n");
		return 0;
	};
	file << std::format("原始分\t等级\tY1\tY2\tT1\tT2\t转换分\n");
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	//int a = 1;
	//产生随机数引擎，采用time作为种子，以确保每次运行程序都会得到不同的结果
	static std::default_random_engine e(seed);
	//产生正态分布对象
	static std::normal_distribution<double> n(Average_Number, sqrt(range));
	for (int i{ 0 }; i < Length; i++) {
		file<<std::format("{:.0f}\t",n(e));
		file << std::format("=LOOKUP(1,0/(RANK(A{},A:A)/COUNTA(A:A)>{{0,0.15,0.5,0.85,0.98}}),{{\"A\",\"B\",\"C\",\"D\",\"E\"}})\t",i+2);
		file << std::format("=VLOOKUP($B{0},分数区间!$A:$E,@COLUMN(分数区间!B:B),0)\t=VLOOKUP($B{0},分数区间!$A:$E,@COLUMN(分数区间!C:C),0)\t=VLOOKUP($B{0},分数区间!$A:$E,@COLUMN(分数区间!D:D),0)\t=VLOOKUP($B{0},分数区间!$A:$E,@COLUMN(分数区间!E:E),0)\t",i+2);
		file << std::format("=(E{0}*(A{0}-D{0})+F{0}*(C{0}-A{0}))/(C{0}-D{0})\n",i+2);
		//List_1[i] = n(e);//把引擎作为参数，调用随机分布对象
		/*List_1[i] = rand() % 100;
		if (List_1[i] > Max)
			List_1[i] = Max;
		if (List_1[i] < Min)
			List_1[i] = Min;*/
		//printf("%d\n",List_1[i]);
	};
	file.close();
	printf("success\n");
	/*while (a) {
		int Add_Number = 0;
		for (int i = 0; i < 100; i++) {
			Add_Number += List_1[i];
		};
		float ANumber = Add_Number / static_cast<float>(100);
		printf("当前平均数为%f\n", ANumber);
		if (ANumber >= (Average_Number - 1) && ANumber <= (Average_Number + 1))
			a=0;
		for (int i = 0; i<100; i++) {
			if (List_1[i] < Max && ANumber <= Average_Number-1) {
				List_1[i]++;
			}
			else if (List_1[i] > Min && ANumber >= Average_Number + 1) {
				List_1[i]--;
			}
		}
	};*/
	//std::sort(List_1, List_1+100);
	/*for (int i = 0; i < Length; i++) {
		printf("%f ", List_1[i]);
	}*/
	return 0;
};
/*int PrintToXlsx() {
	XLDocument doc;
	doc.open("1.xlsx");
	auto wks = doc.workbook().worksheet("Sheet1");

	wks.cell("A1").value() = "Hello, OpenXLSX!";

	doc.save();
	return 0;
}*/