// from server: 31% by atomic.potato
struct TextLabel {
    char pad0[0x218];
    float m_x218;
    float m_x21c;
    float m_x220;
    void notify(const void* p);
    void f(float a, float b, float c);
};

void TextLabel::f(float a, float b, float c)
{
    if (m_x218 != a || m_x21c != b || m_x220 != c)
    {
        m_x218 = a;
        m_x21c = b;
        m_x220 = c;
        notify((const void*)0xe4fca4);
        notify((const void*)0xe4fd00);
    }
}
