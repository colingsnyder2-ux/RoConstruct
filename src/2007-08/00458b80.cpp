// from server: 87% by colin
// roc 2007-08 00458b80  unit: CRobloxWnd  size: 122 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00458b80

extern "C" void __stdcall sub_478db0();
extern "C" void __stdcall sub_478870();
extern "C" void __stdcall sub_62fc62(void*);

struct CRobloxWnd {
    char pad[0x94];
    void* field_94;
    void* field_9c;
    void method();
};

void CRobloxWnd::method() {
    void* p = field_94;
    if (*(void**)0x8bd0d8 != p) {
        (*(void (__thiscall**)(void*))(*(int*)p + 0x98))(p);
        *(void**)0x8bd0d8 = p;
    }
    void* q = field_9c;
    if (q != 0) {
        sub_478db0();
        void* r = field_9c;
        if (r != 0) {
            sub_478870();
            sub_62fc62(r);
        }
        field_9c = 0;
    }
    void* s = field_94;
    if (s != 0) {
        (*(void (__thiscall**)(void*, int))(*(int*)s + 0x9c))(s, 1);
        field_94 = 0;
    }
}
