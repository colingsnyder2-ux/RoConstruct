// from server: 100% by auto
// roc 2008-06 00624360  unit: lua_exception  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00624360
//
// 00624360  56                   push esi
// 00624361  8b742408             mov esi, dword ptr [esp + 8]
// 00624365  68dc4b8400           push 0x844bdc
// 0062436a  6a01                 push 1
// 0062436c  56                   push esi
// 0062436d  e83ed2feff           call 0x6115b0
// 00624372  8b00                 mov eax, dword ptr [eax]
// 00624374  83c40c               add esp, 0xc
// 00624377  85c0                 test eax, eax
// 00624379  7515                 jne 0x624390
// 0062437b  68184c8400           push 0x844c18
// 00624380  56                   push esi
// 00624381  e8fadefeff           call 0x612280
// 00624386  83c408               add esp, 8
// 00624389  b801000000           mov eax, 1
// 0062438e  5e                   pop esi
// 0062438f  c3                   ret 
// 00624390  50                   push eax
// 00624391  680c4c8400           push 0x844c0c
// 00624396  56                   push esi
// 00624397  e884dffeff           call 0x612320
// 0062439c  83c40c               add esp, 0xc
// 0062439f  b801000000           mov eax, 1
// 006243a4  5e                   pop esi
// 006243a5  c3                   ret 
// library lua-5.1.2/liolib.c (function _io_tostring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.2 liolib.c
