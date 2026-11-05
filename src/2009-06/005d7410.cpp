// from server: 38% by atomic.potato
struct S_005d7410 {
    char pad_000[0xa0];
    double m_a0;
    double m_a8;
    char pad_b0[0x08];
    double m_b8;
    char pad_c0[0x04];
    int m_c4;
    char pad_c8[0x08];
    int m_d0;

    void f_005d7410(double x, double y);
};

extern "C" void __stdcall sub_005d6290(int, void*);
extern "C" void __stdcall sub_004ba470(void*, int, int, int, int);

void S_005d7410::f_005d7410(double x, double y)
{
    m_b8 += x;
    double d1 = m_a0 - m_a8;
    double d2 = m_a0;
    double d3 = x;
    double d4 = y;
    if (m_c4 != 0) {
        int buf[10];
        buf[0] = 0x5d5fe0;
        buf[1] = *(int*)&d1;
        buf[2] = *(int*)&d2;
        buf[3] = *(int*)&d3;
        buf[4] = *(int*)&d4;
        sub_005d6290(m_c4, buf);
        d1 = *(double*)&buf[1];
    }
    if (m_d0 != 0) {
        int args[4];
        args[0] = 0x4ba1e0;
        args[1] = *(int*)&d1;
        args[2] = *(int*)&d2;
        args[3] = *(int*)&d3;
        sub_004ba470((void*)m_d0, args[0], args[1], args[2], args[3]);
    }
    m_a8 = m_a0;
}
