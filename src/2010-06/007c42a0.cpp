// from server: 100% by auto
// roc 2010-06 007c42a0  unit: CXTPImageManager  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007c42a0
//
// 007c42a0  8b442418             mov eax, dword ptr [esp + 0x18]
// 007c42a4  8b542414             mov edx, dword ptr [esp + 0x14]
// 007c42a8  50                   push eax
// 007c42a9  8b442414             mov eax, dword ptr [esp + 0x14]
// 007c42ad  52                   push edx
// 007c42ae  8b542414             mov edx, dword ptr [esp + 0x14]
// 007c42b2  50                   push eax
// 007c42b3  8b442414             mov eax, dword ptr [esp + 0x14]
// 007c42b7  52                   push edx
// 007c42b8  0fb7542414           movzx edx, word ptr [esp + 0x14]
// 007c42bd  50                   push eax
// 007c42be  52                   push edx
// 007c42bf  e8acf7ffff           call 0x7c3a70
// 007c42c4  c21800               ret 0x18
// library xtp-13.2.1/Source\Common\XTPImageManager.cpp (function ?SetIcons@CXTPImageManager@@QAEHIPAIHVCSize@@W4XTPImageState@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPImageManager.cpp
