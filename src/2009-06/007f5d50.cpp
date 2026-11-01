// from server: 100% by why2
struct CXTPTabPaintManager {
    char pad0[0x108];
    int m_value;
    void SetValue(int value);
};

void CXTPTabPaintManager::SetValue(int value)
{
    m_value = value;
    void (__thiscall *fn)(CXTPTabPaintManager*) = *(void (__thiscall **)(CXTPTabPaintManager*))(*(int*)this + 0x70);
    fn(this);
}
