// from server: 33% by colin
struct type_info {
    bool operator==(const type_info&) const;
};

struct variant {
    unsigned short vt;
    unsigned short pad;
    union {
        int i;
        float f;
        void* p;
    } val;
};

struct any {
    void* vtable;
    type_info* info;
};

extern type_info type_info_8827c8;
extern type_info type_info_8827d4;
extern type_info type_info_8827e0;
extern type_info type_info_8827ec;
extern type_info type_info_8827f8;

extern "C" void __stdcall VariantClear(variant* v);

extern "C" void* __stdcall unknown_77e6a8(void*);
extern "C" void __stdcall unknown_77e6ac(void*);
extern "C" void __stdcall unknown_77e9d8(void*);

extern "C" int __cdecl sub_411A00(any*);
extern "C" bool __cdecl sub_411AA0(any*);
extern "C" float __cdecl sub_411B40(any*);
extern "C" void __cdecl sub_411D40(any*, void*);
extern "C" void* __cdecl sub_412090(void*);
extern "C" void __cdecl sub_411530(void*, void*);
extern "C" void __cdecl sub_411590(void*, variant*);
extern "C" bool __cdecl sub_411810(any*);
extern "C" bool __cdecl sub_411830(any*);
extern "C" void __cdecl sub_411DE0(void*, const char*);
extern "C" void __cdecl sub_411E00(any*, void*);
extern "C" void __cdecl sub_411E30(any*, void*);

struct bad_any_cast {
    void cast(variant* out);
};

void bad_any_cast::cast(variant* out) {
    any* a = (any*)((char*)this - 4);
    if (type_info_8827c8 == *a->info) {
        out->vt = 1;
        return;
    }
    if (type_info_8827d4 == *a->info) {
        int v = sub_411A00(a);
        out->vt = 3;
        out->val.i = v;
        sub_411590(out, out);
        unknown_77e9d8(out);
        return;
    }
    if (type_info_8827e0 == *a->info) {
        bool b = sub_411AA0(a);
        out->vt = 0xb;
        out->val.i = b ? -1 : 0;
        sub_411590(out, out);
        unknown_77e9d8(out);
        return;
    }
    if (type_info_8827ec == *a->info) {
        float f = sub_411B40(a);
        out->vt = 4;
        out->val.f = f;
        sub_411590(out, out);
        unknown_77e9d8(out);
        return;
    }
    if (type_info_8827f8 == *a->info) {
        void* tmp;
        sub_411E00(a, &tmp);
        const char* s = (const char*)unknown_77e6a8(&tmp);
        sub_411DE0(out, s);
        unknown_77e6ac(&tmp);
        sub_411590(out, out);
        unknown_77e9d8(out);
        return;
    }
    if (sub_411810(a)) {
        void* tmp;
        sub_411E30(a, &tmp);
        const char* s = (const char*)unknown_77e6a8(&tmp);
        sub_411DE0(out, s);
        unknown_77e6ac(&tmp);
        sub_411590(out, out);
        unknown_77e9d8(out);
        return;
    }
    if (sub_411830(a)) {
        void* p;
        sub_411D40(a, &p);
        void* q = sub_412090(p);
        sub_411530(out, q);
        sub_411590(out, out);
        unknown_77e9d8(out);
        return;
    }
    out->vt = 0;
}
