// from server: 69% by atomic.potato
extern "C" void ApplySetting(void *, unsigned long);

struct CRenderSettingsItem
{
    unsigned char value;
    unsigned char padding[223];
    unsigned char field_e0;
    unsigned char padding2[99];

    void update(unsigned char value);
};

void CRenderSettingsItem::update(unsigned char value)
{
    if (field_e0 != value)
    {
        field_e0 = value;
        ApplySetting((char *)this + 0x144, 0xE19C7C);
    }
}
