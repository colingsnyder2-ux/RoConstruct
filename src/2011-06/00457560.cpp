// from server: 100% by atomic.potato
struct CRenderSettingsItem
{
    int value;
    void SetValue(int);
};

extern "C" void __stdcall Target(int);

void CRenderSettingsItem::SetValue(int value)
{
    if (value != *(int*)((char*)this + 0xa8))
    {
        *(int*)((char*)this + 0xa8) = value;
        Target(0xcb3368);
    }
}
