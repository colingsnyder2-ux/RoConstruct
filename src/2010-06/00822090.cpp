// from server: 100% by auto
// roc 2010-06 00822090  unit: CXTCaption  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00822090
//
// 00822090  56                   push esi
// 00822091  8bf1                 mov esi, ecx
// 00822093  803e00               cmp byte ptr [esi], 0
// 00822096  740e                 je 0x8220a6
// 00822098  e8c15bf8ff           call 0x7a7c5e
// 0082209d  8b4e04               mov ecx, dword ptr [esi + 4]
// 008220a0  89480c               mov dword ptr [eax + 0xc], ecx
// 008220a3  c60600               mov byte ptr [esi], 0
// 008220a6  5e                   pop esi
// 008220a7  c3                   ret 
// library xtp-13.2.1/Source\Common\XTPResourceManager.cpp (function ?Undo@CManageState@CXTPResourceManager@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPResourceManager.cpp
