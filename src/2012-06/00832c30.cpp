// from server: 100% by auto
// roc 2012-06 00832c30  unit: RBX::PAVPrimitive::$$A6AXU?$pair::?$signal::Vslot::?$callable  size: 174 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00832c30
//
// 00832c30  8b442408             mov eax, dword ptr [esp + 8]
// 00832c34  57                   push edi
// 00832c35  8b7c2408             mov edi, dword ptr [esp + 8]
// 00832c39  8bcf                 mov ecx, edi
// 00832c3b  e800edffff           call 0x831940
// 00832c40  83780806             cmp dword ptr [eax + 8], 6
// 00832c44  7404                 je 0x832c4a
// 00832c46  33c0                 xor eax, eax
// 00832c48  5f                   pop edi
// 00832c49  c3                   ret 
// 00832c4a  8b08                 mov ecx, dword ptr [eax]
// 00832c4c  80790600             cmp byte ptr [ecx + 6], 0
// 00832c50  8b542410             mov edx, dword ptr [esp + 0x10]
// 00832c54  56                   push esi
// 00832c55  741b                 je 0x832c72
// 00832c57  83fa01               cmp edx, 1
// 00832c5a  7c7d                 jl 0x832cd9
// 00832c5c  0fb67107             movzx esi, byte ptr [ecx + 7]
// 00832c60  3bd6                 cmp edx, esi
// 00832c62  7f75                 jg 0x832cd9
// 00832c64  c1e204               shl edx, 4
// 00832c67  8d4c0a08             lea ecx, [edx + ecx + 8]
// 00832c6b  bee83bb400           mov esi, 0xb43be8
// 00832c70  eb22                 jmp 0x832c94
// 00832c72  83fa01               cmp edx, 1
// 00832c75  8b7110               mov esi, dword ptr [ecx + 0x10]
// 00832c78  7c5f                 jl 0x832cd9
// 00832c7a  3b5624               cmp edx, dword ptr [esi + 0x24]
// 00832c7d  7f5a                 jg 0x832cd9
// 00832c7f  8b761c               mov esi, dword ptr [esi + 0x1c]
// 00832c82  8b7496fc             mov esi, dword ptr [esi + edx*4 - 4]
// 00832c86  8b4c9110             mov ecx, dword ptr [ecx + edx*4 + 0x10]
// 00832c8a  8b4908               mov ecx, dword ptr [ecx + 8]
// 00832c8d  83c610               add esi, 0x10
// 00832c90  85f6                 test esi, esi
// 00832c92  7440                 je 0x832cd4
// 00832c94  834708f0             add dword ptr [edi + 8], -0x10
// 00832c98  8b5708               mov edx, dword ptr [edi + 8]
// 00832c9b  53                   push ebx
// 00832c9c  8b1a                 mov ebx, dword ptr [edx]
// 00832c9e  8919                 mov dword ptr [ecx], ebx
// 00832ca0  8b5a04               mov ebx, dword ptr [edx + 4]
// 00832ca3  895904               mov dword ptr [ecx + 4], ebx
// 00832ca6  8b5208               mov edx, dword ptr [edx + 8]
// 00832ca9  895108               mov dword ptr [ecx + 8], edx
// 00832cac  8b4f08               mov ecx, dword ptr [edi + 8]
// 00832caf  ba04000000           mov edx, 4
// 00832cb4  395108               cmp dword ptr [ecx + 8], edx
// 00832cb7  5b                   pop ebx
// 00832cb8  7c1a                 jl 0x832cd4
// 00832cba  8b09                 mov ecx, dword ptr [ecx]
// 00832cbc  f6410503             test byte ptr [ecx + 5], 3
// 00832cc0  7412                 je 0x832cd4
// 00832cc2  8b00                 mov eax, dword ptr [eax]
// 00832cc4  845005               test byte ptr [eax + 5], dl
// 00832cc7  740b                 je 0x832cd4
// 00832cc9  51                   push ecx
// 00832cca  50                   push eax
// 00832ccb  57                   push edi
// 00832ccc  e8cf061000           call 0x9333a0
// 00832cd1  83c40c               add esp, 0xc
// 00832cd4  8bc6                 mov eax, esi
// 00832cd6  5e                   pop esi
// 00832cd7  5f                   pop edi
// 00832cd8  c3                   ret 
// 00832cd9  5e                   pop esi
// 00832cda  33c0                 xor eax, eax
// 00832cdc  5f                   pop edi
// 00832cdd  c3                   ret 
// library lua-5.1/lapi.c (function _lua_setupvalue)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
