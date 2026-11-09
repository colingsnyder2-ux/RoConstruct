// from server: 76% by atomic.potato
struct CRenderSettingsItem
{
    int value;
    void setValue(int);
};

void CRenderSettingsItem::setValue(int value)
{
    if (value == *(int *)((char *)this + 0xa8))
        return;

    *(int *)((char *)this + 0xa8) = value;
    *(int *)((char *)this + 0x144) = 0xe19d08;
}
