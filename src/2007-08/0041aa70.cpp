// from server: 27% by colin
struct VDHTMLWindow_BoundFuncDesc {
    void construct();
};

extern "C" void __stdcall sub_4199C0();
extern "C" void __stdcall sub_541BF0();
extern "C" void __stdcall sub_77E698();
extern "C" void __stdcall sub_77E6AC();
extern "C" void __stdcall sub_787940();
extern "C" void __stdcall sub_7878FC();
extern "C" void __stdcall sub_7878F4();
extern "C" void __stdcall sub_7878EC();
extern "C" void __stdcall sub_7878DC();
extern "C" void __stdcall sub_7878CC();
extern "C" void __stdcall sub_7878BC();
extern "C" void __stdcall sub_7878AC();
extern "C" void __stdcall sub_78789C();
extern "C" void __stdcall sub_78788C();

void VDHTMLWindow_BoundFuncDesc::construct()
{
    sub_4199C0();
    sub_787940();
    *(int*)((char*)this + 0x00) = 0x7878FC;
    *(int*)((char*)this + 0x04) = 0x7878F4;
    *(int*)((char*)this + 0x10) = 0x7878EC;
    *(int*)((char*)this + 0x14) = 0x7878DC;
    *(int*)((char*)this + 0x2C) = 0x7878CC;
    *(int*)((char*)this + 0x44) = 0x7878BC;
    *(int*)((char*)this + 0x5C) = 0x7878AC;
    *(int*)((char*)this + 0x74) = 0x78789C;
    *(int*)((char*)this + 0x8C) = 0x78788C;
    sub_77E698();
    sub_541BF0();
    sub_77E6AC();
}
