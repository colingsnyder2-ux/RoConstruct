// from server: 100% by auto
// roc 2007-03 005fff30  unit: seg_005f0000  size: 288 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fff30
//
// 005fff30  83ec18               sub esp, 0x18
// 005fff33  53                   push ebx
// 005fff34  56                   push esi
// 005fff35  8bf0                 mov esi, eax
// 005fff37  8b5e30               mov ebx, dword ptr [esi + 0x30]
// 005fff3a  56                   push esi
// 005fff3b  e860240000           call 0x6023a0
// 005fff40  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 005fff43  8d81fcfeffff         lea eax, [ecx - 0x104]
// 005fff49  83c404               add esp, 4
// 005fff4c  83f81b               cmp eax, 0x1b
// 005fff4f  770e                 ja 0x5fff5f
// 005fff51  0fb68034006000       movzx eax, byte ptr [eax + 0x600034]
// 005fff58  ff24852c006000       jmp dword ptr [eax*4 + 0x60002c]
// 005fff5f  83f93b               cmp ecx, 0x3b
// 005fff62  0f84ad000000         je 0x600015
// 005fff68  57                   push edi
// 005fff69  8d7c240c             lea edi, [esp + 0xc]
// 005fff6d  e8eee4ffff           call 0x5fe460
// 005fff72  8bf0                 mov esi, eax
// 005fff74  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005fff78  83f80d               cmp eax, 0xd
// 005fff7b  5f                   pop edi
// 005fff7c  744c                 je 0x5fffca
// 005fff7e  83f80e               cmp eax, 0xe
// 005fff81  7447                 je 0x5fffca
// 005fff83  83fe01               cmp esi, 1
// 005fff86  751f                 jne 0x5fffa7
// 005fff88  8d4c2408             lea ecx, [esp + 8]
// 005fff8c  51                   push ecx
// 005fff8d  53                   push ebx
// 005fff8e  e8ad520100           call 0x615240
// 005fff93  83c408               add esp, 8
// 005fff96  56                   push esi
// 005fff97  50                   push eax
// 005fff98  53                   push ebx
// 005fff99  e8e24d0100           call 0x614d80
// 005fff9e  83c40c               add esp, 0xc
// 005fffa1  5e                   pop esi
// 005fffa2  5b                   pop ebx
// 005fffa3  83c418               add esp, 0x18
// 005fffa6  c3                   ret 
// 005fffa7  8d542408             lea edx, [esp + 8]
// 005fffab  52                   push edx
// 005fffac  53                   push ebx
// 005fffad  e80e520100           call 0x6151c0
// 005fffb2  0fb64332             movzx eax, byte ptr [ebx + 0x32]
// 005fffb6  83c408               add esp, 8
// 005fffb9  56                   push esi
// 005fffba  50                   push eax
// 005fffbb  53                   push ebx
// 005fffbc  e8bf4d0100           call 0x614d80
// 005fffc1  83c40c               add esp, 0xc
// 005fffc4  5e                   pop esi
// 005fffc5  5b                   pop ebx
// 005fffc6  83c418               add esp, 0x18
// 005fffc9  c3                   ret 
// 005fffca  6aff                 push -1
// 005fffcc  8d44240c             lea eax, [esp + 0xc]
// 005fffd0  50                   push eax
// 005fffd1  53                   push ebx
// 005fffd2  e8e9480100           call 0x6148c0
// 005fffd7  83c40c               add esp, 0xc
// 005fffda  837c24080d           cmp dword ptr [esp + 8], 0xd
// 005fffdf  751c                 jne 0x5ffffd
// 005fffe1  83fe01               cmp esi, 1
// 005fffe4  7517                 jne 0x5ffffd
// 005fffe6  8b0b                 mov ecx, dword ptr [ebx]
// 005fffe8  8b510c               mov edx, dword ptr [ecx + 0xc]
// 005fffeb  8b442410             mov eax, dword ptr [esp + 0x10]
// 005fffef  8b0c82               mov ecx, dword ptr [edx + eax*4]
// 005ffff2  8d0482               lea eax, [edx + eax*4]
// 005ffff5  83e1dd               and ecx, 0xffffffdd
// 005ffff8  83c91d               or ecx, 0x1d
// 005ffffb  8908                 mov dword ptr [eax], ecx
// 005ffffd  0fb64332             movzx eax, byte ptr [ebx + 0x32]
// 00600001  83ceff               or esi, 0xffffffff
// 00600004  56                   push esi
// 00600005  50                   push eax
// 00600006  53                   push ebx
// 00600007  e8744d0100           call 0x614d80
// 0060000c  83c40c               add esp, 0xc
// 0060000f  5e                   pop esi
// 00600010  5b                   pop ebx
// 00600011  83c418               add esp, 0x18
// 00600014  c3                   ret 
// 00600015  33f6                 xor esi, esi
// 00600017  33c0                 xor eax, eax
// 00600019  56                   push esi
// 0060001a  50                   push eax
// 0060001b  53                   push ebx
// 0060001c  e85f4d0100           call 0x614d80
// 00600021  83c40c               add esp, 0xc
// 00600024  5e                   pop esi
// 00600025  5b                   pop ebx
// 00600026  83c418               add esp, 0x18
// 00600029  c3                   ret 
// 0060002a  8bff                 mov edi, edi
// 0060002c  150060005f           adc eax, 0x5f006000
// 00600031  ff5f00               call ptr [edi]
// 00600034  0000                 add byte ptr [eax], al
// 00600036  0001                 add byte ptr [ecx], al
// 00600038  0101                 add dword ptr [ecx], eax
// 0060003a  0101                 add dword ptr [ecx], eax
// 0060003c  0101                 add dword ptr [ecx], eax
// 0060003e  0101                 add dword ptr [ecx], eax
// 00600040  0101                 add dword ptr [ecx], eax
// 00600042  0101                 add dword ptr [ecx], eax
// 00600044  0001                 add byte ptr [ecx], al
// 00600046  0101                 add dword ptr [ecx], eax
// 00600048  0101                 add dword ptr [ecx], eax
// 0060004a  0101                 add dword ptr [ecx], eax
// 0060004c  0101                 add dword ptr [ecx], eax
// 0060004e  0100                 add dword ptr [eax], eax
// library lua-5.1.1/lparser.c (function _retstat)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lparser.c
