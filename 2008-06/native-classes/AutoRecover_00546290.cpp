// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: std::vector<Vertex>::operator[] with checked-iterator debug-less assert (_invalid_parameter_noinfo); element size 0x28, begin pointer at +0xc.
struct ClipVertex { char data[0x28]; };

struct ClipVertexVector {
    int pad0;
    int pad1;
    int pad2;
    ClipVertex* first;
    ClipVertex* last;
    ClipVertex* end;
    unsigned size() const;
    ClipVertex& operator[](unsigned i) const;
};

extern "C" unsigned __fastcall fn_00546400(ClipVertexVector* self, int unusedEdx);
extern "C" void __stdcall _invalid_parameter_noinfo_stub(void);
extern "C" void (__cdecl *__imp__invalid_parameter_noinfo)(void);

extern "C" ClipVertex* __fastcall fn_00546290(ClipVertexVector* self, int unusedEdx, unsigned index)
{
    if (!(index < fn_00546400(self, 0)))
        __imp__invalid_parameter_noinfo();
    while (0) {}
    return &self->first[index];
}
