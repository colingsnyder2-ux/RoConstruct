// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: G3D::Array<G3D::Vector3>::resize(int, bool) (__thiscall, 2 stack args).
extern "C" void __fastcall fn_005025c0(void* self, int unusedEdx, int newSize, bool shrinkToFit);

// INFERRED: G3D::Array<G3D::Vector3>::fastClear() (__thiscall, 0 stack args).
extern "C" void __fastcall fn_00502f40(void* self, int unusedEdx)
{
    fn_005025c0(self, unusedEdx, 0, false);
}
