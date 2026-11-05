// from server: 76% by atomic.potato
struct CRenderSettingsItem
{
    char padding[208];
    int value;
    void setValue(int);
};

void CRenderSettingsItem::setValue(int value)
{
    if (value != this->value)
    {
        this->value = value;
        value = 0x00CB33B8;
        *(int*)0x00CB33B8 = value;
    }
}
