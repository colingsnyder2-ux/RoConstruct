// from server: 100% by auto
// roc 2009-12 008f05b0  unit: CXTPRibbonControlTab  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008f05b0
//
// 008f05b0  8b897cffffff         mov ecx, dword ptr [ecx - 0x84]
// 008f05b6  e8153ff1ff           call 0x8044d0
// 008f05bb  8bc8                 mov ecx, eax
// 008f05bd  e8ae55f2ff           call 0x815b70
// 008f05c2  33c9                 xor ecx, ecx
// 008f05c4  394804               cmp dword ptr [eax + 4], ecx
// 008f05c7  0f9fc1               setg cl
// 008f05ca  8bc1                 mov eax, ecx
// 008f05cc  c3                   ret 
// library xtp-15.2.1/Source\Ribbon\XTPRibbonControlTab.cpp (function ?IsMouseLocked@CXTPRibbonControlTab@@MBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Ribbon/XTPRibbonControlTab.cpp
