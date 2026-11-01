// from server: 100% by auto
// roc 2007-03 00717410  unit: seg_00710000  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00717410
//
// 00717410  8b4120               mov eax, dword ptr [ecx + 0x20]
// 00717413  6a00                 push 0
// 00717415  6a00                 push 0
// 00717417  6855040000           push 0x455
// 0071741c  50                   push eax
// 0071741d  ff1550ee7700         call dword ptr [0x77ee50]
// 00717423  a801                 test al, 1
// 00717425  7417                 je 0x71743e
// 00717427  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0071742b  8a4109               mov al, byte ptr [ecx + 9]
// 0071742e  a808                 test al, 8
// 00717430  740c                 je 0x71743e
// 00717432  84c0                 test al, al
// 00717434  7808                 js 0x71743e
// 00717436  b801000000           mov eax, 1
// 0071743b  c20400               ret 4
// 0071743e  33c0                 xor eax, eax
// 00717440  c20400               ret 4
// library xtp-15.2.1/Source\SkinFramework\XTPSkinObjectToolBar.cpp (function ?HasSplitDropDown@CXTPSkinObjectToolBar@@IAEHPAU_TBBUTTON@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinObjectToolBar.cpp
