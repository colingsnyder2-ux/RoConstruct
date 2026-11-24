// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the disassembly reads its argument from [ebp+8] and returns with a plain
// `ret`, so the target is a cdecl function taking one pointer. This contradicts the
// "__thiscall, 0 stack args" hint in the task header, and I followed the code.
// INFERRED: the callee at 0x53f9e0 is called with a single pushed argument (self + 0x24),
// so I declare it with one argument instead of the three in the inferred declaration.
extern "C" unsigned char fn_0053f9e0(void* a1);
extern "C" unsigned char fn_0053f970(void* a1);

extern "C" bool fn_0053f920(char* self)
{
    if (fn_0053f9e0(self + 0x24) && fn_0053f970(self))
        return true;
    return false;
}
