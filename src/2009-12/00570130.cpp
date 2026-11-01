// from server: 100% by auto
// roc 2009-12 00570130  unit: CSHA1  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00570130
//
// 00570130  8b442404             mov eax, dword ptr [esp + 4]
// 00570134  83c801               or eax, 1
// 00570137  c705ec08b20000000000 mov dword ptr [0xb208ec], 0
// 00570141  a3501db800           mov dword ptr [0xb81d50], eax
// 00570146  b9541db800           mov ecx, 0xb81d54
// 0057014b  ba6f020000           mov edx, 0x26f
// 00570150  69c0cd0d0100         imul eax, eax, 0x10dcd
// 00570156  8901                 mov dword ptr [ecx], eax
// 00570158  83c104               add ecx, 4
// 0057015b  83ea01               sub edx, 1
// 0057015e  75f0                 jne 0x570150
// 00570160  c3                   ret 
// library raknet-4.081/Rand.cpp (function ?seedMT@@YAXI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 Rand.cpp
