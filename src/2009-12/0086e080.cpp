// from server: 100% by auto
// roc 2009-12 0086e080  unit: CXTPReportColumns  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0086e080
//
// 0086e080  56                   push esi
// 0086e081  8bf1                 mov esi, ecx
// 0086e083  803e00               cmp byte ptr [esi], 0
// 0086e086  740e                 je 0x86e096
// 0086e088  e8915af8ff           call 0x7f3b1e
// 0086e08d  8b4e04               mov ecx, dword ptr [esi + 4]
// 0086e090  89480c               mov dword ptr [eax + 0xc], ecx
// 0086e093  c60600               mov byte ptr [esi], 0
// 0086e096  5e                   pop esi
// 0086e097  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPResourceManager.cpp (function ?Undo@CManageState@CXTPResourceManager@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPResourceManager.cpp
