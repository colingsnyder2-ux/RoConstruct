// from server: 100% by colin
// roc 2007-08 00653de0  unit: XTP_REPORTRECORDITEM_METRICS  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00653de0

extern "C" void __fastcall sub_63069a(void*);
extern "C" void __cdecl sub_62fc62(void*);

typedef void (__fastcall *FuncPtr77ddbc)(void*);
extern FuncPtr77ddbc g_77ddbc;

struct XTP_REPORTRECORDITEM_METRICS {
    char pad[0x2c];
    int field_2c;
    XTP_REPORTRECORDITEM_METRICS* destroy(unsigned int flags);
};

XTP_REPORTRECORDITEM_METRICS* XTP_REPORTRECORDITEM_METRICS::destroy(unsigned int flags) {
    g_77ddbc((void*)((char*)this + 0x2c));
    sub_63069a(this);
    if (flags & 1) {
        sub_62fc62(this);
    }
    return this;
}
