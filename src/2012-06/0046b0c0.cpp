// from server: 71% by atomic.potato
struct CRenderSettingsItem
{
    int value;
    void setValue(int);
};

void CRenderSettingsItem::setValue(int value)
{
    if (value == *(int*)((char*)this + 0xa4))
        return;

    *(int*)((char*)this + 0xa4) = value;
    *(int*)0xe19860 = value;
    *(int*)((char*)this + 0x144) = 0;
}
