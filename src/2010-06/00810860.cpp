// from server: 100% by auto
// roc 2010-06 00810860  unit: CXTPDockingPane  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00810860
//
// 00810860  8b4110               mov eax, dword ptr [ecx + 0x10]
// 00810863  85c0                 test eax, eax
// 00810865  7404                 je 0x81086b
// 00810867  8b4014               mov eax, dword ptr [eax + 0x14]
// 0081086a  c3                   ret 
// 0081086b  33c0                 xor eax, eax
// 0081086d  c3                   ret 
// library xtp-13.2.1/Source\DockingPane\XTPDockingPane.cpp (function ?GetDockingSite@CXTPDockingPane@@UBEPAVCWnd@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPane.cpp
