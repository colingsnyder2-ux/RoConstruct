// from server: 100% by Xemicl
// roc 2012-06 004a0460  unit: CScriptEditor  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004a0460
//
// 004a0460  832d64a9e10001       sub dword ptr [0xe1a964], 1
// 004a0467  56                   push esi
// 004a0468  8bf1                 mov esi, ecx
// 004a046a  750c                 jne 0x4a0478
// 004a046c  a160a9e100           mov eax, dword ptr [0xe1a960]
// 004a0471  50                   push eax
// 004a0472  ff158c21b200         call dword ptr [0xb2218c]
// 004a0478  8bce                 mov ecx, esi
// 004a047a  5e                   pop esi
// 004a047b  e990204e00           jmp 0x982510
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