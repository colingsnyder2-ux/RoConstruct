// from server: 100% by tester
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
