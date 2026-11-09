// from server: 100% by auto
// roc 2009-06 007a13b0  unit: XTPPaintThemes::CXTPDefaultTheme  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007a13b0
//
// 007a13b0  56                   push esi
// 007a13b1  8bf1                 mov esi, ecx
// 007a13b3  e84814f8ff           call 0x722800
// 007a13b8  6a02                 push 2
// 007a13ba  8bce                 mov ecx, esi
// 007a13bc  e8bf13f8ff           call 0x722780
// 007a13c1  6a09                 push 9
// 007a13c3  8bce                 mov ecx, esi
// 007a13c5  89464c               mov dword ptr [esi + 0x4c], eax
// 007a13c8  e8b313f8ff           call 0x722780
// 007a13cd  894658               mov dword ptr [esi + 0x58], eax
// 007a13d0  5e                   pop esi
// 007a13d1  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPDefaultTheme.cpp (function ?RefreshMetrics@CXTPDefaultTheme@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPDefaultTheme.cpp
