// from server: 47% by atomic.potato
struct Decal {
    char pad[0xd8];
    float m_value;
    void setValue(float v);
};

extern float g_limit;
extern "C" void __cdecl report(const char* fmt, ...);

void Decal::setValue(float v)
{
    if (m_value == v)
        return;
    if (v > g_limit)
    {
        m_value = v;
        report("%.4e", v);
    }
}
