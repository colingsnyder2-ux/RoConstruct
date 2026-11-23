// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" int __fastcall fn_0040a1c0(void* self, int unusedEdx, int a1, int a2, int a3);

// INFERRED: layout from disassembly; vector of dwords at +0x10/+0x14, iteration-state pointer at +0x1c
struct IterState {
    unsigned index;
    unsigned count;
    void* saved;
};

struct Obj40a530 {
    char pad0[0x10];
    int* begin;
    int* end;
    char pad18[4];
    IterState* iter;
};

extern "C" void __fastcall fn_0040a530(Obj40a530* self, int unusedEdx, int a1, int a2)
{
    IterState st;
    st.index = 0;
    st.count = (unsigned)(self->end - self->begin);
    st.saved = self->iter;
    self->iter = &st;
    if (st.count != 0) {
        do {
            fn_0040a1c0(self, 0, a1, a2, self->begin[st.index]);
            ++st.index;
        } while (st.index < st.count);
    }
    self->iter = (IterState*)st.saved;
}
