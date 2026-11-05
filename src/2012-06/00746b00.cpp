// from server: 39% by atomic.potato
extern "C" {
    void __stdcall sub_40F520(void*);
}

struct type_info {
    bool operator==(const type_info&) const;
};

struct bad_cast {
    bad_cast(const char*);
};

extern type_info* g_typeinfo_0;
extern type_info* g_typeinfo_1;
extern void* g_vtable_0;

struct S {
    void* field0;
    void func();
};

void S::func()
{
    void* p = this->field0;
    type_info* ti;
    if (p) {
        ti = *(type_info**)p;
    } else {
        ti = g_typeinfo_0;
    }
    if (ti != g_typeinfo_1) {
        type_info* ti2;
        if (p) {
            ti2 = *(type_info**)p;
        } else {
            ti2 = g_typeinfo_0;
        }
        if (!ti2->operator==(*g_typeinfo_1)) {
            goto end;
        }
        bad_cast bc("bad cast");
        *(void**)((char*)&bc + 4) = g_vtable_0;
        void* local = (char*)&bc + 4;
        sub_40F520(&local);
    }
end:
    ;
}
