// from server: 100% by tester
struct CXTPTabPaintManager {
    char pad0[0xfc];
    int m_value;
    void SetValue(int value);
};

void CXTPTabPaintManager::SetValue(int value)
{
    m_value = value;
    (*(void (__thiscall **)(void *))(*(int *)this + 0x6c))(this);
}