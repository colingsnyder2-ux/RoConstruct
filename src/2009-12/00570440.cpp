// from server: 100% by auto
// roc 2009-12 00570440  unit: CSHA1  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00570440
//
// 00570440  8b442408             mov eax, dword ptr [esp + 8]
// 00570444  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00570448  68ec08b200           push 0xb208ec
// 0057044d  68481db800           push 0xb81d48
// 00570452  68501db800           push 0xb81d50
// 00570457  50                   push eax
// 00570458  51                   push ecx
// 00570459  e8f2feffff           call 0x570350
// 0057045e  83c414               add esp, 0x14
// 00570461  c3                   ret 
// library raknet-4.081/Rand.cpp (function ?fillBufferMT@@YAXPAXI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 Rand.cpp
