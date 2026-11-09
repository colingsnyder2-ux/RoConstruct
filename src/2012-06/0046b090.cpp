// from server: 71% by atomic.potato
struct CRenderSettingsItem
{
    char padding[0x90];
    int value;
    void setValue(int);
};

extern "C" void __stdcall updateValue(int*, int);

void CRenderSettingsItem::setValue(int v)
{
    if (value != v)
    {
        value = v;
        updateValue((int*)this + 0x51, 0xe1982c);
    }
}
