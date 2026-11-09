// from server: 100% by auto
// roc 2009-12 00789850  unit: RBX::UniversalTool  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00789850
//
// 00789850  8b442408             mov eax, dword ptr [esp + 8]
// 00789854  57                   push edi
// 00789855  8b7c2408             mov edi, dword ptr [esp + 8]
// 00789859  8bcf                 mov ecx, edi
// 0078985b  e890edffff           call 0x7885f0
// 00789860  83780806             cmp dword ptr [eax + 8], 6
// 00789864  7404                 je 0x78986a
// 00789866  33c0                 xor eax, eax
// 00789868  5f                   pop edi
// 00789869  c3                   ret 
// 0078986a  8b00                 mov eax, dword ptr [eax]
// 0078986c  80780600             cmp byte ptr [eax + 6], 0
// 00789870  56                   push esi
// 00789871  741f                 je 0x789892
// 00789873  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00789877  83f901               cmp ecx, 1
// 0078987a  7c56                 jl 0x7898d2
// 0078987c  0fb65007             movzx edx, byte ptr [eax + 7]
// 00789880  3bca                 cmp ecx, edx
// 00789882  7f4e                 jg 0x7898d2
// 00789884  c1e104               shl ecx, 4
// 00789887  8d4c0108             lea ecx, [ecx + eax + 8]
// 0078988b  b856fd9900           mov eax, 0x99fd56
// 00789890  eb26                 jmp 0x7898b8
// 00789892  8b542414             mov edx, dword ptr [esp + 0x14]
// 00789896  83fa01               cmp edx, 1
// 00789899  8b7010               mov esi, dword ptr [eax + 0x10]
// 0078989c  7c34                 jl 0x7898d2
// 0078989e  3b5624               cmp edx, dword ptr [esi + 0x24]
// 007898a1  7f2f                 jg 0x7898d2
// 007898a3  8b449010             mov eax, dword ptr [eax + edx*4 + 0x10]
// 007898a7  8b4808               mov ecx, dword ptr [eax + 8]
// 007898aa  8b461c               mov eax, dword ptr [esi + 0x1c]
// 007898ad  8b4490fc             mov eax, dword ptr [eax + edx*4 - 4]
// 007898b1  83c010               add eax, 0x10
// 007898b4  85c0                 test eax, eax
// 007898b6  7417                 je 0x7898cf
// 007898b8  8b31                 mov esi, dword ptr [ecx]
// 007898ba  8b5708               mov edx, dword ptr [edi + 8]
// 007898bd  8932                 mov dword ptr [edx], esi
// 007898bf  8b7104               mov esi, dword ptr [ecx + 4]
// 007898c2  897204               mov dword ptr [edx + 4], esi
// 007898c5  8b4908               mov ecx, dword ptr [ecx + 8]
// 007898c8  894a08               mov dword ptr [edx + 8], ecx
// 007898cb  83470810             add dword ptr [edi + 8], 0x10
// 007898cf  5e                   pop esi
// 007898d0  5f                   pop edi
// 007898d1  c3                   ret 
// 007898d2  5e                   pop esi
// 007898d3  33c0                 xor eax, eax
// 007898d5  5f                   pop edi
// 007898d6  c3                   ret 
// library lua-5.1/lapi.c (function _lua_getupvalue)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
