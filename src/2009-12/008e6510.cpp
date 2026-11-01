// from server: 100% by auto
// roc 2009-12 008e6510  unit: CXTCaptionButton  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008e6510
//
// 008e6510  8b442414             mov eax, dword ptr [esp + 0x14]
// 008e6514  0fb7542410           movzx edx, word ptr [esp + 0x10]
// 008e6519  50                   push eax
// 008e651a  0fb7442410           movzx eax, word ptr [esp + 0x10]
// 008e651f  52                   push edx
// 008e6520  8b542410             mov edx, dword ptr [esp + 0x10]
// 008e6524  50                   push eax
// 008e6525  8b442410             mov eax, dword ptr [esp + 0x10]
// 008e6529  52                   push edx
// 008e652a  50                   push eax
// 008e652b  e870feffff           call 0x8e63a0
// 008e6530  c21400               ret 0x14
// library xtp-15.2.1/Source\Controls\Button\XTPButton.cpp (function ?SetIcon@CXTPButton@@UAEHVCSize@@IIH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Button/XTPButton.cpp
