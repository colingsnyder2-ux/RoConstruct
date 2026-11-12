// from server: 100% by auto
// roc 2008-06 004c1c20  unit: ProfiledRakPeer  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004c1c20
//
// 004c1c20  8b442408             mov eax, dword ptr [esp + 8]
// 004c1c24  8b542404             mov edx, dword ptr [esp + 4]
// 004c1c28  6a00                 push 0
// 004c1c2a  6a00                 push 0
// 004c1c2c  50                   push eax
// 004c1c2d  52                   push edx
// 004c1c2e  e8ade1ffff           call 0x4bfde0
// 004c1c33  85c0                 test eax, eax
// 004c1c35  7506                 jne 0x4c1c3d
// 004c1c37  83c8ff               or eax, 0xffffffff
// 004c1c3a  c20800               ret 8
// 004c1c3d  0fb78010080000       movzx eax, word ptr [eax + 0x810]
// 004c1c44  c20800               ret 8
// library openrbx-raknet/RakPeer.cpp (function ?GetLowestPing@RakPeer@@UBEHUSystemAddress@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
