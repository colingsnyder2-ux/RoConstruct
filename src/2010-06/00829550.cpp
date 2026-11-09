// from server: 100% by auto
// roc 2010-06 00829550  unit: XTPPaintThemes::CXTPDefaultTheme  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00829550
//
// 00829550  56                   push esi
// 00829551  8bf1                 mov esi, ecx
// 00829553  e8383cf8ff           call 0x7ad190
// 00829558  6a02                 push 2
// 0082955a  8bce                 mov ecx, esi
// 0082955c  e8af3bf8ff           call 0x7ad110
// 00829561  6a09                 push 9
// 00829563  8bce                 mov ecx, esi
// 00829565  89464c               mov dword ptr [esi + 0x4c], eax
// 00829568  e8a33bf8ff           call 0x7ad110
// 0082956d  894658               mov dword ptr [esi + 0x58], eax
// 00829570  5e                   pop esi
// 00829571  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPDefaultTheme.cpp (function ?RefreshMetrics@CXTPDefaultTheme@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPDefaultTheme.cpp
