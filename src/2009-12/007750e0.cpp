// from server: 42% by atomic.potato
struct S_func_007750e0 {
    char pad0[0x1c];
    int m_count1c;
    int m_count20;
    char pad24[0x4];
    int m_count28;
    char pad2c[0x4];
    int m_count30;
    int m_count34;
    int f(int a, int b);
};

struct T_func_007750e0 {
    char pad0[0x4];
    int m_count4;
    char pad8[0x4];
    int m_countc;
    int m_count10;
    char pad14[0x4];
    int m_count18;
    int m_count1c;
    char pad20[0x4];
    int m_count24;
    int m_count28;
    int m_count30;
    int m_count34;
};

extern "C" unsigned int __cdecl func_007addd0();
extern "C" void __cdecl func_006ca9f0();
extern "C" void __cdecl func_006cae30();
extern "C" void __cdecl func_006ccfc0();
extern "C" void __cdecl func_007b0f20();
extern "C" void __cdecl func_007c1260();
extern "C" void __cdecl func_007c1280();

int S_func_007750e0::f(int a, int b)
{
    T_func_007750e0* p = (T_func_007750e0*)a;
    char flag = (char)b;
    int i;
    func_006ca9f0();
    int n = (int)func_007addd0();
    if (n > 0) {
        for (i = 0; i < n; i++) {
            int j;
            for (j = 0; j < p->m_count1c; j++) {
                func_007c1280();
            }
            if (flag) {
                for (j = 0; j < m_count20; j++) {
                    func_007c1280();
                }
            } else {
                for (j = 0; j < p->m_count28; j++) {
                    func_007c1280();
                }
            }
            for (j = 0; j < p->m_count1c; j++) {
                func_007c1260();
            }
            for (j = 0; j < p->m_count34; j++) {
                func_007c1280();
            }
            for (j = 0; j < p->m_count4; j++) {
                func_007b0f20();
            }
            for (j = 0; j < p->m_count10; j++) {
                func_006ccfc0();
            }
        }
    }
    func_006cae30();
    return 0;
}
