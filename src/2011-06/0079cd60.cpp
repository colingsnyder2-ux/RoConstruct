// from server: 61% by atomic.potato
struct Inner {
    char pad0[0x1e4];
    float f1e4;
    char pad1[0x1ed - 0x1e4 - 4];
    char b1ed;
    char b1ee;
};

struct Obj {
    virtual int vf0();
    virtual int vf1();
    virtual int vf2();
    virtual int vf3();
    virtual int vf4();
    virtual int vf5();
    virtual int vf6();
    virtual int vf7();
    virtual int vf8();
    virtual int vf9();
    virtual int vf10();
    virtual int vf11();
    Inner* inner;
};

extern "C" int __cdecl sub_67eab0();
extern "C" char __cdecl sub_79bb40(Obj* self);
extern "C" void __cdecl sub_79cb80(Obj* self, int a);
extern "C" void __cdecl sub_79bde0(Obj* self);

void __cdecl sub_79cd60(Obj* self, int a)
{
    int result;
    if (self->inner->f1e4 > 0.0f) {
        result = 0xd;
    } else if (sub_67eab0()) {
        result = 0xd;
    } else if (self->inner->b1ed != 0) {
        result = 0xb;
    } else if (self->inner->b1ee != 0) {
        result = 0xc;
    } else if (self->vf11() == 8 && sub_79bb40(self)) {
        result = 7;
    } else {
        result = a;
    }
    if (result != self->vf11()) {
        if (self->vf11() != 7 || result != 8) {
            sub_79cb80(self, result);
            sub_79bde0(self);
        }
    }
}
