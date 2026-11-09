// from server: 100% by colin
struct RBX_ViewRbxGfx {
    char pad[0x20];
    unsigned char m_flag;
    unsigned char getAndClear();
};

unsigned char RBX_ViewRbxGfx::getAndClear()
{
    unsigned char v = m_flag;
    m_flag = 0;
    return v;
}
