// from server: 65% by atomic.potato
struct CRenderSettingsItem
{
    void setValue(unsigned char value);
};

void __thiscall CRenderSettingsItem::setValue(unsigned char value)
{
    if (value != *((unsigned char *)this + 0x100))
    {
        *((unsigned char *)this + 0x100) = value;
    }
}
