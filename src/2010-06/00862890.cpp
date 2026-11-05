// from server: 100% by auto
// roc 2010-06 00862890  unit: CXTPDockingPaneMiniWnd  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00862890
//
// 00862890  8d8108ffffff         lea eax, [ecx - 0xf8]
// 00862896  85c0                 test eax, eax
// 00862898  7501                 jne 0x86289b
// 0086289a  c3                   ret 
// 0086289b  8b4020               mov eax, dword ptr [eax + 0x20]
// 0086289e  c3                   ret 
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneMiniWnd.cpp (function ?GetPaneHwnd@CXTPDockingPaneMiniWnd@@MBEPAUHWND__@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneMiniWnd.cpp
