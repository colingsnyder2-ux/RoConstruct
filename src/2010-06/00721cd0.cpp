// from server: 100% by auto
// roc 2010-06 00721cd0  unit: RBX::UniversalTool  size: 109 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00721cd0
//
// 00721cd0  8b442410             mov eax, dword ptr [esp + 0x10]
// 00721cd4  83ec08               sub esp, 8
// 00721cd7  56                   push esi
// 00721cd8  8b742410             mov esi, dword ptr [esp + 0x10]
// 00721cdc  85c0                 test eax, eax
// 00721cde  7504                 jne 0x721ce4
// 00721ce0  33c9                 xor ecx, ecx
// 00721ce2  eb0c                 jmp 0x721cf0
// 00721ce4  8bce                 mov ecx, esi
// 00721ce6  e8b5f0ffff           call 0x720da0
// 00721ceb  2b4620               sub eax, dword ptr [esi + 0x20]
// 00721cee  8bc8                 mov ecx, eax
// 00721cf0  8b442414             mov eax, dword ptr [esp + 0x14]
// 00721cf4  40                   inc eax
// 00721cf5  c1e004               shl eax, 4
// 00721cf8  8bd0                 mov edx, eax
// 00721cfa  8b4608               mov eax, dword ptr [esi + 8]
// 00721cfd  57                   push edi
// 00721cfe  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 00721d02  2bc2                 sub eax, edx
// 00721d04  89442408             mov dword ptr [esp + 8], eax
// 00721d08  2b4620               sub eax, dword ptr [esi + 0x20]
// 00721d0b  51                   push ecx
// 00721d0c  50                   push eax
// 00721d0d  8d442410             lea eax, [esp + 0x10]
// 00721d11  50                   push eax
// 00721d12  68b01c7200           push 0x721cb0
// 00721d17  56                   push esi
// 00721d18  897c2420             mov dword ptr [esp + 0x20], edi
// 00721d1c  e8efe70000           call 0x730510
// 00721d21  83c414               add esp, 0x14
// 00721d24  83ffff               cmp edi, -1
// 00721d27  5f                   pop edi
// 00721d28  750e                 jne 0x721d38
// 00721d2a  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00721d2d  8b7608               mov esi, dword ptr [esi + 8]
// 00721d30  3b7108               cmp esi, dword ptr [ecx + 8]
// 00721d33  7203                 jb 0x721d38
// 00721d35  897108               mov dword ptr [ecx + 8], esi
// 00721d38  5e                   pop esi
// 00721d39  83c408               add esp, 8
// 00721d3c  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pcall)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
