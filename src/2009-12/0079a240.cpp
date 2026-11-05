// from server: 100% by auto
// roc 2009-12 0079a240  unit: lua_exception  size: 77 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079a240
//
// 0079a240  53                   push ebx
// 0079a241  8bc2                 mov eax, edx
// 0079a243  57                   push edi
// 0079a244  8b7e08               mov edi, dword ptr [esi + 8]
// 0079a247  8d5801               lea ebx, [eax + 1]
// 0079a24a  8d9b00000000         lea ebx, [ebx]
// 0079a250  8a08                 mov cl, byte ptr [eax]
// 0079a252  40                   inc eax
// 0079a253  84c9                 test cl, cl
// 0079a255  75f9                 jne 0x79a250
// 0079a257  2bc3                 sub eax, ebx
// 0079a259  50                   push eax
// 0079a25a  52                   push edx
// 0079a25b  56                   push esi
// 0079a25c  e82f690300           call 0x7d0b90
// 0079a261  8907                 mov dword ptr [edi], eax
// 0079a263  c7470804000000       mov dword ptr [edi + 8], 4
// 0079a26a  8b461c               mov eax, dword ptr [esi + 0x1c]
// 0079a26d  2b4608               sub eax, dword ptr [esi + 8]
// 0079a270  bf10000000           mov edi, 0x10
// 0079a275  83c40c               add esp, 0xc
// 0079a278  3bc7                 cmp eax, edi
// 0079a27a  7f0b                 jg 0x79a287
// 0079a27c  6a01                 push 1
// 0079a27e  56                   push esi
// 0079a27f  e8acd0ffff           call 0x797330
// 0079a284  83c408               add esp, 8
// 0079a287  017e08               add dword ptr [esi + 8], edi
// 0079a28a  5f                   pop edi
// 0079a28b  5b                   pop ebx
// 0079a28c  c3                   ret 
// library lua-5.1/lobject.c (function _pushstr)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lobject.c
