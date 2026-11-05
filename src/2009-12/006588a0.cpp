// from server: 36% by atomic.potato
// roc 2009-12 006588a0  unit: RBX::VSeat::?$FactoryProduct  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006588a0

extern "C" char __stdcall sub_658370(int, int, int, int, int, int, int);

struct VSeat {
    int field0;
    int field4;
    char pad8[0x18];
    int method(int, int, int, int, int, int);
};

int VSeat::method(int a, int b, int c, int d, int e, int f)
{
    char buf[0x18];
    *(int*)(buf + 0) = a;
    *(int*)(buf + 4) = b;
    *(int*)(buf + 8) = c;
    *(int*)(buf + 0xc) = d;
    *(int*)(buf + 0x10) = e;
    *(int*)(buf + 0x14) = f;
    char r = sub_658370(0xb2f3b8, (int)(this + 1), (int)buf, 0, 0, 0, 0);
    int v = -(int)(unsigned char)r;
    this->field0 = v & 0xb2f3b8;
    return this->field0;
}
