// from server: 100% by auto
// roc 2009-12 008ae7c0  unit: CXTPDockingPaneMiniWnd  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008ae7c0
//
// 008ae7c0  8d8108ffffff         lea eax, [ecx - 0xf8]
// 008ae7c6  85c0                 test eax, eax
// 008ae7c8  7501                 jne 0x8ae7cb
// 008ae7ca  c3                   ret 
// 008ae7cb  8b4020               mov eax, dword ptr [eax + 0x20]
// 008ae7ce  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneMiniWnd.cpp (function ?GetPaneHwnd@CXTPDockingPaneMiniWnd@@MBEPAUHWND__@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneMiniWnd.cpp
