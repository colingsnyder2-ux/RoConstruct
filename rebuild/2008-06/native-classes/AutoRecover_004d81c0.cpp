// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no headers were provided, so every type here is a local stand-in
// reconstructed from the disassembly. The call order and control flow follow
// the disassembly; the types and the temporaries' stack layout are guesses.

struct sp_counted_base {
    virtual void dispose() = 0;   // vtbl+0 (dispose)
    virtual void destroy() = 0;   // vtbl+4
    virtual void unused() = 0;    // vtbl+8
    int use_count;                // +4
    int weak_count;               // +8
};

struct SlotData {
    int pad0;
    int pad1;
    int connectionState;          // +8, tested for non-zero
};

struct SlotBase {
    int pad[7];
    SlotData* data;               // +0x1c
};

struct SignalImpl;

struct Connection {
    int pad0;
    int p1;                       // +4
    int p2;                       // +8
    unsigned char flag;           // +0xc
};

struct AnyHolder {
    struct Vt { void (__fastcall *dtor)(AnyHolder*, int, int); };
    Vt* vt;
};

struct Owner {
    SignalImpl* signal;           // [this]
};

struct SharedCount {
    int* px;
    sp_counted_base* pn;
};

// INFERRED: the disassembly pushes a single stack argument (4) and cleans it
// up with "add esp, 4", so this is really an allocator, i.e. operator new.
// The brief's declaration of this callee as a __fastcall helper with 7 args
// does not match the call site.
extern "C" void* __cdecl fn_006a0920(unsigned size);

extern "C" void __fastcall fn_0042a800(SharedCount* self, int unusedEdx, int* p);
extern "C" void __cdecl fn_0047d410(SharedCount* a, int* b, int* c);
extern "C" void __fastcall fn_004d7d50(void* self, int unusedEdx, void* func);
extern "C" void __fastcall fn_004915b0(SlotBase* self, int unusedEdx, void* outSharedPtr, void* a);
extern "C" void __fastcall fn_0056a900(SignalImpl* self, int unusedEdx, void* ret, void* slotData, void* any);

extern "C" Connection* __fastcall fn_004d81c0(Owner* self, int unusedEdx,
                                              Connection* ret, int* value,
                                              SlotBase* slot, void* unused4)
{
    SlotData* d = slot->data;
    if (!d || d->connectionState == 0) {
        ret->p1 = 0;
        ret->p2 = 0;
        ret->flag = 0;
        return ret;
    }

    int* p = (int*)fn_006a0920(4);
    if (p)
        *p = *value;

    SharedCount sc;
    fn_0042a800(&sc, 0, p);
    SharedCount tmp;
    fn_0047d410(&tmp, p, p);

    AnyHolder* any = 0;
    fn_004d7d50(&any, 0, (char*)slot + 8);

    struct { void* a; void* b; } sharedData;
    fn_004915b0(slot, 0, &sharedData, &sharedData);

    fn_0056a900(self->signal, 0, ret, sharedData.a, &sc);

    if (any)
        any->vt->dtor(any, 0, 1);

    sp_counted_base* pn = sc.pn;
    if (pn) {
        if (--pn->use_count == 0) {
            pn->dispose();
            if (--pn->weak_count == 0)
                pn->unused();
        }
    }
    return ret;
}
