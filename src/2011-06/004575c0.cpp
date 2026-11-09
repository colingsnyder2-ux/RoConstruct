// from server: 75% by atomic.potato
struct CRenderSettingsItem
{
    char padding[180];
    int value;
    void setValue(int);
};

extern "C" void __cdecl SetRenderSettingsItem(int);

void CRenderSettingsItem::setValue(int value)
{
    if (value != this->value)
    {
        this->value = value;
        SetRenderSettingsItem(0x00CB32B0);
    }
}
