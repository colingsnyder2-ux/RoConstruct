// from server: 43% by atomic.potato
extern "C" int __stdcall sub_006322E0(int);
extern void sub_007E1DF0();

struct S_func_00512C20 {
    void* m_vtbl;
    int m_field4;
    int m_field8;
    int m_fieldC;
    char m_field10;
    char m_field11;
    void* ctor(int a1, int a2, int a3);
};

void* S_func_00512C20::ctor(int a1, int a2, int a3)
{
    m_vtbl = (void*)0x99FD70;
    m_field4 = sub_006322E0(a1);
    if (*(char*)0xB901E4 != 0) {
        sub_007E1DF0();
    }
    m_vtbl = (void*)0x9BA0A4;
    m_field8 = 0xB18114;
    m_fieldC = sub_006322E0(a3);
    m_field10 = 0;
    m_field11 = 0;
    return this;
}
