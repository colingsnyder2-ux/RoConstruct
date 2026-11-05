// from server: 60% by king_originala
struct S {
    char pad[0x13C];
    S(int);
};

S::S(int)
{
    *(int*)((char*)this + 0x0C) = 0x846DC4;
    *(int*)((char*)this + 0x10) = 0x846DBC;
    *(int*)((char*)this + 0x14) = 0x846DB4;
    *(int*)((char*)this + 0x20) = 0x846DAC;
    *(int*)((char*)this + 0x24) = 0x846D9C;
    *(int*)((char*)this + 0x44) = 0x846D8C;
    *(int*)((char*)this + 0x64) = 0x846D7C;
    *(int*)((char*)this + 0x84) = 0x846D6C;
    *(int*)((char*)this + 0xA4) = 0x846D5C;
    *(int*)((char*)this + 0xC4) = 0x846D4C;
    *(int*)((char*)this + 0x130) = 0x846D30;
    *(int*)((char*)this + 0x138) = 0x846D24;
}
