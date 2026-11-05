// from server: 100% by auto
// roc 2012-06 00832870  unit: RBX::PAVPrimitive::$$A6AXU?$pair::?$signal::Vslot::?$callable  size: 109 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00832870
//
// 00832870  8b442410             mov eax, dword ptr [esp + 0x10]
// 00832874  83ec08               sub esp, 8
// 00832877  56                   push esi
// 00832878  8b742410             mov esi, dword ptr [esp + 0x10]
// 0083287c  85c0                 test eax, eax
// 0083287e  7504                 jne 0x832884
// 00832880  33c9                 xor ecx, ecx
// 00832882  eb0c                 jmp 0x832890
// 00832884  8bce                 mov ecx, esi
// 00832886  e8b5f0ffff           call 0x831940
// 0083288b  2b4620               sub eax, dword ptr [esi + 0x20]
// 0083288e  8bc8                 mov ecx, eax
// 00832890  8b442414             mov eax, dword ptr [esp + 0x14]
// 00832894  40                   inc eax
// 00832895  c1e004               shl eax, 4
// 00832898  8bd0                 mov edx, eax
// 0083289a  8b4608               mov eax, dword ptr [esi + 8]
// 0083289d  57                   push edi
// 0083289e  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 008328a2  2bc2                 sub eax, edx
// 008328a4  89442408             mov dword ptr [esp + 8], eax
// 008328a8  2b4620               sub eax, dword ptr [esi + 0x20]
// 008328ab  51                   push ecx
// 008328ac  50                   push eax
// 008328ad  8d442410             lea eax, [esp + 0x10]
// 008328b1  50                   push eax
// 008328b2  6850288300           push 0x832850
// 008328b7  56                   push esi
// 008328b8  897c2420             mov dword ptr [esp + 0x20], edi
// 008328bc  e81f280200           call 0x8550e0
// 008328c1  83c414               add esp, 0x14
// 008328c4  83ffff               cmp edi, -1
// 008328c7  5f                   pop edi
// 008328c8  750e                 jne 0x8328d8
// 008328ca  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 008328cd  8b7608               mov esi, dword ptr [esi + 8]
// 008328d0  3b7108               cmp esi, dword ptr [ecx + 8]
// 008328d3  7203                 jb 0x8328d8
// 008328d5  897108               mov dword ptr [ecx + 8], esi
// 008328d8  5e                   pop esi
// 008328d9  83c408               add esp, 8
// 008328dc  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pcall)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
