// from server: 100% by atomic.potato
struct CXTPTabPaintManager
{
    void SetValue(int value);
};

void CXTPTabPaintManager::SetValue(int value)
{
    *(int *)((char *)this + 0x108) = value;
    (*(void (__thiscall **)(CXTPTabPaintManager *))(*(int *)this + 0x70))(this);
}
