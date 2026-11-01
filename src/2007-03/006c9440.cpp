// from server: 100% by auto
// roc 2007-03 006c9440  unit: seg_006c0000  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006c9440
//
// 006c9440  56                   push esi
// 006c9441  8bf1                 mov esi, ecx
// 006c9443  8b06                 mov eax, dword ptr [esi]
// 006c9445  8b5020               mov edx, dword ptr [eax + 0x20]
// 006c9448  ffd2                 call edx
// 006c944a  85c0                 test eax, eax
// 006c944c  7414                 je 0x6c9462
// 006c944e  8b06                 mov eax, dword ptr [esi]
// 006c9450  8b5020               mov edx, dword ptr [eax + 0x20]
// 006c9453  6a00                 push 0
// 006c9455  6a00                 push 0
// 006c9457  8bce                 mov ecx, esi
// 006c9459  ffd2                 call edx
// 006c945b  50                   push eax
// 006c945c  ff1554ee7700         call dword ptr [0x77ee54]
// 006c9462  5e                   pop esi
// 006c9463  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneBase.cpp (function ?RedrawPane@CXTPDockingPaneBase@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneBase.cpp
