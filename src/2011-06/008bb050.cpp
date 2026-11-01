// from server: 100% by auto
// roc 2011-06 008bb050  unit: CXTPDockingPaneAutoHidePanel  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008bb050
//
// 008bb050  56                   push esi
// 008bb051  8bf1                 mov esi, ecx
// 008bb053  837e2000             cmp dword ptr [esi + 0x20], 0
// 008bb057  7407                 je 0x8bb060
// 008bb059  8b06                 mov eax, dword ptr [esi]
// 008bb05b  8b5068               mov edx, dword ptr [eax + 0x68]
// 008bb05e  ffd2                 call edx
// 008bb060  8bce                 mov ecx, esi
// 008bb062  5e                   pop esi
// 008bb063  e900f8f4ff           jmp 0x80a868
// library xtp-15.2.1-shared-mfc/Source\DockingPane\XTPDockingPaneAutoHidePanel.cpp (function ?OnFinalRelease@CXTPDockingPaneAutoHidePanel@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/DockingPane/XTPDockingPaneAutoHidePanel.cpp
