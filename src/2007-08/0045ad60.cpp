// from server: 25% by colin
struct VStopwatchStatsItem {
    char pad0[0x110];
    int field110;
    int field114;
    int field118;
    int ctor(int arg);
};

extern "C" void __stdcall sub_45AAC0();
extern "C" void __stdcall sub_459C80(int, int);

int VStopwatchStatsItem::ctor(int arg)
{
    sub_45AAC0();
    *(int*)((char*)this + 0x00) = 0x793a3c;
    *(int*)((char*)this + 0x04) = 0x793a30;
    *(int*)((char*)this + 0x10) = 0x793a28;
    *(int*)((char*)this + 0x14) = 0x793a18;
    *(int*)((char*)this + 0x2c) = 0x793a08;
    *(int*)((char*)this + 0x44) = 0x7939f8;
    *(int*)((char*)this + 0x5c) = 0x7939e8;
    *(int*)((char*)this + 0x74) = 0x7939d8;
    *(int*)((char*)this + 0x8c) = 0x7939c8;
    field110 = 0;
    field114 = 0;
    field118 = 0;
    sub_459C80(0x5b9940, arg);
    return (int)this;
}
