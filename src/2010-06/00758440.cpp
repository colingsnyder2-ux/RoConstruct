// from server: 100% by atomic.potato
struct S
{
    char padding[12];
    void* field_0C;
    void f();
};

extern "C" void __cdecl sub_758300(void*, int);
extern "C" void __cdecl sub_7A799A(void*);

void S::f()
{
    void* p = field_0C;
    if (p)
    {
        sub_758300(p, *((int*)p + 5));
        sub_7A799A(p);
    }
}
