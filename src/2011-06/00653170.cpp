// from server: 26% by atomic.potato
extern "C" float _fltused;

extern "C" void __stdcall sub_411F60(const char*, ...);

struct RBX_Decal {
    char pad[0xc8];
    float m_value;
    void set(float v);
};

void RBX_Decal::set(float v)
{
    if (m_value == v)
        return;
    if (v < *(float*)0x00a690b4)
        return;
    m_value = v;
    sub_411F60("%.4e", v);
}
