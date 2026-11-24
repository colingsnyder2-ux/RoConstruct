// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the original is a this-adjustor thunk: it subtracts 0x10 from ecx
// and then jumps to fn_005e1de0, which is a __thiscall member on the outer
// object. The required ABI for this target is __cdecl, and portable C++
// cannot read ecx under __cdecl. So the object pointer is modelled here as an
// explicit argument.
// INFERRED: fn_005e1de0 is __thiscall with no stack arguments. It is declared
// __fastcall (object in ecx, dummy edx), and its return type is a guess.
extern "C" int __fastcall fn_005e1de0(char* self, int unusedEdx);

extern "C" int __cdecl fn_005e1d10(char* self)
{
    return fn_005e1de0(self - 0x10, 0);
}
