// from server: 100% by atomic.potato
extern "C" void __stdcall sub_00977D20(void*, void*, double);

extern double g_00B5F4F8;

struct S
{
    void* f(void*, void*);
};

void* S::f(void* a, void* b)
{
    sub_00977D20(a, b, g_00B5F4F8);
    return a;
}
