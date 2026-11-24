// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: class unknown; self has base-ctor call, field +4 holds pointer whose +8 is a CSize*.
struct CSize;
extern "C" void __fastcall fn_00542820(ListObj* self, int unusedEdx);
extern "C" void* __cdecl fn_006a0920(int size);
extern "C" CSize* __fastcall fn_005f1270(void* self, int unusedEdx, int a, int b);

struct Holder4 {
    int vt;
    struct Inner { int pad[2]; CSize* size; }* inner;
};

extern "C" void __fastcall fn_00542770(Holder4* self, int unusedEdx, Holder4::Inner* arg1)
{
    fn_00542820(self, 0, 0, 0, 0, 0, 0);
    self->inner = arg1;
    if (self->inner) {
        void* mem = fn_006a0920(8);
        CSize* s = 0;
        if (mem)
            s = fn_005f1270(mem, 0, (int)self, self->inner->pad[1]);
        self->inner->size = s;
    }
}
