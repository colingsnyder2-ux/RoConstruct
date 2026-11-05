// from server: 74% by atomic.potato
extern "C" void __stdcall SetValue(void *, unsigned int);

struct CRenderSettingsItem
{
    unsigned char padding[0xC0];
    unsigned int value;
    void Set(unsigned int);
};

void CRenderSettingsItem::Set(unsigned int value)
{
    if (value != this->value)
    {
        this->value = value;
        SetValue((char *)this + 0x144, 0xE199E8);
    }
}
