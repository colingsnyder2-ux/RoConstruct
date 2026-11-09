// from server: 76% by atomic.potato
struct CRenderSettingsItem
{
    int value;
    void setValue(int value);
};

void CRenderSettingsItem::setValue(int value)
{
    if (value != *(int*)((char*)this + 0xe0))
    {
        *(int*)((char*)this + 0xe0) = value;
        *(int*)0x00cb34b0 = 0;
    }
}
