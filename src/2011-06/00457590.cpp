// from server: 100% by atomic.potato
struct CRenderSettingsItem
{
    char padding[160];
    int value;
    void value_set(int);
};

extern "C" void __stdcall SetRenderSettingsValue(int);

void CRenderSettingsItem::value_set(int v)
{
    if (v != value)
    {
        value = v;
        SetRenderSettingsValue(0x00CB3288);
    }
}
