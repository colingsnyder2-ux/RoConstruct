// from server: 100% by atomic.potato
extern "C" void __stdcall Function_411f60(int);

struct CRenderSettingsItem
{
    char padding[184];
    int value;
    void setValue(int);
};

void CRenderSettingsItem::setValue(int v)
{
    if (v != value)
    {
        value = v;
        Function_411f60(0x00CB35D4);
    }
}
