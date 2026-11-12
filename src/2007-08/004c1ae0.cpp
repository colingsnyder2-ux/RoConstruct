// from server: 100% by colin
// roc 2007-08 004c1ae0  unit: RakPeer  size: 106 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004c1ae0
//
// 004c1ae0  80b98000000000       cmp byte ptr [ecx + 0x80], 0
// 004c1ae7  7447                 je 0x4c1b30
// 004c1ae9  8d8114010000         lea eax, [ecx + 0x114]
// 004c1aef  50                   push eax
// 004c1af0  8d9104010000         lea edx, [ecx + 0x104]
// 004c1af6  52                   push edx
// 004c1af7  8d81e4000000         lea eax, [ecx + 0xe4]
// 004c1afd  50                   push eax
// 004c1afe  8d91d4000000         lea edx, [ecx + 0xd4]
// 004c1b04  52                   push edx
// 004c1b05  8d8124010000         lea eax, [ecx + 0x124]
// 004c1b0b  50                   push eax
// 004c1b0c  8d91f4000000         lea edx, [ecx + 0xf4]
// 004c1b12  52                   push edx
// 004c1b13  8b542420             mov edx, dword ptr [esp + 0x20]
// 004c1b17  8d81c4000000         lea eax, [ecx + 0xc4]
// 004c1b1d  50                   push eax
// 004c1b1e  51                   push ecx
// 004c1b1f  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 004c1b23  51                   push ecx
// 004c1b24  52                   push edx
// 004c1b25  e896eeffff           call 0x4c09c0
// 004c1b2a  83c428               add esp, 0x28
// 004c1b2d  c20800               ret 8
// 004c1b30  8b442408             mov eax, dword ptr [esp + 8]
// 004c1b34  50                   push eax
// 004c1b35  8b442408             mov eax, dword ptr [esp + 8]
// 004c1b39  8d5120               lea edx, [ecx + 0x20]
// 004c1b3c  52                   push edx
// 004c1b3d  51                   push ecx
// 004c1b3e  50                   push eax
// 004c1b3f  e8dcbbffff           call 0x4bd720
// 004c1b44  83c410               add esp, 0x10
// 004c1b47  c20800               ret 8
// copied from an identical function in another client (function ?encrypt@?$RSACrypt@$$BY07I@big@@QAEXAAY07I0@Z)

// from server: 100% by tester
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lang: cpp
// roc-lib: openrbx-raknet RakPeer.cpp