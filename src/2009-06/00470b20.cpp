// from server: 100% by auto
// roc 2009-06 00470b20  unit: RBX::LDraw2Lua::LDraw2RobloxColorMap  size: 562 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00470b20
//
// 00470b20  83ec14               sub esp, 0x14
// 00470b23  56                   push esi
// 00470b24  8bf1                 mov esi, ecx
// 00470b26  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 00470b2a  57                   push edi
// 00470b2b  7521                 jne 0x470b4e
// 00470b2d  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00470b31  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00470b34  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00470b38  50                   push eax
// 00470b39  51                   push ecx
// 00470b3a  6a01                 push 1
// 00470b3c  57                   push edi
// 00470b3d  8bce                 mov ecx, esi
// 00470b3f  e86c320000           call 0x473db0
// 00470b44  8bc7                 mov eax, edi
// 00470b46  5f                   pop edi
// 00470b47  5e                   pop esi
// 00470b48  83c414               add esp, 0x14
// 00470b4b  c21000               ret 0x10
// 00470b4e  8b442424             mov eax, dword ptr [esp + 0x24]
// 00470b52  8b5618               mov edx, dword ptr [esi + 0x18]
// 00470b55  8b3a                 mov edi, dword ptr [edx]
// 00470b57  8b0e                 mov ecx, dword ptr [esi]
// 00470b59  53                   push ebx
// 00470b5a  8b1dace98900         mov ebx, dword ptr [0x89e9ac]
// 00470b60  85c0                 test eax, eax
// 00470b62  7404                 je 0x470b68
// 00470b64  3bc1                 cmp eax, ecx
// 00470b66  7406                 je 0x470b6e
// 00470b68  ffd3                 call ebx
// 00470b6a  8b442428             mov eax, dword ptr [esp + 0x28]
// 00470b6e  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 00470b72  55                   push ebp
// 00470b73  3bd7                 cmp edx, edi
// 00470b75  753a                 jne 0x470bb1
// 00470b77  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 00470b7b  83c20c               add edx, 0xc
// 00470b7e  52                   push edx
// 00470b7f  57                   push edi
// 00470b80  ff15e0e48900         call dword ptr [0x89e4e0]
// 00470b86  83c408               add esp, 8
// 00470b89  84c0                 test al, al
// 00470b8b  0f849a010000         je 0x470d2b
// 00470b91  8b442430             mov eax, dword ptr [esp + 0x30]
// 00470b95  57                   push edi
// 00470b96  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00470b9a  50                   push eax
// 00470b9b  6a01                 push 1
// 00470b9d  57                   push edi
// 00470b9e  8bce                 mov ecx, esi
// 00470ba0  e80b320000           call 0x473db0
// 00470ba5  5d                   pop ebp
// 00470ba6  5b                   pop ebx
// 00470ba7  8bc7                 mov eax, edi
// 00470ba9  5f                   pop edi
// 00470baa  5e                   pop esi
// 00470bab  83c414               add esp, 0x14
// 00470bae  c21000               ret 0x10
// 00470bb1  8b7e18               mov edi, dword ptr [esi + 0x18]
// 00470bb4  8b0e                 mov ecx, dword ptr [esi]
// 00470bb6  85c0                 test eax, eax
// 00470bb8  7404                 je 0x470bbe
// 00470bba  3bc1                 cmp eax, ecx
// 00470bbc  7406                 je 0x470bc4
// 00470bbe  ffd3                 call ebx
// 00470bc0  8b542430             mov edx, dword ptr [esp + 0x30]
// 00470bc4  3bd7                 cmp edx, edi
// 00470bc6  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 00470bca  753e                 jne 0x470c0a
// 00470bcc  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00470bcf  8b4108               mov eax, dword ptr [ecx + 8]
// 00470bd2  83c00c               add eax, 0xc
// 00470bd5  57                   push edi
// 00470bd6  50                   push eax
// 00470bd7  ff15e0e48900         call dword ptr [0x89e4e0]
// 00470bdd  83c408               add esp, 8
// 00470be0  84c0                 test al, al
// 00470be2  0f8443010000         je 0x470d2b
// 00470be8  8b5618               mov edx, dword ptr [esi + 0x18]
// 00470beb  8b4208               mov eax, dword ptr [edx + 8]
// 00470bee  57                   push edi
// 00470bef  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00470bf3  50                   push eax
// 00470bf4  6a00                 push 0
// 00470bf6  57                   push edi
// 00470bf7  8bce                 mov ecx, esi
// 00470bf9  e8b2310000           call 0x473db0
// 00470bfe  5d                   pop ebp
// 00470bff  5b                   pop ebx
// 00470c00  8bc7                 mov eax, edi
// 00470c02  5f                   pop edi
// 00470c03  5e                   pop esi
// 00470c04  83c414               add esp, 0x14
// 00470c07  c21000               ret 0x10
// 00470c0a  8b2de0e48900         mov ebp, dword ptr [0x89e4e0]
// 00470c10  83c20c               add edx, 0xc
// 00470c13  52                   push edx
// 00470c14  57                   push edi
// 00470c15  ffd5                 call ebp
// 00470c17  83c408               add esp, 8
// 00470c1a  84c0                 test al, al
// 00470c1c  746c                 je 0x470c8a
// 00470c1e  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00470c22  8b542430             mov edx, dword ptr [esp + 0x30]
// 00470c26  894c2410             mov dword ptr [esp + 0x10], ecx
// 00470c2a  8d4c2410             lea ecx, [esp + 0x10]
// 00470c2e  89542414             mov dword ptr [esp + 0x14], edx
// 00470c32  e819a91800           call 0x5fb550
// 00470c37  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 00470c3b  57                   push edi
// 00470c3c  8d430c               lea eax, [ebx + 0xc]
// 00470c3f  50                   push eax
// 00470c40  8d4e08               lea ecx, [esi + 8]
// 00470c43  e8c8831600           call 0x5d9010
// 00470c48  84c0                 test al, al
// 00470c4a  743e                 je 0x470c8a
// 00470c4c  8b4b08               mov ecx, dword ptr [ebx + 8]
// 00470c4f  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 00470c53  57                   push edi
// 00470c54  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00470c58  8bce                 mov ecx, esi
// 00470c5a  7415                 je 0x470c71
// 00470c5c  53                   push ebx
// 00470c5d  6a00                 push 0
// 00470c5f  57                   push edi
// 00470c60  e84b310000           call 0x473db0
// 00470c65  5d                   pop ebp
// 00470c66  5b                   pop ebx
// 00470c67  8bc7                 mov eax, edi
// 00470c69  5f                   pop edi
// 00470c6a  5e                   pop esi
// 00470c6b  83c414               add esp, 0x14
// 00470c6e  c21000               ret 0x10
// 00470c71  8b542434             mov edx, dword ptr [esp + 0x34]
// 00470c75  52                   push edx
// 00470c76  6a01                 push 1
// 00470c78  57                   push edi
// 00470c79  e832310000           call 0x473db0
// 00470c7e  5d                   pop ebp
// 00470c7f  5b                   pop ebx
// 00470c80  8bc7                 mov eax, edi
// 00470c82  5f                   pop edi
// 00470c83  5e                   pop esi
// 00470c84  83c414               add esp, 0x14
// 00470c87  c21000               ret 0x10
// 00470c8a  8b442430             mov eax, dword ptr [esp + 0x30]
// 00470c8e  83c00c               add eax, 0xc
// 00470c91  57                   push edi
// 00470c92  50                   push eax
// 00470c93  ffd5                 call ebp
// 00470c95  83c408               add esp, 8
// 00470c98  84c0                 test al, al
// 00470c9a  0f848b000000         je 0x470d2b
// 00470ca0  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00470ca4  8b542430             mov edx, dword ptr [esp + 0x30]
// 00470ca8  8b4618               mov eax, dword ptr [esi + 0x18]
// 00470cab  894c2410             mov dword ptr [esp + 0x10], ecx
// 00470caf  8b0e                 mov ecx, dword ptr [esi]
// 00470cb1  894c2418             mov dword ptr [esp + 0x18], ecx
// 00470cb5  8d4c2410             lea ecx, [esp + 0x10]
// 00470cb9  89542414             mov dword ptr [esp + 0x14], edx
// 00470cbd  8944241c             mov dword ptr [esp + 0x1c], eax
// 00470cc1  e84add1c00           call 0x63ea10
// 00470cc6  8d542418             lea edx, [esp + 0x18]
// 00470cca  52                   push edx
// 00470ccb  8d4c2414             lea ecx, [esp + 0x14]
// 00470ccf  e8cc271d00           call 0x6434a0
// 00470cd4  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 00470cd8  84c0                 test al, al
// 00470cda  7511                 jne 0x470ced
// 00470cdc  8d430c               lea eax, [ebx + 0xc]
// 00470cdf  50                   push eax
// 00470ce0  57                   push edi
// 00470ce1  8d4e08               lea ecx, [esi + 8]
// 00470ce4  e827831600           call 0x5d9010
// 00470ce9  84c0                 test al, al
// 00470ceb  743e                 je 0x470d2b
// 00470ced  8b442430             mov eax, dword ptr [esp + 0x30]
// 00470cf1  8b4808               mov ecx, dword ptr [eax + 8]
// 00470cf4  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 00470cf8  57                   push edi
// 00470cf9  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00470cfd  8bce                 mov ecx, esi
// 00470cff  7415                 je 0x470d16
// 00470d01  50                   push eax
// 00470d02  6a00                 push 0
// 00470d04  57                   push edi
// 00470d05  e8a6300000           call 0x473db0
// 00470d0a  5d                   pop ebp
// 00470d0b  5b                   pop ebx
// 00470d0c  8bc7                 mov eax, edi
// 00470d0e  5f                   pop edi
// 00470d0f  5e                   pop esi
// 00470d10  83c414               add esp, 0x14
// 00470d13  c21000               ret 0x10
// 00470d16  53                   push ebx
// 00470d17  6a01                 push 1
// 00470d19  57                   push edi
// 00470d1a  e891300000           call 0x473db0
// 00470d1f  5d                   pop ebp
// 00470d20  5b                   pop ebx
// 00470d21  8bc7                 mov eax, edi
// 00470d23  5f                   pop edi
// 00470d24  5e                   pop esi
// 00470d25  83c414               add esp, 0x14
// 00470d28  c21000               ret 0x10
// 00470d2b  57                   push edi
// 00470d2c  8d54241c             lea edx, [esp + 0x1c]
// 00470d30  52                   push edx
// 00470d31  8bce                 mov ecx, esi
// 00470d33  e8f8380000           call 0x474630
// 00470d38  8b10                 mov edx, dword ptr [eax]
// 00470d3a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00470d3e  5d                   pop ebp
// 00470d3f  5b                   pop ebx
// 00470d40  8911                 mov dword ptr [ecx], edx
// 00470d42  8b4004               mov eax, dword ptr [eax + 4]
// 00470d45  5f                   pop edi
// 00470d46  894104               mov dword ptr [ecx + 4], eax
// 00470d49  8bc1                 mov eax, ecx
// 00470d4b  5e                   pop esi
// 00470d4c  83c414               add esp, 0x14
// 00470d4f  c21000               ret 0x10
// standard library map_str<ptr> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@2@@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
