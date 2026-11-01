// from server: 100% by auto
// roc 2009-12 0083b890  unit: CXTPToolBar::CControlButtonExpand  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0083b890
//
// 0083b890  8b4108               mov eax, dword ptr [ecx + 8]
// 0083b893  85c0                 test eax, eax
// 0083b895  7501                 jne 0x83b898
// 0083b897  c3                   ret 
// 0083b898  56                   push esi
// 0083b899  6854839f00           push 0x9f8354
// 0083b89e  8d7110               lea esi, [ecx + 0x10]
// 0083b8a1  50                   push eax
// 0083b8a2  c70614000000         mov dword ptr [esi], 0x14
// 0083b8a8  ff1520b29800         call dword ptr [0x98b220]
// 0083b8ae  85c0                 test eax, eax
// 0083b8b0  740b                 je 0x83b8bd
// 0083b8b2  56                   push esi
// 0083b8b3  ffd0                 call eax
// 0083b8b5  f7d8                 neg eax
// 0083b8b7  1bc0                 sbb eax, eax
// 0083b8b9  f7d8                 neg eax
// 0083b8bb  5e                   pop esi
// 0083b8bc  c3                   ret 
// 0083b8bd  33c0                 xor eax, eax
// 0083b8bf  5e                   pop esi
// 0083b8c0  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?GetVersionInfo@CXTPModuleHandle@@AAEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
