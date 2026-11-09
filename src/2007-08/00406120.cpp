// from server: 38% by colin
extern "C" void* __cdecl sub_62FEF6(unsigned int);

struct CComEnum {
    void* vtable;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
};

struct CComObjectBase {
    void* vtable;
    void (__stdcall *Release)(void);
};

extern CComObjectBase* g_8BAE44;

struct UIEnumConnections {
    long __stdcall CreateInstance(void** ppv);
};

long UIEnumConnections::CreateInstance(void** ppv) {
    if (ppv == 0) {
        return (long)0x80004003;
    }
    *ppv = 0;
    CComEnum* p = (CComEnum*)sub_62FEF6(0x1c);
    if (p != 0) {
        p->field_4 = 0;
        p->field_10 = 0;
        p->field_C = 0;
        p->field_8 = 0;
        p->field_14 = 0;
        p->field_18 = 0;
        p->vtable = (void*)0x784ff4;
        CComObjectBase* obj = g_8BAE44;
        void** vt = (void**)obj->vtable;
        void (__stdcall *fn)(void) = (void (__stdcall *)(void))vt[1];
        fn();
    }
    *ppv = p;
    return 0;
}
