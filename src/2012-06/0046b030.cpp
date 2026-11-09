// from server: 65% by atomic.potato
extern "C" void __stdcall UpdateRenderSetting(void*);

struct CRenderSettingsItem
{
    char padding[0x4c];
    int value;
    void SetValue(int);
};

void CRenderSettingsItem::SetValue(int v)
{
    if (v != value)
    {
        value = v;
        UpdateRenderSetting((char*)this + 0xc0);
    }
}
