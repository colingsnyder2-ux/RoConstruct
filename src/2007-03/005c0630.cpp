// from server: 100% by auto
// roc 2007-03 005c0630  unit: seg_005c0000  size: 252 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c0630
//
// 005c0630  83ec08               sub esp, 8
// 005c0633  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 005c0637  53                   push ebx
// 005c0638  55                   push ebp
// 005c0639  56                   push esi
// 005c063a  8b742418             mov esi, dword ptr [esp + 0x18]
// 005c063e  0fb74634             movzx eax, word ptr [esi + 0x34]
// 005c0642  8a4e37               mov cl, byte ptr [esi + 0x37]
// 005c0645  8b5e14               mov ebx, dword ptr [esi + 0x14]
// 005c0648  2b5e28               sub ebx, dword ptr [esi + 0x28]
// 005c064b  57                   push edi
// 005c064c  8b7e74               mov edi, dword ptr [esi + 0x74]
// 005c064f  89442414             mov dword ptr [esp + 0x14], eax
// 005c0653  8b442424             mov eax, dword ptr [esp + 0x24]
// 005c0657  884c241c             mov byte ptr [esp + 0x1c], cl
// 005c065b  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 005c065f  50                   push eax
// 005c0660  51                   push ecx
// 005c0661  56                   push esi
// 005c0662  897c241c             mov dword ptr [esp + 0x1c], edi
// 005c0666  895674               mov dword ptr [esi + 0x74], edx
// 005c0669  e842f4ffff           call 0x5bfab0
// 005c066e  8be8                 mov ebp, eax
// 005c0670  83c40c               add esp, 0xc
// 005c0673  85ed                 test ebp, ebp
// 005c0675  0f84a6000000         je 0x5c0721
// 005c067b  8b7e20               mov edi, dword ptr [esi + 0x20]
// 005c067e  037c2428             add edi, dword ptr [esp + 0x28]
// 005c0682  57                   push edi
// 005c0683  56                   push esi
// 005c0684  e8e7c30300           call 0x5fca70
// 005c0689  57                   push edi
// 005c068a  55                   push ebp
// 005c068b  56                   push esi
// 005c068c  e8eff2ffff           call 0x5bf980
// 005c0691  8b4e28               mov ecx, dword ptr [esi + 0x28]
// 005c0694  668b542428           mov dx, word ptr [esp + 0x28]
// 005c0699  8d0419               lea eax, [ecx + ebx]
// 005c069c  66895634             mov word ptr [esi + 0x34], dx
// 005c06a0  894614               mov dword ptr [esi + 0x14], eax
// 005c06a3  8b10                 mov edx, dword ptr [eax]
// 005c06a5  89560c               mov dword ptr [esi + 0xc], edx
// 005c06a8  8b500c               mov edx, dword ptr [eax + 0xc]
// 005c06ab  895618               mov dword ptr [esi + 0x18], edx
// 005c06ae  8a542430             mov dl, byte ptr [esp + 0x30]
// 005c06b2  83c414               add esp, 0x14
// 005c06b5  817e30204e0000       cmp dword ptr [esi + 0x30], 0x4e20
// 005c06bc  885637               mov byte ptr [esi + 0x37], dl
// 005c06bf  7e4f                 jle 0x5c0710
// 005c06c1  2bc1                 sub eax, ecx
// 005c06c3  8bc8                 mov ecx, eax
// 005c06c5  b8abaaaa2a           mov eax, 0x2aaaaaab
// 005c06ca  f7e9                 imul ecx
// 005c06cc  c1fa02               sar edx, 2
// 005c06cf  8bc2                 mov eax, edx
// 005c06d1  c1e81f               shr eax, 0x1f
// 005c06d4  8d4c0201             lea ecx, [edx + eax + 1]
// 005c06d8  81f9204e0000         cmp ecx, 0x4e20
// 005c06de  7d1f                 jge 0x5c06ff
// 005c06e0  68204e0000           push 0x4e20
// 005c06e5  56                   push esi
// 005c06e6  e885f5ffff           call 0x5bfc70
// 005c06eb  8b542418             mov edx, dword ptr [esp + 0x18]
// 005c06ef  83c408               add esp, 8
// 005c06f2  5f                   pop edi
// 005c06f3  895674               mov dword ptr [esi + 0x74], edx
// 005c06f6  5e                   pop esi
// 005c06f7  8bc5                 mov eax, ebp
// 005c06f9  5d                   pop ebp
// 005c06fa  5b                   pop ebx
// 005c06fb  83c408               add esp, 8
// 005c06fe  c3                   ret 
// 005c06ff  8b442410             mov eax, dword ptr [esp + 0x10]
// 005c0703  5f                   pop edi
// 005c0704  894674               mov dword ptr [esi + 0x74], eax
// 005c0707  5e                   pop esi
// 005c0708  8bc5                 mov eax, ebp
// 005c070a  5d                   pop ebp
// 005c070b  5b                   pop ebx
// 005c070c  83c408               add esp, 8
// 005c070f  c3                   ret 
// 005c0710  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005c0714  5f                   pop edi
// 005c0715  894e74               mov dword ptr [esi + 0x74], ecx
// 005c0718  5e                   pop esi
// 005c0719  8bc5                 mov eax, ebp
// 005c071b  5d                   pop ebp
// 005c071c  5b                   pop ebx
// 005c071d  83c408               add esp, 8
// 005c0720  c3                   ret 
// 005c0721  897e74               mov dword ptr [esi + 0x74], edi
// 005c0724  5f                   pop edi
// 005c0725  5e                   pop esi
// 005c0726  5d                   pop ebp
// 005c0727  5b                   pop ebx
// 005c0728  83c408               add esp, 8
// 005c072b  c3                   ret 
// library lua-5.1.1/ldo.c (function _luaD_pcall)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ldo.c
