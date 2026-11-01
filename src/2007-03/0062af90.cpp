// from server: 100% by auto
// roc 2007-03 0062af90  unit: seg_00620000  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0062af90
//
// 0062af90  8b442418             mov eax, dword ptr [esp + 0x18]
// 0062af94  8b542414             mov edx, dword ptr [esp + 0x14]
// 0062af98  50                   push eax
// 0062af99  8b442414             mov eax, dword ptr [esp + 0x14]
// 0062af9d  52                   push edx
// 0062af9e  8b542414             mov edx, dword ptr [esp + 0x14]
// 0062afa2  50                   push eax
// 0062afa3  8b442414             mov eax, dword ptr [esp + 0x14]
// 0062afa7  52                   push edx
// 0062afa8  0fb7542414           movzx edx, word ptr [esp + 0x14]
// 0062afad  50                   push eax
// 0062afae  52                   push edx
// 0062afaf  e80cf8ffff           call 0x62a7c0
// 0062afb4  c21800               ret 0x18
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ?SetIcons@CXTPImageManager@@QAEHIPAIHVCSize@@W4XTPImageState@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp
