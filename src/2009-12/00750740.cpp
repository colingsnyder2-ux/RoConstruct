// from server: 50% by atomic.potato
struct S {
    char pad0[0x20];
    int field20;
    char pad24[0xac - 0x24];
    float fieldac;
    char padb0[0x100 - 0xb0];
    S* make(float arg);
};

extern "C" void __stdcall sub_774960();
extern "C" int __cdecl sub_650a30();

extern int dword_B900B8;

S* S::make(float arg)
{
    sub_774960();
    this->fieldac = arg;
    *(int*)((char*)this + 0x00) = 0x9cd274;
    *(int*)((char*)this + 0x04) = 0x9cd268;
    *(int*)((char*)this + 0x18) = 0x9cd25c;
    *(int*)((char*)this + 0x1c) = 0x9cd254;
    *(int*)((char*)this + 0x94) = 0x9cd24c;
    this->field20 = sub_650a30();
    dword_B900B8++;
    return this;
}
