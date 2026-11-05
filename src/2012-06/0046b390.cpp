// from server: 75% by atomic.potato
struct CRenderSettingsItem
{
    void Update(unsigned char value);
    unsigned char padding[225];
    unsigned char field;
};

void CRenderSettingsItem::Update(unsigned char value)
{
    if (value != field)
    {
        field = value;
        *(unsigned long*)0xE19A50 = 0xE19A50;
        *(unsigned long*)((char*)this + 0x144) = 0xE19A50;
    }
}
