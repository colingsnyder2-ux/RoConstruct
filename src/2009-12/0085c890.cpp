// from server: 100% by auto
// roc 2009-12 0085c890  unit: CXTPDockingPane  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0085c890
//
// 0085c890  8b4110               mov eax, dword ptr [ecx + 0x10]
// 0085c893  85c0                 test eax, eax
// 0085c895  7404                 je 0x85c89b
// 0085c897  8b4014               mov eax, dword ptr [eax + 0x14]
// 0085c89a  c3                   ret 
// 0085c89b  33c0                 xor eax, eax
// 0085c89d  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPane.cpp (function ?GetDockingSite@CXTPDockingPane@@UBEPAVCWnd@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPane.cpp
