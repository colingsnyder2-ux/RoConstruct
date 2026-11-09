// from server: 100% by auto
// roc 2010-06 008a7030  unit: CXTPDockingPaneAutoHidePanel  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008a7030
//
// 008a7030  56                   push esi
// 008a7031  8b713c               mov esi, dword ptr [ecx + 0x3c]
// 008a7034  85f6                 test esi, esi
// 008a7036  7416                 je 0x8a704e
// 008a7038  8bc6                 mov eax, esi
// 008a703a  8b4808               mov ecx, dword ptr [eax + 8]
// 008a703d  8b01                 mov eax, dword ptr [ecx]
// 008a703f  8b5014               mov edx, dword ptr [eax + 0x14]
// 008a7042  8b36                 mov esi, dword ptr [esi]
// 008a7044  ffd2                 call edx
// 008a7046  85c0                 test eax, eax
// 008a7048  740b                 je 0x8a7055
// 008a704a  85f6                 test esi, esi
// 008a704c  75ea                 jne 0x8a7038
// 008a704e  b801000000           mov eax, 1
// 008a7053  5e                   pop esi
// 008a7054  c3                   ret 
// 008a7055  33c0                 xor eax, eax
// 008a7057  5e                   pop esi
// 008a7058  c3                   ret 
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneBaseContainer.cpp (function ?IsEmpty@CXTPDockingPaneBaseContainer@@MBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneBaseContainer.cpp
