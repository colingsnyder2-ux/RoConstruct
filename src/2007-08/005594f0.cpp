// from server: 100% by colin
struct S_func_005594f0 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    char m14;
    S_func_005594f0* f(S_func_005594f0* a1);
};

S_func_005594f0* S_func_005594f0::f(S_func_005594f0* a1)
{
    m0 = a1->m0;
    m4 = 0;
    m8 = 0;
    mC = 0;
    if (a1->m4 != 0) {
        mC = a1->mC;
        m4 = a1->m4;
        m8 = ((int (__cdecl *)(int, int))a1->m4)(a1->m8, 0);
    }
    m10 = a1->m10;
    m14 = a1->m14;
    return this;
}
