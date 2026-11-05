// from server: 38% by colin
struct ArgList {
    char pad[0x48];
};

struct BoundFuncDesc {
    char pad0[0x24];
    float x;
    float y;
    float z;
};

struct Vec3 {
    float x, y, z;
};

struct Arg {
    char pad[0x1c];
};

extern "C" void __stdcall sub_5095d0(void*, void*);
extern "C" void __stdcall sub_4a0830(void*, void*);
extern "C" char __stdcall sub_4a0290(void*, void*, void*, void*);
extern "C" void __stdcall sub_49fcf0(void*);
extern "C" void __stdcall sub_49fcd0(void*);
extern "C" void __stdcall sub_49fd90(void*, void*, int, int);
extern "C" char __stdcall sub_5aadb0(void*);
extern "C" int __stdcall sub_5aae20(void*);
extern "C" void __stdcall sub_5aa880(void*, void*);

void BoundFuncDesc_impl(BoundFuncDesc* self, void* arg);

void BoundFuncDesc_impl(BoundFuncDesc* self, void* arg)
{
    char buf[0x48];
    Vec3 v;
    Arg a;
    void* p;
    char c;

    sub_5095d0(buf + 0x1c, arg);
    v.x = self->x;
    v.y = self->y;
    v.z = self->z;
    sub_4a0830(&a, &v);
    c = sub_4a0290(&p, buf + 0x0c, buf + 0x08, buf + 0x40);
    if (c) {
        sub_49fcf0(p);
        sub_49fd90(p, buf + 0x40, 0xb, 1);
        sub_49fd90(p, buf + 0x08, 0xb, 1);
        sub_49fd90(p, buf + 0x0c, 0xb, 1);
    } else {
        sub_49fcd0(p);
        sub_49fd90(p, &v.x, 0x20, 1);
        sub_49fd90(p, &v.y, 0x20, 1);
        sub_49fd90(p, &v.z, 0x20, 1);
    }
    if (sub_5aadb0(&a)) {
        sub_49fcf0(p);
        int n = sub_5aae20(&a);
        sub_49fd90(p, &n, 6, 1);
    } else {
        sub_49fcd0(p);
        Vec3 w;
        sub_5aa880(&w, &a);
        sub_49fd90(p, &w.x, 0x20, 1);
        sub_49fd90(p, &w.y, 0x20, 1);
        sub_49fd90(p, &w.z, 0x20, 1);
    }
}
