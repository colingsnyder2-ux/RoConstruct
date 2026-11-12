// from server: 100% by auto
// roc 2008-06 004c1b20  unit: ProfiledRakPeer  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004c1b20
//
// 004c1b20  8b442408             mov eax, dword ptr [esp + 8]
// 004c1b24  56                   push esi
// 004c1b25  6a00                 push 0
// 004c1b27  8bf1                 mov esi, ecx
// 004c1b29  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004c1b2d  50                   push eax
// 004c1b2e  51                   push ecx
// 004c1b2f  8bce                 mov ecx, esi
// 004c1b31  e8fae1ffff           call 0x4bfd30
// 004c1b36  83f8ff               cmp eax, -1
// 004c1b39  741b                 je 0x4c1b56
// 004c1b3b  8b962c020000         mov edx, dword ptr [esi + 0x22c]
// 004c1b41  69c050080000         imul eax, eax, 0x850
// 004c1b47  803c1000             cmp byte ptr [eax + edx], 0
// 004c1b4b  7409                 je 0x4c1b56
// 004c1b4d  b801000000           mov eax, 1
// 004c1b52  5e                   pop esi
// 004c1b53  c20800               ret 8
// 004c1b56  33c0                 xor eax, eax
// 004c1b58  5e                   pop esi
// 004c1b59  c20800               ret 8
// library openrbx-raknet/RakPeer.cpp (function ?IsConnected@RakPeer@@UAE_NUSystemAddress@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
