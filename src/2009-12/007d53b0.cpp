// from server: 100% by auto
// roc 2009-12 007d53b0  unit: seg_007d0000  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d53b0
//
// 007d53b0  8b4638               mov eax, dword ptr [esi + 0x38]
// 007d53b3  8b08                 mov ecx, dword ptr [eax]
// 007d53b5  57                   push edi
// 007d53b6  8b3e                 mov edi, dword ptr [esi]
// 007d53b8  8d51ff               lea edx, [ecx - 1]
// 007d53bb  8910                 mov dword ptr [eax], edx
// 007d53bd  85c9                 test ecx, ecx
// 007d53bf  760f                 jbe 0x7d53d0
// 007d53c1  8b4e38               mov ecx, dword ptr [esi + 0x38]
// 007d53c4  8b5104               mov edx, dword ptr [ecx + 4]
// 007d53c7  0fb602               movzx eax, byte ptr [edx]
// 007d53ca  42                   inc edx
// 007d53cb  895104               mov dword ptr [ecx + 4], edx
// 007d53ce  eb0c                 jmp 0x7d53dc
// 007d53d0  8b4638               mov eax, dword ptr [esi + 0x38]
// 007d53d3  50                   push eax
// 007d53d4  e8f7bcffff           call 0x7d10d0
// 007d53d9  83c404               add esp, 4
// 007d53dc  8906                 mov dword ptr [esi], eax
// 007d53de  83f80a               cmp eax, 0xa
// 007d53e1  7405                 je 0x7d53e8
// 007d53e3  83f80d               cmp eax, 0xd
// 007d53e6  752f                 jne 0x7d5417
// 007d53e8  3bc7                 cmp eax, edi
// 007d53ea  742b                 je 0x7d5417
// 007d53ec  8b4638               mov eax, dword ptr [esi + 0x38]
// 007d53ef  8b08                 mov ecx, dword ptr [eax]
// 007d53f1  8d51ff               lea edx, [ecx - 1]
// 007d53f4  8910                 mov dword ptr [eax], edx
// 007d53f6  85c9                 test ecx, ecx
// 007d53f8  760f                 jbe 0x7d5409
// 007d53fa  8b4e38               mov ecx, dword ptr [esi + 0x38]
// 007d53fd  8b5104               mov edx, dword ptr [ecx + 4]
// 007d5400  0fb602               movzx eax, byte ptr [edx]
// 007d5403  42                   inc edx
// 007d5404  895104               mov dword ptr [ecx + 4], edx
// 007d5407  eb0c                 jmp 0x7d5415
// 007d5409  8b4638               mov eax, dword ptr [esi + 0x38]
// 007d540c  50                   push eax
// 007d540d  e8bebcffff           call 0x7d10d0
// 007d5412  83c404               add esp, 4
// 007d5415  8906                 mov dword ptr [esi], eax
// 007d5417  ff4604               inc dword ptr [esi + 4]
// 007d541a  817e04fdffff7f       cmp dword ptr [esi + 4], 0x7ffffffd
// 007d5421  5f                   pop edi
// 007d5422  7c12                 jl 0x7d5436
// 007d5424  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 007d5427  51                   push ecx
// 007d5428  68f4f39e00           push 0x9ef3f4
// 007d542d  56                   push esi
// 007d542e  e86dfeffff           call 0x7d52a0
// 007d5433  83c40c               add esp, 0xc
// 007d5436  c3                   ret 
// library lua-5.1/llex.c (function _inclinenumber)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 llex.c
