#include "_atoi.h"
#include <assert.h>

/************************************************************************
* @brief 替代 atoi 函数
* @author 袁沅祥
* @date 2018.11.11
* @ref 网易面试，问atoi实现的效率改进问题
* https://bbs.csdn.net/topics/80163798
************************************************************************/
int _atoi(const char *src)
{
	const char *p = src;
	static const int a[][10] = 
	{
		0, 1e0, 2e0, 3e0, 4e0, 5e0, 6e0, 7e0, 8e0, 9e0, 
		0, 1e1, 2e1, 3e1, 4e1, 5e1, 6e1, 7e1, 8e1, 9e1, 
		0, 1e2, 2e2, 3e2, 4e2, 5e2, 6e2, 7e2, 8e2, 9e2, 
		0, 1e3, 2e3, 3e3, 4e3, 5e3, 6e3, 7e3, 8e3, 9e3, 
		0, 1e4, 2e4, 3e4, 4e4, 5e4, 6e4, 7e4, 8e4, 9e4, 
		0, 1e5, 2e5, 3e5, 4e5, 5e5, 6e5, 7e5, 8e5, 9e5, 
		0, 1e6, 2e6, 3e6, 4e6, 5e6, 6e6, 7e6, 8e6, 9e6, 
		0, 1e7, 2e7, 3e7, 4e7, 5e7, 6e7, 7e7, 8e7, 9e7, 
		0, 1e8, 2e8, 3e8, 4e8, 5e8, 6e8, 7e8, 8e8, 9e8, 
		0, 1e9, 2e9, 3e9, 4e9, 5e9, 6e9, 7e9, 8e9, 9e9, 
	};
	if (*p){
		int s = 0;
		const int *n = a[0];
		while (*p && '.'!=*p) {_assert(('0'<=*p && *p<='9') || '-'==*p);++p;}
		_assert(p - src <= 10);
		while (--p != src) { s += n[(*p - '0')]; n += 10; }
		return ('-' != *p) ? s + n[(*p - '0')] : -s;
	}
	return 0;
}
