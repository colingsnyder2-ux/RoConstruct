// from server: 67% by atomic.potato
extern "C" unsigned long __stdcall inet_addr(const char*);

struct Job {
    int run(int a, int b, int c, int d, int e, int f);
};

int Job::run(int a, int b, int c, int d, int e, int f)
{
    unsigned long x = inet_addr((const char*)f);
    return ((int (__thiscall*)(Job*, int, int, int, int, int, unsigned long))0x5134e0)(this, a, b, c, d, e, x);
}
