// from server: 100% by auto
// roc 2009-06 006b9b00  unit: RBX::UniversalTool  size: 109 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b9b00
//
// 006b9b00  8b442410             mov eax, dword ptr [esp + 0x10]
// 006b9b04  83ec08               sub esp, 8
// 006b9b07  56                   push esi
// 006b9b08  8b742410             mov esi, dword ptr [esp + 0x10]
// 006b9b0c  85c0                 test eax, eax
// 006b9b0e  7504                 jne 0x6b9b14
// 006b9b10  33c9                 xor ecx, ecx
// 006b9b12  eb0c                 jmp 0x6b9b20
// 006b9b14  8bce                 mov ecx, esi
// 006b9b16  e8b5f0ffff           call 0x6b8bd0
// 006b9b1b  2b4620               sub eax, dword ptr [esi + 0x20]
// 006b9b1e  8bc8                 mov ecx, eax
// 006b9b20  8b442414             mov eax, dword ptr [esp + 0x14]
// 006b9b24  40                   inc eax
// 006b9b25  c1e004               shl eax, 4
// 006b9b28  8bd0                 mov edx, eax
// 006b9b2a  8b4608               mov eax, dword ptr [esi + 8]
// 006b9b2d  57                   push edi
// 006b9b2e  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 006b9b32  2bc2                 sub eax, edx
// 006b9b34  89442408             mov dword ptr [esp + 8], eax
// 006b9b38  2b4620               sub eax, dword ptr [esi + 0x20]
// 006b9b3b  51                   push ecx
// 006b9b3c  50                   push eax
// 006b9b3d  8d442410             lea eax, [esp + 0x10]
// 006b9b41  50                   push eax
// 006b9b42  68e09a6b00           push 0x6b9ae0
// 006b9b47  56                   push esi
// 006b9b48  897c2420             mov dword ptr [esp + 0x20], edi
// 006b9b4c  e8ef9b0000           call 0x6c3740
// 006b9b51  83c414               add esp, 0x14
// 006b9b54  83ffff               cmp edi, -1
// 006b9b57  5f                   pop edi
// 006b9b58  750e                 jne 0x6b9b68
// 006b9b5a  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 006b9b5d  8b7608               mov esi, dword ptr [esi + 8]
// 006b9b60  3b7108               cmp esi, dword ptr [ecx + 8]
// 006b9b63  7203                 jb 0x6b9b68
// 006b9b65  897108               mov dword ptr [ecx + 8], esi
// 006b9b68  5e                   pop esi
// 006b9b69  83c408               add esp, 8
// 006b9b6c  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pcall)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
