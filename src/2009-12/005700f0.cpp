// from server: 100% by auto
// roc 2009-12 005700f0  unit: CSHA1  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005700f0
//
// 005700f0  8b442404             mov eax, dword ptr [esp + 4]
// 005700f4  83c801               or eax, 1
// 005700f7  c781c809000000000000 mov dword ptr [ecx + 0x9c8], 0
// 00570101  8901                 mov dword ptr [ecx], eax
// 00570103  83c104               add ecx, 4
// 00570106  ba6f020000           mov edx, 0x26f
// 0057010b  eb03                 jmp 0x570110
// 0057010d  8d4900               lea ecx, [ecx]
// 00570110  69c0cd0d0100         imul eax, eax, 0x10dcd
// 00570116  8901                 mov dword ptr [ecx], eax
// 00570118  83c104               add ecx, 4
// 0057011b  83ea01               sub edx, 1
// 0057011e  75f0                 jne 0x570110
// 00570120  c20400               ret 4
// library rbx2016-raknet/Rand.cpp (function ?SeedMT@RakNetRandom@RakNet@@QAEXI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-raknet Rand.cpp
