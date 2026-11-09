// from server: 100% by auto
// roc 2010-06 008a4780  unit: CXTPRibbonControlTab  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008a4780
//
// 008a4780  8b897cffffff         mov ecx, dword ptr [ecx - 0x84]
// 008a4786  e8453ef1ff           call 0x7b85d0
// 008a478b  8bc8                 mov ecx, eax
// 008a478d  e8ae54f2ff           call 0x7c9c40
// 008a4792  33c9                 xor ecx, ecx
// 008a4794  394804               cmp dword ptr [eax + 4], ecx
// 008a4797  0f9fc1               setg cl
// 008a479a  8bc1                 mov eax, ecx
// 008a479c  c3                   ret 
// library xtp-13.2.1/Source\Ribbon\XTPRibbonControlTab.cpp (function ?IsMouseLocked@CXTPRibbonControlTab@@MBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Ribbon/XTPRibbonControlTab.cpp
