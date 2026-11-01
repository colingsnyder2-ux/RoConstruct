// from server: 100% by auto
// roc 2009-12 008b0760  unit: CXTPDockingPane  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008b0760
//
// 008b0760  56                   push esi
// 008b0761  8bf1                 mov esi, ecx
// 008b0763  8b06                 mov eax, dword ptr [esi]
// 008b0765  8b5020               mov edx, dword ptr [eax + 0x20]
// 008b0768  ffd2                 call edx
// 008b076a  85c0                 test eax, eax
// 008b076c  7414                 je 0x8b0782
// 008b076e  8b06                 mov eax, dword ptr [esi]
// 008b0770  8b5020               mov edx, dword ptr [eax + 0x20]
// 008b0773  6a00                 push 0
// 008b0775  6a00                 push 0
// 008b0777  8bce                 mov ecx, esi
// 008b0779  ffd2                 call edx
// 008b077b  50                   push eax
// 008b077c  ff15e8cb9800         call dword ptr [0x98cbe8]
// 008b0782  5e                   pop esi
// 008b0783  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneBase.cpp (function ?RedrawPane@CXTPDockingPaneBase@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneBase.cpp
