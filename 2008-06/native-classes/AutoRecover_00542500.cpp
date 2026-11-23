// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: std::set<int> node pool-like container; fields +0xc begin, +0x10 size, +0x14 end, node size 0x28
struct Holder {
    int pad0;
    int pad4;
    int pad8;
    int* first;
    int* last;
    int* end;
    void clear();
};

extern "C" int __fastcall fn_005442f0(void* self, int unusedEdx, int a1, int a2);
extern "C" void __fastcall fn_00543610(void* self, int unusedEdx, int ptr, int count);

extern "C" void __fastcall fn_00542500(Holder* self, int unusedEdx)
{
    if (self->first) {
        fn_005442f0(self, 0, (int)self->first, (int)self->last);
        fn_00543610((char*)self + 8, 0, (int)self->first, ((int)self->end - (int)self->first) / 0x28);
    }
    self->first = 0;
    self->last = 0;
    self->end = 0;
}
