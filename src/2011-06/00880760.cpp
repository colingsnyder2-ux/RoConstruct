// from server: 100% by auto
// roc 2011-06 00880760  unit: PAUHWND__::?$CArray  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00880760
//
// 00880760  56                   push esi
// 00880761  8bf1                 mov esi, ecx
// 00880763  837e1000             cmp dword ptr [esi + 0x10], 0
// 00880767  7e15                 jle 0x88077e
// 00880769  8b460c               mov eax, dword ptr [esi + 0xc]
// 0088076c  8b08                 mov ecx, dword ptr [eax]
// 0088076e  8b11                 mov edx, dword ptr [ecx]
// 00880770  8b8288010000         mov eax, dword ptr [edx + 0x188]
// 00880776  ffd0                 call eax
// 00880778  837e1000             cmp dword ptr [esi + 0x10], 0
// 0088077c  7feb                 jg 0x880769
// 0088077e  5e                   pop esi
// 0088077f  c3                   ret 
// library xtp-15.2.1-shared-mfc/Source\CommandBars\XTPMouseManager.cpp (function ?SendTrackLost@CXTPMouseManager@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/CommandBars/XTPMouseManager.cpp
