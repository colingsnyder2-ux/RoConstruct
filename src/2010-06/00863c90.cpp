// from server: 100% by auto
// roc 2010-06 00863c90  unit: CXTPDockingPaneMiniWnd  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00863c90
//
// 00863c90  8b542404             mov edx, dword ptr [esp + 4]
// 00863c94  8b4214               mov eax, dword ptr [edx + 0x14]
// 00863c97  3df1240000           cmp eax, 0x24f1
// 00863c9c  7506                 jne 0x863ca4
// 00863c9e  8b413c               mov eax, dword ptr [ecx + 0x3c]
// 00863ca1  c20400               ret 4
// 00863ca4  3df0240000           cmp eax, 0x24f0
// 00863ca9  7515                 jne 0x863cc0
// 00863cab  8b4150               mov eax, dword ptr [ecx + 0x50]
// 00863cae  f7d8                 neg eax
// 00863cb0  1bc0                 sbb eax, eax
// 00863cb2  83e002               and eax, 2
// 00863cb5  894220               mov dword ptr [edx + 0x20], eax
// 00863cb8  a1789fbe00           mov eax, dword ptr [0xbe9f78]
// 00863cbd  c20400               ret 4
// 00863cc0  3df4240000           cmp eax, 0x24f4
// 00863cc5  751f                 jne 0x863ce6
// 00863cc7  81c108ffffff         add ecx, 0xffffff08
// 00863ccd  e8defeffff           call 0x863bb0
// 00863cd2  85c0                 test eax, eax
// 00863cd4  740b                 je 0x863ce1
// 00863cd6  8bc8                 mov ecx, eax
// 00863cd8  e873cefaff           call 0x810b50
// 00863cdd  a810                 test al, 0x10
// 00863cdf  7505                 jne 0x863ce6
// 00863ce1  33c0                 xor eax, eax
// 00863ce3  c20400               ret 4
// 00863ce6  b801000000           mov eax, 1
// 00863ceb  c20400               ret 4
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneMiniWnd.cpp (function ?IsCaptionButtonVisible@CXTPDockingPaneMiniWnd@@MAEHPAVCXTPDockingPaneCaptionButton@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneMiniWnd.cpp
