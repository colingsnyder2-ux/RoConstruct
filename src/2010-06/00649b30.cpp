// from server: 100% by atomic.potato
extern "C" void __cdecl Func_00649a50(void *, double, const char *, int);

struct StatsItem_00649b30 {
    int value;
    void f(int *);
};

void StatsItem_00649b30::f(int *p)
{
    Func_00649a50(this, (double)*p, (const char *)0x00a07674, *p);
}
