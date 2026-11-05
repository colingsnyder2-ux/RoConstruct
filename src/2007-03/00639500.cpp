// from server: 60% by tester
extern "C" int __stdcall InterlockedIncrement(int*);

struct S_func_0044b5c0 {
    char pad0[164];
    int m_x;
    int f();
};

struct S {
    char pad0[0xf0];
    int m_f0;
    char pad1[0x4];
    int m_f8;
    char pad2[0x78];
    int m_174;
    int f(int);
};

extern int G1_func_0061e6d2();
extern int G1_func_00638d10();
extern int G1_func_00694260();
extern int G1_func_0061e672();
extern int G1_func_0073abb8();

int S::f(int arg)
{
    if (G1_func_0061e6d2() == -1)
        return 0;

    int edi = G1_func_00638d10();

    if (m_f8 != 6)
    {
        if (edi != 0)
        {
            G1_func_00694260();
        }
    }

    if (edi != 0)
    {
        if (m_174 != 0)
        {
            G1_func_0061e672();
            m_174 = 0;
        }
        int r = ((S_func_0044b5c0*)edi)->f();
        m_174 = r;
        if (r != 0)
        {
            InterlockedIncrement((int*)(r + 4));
            return 0;
        }
    }
    else
    {
        if (m_f0 == 2)
            return 0;
        G1_func_0073abb8();
    }
    return 0;
}
