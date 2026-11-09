// from server: 63% by atomic.potato
struct CRenderSettingsItem
{
    char padding[72];
    int value;

    void Set(int value);
};

extern "C" void UpdateRenderSettings(CRenderSettingsItem *, int);

void CRenderSettingsItem::Set(int value)
{
    if (value != this->value)
    {
        this->value = value;
        UpdateRenderSettings((CRenderSettingsItem *)((char *)this - 0x94), 0xCB35AC);
    }
}
