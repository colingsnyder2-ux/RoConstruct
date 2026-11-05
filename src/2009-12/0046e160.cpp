// from server: 100% by auto
// roc 2009-12 0046e160  unit: CScriptEditor  size: 119 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0046e160
//
// 0046e160  6aff                 push -1
// 0046e162  68a8d59200           push 0x92d5a8
// 0046e167  64a100000000         mov eax, dword ptr fs:[0]
// 0046e16d  50                   push eax
// 0046e16e  64892500000000       mov dword ptr fs:[0], esp
// 0046e175  51                   push ecx
// 0046e176  56                   push esi
// 0046e177  57                   push edi
// 0046e178  8bf9                 mov edi, ecx
// 0046e17a  897c2408             mov dword ptr [esp + 8], edi
// 0046e17e  8b7758               mov esi, dword ptr [edi + 0x58]
// 0046e181  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0046e189  85f6                 test esi, esi
// 0046e18b  742a                 je 0x46e1b7
// 0046e18d  8d4604               lea eax, [esi + 4]
// 0046e190  83c9ff               or ecx, 0xffffffff
// 0046e193  f00fc108             lock xadd dword ptr [eax], ecx
// 0046e197  751e                 jne 0x46e1b7
// 0046e199  8b16                 mov edx, dword ptr [esi]
// 0046e19b  8b4204               mov eax, dword ptr [edx + 4]
// 0046e19e  8bce                 mov ecx, esi
// 0046e1a0  ffd0                 call eax
// 0046e1a2  8d4e08               lea ecx, [esi + 8]
// 0046e1a5  83caff               or edx, 0xffffffff
// 0046e1a8  f00fc111             lock xadd dword ptr [ecx], edx
// 0046e1ac  7509                 jne 0x46e1b7
// 0046e1ae  8b06                 mov eax, dword ptr [esi]
// 0046e1b0  8b5008               mov edx, dword ptr [eax + 8]
// 0046e1b3  8bce                 mov ecx, esi
// 0046e1b5  ffd2                 call edx
// 0046e1b7  8bcf                 mov ecx, edi
// 0046e1b9  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 0046e1c1  e8305a3800           call 0x7f3bf6
// 0046e1c6  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0046e1ca  5f                   pop edi
// 0046e1cb  5e                   pop esi
// 0046e1cc  64890d00000000       mov dword ptr fs:[0], ecx
// 0046e1d3  83c410               add esp, 0x10
// 0046e1d6  c3                   ret 
// library boost-1.44.0/libs\regex\src\cregex.cpp (function ??1?$regex_iterator_implementation@V?$_String_const_iterator@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.44.0 libs/regex/src/cregex.cpp
