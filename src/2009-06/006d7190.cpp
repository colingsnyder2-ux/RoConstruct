// from server: 100% by auto
// roc 2009-06 006d7190  unit: RBX::RotatePJoint  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006d7190
//
// 006d7190  8b89d4000000         mov ecx, dword ptr [ecx + 0xd4]
// 006d7196  85c9                 test ecx, ecx
// 006d7198  7405                 je 0x6d719f
// 006d719a  e9917afdff           jmp 0x6aec30
// 006d719f  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\olesvr1.cpp (function ?ActivateDocObject@COleServerDoc@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/olesvr1.cpp
