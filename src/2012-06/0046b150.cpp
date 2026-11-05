// from server: 74% by atomic.potato
extern "C" void __stdcall UpdateRenderSetting(void *, int);

struct CRenderSettingsItem
{
    char padding[0xB0];
    int value;
    void __thiscall SetValue(int);
};

void __thiscall CRenderSettingsItem::SetValue(int value)
{
    if (value != this->value)
    {
        this->value = value;
        UpdateRenderSetting((char *)this + 0x144, 0xE19700);
    }
}
