// from server: 100% by auto
// roc 2009-12 008ce000  unit: CXTPTabManagerItem  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008ce000
//
// 008ce000  8bc1                 mov eax, ecx
// 008ce002  8b4860               mov ecx, dword ptr [eax + 0x60]
// 008ce005  8b11                 mov edx, dword ptr [ecx]
// 008ce007  50                   push eax
// 008ce008  8b4214               mov eax, dword ptr [edx + 0x14]
// 008ce00b  ffd0                 call eax
// 008ce00d  c3                   ret 
// library xtp-15.2.1/Source\TabManager\XTPTabManager.cpp (function ?GetColor@CXTPTabManagerItem@@QAEKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabManager.cpp
