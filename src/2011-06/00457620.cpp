// from server: 65% by atomic.potato
struct CRenderSettingsItem
{
    char padding[188];
    int value;
    void SetValue(int);
};

void CRenderSettingsItem::SetValue(int value)
{
    if (this->value != value)
    {
        this->value = value;
        SetValue(0xcb3390);
    }
}
