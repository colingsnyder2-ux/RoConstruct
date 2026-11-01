// from server: 100% by auto
// roc 2007-03 007151f0  unit: seg_00710000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 007151f0
//
// 007151f0  56                   push esi
// 007151f1  8b713c               mov esi, dword ptr [ecx + 0x3c]
// 007151f4  85f6                 test esi, esi
// 007151f6  7416                 je 0x71520e
// 007151f8  8bc6                 mov eax, esi
// 007151fa  8b4808               mov ecx, dword ptr [eax + 8]
// 007151fd  8b01                 mov eax, dword ptr [ecx]
// 007151ff  8b5014               mov edx, dword ptr [eax + 0x14]
// 00715202  8b36                 mov esi, dword ptr [esi]
// 00715204  ffd2                 call edx
// 00715206  85c0                 test eax, eax
// 00715208  740b                 je 0x715215
// 0071520a  85f6                 test esi, esi
// 0071520c  75ea                 jne 0x7151f8
// 0071520e  b801000000           mov eax, 1
// 00715213  5e                   pop esi
// 00715214  c3                   ret 
// 00715215  33c0                 xor eax, eax
// 00715217  5e                   pop esi
// 00715218  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneBaseContainer.cpp (function ?IsEmpty@CXTPDockingPaneBaseContainer@@MBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneBaseContainer.cpp
