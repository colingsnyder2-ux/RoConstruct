// from server: 100% by auto
// roc 2010-06 00721c70  unit: RBX::UniversalTool  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00721c70
//
// 00721c70  8b442408             mov eax, dword ptr [esp + 8]
// 00721c74  56                   push esi
// 00721c75  8b742408             mov esi, dword ptr [esp + 8]
// 00721c79  8b4e08               mov ecx, dword ptr [esi + 8]
// 00721c7c  57                   push edi
// 00721c7d  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00721c81  40                   inc eax
// 00721c82  c1e004               shl eax, 4
// 00721c85  57                   push edi
// 00721c86  2bc8                 sub ecx, eax
// 00721c88  51                   push ecx
// 00721c89  56                   push esi
// 00721c8a  e8d1e60000           call 0x730360
// 00721c8f  83c40c               add esp, 0xc
// 00721c92  83ffff               cmp edi, -1
// 00721c95  750e                 jne 0x721ca5
// 00721c97  8b4614               mov eax, dword ptr [esi + 0x14]
// 00721c9a  8b7608               mov esi, dword ptr [esi + 8]
// 00721c9d  3b7008               cmp esi, dword ptr [eax + 8]
// 00721ca0  7203                 jb 0x721ca5
// 00721ca2  897008               mov dword ptr [eax + 8], esi
// 00721ca5  5f                   pop edi
// 00721ca6  5e                   pop esi
// 00721ca7  c3                   ret 
// library lua-5.1/lapi.c (function _lua_call)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
