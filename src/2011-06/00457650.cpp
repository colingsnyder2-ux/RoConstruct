// from server: 75% by atomic.potato
struct CRenderSettingsItem
{
    char padding[192];
    int value;
    void SetValue(int value);
};

extern "C" void __cdecl Function411F60(int);

void CRenderSettingsItem::SetValue(int value)
{
    if (value != this->value)
    {
        this->value = value;
        Function411F60(0x00CB31D8);
    }
}
