// from server: 100% by auto
// roc 2010-06 007fabf0  unit: CXTPControls  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007fabf0
//
// 007fabf0  8bc1                 mov eax, ecx
// 007fabf2  8b483c               mov ecx, dword ptr [eax + 0x3c]
// 007fabf5  85c9                 test ecx, ecx
// 007fabf7  7506                 jne 0x7fabff
// 007fabf9  b801000000           mov eax, 1
// 007fabfe  c3                   ret 
// 007fabff  50                   push eax
// 007fac00  e80bffffff           call 0x7fab10
// 007fac05  f7d8                 neg eax
// 007fac07  1bc0                 sbb eax, eax
// 007fac09  40                   inc eax
// 007fac0a  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPControls.cpp (function ?IsChanged@CXTPControls@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControls.cpp
