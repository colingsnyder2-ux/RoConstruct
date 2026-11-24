// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

extern "C" __declspec(dllimport) void __cdecl _invalid_parameter_noinfo(void);

// INFERRED: no class header was found. The object has a data pointer at +0xC,
// and 0x546320 (labelled ConvexBody::getPolygonCount) is likely an identical
// size() routine folded together with it.
struct ElemContainer {
    int pad0;
    int pad1;
    int pad2;
    unsigned* first; // +0xC
};

extern "C" unsigned __fastcall fn_00546320(ElemContainer* self, int unusedEdx);

// INFERRED: this looks like a checked vector<T>::operator[] returning &first[index] for a 4-byte element.
extern "C" unsigned* __fastcall fn_00552e60(ElemContainer* self, int unusedEdx, unsigned index)
{
    if (!(index < fn_00546320(self, 0)))
        _invalid_parameter_noinfo();
    return self->first + index;
}
