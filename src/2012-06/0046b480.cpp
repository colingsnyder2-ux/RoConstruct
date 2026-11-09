// from server: 74% by atomic.potato
extern "C" void __stdcall sub_414500(void *, unsigned int);

struct CRenderSettingsItem
{
    void f(unsigned char);
};

void CRenderSettingsItem::f(unsigned char value)
{
    if (value != *(unsigned char *)((char *)this + 0x102))
    {
        *(unsigned char *)((char *)this + 0x102) = value;
        sub_414500((char *)this + 0x144, 0xE19B60);
    }
}
