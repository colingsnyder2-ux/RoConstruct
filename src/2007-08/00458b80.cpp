// from server: 100% by EspClaude
// roc 2007-08 00458b80  unit: CRobloxWnd  size: 122 bytes

struct Helper9c {
    void method_478db0();
    void method_478870();
};
extern "C" void sub_62fc62(void*);

struct Obj94;
extern Obj94* g_current_8bd0d8;

struct CRobloxWnd {
    char pad[0x94];
    Obj94* field_94;
    char pad98[4];
    Helper9c* field_9c;
    void method();
};

void CRobloxWnd::method() {
    Obj94* p = field_94;
    if (g_current_8bd0d8 != p) {
        (*(void (__thiscall**)(void*))(*(int*)p + 0x98))(p);
        g_current_8bd0d8 = p;
    }
    if (field_9c != 0) {
        field_9c->method_478db0();
        Helper9c* r = field_9c;
        if (r != 0) {
            r->method_478870();
            sub_62fc62(r);
        }
        field_9c = 0;
    }
    Obj94* s = field_94;
    if (s != 0) {
        (*(void (__thiscall**)(void*, int))(*(int*)s + 0x9c))(s, 1);
        field_94 = 0;
    }
}
