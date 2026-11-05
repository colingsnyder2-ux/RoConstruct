// from server: 100% by auto
// roc 2010-06 008821d0  unit: CXTPTabManagerItem  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008821d0
//
// 008821d0  8bc1                 mov eax, ecx
// 008821d2  8b4860               mov ecx, dword ptr [eax + 0x60]
// 008821d5  8b11                 mov edx, dword ptr [ecx]
// 008821d7  50                   push eax
// 008821d8  8b4214               mov eax, dword ptr [edx + 0x14]
// 008821db  ffd0                 call eax
// 008821dd  c3                   ret 
// library xtp-13.2.1/Source\TabManager\XTPTabManager.cpp (function ?GetColor@CXTPTabManagerItem@@QAEKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabManager.cpp
