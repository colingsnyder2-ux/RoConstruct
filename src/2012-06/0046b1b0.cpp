// from server: 74% by atomic.potato
extern "C" void __stdcall sub_414500(void *, int);

struct CRenderSettingsItem
{
    char padding[0xb8];
    int value;
    void setValue(int);
};

void CRenderSettingsItem::setValue(int value)
{
    if (value == this->value)
        return;

    this->value = value;
    sub_414500((char *)this + 0x144, 0x00e19aa8);
}
