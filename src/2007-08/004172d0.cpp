// from server: 100% by colin
struct S_func_004172d0 {
    int m_0;
    int m_4;
    int m_8;
    S_func_004172d0* f(char arg, int arg2);
};

extern "C" char __cdecl sub_4879d0(char* p);
extern "C" void* __cdecl sub_62fef6(int n);

S_func_004172d0* S_func_004172d0::f(char arg, int arg2)
{
    m_0 = 0;
    m_4 = 0;
    m_8 = 0;
    char local = arg;
    if (!sub_4879d0(&local)) {
        m_8 = 0x417150;
        m_0 = 0x417240;
        void* p = sub_62fef6(1);
        if (p) {
            *(char*)p = local;
        }
        m_4 = (int)p;
    }
    return this;
}
