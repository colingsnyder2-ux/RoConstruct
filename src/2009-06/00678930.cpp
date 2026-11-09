// from server: 28% by atomic.potato
struct Inner {
    char pad[0x18];
};

struct Mid {
    char pad0[0x18];
    Inner inner18;
    Inner inner1c;
};

struct Obj {
    char pad0[0x9c];
    char field9c[8];
    char fielda4[8];
};

extern "C" int __stdcall sub_41ab20(void*);
extern "C" int __stdcall sub_4bd160(int);
extern "C" int __stdcall sub_5f9b80(void*);
extern "C" int __stdcall sub_610c90(void*, void*);
extern "C" int __stdcall sub_6788e0(void*, void*);
extern "C" int __stdcall sub_67e6b0(int);

struct PhysicsService {
    void func(int a, int b);
};

void PhysicsService::func(int a, int b) {
    Obj* self = (Obj*)this;
    sub_5f9b80(self->field9c);
    sub_5f9b80(self->fielda4);
    if (a == 0) return;
    int r = sub_4bd160(a);
    if (r == 0) return;
    int e = sub_67e6b0(*(int*)(r + 0x150));
    if (e == 0) return;
    Mid* m = (Mid*)e;
    {
        struct { int f; int z; void* s; int a; } cb;
        cb.f = 0x678500;
        cb.z = 0;
        cb.s = self;
        cb.a = a;
        void* p = (void*)sub_6788e0(&m->inner18, &cb);
        sub_610c90(self->field9c, p);
        sub_41ab20(&cb);
    }
    {
        struct { int f; int z; void* s; int a; } cb;
        cb.f = 0x6785d0;
        cb.z = 0;
        cb.s = self;
        cb.a = a;
        void* p = (void*)sub_6788e0(&m->inner1c, &cb);
        sub_610c90(self->fielda4, p);
        sub_41ab20(&cb);
    }
}
