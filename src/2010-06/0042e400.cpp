// from server: 100% by auto
// roc 2010-06 0042e400  unit: CObjectBrowser  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0042e400
//
// 0042e400  8b442404             mov eax, dword ptr [esp + 4]
// 0042e404  50                   push eax
// 0042e405  e8ea9e3700           call 0x7a82f4
// 0042e40a  f7d8                 neg eax
// 0042e40c  1bc0                 sbb eax, eax
// 0042e40e  f7d8                 neg eax
// 0042e410  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTHexEdit.cpp (function ?PreCreateWindow@CXTHexEdit@@MAEHAAUtagCREATESTRUCTA@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTHexEdit.cpp
