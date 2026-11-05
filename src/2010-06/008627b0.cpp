// from server: 100% by auto
// roc 2010-06 008627b0  unit: CXTPDockingPaneMiniWnd  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008627b0
//
// 008627b0  56                   push esi
// 008627b1  8bf1                 mov esi, ecx
// 008627b3  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 008627b6  8d8614010000         lea eax, [esi + 0x114]
// 008627bc  50                   push eax
// 008627bd  51                   push ecx
// 008627be  ff153cbc9e00         call dword ptr [0x9ebc3c]
// 008627c4  8bce                 mov ecx, esi
// 008627c6  5e                   pop esi
// 008627c7  e9905cf4ff           jmp 0x7a845c
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneMiniWnd.cpp (function ?OnDestroy@CXTPDockingPaneMiniWnd@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneMiniWnd.cpp
