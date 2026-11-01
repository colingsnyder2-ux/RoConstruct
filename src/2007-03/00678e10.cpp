// from server: 100% by auto
// roc 2007-03 00678e10  unit: seg_00670000  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00678e10
//
// 00678e10  8b4110               mov eax, dword ptr [ecx + 0x10]
// 00678e13  85c0                 test eax, eax
// 00678e15  7404                 je 0x678e1b
// 00678e17  8b4014               mov eax, dword ptr [eax + 0x14]
// 00678e1a  c3                   ret 
// 00678e1b  33c0                 xor eax, eax
// 00678e1d  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPane.cpp (function ?GetDockingSite@CXTPDockingPane@@UBEPAVCWnd@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPane.cpp
