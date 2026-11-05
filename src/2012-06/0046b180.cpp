// from server: 86% by Intel
struct CRenderSettingsItem
{
    void SetValue(int value);
};

extern "C" void __stdcall NotifyChange(int);

void CRenderSettingsItem::SetValue(int value)
{
    if (value != *(int*)((char*)this + 0xB4))
    {
        *(int*)((char*)this + 0xB4) = value;
        NotifyChange(0xE19D70);
    }
}
