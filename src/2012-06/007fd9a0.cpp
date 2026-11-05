// roc 2012-06 007fd9a0  unit: std::D::DU?$char_traits::$$A6AXV?$basic_string::?$signal::Vslot::?$callable  size: 119 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007fd9a0
//
// 007fd9a0  6aff                 push -1
// 007fd9a2  68a8a4ac00           push 0xaca4a8
// 007fd9a7  64a100000000         mov eax, dword ptr fs:[0]
// 007fd9ad  50                   push eax
// 007fd9ae  64892500000000       mov dword ptr fs:[0], esp
// 007fd9b5  51                   push ecx
// 007fd9b6  56                   push esi
// 007fd9b7  57                   push edi
// 007fd9b8  8bf9                 mov edi, ecx
// 007fd9ba  897c2408             mov dword ptr [esp + 8], edi
// 007fd9be  8b7744               mov esi, dword ptr [edi + 0x44]
// 007fd9c1  c744241400000000     mov dword ptr [esp + 0x14], 0
// 007fd9c9  85f6                 test esi, esi
// 007fd9cb  742a                 je 0x7fd9f7
// 007fd9cd  8d4604               lea eax, [esi + 4]
// 007fd9d0  83c9ff               or ecx, 0xffffffff
// 007fd9d3  f00fc108             lock xadd dword ptr [eax], ecx
// 007fd9d7  751e                 jne 0x7fd9f7
// 007fd9d9  8b16                 mov edx, dword ptr [esi]
// 007fd9db  8b4204               mov eax, dword ptr [edx + 4]
// 007fd9de  8bce                 mov ecx, esi
// 007fd9e0  ffd0                 call eax
// 007fd9e2  8d4e08               lea ecx, [esi + 8]
// 007fd9e5  83caff               or edx, 0xffffffff
// 007fd9e8  f00fc111             lock xadd dword ptr [ecx], edx
// 007fd9ec  7509                 jne 0x7fd9f7
// 007fd9ee  8b06                 mov eax, dword ptr [esi]
// 007fd9f0  8b5008               mov edx, dword ptr [eax + 8]
// 007fd9f3  8bce                 mov ecx, esi
// 007fd9f5  ffd2                 call edx
// 007fd9f7  8bcf                 mov ecx, edi
// 007fd9f9  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 007fda01  e8eaf2ffff           call 0x7fccf0
// 007fda06  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007fda0a  5f                   pop edi
// 007fda0b  5e                   pop esi
// 007fda0c  64890d00000000       mov dword ptr fs:[0], ecx
// 007fda13  83c410               add esp, 0x10
// 007fda16  c3                   ret 
// copied from an identical function in another client (function ??1?$regex_iterator_implementation@PBDDU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@boost@@QAE@XZ)

// roc-cl: 30729
// roc-lang: cpp
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.44.0 libs/regex/src/cregex.cpp