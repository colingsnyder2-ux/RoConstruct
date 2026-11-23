// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: object holds a std::set<int> at offset 8; the target is its (non-inlined) destructor wrapper.
extern "C" void __fastcall fn_00540dc0(void* tree, int unusedEdx);
extern "C" void __fastcall fn_005404d0(char* self, int unusedEdx)
{
    fn_00540dc0(self + 8, 0);
}
