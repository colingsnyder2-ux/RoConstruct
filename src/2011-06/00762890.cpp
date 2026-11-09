// from server: 100% by auto
// roc 2011-06 00762890  unit: seg_00760000  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00762890
//
// 00762890  56                   push esi
// 00762891  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00762895  57                   push edi
// 00762896  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0076289a  8bc6                 mov eax, esi
// 0076289c  8bcf                 mov ecx, edi
// 0076289e  e80df9ffff           call 0x7621b0
// 007628a3  8b4808               mov ecx, dword ptr [eax + 8]
// 007628a6  83c1fe               add ecx, -2
// 007628a9  83f906               cmp ecx, 6
// 007628ac  772a                 ja 0x7628d8
// 007628ae  ff248de0287600       jmp dword ptr [ecx*4 + 0x7628e0]
// 007628b5  8b00                 mov eax, dword ptr [eax]
// 007628b7  5f                   pop edi
// 007628b8  5e                   pop esi
// 007628b9  c3                   ret 
// 007628ba  8bc6                 mov eax, esi
// 007628bc  8bcf                 mov ecx, edi
// 007628be  e8edf8ffff           call 0x7621b0
// 007628c3  8b4808               mov ecx, dword ptr [eax + 8]
// 007628c6  83e902               sub ecx, 2
// 007628c9  74ea                 je 0x7628b5
// 007628cb  83e905               sub ecx, 5
// 007628ce  7508                 jne 0x7628d8
// 007628d0  8b00                 mov eax, dword ptr [eax]
// 007628d2  5f                   pop edi
// 007628d3  83c018               add eax, 0x18
// 007628d6  5e                   pop esi
// 007628d7  c3                   ret 
// 007628d8  5f                   pop edi
// 007628d9  33c0                 xor eax, eax
// 007628db  5e                   pop esi
// 007628dc  c3                   ret 
// 007628dd  8d4900               lea ecx, [ecx]
// 007628e0  ba287600d8           mov edx, 0xd8007628
// 007628e5  287600               sub byte ptr [esi], dh
// 007628e8  d828                 fsubr dword ptr [eax]
// 007628ea  7600                 jbe 0x7628ec
// 007628ec  b528                 mov ch, 0x28
// 007628ee  7600                 jbe 0x7628f0
// 007628f0  b528                 mov ch, 0x28
// 007628f2  7600                 jbe 0x7628f4
// 007628f4  ba287600b5           mov edx, 0xb5007628
// 007628f9  287600               sub byte ptr [esi], dh
// library lua-5.1/lapi.c (function _lua_topointer)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
