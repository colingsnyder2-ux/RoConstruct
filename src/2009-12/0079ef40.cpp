// from server: 100% by auto
// roc 2009-12 0079ef40  unit: seg_00790000  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079ef40
//
// 0079ef40  56                   push esi
// 0079ef41  8b742408             mov esi, dword ptr [esp + 8]
// 0079ef45  57                   push edi
// 0079ef46  6a02                 push 2
// 0079ef48  56                   push esi
// 0079ef49  e862b9feff           call 0x78a8b0
// 0079ef4e  6a05                 push 5
// 0079ef50  6a01                 push 1
// 0079ef52  56                   push esi
// 0079ef53  8bf8                 mov edi, eax
// 0079ef55  e896b7feff           call 0x78a6f0
// 0079ef5a  47                   inc edi
// 0079ef5b  57                   push edi
// 0079ef5c  56                   push esi
// 0079ef5d  e81e9efeff           call 0x788d80
// 0079ef62  57                   push edi
// 0079ef63  6a01                 push 1
// 0079ef65  56                   push esi
// 0079ef66  e825a1feff           call 0x789090
// 0079ef6b  6aff                 push -1
// 0079ef6d  56                   push esi
// 0079ef6e  e81d9afeff           call 0x788990
// 0079ef73  83c430               add esp, 0x30
// 0079ef76  f7d8                 neg eax
// 0079ef78  1bc0                 sbb eax, eax
// 0079ef7a  5f                   pop edi
// 0079ef7b  83e002               and eax, 2
// 0079ef7e  5e                   pop esi
// 0079ef7f  c3                   ret 
// library lua-5.1/lbaselib.c (function _ipairsaux)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lbaselib.c
