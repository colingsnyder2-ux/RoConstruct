// from server: 100% by auto
// roc 2009-06 007d3b80  unit: CXTPDockingPaneMiniWnd  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007d3b80
//
// 007d3b80  56                   push esi
// 007d3b81  8bf1                 mov esi, ecx
// 007d3b83  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 007d3b86  8d8614010000         lea eax, [esi + 0x114]
// 007d3b8c  50                   push eax
// 007d3b8d  51                   push ecx
// 007d3b8e  ff15f4ed8900         call dword ptr [0x89edf4]
// 007d3b94  8bce                 mov ecx, esi
// 007d3b96  5e                   pop esi
// 007d3b97  e95259f4ff           jmp 0x7194ee
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneMiniWnd.cpp (function ?OnDestroy@CXTPDockingPaneMiniWnd@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneMiniWnd.cpp
