// from server: 100% by auto
// roc 2009-12 008ae6e0  unit: CXTPDockingPaneMiniWnd  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008ae6e0
//
// 008ae6e0  56                   push esi
// 008ae6e1  8bf1                 mov esi, ecx
// 008ae6e3  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 008ae6e6  8d8614010000         lea eax, [esi + 0x114]
// 008ae6ec  50                   push eax
// 008ae6ed  51                   push ecx
// 008ae6ee  ff1570cc9800         call dword ptr [0x98cc70]
// 008ae6f4  8bce                 mov ecx, esi
// 008ae6f6  5e                   pop esi
// 008ae6f7  e9205cf4ff           jmp 0x7f431c
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneMiniWnd.cpp (function ?OnDestroy@CXTPDockingPaneMiniWnd@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneMiniWnd.cpp
