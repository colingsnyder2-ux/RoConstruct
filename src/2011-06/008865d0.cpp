// from server: 100% by auto
// roc 2011-06 008865d0  unit: XTPPaintThemes::CXTPDefaultTheme  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008865d0
//
// 008865d0  56                   push esi
// 008865d1  8bf1                 mov esi, ecx
// 008865d3  e85890f8ff           call 0x80f630
// 008865d8  6a02                 push 2
// 008865da  8bce                 mov ecx, esi
// 008865dc  e8cf8ff8ff           call 0x80f5b0
// 008865e1  6a09                 push 9
// 008865e3  8bce                 mov ecx, esi
// 008865e5  89464c               mov dword ptr [esi + 0x4c], eax
// 008865e8  e8c38ff8ff           call 0x80f5b0
// 008865ed  894658               mov dword ptr [esi + 0x58], eax
// 008865f0  5e                   pop esi
// 008865f1  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPDefaultTheme.cpp (function ?RefreshMetrics@CXTPDefaultTheme@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPDefaultTheme.cpp
