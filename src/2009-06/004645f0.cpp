// from server: 100% by EspClaude
// roc 2009-06 004645f0  unit: CScriptEditor  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004645f0
//
// 004645f0  832d08b6a30001       sub dword ptr [0xa3b608], 1
// 004645f7  56                   push esi
// 004645f8  8bf1                 mov esi, ecx
// 004645fa  750c                 jne 0x464608
// 004645fc  a104b6a300           mov eax, dword ptr [0xa3b604]
// 00464601  50                   push eax
// 00464602  ff15b4e18900         call dword ptr [0x89e1b4]
// 00464608  8bce                 mov ecx, esi
// 0046460a  5e                   pop esi
// 0046460b  e924482b00           jmp 0x718e34
// copied from an identical function in another client (function ?fn_ROCX000079_00463980@CScriptEditor@ns_ROCX000079@@QAEXXZ)

namespace ns_ROCX000079 {
extern int libraryReferences;
extern void* libraryHandle;
extern "C" int (__stdcall* FreeLibrary)(void*);

struct CScriptEditor
{
    void cleanup();
    void fn_ROCX000079_00463980();
};

void CScriptEditor::fn_ROCX000079_00463980()
{
    if (--libraryReferences == 0)
        FreeLibrary(libraryHandle);
    cleanup();
}
}
