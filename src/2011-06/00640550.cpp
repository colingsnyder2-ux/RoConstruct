// from server: 100% by auto
// roc 2011-06 00640550  unit: RBX::DecalTool  size: 119 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00640550
//
// 00640550  6aff                 push -1
// 00640552  6808b99e00           push 0x9eb908
// 00640557  64a100000000         mov eax, dword ptr fs:[0]
// 0064055d  50                   push eax
// 0064055e  64892500000000       mov dword ptr fs:[0], esp
// 00640565  51                   push ecx
// 00640566  56                   push esi
// 00640567  57                   push edi
// 00640568  8bf9                 mov edi, ecx
// 0064056a  897c2408             mov dword ptr [esp + 8], edi
// 0064056e  8b7754               mov esi, dword ptr [edi + 0x54]
// 00640571  c744241400000000     mov dword ptr [esp + 0x14], 0
// 00640579  85f6                 test esi, esi
// 0064057b  742a                 je 0x6405a7
// 0064057d  8d4604               lea eax, [esi + 4]
// 00640580  83c9ff               or ecx, 0xffffffff
// 00640583  f00fc108             lock xadd dword ptr [eax], ecx
// 00640587  751e                 jne 0x6405a7
// 00640589  8b16                 mov edx, dword ptr [esi]
// 0064058b  8b4204               mov eax, dword ptr [edx + 4]
// 0064058e  8bce                 mov ecx, esi
// 00640590  ffd0                 call eax
// 00640592  8d4e08               lea ecx, [esi + 8]
// 00640595  83caff               or edx, 0xffffffff
// 00640598  f00fc111             lock xadd dword ptr [ecx], edx
// 0064059c  7509                 jne 0x6405a7
// 0064059e  8b06                 mov eax, dword ptr [esi]
// 006405a0  8b5008               mov edx, dword ptr [eax + 8]
// 006405a3  8bce                 mov ecx, esi
// 006405a5  ffd2                 call edx
// 006405a7  8bcf                 mov ecx, edi
// 006405a9  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 006405b1  e89adcffff           call 0x63e250
// 006405b6  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 006405ba  5f                   pop edi
// 006405bb  5e                   pop esi
// 006405bc  64890d00000000       mov dword ptr fs:[0], ecx
// 006405c3  83c410               add esp, 0x10
// 006405c6  c3                   ret 
// library boost-1.40.0/libs\regex\src\cregex.cpp (function ??1?$regex_iterator_implementation@V?$_String_const_iterator@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/cregex.cpp
