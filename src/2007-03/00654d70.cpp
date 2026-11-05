// from server: 100% by tester
struct CXTTreeBase
{
    char pad_0000[0x460];
    int  m_kind;
    int  m_value;
    int  getValue();
};

int CXTTreeBase::getValue()
{
    if (m_kind == 4 || m_kind == 5)
        return m_value;
    return m_kind;
}
