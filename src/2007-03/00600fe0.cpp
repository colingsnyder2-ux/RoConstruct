// from server: 100% by auto
// roc 2007-03 00600fe0  unit: seg_00600000  size: 140 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00600fe0
//
// 00600fe0  8b4638               mov eax, dword ptr [esi + 0x38]
// 00600fe3  8b08                 mov ecx, dword ptr [eax]
// 00600fe5  85c9                 test ecx, ecx
// 00600fe7  57                   push edi
// 00600fe8  8b3e                 mov edi, dword ptr [esi]
// 00600fea  8d51ff               lea edx, [ecx - 1]
// 00600fed  8910                 mov dword ptr [eax], edx
// 00600fef  7611                 jbe 0x601002
// 00600ff1  8b4e38               mov ecx, dword ptr [esi + 0x38]
// 00600ff4  8b5104               mov edx, dword ptr [ecx + 4]
// 00600ff7  0fb602               movzx eax, byte ptr [edx]
// 00600ffa  83c201               add edx, 1
// 00600ffd  895104               mov dword ptr [ecx + 4], edx
// 00601000  eb0c                 jmp 0x60100e
// 00601002  8b4638               mov eax, dword ptr [esi + 0x38]
// 00601005  50                   push eax
// 00601006  e895bcffff           call 0x5fcca0
// 0060100b  83c404               add esp, 4
// 0060100e  83f80a               cmp eax, 0xa
// 00601011  8906                 mov dword ptr [esi], eax
// 00601013  7405                 je 0x60101a
// 00601015  83f80d               cmp eax, 0xd
// 00601018  7531                 jne 0x60104b
// 0060101a  3bc7                 cmp eax, edi
// 0060101c  742d                 je 0x60104b
// 0060101e  8b4638               mov eax, dword ptr [esi + 0x38]
// 00601021  8b08                 mov ecx, dword ptr [eax]
// 00601023  85c9                 test ecx, ecx
// 00601025  8d51ff               lea edx, [ecx - 1]
// 00601028  8910                 mov dword ptr [eax], edx
// 0060102a  7611                 jbe 0x60103d
// 0060102c  8b4e38               mov ecx, dword ptr [esi + 0x38]
// 0060102f  8b5104               mov edx, dword ptr [ecx + 4]
// 00601032  0fb602               movzx eax, byte ptr [edx]
// 00601035  83c201               add edx, 1
// 00601038  895104               mov dword ptr [ecx + 4], edx
// 0060103b  eb0c                 jmp 0x601049
// 0060103d  8b4638               mov eax, dword ptr [esi + 0x38]
// 00601040  50                   push eax
// 00601041  e85abcffff           call 0x5fcca0
// 00601046  83c404               add esp, 4
// 00601049  8906                 mov dword ptr [esi], eax
// 0060104b  83460401             add dword ptr [esi + 4], 1
// 0060104f  817e04fdffff7f       cmp dword ptr [esi + 4], 0x7ffffffd
// 00601056  5f                   pop edi
// 00601057  7c12                 jl 0x60106b
// 00601059  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0060105c  51                   push ecx
// 0060105d  68240a7c00           push 0x7c0a24
// 00601062  56                   push esi
// 00601063  e868feffff           call 0x600ed0
// 00601068  83c40c               add esp, 0xc
// 0060106b  c3                   ret 
// library lua-5.1.1/llex.c (function _inclinenumber)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 llex.c
