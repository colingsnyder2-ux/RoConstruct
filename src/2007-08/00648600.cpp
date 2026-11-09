// from server: 100% by colin
// roc 2007-08 00648600  unit: CXTPCommandBar  size: 20 bytes

struct CXTPCommandBar
{
    int m_first;
    int m_second;

    int IsUnset() const;
};

int CXTPCommandBar::IsUnset() const
{
    return m_first == 0 && m_second == 0;
}
