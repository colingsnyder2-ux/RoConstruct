// from server: 61% by atomic.potato
extern "C" void* __cdecl sub_0053f530(void*);

struct S
{
    void __cdecl f(void* a, void* b);
};

void S::f(void* a, void* b)
{
    *(void**)b = *(void**)sub_0053f530(b);
}
