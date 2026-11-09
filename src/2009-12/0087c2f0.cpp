// from server: 100% by auto
// roc 2009-12 0087c2f0  unit: XTPPaintThemes::CXTPDefaultTheme  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0087c2f0
//
// 0087c2f0  56                   push esi
// 0087c2f1  8bf1                 mov esi, ecx
// 0087c2f3  e8c813f8ff           call 0x7fd6c0
// 0087c2f8  6a02                 push 2
// 0087c2fa  8bce                 mov ecx, esi
// 0087c2fc  e83f13f8ff           call 0x7fd640
// 0087c301  6a09                 push 9
// 0087c303  8bce                 mov ecx, esi
// 0087c305  89464c               mov dword ptr [esi + 0x4c], eax
// 0087c308  e83313f8ff           call 0x7fd640
// 0087c30d  894658               mov dword ptr [esi + 0x58], eax
// 0087c310  5e                   pop esi
// 0087c311  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPDefaultTheme.cpp (function ?RefreshMetrics@CXTPDefaultTheme@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPDefaultTheme.cpp
