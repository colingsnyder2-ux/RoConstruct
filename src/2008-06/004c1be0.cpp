// from server: 100% by auto
// roc 2008-06 004c1be0  unit: ProfiledRakPeer  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004c1be0
//
// 004c1be0  8b442408             mov eax, dword ptr [esp + 8]
// 004c1be4  8b542404             mov edx, dword ptr [esp + 4]
// 004c1be8  6a00                 push 0
// 004c1bea  6a00                 push 0
// 004c1bec  50                   push eax
// 004c1bed  52                   push edx
// 004c1bee  e8ede1ffff           call 0x4bfde0
// 004c1bf3  85c0                 test eax, eax
// 004c1bf5  7506                 jne 0x4c1bfd
// 004c1bf7  83c8ff               or eax, 0xffffffff
// 004c1bfa  c20800               ret 8
// 004c1bfd  8d4818               lea ecx, [eax + 0x18]
// 004c1c00  e8ebd00000           call 0x4cecf0
// 004c1c05  6a00                 push 0
// 004c1c07  68e8030000           push 0x3e8
// 004c1c0c  52                   push edx
// 004c1c0d  50                   push eax
// 004c1c0e  e81d001e00           call 0x6a1c30
// 004c1c13  c20800               ret 8
// library openrbx-raknet/RakPeer.cpp (function ?GetLastPing@RakPeer@@UBEHUSystemAddress@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
