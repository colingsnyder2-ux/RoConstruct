// from server: 86% by atomic.potato
struct CRenderSettingsItem
{
    char padding[0x98];
    int value;
    void update(int);
    void set(int);
};

void CRenderSettingsItem::set(int v)
{
    if (v != value)
    {
        value = v;
        update(0xe19980);
    }
}
