// from server: 100% by auto
// roc 2010-06 00823130  unit: PAVCXTPCommandBar::?$CArray  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00823130
//
// 00823130  56                   push esi
// 00823131  8bf1                 mov esi, ecx
// 00823133  837e1000             cmp dword ptr [esi + 0x10], 0
// 00823137  7e15                 jle 0x82314e
// 00823139  8b460c               mov eax, dword ptr [esi + 0xc]
// 0082313c  8b08                 mov ecx, dword ptr [eax]
// 0082313e  8b11                 mov edx, dword ptr [ecx]
// 00823140  8b8288010000         mov eax, dword ptr [edx + 0x188]
// 00823146  ffd0                 call eax
// 00823148  837e1000             cmp dword ptr [esi + 0x10], 0
// 0082314c  7feb                 jg 0x823139
// 0082314e  5e                   pop esi
// 0082314f  c3                   ret 
// library xtp-13.2.1-shared-mfc/Source\CommandBars\XTPMouseManager.cpp (function ?SendTrackLost@CXTPMouseManager@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/CommandBars/XTPMouseManager.cpp
