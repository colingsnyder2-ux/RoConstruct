// from server: 43% by atomic.potato
struct S_func_006e58b0 {
    char pad0[0x38];
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    void f(int, int);
};

extern "C" int __cdecl G1_func_005a83b0();
extern "C" int __cdecl G2_func_007a8bea(int, int, int, int, int);
extern "C" void __cdecl G3_func_007a89b2(int);
extern "C" void __cdecl G4_func_009ea89c(int);

void S_func_006e58b0::f(int a, int b)
{
    int v8 = m_40;
    int vc;
    if (m_44) {
        vc = (*(int (__thiscall **)(int))(*(int *)m_44 + 8))(m_44);
    } else {
        vc = 0;
    }
    (*(void (__thiscall **)(int, int *, int))(*(int *)a + 4))(a, &v8, 1);
    int edi = G2_func_007a8bea(0, 0xbda118, 0xb79040, 0, vc);
    if (!edi) {
        G4_func_009ea89c(0xa00a54);
        G3_func_007a89b2(0xb12290);
    }
    int *p = (int *)G1_func_005a83b0();
    int tmp[7];
    tmp[0] = 0xa1ac90;
    tmp[1] = p[1];
    tmp[2] = p[2];
    tmp[3] = p[3];
    tmp[4] = p[4];
    tmp[5] = p[5];
    tmp[6] = p[6];
    (*(void (__thiscall **)(int, int *))(m_38))(m_3c + edi, tmp);
    if (vc) {
        (*(void (__thiscall **)(int, int))(*(int *)vc))(vc, 1);
    }
}
