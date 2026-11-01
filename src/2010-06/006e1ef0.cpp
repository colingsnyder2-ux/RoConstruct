// from server: 100% by atomic.potato
struct P8CRenderSettings {
    char pad[0x1cc];
    unsigned char field_0x1cc;
    void SetImpl(unsigned char value);
};

extern "C" void __stdcall sub_40C470(unsigned int);

void P8CRenderSettings::SetImpl(unsigned char value)
{
    if (field_0x1cc != value)
    {
        field_0x1cc = value;
        sub_40C470(0xc21054);
    }
}
