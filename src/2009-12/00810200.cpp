// from server: 100% by auto
// roc 2009-12 00810200  unit: CXTPImageManager  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00810200
//
// 00810200  8b442418             mov eax, dword ptr [esp + 0x18]
// 00810204  8b542414             mov edx, dword ptr [esp + 0x14]
// 00810208  50                   push eax
// 00810209  8b442414             mov eax, dword ptr [esp + 0x14]
// 0081020d  52                   push edx
// 0081020e  8b542414             mov edx, dword ptr [esp + 0x14]
// 00810212  50                   push eax
// 00810213  8b442414             mov eax, dword ptr [esp + 0x14]
// 00810217  52                   push edx
// 00810218  0fb7542414           movzx edx, word ptr [esp + 0x14]
// 0081021d  50                   push eax
// 0081021e  52                   push edx
// 0081021f  e8acf7ffff           call 0x80f9d0
// 00810224  c21800               ret 0x18
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ?SetIcons@CXTPImageManager@@QAEHIPAIHVCSize@@W4XTPImageState@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp
