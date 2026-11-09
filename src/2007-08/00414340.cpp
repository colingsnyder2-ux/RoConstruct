// from server: 35% by colin
struct S {
    char pad[0xe8];
    int field_e8;
    void ctor();
};

extern "C" void __cdecl sub_725720(int);
extern "C" void __cdecl sub_5402B0();

void S::ctor()
{
    *(int*)((char*)this + 0x00) = 0x787284;
    *(int*)((char*)this + 0x04) = 0x787278;
    *(int*)((char*)this + 0x10) = 0x787270;
    *(int*)((char*)this + 0x14) = 0x787260;
    *(int*)((char*)this + 0x2c) = 0x787250;
    *(int*)((char*)this + 0x44) = 0x787240;
    *(int*)((char*)this + 0x5c) = 0x787230;
    *(int*)((char*)this + 0x74) = 0x787220;
    *(int*)((char*)this + 0x8c) = 0x787210;
    sub_725720((int)((char*)this + 0xe8));
    sub_5402B0();
}
