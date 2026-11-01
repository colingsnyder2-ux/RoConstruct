// from server: 100% by auto
// roc 2011-06 008f1390  unit: CXTCaptionTheme  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008f1390
//
// 008f1390  56                   push esi
// 008f1391  8bf1                 mov esi, ecx
// 008f1393  e8a8a2f7ff           call 0x86b640
// 008f1398  e84340f5ff           call 0x8453e0
// 008f139d  6a10                 push 0x10
// 008f139f  8bc8                 mov ecx, eax
// 008f13a1  e80a38f5ff           call 0x844bb0
// 008f13a6  894618               mov dword ptr [esi + 0x18], eax
// 008f13a9  e83240f5ff           call 0x8453e0
// 008f13ae  6a14                 push 0x14
// 008f13b0  8bc8                 mov ecx, eax
// 008f13b2  e8f937f5ff           call 0x844bb0
// 008f13b7  894624               mov dword ptr [esi + 0x24], eax
// 008f13ba  5e                   pop esi
// 008f13bb  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTCaptionTheme.cpp (function ?RefreshMetrics@CXTCaptionTheme@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaptionTheme.cpp
