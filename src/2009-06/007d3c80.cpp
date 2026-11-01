// from server: 100% by auto
// roc 2009-06 007d3c80  unit: CXTPDockingPaneMiniWnd  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007d3c80
//
// 007d3c80  8d8108ffffff         lea eax, [ecx - 0xf8]
// 007d3c86  85c0                 test eax, eax
// 007d3c88  7501                 jne 0x7d3c8b
// 007d3c8a  c3                   ret 
// 007d3c8b  8b4020               mov eax, dword ptr [eax + 0x20]
// 007d3c8e  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneMiniWnd.cpp (function ?GetPaneHwnd@CXTPDockingPaneMiniWnd@@MBEPAUHWND__@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneMiniWnd.cpp
