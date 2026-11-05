// from server: 100% by auto
// roc 2009-12 00797db0  unit: lua_exception  size: 99 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00797db0
//
// 00797db0  83ec14               sub esp, 0x14
// 00797db3  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00797db7  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00797dbb  56                   push esi
// 00797dbc  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 00797dc0  8b5674               mov edx, dword ptr [esi + 0x74]
// 00797dc3  57                   push edi
// 00797dc4  89442408             mov dword ptr [esp + 8], eax
// 00797dc8  8b4608               mov eax, dword ptr [esi + 8]
// 00797dcb  2b4620               sub eax, dword ptr [esi + 0x20]
// 00797dce  52                   push edx
// 00797dcf  50                   push eax
// 00797dd0  894c2420             mov dword ptr [esp + 0x20], ecx
// 00797dd4  8d4c2410             lea ecx, [esp + 0x10]
// 00797dd8  51                   push ecx
// 00797dd9  68f0767900           push 0x7976f0
// 00797dde  56                   push esi
// 00797ddf  c744242000000000     mov dword ptr [esp + 0x20], 0
// 00797de7  c744242800000000     mov dword ptr [esp + 0x28], 0
// 00797def  e8bcfeffff           call 0x797cb0
// 00797df4  8b542428             mov edx, dword ptr [esp + 0x28]
// 00797df8  6a00                 push 0
// 00797dfa  8bf8                 mov edi, eax
// 00797dfc  8b442424             mov eax, dword ptr [esp + 0x24]
// 00797e00  52                   push edx
// 00797e01  50                   push eax
// 00797e02  56                   push esi
// 00797e03  e8a8990300           call 0x7d17b0
// 00797e08  83c424               add esp, 0x24
// 00797e0b  8bc7                 mov eax, edi
// 00797e0d  5f                   pop edi
// 00797e0e  5e                   pop esi
// 00797e0f  83c414               add esp, 0x14
// 00797e12  c3                   ret 
// library lua-5.1/ldo.c (function _luaD_protectedparser)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ldo.c
