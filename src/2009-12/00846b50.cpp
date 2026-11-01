// from server: 100% by auto
// roc 2009-12 00846b50  unit: CXTPControls  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00846b50
//
// 00846b50  8bc1                 mov eax, ecx
// 00846b52  8b483c               mov ecx, dword ptr [eax + 0x3c]
// 00846b55  85c9                 test ecx, ecx
// 00846b57  7506                 jne 0x846b5f
// 00846b59  b801000000           mov eax, 1
// 00846b5e  c3                   ret 
// 00846b5f  50                   push eax
// 00846b60  e80bffffff           call 0x846a70
// 00846b65  f7d8                 neg eax
// 00846b67  1bc0                 sbb eax, eax
// 00846b69  40                   inc eax
// 00846b6a  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPControls.cpp (function ?IsChanged@CXTPControls@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControls.cpp
