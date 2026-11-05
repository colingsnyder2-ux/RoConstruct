// from server: 80% by atomic.potato
struct S
{
    int f();
};

extern "C" void * __cdecl sub_5dc670(void *);
extern "C" void __cdecl sub_62bea0(void *);

int S::f()
{
    char buffer[136];
    void *p = sub_5dc670(buffer);
    int result = *(int *)((char *)p + 8);
    sub_62bea0(buffer);
    return result;
}
