// from server: 100% by colin
struct CXTCaptionButtonThemeFactory
{
    char pad[0x18];
    int field_18;
    char pad2[0x64];
    int field_80;
    int field_84;
    CXTCaptionButtonThemeFactory();
};

extern "C" void __stdcall sub_720bc0(int);

CXTCaptionButtonThemeFactory::CXTCaptionButtonThemeFactory()
{
    sub_720bc0(0);
    *(int*)this = 0x7deb6c;
    field_84 = 0;
    field_80 = 0;
    field_18 = 0;
}
