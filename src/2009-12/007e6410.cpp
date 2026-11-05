// from server: 77% by atomic.potato
struct S_func_0052f670 {
    int m_x;
    int f();
};

struct S_func_007e6410 {
    char pad0[8];
    char m_flag8;
    char pad9[0x37];
    int m_44;
    char pad48[8];
    int m_50;
    char pad54[0x14];
    double m_68;
    int m_70;
    double m_78;
    double m_80;
    char m_88;
    char pad89[7];
    double m_90;
    int m_98;
    double m_a0;
    double m_a8;
    char m_b0;
    char padb1[7];
    double m_b8;
    int m_c0;
    double m_c8;
    double m_d0;
    char m_d8;
    char padd9[0x3f];
    double m_118;
    double m_120;
    double m_128;
    double m_130;
    char m_138;
    char pad139[0x2f];
    int m_168;
    char pad16c[0x24];
    S_func_0052f670 m_190;
    void f();
};

extern "C" unsigned long __stdcall WaitForSingleObject(void*, unsigned long);
extern void* g_98b258;

void S_func_007e6410::f()
{
    int* p = (int*)&m_190;
    int v = ((S_func_0052f670*)p)->f();
    unsigned long r = WaitForSingleObject(g_98b258, v);
    if (r != 0x102)
        return;
    for (;;) {
        double d;
        if (m_flag8)
            d = 1.0;
        else
            d = 0.0;
        int hi = *(int*)((char*)&d + 4) & 0x7ff00000;
        if (hi != 0x7ff00000) {
            if (m_138) {
                // keep d
            } else {
                double t = d - m_118;
                t = t * m_128;
                double u = m_118 * d;
                d = t + u;
            }
            m_128 = d;
            m_138 = 0;
            double old = m_120;
            m_120 = d;
            double diff = old - d;
            diff = diff * diff;
            diff = diff * m_118;
            double t2 = d - m_118;
            t2 = t2 * m_130;
            m_130 = diff + t2;
        }
        int a = m_50;
        int c = a + 0x7fffffff;
        if ((unsigned)c <= 0xfffffffeu) {
            double fd = (double)a;
            if (m_b0) {
                // keep fd
            } else {
                double t = fd - m_90;
                t = t * m_a0;
                double u = m_90 * fd;
                fd = t + u;
            }
            m_a0 = fd;
            m_98 = a;
            double old = m_90;
            double diff = old - fd;
            m_b0 = 0;
            diff = diff * diff;
            diff = diff * m_90;
            double t2 = fd - m_90;
            t2 = t2 * m_a8;
            m_a8 = diff + t2;
        }
        int b = m_44;
        int c2 = b + 0x7fffffff;
        if ((unsigned)c2 <= 0xfffffffeu) {
            double fd = (double)b;
            if (m_88) {
                // keep fd
            } else {
                double t = fd - m_68;
                t = t * m_78;
                double u = m_68 * fd;
                fd = t + u;
            }
            m_78 = fd;
            m_70 = b;
            double old = m_68;
            double diff = old - fd;
            m_88 = 0;
            diff = diff * diff;
            diff = diff * m_68;
            double t2 = fd - m_68;
            t2 = t2 * m_80;
            m_80 = diff + t2;
        }
        int e = m_168;
        int c3 = e + 0x7fffffff;
        if ((unsigned)c3 <= 0xfffffffeu) {
            double fd = (double)e;
            if (m_d8) {
                // keep fd
            } else {
                double t = fd - m_b8;
                t = t * m_c8;
                double u = m_b8 * fd;
                fd = t + u;
            }
            m_c8 = fd;
            m_c0 = e;
            double old = m_b8;
            double diff = old - fd;
            m_d8 = 0;
            diff = diff * diff;
            diff = diff * m_b8;
            double t2 = fd - m_b8;
            t2 = t2 * m_d0;
            m_d0 = diff + t2;
        }
        int v2 = ((S_func_0052f670*)p)->f();
        unsigned long r2 = WaitForSingleObject(g_98b258, v2);
        if (r2 != 0x102)
            break;
    }
}
