// from server: 100% by tester
namespace ns_ROCX000012 {
struct CXTPTabPaintManager
{
    int m_nValue;
    char m_pad[260];
    int m_nField104;
    void SetValue(int);
};

void CXTPTabPaintManager::SetValue(int nValue)
{
    m_nField104 = nValue;
    (*(void (__thiscall **)(CXTPTabPaintManager *))(*(int *)this + 0x70))(this);
}
}