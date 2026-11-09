// from server: 55% by colin
struct Scintilla_CScintillaView {
    void* vtable;
    char pad[0x54];
    char inner[0x100];
    void func_0045d5c0(int, int, int, int, int, int);
};

extern "C" void* __stdcall sub_77dd6c(void*);
extern "C" void* __stdcall sub_77dd98(void*, int, int, int, int);

extern char g_88a57c;
extern char g_88a580;
extern int g_88a584;
extern int g_88a588;
extern int g_88a58c;
extern int g_88a590;

extern void sub_45ca90(void*, void*);

void Scintilla_CScintillaView::func_0045d5c0(int a1, int a2, int a3, int a4, int a5, int a6)
{
    sub_77dd6c(&g_88a57c);
    sub_77dd6c(&g_88a580);

    g_88a584 = a2;
    g_88a588 = a1;
    g_88a58c = a3;
    g_88a590 = a4;

    void* vt = vtable;
    void* r = sub_77dd98(&g_88a57c, a1, a2, a3, a4);
    int (*fn1)(void*, void*) = *(int (**)(void*, void*))((char*)vt + 0x1b8);
    if (fn1(this, r) == 0) {
        void* vt2 = vtable;
        void* r2 = sub_77dd98(&g_88a57c, a1, a2, a3, a4);
        int (*fn2)(void*, void*) = *(int (**)(void*, void*))((char*)vt2 + 0x1a4);
        if (fn2(this, r2) == 0) {
            void* vt3 = vtable;
            void* r3 = sub_77dd98(&g_88a57c, a1, a2, a3, a4);
            int (*fn3)(void*, void*, int) = *(int (**)(void*, void*, int))((char*)vt3 + 0x1a0);
            fn3(this, r3, 1);
            return;
        }
    } else {
        void* r4 = sub_77dd98(&g_88a580, 1, 0, 0, 0);
        sub_45ca90(inner, r4);

        void* vt4 = vtable;
        void* r5 = sub_77dd98(&g_88a57c, a1, a2, a3, a4);
        int (*fn4)(void*, void*) = *(int (**)(void*, void*))((char*)vt4 + 0x1a4);
        if (fn4(this, r5) == 0) {
            void* vt5 = vtable;
            void* r6 = sub_77dd98(&g_88a57c, a1, a2, a3, a4);
            int (*fn5)(void*, void*, int) = *(int (**)(void*, void*, int))((char*)vt5 + 0x1a0);
            fn5(this, r6, 1);
            return;
        }
    }

    int (*fn6)(void*) = *(int (**)(void*))((char*)vtable + 0x1c0);
    fn6(this);
}
