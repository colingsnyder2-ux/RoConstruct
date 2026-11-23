// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: std::allocator<T>::max_size() for 4-byte T (0x1fffffff = UINT_MAX/8 style bound), max(1, n) form.
struct Allocator550de0 {};

extern "C" unsigned int __fastcall fn_00550de0(Allocator550de0* self, int unusedEdx)
{
    unsigned int count = 0x1fffffff;
    return count > 0 ? count : 1;
}
