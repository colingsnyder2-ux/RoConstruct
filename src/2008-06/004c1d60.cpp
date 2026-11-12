// from server: 100% by auto
// roc 2008-06 004c1d60  unit: ProfiledRakPeer  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004c1d60
//
// 004c1d60  56                   push esi
// 004c1d61  8bf1                 mov esi, ecx
// 004c1d63  6870cb9300           push 0x93cb70
// 004c1d68  8d4c240c             lea ecx, [esp + 0xc]
// 004c1d6c  e8df7afeff           call 0x4a9850
// 004c1d71  84c0                 test al, al
// 004c1d73  7423                 je 0x4c1d98
// 004c1d75  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004c1d79  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004c1d7d  6a01                 push 1
// 004c1d7f  6a00                 push 0
// 004c1d81  50                   push eax
// 004c1d82  51                   push ecx
// 004c1d83  8bce                 mov ecx, esi
// 004c1d85  e856e0ffff           call 0x4bfde0
// 004c1d8a  85c0                 test eax, eax
// 004c1d8c  740a                 je 0x4c1d98
// 004c1d8e  8b8044080000         mov eax, dword ptr [eax + 0x844]
// 004c1d94  5e                   pop esi
// 004c1d95  c20800               ret 8
// 004c1d98  8b8608070000         mov eax, dword ptr [esi + 0x708]
// 004c1d9e  5e                   pop esi
// 004c1d9f  c20800               ret 8
// library openrbx-raknet/RakPeer.cpp (function ?GetMTUSize@RakPeer@@UBEHUSystemAddress@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
