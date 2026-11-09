// from server: 90% by atomic.potato
// roc 2009-12 004f5590  unit: RBX::GfxAttachement  size: 57 bytes
// library rbxgs-net/Player.cpp

struct type_info {
    bool __thiscall operator==(const type_info&) const;
};

extern "C" {
    typedef bool (__stdcall *TypeInfoEqFn)(const type_info*, const type_info*);
    extern TypeInfoEqFn g_typeInfoEq;
}

struct S {
    void* field0;
    void* getTypeInfo();
};

void* S::getTypeInfo() {
    void* p = field0;
    if (p) {
        void** vtbl = *(void***)p;
        typedef void* (__thiscall *Fn)(void*);
        Fn f = (Fn)vtbl[1];
        return f(p);
    }
    return (void*)0x00b0030c;
}

void* __cdecl func(S* obj) {
    if (!obj) return 0;
    void* ti = obj->getTypeInfo();
    const type_info* target = (const type_info*)0x00b033e8;
    if (g_typeInfoEq((const type_info*)ti, target)) {
        return (char*)obj->field0 + 4;
    }
    return 0;
}
