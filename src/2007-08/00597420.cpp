// from server: 100% by colin
struct S_00597420 {
    char pad0[4];
    int m_field4;
    char pad8[8];
    int m_field10;
    int m_field14;
    char pad18[0x18];
    int m_field2c;
    char pad30[0x18];
    int m_field44;
    char pad48[0x18];
    int m_field5c;
    char pad60[0x18];
    int m_field74;
    char pad78[0x14];
    int m_field8c;
    S_00597420* ctor(int);
};

extern "C" void __stdcall sub_0058bad0(int);

S_00597420* S_00597420::ctor(int arg)
{
    sub_0058bad0(arg);
    *(int*)((char*)this + 0) = 0x7b10ac;
    *(int*)((char*)this + 4) = 0x7b10a0;
    *(int*)((char*)this + 0x10) = 0x7b1098;
    *(int*)((char*)this + 0x14) = 0x7b1088;
    *(int*)((char*)this + 0x2c) = 0x7b1078;
    *(int*)((char*)this + 0x44) = 0x7b1068;
    *(int*)((char*)this + 0x5c) = 0x7b1058;
    *(int*)((char*)this + 0x74) = 0x7b1048;
    *(int*)((char*)this + 0x8c) = 0x7b1038;
    return this;
}
