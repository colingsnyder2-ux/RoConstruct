// from server: 100% by auto
// roc 2007-03 00614420  unit: seg_00610000  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00614420
//
// 00614420  83faff               cmp edx, -1
// 00614423  56                   push esi
// 00614424  57                   push edi
// 00614425  7449                 je 0x614470
// 00614427  8b08                 mov ecx, dword ptr [eax]
// 00614429  8b790c               mov edi, dword ptr [ecx + 0xc]
// 0061442c  8d642400             lea esp, [esp]
// 00614430  83fa01               cmp edx, 1
// 00614433  8d0497               lea eax, [edi + edx*4]
// 00614436  7c14                 jl 0x61444c
// 00614438  8b70fc               mov esi, dword ptr [eax - 4]
// 0061443b  8d48fc               lea ecx, [eax - 4]
// 0061443e  83e63f               and esi, 0x3f
// 00614441  f686ac087c0080       test byte ptr [esi + 0x7c08ac], 0x80
// 00614448  8bf1                 mov esi, ecx
// 0061444a  7502                 jne 0x61444e
// 0061444c  8bf0                 mov esi, eax
// 0061444e  8b0e                 mov ecx, dword ptr [esi]
// 00614450  83e13f               and ecx, 0x3f
// 00614453  80f91b               cmp cl, 0x1b
// 00614456  751d                 jne 0x614475
// 00614458  8b00                 mov eax, dword ptr [eax]
// 0061445a  c1e80e               shr eax, 0xe
// 0061445d  2dffff0100           sub eax, 0x1ffff
// 00614462  83f8ff               cmp eax, -1
// 00614465  7409                 je 0x614470
// 00614467  8d540201             lea edx, [edx + eax + 1]
// 0061446b  83faff               cmp edx, -1
// 0061446e  75c0                 jne 0x614430
// 00614470  5f                   pop edi
// 00614471  33c0                 xor eax, eax
// 00614473  5e                   pop esi
// 00614474  c3                   ret 
// 00614475  5f                   pop edi
// 00614476  b801000000           mov eax, 1
// 0061447b  5e                   pop esi
// 0061447c  c3                   ret 
// library lua-5.1.1/lcode.c (function _need_value)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lcode.c
