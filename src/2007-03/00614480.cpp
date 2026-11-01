// from server: 100% by auto
// roc 2007-03 00614480  unit: seg_00610000  size: 122 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00614480
//
// 00614480  83f801               cmp eax, 1
// 00614483  8b12                 mov edx, dword ptr [edx]
// 00614485  8b520c               mov edx, dword ptr [edx + 0xc]
// 00614488  56                   push esi
// 00614489  8d1482               lea edx, [edx + eax*4]
// 0061448c  7c12                 jl 0x6144a0
// 0061448e  8b42fc               mov eax, dword ptr [edx - 4]
// 00614491  8d72fc               lea esi, [edx - 4]
// 00614494  83e03f               and eax, 0x3f
// 00614497  f680ac087c0080       test byte ptr [eax + 0x7c08ac], 0x80
// 0061449e  7502                 jne 0x6144a2
// 006144a0  8bf2                 mov esi, edx
// 006144a2  8b06                 mov eax, dword ptr [esi]
// 006144a4  8bd0                 mov edx, eax
// 006144a6  83e23f               and edx, 0x3f
// 006144a9  80fa1b               cmp dl, 0x1b
// 006144ac  7404                 je 0x6144b2
// 006144ae  33c0                 xor eax, eax
// 006144b0  5e                   pop esi
// 006144b1  c3                   ret 
// 006144b2  81f9ff000000         cmp ecx, 0xff
// 006144b8  741f                 je 0x6144d9
// 006144ba  8bd0                 mov edx, eax
// 006144bc  c1ea17               shr edx, 0x17
// 006144bf  3bca                 cmp ecx, edx
// 006144c1  7416                 je 0x6144d9
// 006144c3  c1e106               shl ecx, 6
// 006144c6  33c8                 xor ecx, eax
// 006144c8  81e1c03f0000         and ecx, 0x3fc0
// 006144ce  33c8                 xor ecx, eax
// 006144d0  890e                 mov dword ptr [esi], ecx
// 006144d2  b801000000           mov eax, 1
// 006144d7  5e                   pop esi
// 006144d8  c3                   ret 
// 006144d9  8bc8                 mov ecx, eax
// 006144db  81e1ffffb5ff         and ecx, 0xffb5ffff
// 006144e1  81c900003400         or ecx, 0x340000
// 006144e7  2500c07f00           and eax, 0x7fc000
// 006144ec  c1e911               shr ecx, 0x11
// 006144ef  0bc8                 or ecx, eax
// 006144f1  890e                 mov dword ptr [esi], ecx
// 006144f3  b801000000           mov eax, 1
// 006144f8  5e                   pop esi
// 006144f9  c3                   ret 
// library lua-5.1.1/lcode.c (function _patchtestreg)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lcode.c
