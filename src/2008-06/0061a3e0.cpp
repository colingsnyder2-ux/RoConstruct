// from server: 100% by auto
// roc 2008-06 0061a3e0  unit: RBX::InletTool  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0061a3e0
//
// 0061a3e0  e8dbfcffff           call 0x61a0c0
// 0061a3e5  33c0                 xor eax, eax
// 0061a3e7  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\ctlppg.cpp (function ?OnInitDialog@COlePropertyPage@@UAEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ctlppg.cpp
