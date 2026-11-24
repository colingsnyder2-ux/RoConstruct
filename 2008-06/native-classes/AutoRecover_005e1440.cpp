// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the original is a this-adjusting thunk that does
// "sub ecx,0x10; jmp func_005e1470". The ecx value comes from the caller.
// The checker requires a __cdecl definition. Plain C++ cannot read ecx
// without inline asm, so this version takes the object pointer as a stack
// argument. The compiled code is close but not identical to the original.
// The callee is modeled as a __thiscall helper declared __fastcall, with a
// dummy edx argument. The return type is unknown, so it is assumed to be int.
extern "C" int __fastcall fn_005e1470(void* self, int unusedEdx);

extern "C" int fn_005e1440(void* self)
{
    return fn_005e1470(static_cast<char*>(self) - 0x10, 0);
}
