// from server: 46% by atomic.potato
typedef int (__thiscall *Fn495f40)(void *);
typedef int (__cdecl *Fn983b6a)(int);
typedef int (__thiscall *FnB229ec)(void *, int);

struct S
{
    void *field0c;
    unsigned char f();
};

unsigned char S::f()
{
    int value;
    int converted;

    value = ((Fn495f40)0x495f40)((void *)((*(void **)((char *)field0c + 0xac4))));
    if (!value)
        return 0;

    converted = ((Fn983b6a)0x983b6a)(value);
    return (unsigned char)((FnB229ec)0xb229ec)((void *)0xdae1d8, converted);
}
