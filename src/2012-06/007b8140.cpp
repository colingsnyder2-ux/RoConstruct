// from server: 27% by Intel
struct Sparkles {
    char pad[0x88];
    float m_val0;
    float m_val1;
    float m_val2;

    void sub_7b8140(float a1, float a2, float a3);
};

extern "C" void __stdcall sub_414da0(int);

void Sparkles::sub_7b8140(float a1, float a2, float a3)
{
    if (!(m_val0 > a1) && !(m_val1 > a2) && !(m_val2 > a3))
        return;

    m_val0 = a1;
    m_val1 = a2;
    m_val2 = a3;
    sub_414da0(0xE4B468);
}
