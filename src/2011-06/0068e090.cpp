// from server: 23% by atomic.potato
struct Vec2 { float x; float y; };

struct Obj {
    char pad0[0x324];
    char pad324[0x1c];
    char flag354;
    char pad355[0xb];
    int field360;
    char pad364[0x40];

    Obj* method(int arg);
};

extern "C" int __stdcall sub_4c6b40(int, Obj*);
extern "C" Obj* __stdcall sub_68e050(Obj*);
extern "C" void __stdcall sub_7327a0(int, void*);
extern "C" void __stdcall sub_721f30(void*, void*);
extern "C" Vec2* __stdcall sub_53b3a0();
extern "C" float __stdcall sub_68ce70(int, int, void*, int, int);
extern "C" void __stdcall sub_7736f0(void*);

struct VTable {
    char pad0[0xc];
    void (__stdcall *fn)(void*, void*);
};

struct Holder {
    VTable* vt;
};

Obj* Obj::method(int arg) {
    if (!sub_4c6b40(0, this)) {
        Vec2* v = sub_53b3a0();
        Vec2* out = (Vec2*)arg;
        out->x = v->x;
        out->y = v->y;
        return this;
    }
    Obj* p = sub_68e050(this);
    if (!p) {
        Vec2* v = sub_53b3a0();
        Vec2* out = (Vec2*)arg;
        out->x = v->x;
        out->y = v->y;
        return this;
    }
    Holder h;
    sub_7327a0((int)p, &h);
    if (h.vt == 0) {
        sub_7736f0(&h);
        Vec2* v = sub_53b3a0();
        Vec2* out = (Vec2*)arg;
        out->x = v->x;
        out->y = v->y;
        return this;
    }
    Vec2 tmp;
    Vec2* src;
    if (this->flag354) {
        Vec2 a;
        sub_721f30(this, &a);
        tmp.x = a.x - a.y;
        tmp.y = a.x - a.y;
        src = &tmp;
    } else {
        src = sub_53b3a0();
    }
    float f = sub_68ce70(this->field360, 0, src, 0, 0);
    void* self = (void*)h.vt;
    VTable* vt = h.vt;
    vt->fn(self, (void*)((char*)this + 0x324));
    sub_7736f0(&h);
    return this;
}
