// from server: 100% by auto
// roc 2009-06 00814a50  unit: CXTPRibbonControlTab  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00814a50
//
// 00814a50  8b897cffffff         mov ecx, dword ptr [ecx - 0x84]
// 00814a56  e83589f1ff           call 0x72d390
// 00814a5b  8bc8                 mov ecx, eax
// 00814a5d  e85e64f1ff           call 0x72aec0
// 00814a62  33c9                 xor ecx, ecx
// 00814a64  394804               cmp dword ptr [eax + 4], ecx
// 00814a67  0f9fc1               setg cl
// 00814a6a  8bc1                 mov eax, ecx
// 00814a6c  c3                   ret 
// library xtp-15.2.1/Source\Ribbon\XTPRibbonControlTab.cpp (function ?IsMouseLocked@CXTPRibbonControlTab@@MBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Ribbon/XTPRibbonControlTab.cpp
