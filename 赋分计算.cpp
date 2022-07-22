// 赋分计算.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "赋分计算.h"
#include "stdlib.h"
#include <algorithm>

int main()
{
    int a{};
    int b{};
    int c{};
    int d{};
    std::cout << "输入需要生成的随机数数量(建议100)(<1 debug mode)" << std::endl;
    std::cin >> a;
    if (a == 0) {
        SpawnList(80, 55, 100,1);
        system("pause");
        return 0;
    };
    if (a < 1) {
        SpawnList(80, 55, 100, 2);
        system("pause");
        return 0;
    }
    std::cout << "输入需要生成的随机数的极差(建议80)" << std::endl;
    std::cin >> b;
    if (b < 1)
        b = 1;
    std::cout << "输入需要生成的随机数平均值(建议55)" << std::endl;
    std::cin >> d;
    SpawnList(b,d,a,0);
    //PrintToXlsx();
    //std::cout << "Hello World!\n";
    system("pause");
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
