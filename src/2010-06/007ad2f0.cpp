// from server: 100% by auto
// roc 2010-06 007ad2f0  unit: CXTPPaintManager  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007ad2f0
//
// 007ad2f0  8b0db054c200         mov ecx, dword ptr [0xc254b0]
// 007ad2f6  85c9                 test ecx, ecx
// 007ad2f8  7405                 je 0x7ad2ff
// 007ad2fa  e81dacffff           call 0x7a7f1c
// 007ad2ff  c705b054c20000000000 mov dword ptr [0xc254b0], 0
// 007ad309  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPPaintManager.cpp (function ?Done@CXTPPaintManager@@SAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPPaintManager.cpp
