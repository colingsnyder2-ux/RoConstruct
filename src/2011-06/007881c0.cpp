// from server: 100% by atomic.potato
struct S
{
    char f();
    int pad0;
    int pad1;
    int pad2;
};

typedef int (__cdecl *CallType)(int);
typedef int (__thiscall *CompareType)(int, const void *);

extern "C" int __cdecl sub_80bbc2(int);
extern CompareType g_call;

char S::f()
{
    int eax = *(int *)((char *)this + 12);
    int ecx = *(int *)((char *)eax + 2764);
    eax = *(int *)((char *)ecx + 392);
    if (eax)
    {
        eax = sub_80bbc2(eax);
        return g_call(0xC90AD8, (const void *)eax);
    }
    return 0;
}
