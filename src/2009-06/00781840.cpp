// from server: 100% by auto
// roc 2009-06 00781840  unit: CXTPDockingPane  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00781840
//
// 00781840  8b4110               mov eax, dword ptr [ecx + 0x10]
// 00781843  85c0                 test eax, eax
// 00781845  7404                 je 0x78184b
// 00781847  8b4014               mov eax, dword ptr [eax + 0x14]
// 0078184a  c3                   ret 
// 0078184b  33c0                 xor eax, eax
// 0078184d  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPane.cpp (function ?GetDockingSite@CXTPDockingPane@@UBEPAVCWnd@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPane.cpp
