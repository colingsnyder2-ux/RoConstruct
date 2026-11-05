// from server: 100% by atomic.potato
extern "C" void __stdcall Function_411f60(int);

struct CRenderSettingsItem
{
    char padding[265];
    unsigned char value;
    void setValue(unsigned char);
};

void CRenderSettingsItem::setValue(unsigned char v)
{
    if (v != value)
    {
        value = v;
        Function_411f60(0x00CB3228);
    }
}
