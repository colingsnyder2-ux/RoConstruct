// from server: 64% by atomic.potato
struct CXTPTabPaintManager
{
    int value;
    void SetValue(int);
};

void CXTPTabPaintManager::SetValue(int value)
{
    this->value = value;
    void (__thiscall *func)(CXTPTabPaintManager *) =
        *(void (__thiscall **)(CXTPTabPaintManager *))(*(int *)this + 0x70);
    func(this);
}
