// from server: 76% by atomic.potato
extern "C" void __fastcall sub_411F60(void*, void*);

struct CoreGuiService_00647310
{
    char pad0[161];
    unsigned char m_value;
    void setValue(unsigned char value);
};

void CoreGuiService_00647310::setValue(unsigned char value)
{
    if (m_value != value)
    {
        m_value = value;
        sub_411F60(this, (void*)0x00CCCDA4);
    }
}
