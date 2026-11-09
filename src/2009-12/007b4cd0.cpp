// from server: 100% by auto
// roc 2009-12 007b4cd0  unit: RBX::RotatePJoint  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007b4cd0
//
// 007b4cd0  8b89d4000000         mov ecx, dword ptr [ecx + 0xd4]
// 007b4cd6  85c9                 test ecx, ecx
// 007b4cd8  7405                 je 0x7b4cdf
// 007b4cda  e91164ffff           jmp 0x7ab0f0
// 007b4cdf  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\olesvr1.cpp (function ?ActivateDocObject@COleServerDoc@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/olesvr1.cpp
