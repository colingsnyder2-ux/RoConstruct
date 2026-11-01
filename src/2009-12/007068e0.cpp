// from server: 100% by auto
// roc 2009-12 007068e0  unit: RBX::VInstance::?$NonFactoryProduct  size: 119 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007068e0
//
// 007068e0  6aff                 push -1
// 007068e2  6888ce9400           push 0x94ce88
// 007068e7  64a100000000         mov eax, dword ptr fs:[0]
// 007068ed  50                   push eax
// 007068ee  64892500000000       mov dword ptr fs:[0], esp
// 007068f5  51                   push ecx
// 007068f6  56                   push esi
// 007068f7  57                   push edi
// 007068f8  8bf9                 mov edi, ecx
// 007068fa  897c2408             mov dword ptr [esp + 8], edi
// 007068fe  8b7744               mov esi, dword ptr [edi + 0x44]
// 00706901  c744241400000000     mov dword ptr [esp + 0x14], 0
// 00706909  85f6                 test esi, esi
// 0070690b  742a                 je 0x706937
// 0070690d  8d4604               lea eax, [esi + 4]
// 00706910  83c9ff               or ecx, 0xffffffff
// 00706913  f00fc108             lock xadd dword ptr [eax], ecx
// 00706917  751e                 jne 0x706937
// 00706919  8b16                 mov edx, dword ptr [esi]
// 0070691b  8b4204               mov eax, dword ptr [edx + 4]
// 0070691e  8bce                 mov ecx, esi
// 00706920  ffd0                 call eax
// 00706922  8d4e08               lea ecx, [esi + 8]
// 00706925  83caff               or edx, 0xffffffff
// 00706928  f00fc111             lock xadd dword ptr [ecx], edx
// 0070692c  7509                 jne 0x706937
// 0070692e  8b06                 mov eax, dword ptr [esi]
// 00706930  8b5008               mov edx, dword ptr [eax + 8]
// 00706933  8bce                 mov ecx, esi
// 00706935  ffd2                 call edx
// 00706937  8bcf                 mov ecx, edi
// 00706939  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 00706941  e8faf0ffff           call 0x705a40
// 00706946  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0070694a  5f                   pop edi
// 0070694b  5e                   pop esi
// 0070694c  64890d00000000       mov dword ptr fs:[0], ecx
// 00706953  83c410               add esp, 0x10
// 00706956  c3                   ret 
// library boost-1.44.0/libs\regex\src\cregex.cpp (function ??1?$regex_iterator_implementation@PBDDU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.44.0 libs/regex/src/cregex.cpp
