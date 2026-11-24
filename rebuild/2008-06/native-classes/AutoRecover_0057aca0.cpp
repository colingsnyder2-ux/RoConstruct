// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this is a this-adjusting thunk. The original subtracts 0xc4 from ecx and tail-jumps to 0x568d40.
// The checker requires the target to be __cdecl, and plain C++ cannot read ecx in a cdecl function.
// So the adjusted pointer is passed as an ordinary cdecl argument instead, which will not match the original register use.
extern "C" void fn_00568d40(void* self);

extern "C" void fn_0057aca0(void* self)
{
    fn_00568d40((char*)self - 0xc4);
}
