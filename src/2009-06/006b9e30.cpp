// from server: 100% by auto
// roc 2009-06 006b9e30  unit: RBX::UniversalTool  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b9e30
//
// 006b9e30  8b442408             mov eax, dword ptr [esp + 8]
// 006b9e34  57                   push edi
// 006b9e35  8b7c2408             mov edi, dword ptr [esp + 8]
// 006b9e39  8bcf                 mov ecx, edi
// 006b9e3b  e890edffff           call 0x6b8bd0
// 006b9e40  83780806             cmp dword ptr [eax + 8], 6
// 006b9e44  7404                 je 0x6b9e4a
// 006b9e46  33c0                 xor eax, eax
// 006b9e48  5f                   pop edi
// 006b9e49  c3                   ret 
// 006b9e4a  8b00                 mov eax, dword ptr [eax]
// 006b9e4c  80780600             cmp byte ptr [eax + 6], 0
// 006b9e50  56                   push esi
// 006b9e51  741f                 je 0x6b9e72
// 006b9e53  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 006b9e57  83f901               cmp ecx, 1
// 006b9e5a  7c56                 jl 0x6b9eb2
// 006b9e5c  0fb65007             movzx edx, byte ptr [eax + 7]
// 006b9e60  3bca                 cmp ecx, edx
// 006b9e62  7f4e                 jg 0x6b9eb2
// 006b9e64  c1e104               shl ecx, 4
// 006b9e67  8d4c0108             lea ecx, [ecx + eax + 8]
// 006b9e6b  b816d28a00           mov eax, 0x8ad216
// 006b9e70  eb26                 jmp 0x6b9e98
// 006b9e72  8b542414             mov edx, dword ptr [esp + 0x14]
// 006b9e76  83fa01               cmp edx, 1
// 006b9e79  8b7010               mov esi, dword ptr [eax + 0x10]
// 006b9e7c  7c34                 jl 0x6b9eb2
// 006b9e7e  3b5624               cmp edx, dword ptr [esi + 0x24]
// 006b9e81  7f2f                 jg 0x6b9eb2
// 006b9e83  8b449010             mov eax, dword ptr [eax + edx*4 + 0x10]
// 006b9e87  8b4808               mov ecx, dword ptr [eax + 8]
// 006b9e8a  8b461c               mov eax, dword ptr [esi + 0x1c]
// 006b9e8d  8b4490fc             mov eax, dword ptr [eax + edx*4 - 4]
// 006b9e91  83c010               add eax, 0x10
// 006b9e94  85c0                 test eax, eax
// 006b9e96  7417                 je 0x6b9eaf
// 006b9e98  8b31                 mov esi, dword ptr [ecx]
// 006b9e9a  8b5708               mov edx, dword ptr [edi + 8]
// 006b9e9d  8932                 mov dword ptr [edx], esi
// 006b9e9f  8b7104               mov esi, dword ptr [ecx + 4]
// 006b9ea2  897204               mov dword ptr [edx + 4], esi
// 006b9ea5  8b4908               mov ecx, dword ptr [ecx + 8]
// 006b9ea8  894a08               mov dword ptr [edx + 8], ecx
// 006b9eab  83470810             add dword ptr [edi + 8], 0x10
// 006b9eaf  5e                   pop esi
// 006b9eb0  5f                   pop edi
// 006b9eb1  c3                   ret 
// 006b9eb2  5e                   pop esi
// 006b9eb3  33c0                 xor eax, eax
// 006b9eb5  5f                   pop edi
// 006b9eb6  c3                   ret 
// library lua-5.1/lapi.c (function _lua_getupvalue)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
