// from server: 42% by atomic.potato
extern "C" void SetRenderSetting(void*, int);

struct CRenderSettingsItem
{
    int value;
    void SetValue(int);
};

void CRenderSettingsItem::SetValue(int value)
{
    if (value != this->value)
    {
        this->value = value;
        SetRenderSetting(this, 0x00CB33E0);
    }
}
