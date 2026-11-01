// from server: 100% by colin
struct CXTPTabPaintManager
{
    int m_pad[0x42];
    int m_nValue;

    void SetValue(int value);
};

void CXTPTabPaintManager::SetValue(int value)
{
    m_nValue = value;
    ((void (__thiscall *)(CXTPTabPaintManager *))((*(void ***)this)[0x1C]))(this);
}
