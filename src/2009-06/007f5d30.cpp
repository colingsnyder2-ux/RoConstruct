// from server: 100% by why2
struct CXTPTabPaintManager {
    char pad0[0x104];
    int m_value;
    void SetValue(int value);
};

void CXTPTabPaintManager::SetValue(int value)
{
    m_value = value;
    (*(void (__thiscall **)(void *))(*(int *)this + 0x70))(this);
}
