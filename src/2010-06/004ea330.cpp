// from server: 31% by atomic.potato
extern "C" void* __cdecl function_007a79a0(unsigned int);

struct T
{
    void g();
};

extern "C" void __fastcall function_0068bec0(void*);
extern "C" void __fastcall function_004e8c10(void*, void*, void*);

struct S
{
    void f(void* a, void* b);
};

void S::f(void* a, void* b)
{
    void* p = function_007a79a0(0x1ac);
    void* q = 0;
    if (p != 0)
    {
        function_0068bec0(p);
        q = p;
    }
    function_004e8c10(this, q, a);
}
