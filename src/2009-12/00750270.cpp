// from server: 40% by atomic.potato
// roc 2009-12 00750270  unit: RBX::VLocalBackpack::?$FactoryProduct  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00750270

extern "C" char __stdcall sub_515860(int, int, int, int);

struct S {
    char pad0[0x18];
    int field18;
    char pad1[0x1c];
    int field38;
    int field3c;
    int field40;
    int field44;
    S* init(int, int, int, int, int);
};

S* S::init(int a, int b, int c, int d, int e) {
    *(int*)this = 0x9a2d44;
    *(int*)((char*)this + 0xc) = b;
    char r = sub_515860(a, b, c, d);
    int v = -(int)(unsigned char)r;
    field18 = v & 0xb593cc;
    field38 = 0;
    field3c = 0;
    field40 = 0;
    field44 = 0;
    return this;
}
