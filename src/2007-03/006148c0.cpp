// from server: 100% by auto
// roc 2007-03 006148c0  unit: seg_00610000  size: 133 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006148c0
//
// 006148c0  8b542408             mov edx, dword ptr [esp + 8]
// 006148c4  8b02                 mov eax, dword ptr [edx]
// 006148c6  83f80d               cmp eax, 0xd
// 006148c9  7525                 jne 0x6148f0
// 006148cb  8b4208               mov eax, dword ptr [edx + 8]
// 006148ce  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006148d2  8b11                 mov edx, dword ptr [ecx]
// 006148d4  8b4a0c               mov ecx, dword ptr [edx + 0xc]
// 006148d7  8b54240c             mov edx, dword ptr [esp + 0xc]
// 006148db  83c201               add edx, 1
// 006148de  c1e20e               shl edx, 0xe
// 006148e1  331481               xor edx, dword ptr [ecx + eax*4]
// 006148e4  8d0481               lea eax, [ecx + eax*4]
// 006148e7  81e200c07f00         and edx, 0x7fc000
// 006148ed  3110                 xor dword ptr [eax], edx
// 006148ef  c3                   ret 
// 006148f0  83f80e               cmp eax, 0xe
// 006148f3  754f                 jne 0x614944
// 006148f5  8b4a08               mov ecx, dword ptr [edx + 8]
// 006148f8  8b442404             mov eax, dword ptr [esp + 4]
// 006148fc  56                   push esi
// 006148fd  8b30                 mov esi, dword ptr [eax]
// 006148ff  8b760c               mov esi, dword ptr [esi + 0xc]
// 00614902  8d0c8e               lea ecx, [esi + ecx*4]
// 00614905  8b742410             mov esi, dword ptr [esp + 0x10]
// 00614909  57                   push edi
// 0061490a  8b39                 mov edi, dword ptr [ecx]
// 0061490c  83c601               add esi, 1
// 0061490f  c1e617               shl esi, 0x17
// 00614912  81e7ffff7f00         and edi, 0x7fffff
// 00614918  33f7                 xor esi, edi
// 0061491a  8931                 mov dword ptr [ecx], esi
// 0061491c  8b5208               mov edx, dword ptr [edx + 8]
// 0061491f  8b08                 mov ecx, dword ptr [eax]
// 00614921  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 00614924  8d0c91               lea ecx, [ecx + edx*4]
// 00614927  8b5024               mov edx, dword ptr [eax + 0x24]
// 0061492a  c1e206               shl edx, 6
// 0061492d  3311                 xor edx, dword ptr [ecx]
// 0061492f  6a01                 push 1
// 00614931  81e2c03f0000         and edx, 0x3fc0
// 00614937  3111                 xor dword ptr [ecx], edx
// 00614939  50                   push eax
// 0061493a  e8a1fdffff           call 0x6146e0
// 0061493f  83c408               add esp, 8
// 00614942  5f                   pop edi
// 00614943  5e                   pop esi
// 00614944  c3                   ret 
// library lua-5.1.1/lcode.c (function _luaK_setreturns)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lcode.c
