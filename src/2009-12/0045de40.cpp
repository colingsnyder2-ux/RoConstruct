// from server: 86% by atomic.potato
extern "C" int __stdcall Function_007f4aaa(void *, void *, void *, int);

struct StatsService
{
    int f(void *);
};

int StatsService::f(void *value)
{
    int result = Function_007f4aaa(value, (void *)0xaffe40, (void *)0xb09f64, 0);
    return result != 0;
}
