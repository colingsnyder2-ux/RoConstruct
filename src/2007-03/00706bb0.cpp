// from server: 100% by auto
// roc 2007-03 00706bb0  unit: seg_00700000  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00706bb0
//
// 00706bb0  8b442414             mov eax, dword ptr [esp + 0x14]
// 00706bb4  0fb7542410           movzx edx, word ptr [esp + 0x10]
// 00706bb9  50                   push eax
// 00706bba  0fb7442410           movzx eax, word ptr [esp + 0x10]
// 00706bbf  52                   push edx
// 00706bc0  8b542410             mov edx, dword ptr [esp + 0x10]
// 00706bc4  50                   push eax
// 00706bc5  8b442410             mov eax, dword ptr [esp + 0x10]
// 00706bc9  52                   push edx
// 00706bca  50                   push eax
// 00706bcb  e890feffff           call 0x706a60
// 00706bd0  c21400               ret 0x14
// library xtp-15.2.1/Source\Controls\Button\XTPButton.cpp (function ?SetIcon@CXTPButton@@UAEHVCSize@@IIH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Button/XTPButton.cpp
