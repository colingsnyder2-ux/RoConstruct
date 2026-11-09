// from server: 54% by atomic.potato
struct Inner {
    char pad0[4];
    int field4;
    char pad8[8];
    int field10;
    char pad14[4];
    int field18;
};

struct Arg {
    int a;
    int b;
};

struct VTable1 {
    void* f0;
    void* f4;
    void* f8;
    void* fC;
    void* f10;
    void* f14;
    void* f18;
    void* f1C;
    void* f20;
    void* f24;
};

struct Obj {
    VTable1* vt;
};

extern "C" void __stdcall sub_922cc0(Arg* out, int a, int b);

struct Builder {
    char pad0[4];
    Inner* p4;
    char pad8[8];
    Inner* p10;
    char pad14[4];
    Inner* p18;
    int method(Obj* obj, Arg* out);
};

int Builder::method(Obj* obj, Arg* out) {
    Arg local;
    sub_922cc0(&local, p4->field4, p10->field4);
    int ebp = ((int (__stdcall*)(Obj*))obj->vt->f24)(obj);
    int eax = p18->field4 & 0xf00;
    if (eax == 0) {
        ((void (__stdcall*)(int, Arg*))p10->field4)(0, &local);
    } else if (eax == 0x100 || eax == 0x200 || eax == 0x300) {
        ((void (__stdcall*)(int, int, Arg*))p10->field4)(p18->field4, 1, &local);
    }
    int ecx = ((int (__stdcall*)(Obj*))obj->vt->f24)(obj);
    out->a = ebp;
    out->b = ecx;
    return 0;
}
