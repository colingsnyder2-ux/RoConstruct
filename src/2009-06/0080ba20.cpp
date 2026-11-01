// from server: 100% by auto
// roc 2009-06 0080ba20  unit: CXTCaptionButton  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0080ba20
//
// 0080ba20  8b442414             mov eax, dword ptr [esp + 0x14]
// 0080ba24  0fb7542410           movzx edx, word ptr [esp + 0x10]
// 0080ba29  50                   push eax
// 0080ba2a  0fb7442410           movzx eax, word ptr [esp + 0x10]
// 0080ba2f  52                   push edx
// 0080ba30  8b542410             mov edx, dword ptr [esp + 0x10]
// 0080ba34  50                   push eax
// 0080ba35  8b442410             mov eax, dword ptr [esp + 0x10]
// 0080ba39  52                   push edx
// 0080ba3a  50                   push eax
// 0080ba3b  e870feffff           call 0x80b8b0
// 0080ba40  c21400               ret 0x14
// library xtp-15.2.1/Source\Controls\Button\XTPButton.cpp (function ?SetIcon@CXTPButton@@UAEHVCSize@@IIH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Button/XTPButton.cpp
