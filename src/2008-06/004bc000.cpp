// from server: 100% by auto
// roc 2008-06 004bc000  unit: ProfiledRakPeer  size: 130 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bc000
//
// 004bc000  53                   push ebx
// 004bc001  55                   push ebp
// 004bc002  56                   push esi
// 004bc003  8bf1                 mov esi, ecx
// 004bc005  33c0                 xor eax, eax
// 004bc007  33ed                 xor ebp, ebp
// 004bc009  57                   push edi
// 004bc00a  663b4608             cmp ax, word ptr [esi + 8]
// 004bc00e  7360                 jae 0x4bc070
// 004bc010  8a5c241c             mov bl, byte ptr [esp + 0x1c]
// 004bc014  33ff                 xor edi, edi
// 004bc016  eb08                 jmp 0x4bc020
// 004bc018  8da42400000000       lea esp, [esp]
// 004bc01f  90                   nop 
// 004bc020  8b8e2c020000         mov ecx, dword ptr [esi + 0x22c]
// 004bc026  803c3900             cmp byte ptr [ecx + edi], 0
// 004bc02a  8d0439               lea eax, [ecx + edi]
// 004bc02d  7432                 je 0x4bc061
// 004bc02f  83b84808000008       cmp dword ptr [eax + 0x848], 8
// 004bc036  7529                 jne 0x4bc061
// 004bc038  84db                 test bl, bl
// 004bc03a  750f                 jne 0x4bc04b
// 004bc03c  8d542414             lea edx, [esp + 0x14]
// 004bc040  52                   push edx
// 004bc041  8d4804               lea ecx, [eax + 4]
// 004bc044  e8d7d7feff           call 0x4a9820
// 004bc049  eb12                 jmp 0x4bc05d
// 004bc04b  80fb01               cmp bl, 1
// 004bc04e  7511                 jne 0x4bc061
// 004bc050  8d4c2414             lea ecx, [esp + 0x14]
// 004bc054  51                   push ecx
// 004bc055  8d4804               lea ecx, [eax + 4]
// 004bc058  e8f3d7feff           call 0x4a9850
// 004bc05d  84c0                 test al, al
// 004bc05f  7518                 jne 0x4bc079
// 004bc061  0fb75608             movzx edx, word ptr [esi + 8]
// 004bc065  45                   inc ebp
// 004bc066  81c750080000         add edi, 0x850
// 004bc06c  3bea                 cmp ebp, edx
// 004bc06e  72b0                 jb 0x4bc020
// 004bc070  5f                   pop edi
// 004bc071  5e                   pop esi
// 004bc072  5d                   pop ebp
// 004bc073  32c0                 xor al, al
// 004bc075  5b                   pop ebx
// 004bc076  c20c00               ret 0xc
// 004bc079  5f                   pop edi
// 004bc07a  5e                   pop esi
// 004bc07b  5d                   pop ebp
// 004bc07c  b001                 mov al, 1
// 004bc07e  5b                   pop ebx
// 004bc07f  c20c00               ret 0xc
// library openrbx-raknet/RakPeer.cpp (function ?ValidSendTarget@RakPeer@@IAE_NUSystemAddress@@_N@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
