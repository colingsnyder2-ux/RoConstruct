// from server: 53% by atomic.potato
struct VRegion3int16 {
    int x, y, z;
};

extern "C" void __stdcall G1_func_006c5510();
extern "C" void* __fastcall func_007c5de0(void*);
extern "C" void* __fastcall func_006c5510(void*);

typedef bool (__stdcall *type_info_eq)(const void*, const void*);

struct S {
    void* vtable;
    void* ptr;
    char pad[8];
    VRegion3int16* get(VRegion3int16* out);
};

VRegion3int16* S::get(VRegion3int16* out) {
    void* vt = vtable;
    void* ti = *(void**)((char*)vt + 0x10);
    if (ti != (void*)0xda1ffc) {
        type_info_eq eq = *(type_info_eq*)0xb229ec;
        if (!eq(ti, (void*)0xda1ffc)) {
            void* p = ptr;
            void* v = vtable;
            void* local[3];
            local[0] = v;
            local[1] = 0;
            if (p) {
                void (*fn)(void*, void*) = *(void (**)(void*, void*))((char*)p + 8);
                fn((char*)this + 8, &local[2]);
            }
            local[1] = ptr;
            func_006c5510(&local[0]);
            VRegion3int16* r = (VRegion3int16*)func_007c5de0(&local[0]);
            out->x = r->x;
            out->y = r->y;
            out->z = r->z;
            void* p2 = local[1];
            if (p2) {
                void (*fn2)(void*) = *(void (**)(void*))((char*)p2 + 4);
                fn2(&local[2]);
            }
            return out;
        }
    }
    VRegion3int16* r = (VRegion3int16*)func_007c5de0((char*)this + 4);
    out->x = r->x;
    out->y = r->y;
    out->z = r->z;
    return out;
}
