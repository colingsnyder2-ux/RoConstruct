// from server: 100% by auto
// roc 2010-06 0075cc70  unit: RBX::RotatePJoint  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0075cc70
//
// 0075cc70  8b89d4000000         mov ecx, dword ptr [ecx + 0xd4]
// 0075cc76  85c9                 test ecx, ecx
// 0075cc78  7405                 je 0x75cc7f
// 0075cc7a  e971edfeff           jmp 0x74b9f0
// 0075cc7f  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\olesvr1.cpp (function ?ActivateDocObject@COleServerDoc@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/olesvr1.cpp
