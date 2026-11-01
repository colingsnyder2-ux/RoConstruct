// from server: 100% by auto
// roc 2009-06 00739110  unit: CXTPImageManager  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00739110
//
// 00739110  8b442418             mov eax, dword ptr [esp + 0x18]
// 00739114  8b542414             mov edx, dword ptr [esp + 0x14]
// 00739118  50                   push eax
// 00739119  8b442414             mov eax, dword ptr [esp + 0x14]
// 0073911d  52                   push edx
// 0073911e  8b542414             mov edx, dword ptr [esp + 0x14]
// 00739122  50                   push eax
// 00739123  8b442414             mov eax, dword ptr [esp + 0x14]
// 00739127  52                   push edx
// 00739128  0fb7542414           movzx edx, word ptr [esp + 0x14]
// 0073912d  50                   push eax
// 0073912e  52                   push edx
// 0073912f  e8acf7ffff           call 0x7388e0
// 00739134  c21800               ret 0x18
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ?SetIcons@CXTPImageManager@@QAEHIPAIHVCSize@@W4XTPImageState@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp
