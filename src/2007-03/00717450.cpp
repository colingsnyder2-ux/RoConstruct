// from server: 100% by auto
// roc 2007-03 00717450  unit: seg_00710000  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00717450
//
// 00717450  8b4120               mov eax, dword ptr [ecx + 0x20]
// 00717453  6a00                 push 0
// 00717455  6a00                 push 0
// 00717457  6855040000           push 0x455
// 0071745c  50                   push eax
// 0071745d  ff1550ee7700         call dword ptr [0x77ee50]
// 00717463  a801                 test al, 1
// 00717465  8b442404             mov eax, dword ptr [esp + 4]
// 00717469  7406                 je 0x717471
// 0071746b  f6400908             test byte ptr [eax + 9], 8
// 0071746f  750b                 jne 0x71747c
// 00717471  f6400980             test byte ptr [eax + 9], 0x80
// 00717475  7505                 jne 0x71747c
// 00717477  33c0                 xor eax, eax
// 00717479  c20400               ret 4
// 0071747c  b801000000           mov eax, 1
// 00717481  c20400               ret 4
// library xtp-15.2.1/Source\SkinFramework\XTPSkinObjectToolBar.cpp (function ?HasDropDownArrow@CXTPSkinObjectToolBar@@IAEHPAU_TBBUTTON@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinObjectToolBar.cpp
