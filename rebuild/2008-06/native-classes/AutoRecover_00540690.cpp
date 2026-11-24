// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the object is a std::vector<int>-like container (size()/capacity() helpers
// are mis-named in the symbol comments); the field at +0x10 is the "last" iterator used
// by the in-place fill path.
struct IntVecLike {
    int pad0[4];
    int last;   // +0x10
};

extern "C" unsigned __fastcall fn_00546320(void* self, int unusedEdx);   // size()
extern "C" unsigned __fastcall fn_005462e0(void* self, int unusedEdx);   // capacity()
extern "C" int __fastcall fn_00541540(void* self, int unusedEdx, int a1, int a2, int a3);
extern "C" int __fastcall fn_00540660(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_00541380(void* self, int unusedEdx, int a1, int a2, int a3, int a4);

extern "C" void __fastcall fn_00540690(IntVecLike* self, int unusedEdx, int value)
{
    if (fn_00546320(self, 0) < fn_005462e0(self, 0)) {
        self->last = fn_00541540(self, 0, self->last, 1, value);
    } else {
        int tmp[2];
        int out[2];
        int* p = (int*)fn_00540660(self, 0, (int)tmp);
        int pair[2];
        pair[0] = p[0];
        pair[1] = p[1];
        fn_00541380(self, 0, (int)out, pair[0], pair[1], value);
    }
}
