// from server: 21% by colin
struct DataState;
struct SelItem { int a; int b; int c; };

struct Vec {
    SelItem* begin;
    SelItem* end;
    SelItem* cap;
};

struct Inner {
    char pad0[0xf4];
    Vec vec;
};

struct Obj {
    char pad0[0x20];
    Inner* inner;
};

struct Sel {
    char pad0[0x2d4];
};

struct DataModel {
    char pad0[0xc];
    Sel* sel;
};

struct Verb {
    char pad0[0x20];
    Obj* obj;
    char pad1[0x8];
    DataModel* dm;
    void doIt(DataState*);
};

struct Tmp {
    char pad0[0x24];
    int flag;
    char pad1[0x28];
};

extern "C" void __stdcall sub_55e290();
extern "C" void __stdcall sub_5618e0();
extern "C" void __stdcall sub_5e0d50();
extern "C" void __stdcall sub_5e0660();
extern "C" void __stdcall sub_5e09e0();
extern "C" void __stdcall sub_5e0fa0();
extern "C" void __stdcall sub_55a920();
extern "C" void __stdcall sub_58c810();
extern "C" void __stdcall sub_558b60();
extern "C" void __stdcall sub_4108b0();
extern "C" void __stdcall sub_5e0ef0();

extern float g_7a95dc;

void Verb::doIt(DataState* ds)
{
    Obj* o = this->obj;
    sub_55e290();
    Inner* in;
    if (this->obj) {
        sub_5618e0();
        in = this->obj->inner;
    } else {
        in = 0;
    }
    Vec* v = &in->vec;
    if (v->end == v->begin) {
        return;
    }
    Tmp tmp;
    sub_5e0d50();
    sub_5e0660();
    float f0 = 0.0f;
    float f1 = g_7a95dc;
    sub_5e09e0();
    sub_5e0fa0();
    int esi;
    if (f0 == tmp.flag) {
        esi = 1;
    } else {
        esi = 4;
    }
    Obj* o2;
    if (this->obj) {
        sub_55a920();
        o2 = this->obj;
    } else {
        o2 = 0;
    }
    sub_58c810();
    Sel* s = this->dm->sel;
    sub_558b60();
    sub_4108b0();
    sub_5e0ef0();
}
