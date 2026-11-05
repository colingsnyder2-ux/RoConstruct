// from server: 100% by auto
// roc 2011-06 00763410  unit: seg_00760000  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00763410
//
// 00763410  8b442408             mov eax, dword ptr [esp + 8]
// 00763414  57                   push edi
// 00763415  8b7c2408             mov edi, dword ptr [esp + 8]
// 00763419  8bcf                 mov ecx, edi
// 0076341b  e890edffff           call 0x7621b0
// 00763420  83780806             cmp dword ptr [eax + 8], 6
// 00763424  7404                 je 0x76342a
// 00763426  33c0                 xor eax, eax
// 00763428  5f                   pop edi
// 00763429  c3                   ret 
// 0076342a  8b00                 mov eax, dword ptr [eax]
// 0076342c  80780600             cmp byte ptr [eax + 6], 0
// 00763430  56                   push esi
// 00763431  741f                 je 0x763452
// 00763433  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00763437  83f901               cmp ecx, 1
// 0076343a  7c56                 jl 0x763492
// 0076343c  0fb65007             movzx edx, byte ptr [eax + 7]
// 00763440  3bca                 cmp ecx, edx
// 00763442  7f4e                 jg 0x763492
// 00763444  c1e104               shl ecx, 4
// 00763447  8d4c0108             lea ecx, [ecx + eax + 8]
// 0076344b  b8cabea500           mov eax, 0xa5beca
// 00763450  eb26                 jmp 0x763478
// 00763452  8b542414             mov edx, dword ptr [esp + 0x14]
// 00763456  83fa01               cmp edx, 1
// 00763459  8b7010               mov esi, dword ptr [eax + 0x10]
// 0076345c  7c34                 jl 0x763492
// 0076345e  3b5624               cmp edx, dword ptr [esi + 0x24]
// 00763461  7f2f                 jg 0x763492
// 00763463  8b449010             mov eax, dword ptr [eax + edx*4 + 0x10]
// 00763467  8b4808               mov ecx, dword ptr [eax + 8]
// 0076346a  8b461c               mov eax, dword ptr [esi + 0x1c]
// 0076346d  8b4490fc             mov eax, dword ptr [eax + edx*4 - 4]
// 00763471  83c010               add eax, 0x10
// 00763474  85c0                 test eax, eax
// 00763476  7417                 je 0x76348f
// 00763478  8b31                 mov esi, dword ptr [ecx]
// 0076347a  8b5708               mov edx, dword ptr [edi + 8]
// 0076347d  8932                 mov dword ptr [edx], esi
// 0076347f  8b7104               mov esi, dword ptr [ecx + 4]
// 00763482  897204               mov dword ptr [edx + 4], esi
// 00763485  8b4908               mov ecx, dword ptr [ecx + 8]
// 00763488  894a08               mov dword ptr [edx + 8], ecx
// 0076348b  83470810             add dword ptr [edi + 8], 0x10
// 0076348f  5e                   pop esi
// 00763490  5f                   pop edi
// 00763491  c3                   ret 
// 00763492  5e                   pop esi
// 00763493  33c0                 xor eax, eax
// 00763495  5f                   pop edi
// 00763496  c3                   ret 
// library lua-5.1/lapi.c (function _lua_getupvalue)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
