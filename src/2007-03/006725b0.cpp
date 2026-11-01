// from server: 100% by tester
struct CXTPControls
{
    char m_pad[0xf4];
    int m_nFieldF4;
    char m_pad2[4];
    int m_nFieldFC;
    void SetValue(int);
};

void CXTPControls::SetValue(int nValue)
{
    CXTPControls *pThis = this;
    CXTPControls *pArg = (CXTPControls *)nValue;
    pArg->m_nFieldF4 = 0;
    pArg->m_nFieldFC = 0;
    (*(void (__thiscall **)(CXTPControls *))(*(int *)pArg + 0x124))(pArg);
    (*(void (__thiscall **)(CXTPControls *))(*(int *)pThis + 0x6c))(pThis);
}