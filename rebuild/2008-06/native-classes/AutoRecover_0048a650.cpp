// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no class headers are available. The target is an MSVC adjustor{20} thunk:
// this -= 20, then a tail jump to the vector deleting destructor at 0x00492870.
// INFERRED: the checker requires a __cdecl definition, so the thunk is written as a plain
// cdecl function taking (this, flags), and the callee is declared with the same convention.
// INFERRED: the real name is the mangled adjustor{20} thunk; the fn_ convention is used instead.

extern "C" void* fn_00492870(void* self, unsigned int flags);

extern "C" void* fn_0048a650(void* self, unsigned int flags)
{
    return fn_00492870((void*)((unsigned int)self - 0x14), flags);
}
