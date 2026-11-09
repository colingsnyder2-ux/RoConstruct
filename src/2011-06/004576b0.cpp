// from server: 80% by atomic.potato
struct CRenderSettingsItem
{
    int value;
    void setValue(int value);
};

void CRenderSettingsItem::setValue(int value)
{
    if (value != *(int*)((char*)this + 0xc8))
    {
        *(int*)((char*)this + 0xc8) = value;
        value = 0x00cb3428;
        *(int*)((char*)this + 0x04) = value;
    }
}
