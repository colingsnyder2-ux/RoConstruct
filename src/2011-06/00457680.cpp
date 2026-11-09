// from server: 72% by atomic.potato
extern "C" void __stdcall SetRenderSettingValue(int, int);

struct CRenderSettingsItem
{
    int padding[49];
    int value;
    void SetValue(int);
};

void CRenderSettingsItem::SetValue(int value)
{
    if (value == this->value)
        return;
    this->value = value;
    SetRenderSettingValue(0x00CB3624, value);
}
