// from server: 25% by atomic.potato
struct TweenService_008f5f70 {
    char pad0[0x28];
    int field28;
    int ctor();
};

extern "C" void __stdcall sub_006861b0();
extern "C" int __stdcall sub_00781f30();
extern int g_e48c1c;

int TweenService_008f5f70::ctor()
{
    sub_006861b0();
    *(int*)((char*)this + 0x00) = 0xbeffb4;
    *(int*)((char*)this + 0x04) = 0xbeffac;
    *(int*)((char*)this + 0x18) = 0xbeffa0;
    *(int*)((char*)this + 0x1c) = 0xbeff94;
    field28 = sub_00781f30();
    g_e48c1c++;
    return (int)this;
}
