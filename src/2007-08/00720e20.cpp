// from server: 100% by colin
struct CXTCaptionButtonThemeOfficeXP {
    char pad0[0x18];
    int field18;
    char pad1[0x60];
    int field7c;
    int field80;
    int field84;
    void sub_720bc0(int);
    CXTCaptionButtonThemeOfficeXP* construct(int);
};

CXTCaptionButtonThemeOfficeXP* CXTCaptionButtonThemeOfficeXP::construct(int arg)
{
    sub_720bc0(0);
    field7c = arg;
    *(int*)this = 0x7e241c;
    field18 = 0;
    field80 = 0;
    field84 = 0;
    return this;
}
