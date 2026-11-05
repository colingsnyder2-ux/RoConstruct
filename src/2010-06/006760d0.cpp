// from server: 100% by auto
// roc 2010-06 006760d0  unit: RBX::VHumanoid::?$EventDesc  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006760d0
//
// 006760d0  8b493c               mov ecx, dword ptr [ecx + 0x3c]
// 006760d3  85c9                 test ecx, ecx
// 006760d5  7405                 je 0x6760dc
// 006760d7  e974980d00           jmp 0x74f950
// 006760dc  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxpanecontainermanager.cpp (function ?RemoveNonValidPanes@CPaneContainerManager@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpanecontainermanager.cpp
