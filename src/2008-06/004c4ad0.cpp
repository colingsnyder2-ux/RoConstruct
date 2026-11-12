// from server: 100% by auto
// roc 2008-06 004c4ad0  unit: ProfiledRakPeer  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004c4ad0
//
// 004c4ad0  80b98000000000       cmp byte ptr [ecx + 0x80], 0
// 004c4ad7  744a                 je 0x4c4b23
// 004c4ad9  8d8114010000         lea eax, [ecx + 0x114]
// 004c4adf  50                   push eax
// 004c4ae0  8d9104010000         lea edx, [ecx + 0x104]
// 004c4ae6  52                   push edx
// 004c4ae7  8d81e4000000         lea eax, [ecx + 0xe4]
// 004c4aed  50                   push eax
// 004c4aee  8d91d4000000         lea edx, [ecx + 0xd4]
// 004c4af4  52                   push edx
// 004c4af5  8d8124010000         lea eax, [ecx + 0x124]
// 004c4afb  50                   push eax
// 004c4afc  8d91f4000000         lea edx, [ecx + 0xf4]
// 004c4b02  52                   push edx
// 004c4b03  8b542420             mov edx, dword ptr [esp + 0x20]
// 004c4b07  8d81c4000000         lea eax, [ecx + 0xc4]
// 004c4b0d  50                   push eax
// 004c4b0e  81c184000000         add ecx, 0x84
// 004c4b14  51                   push ecx
// 004c4b15  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 004c4b19  51                   push ecx
// 004c4b1a  52                   push edx
// 004c4b1b  e8a0e9ffff           call 0x4c34c0
// 004c4b20  83c428               add esp, 0x28
// 004c4b23  c20800               ret 8
// library openrbx-raknet/RakPeer.cpp (function ?decrypt@?$RSACrypt@$$BY07I@big@@QAEXAAY07I0@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
