#pragma once

#ifdef _DEBUG
#define _assert(p) assert(p);
#else
#define _assert(p) if(!(p)) return 0;
#endif

int _atoi(const char *src);
