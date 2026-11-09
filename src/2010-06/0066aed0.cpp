// from server: 100% by auto
// roc 2010-06 0066aed0  unit: RBX::Teams  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0066aed0
//
// 0066aed0  8b442404             mov eax, dword ptr [esp + 4]
// 0066aed4  50                   push eax
// 0066aed5  e816ffffff           call 0x66adf0
// 0066aeda  f7d8                 neg eax
// 0066aedc  1bc0                 sbb eax, eax
// 0066aede  f7d8                 neg eax
// 0066aee0  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTHexEdit.cpp (function ?PreCreateWindow@CXTHexEdit@@MAEHAAUtagCREATESTRUCTA@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTHexEdit.cpp
