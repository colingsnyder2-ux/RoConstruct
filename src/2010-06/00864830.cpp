// from server: 100% by auto
// roc 2010-06 00864830  unit: CXTPDockingPane  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00864830
//
// 00864830  56                   push esi
// 00864831  8bf1                 mov esi, ecx
// 00864833  8b06                 mov eax, dword ptr [esi]
// 00864835  8b5020               mov edx, dword ptr [eax + 0x20]
// 00864838  ffd2                 call edx
// 0086483a  85c0                 test eax, eax
// 0086483c  7414                 je 0x864852
// 0086483e  8b06                 mov eax, dword ptr [esi]
// 00864840  8b5020               mov edx, dword ptr [eax + 0x20]
// 00864843  6a00                 push 0
// 00864845  6a00                 push 0
// 00864847  8bce                 mov ecx, esi
// 00864849  ffd2                 call edx
// 0086484b  50                   push eax
// 0086484c  ff1578ba9e00         call dword ptr [0x9eba78]
// 00864852  5e                   pop esi
// 00864853  c3                   ret 
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneBase.cpp (function ?RedrawPane@CXTPDockingPaneBase@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneBase.cpp
