// from server: 100% by auto
// roc 2007-03 006e5590  unit: seg_006e0000  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006e5590
//
// 006e5590  8bc1                 mov eax, ecx
// 006e5592  8b4860               mov ecx, dword ptr [eax + 0x60]
// 006e5595  8b11                 mov edx, dword ptr [ecx]
// 006e5597  50                   push eax
// 006e5598  8b4214               mov eax, dword ptr [edx + 0x14]
// 006e559b  ffd0                 call eax
// 006e559d  c3                   ret 
// library xtp-15.2.1/Source\TabManager\XTPTabManager.cpp (function ?GetColor@CXTPTabManagerItem@@QAEKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabManager.cpp
