// from server: 100% by auto
// roc 2007-03 00560ba0  unit: seg_00560000  size: 119 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00560ba0
//
// 00560ba0  6aff                 push -1
// 00560ba2  68a8517500           push 0x7551a8
// 00560ba7  64a100000000         mov eax, dword ptr fs:[0]
// 00560bad  50                   push eax
// 00560bae  64892500000000       mov dword ptr fs:[0], esp
// 00560bb5  51                   push ecx
// 00560bb6  56                   push esi
// 00560bb7  57                   push edi
// 00560bb8  8bf9                 mov edi, ecx
// 00560bba  897c2408             mov dword ptr [esp + 8], edi
// 00560bbe  8b7738               mov esi, dword ptr [edi + 0x38]
// 00560bc1  85f6                 test esi, esi
// 00560bc3  c744241400000000     mov dword ptr [esp + 0x14], 0
// 00560bcb  742a                 je 0x560bf7
// 00560bcd  8d4604               lea eax, [esi + 4]
// 00560bd0  83c9ff               or ecx, 0xffffffff
// 00560bd3  f00fc108             lock xadd dword ptr [eax], ecx
// 00560bd7  751e                 jne 0x560bf7
// 00560bd9  8b16                 mov edx, dword ptr [esi]
// 00560bdb  8b4204               mov eax, dword ptr [edx + 4]
// 00560bde  8bce                 mov ecx, esi
// 00560be0  ffd0                 call eax
// 00560be2  8d4e08               lea ecx, [esi + 8]
// 00560be5  83caff               or edx, 0xffffffff
// 00560be8  f00fc111             lock xadd dword ptr [ecx], edx
// 00560bec  7509                 jne 0x560bf7
// 00560bee  8b06                 mov eax, dword ptr [esi]
// 00560bf0  8b5008               mov edx, dword ptr [eax + 8]
// 00560bf3  8bce                 mov ecx, esi
// 00560bf5  ffd2                 call edx
// 00560bf7  8bcf                 mov ecx, edi
// 00560bf9  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 00560c01  e80a540000           call 0x566010
// 00560c06  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00560c0a  5f                   pop edi
// 00560c0b  5e                   pop esi
// 00560c0c  64890d00000000       mov dword ptr fs:[0], ecx
// 00560c13  83c410               add esp, 0x10
// 00560c16  c3                   ret 
// library boost-1.40.0/libs\regex\src\cregex.cpp (function ??1?$regex_iterator_implementation@PBDDU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/cregex.cpp
