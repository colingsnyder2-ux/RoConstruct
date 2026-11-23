// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: layouts guessed from the disassembly; boost::signals internals are reached through fn_ externs.
extern "C" void* fn_006a0920(int size); // INFERRED: operator new(0x2c)
extern "C" void __fastcall fn_00591e00(void* list, int unusedEdx);
extern "C" void __fastcall fn_00595780(void* self, int unusedEdx, void* node);
extern "C" void __fastcall fn_00595470(void* sc, int unusedEdx, void* conn);
extern "C" void __fastcall fn_005950f0(void* dst, int unusedEdx, void* src);
extern "C" void __fastcall fn_00595020(void* trackable, int unusedEdx, void* conn, void* bound);
extern "C" void* __fastcall fn_00595140(void* list, int unusedEdx, void* a, void* b, void* c);
extern "C" void __fastcall fn_00595190(void* list, int unusedEdx, int n);
extern "C" void __fastcall fn_00595500(void* sc, int unusedEdx, void* out);
extern "C" void __fastcall fn_00595370(void* conn, int unusedEdx);
extern "C" void __fastcall fn_005954b0(void* sc, int unusedEdx);

// INFERRED: unknown global at 0x47d410 (binder vtable)
extern "C" char g_0047d410[];

struct Slots {
    void** begin;   // +0
    int pad[2];
    void** cur;     // +0xc
    void** end;     // +0x10
};

struct Owner {
    Slots* slots;   // +0
};

struct Binder {
    Owner* owner;      // +0
    int zero;          // +4
    void* vtbl;        // +8
    char flag;         // +0xc
    int pad;
    char list[0x1c];   // +0x10
};

extern "C" void __fastcall fn_00595840(Owner* self, int unusedEdx)
{
    Binder* b = (Binder*)fn_006a0920(0x2c);
    if (b)
        fn_00591e00(b->list, 0);
    b->owner = self;
    b->zero = 0;
    b->flag = 0;
    b->vtbl = (void*)g_0047d410;
    fn_00595780((char*)self->slots + 0x18, 0, b);

    char sc[12];
    fn_00595470(sc, 0, (char*)self->slots + 0x18);

    // INFERRED: iterate slot vector, re-connecting each trackable into the binder's list
    void** it = self->slots->cur;
    while (it != self->slots->end) {
        char conn[12];
        char bound[12];
        fn_005950f0(conn, 0, (char*)self->slots + 0x18);
        fn_00595020(*it, 0, conn, bound);
        void* n = fn_00595140(b->list, 0, 0, 0, bound);
        fn_00595190(b->list, 0, 1);
        (void)n;
        ++it;
    }

    char out[12];
    fn_00595500(sc, 0, out);
    fn_00595370(out, 0);
    *((char*)self->slots + 0x24) = 1;
    fn_005954b0(sc, 0);
}
