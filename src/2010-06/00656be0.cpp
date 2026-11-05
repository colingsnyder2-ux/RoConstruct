// from server: 100% by atomic.potato
extern "C" int __cdecl sub_007a8bea(void *, void *, void *, void *, void *);

struct S_func_00656be0 {
    int f(void *);
};

int S_func_00656be0::f(void *arg)
{
    return sub_007a8bea(arg, 0, (void *)0x00b78e40, (void *)0x00bb9ff4, 0) != 0;
}
