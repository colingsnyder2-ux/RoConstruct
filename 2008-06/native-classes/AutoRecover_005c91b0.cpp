// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: shared-count style control block (vptr, use=1, weak=1, ptr); the real type name is unknown.
extern "C" void* fn_006a0920(unsigned size);

struct CountedBlock2008 {
    virtual ~CountedBlock2008() {}
    int use;
    int weak;
    int ptr;
};

struct Holder2008 {
    CountedBlock2008* block;
};

extern "C" Holder2008* __fastcall fn_005c91b0(Holder2008* self, int unusedEdx, int arg1, int arg2)
{
    self->block = 0;
    CountedBlock2008* b = (CountedBlock2008*)fn_006a0920(0x14);
    if (b) {
        b->use = 1;
        b->weak = 1;
        b->ptr = arg1;
        // vptr set by compiler-emitted store (0x839bec)
    }
    self->block = b;
    return self;
}
