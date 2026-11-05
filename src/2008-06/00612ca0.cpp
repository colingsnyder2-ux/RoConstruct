// from server: 100% by auto
// roc 2008-06 00612ca0  unit: seg_00610000  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00612ca0
//
// 00612ca0  8b442408             mov eax, dword ptr [esp + 8]
// 00612ca4  57                   push edi
// 00612ca5  8b7c2408             mov edi, dword ptr [esp + 8]
// 00612ca9  8bcf                 mov ecx, edi
// 00612cab  e8e0edffff           call 0x611a90
// 00612cb0  83780806             cmp dword ptr [eax + 8], 6
// 00612cb4  7404                 je 0x612cba
// 00612cb6  33c0                 xor eax, eax
// 00612cb8  5f                   pop edi
// 00612cb9  c3                   ret 
// 00612cba  8b00                 mov eax, dword ptr [eax]
// 00612cbc  80780600             cmp byte ptr [eax + 6], 0
// 00612cc0  56                   push esi
// 00612cc1  741f                 je 0x612ce2
// 00612cc3  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00612cc7  83f901               cmp ecx, 1
// 00612cca  7c56                 jl 0x612d22
// 00612ccc  0fb65007             movzx edx, byte ptr [eax + 7]
// 00612cd0  3bca                 cmp ecx, edx
// 00612cd2  7f4e                 jg 0x612d22
// 00612cd4  c1e104               shl ecx, 4
// 00612cd7  8d4c0108             lea ecx, [ecx + eax + 8]
// 00612cdb  b816b78000           mov eax, 0x80b716
// 00612ce0  eb26                 jmp 0x612d08
// 00612ce2  8b542414             mov edx, dword ptr [esp + 0x14]
// 00612ce6  83fa01               cmp edx, 1
// 00612ce9  8b7010               mov esi, dword ptr [eax + 0x10]
// 00612cec  7c34                 jl 0x612d22
// 00612cee  3b5624               cmp edx, dword ptr [esi + 0x24]
// 00612cf1  7f2f                 jg 0x612d22
// 00612cf3  8b449010             mov eax, dword ptr [eax + edx*4 + 0x10]
// 00612cf7  8b4808               mov ecx, dword ptr [eax + 8]
// 00612cfa  8b461c               mov eax, dword ptr [esi + 0x1c]
// 00612cfd  8b4490fc             mov eax, dword ptr [eax + edx*4 - 4]
// 00612d01  83c010               add eax, 0x10
// 00612d04  85c0                 test eax, eax
// 00612d06  7417                 je 0x612d1f
// 00612d08  8b31                 mov esi, dword ptr [ecx]
// 00612d0a  8b5708               mov edx, dword ptr [edi + 8]
// 00612d0d  8932                 mov dword ptr [edx], esi
// 00612d0f  8b7104               mov esi, dword ptr [ecx + 4]
// 00612d12  897204               mov dword ptr [edx + 4], esi
// 00612d15  8b4908               mov ecx, dword ptr [ecx + 8]
// 00612d18  894a08               mov dword ptr [edx + 8], ecx
// 00612d1b  83470810             add dword ptr [edi + 8], 0x10
// 00612d1f  5e                   pop esi
// 00612d20  5f                   pop edi
// 00612d21  c3                   ret 
// 00612d22  5e                   pop esi
// 00612d23  33c0                 xor eax, eax
// 00612d25  5f                   pop edi
// 00612d26  c3                   ret 
// library lua-5.1/lapi.c (function _lua_getupvalue)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
