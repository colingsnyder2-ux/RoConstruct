// from server: 53% by atomic.potato
struct S
{
    int f(void* a, void* b);
    int x[11];
};

extern "C" int __cdecl sub_7377c0(void*, void*);

int S::f(void* a, void* b)
{
    int local;
    void* p = (void*)x[10];
    void* q = *(void**)p;
    return ((int (__thiscall *)(void*, void*, int))(*(void**)q))(
        p, b, sub_7377c0(a, &local));
}
