// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// Import thunk: jmp through the IAT slot at 0x804cd8 (rgmain Ogre::MemoryDataStream::skipLine).
// INFERRED: no args are declared, so the tail call forwards ecx and the stack args untouched.
typedef unsigned int (__cdecl *SkipLineFn)();

extern "C" SkipLineFn __imp_Ogre_MemoryDataStream_skipLine; // IAT slot 0x00804cd8

extern "C" unsigned int fn_0069fc96()
{
    return __imp_Ogre_MemoryDataStream_skipLine();
}
