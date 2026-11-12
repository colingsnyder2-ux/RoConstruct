// from server: 100% by auto
// roc 2008-06 004c4b30  unit: ProfiledRakPeer  size: 466 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004c4b30
//
// 004c4b30  83ec20               sub esp, 0x20
// 004c4b33  8b442428             mov eax, dword ptr [esp + 0x28]
// 004c4b37  53                   push ebx
// 004c4b38  55                   push ebp
// 004c4b39  56                   push esi
// 004c4b3a  8bd9                 mov ebx, ecx
// 004c4b3c  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 004c4b40  57                   push edi
// 004c4b41  8bf9                 mov edi, ecx
// 004c4b43  2bf8                 sub edi, eax
// 004c4b45  c6838000000001       mov byte ptr [ebx + 0x80], 1
// 004c4b4c  be03000000           mov esi, 3
// 004c4b51  8d500c               lea edx, [eax + 0xc]
// 004c4b54  897c2438             mov dword ptr [esp + 0x38], edi
// 004c4b58  eb0a                 jmp 0x4c4b64
// 004c4b5a  8d9b00000000         lea ebx, [ebx]
// 004c4b60  8b7c2438             mov edi, dword ptr [esp + 0x38]
// 004c4b64  8b3c17               mov edi, dword ptr [edi + edx]
// 004c4b67  8b2a                 mov ebp, dword ptr [edx]
// 004c4b69  3bfd                 cmp edi, ebp
// 004c4b6b  0f8750010000         ja 0x4c4cc1
// 004c4b71  7208                 jb 0x4c4b7b
// 004c4b73  4e                   dec esi
// 004c4b74  83ea04               sub edx, 4
// 004c4b77  85f6                 test esi, esi
// 004c4b79  7de5                 jge 0x4c4b60
// 004c4b7b  8b11                 mov edx, dword ptr [ecx]
// 004c4b7d  8993c4000000         mov dword ptr [ebx + 0xc4], edx
// 004c4b83  8b5104               mov edx, dword ptr [ecx + 4]
// 004c4b86  8db3c4000000         lea esi, [ebx + 0xc4]
// 004c4b8c  895604               mov dword ptr [esi + 4], edx
// 004c4b8f  8b5108               mov edx, dword ptr [ecx + 8]
// 004c4b92  895608               mov dword ptr [esi + 8], edx
// 004c4b95  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 004c4b98  894e0c               mov dword ptr [esi + 0xc], ecx
// 004c4b9b  8b10                 mov edx, dword ptr [eax]
// 004c4b9d  8dbbf4000000         lea edi, [ebx + 0xf4]
// 004c4ba3  8917                 mov dword ptr [edi], edx
// 004c4ba5  8b4804               mov ecx, dword ptr [eax + 4]
// 004c4ba8  894f04               mov dword ptr [edi + 4], ecx
// 004c4bab  8b5008               mov edx, dword ptr [eax + 8]
// 004c4bae  895708               mov dword ptr [edi + 8], edx
// 004c4bb1  8b400c               mov eax, dword ptr [eax + 0xc]
// 004c4bb4  89470c               mov dword ptr [edi + 0xc], eax
// 004c4bb7  8b0e                 mov ecx, dword ptr [esi]
// 004c4bb9  8b5604               mov edx, dword ptr [esi + 4]
// 004c4bbc  8b4608               mov eax, dword ptr [esi + 8]
// 004c4bbf  894c2420             mov dword ptr [esp + 0x20], ecx
// 004c4bc3  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 004c4bc6  894c242c             mov dword ptr [esp + 0x2c], ecx
// 004c4bca  89542424             mov dword ptr [esp + 0x24], edx
// 004c4bce  89442428             mov dword ptr [esp + 0x28], eax
// 004c4bd2  33c9                 xor ecx, ecx
// 004c4bd4  8b448c20             mov eax, dword ptr [esp + ecx*4 + 0x20]
// 004c4bd8  8d50ff               lea edx, [eax - 1]
// 004c4bdb  89548c20             mov dword ptr [esp + ecx*4 + 0x20], edx
// 004c4bdf  85c0                 test eax, eax
// 004c4be1  7506                 jne 0x4c4be9
// 004c4be3  41                   inc ecx
// 004c4be4  83f904               cmp ecx, 4
// 004c4be7  72eb                 jb 0x4c4bd4
// 004c4be9  8b07                 mov eax, dword ptr [edi]
// 004c4beb  8b4f04               mov ecx, dword ptr [edi + 4]
// 004c4bee  8b5708               mov edx, dword ptr [edi + 8]
// 004c4bf1  89442410             mov dword ptr [esp + 0x10], eax
// 004c4bf5  8b470c               mov eax, dword ptr [edi + 0xc]
// 004c4bf8  894c2414             mov dword ptr [esp + 0x14], ecx
// 004c4bfc  89542418             mov dword ptr [esp + 0x18], edx
// 004c4c00  8944241c             mov dword ptr [esp + 0x1c], eax
// 004c4c04  33c9                 xor ecx, ecx
// 004c4c06  eb08                 jmp 0x4c4c10
// 004c4c08  8da42400000000       lea esp, [esp]
// 004c4c0f  90                   nop 
// 004c4c10  8b448c10             mov eax, dword ptr [esp + ecx*4 + 0x10]
// 004c4c14  8d50ff               lea edx, [eax - 1]
// 004c4c17  89548c10             mov dword ptr [esp + ecx*4 + 0x10], edx
// 004c4c1b  85c0                 test eax, eax
// 004c4c1d  7506                 jne 0x4c4c25
// 004c4c1f  41                   inc ecx
// 004c4c20  83f904               cmp ecx, 4
// 004c4c23  72eb                 jb 0x4c4c10
// 004c4c25  8daba4000000         lea ebp, [ebx + 0xa4]
// 004c4c2b  55                   push ebp
// 004c4c2c  8d442414             lea eax, [esp + 0x14]
// 004c4c30  50                   push eax
// 004c4c31  8d4c2428             lea ecx, [esp + 0x28]
// 004c4c35  51                   push ecx
// 004c4c36  e8d58fffff           call 0x4bdc10
// 004c4c3b  53                   push ebx
// 004c4c3c  55                   push ebp
// 004c4c3d  e8eebdffff           call 0x4c0a30
// 004c4c42  8d9384000000         lea edx, [ebx + 0x84]
// 004c4c48  52                   push edx
// 004c4c49  55                   push ebp
// 004c4c4a  53                   push ebx
// 004c4c4b  e830c7ffff           call 0x4c1380
// 004c4c50  8d8324010000         lea eax, [ebx + 0x124]
// 004c4c56  50                   push eax
// 004c4c57  57                   push edi
// 004c4c58  56                   push esi
// 004c4c59  e842bfffff           call 0x4c0ba0
// 004c4c5e  8d6b20               lea ebp, [ebx + 0x20]
// 004c4c61  55                   push ebp
// 004c4c62  57                   push edi
// 004c4c63  56                   push esi
// 004c4c64  e8a78fffff           call 0x4bdc10
// 004c4c69  8d4b40               lea ecx, [ebx + 0x40]
// 004c4c6c  51                   push ecx
// 004c4c6d  55                   push ebp
// 004c4c6e  e87de7ffff           call 0x4c33f0
// 004c4c73  83c440               add esp, 0x40
// 004c4c76  8d5360               lea edx, [ebx + 0x60]
// 004c4c79  52                   push edx
// 004c4c7a  55                   push ebp
// 004c4c7b  e820bbffff           call 0x4c07a0
// 004c4c80  8d83d4000000         lea eax, [ebx + 0xd4]
// 004c4c86  50                   push eax
// 004c4c87  56                   push esi
// 004c4c88  e813ebffff           call 0x4c37a0
// 004c4c8d  8d8be4000000         lea ecx, [ebx + 0xe4]
// 004c4c93  51                   push ecx
// 004c4c94  56                   push esi
// 004c4c95  e8a6c1ffff           call 0x4c0e40
// 004c4c9a  8d9304010000         lea edx, [ebx + 0x104]
// 004c4ca0  52                   push edx
// 004c4ca1  57                   push edi
// 004c4ca2  e8f9eaffff           call 0x4c37a0
// 004c4ca7  81c314010000         add ebx, 0x114
// 004c4cad  53                   push ebx
// 004c4cae  57                   push edi
// 004c4caf  e88cc1ffff           call 0x4c0e40
// 004c4cb4  83c428               add esp, 0x28
// 004c4cb7  5f                   pop edi
// 004c4cb8  5e                   pop esi
// 004c4cb9  5d                   pop ebp
// 004c4cba  5b                   pop ebx
// 004c4cbb  83c420               add esp, 0x20
// 004c4cbe  c20800               ret 8
// 004c4cc1  8b11                 mov edx, dword ptr [ecx]
// 004c4cc3  8993f4000000         mov dword ptr [ebx + 0xf4], edx
// 004c4cc9  8b5104               mov edx, dword ptr [ecx + 4]
// 004c4ccc  8dbbf4000000         lea edi, [ebx + 0xf4]
// 004c4cd2  895704               mov dword ptr [edi + 4], edx
// 004c4cd5  8b5108               mov edx, dword ptr [ecx + 8]
// 004c4cd8  895708               mov dword ptr [edi + 8], edx
// 004c4cdb  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 004c4cde  894f0c               mov dword ptr [edi + 0xc], ecx
// 004c4ce1  8b10                 mov edx, dword ptr [eax]
// 004c4ce3  8db3c4000000         lea esi, [ebx + 0xc4]
// 004c4ce9  8916                 mov dword ptr [esi], edx
// 004c4ceb  8b4804               mov ecx, dword ptr [eax + 4]
// 004c4cee  894e04               mov dword ptr [esi + 4], ecx
// 004c4cf1  8b5008               mov edx, dword ptr [eax + 8]
// 004c4cf4  895608               mov dword ptr [esi + 8], edx
// 004c4cf7  8b400c               mov eax, dword ptr [eax + 0xc]
// 004c4cfa  89460c               mov dword ptr [esi + 0xc], eax
// 004c4cfd  e9b5feffff           jmp 0x4c4bb7
// library openrbx-raknet/RakPeer.cpp (function ??$setPrivateKey@$$BY03I@?$RSACrypt@$$BY07I@big@@QAEXAAY03I0@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
