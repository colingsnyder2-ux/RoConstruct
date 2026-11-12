// from server: 100% by auto
// roc 2008-06 004c6580  unit: RakPeer  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004c6580
//
// 004c6580  83ec20               sub esp, 0x20
// 004c6583  56                   push esi
// 004c6584  8d442414             lea eax, [esp + 0x14]
// 004c6588  50                   push eax
// 004c6589  8bf1                 mov esi, ecx
// 004c658b  e880e7ffff           call 0x4c4d10
// 004c6590  8d4c2408             lea ecx, [esp + 8]
// 004c6594  51                   push ecx
// 004c6595  e876e7ffff           call 0x4c4d10
// 004c659a  83c408               add esp, 8
// 004c659d  8d542404             lea edx, [esp + 4]
// 004c65a1  52                   push edx
// 004c65a2  8d442418             lea eax, [esp + 0x18]
// 004c65a6  50                   push eax
// 004c65a7  8bce                 mov ecx, esi
// 004c65a9  e882e5ffff           call 0x4c4b30
// 004c65ae  5e                   pop esi
// 004c65af  83c420               add esp, 0x20
// 004c65b2  c3                   ret 
// library openrbx-raknet/RakPeer.cpp (function ?generateKeys@?$RSACrypt@$$BY07I@big@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
