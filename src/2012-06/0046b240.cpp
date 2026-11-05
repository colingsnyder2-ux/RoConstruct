// from server: 67% by atomic.potato
struct CRenderSettingsItem
{
    char pad[196];
    int value;
    int SetValue(int);
};

extern "C" void UpdateSetting(int*, int);

int CRenderSettingsItem::SetValue(int v)
{
    if (value == v)
        return 0;

    value = v;
    UpdateSetting((int*)this + 81, 0xE19A1C);
    return 0;
}
