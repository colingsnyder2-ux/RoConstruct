// from server: 65% by atomic.potato
struct CRenderSettingsItem
{
    char padding[0xbc];
    int value;
    void update(int value);
    void SetValue(int value);
};

void CRenderSettingsItem::update(int value)
{
}

void CRenderSettingsItem::SetValue(int value)
{
    if (value != this->value)
    {
        this->value = value;
        update(0xe19920);
    }
}
