// from server: 100% by auto
// roc 2009-06 007f3450  unit: CXTPTabManagerItem  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007f3450
//
// 007f3450  8bc1                 mov eax, ecx
// 007f3452  8b4860               mov ecx, dword ptr [eax + 0x60]
// 007f3455  8b11                 mov edx, dword ptr [ecx]
// 007f3457  50                   push eax
// 007f3458  8b4214               mov eax, dword ptr [edx + 0x14]
// 007f345b  ffd0                 call eax
// 007f345d  c3                   ret 
// library xtp-15.2.1/Source\TabManager\XTPTabManager.cpp (function ?GetColor@CXTPTabManagerItem@@QAEKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabManager.cpp
