// from server: 100% by auto
// roc 2007-03 006e58e0  unit: seg_006e0000  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006e58e0
//
// 006e58e0  8b4104               mov eax, dword ptr [ecx + 4]
// 006e58e3  85c0                 test eax, eax
// 006e58e5  7404                 je 0x6e58eb
// 006e58e7  8b402c               mov eax, dword ptr [eax + 0x2c]
// 006e58ea  c3                   ret 
// 006e58eb  83c8ff               or eax, 0xffffffff
// 006e58ee  c3                   ret 
// library xtp-15.2.1/Source\TabManager\XTPTabManager.cpp (function ?GetCurSel@CXTPTabManager@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabManager.cpp
