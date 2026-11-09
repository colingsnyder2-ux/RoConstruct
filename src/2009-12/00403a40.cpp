// from server: 100% by atomic.potato
extern "C" int __stdcall sub_402b80(unsigned int);

struct S
{
    int f(void *);
};

extern "C" int (__cdecl *sub_98b778)(void *);

int S::f(void *arg)
{
    int value = sub_98b778(arg);
    if (value == 0)
        value = sub_402b80(0x8007000e);
    *(int *)this = value;
    return value;
}
