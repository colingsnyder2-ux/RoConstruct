// from server: 100% by auto
// roc 2009-12 007972b0  unit: lua_exception  size: 123 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007972b0
//
// 007972b0  53                   push ebx
// 007972b1  55                   push ebp
// 007972b2  56                   push esi
// 007972b3  8b742410             mov esi, dword ptr [esp + 0x10]
// 007972b7  8b6e28               mov ebp, dword ptr [esi + 0x28]
// 007972ba  57                   push edi
// 007972bb  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 007972bf  8d4701               lea eax, [edi + 1]
// 007972c2  3daaaaaa0a           cmp eax, 0xaaaaaaa
// 007972c7  7723                 ja 0x7972ec
// 007972c9  8b4630               mov eax, dword ptr [esi + 0x30]
// 007972cc  8d0c7f               lea ecx, [edi + edi*2]
// 007972cf  03c9                 add ecx, ecx
// 007972d1  8d1440               lea edx, [eax + eax*2]
// 007972d4  03d2                 add edx, edx
// 007972d6  03c9                 add ecx, ecx
// 007972d8  03c9                 add ecx, ecx
// 007972da  51                   push ecx
// 007972db  03d2                 add edx, edx
// 007972dd  03d2                 add edx, edx
// 007972df  52                   push edx
// 007972e0  55                   push ebp
// 007972e1  56                   push esi
// 007972e2  e8c9a40300           call 0x7d17b0
// 007972e7  83c410               add esp, 0x10
// 007972ea  eb09                 jmp 0x7972f5
// 007972ec  56                   push esi
// 007972ed  e89ea40300           call 0x7d1790
// 007972f2  83c404               add esp, 4
// 007972f5  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 007972f8  8bd8                 mov ebx, eax
// 007972fa  2bcd                 sub ecx, ebp
// 007972fc  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00797301  f7e9                 imul ecx
// 00797303  c1fa02               sar edx, 2
// 00797306  8bc2                 mov eax, edx
// 00797308  c1e81f               shr eax, 0x1f
// 0079730b  03c2                 add eax, edx
// 0079730d  8d0440               lea eax, [eax + eax*2]
// 00797310  8d0cc3               lea ecx, [ebx + eax*8]
// 00797313  8d147f               lea edx, [edi + edi*2]
// 00797316  897e30               mov dword ptr [esi + 0x30], edi
// 00797319  8d44d3e8             lea eax, [ebx + edx*8 - 0x18]
// 0079731d  5f                   pop edi
// 0079731e  895e28               mov dword ptr [esi + 0x28], ebx
// 00797321  894e14               mov dword ptr [esi + 0x14], ecx
// 00797324  894624               mov dword ptr [esi + 0x24], eax
// 00797327  5e                   pop esi
// 00797328  5d                   pop ebp
// 00797329  5b                   pop ebx
// 0079732a  c3                   ret 
// library lua-5.1/ldo.c (function _luaD_reallocCI)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ldo.c
