// from server: 100% by auto
// roc 2007-03 00715f70  unit: seg_00710000  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00715f70
//
// 00715f70  8b4120               mov eax, dword ptr [ecx + 0x20]
// 00715f73  6a00                 push 0
// 00715f75  6a00                 push 0
// 00715f77  50                   push eax
// 00715f78  ff1554ee7700         call dword ptr [0x77ee54]
// 00715f7e  c3                   ret 
// library xtp-15.2.1/Source\Controls\Deprecated\XTButton.cpp (function ?OnInvalidate@CXTButton@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTButton.cpp
