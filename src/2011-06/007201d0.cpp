// from server: 76% by atomic.potato
typedef int (__thiscall *Method)(void *, void *);

extern "C" int __cdecl sub_5df060(void *, int *);

struct S
{
    int f(void *);
};

int S::f(void *arg)
{
    char *p = *(char **)((char *)this + 0x20);
    int value = (*(Method *)(*(char **)p + 8))(p, arg);
    return sub_5df060(&arg, &value);
}
