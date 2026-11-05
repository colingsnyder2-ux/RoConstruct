// from server: 57% by atomic.potato
struct VFlag {
    void ctor();
    int field0;
    int field4;
    char pad8[0x10];
    int field18;
    int field1c;
    int field20;
    char pad24[0x70];
    int field94;
    char pad98[0x7c];
    int field114;
    int field118;
    int field11c;
    int field120;
    char pad124[0xc];
    int field130;
    VFlag* ctor2();
};

extern "C" int __cdecl sub_6502c0();
extern "C" void __cdecl sub_744250();

int g_b8fda8;

VFlag* VFlag::ctor2()
{
    this->ctor();
    this->field20 = sub_6502c0();
    g_b8fda8++;
    *(int*)((char*)this + 0x00) = 0x9e339c;
    *(int*)((char*)this + 0x04) = 0x9e3394;
    *(int*)((char*)this + 0x18) = 0x9e3388;
    *(int*)((char*)this + 0x1c) = 0x9e3380;
    *(int*)((char*)this + 0x94) = 0x9e3378;
    *(int*)((char*)this + 0x114) = 0x9e3370;
    *(int*)((char*)this + 0x120) = 0x9e3358;
    *(int*)((char*)this + 0x130) = 0x9e3350;
    return this;
}
