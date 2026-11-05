// from server: 30% by atomic.potato
// roc 2009-12 00742eb0  unit: RBX::VVelocityMotor::?$FactoryProduct  size: 374 bytes

extern "C" void __stdcall sub_662AB0(int, int);
extern "C" void __stdcall sub_528FF0(int, int, int);
extern "C" void* __stdcall sub_7F3860(int);
extern "C" void __stdcall sub_71DB70(int, int, int);

struct S {
    char pad0[0x34];
    char field34[0x20];
    char field54[0x20];
    char field74[0x18];
    char field8c[0x18];
    char fielda4[0x18];
    char fieldbc[0x18];
    char fieldd4[0x18];

    void init();
};

void S::init()
{
    sub_662AB0(0x9E2DD8, 0xB2C7BC);
    *(int*)this = 0x9CCCDC;
    sub_528FF0((int)this + 0x34, (int)this + 0x38, (int)this + 0x3C);
    sub_528FF0((int)this + 0x54, (int)this + 0x58, (int)this + 0x5C);
    void* p;
    p = sub_7F3860(4);
    if (p) *(void**)p = (char*)this + 0x74;
    else p = 0;
    *(void**)((char*)this + 0x74) = p;
    *(int*)((char*)this + 0x80) = 0;
    *(int*)((char*)this + 0x84) = 0;
    *(int*)((char*)this + 0x88) = 0;
    p = sub_7F3860(4);
    if (p) *(void**)p = (char*)this + 0x8c;
    else p = 0;
    *(void**)((char*)this + 0x8c) = p;
    *(int*)((char*)this + 0x98) = 0;
    *(int*)((char*)this + 0x9c) = 0;
    *(int*)((char*)this + 0xa0) = 0;
    p = sub_7F3860(4);
    if (p) *(void**)p = (char*)this + 0xa4;
    else p = 0;
    *(void**)((char*)this + 0xa4) = p;
    *(int*)((char*)this + 0xb0) = 0;
    *(int*)((char*)this + 0xb4) = 0;
    *(int*)((char*)this + 0xb8) = 0;
    p = sub_7F3860(4);
    if (p) *(void**)p = (char*)this + 0xbc;
    else p = 0;
    *(void**)((char*)this + 0xbc) = p;
    *(int*)((char*)this + 0xc8) = 0;
    *(int*)((char*)this + 0xcc) = 0;
    *(int*)((char*)this + 0xd0) = 0;
    p = sub_7F3860(4);
    if (p) *(void**)p = (char*)this + 0xd4;
    else p = 0;
    *(void**)((char*)this + 0xd4) = p;
    *(int*)((char*)this + 0xe0) = 0;
    *(int*)((char*)this + 0xe4) = 0;
    *(int*)((char*)this + 0xe8) = 0;
    sub_71DB70((int)this, 0, 0x9A8D5C);
    sub_71DB70((int)this, 1, 0x9E2DC4);
    sub_71DB70((int)this, 2, 0x9A8D64);
}
