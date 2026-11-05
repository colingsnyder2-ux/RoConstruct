// from server: 80% by atomic.potato
struct S
{
    int __cdecl f(int);
};

extern "C" S *__cdecl sub_5dc670(void *);
extern "C" void __cdecl sub_62bea0(void *);

int __cdecl S::f(int)
{
    char buffer[136];
    S *p = sub_5dc670(buffer);
    int result = *(int *)((char *)p + 0x64);
    sub_62bea0(buffer);
    return result;
}
