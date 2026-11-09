// from server: 100% by atomic.potato
struct ViewRbxGfx
{
    unsigned char pad18[24];
    unsigned char m_flag18;
    unsigned char pad19[35];
    unsigned char m_flag3c;
    void f(unsigned char value);
};

void ViewRbxGfx::f(unsigned char value)
{
    m_flag18 = 0;
    if (value != 0)
        m_flag3c = 0;
}
