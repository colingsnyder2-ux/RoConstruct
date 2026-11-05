// from server: 100% by auto
// roc 2010-06 007c8f70  unit: CXTPCommandBarKeyboardTip  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007c8f70
//
// 007c8f70  8b442404             mov eax, dword ptr [esp + 4]
// 007c8f74  894154               mov dword ptr [ecx + 0x54], eax
// 007c8f77  e864f8ffff           call 0x7c87e0
// 007c8f7c  8bc8                 mov ecx, eax
// 007c8f7e  e87d7affff           call 0x7c0a00
// 007c8f83  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?SetImageManager@CXTPCommandBars@@QAEXPAVCXTPImageManager@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCommandBars.cpp
