// from server: 100% by auto
// roc 2010-06 00721ee0  unit: RBX::UniversalTool  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00721ee0
//
// 00721ee0  8b442408             mov eax, dword ptr [esp + 8]
// 00721ee4  56                   push esi
// 00721ee5  8b742408             mov esi, dword ptr [esp + 8]
// 00721ee9  8bce                 mov ecx, esi
// 00721eeb  e8b0eeffff           call 0x720da0
// 00721ef0  8b4e08               mov ecx, dword ptr [esi + 8]
// 00721ef3  8b10                 mov edx, dword ptr [eax]
// 00721ef5  83e910               sub ecx, 0x10
// 00721ef8  51                   push ecx
// 00721ef9  52                   push edx
// 00721efa  56                   push esi
// 00721efb  e830b10500           call 0x77d030
// 00721f00  83c40c               add esp, 0xc
// 00721f03  85c0                 test eax, eax
// 00721f05  7406                 je 0x721f0d
// 00721f07  83460810             add dword ptr [esi + 8], 0x10
// 00721f0b  5e                   pop esi
// 00721f0c  c3                   ret 
// 00721f0d  834608f0             add dword ptr [esi + 8], -0x10
// 00721f11  5e                   pop esi
// 00721f12  c3                   ret 
// library lua-5.1/lapi.c (function _lua_next)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
