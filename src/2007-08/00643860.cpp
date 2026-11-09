// from server: 100% by colin
struct CXTPCommandBar
{
    char pad[0xec];
    unsigned int m_flags;
    unsigned int get_flag() const;
};

unsigned int CXTPCommandBar::get_flag() const
{
    return (m_flags >> 22) & 1;
}
