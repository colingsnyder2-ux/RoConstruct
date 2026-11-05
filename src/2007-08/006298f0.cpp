// from server: 100% by auto
// roc 2007-08 006298f0  unit: RBX::AssemblyStage  size: 192 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006298f0
//
// 006298f0  56                   push esi
// 006298f1  57                   push edi
// 006298f2  e809f7ffff           call 0x629000
// 006298f7  8b06                 mov eax, dword ptr [esi]
// 006298f9  83c0ff               add eax, -1
// 006298fc  83c408               add esp, 8
// 006298ff  83f80b               cmp eax, 0xb
// 00629902  776b                 ja 0x62996f
// 00629904  0fb680a4996200       movzx eax, byte ptr [eax + 0x6299a4]
// 0062990b  ff248590996200       jmp dword ptr [eax*4 + 0x629990]
// 00629912  c70602000000         mov dword ptr [esi], 2
// 00629918  eb55                 jmp 0x62996f
// 0062991a  c70603000000         mov dword ptr [esi], 3
// 00629920  eb4d                 jmp 0x62996f
// 00629922  8bc6                 mov eax, esi
// 00629924  8bcf                 mov ecx, edi
// 00629926  e855f2ffff           call 0x628b80
// 0062992b  eb42                 jmp 0x62996f
// 0062992d  56                   push esi
// 0062992e  8bc7                 mov eax, edi
// 00629930  e8dbf8ffff           call 0x629210
// 00629935  83c404               add esp, 4
// 00629938  833e0c               cmp dword ptr [esi], 0xc
// 0062993b  7516                 jne 0x629953
// 0062993d  8b4608               mov eax, dword ptr [esi + 8]
// 00629940  a900010000           test eax, 0x100
// 00629945  750c                 jne 0x629953
// 00629947  0fb64f32             movzx ecx, byte ptr [edi + 0x32]
// 0062994b  3bc1                 cmp eax, ecx
// 0062994d  7c04                 jl 0x629953
// 0062994f  834724ff             add dword ptr [edi + 0x24], -1
// 00629953  8b5608               mov edx, dword ptr [esi + 8]
// 00629956  6a00                 push 0
// 00629958  52                   push edx
// 00629959  6a00                 push 0
// 0062995b  6a13                 push 0x13
// 0062995d  57                   push edi
// 0062995e  e81df4ffff           call 0x628d80
// 00629963  83c414               add esp, 0x14
// 00629966  894608               mov dword ptr [esi + 8], eax
// 00629969  c7060b000000         mov dword ptr [esi], 0xb
// 0062996f  8b4614               mov eax, dword ptr [esi + 0x14]
// 00629972  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00629975  894610               mov dword ptr [esi + 0x10], eax
// 00629978  57                   push edi
// 00629979  8bc1                 mov eax, ecx
// 0062997b  894e14               mov dword ptr [esi + 0x14], ecx
// 0062997e  e84dedffff           call 0x6286d0
// 00629983  8b4610               mov eax, dword ptr [esi + 0x10]
// 00629986  57                   push edi
// 00629987  e844edffff           call 0x6286d0
// 0062998c  83c408               add esp, 8
// 0062998f  c3                   ret 
// 00629990  129962001a99         adc bl, byte ptr [ecx - 0x66e5ff9e]
// 00629996  6200                 bound eax, qword ptr [eax]
// 00629998  229962002d99         and bl, byte ptr [ecx - 0x66d2ff9e]
// 0062999e  6200                 bound eax, qword ptr [eax]
// 006299a0  6f                   outsd dx, dword ptr [esi]
// 006299a1  99                   cdq 
// 006299a2  6200                 bound eax, qword ptr [eax]
// 006299a4  0001                 add byte ptr [ecx], al
// 006299a6  0001                 add byte ptr [ecx], al
// 006299a8  010404               add dword ptr [esp + eax], eax
// 006299ab  0404                 add al, 4
// 006299ad  0203                 add al, byte ptr [ebx]
// library lua-5.1/lcode.c (function _codenot)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c
