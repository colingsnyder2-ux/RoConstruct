// from server: 96% by atomic.potato
struct S_func_007e79e0 {
    char pad0[0x80];
    int m_80;
    char pad1[0x0C];
    int m_90;
    int m_94;
    void f();
};

extern "C" void* __stdcall sub_007e5d40(void*);

void S_func_007e79e0::f()
{
    int tmp[2];
    m_80 = 1;
    void* p = sub_007e5d40(tmp);
    m_90 = *(int*)p;
    m_94 = *(int*)((char*)p + 4);
}
