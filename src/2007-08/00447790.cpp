// from server: 45% by colin
struct CRenderSettings {
    char pad[0x118];
    int widthHeight;
    char pad2[4];
    int field11c;
};

extern int g_888554;
extern int g_888558;
extern int g_897a60;

struct Vtable {
    char pad[8];
    void (__stdcall *fn8)(void*, char*);
};

struct Obj8bbd30 {
    Vtable* vt;
};

extern Obj8bbd30* g_obj8bbd30;

void __stdcall sub_447650(int);
void __stdcall sub_444710(void*, const char*);
int __stdcall sub_472f80();

void sub_447790(CRenderSettings* self) {
    char local;
    int w, h;
    sub_447650(1);
    local = 1;
    void* p = self ? (void*)((char*)self + 4) : 0;
    Obj8bbd30* o = g_obj8bbd30;
    o->vt->fn8(o, &local);
    if (g_888554 != 1) {
        g_888554 = 1;
        sub_444710(self, (const char*)0x8bbcf8);
    }
    int v = g_888558;
    if (v != self->field11c) {
        self->field11c = v;
        sub_444710(self, (const char*)0x8bbc18);
    }
    int r = sub_472f80();
    if ((unsigned)r >= 0xf42400) {
        w = 0x400;
        h = 0x300;
    } else {
        w = 0x320;
        h = 0x258;
    }
    if (w != self->widthHeight) {
        self->widthHeight = w;
        sub_444710(self, (const char*)0x8bbc34);
    }
    if (g_897a60 != 1) {
        g_897a60 = 1;
        sub_444710(self, (const char*)0x8bbcc0);
    }
}
