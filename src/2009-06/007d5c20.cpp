// from server: 100% by auto
// roc 2009-06 007d5c20  unit: CXTPDockingPane  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007d5c20
//
// 007d5c20  56                   push esi
// 007d5c21  8bf1                 mov esi, ecx
// 007d5c23  8b06                 mov eax, dword ptr [esi]
// 007d5c25  8b5020               mov edx, dword ptr [eax + 0x20]
// 007d5c28  ffd2                 call edx
// 007d5c2a  85c0                 test eax, eax
// 007d5c2c  7414                 je 0x7d5c42
// 007d5c2e  8b06                 mov eax, dword ptr [esi]
// 007d5c30  8b5020               mov edx, dword ptr [eax + 0x20]
// 007d5c33  6a00                 push 0
// 007d5c35  6a00                 push 0
// 007d5c37  8bce                 mov ecx, esi
// 007d5c39  ffd2                 call edx
// 007d5c3b  50                   push eax
// 007d5c3c  ff157cee8900         call dword ptr [0x89ee7c]
// 007d5c42  5e                   pop esi
// 007d5c43  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneBase.cpp (function ?RedrawPane@CXTPDockingPaneBase@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneBase.cpp
