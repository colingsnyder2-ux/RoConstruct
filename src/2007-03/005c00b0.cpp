// from server: 100% by auto
// roc 2007-03 005c00b0  unit: seg_005c0000  size: 218 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c00b0
//
// 005c00b0  53                   push ebx
// 005c00b1  56                   push esi
// 005c00b2  57                   push edi
// 005c00b3  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 005c00b7  8b07                 mov eax, dword ptr [edi]
// 005c00b9  50                   push eax
// 005c00ba  e821cc0300           call 0x5fcce0
// 005c00bf  8b742414             mov esi, dword ptr [esp + 0x14]
// 005c00c3  8bd8                 mov ebx, eax
// 005c00c5  8b4610               mov eax, dword ptr [esi + 0x10]
// 005c00c8  8b4844               mov ecx, dword ptr [eax + 0x44]
// 005c00cb  83c404               add esp, 4
// 005c00ce  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 005c00d1  7209                 jb 0x5c00dc
// 005c00d3  56                   push esi
// 005c00d4  e8d7960300           call 0x5f97b0
// 005c00d9  83c404               add esp, 4
// 005c00dc  83fb1b               cmp ebx, 0x1b
// 005c00df  b8400d6000           mov eax, 0x600d40
// 005c00e4  7405                 je 0x5c00eb
// 005c00e6  b850026000           mov eax, 0x600250
// 005c00eb  8b5710               mov edx, dword ptr [edi + 0x10]
// 005c00ee  52                   push edx
// 005c00ef  8b17                 mov edx, dword ptr [edi]
// 005c00f1  8d4f04               lea ecx, [edi + 4]
// 005c00f4  51                   push ecx
// 005c00f5  52                   push edx
// 005c00f6  56                   push esi
// 005c00f7  ffd0                 call eax
// 005c00f9  8bf8                 mov edi, eax
// 005c00fb  8b4648               mov eax, dword ptr [esi + 0x48]
// 005c00fe  0fb64f48             movzx ecx, byte ptr [edi + 0x48]
// 005c0102  50                   push eax
// 005c0103  51                   push ecx
// 005c0104  56                   push esi
// 005c0105  e8f6c70300           call 0x5fc900
// 005c010a  33db                 xor ebx, ebx
// 005c010c  83c41c               add esp, 0x1c
// 005c010f  897810               mov dword ptr [eax + 0x10], edi
// 005c0112  385f48               cmp byte ptr [edi + 0x48], bl
// 005c0115  89442414             mov dword ptr [esp + 0x14], eax
// 005c0119  7624                 jbe 0x5c013f
// 005c011b  55                   push ebp
// 005c011c  8d6814               lea ebp, [eax + 0x14]
// 005c011f  90                   nop 
// 005c0120  56                   push esi
// 005c0121  e83ac80300           call 0x5fc960
// 005c0126  894500               mov dword ptr [ebp], eax
// 005c0129  0fb65748             movzx edx, byte ptr [edi + 0x48]
// 005c012d  83c301               add ebx, 1
// 005c0130  83c404               add esp, 4
// 005c0133  83c504               add ebp, 4
// 005c0136  3bda                 cmp ebx, edx
// 005c0138  7ce6                 jl 0x5c0120
// 005c013a  8b442418             mov eax, dword ptr [esp + 0x18]
// 005c013e  5d                   pop ebp
// 005c013f  8b4e08               mov ecx, dword ptr [esi + 8]
// 005c0142  8901                 mov dword ptr [ecx], eax
// 005c0144  c7410806000000       mov dword ptr [ecx + 8], 6
// 005c014b  8b461c               mov eax, dword ptr [esi + 0x1c]
// 005c014e  2b4608               sub eax, dword ptr [esi + 8]
// 005c0151  bf10000000           mov edi, 0x10
// 005c0156  3bc7                 cmp eax, edi
// 005c0158  7f29                 jg 0x5c0183
// 005c015a  8b462c               mov eax, dword ptr [esi + 0x2c]
// 005c015d  83f801               cmp eax, 1
// 005c0160  7c14                 jl 0x5c0176
// 005c0162  8d0c00               lea ecx, [eax + eax]
// 005c0165  51                   push ecx
// 005c0166  56                   push esi
// 005c0167  e8a4faffff           call 0x5bfc10
// 005c016c  83c408               add esp, 8
// 005c016f  017e08               add dword ptr [esi + 8], edi
// 005c0172  5f                   pop edi
// 005c0173  5e                   pop esi
// 005c0174  5b                   pop ebx
// 005c0175  c3                   ret 
// 005c0176  83c001               add eax, 1
// 005c0179  50                   push eax
// 005c017a  56                   push esi
// 005c017b  e890faffff           call 0x5bfc10
// 005c0180  83c408               add esp, 8
// 005c0183  017e08               add dword ptr [esi + 8], edi
// 005c0186  5f                   pop edi
// 005c0187  5e                   pop esi
// 005c0188  5b                   pop ebx
// 005c0189  c3                   ret 
// library lua-5.1.1/ldo.c (function _f_parser)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ldo.c
