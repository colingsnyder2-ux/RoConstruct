// from server: 100% by auto
// roc 2007-03 006a39b0  unit: seg_006a0000  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006a39b0
//
// 006a39b0  56                   push esi
// 006a39b1  8bf1                 mov esi, ecx
// 006a39b3  e858e8f8ff           call 0x632210
// 006a39b8  6a02                 push 2
// 006a39ba  8bce                 mov ecx, esi
// 006a39bc  e8dfe7f8ff           call 0x6321a0
// 006a39c1  6a09                 push 9
// 006a39c3  8bce                 mov ecx, esi
// 006a39c5  89464c               mov dword ptr [esi + 0x4c], eax
// 006a39c8  e8d3e7f8ff           call 0x6321a0
// 006a39cd  894658               mov dword ptr [esi + 0x58], eax
// 006a39d0  5e                   pop esi
// 006a39d1  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPDefaultTheme.cpp (function ?RefreshMetrics@CXTPDefaultTheme@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPDefaultTheme.cpp
