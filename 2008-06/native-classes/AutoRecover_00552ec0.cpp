// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this looks like std::vector<T>::pop_back with a 4-byte element;
// [this+0x10] is _Mylast and fn_00552fd0 is empty().
struct PodVec4 {
    int pad0;
    int pad1;
    int pad2;
    int pad3;
    char* last; // +0x10
};

// INFERRED: the disassembly pushes no stack args for this call, so the
// 2 stack args in the supplied declaration are dropped. Returns bool in al.
extern "C" unsigned char __fastcall fn_00552fd0(void* self, int unusedEdx);
extern "C" void __fastcall fn_005467b0(void* self, int unusedEdx, void* first, void* last);

extern "C" void __fastcall fn_00552ec0(PodVec4* self, int unusedEdx)
{
    if (!fn_00552fd0(self, 0)) {
        fn_005467b0(self, 0, self->last - 4, self->last);
        self->last = self->last - 4;
    }
}
