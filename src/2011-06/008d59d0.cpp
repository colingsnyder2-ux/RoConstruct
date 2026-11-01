// from server: 100% by tester
struct CXTPTabPaintManager
{
    int m_nValue;
    char m_pad[256];
    int m_nField104;
    void SetValue(int);
};

void CXTPTabPaintManager::SetValue(int nValue)
{
    m_nField104 = nValue;
    (*(void (__thiscall **)(CXTPTabPaintManager *))(*(int *)this + 0x70))(this);
}