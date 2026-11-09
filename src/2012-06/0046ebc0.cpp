// from server: 100% by auto
// roc 2012-06 0046ebc0  unit: RBX::Security::VContext::?$thread_specific_ptr::delete_data  size: 775 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0046ebc0
//
// 0046ebc0  55                   push ebp
// 0046ebc1  8d6c2494             lea ebp, [esp - 0x6c]
// 0046ebc5  81ec24010000         sub esp, 0x124
// 0046ebcb  53                   push ebx
// 0046ebcc  8b5d78               mov ebx, dword ptr [ebp + 0x78]
// 0046ebcf  56                   push esi
// 0046ebd0  57                   push edi
// 0046ebd1  c7456800000000       mov dword ptr [ebp + 0x68], 0
// 0046ebd8  85db                 test ebx, ebx
// 0046ebda  0f84d3020000         je 0x46eeb3
// 0046ebe0  8b7d74               mov edi, dword ptr [ebp + 0x74]
// 0046ebe3  8b07                 mov eax, dword ptr [edi]
// 0046ebe5  3b0568cdc000         cmp eax, dword ptr [0xc0cd68]
// 0046ebeb  7525                 jne 0x46ec12
// 0046ebed  8b4f04               mov ecx, dword ptr [edi + 4]
// 0046ebf0  3b0d6ccdc000         cmp ecx, dword ptr [0xc0cd6c]
// 0046ebf6  751a                 jne 0x46ec12
// 0046ebf8  8b5708               mov edx, dword ptr [edi + 8]
// 0046ebfb  3b1570cdc000         cmp edx, dword ptr [0xc0cd70]
// 0046ec01  750f                 jne 0x46ec12
// 0046ec03  8b470c               mov eax, dword ptr [edi + 0xc]
// 0046ec06  3b0574cdc000         cmp eax, dword ptr [0xc0cd74]
// 0046ec0c  0f84a1020000         je 0x46eeb3
// 0046ec12  8d4d68               lea ecx, [ebp + 0x68]
// 0046ec15  51                   push ecx
// 0046ec16  68989eb500           push 0xb59e98
// 0046ec1b  6a01                 push 1
// 0046ec1d  6a00                 push 0
// 0046ec1f  6848cdc000           push 0xc0cd48
// 0046ec24  ff151851b200         call dword ptr [0xb25118]
// 0046ec2a  85c0                 test eax, eax
// 0046ec2c  7d27                 jge 0x46ec55
// 0046ec2e  8b4568               mov eax, dword ptr [ebp + 0x68]
// 0046ec31  85c0                 test eax, eax
// 0046ec33  0f847a020000         je 0x46eeb3
// 0046ec39  8b10                 mov edx, dword ptr [eax]
// 0046ec3b  50                   push eax
// 0046ec3c  8b4208               mov eax, dword ptr [edx + 8]
// 0046ec3f  ffd0                 call eax
// 0046ec41  33c0                 xor eax, eax
// 0046ec43  8da53cffffff         lea esp, [ebp - 0xc4]
// 0046ec49  5f                   pop edi
// 0046ec4a  5e                   pop esi
// 0046ec4b  5b                   pop ebx
// 0046ec4c  83c56c               add ebp, 0x6c
// 0046ec4f  8be5                 mov esp, ebp
// 0046ec51  5d                   pop ebp
// 0046ec52  c20c00               ret 0xc
// 0046ec55  833b00               cmp dword ptr [ebx], 0
// 0046ec58  747c                 je 0x46ecd6
// 0046ec5a  837d7c00             cmp dword ptr [ebp + 0x7c], 0
// 0046ec5e  8b4304               mov eax, dword ptr [ebx + 4]
// 0046ec61  8b08                 mov ecx, dword ptr [eax]
// 0046ec63  894d48               mov dword ptr [ebp + 0x48], ecx
// 0046ec66  8b5004               mov edx, dword ptr [eax + 4]
// 0046ec69  89554c               mov dword ptr [ebp + 0x4c], edx
// 0046ec6c  8b4808               mov ecx, dword ptr [eax + 8]
// 0046ec6f  894d50               mov dword ptr [ebp + 0x50], ecx
// 0046ec72  8b500c               mov edx, dword ptr [eax + 0xc]
// 0046ec75  8b4568               mov eax, dword ptr [ebp + 0x68]
// 0046ec78  895554               mov dword ptr [ebp + 0x54], edx
// 0046ec7b  8b08                 mov ecx, dword ptr [eax]
// 0046ec7d  8d5548               lea edx, [ebp + 0x48]
// 0046ec80  52                   push edx
// 0046ec81  6a01                 push 1
// 0046ec83  57                   push edi
// 0046ec84  50                   push eax
// 0046ec85  7438                 je 0x46ecbf
// 0046ec87  833b01               cmp dword ptr [ebx], 1
// 0046ec8a  7505                 jne 0x46ec91
// 0046ec8c  8b4114               mov eax, dword ptr [ecx + 0x14]
// 0046ec8f  eb03                 jmp 0x46ec94
// 0046ec91  8b411c               mov eax, dword ptr [ecx + 0x1c]
// 0046ec94  ffd0                 call eax
// 0046ec96  8bf0                 mov esi, eax
// 0046ec98  85f6                 test esi, esi
// 0046ec9a  7d32                 jge 0x46ecce
// 0046ec9c  8b4568               mov eax, dword ptr [ebp + 0x68]
// 0046ec9f  85c0                 test eax, eax
// 0046eca1  7408                 je 0x46ecab
// 0046eca3  8b08                 mov ecx, dword ptr [eax]
// 0046eca5  8b5108               mov edx, dword ptr [ecx + 8]
// 0046eca8  50                   push eax
// 0046eca9  ffd2                 call edx
// 0046ecab  8bc6                 mov eax, esi
// 0046ecad  8da53cffffff         lea esp, [ebp - 0xc4]
// 0046ecb3  5f                   pop edi
// 0046ecb4  5e                   pop esi
// 0046ecb5  5b                   pop ebx
// 0046ecb6  83c56c               add ebp, 0x6c
// 0046ecb9  8be5                 mov esp, ebp
// 0046ecbb  5d                   pop ebp
// 0046ecbc  c20c00               ret 0xc
// 0046ecbf  833b01               cmp dword ptr [ebx], 1
// 0046ecc2  7505                 jne 0x46ecc9
// 0046ecc4  8b4118               mov eax, dword ptr [ecx + 0x18]
// 0046ecc7  eb03                 jmp 0x46eccc
// 0046ecc9  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0046eccc  ffd0                 call eax
// 0046ecce  83c308               add ebx, 8
// 0046ecd1  833b00               cmp dword ptr [ebx], 0
// 0046ecd4  7584                 jne 0x46ec5a
// 0046ecd6  837d7c00             cmp dword ptr [ebp + 0x7c], 0
// 0046ecda  0f85c4010000         jne 0x46eea4
// 0046ece0  6a40                 push 0x40
// 0046ece2  8d8548ffffff         lea eax, [ebp - 0xb8]
// 0046ece8  50                   push eax
// 0046ece9  57                   push edi
// 0046ecea  ff154051b200         call dword ptr [0xb25140]
// 0046ecf0  8d8d48ffffff         lea ecx, [ebp - 0xb8]
// 0046ecf6  51                   push ecx
// 0046ecf7  c7457800000000       mov dword ptr [ebp + 0x78], 0
// 0046ecfe  ff15c421b200         call dword ptr [0xb221c4]
// 0046ed04  40                   inc eax
// 0046ed05  6a02                 push 2
// 0046ed07  50                   push eax
// 0046ed08  8d557c               lea edx, [ebp + 0x7c]
// 0046ed0b  52                   push edx
// 0046ed0c  89457c               mov dword ptr [ebp + 0x7c], eax
// 0046ed0f  e89c53f9ff           call 0x4040b0
// 0046ed14  83c40c               add esp, 0xc
// 0046ed17  85c0                 test eax, eax
// 0046ed19  0f8c7d010000         jl 0x46ee9c
// 0046ed1f  8b757c               mov esi, dword ptr [ebp + 0x7c]
// 0046ed22  81fe00040000         cmp esi, 0x400
// 0046ed28  7f18                 jg 0x46ed42
// 0046ed2a  56                   push esi
// 0046ed2b  e84060f9ff           call 0x404d70
// 0046ed30  83c404               add esp, 4
// 0046ed33  84c0                 test al, al
// 0046ed35  740b                 je 0x46ed42
// 0046ed37  8bc6                 mov eax, esi
// 0046ed39  e8d2455100           call 0x983310
// 0046ed3e  8bc4                 mov eax, esp
// 0046ed40  eb09                 jmp 0x46ed4b
// 0046ed42  56                   push esi
// 0046ed43  8d4d78               lea ecx, [ebp + 0x78]
// 0046ed46  e8d564f9ff           call 0x405220
// 0046ed4b  6a03                 push 3
// 0046ed4d  56                   push esi
// 0046ed4e  8d8d48ffffff         lea ecx, [ebp - 0xb8]
// 0046ed54  51                   push ecx
// 0046ed55  50                   push eax
// 0046ed56  e8e553f9ff           call 0x404140
// 0046ed5b  8bf0                 mov esi, eax
// 0046ed5d  85f6                 test esi, esi
// 0046ed5f  0f8437010000         je 0x46ee9c
// 0046ed65  68909eb500           push 0xb59e90
// 0046ed6a  8d55c8               lea edx, [ebp - 0x38]
// 0046ed6d  6880000000           push 0x80
// 0046ed72  52                   push edx
// 0046ed73  e878d7ffff           call 0x46c4f0
// 0046ed78  56                   push esi
// 0046ed79  8d45c8               lea eax, [ebp - 0x38]
// 0046ed7c  6880000000           push 0x80
// 0046ed81  50                   push eax
// 0046ed82  e889d7ffff           call 0x46c510
// 0046ed87  68789eb500           push 0xb59e78
// 0046ed8c  8d4dc8               lea ecx, [ebp - 0x38]
// 0046ed8f  6880000000           push 0x80
// 0046ed94  51                   push ecx
// 0046ed95  e876d7ffff           call 0x46c510
// 0046ed9a  83c424               add esp, 0x24
// 0046ed9d  6819000200           push 0x20019
// 0046eda2  8d55c8               lea edx, [ebp - 0x38]
// 0046eda5  33ff                 xor edi, edi
// 0046eda7  52                   push edx
// 0046eda8  6800000080           push 0x80000000
// 0046edad  8d4d60               lea ecx, [ebp + 0x60]
// 0046edb0  c7455800000080       mov dword ptr [ebp + 0x58], 0x80000000
// 0046edb7  897d5c               mov dword ptr [ebp + 0x5c], edi
// 0046edba  897d60               mov dword ptr [ebp + 0x60], edi
// 0046edbd  897d64               mov dword ptr [ebp + 0x64], edi
// 0046edc0  897d7c               mov dword ptr [ebp + 0x7c], edi
// 0046edc3  e83856f9ff           call 0x404400
// 0046edc8  85c0                 test eax, eax
// 0046edca  7537                 jne 0x46ee03
// 0046edcc  8b4d60               mov ecx, dword ptr [ebp + 0x60]
// 0046edcf  57                   push edi
// 0046edd0  57                   push edi
// 0046edd1  57                   push edi
// 0046edd2  57                   push edi
// 0046edd3  57                   push edi
// 0046edd4  57                   push edi
// 0046edd5  57                   push edi
// 0046edd6  8d457c               lea eax, [ebp + 0x7c]
// 0046edd9  50                   push eax
// 0046edda  57                   push edi
// 0046eddb  57                   push edi
// 0046eddc  57                   push edi
// 0046eddd  51                   push ecx
// 0046edde  ff151420b200         call dword ptr [0xb22014]
// 0046ede4  8d4d60               lea ecx, [ebp + 0x60]
// 0046ede7  8bd8                 mov ebx, eax
// 0046ede9  e8e255f9ff           call 0x4043d0
// 0046edee  3bdf                 cmp ebx, edi
// 0046edf0  7511                 jne 0x46ee03
// 0046edf2  397d7c               cmp dword ptr [ebp + 0x7c], edi
// 0046edf5  750c                 jne 0x46ee03
// 0046edf7  8d55c8               lea edx, [ebp - 0x38]
// 0046edfa  52                   push edx
// 0046edfb  8d4d58               lea ecx, [ebp + 0x58]
// 0046edfe  e86d55f9ff           call 0x404370
// 0046ee03  68909eb500           push 0xb59e90
// 0046ee08  8d45c8               lea eax, [ebp - 0x38]
// 0046ee0b  6880000000           push 0x80
// 0046ee10  50                   push eax
// 0046ee11  e8dad6ffff           call 0x46c4f0
// 0046ee16  56                   push esi
// 0046ee17  8d4dc8               lea ecx, [ebp - 0x38]
// 0046ee1a  6880000000           push 0x80
// 0046ee1f  51                   push ecx
// 0046ee20  e8ebd6ffff           call 0x46c510
// 0046ee25  68609eb500           push 0xb59e60
// 0046ee2a  8d55c8               lea edx, [ebp - 0x38]
// 0046ee2d  6880000000           push 0x80
// 0046ee32  52                   push edx
// 0046ee33  e8d8d6ffff           call 0x46c510
// 0046ee38  83c424               add esp, 0x24
// 0046ee3b  6819000200           push 0x20019
// 0046ee40  8d45c8               lea eax, [ebp - 0x38]
// 0046ee43  50                   push eax
// 0046ee44  6800000080           push 0x80000000
// 0046ee49  8d4d60               lea ecx, [ebp + 0x60]
// 0046ee4c  e8af55f9ff           call 0x404400
// 0046ee51  85c0                 test eax, eax
// 0046ee53  7537                 jne 0x46ee8c
// 0046ee55  8b5560               mov edx, dword ptr [ebp + 0x60]
// 0046ee58  57                   push edi
// 0046ee59  57                   push edi
// 0046ee5a  57                   push edi
// 0046ee5b  57                   push edi
// 0046ee5c  57                   push edi
// 0046ee5d  57                   push edi
// 0046ee5e  57                   push edi
// 0046ee5f  8d4d7c               lea ecx, [ebp + 0x7c]
// 0046ee62  51                   push ecx
// 0046ee63  57                   push edi
// 0046ee64  57                   push edi
// 0046ee65  57                   push edi
// 0046ee66  52                   push edx
// 0046ee67  ff151420b200         call dword ptr [0xb22014]
// 0046ee6d  8d4d60               lea ecx, [ebp + 0x60]
// 0046ee70  8bf0                 mov esi, eax
// 0046ee72  e85955f9ff           call 0x4043d0
// 0046ee77  3bf7                 cmp esi, edi
// 0046ee79  7511                 jne 0x46ee8c
// 0046ee7b  397d7c               cmp dword ptr [ebp + 0x7c], edi
// 0046ee7e  750c                 jne 0x46ee8c
// 0046ee80  8d45c8               lea eax, [ebp - 0x38]
// 0046ee83  50                   push eax
// 0046ee84  8d4d58               lea ecx, [ebp + 0x58]
// 0046ee87  e8e454f9ff           call 0x404370
// 0046ee8c  8d4d60               lea ecx, [ebp + 0x60]
// 0046ee8f  e8bc60f9ff           call 0x404f50
// 0046ee94  8d4d58               lea ecx, [ebp + 0x58]
// 0046ee97  e8b460f9ff           call 0x404f50
// 0046ee9c  8d4d78               lea ecx, [ebp + 0x78]
// 0046ee9f  e8bc5bf9ff           call 0x404a60
// 0046eea4  8b4568               mov eax, dword ptr [ebp + 0x68]
// 0046eea7  85c0                 test eax, eax
// 0046eea9  7408                 je 0x46eeb3
// 0046eeab  8b08                 mov ecx, dword ptr [eax]
// 0046eead  8b5108               mov edx, dword ptr [ecx + 8]
// 0046eeb0  50                   push eax
// 0046eeb1  ffd2                 call edx
// 0046eeb3  33c0                 xor eax, eax
// 0046eeb5  8da53cffffff         lea esp, [ebp - 0xc4]
// 0046eebb  5f                   pop edi
// 0046eebc  5e                   pop esi
// 0046eebd  5b                   pop ebx
// 0046eebe  83c56c               add ebp, 0x6c
// 0046eec1  8be5                 mov esp, ebp
// 0046eec3  5d                   pop ebp
// 0046eec4  c20c00               ret 0xc
// library atl-9.0/atl.cpp (function _AtlRegisterClassCategoriesHelper@12)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
