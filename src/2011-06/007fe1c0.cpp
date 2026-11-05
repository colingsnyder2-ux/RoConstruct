// from server: 36% by atomic.potato
struct S
{
    char pad0[0x2c];
    char cs[0x18];
    char pad1[0x4];
    char pad2[0x4];
    char *begin;
    char *end;

    void f();
};

extern "C" void __stdcall EnterCriticalSection(void *);
extern "C" void __stdcall LeaveCriticalSection(void *);
extern "C" void __stdcall sub_7fe0c0(void *, char *, char *, void *, void *);

void S::f()
{
    if ((end - begin) >> 3 > 0)
    {
        EnterCriticalSection(cs);
        sub_7fe0c0(&cs[0x1c], begin, end, (void*)0x7fd920, this);
        LeaveCriticalSection(cs);
    }
}
