// from server: 100% by auto
// roc 2009-06 007d5060  unit: CXTPDockingPaneMiniWnd  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007d5060
//
// 007d5060  8b542404             mov edx, dword ptr [esp + 4]
// 007d5064  8b4214               mov eax, dword ptr [edx + 0x14]
// 007d5067  3df1240000           cmp eax, 0x24f1
// 007d506c  7506                 jne 0x7d5074
// 007d506e  8b413c               mov eax, dword ptr [ecx + 0x3c]
// 007d5071  c20400               ret 4
// 007d5074  3df0240000           cmp eax, 0x24f0
// 007d5079  7515                 jne 0x7d5090
// 007d507b  8b4150               mov eax, dword ptr [ecx + 0x50]
// 007d507e  f7d8                 neg eax
// 007d5080  1bc0                 sbb eax, eax
// 007d5082  83e002               and eax, 2
// 007d5085  894220               mov dword ptr [edx + 0x20], eax
// 007d5088  a1f08ea200           mov eax, dword ptr [0xa28ef0]
// 007d508d  c20400               ret 4
// 007d5090  3df4240000           cmp eax, 0x24f4
// 007d5095  751f                 jne 0x7d50b6
// 007d5097  81c108ffffff         add ecx, 0xffffff08
// 007d509d  e8defeffff           call 0x7d4f80
// 007d50a2  85c0                 test eax, eax
// 007d50a4  740b                 je 0x7d50b1
// 007d50a6  8bc8                 mov ecx, eax
// 007d50a8  e883cafaff           call 0x781b30
// 007d50ad  a810                 test al, 0x10
// 007d50af  7505                 jne 0x7d50b6
// 007d50b1  33c0                 xor eax, eax
// 007d50b3  c20400               ret 4
// 007d50b6  b801000000           mov eax, 1
// 007d50bb  c20400               ret 4
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneMiniWnd.cpp (function ?IsCaptionButtonVisible@CXTPDockingPaneMiniWnd@@MAEHPAVCXTPDockingPaneCaptionButton@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneMiniWnd.cpp
