// from server: 74% by atomic.potato
extern "C" void __stdcall UpdateRenderSettings(void*, unsigned int);

struct CRenderSettingsItem
{
    unsigned char value;
    void Update(unsigned char value);
};

void CRenderSettingsItem::Update(unsigned char value)
{
    if (value == *(unsigned char*)((char*)this + 0xff))
        return;

    *(unsigned char*)((char*)this + 0xff) = value;
    UpdateRenderSettings((char*)this + 0x144, 0xe19adc);
}
