// from server: 100% by auto
// roc 2009-12 00701090  unit: RBX::TimerService  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00701090
//
// 00701090  8b493c               mov ecx, dword ptr [ecx + 0x3c]
// 00701093  85c9                 test ecx, ecx
// 00701095  7405                 je 0x70109c
// 00701097  e9141f0b00           jmp 0x7b2fb0
// 0070109c  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxpanecontainermanager.cpp (function ?RemoveNonValidPanes@CPaneContainerManager@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpanecontainermanager.cpp
