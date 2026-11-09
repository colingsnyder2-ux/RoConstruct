// from server: 100% by tester
struct CXTPCommandBar
{
    char pad[0xf0];
    unsigned int m_flags;
    unsigned int get_flag() const;
};

unsigned int CXTPCommandBar::get_flag() const
{
    return (m_flags >> 22) & 1;
}
