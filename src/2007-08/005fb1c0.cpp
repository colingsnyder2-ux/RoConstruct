// from server: 100% by colin
struct S_func_005fb1c0
{
    char pad0[0x2d4];
    int m_field2d4;
    int m_field2d8;
    void* f(int a);
};

extern "C" void __stdcall sub_005fb120();
extern "C" void (__cdecl *g_free)(void*);

void* S_func_005fb1c0::f(int a)
{
    sub_005fb120();
    int* p = (int*)m_field2d8;
    m_field2d4 = 0x7a4cac;
    int* q = (int*)p[1];
    *(int*)((char*)q + (int)this + 0x2d8) = 0x7a4ca4;
    if (a & 1)
    {
        g_free(this);
    }
    return this;
}
