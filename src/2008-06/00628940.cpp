// from server: 100% by auto
// roc 2008-06 00628940  unit: seg_00620000  size: 244 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00628940
//
// 00628940  56                   push esi
// 00628941  8b742408             mov esi, dword ptr [esp + 8]
// 00628945  6a01                 push 1
// 00628947  56                   push esi
// 00628948  e8438dfeff           call 0x611690
// 0062894d  68b4448300           push 0x8344b4
// 00628952  6a01                 push 1
// 00628954  56                   push esi
// 00628955  e82684feff           call 0x610d80
// 0062895a  83c414               add esp, 0x14
// 0062895d  85c0                 test eax, eax
// 0062895f  0f85b2000000         jne 0x628a17
// 00628965  6a01                 push 1
// 00628967  56                   push esi
// 00628968  e89394feff           call 0x611e00
// 0062896d  83c408               add esp, 8
// 00628970  83f804               cmp eax, 4
// 00628973  7775                 ja 0x6289ea
// 00628975  ff2485208a6200       jmp dword ptr [eax*4 + 0x628a20]
// 0062897c  6a00                 push 0
// 0062897e  6a01                 push 1
// 00628980  56                   push esi
// 00628981  e88a96feff           call 0x612010
// 00628986  50                   push eax
// 00628987  56                   push esi
// 00628988  e8f398feff           call 0x612280
// 0062898d  83c414               add esp, 0x14
// 00628990  b801000000           mov eax, 1
// 00628995  5e                   pop esi
// 00628996  c3                   ret 
// 00628997  6a01                 push 1
// 00628999  56                   push esi
// 0062899a  e83194feff           call 0x611dd0
// 0062899f  83c408               add esp, 8
// 006289a2  b801000000           mov eax, 1
// 006289a7  5e                   pop esi
// 006289a8  c3                   ret 
// 006289a9  6a01                 push 1
// 006289ab  56                   push esi
// 006289ac  e82f96feff           call 0x611fe0
// 006289b1  83c408               add esp, 8
// 006289b4  85c0                 test eax, eax
// 006289b6  b894ba8100           mov eax, 0x81ba94
// 006289bb  7505                 jne 0x6289c2
// 006289bd  b81ce28100           mov eax, 0x81e21c
// 006289c2  50                   push eax
// 006289c3  56                   push esi
// 006289c4  e8b798feff           call 0x612280
// 006289c9  83c408               add esp, 8
// 006289cc  b801000000           mov eax, 1
// 006289d1  5e                   pop esi
// 006289d2  c3                   ret 
// 006289d3  6a03                 push 3
// 006289d5  68e8048300           push 0x8304e8
// 006289da  56                   push esi
// 006289db  e86098feff           call 0x612240
// 006289e0  83c40c               add esp, 0xc
// 006289e3  b801000000           mov eax, 1
// 006289e8  5e                   pop esi
// 006289e9  c3                   ret 
// 006289ea  6a01                 push 1
// 006289ec  56                   push esi
// 006289ed  e87e97feff           call 0x612170
// 006289f2  83c408               add esp, 8
// 006289f5  50                   push eax
// 006289f6  6a01                 push 1
// 006289f8  56                   push esi
// 006289f9  e80294feff           call 0x611e00
// 006289fe  50                   push eax
// 006289ff  56                   push esi
// 00628a00  e81b94feff           call 0x611e20
// 00628a05  83c410               add esp, 0x10
// 00628a08  50                   push eax
// 00628a09  6800578400           push 0x845700
// 00628a0e  56                   push esi
// 00628a0f  e80c99feff           call 0x612320
// 00628a14  83c410               add esp, 0x10
// 00628a17  b801000000           mov eax, 1
// 00628a1c  5e                   pop esi
// 00628a1d  c3                   ret 
// 00628a1e  8bff                 mov edi, edi
// 00628a20  d3896200a989         ror dword ptr [ecx - 0x7656ff9e], cl
// 00628a26  6200                 bound eax, qword ptr [eax]
// 00628a28  ea8962007c8962       ljmp 0x6289:0x7c006289
// library lua-5.1/lbaselib.c (function _luaB_tostring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lbaselib.c
