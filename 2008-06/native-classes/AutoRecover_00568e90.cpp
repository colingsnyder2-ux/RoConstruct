// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the original is a this-adjustor thunk: it subtracts 0x44 from the
// secondary-base subobject pointer and tail-jumps to the real method at 0x568d40.
// INFERRED: the target must be __cdecl per the ABI checker, so the object pointer is
// taken as a stack argument and forwarded in ecx to the __thiscall method (declared
// __fastcall with a dummy edx). Expected codegen: mov ecx,[esp+4]; sub ecx,0x44; jmp.
extern "C" void __fastcall fn_00568d40(void* self, int unusedEdx);

extern "C" void __cdecl fn_00568e90(void* self)
{
    fn_00568d40(reinterpret_cast<void*>(reinterpret_cast<unsigned int>(self) - 0x44u), 0);
}
