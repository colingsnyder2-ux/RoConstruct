// from server: 100% by auto
// roc 2010-06 007b82c0  unit: CXTPDockingPaneAutoHidePanel  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007b82c0
//
// 007b82c0  56                   push esi
// 007b82c1  8bf1                 mov esi, ecx
// 007b82c3  837e2000             cmp dword ptr [esi + 0x20], 0
// 007b82c7  7407                 je 0x7b82d0
// 007b82c9  8b06                 mov eax, dword ptr [esi]
// 007b82cb  8b5068               mov edx, dword ptr [eax + 0x68]
// 007b82ce  ffd2                 call edx
// 007b82d0  8bce                 mov ecx, esi
// 007b82d2  5e                   pop esi
// 007b82d3  e9d2fefeff           jmp 0x7a81aa
// library xtp-13.2.1-shared-mfc/Source\DockingPane\XTPDockingPaneAutoHidePanel.cpp (function ?OnFinalRelease@CXTPDockingPaneAutoHidePanel@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/DockingPane/XTPDockingPaneAutoHidePanel.cpp
