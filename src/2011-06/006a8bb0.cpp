// from server: 77% by colin
struct S_func_006a8bb0 {
    void* m_vtbl;
    int m_field4;
    int m_field8;
    char m_pad[8];
    int m_field14;
    int m_field18;
    int m_field1c;
    void f(void* arg);
};

extern "C" char __fastcall sub_007f8d00(int* p);
extern "C" void __fastcall sub_007f8c90(int* p);

void S_func_006a8bb0::f(void* arg)
{
    if (sub_007f8d00(&m_field14))
        return;

    int* p4 = (int*)m_field4;
    int* a4 = (int*)((char*)arg + 4);
    if (*a4 != p4[1])
        return;

    int* p8;
    if (m_field8)
        p8 = (int*)((char*)m_field8 + 0x1c);
    else
        p8 = 0;

    int* c = (int*)p4[7];
    int* vt = (int*)*c;
    int (*fn)(int*, int*) = (int (*)(int*, int*))vt[2];
    int r = fn(c, p8);
    if (r > 0) {
        if (sub_007f8d00(&m_field18))
            return;
        int* vt2 = (int*)m_vtbl;
        void (*fn2)() = (void (*)())vt2[0];
        fn2();
        return;
    }

    if (sub_007f8d00(&m_field18))
        return;
    sub_007f8c90(&m_field18);
}
