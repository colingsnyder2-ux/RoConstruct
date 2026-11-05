// from server: 100% by auto
// roc 2009-06 00675cb0  unit: RBX::TimerService  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00675cb0
//
// 00675cb0  8b493c               mov ecx, dword ptr [ecx + 0x3c]
// 00675cb3  85c9                 test ecx, ecx
// 00675cb5  7405                 je 0x675cbc
// 00675cb7  e914000600           jmp 0x6d5cd0
// 00675cbc  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxpanecontainermanager.cpp (function ?RemoveNonValidPanes@CPaneContainerManager@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpanecontainermanager.cpp
