// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" void* fn_006a0920(unsigned int size);

// INFERRED: 0x14-byte refcount-style control block; vtable at 0x819868, two counts at +4/+8, payload at +0xc.
struct CtrlBlock {
    virtual ~CtrlBlock() {}
    int uses;
    int weak;
    void* ptr;
    int pad; // INFERRED: size 0x14 requires it
};

struct Holder {
    CtrlBlock* block;
};

// INFERRED: unknown owner class, treated as a holder of one pointer
extern "C" Holder* __fastcall fn_0045b830(Holder* self, int unusedEdx, void* arg)
{
    self->block = 0;
    CtrlBlock* b = (CtrlBlock*)fn_006a0920(0x14);
    if (b) {
        b->uses = 1;
        b->weak = 1;
        b->ptr = arg;
    }
    self->block = b;
    return self;
}
