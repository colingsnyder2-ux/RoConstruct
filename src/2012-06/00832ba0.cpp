// from server: 100% by auto
// roc 2012-06 00832ba0  unit: RBX::PAVPrimitive::$$A6AXU?$pair::?$signal::Vslot::?$callable  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00832ba0
//
// 00832ba0  8b442408             mov eax, dword ptr [esp + 8]
// 00832ba4  57                   push edi
// 00832ba5  8b7c2408             mov edi, dword ptr [esp + 8]
// 00832ba9  8bcf                 mov ecx, edi
// 00832bab  e890edffff           call 0x831940
// 00832bb0  83780806             cmp dword ptr [eax + 8], 6
// 00832bb4  7404                 je 0x832bba
// 00832bb6  33c0                 xor eax, eax
// 00832bb8  5f                   pop edi
// 00832bb9  c3                   ret 
// 00832bba  8b00                 mov eax, dword ptr [eax]
// 00832bbc  80780600             cmp byte ptr [eax + 6], 0
// 00832bc0  56                   push esi
// 00832bc1  741f                 je 0x832be2
// 00832bc3  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00832bc7  83f901               cmp ecx, 1
// 00832bca  7c56                 jl 0x832c22
// 00832bcc  0fb65007             movzx edx, byte ptr [eax + 7]
// 00832bd0  3bca                 cmp ecx, edx
// 00832bd2  7f4e                 jg 0x832c22
// 00832bd4  c1e104               shl ecx, 4
// 00832bd7  8d4c0108             lea ecx, [ecx + eax + 8]
// 00832bdb  b8e83bb400           mov eax, 0xb43be8
// 00832be0  eb26                 jmp 0x832c08
// 00832be2  8b542414             mov edx, dword ptr [esp + 0x14]
// 00832be6  83fa01               cmp edx, 1
// 00832be9  8b7010               mov esi, dword ptr [eax + 0x10]
// 00832bec  7c34                 jl 0x832c22
// 00832bee  3b5624               cmp edx, dword ptr [esi + 0x24]
// 00832bf1  7f2f                 jg 0x832c22
// 00832bf3  8b449010             mov eax, dword ptr [eax + edx*4 + 0x10]
// 00832bf7  8b4808               mov ecx, dword ptr [eax + 8]
// 00832bfa  8b461c               mov eax, dword ptr [esi + 0x1c]
// 00832bfd  8b4490fc             mov eax, dword ptr [eax + edx*4 - 4]
// 00832c01  83c010               add eax, 0x10
// 00832c04  85c0                 test eax, eax
// 00832c06  7417                 je 0x832c1f
// 00832c08  8b31                 mov esi, dword ptr [ecx]
// 00832c0a  8b5708               mov edx, dword ptr [edi + 8]
// 00832c0d  8932                 mov dword ptr [edx], esi
// 00832c0f  8b7104               mov esi, dword ptr [ecx + 4]
// 00832c12  897204               mov dword ptr [edx + 4], esi
// 00832c15  8b4908               mov ecx, dword ptr [ecx + 8]
// 00832c18  894a08               mov dword ptr [edx + 8], ecx
// 00832c1b  83470810             add dword ptr [edi + 8], 0x10
// 00832c1f  5e                   pop esi
// 00832c20  5f                   pop edi
// 00832c21  c3                   ret 
// 00832c22  5e                   pop esi
// 00832c23  33c0                 xor eax, eax
// 00832c25  5f                   pop edi
// 00832c26  c3                   ret 
// library lua-5.1/lapi.c (function _lua_getupvalue)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
