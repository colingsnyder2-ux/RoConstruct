// from server: 100% by colin
struct S_func_00576a90 {
    char pad0[0x294];
    int m_field294;
    int m_field298;
    void* f(int);
};

extern "C" void __stdcall sub_576480();
extern "C" void (__cdecl *free)(void*);

void* S_func_00576a90::f(int arg)
{
    sub_576480();
    int* p = (int*)m_field298;
    m_field294 = 0x7a4cac;
    int v = p[1];
    *(int*)((char*)v + (int)this + 0x298) = 0x7a4ca4;
    if (arg & 1) {
        free(this);
    }
    return this;
}
