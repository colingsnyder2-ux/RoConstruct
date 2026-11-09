// from server: 63% by colin
struct V3 {
    char pad0[0x24];
    float x;
    float y;
    float z;
};

struct Str {
    char buf[0x1c];
};

extern "C" {
    void __stdcall sub_5095d0();
    void __stdcall sub_541bf0();
    void* __stdcall sub_77e698();
    void* __stdcall sub_77e6ac();
    void __stdcall str_ctor(Str* self, const char* s);
    void __stdcall str_dtor(Str* self);
}

extern float g_8c7e74;
extern float g_8c7e78;
extern float g_8c7e7c;
extern const char g_791ec4[];

struct S {
    void* f();
};

void* S::f() {
    V3* v = (V3*)this;
    sub_5095d0();
    v->x = g_8c7e74;
    v->y = g_8c7e78;
    v->z = g_8c7e7c;
    Str s;
    str_ctor(&s, g_791ec4);
    sub_541bf0();
    str_dtor(&s);
    return this;
}
