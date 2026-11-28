// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS /hotpatch

// INFERRED: the call goes through the import slot at 0x00965cf4. Its real name and
// signature are unknown, so it is declared as a dllimport stdcall with two arguments.
extern "C" __declspec(dllimport) int __stdcall fn_00965cf4(unsigned int arg, int flag);

// INFERRED: the original keeps an ebp frame (push ebp / mov ebp, esp / pop ebp),
// so frame-pointer omission is turned off for this function.
// NOTE: the leading "mov edi, edi" hot-patch padding in the original cannot be
// produced from source alone under these fixed flags, so the first instruction
// may still differ.
#pragma optimize("y", off)
extern "C" int __stdcall fn_006a2550(unsigned int arg)
{
    return fn_00965cf4(arg, 0);
}
#pragma optimize("", on)
