// from server: 97% by atomic.potato
extern "C" void* __cdecl sub_833810(void*, int, void*);
extern "C" void __cdecl sub_428540(int);

struct S
{
    int __cdecl f(void*);
};

int __cdecl S::f(void* a)
{
    void* p = sub_833810(a, 1, *(void**)0x00de1408);
    int v = *(int*)p;
    if (v)
        sub_428540(v + 5);
    return 0;
}
