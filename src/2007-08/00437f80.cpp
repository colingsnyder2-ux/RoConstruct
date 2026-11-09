// from server: 40% by colin
struct CComVariant {
    void Clear();
    void* p;
};

struct CStandardOutputView {
    char pad[0x0c];
    void* field_0c;
    char pad2[0xf4 - 0x10];
    void* field_f4;
    char pad3[0x104 - 0xf8];
    unsigned int field_104;
    char pad4[0x10c - 0x108];
    void* field_10c;
    void func_00437f80(CComVariant* var);
};

extern "C" void __stdcall VariantClear(void* pvarg);

void CStandardOutputView::func_00437f80(CComVariant* var)
{
    CComVariant local10;
    CComVariant local14;
    CComVariant local18;
    CComVariant local1c;
    CComVariant local20;
    CComVariant local24;
    CComVariant local28;
    CComVariant local2c;
    CComVariant local30;
    CComVariant local34;
    CComVariant local38;
    CComVariant local3c;

    local10.p = 0;
    if (var != 0) {
        void** vtbl = *(void***)var;
        void (*fn)(void*, void*, void*) = (void (*)(void*, void*, void*))vtbl[0];
        fn(var, (void*)0x78cd80, &local10);
    }

    local30.p = 0;
    local14.p = 0;

    void* p = field_10c;
    void** vtbl2 = *(void***)p;
    void (*fn2)(void*, void*, void*) = (void (*)(void*, void*, void*))vtbl2[0x4c / 4];
    fn2(p, local14.p, &local14);

    if (fn2 != 0) {
        goto cleanup;
    }

    *(unsigned short*)&local18 = 2;
    *(unsigned short*)&local20 = 0;

    void* p2 = field_10c;
    void** vtbl3 = *(void***)p2;
    void (*fn3)(void*, void*, void*, void*, void*) = (void (*)(void*, void*, void*, void*, void*))vtbl3[0xb8 / 4];
    fn3(p2, var, local18.p, local1c.p, local20.p);

    VariantClear(&local18);

    void* p3 = field_10c;
    void** vtbl4 = *(void***)p3;
    void (*fn4)(void*, void*, void*) = (void (*)(void*, void*, void*))vtbl4[0x34 / 4];
    fn4(p3, local10.p, &local38);

    if (field_104 > 0x190) {
        local38.p = 0;
        void* p4 = field_10c;
        void** vtbl5 = *(void***)p4;
        void (*fn5)(void*, void*, void*) = (void (*)(void*, void*, void*))vtbl5[0x34 / 4];
        fn5(p4, local10.p, &local38);

        if (local38.p != 0) {
            void** vtbl6 = *(void***)local38.p;
            void (*fn6)(void*) = (void (*)(void*))vtbl6[2];
            fn6(local38.p);
        }
    }

cleanup:
    if (local14.p != 0) {
        void** vtbl7 = *(void***)local14.p;
        void (*fn7)(void*) = (void (*)(void*))vtbl7[2];
        fn7(local14.p);
    }
    if (local10.p != 0) {
        void** vtbl8 = *(void***)local10.p;
        void (*fn8)(void*) = (void (*)(void*))vtbl8[2];
        fn8(local10.p);
    }
}
