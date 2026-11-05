// from server: 100% by auto
// roc 2010-06 0089a830  unit: CXTCaptionButton  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0089a830
//
// 0089a830  8b442414             mov eax, dword ptr [esp + 0x14]
// 0089a834  0fb7542410           movzx edx, word ptr [esp + 0x10]
// 0089a839  50                   push eax
// 0089a83a  0fb7442410           movzx eax, word ptr [esp + 0x10]
// 0089a83f  52                   push edx
// 0089a840  8b542410             mov edx, dword ptr [esp + 0x10]
// 0089a844  50                   push eax
// 0089a845  8b442410             mov eax, dword ptr [esp + 0x10]
// 0089a849  52                   push edx
// 0089a84a  50                   push eax
// 0089a84b  e870feffff           call 0x89a6c0
// 0089a850  c21400               ret 0x14
// library xtp-13.2.1/Source\Controls\XTButton.cpp (function ?SetIcon@CXTButton@@UAEHVCSize@@IIH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTButton.cpp
