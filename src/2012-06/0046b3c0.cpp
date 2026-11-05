// from server: 72% by atomic.potato
extern "C" void __fastcall UpdateSettings(void *, int);

struct CRenderSettingsItem
{
    unsigned char pad[228];
    unsigned char value;
    void update(unsigned char value);
};

void CRenderSettingsItem::update(unsigned char value)
{
    if (value != this->value)
    {
        this->value = value;
        UpdateSettings((char *)this + 324, 0xe1979c);
    }
}
