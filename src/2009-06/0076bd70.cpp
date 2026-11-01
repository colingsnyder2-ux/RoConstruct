// from server: 100% by auto
// roc 2009-06 0076bd70  unit: CXTPControls  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0076bd70
//
// 0076bd70  8bc1                 mov eax, ecx
// 0076bd72  8b483c               mov ecx, dword ptr [eax + 0x3c]
// 0076bd75  85c9                 test ecx, ecx
// 0076bd77  7506                 jne 0x76bd7f
// 0076bd79  b801000000           mov eax, 1
// 0076bd7e  c3                   ret 
// 0076bd7f  50                   push eax
// 0076bd80  e80bffffff           call 0x76bc90
// 0076bd85  f7d8                 neg eax
// 0076bd87  1bc0                 sbb eax, eax
// 0076bd89  40                   inc eax
// 0076bd8a  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPControls.cpp (function ?IsChanged@CXTPControls@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControls.cpp
