// from server: 72% by atomic.potato
struct CRenderSettingsItem
{
    unsigned char value;
    int Update();
    int SetValue(unsigned char);
};

extern "C" int __stdcall UpdateSettings(void *, int);

int CRenderSettingsItem::SetValue(unsigned char value)
{
    if (value == *(unsigned char *)((char *)this + 0x101))
        return 0;

    *(unsigned char *)((char *)this + 0x101) = value;
    return UpdateSettings((char *)this + 0x144, 0x00E1976C);
}
