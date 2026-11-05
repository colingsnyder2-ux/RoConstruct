// from server: 100% by auto
// roc 2010-06 0044ebb0  unit: CRbxPlayDocTemplate  size: 775 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0044ebb0
//
// 0044ebb0  55                   push ebp
// 0044ebb1  8d6c2494             lea ebp, [esp - 0x6c]
// 0044ebb5  81ec24010000         sub esp, 0x124
// 0044ebbb  53                   push ebx
// 0044ebbc  8b5d78               mov ebx, dword ptr [ebp + 0x78]
// 0044ebbf  56                   push esi
// 0044ebc0  57                   push edi
// 0044ebc1  c7456800000000       mov dword ptr [ebp + 0x68], 0
// 0044ebc8  85db                 test ebx, ebx
// 0044ebca  0f84d3020000         je 0x44eea3
// 0044ebd0  8b7d74               mov edi, dword ptr [ebp + 0x74]
// 0044ebd3  8b07                 mov eax, dword ptr [edi]
// 0044ebd5  3b05485aa500         cmp eax, dword ptr [0xa55a48]
// 0044ebdb  7525                 jne 0x44ec02
// 0044ebdd  8b4f04               mov ecx, dword ptr [edi + 4]
// 0044ebe0  3b0d4c5aa500         cmp ecx, dword ptr [0xa55a4c]
// 0044ebe6  751a                 jne 0x44ec02
// 0044ebe8  8b5708               mov edx, dword ptr [edi + 8]
// 0044ebeb  3b15505aa500         cmp edx, dword ptr [0xa55a50]
// 0044ebf1  750f                 jne 0x44ec02
// 0044ebf3  8b470c               mov eax, dword ptr [edi + 0xc]
// 0044ebf6  3b05545aa500         cmp eax, dword ptr [0xa55a54]
// 0044ebfc  0f84a1020000         je 0x44eea3
// 0044ec02  8d4d68               lea ecx, [ebp + 0x68]
// 0044ec05  51                   push ecx
// 0044ec06  68d4c1a000           push 0xa0c1d4
// 0044ec0b  6a01                 push 1
// 0044ec0d  6a00                 push 0
// 0044ec0f  68185aa500           push 0xa55a18
// 0044ec14  ff15dcd09e00         call dword ptr [0x9ed0dc]
// 0044ec1a  85c0                 test eax, eax
// 0044ec1c  7d27                 jge 0x44ec45
// 0044ec1e  8b4568               mov eax, dword ptr [ebp + 0x68]
// 0044ec21  85c0                 test eax, eax
// 0044ec23  0f847a020000         je 0x44eea3
// 0044ec29  8b10                 mov edx, dword ptr [eax]
// 0044ec2b  50                   push eax
// 0044ec2c  8b4208               mov eax, dword ptr [edx + 8]
// 0044ec2f  ffd0                 call eax
// 0044ec31  33c0                 xor eax, eax
// 0044ec33  8da53cffffff         lea esp, [ebp - 0xc4]
// 0044ec39  5f                   pop edi
// 0044ec3a  5e                   pop esi
// 0044ec3b  5b                   pop ebx
// 0044ec3c  83c56c               add ebp, 0x6c
// 0044ec3f  8be5                 mov esp, ebp
// 0044ec41  5d                   pop ebp
// 0044ec42  c20c00               ret 0xc
// 0044ec45  833b00               cmp dword ptr [ebx], 0
// 0044ec48  747c                 je 0x44ecc6
// 0044ec4a  837d7c00             cmp dword ptr [ebp + 0x7c], 0
// 0044ec4e  8b4304               mov eax, dword ptr [ebx + 4]
// 0044ec51  8b08                 mov ecx, dword ptr [eax]
// 0044ec53  894d48               mov dword ptr [ebp + 0x48], ecx
// 0044ec56  8b5004               mov edx, dword ptr [eax + 4]
// 0044ec59  89554c               mov dword ptr [ebp + 0x4c], edx
// 0044ec5c  8b4808               mov ecx, dword ptr [eax + 8]
// 0044ec5f  894d50               mov dword ptr [ebp + 0x50], ecx
// 0044ec62  8b500c               mov edx, dword ptr [eax + 0xc]
// 0044ec65  8b4568               mov eax, dword ptr [ebp + 0x68]
// 0044ec68  895554               mov dword ptr [ebp + 0x54], edx
// 0044ec6b  8b08                 mov ecx, dword ptr [eax]
// 0044ec6d  8d5548               lea edx, [ebp + 0x48]
// 0044ec70  52                   push edx
// 0044ec71  6a01                 push 1
// 0044ec73  57                   push edi
// 0044ec74  50                   push eax
// 0044ec75  7438                 je 0x44ecaf
// 0044ec77  833b01               cmp dword ptr [ebx], 1
// 0044ec7a  7505                 jne 0x44ec81
// 0044ec7c  8b4114               mov eax, dword ptr [ecx + 0x14]
// 0044ec7f  eb03                 jmp 0x44ec84
// 0044ec81  8b411c               mov eax, dword ptr [ecx + 0x1c]
// 0044ec84  ffd0                 call eax
// 0044ec86  8bf0                 mov esi, eax
// 0044ec88  85f6                 test esi, esi
// 0044ec8a  7d32                 jge 0x44ecbe
// 0044ec8c  8b4568               mov eax, dword ptr [ebp + 0x68]
// 0044ec8f  85c0                 test eax, eax
// 0044ec91  7408                 je 0x44ec9b
// 0044ec93  8b08                 mov ecx, dword ptr [eax]
// 0044ec95  8b5108               mov edx, dword ptr [ecx + 8]
// 0044ec98  50                   push eax
// 0044ec99  ffd2                 call edx
// 0044ec9b  8bc6                 mov eax, esi
// 0044ec9d  8da53cffffff         lea esp, [ebp - 0xc4]
// 0044eca3  5f                   pop edi
// 0044eca4  5e                   pop esi
// 0044eca5  5b                   pop ebx
// 0044eca6  83c56c               add ebp, 0x6c
// 0044eca9  8be5                 mov esp, ebp
// 0044ecab  5d                   pop ebp
// 0044ecac  c20c00               ret 0xc
// 0044ecaf  833b01               cmp dword ptr [ebx], 1
// 0044ecb2  7505                 jne 0x44ecb9
// 0044ecb4  8b4118               mov eax, dword ptr [ecx + 0x18]
// 0044ecb7  eb03                 jmp 0x44ecbc
// 0044ecb9  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0044ecbc  ffd0                 call eax
// 0044ecbe  83c308               add ebx, 8
// 0044ecc1  833b00               cmp dword ptr [ebx], 0
// 0044ecc4  7584                 jne 0x44ec4a
// 0044ecc6  837d7c00             cmp dword ptr [ebp + 0x7c], 0
// 0044ecca  0f85c4010000         jne 0x44ee94
// 0044ecd0  6a40                 push 0x40
// 0044ecd2  8d8548ffffff         lea eax, [ebp - 0xb8]
// 0044ecd8  50                   push eax
// 0044ecd9  57                   push edi
// 0044ecda  ff15ecd09e00         call dword ptr [0x9ed0ec]
// 0044ece0  8d8d48ffffff         lea ecx, [ebp - 0xb8]
// 0044ece6  51                   push ecx
// 0044ece7  c7457800000000       mov dword ptr [ebp + 0x78], 0
// 0044ecee  ff15a8a39e00         call dword ptr [0x9ea3a8]
// 0044ecf4  40                   inc eax
// 0044ecf5  6a02                 push 2
// 0044ecf7  50                   push eax
// 0044ecf8  8d557c               lea edx, [ebp + 0x7c]
// 0044ecfb  52                   push edx
// 0044ecfc  89457c               mov dword ptr [ebp + 0x7c], eax
// 0044ecff  e8cc3dfbff           call 0x402ad0
// 0044ed04  83c40c               add esp, 0xc
// 0044ed07  85c0                 test eax, eax
// 0044ed09  0f8c7d010000         jl 0x44ee8c
// 0044ed0f  8b757c               mov esi, dword ptr [ebp + 0x7c]
// 0044ed12  81fe00040000         cmp esi, 0x400
// 0044ed18  7f18                 jg 0x44ed32
// 0044ed1a  56                   push esi
// 0044ed1b  e8304efbff           call 0x403b50
// 0044ed20  83c404               add esp, 4
// 0044ed23  84c0                 test al, al
// 0044ed25  740b                 je 0x44ed32
// 0044ed27  8bc6                 mov eax, esi
// 0044ed29  e8529e3500           call 0x7a8b80
// 0044ed2e  8bc4                 mov eax, esp
// 0044ed30  eb09                 jmp 0x44ed3b
// 0044ed32  56                   push esi
// 0044ed33  8d4d78               lea ecx, [ebp + 0x78]
// 0044ed36  e8b553fbff           call 0x4040f0
// 0044ed3b  6a03                 push 3
// 0044ed3d  56                   push esi
// 0044ed3e  8d8d48ffffff         lea ecx, [ebp - 0xb8]
// 0044ed44  51                   push ecx
// 0044ed45  50                   push eax
// 0044ed46  e8153efbff           call 0x402b60
// 0044ed4b  8bf0                 mov esi, eax
// 0044ed4d  85f6                 test esi, esi
// 0044ed4f  0f8437010000         je 0x44ee8c
// 0044ed55  68ccc1a000           push 0xa0c1cc
// 0044ed5a  8d55c8               lea edx, [ebp - 0x38]
// 0044ed5d  6880000000           push 0x80
// 0044ed62  52                   push edx
// 0044ed63  e868d8ffff           call 0x44c5d0
// 0044ed68  56                   push esi
// 0044ed69  8d45c8               lea eax, [ebp - 0x38]
// 0044ed6c  6880000000           push 0x80
// 0044ed71  50                   push eax
// 0044ed72  e879d8ffff           call 0x44c5f0
// 0044ed77  68b4c1a000           push 0xa0c1b4
// 0044ed7c  8d4dc8               lea ecx, [ebp - 0x38]
// 0044ed7f  6880000000           push 0x80
// 0044ed84  51                   push ecx
// 0044ed85  e866d8ffff           call 0x44c5f0
// 0044ed8a  83c424               add esp, 0x24
// 0044ed8d  6819000200           push 0x20019
// 0044ed92  8d55c8               lea edx, [ebp - 0x38]
// 0044ed95  33ff                 xor edi, edi
// 0044ed97  52                   push edx
// 0044ed98  6800000080           push 0x80000000
// 0044ed9d  8d4d60               lea ecx, [ebp + 0x60]
// 0044eda0  c7455800000080       mov dword ptr [ebp + 0x58], 0x80000000
// 0044eda7  897d5c               mov dword ptr [ebp + 0x5c], edi
// 0044edaa  897d60               mov dword ptr [ebp + 0x60], edi
// 0044edad  897d64               mov dword ptr [ebp + 0x64], edi
// 0044edb0  897d7c               mov dword ptr [ebp + 0x7c], edi
// 0044edb3  e80841fbff           call 0x402ec0
// 0044edb8  85c0                 test eax, eax
// 0044edba  7537                 jne 0x44edf3
// 0044edbc  8b4d60               mov ecx, dword ptr [ebp + 0x60]
// 0044edbf  57                   push edi
// 0044edc0  57                   push edi
// 0044edc1  57                   push edi
// 0044edc2  57                   push edi
// 0044edc3  57                   push edi
// 0044edc4  57                   push edi
// 0044edc5  57                   push edi
// 0044edc6  8d457c               lea eax, [ebp + 0x7c]
// 0044edc9  50                   push eax
// 0044edca  57                   push edi
// 0044edcb  57                   push edi
// 0044edcc  57                   push edi
// 0044edcd  51                   push ecx
// 0044edce  ff1520a09e00         call dword ptr [0x9ea020]
// 0044edd4  8d4d60               lea ecx, [ebp + 0x60]
// 0044edd7  8bd8                 mov ebx, eax
// 0044edd9  e8b240fbff           call 0x402e90
// 0044edde  3bdf                 cmp ebx, edi
// 0044ede0  7511                 jne 0x44edf3
// 0044ede2  397d7c               cmp dword ptr [ebp + 0x7c], edi
// 0044ede5  750c                 jne 0x44edf3
// 0044ede7  8d55c8               lea edx, [ebp - 0x38]
// 0044edea  52                   push edx
// 0044edeb  8d4d58               lea ecx, [ebp + 0x58]
// 0044edee  e83d40fbff           call 0x402e30
// 0044edf3  68ccc1a000           push 0xa0c1cc
// 0044edf8  8d45c8               lea eax, [ebp - 0x38]
// 0044edfb  6880000000           push 0x80
// 0044ee00  50                   push eax
// 0044ee01  e8cad7ffff           call 0x44c5d0
// 0044ee06  56                   push esi
// 0044ee07  8d4dc8               lea ecx, [ebp - 0x38]
// 0044ee0a  6880000000           push 0x80
// 0044ee0f  51                   push ecx
// 0044ee10  e8dbd7ffff           call 0x44c5f0
// 0044ee15  689cc1a000           push 0xa0c19c
// 0044ee1a  8d55c8               lea edx, [ebp - 0x38]
// 0044ee1d  6880000000           push 0x80
// 0044ee22  52                   push edx
// 0044ee23  e8c8d7ffff           call 0x44c5f0
// 0044ee28  83c424               add esp, 0x24
// 0044ee2b  6819000200           push 0x20019
// 0044ee30  8d45c8               lea eax, [ebp - 0x38]
// 0044ee33  50                   push eax
// 0044ee34  6800000080           push 0x80000000
// 0044ee39  8d4d60               lea ecx, [ebp + 0x60]
// 0044ee3c  e87f40fbff           call 0x402ec0
// 0044ee41  85c0                 test eax, eax
// 0044ee43  7537                 jne 0x44ee7c
// 0044ee45  8b5560               mov edx, dword ptr [ebp + 0x60]
// 0044ee48  57                   push edi
// 0044ee49  57                   push edi
// 0044ee4a  57                   push edi
// 0044ee4b  57                   push edi
// 0044ee4c  57                   push edi
// 0044ee4d  57                   push edi
// 0044ee4e  57                   push edi
// 0044ee4f  8d4d7c               lea ecx, [ebp + 0x7c]
// 0044ee52  51                   push ecx
// 0044ee53  57                   push edi
// 0044ee54  57                   push edi
// 0044ee55  57                   push edi
// 0044ee56  52                   push edx
// 0044ee57  ff1520a09e00         call dword ptr [0x9ea020]
// 0044ee5d  8d4d60               lea ecx, [ebp + 0x60]
// 0044ee60  8bf0                 mov esi, eax
// 0044ee62  e82940fbff           call 0x402e90
// 0044ee67  3bf7                 cmp esi, edi
// 0044ee69  7511                 jne 0x44ee7c
// 0044ee6b  397d7c               cmp dword ptr [ebp + 0x7c], edi
// 0044ee6e  750c                 jne 0x44ee7c
// 0044ee70  8d45c8               lea eax, [ebp - 0x38]
// 0044ee73  50                   push eax
// 0044ee74  8d4d58               lea ecx, [ebp + 0x58]
// 0044ee77  e8b43ffbff           call 0x402e30
// 0044ee7c  8d4d60               lea ecx, [ebp + 0x60]
// 0044ee7f  e87c4ffbff           call 0x403e00
// 0044ee84  8d4d58               lea ecx, [ebp + 0x58]
// 0044ee87  e8744ffbff           call 0x403e00
// 0044ee8c  8d4d78               lea ecx, [ebp + 0x78]
// 0044ee8f  e83c4afbff           call 0x4038d0
// 0044ee94  8b4568               mov eax, dword ptr [ebp + 0x68]
// 0044ee97  85c0                 test eax, eax
// 0044ee99  7408                 je 0x44eea3
// 0044ee9b  8b08                 mov ecx, dword ptr [eax]
// 0044ee9d  8b5108               mov edx, dword ptr [ecx + 8]
// 0044eea0  50                   push eax
// 0044eea1  ffd2                 call edx
// 0044eea3  33c0                 xor eax, eax
// 0044eea5  8da53cffffff         lea esp, [ebp - 0xc4]
// 0044eeab  5f                   pop edi
// 0044eeac  5e                   pop esi
// 0044eead  5b                   pop ebx
// 0044eeae  83c56c               add ebp, 0x6c
// 0044eeb1  8be5                 mov esp, ebp
// 0044eeb3  5d                   pop ebp
// 0044eeb4  c20c00               ret 0xc
// library atl-9.0/atl.cpp (function _AtlRegisterClassCategoriesHelper@12)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
