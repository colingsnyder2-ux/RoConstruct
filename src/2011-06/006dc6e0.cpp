// from server: 61% by colin
struct VTable1 {
    char pad[0x1c];
    bool (__stdcall *check)(void*);
};

struct VTable2 {
    char pad[0x10];
    void (__stdcall *notify)(void*, void*);
};

struct Obj {
    VTable1* vt;
};

struct EventDesc {
    char pad[0x68];
    int field_68;
    char pad2[0x8];
    int field_74;
    char pad3[0x44];
    void* field_bc;
    void removeFromList(void*);
};

extern "C" int __stdcall sub_7b1f10(void*, void*);

void EventDesc::removeFromList(void* p) {
    Obj* obj = (Obj*)p;
    if (obj->vt->check(obj)) {
        sub_7b1f10(&field_68, &obj);
    }
    VTable2* v = (VTable2*)field_bc;
    v->notify(field_bc, obj);
    field_74--;
}
