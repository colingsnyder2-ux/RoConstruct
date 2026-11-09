// from server: 77% by atomic.potato
extern "C" long __stdcall InterlockedIncrement(volatile long *);

struct S {
    int f(int);
};

int S::f(int value)
{
    char *p = reinterpret_cast<char *>(this) + 8;
    ((void (__thiscall *)(char *))0x666300)(p);
    return (int)InterlockedIncrement(reinterpret_cast<volatile long *>(p + 0x804));
}
