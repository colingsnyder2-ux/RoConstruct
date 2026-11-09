// from server: 49% by atomic.potato
struct S_func_004623a0 {
    void* m_vtbl;
    void* m_obj;
    int m_8;
    int m_c;
    int m_10;
    int m_14;
    int m_18;
    char m_1c;
    char m_1d;
    char pad1e[2];
    int m_20;
    void f();
};

extern "C" int __stdcall DeleteObject(void*);
extern "C" void* __stdcall sub_b22170(void*);

void S_func_004623a0::f()
{
    void* p = m_obj;
    m_vtbl = (void*)0xb5754c;
    if (p != 0) {
        sub_b22170(p);
        m_obj = 0;
        m_8 = 0;
        m_c = 0;
        m_10 = 0;
        m_18 = 0;
        m_14 = 0;
        m_20 = -1;
        m_1d = 0;
        m_1c = 0;
    }
}
