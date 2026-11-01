// from server: 100% by colin
struct CXTPTabManager_CNavigateButtonArrowLeft
{
    char m_pad[0x1c];
    int m_nValue;
    void SetValue(int nValue);
};

void CXTPTabManager_CNavigateButtonArrowLeft::SetValue(int nValue)
{
    if (m_nValue != nValue)
    {
        m_nValue = nValue;
        (*(void (__thiscall **)(void *))(*(int *)this + 8))(this);
    }
}
