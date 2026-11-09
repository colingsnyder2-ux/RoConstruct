// from server: 100% by colin
struct CXTPControlCustom
{
    char pad[0x170];
    int m_n0x170;
    int m_n0x174;
    int m_n0x178;
    int m_n0x17c;
    int m_n0x180;
    char pad2[4];
    int m_n0x188;
    int m_n0x18c;
    int m_n0x190;
    int m_n0x194;
    void CopyFrom(CXTPControlCustom* other);
};

extern void __stdcall sub_0063cb00(CXTPControlCustom* other);

void CXTPControlCustom::CopyFrom(CXTPControlCustom* other)
{
    m_n0x174 = other->m_n0x174;
    m_n0x178 = other->m_n0x178;
    m_n0x17c = other->m_n0x17c;
    m_n0x180 = other->m_n0x180;
    m_n0x190 = other->m_n0x190;
    m_n0x188 = other->m_n0x188;
    m_n0x18c = other->m_n0x18c;
    m_n0x170 = other->m_n0x170;
    m_n0x194 = other->m_n0x194;
    sub_0063cb00(other);
}
