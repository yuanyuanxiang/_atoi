
#include "_atoi.h"
#include <windows.h>
#include <stdio.h>
#include <time.h>
#include <assert.h>

#ifdef _DEBUG
// 随机数个数
#define NUMS 100
// 循环次数
#define TIMES 10000
#else
#define NUMS 1000
#define TIMES 100000
#endif

typedef char str12[20];

int main()
{
	int s1 = _atoi("");
	int s2 = _atoi("-");
	int s3 = _atoi("250.123");
	int s4 = _atoi("-360");
	int s5 = _atoi("123456789");
	int s6 = _atoi("-123456789");

	assert(NUMS <= 1e8);
	srand(time(NULL));
	// 生成随机浮点数
	str12 p[NUMS];
	const int m = 1e9;
	for (int i = 0; i < NUMS; ++i)
	{
		int d = rand() % m;
		sprintf_s(p[i], "%d", d);
	}
	int _s[NUMS] = {0}, s[NUMS] = {0};
	// _atof
	clock_t t = clock();
	for (int n = 0; n < TIMES; ++n)
	{
		for (int i = 0; i < NUMS; ++i)
			_s[i] = _atoi(p[i]);
	}
	int tm1 = t = clock() - t;
	printf("_atof using time: %dms\n", t);
	// atof
	t = clock();
	for (int n = 0; n < TIMES; ++n)
	{
		for (int i = 0; i < NUMS; ++i)
			s[i] = atoi(p[i]);
	}
	int tm2 = t = clock() - t;
	printf("atof using time: %dms\n", t);

	// 比较差异
	for (int i = 0; i < NUMS; ++i)
	{
		if(1e-15 < _s[i] - s[i])
			printf("_atoi[%d]= d, atoi[d]= %d\n", _s[i], s[i]);
	}
	printf("speed up: %f\n", 1.0 * tm2 / tm1);

	system("PAUSE");

	return 0;
}
