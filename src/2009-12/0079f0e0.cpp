// from server: 100% by auto
// roc 2009-12 0079f0e0  unit: seg_00790000  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079f0e0
//
// 0079f0e0  56                   push esi
// 0079f0e1  8b742408             mov esi, dword ptr [esp + 8]
// 0079f0e5  57                   push edi
// 0079f0e6  6a00                 push 0
// 0079f0e8  6848b69e00           push 0x9eb648
// 0079f0ed  6a02                 push 2
// 0079f0ef  56                   push esi
// 0079f0f0  e8dbb6feff           call 0x78a7d0
// 0079f0f5  6a06                 push 6
// 0079f0f7  6a01                 push 1
// 0079f0f9  56                   push esi
// 0079f0fa  8bf8                 mov edi, eax
// 0079f0fc  e8efb5feff           call 0x78a6f0
// 0079f101  6a03                 push 3
// 0079f103  56                   push esi
// 0079f104  e8a796feff           call 0x7887b0
// 0079f109  57                   push edi
// 0079f10a  6a00                 push 0
// 0079f10c  6860f07900           push 0x79f060
// 0079f111  56                   push esi
// 0079f112  e879a4feff           call 0x789590
// 0079f117  83c434               add esp, 0x34
// 0079f11a  85c0                 test eax, eax
// 0079f11c  7508                 jne 0x79f126
// 0079f11e  5f                   pop edi
// 0079f11f  b801000000           mov eax, 1
// 0079f124  5e                   pop esi
// 0079f125  c3                   ret 
// 0079f126  56                   push esi
// 0079f127  e8149cfeff           call 0x788d40
// 0079f12c  6afe                 push -2
// 0079f12e  56                   push esi
// 0079f12f  e81c97feff           call 0x788850
// 0079f134  83c40c               add esp, 0xc
// 0079f137  5f                   pop edi
// 0079f138  b802000000           mov eax, 2
// 0079f13d  5e                   pop esi
// 0079f13e  c3                   ret 
// library lua-5.1/lbaselib.c (function _luaB_load)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lbaselib.c
