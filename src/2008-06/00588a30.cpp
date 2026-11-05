// from server: 100% by auto
// roc 2008-06 00588a30  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 470 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00588a30
//
// 00588a30  83ec14               sub esp, 0x14
// 00588a33  56                   push esi
// 00588a34  8bf1                 mov esi, ecx
// 00588a36  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 00588a3a  57                   push edi
// 00588a3b  7521                 jne 0x588a5e
// 00588a3d  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00588a41  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00588a44  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00588a48  50                   push eax
// 00588a49  51                   push ecx
// 00588a4a  6a01                 push 1
// 00588a4c  57                   push edi
// 00588a4d  8bce                 mov ecx, esi
// 00588a4f  e8ccedffff           call 0x587820
// 00588a54  8bc7                 mov eax, edi
// 00588a56  5f                   pop edi
// 00588a57  5e                   pop esi
// 00588a58  83c414               add esp, 0x14
// 00588a5b  c21000               ret 0x10
// 00588a5e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00588a62  8b5618               mov edx, dword ptr [esi + 0x18]
// 00588a65  8b3a                 mov edi, dword ptr [edx]
// 00588a67  8b06                 mov eax, dword ptr [esi]
// 00588a69  53                   push ebx
// 00588a6a  8b1d90288000         mov ebx, dword ptr [0x802890]
// 00588a70  85c9                 test ecx, ecx
// 00588a72  7404                 je 0x588a78
// 00588a74  3bc8                 cmp ecx, eax
// 00588a76  7406                 je 0x588a7e
// 00588a78  ffd3                 call ebx
// 00588a7a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00588a7e  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00588a82  3bc7                 cmp eax, edi
// 00588a84  752a                 jne 0x588ab0
// 00588a86  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 00588a8a  8b0f                 mov ecx, dword ptr [edi]
// 00588a8c  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 00588a8f  0f834b010000         jae 0x588be0
// 00588a95  57                   push edi
// 00588a96  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00588a9a  50                   push eax
// 00588a9b  6a01                 push 1
// 00588a9d  57                   push edi
// 00588a9e  8bce                 mov ecx, esi
// 00588aa0  e87bedffff           call 0x587820
// 00588aa5  5b                   pop ebx
// 00588aa6  8bc7                 mov eax, edi
// 00588aa8  5f                   pop edi
// 00588aa9  5e                   pop esi
// 00588aaa  83c414               add esp, 0x14
// 00588aad  c21000               ret 0x10
// 00588ab0  8b7e18               mov edi, dword ptr [esi + 0x18]
// 00588ab3  8b16                 mov edx, dword ptr [esi]
// 00588ab5  85c9                 test ecx, ecx
// 00588ab7  7404                 je 0x588abd
// 00588ab9  3bca                 cmp ecx, edx
// 00588abb  740a                 je 0x588ac7
// 00588abd  ffd3                 call ebx
// 00588abf  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00588ac3  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00588ac7  3bc7                 cmp eax, edi
// 00588ac9  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 00588acd  752c                 jne 0x588afb
// 00588acf  8b5618               mov edx, dword ptr [esi + 0x18]
// 00588ad2  8b4208               mov eax, dword ptr [edx + 8]
// 00588ad5  8b480c               mov ecx, dword ptr [eax + 0xc]
// 00588ad8  3b0f                 cmp ecx, dword ptr [edi]
// 00588ada  0f8300010000         jae 0x588be0
// 00588ae0  57                   push edi
// 00588ae1  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00588ae5  50                   push eax
// 00588ae6  6a00                 push 0
// 00588ae8  57                   push edi
// 00588ae9  8bce                 mov ecx, esi
// 00588aeb  e830edffff           call 0x587820
// 00588af0  5b                   pop ebx
// 00588af1  8bc7                 mov eax, edi
// 00588af3  5f                   pop edi
// 00588af4  5e                   pop esi
// 00588af5  83c414               add esp, 0x14
// 00588af8  c21000               ret 0x10
// 00588afb  8b17                 mov edx, dword ptr [edi]
// 00588afd  39500c               cmp dword ptr [eax + 0xc], edx
// 00588b00  7663                 jbe 0x588b65
// 00588b02  894c240c             mov dword ptr [esp + 0xc], ecx
// 00588b06  8d4c240c             lea ecx, [esp + 0xc]
// 00588b0a  89442410             mov dword ptr [esp + 0x10], eax
// 00588b0e  e82d34f2ff           call 0x4abf40
// 00588b13  8b17                 mov edx, dword ptr [edi]
// 00588b15  8b442410             mov eax, dword ptr [esp + 0x10]
// 00588b19  39500c               cmp dword ptr [eax + 0xc], edx
// 00588b1c  733c                 jae 0x588b5a
// 00588b1e  8b5008               mov edx, dword ptr [eax + 8]
// 00588b21  807a1900             cmp byte ptr [edx + 0x19], 0
// 00588b25  57                   push edi
// 00588b26  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00588b2a  8bce                 mov ecx, esi
// 00588b2c  7414                 je 0x588b42
// 00588b2e  50                   push eax
// 00588b2f  6a00                 push 0
// 00588b31  57                   push edi
// 00588b32  e8e9ecffff           call 0x587820
// 00588b37  5b                   pop ebx
// 00588b38  8bc7                 mov eax, edi
// 00588b3a  5f                   pop edi
// 00588b3b  5e                   pop esi
// 00588b3c  83c414               add esp, 0x14
// 00588b3f  c21000               ret 0x10
// 00588b42  8b442430             mov eax, dword ptr [esp + 0x30]
// 00588b46  50                   push eax
// 00588b47  6a01                 push 1
// 00588b49  57                   push edi
// 00588b4a  e8d1ecffff           call 0x587820
// 00588b4f  5b                   pop ebx
// 00588b50  8bc7                 mov eax, edi
// 00588b52  5f                   pop edi
// 00588b53  5e                   pop esi
// 00588b54  83c414               add esp, 0x14
// 00588b57  c21000               ret 0x10
// 00588b5a  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00588b5e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00588b62  39500c               cmp dword ptr [eax + 0xc], edx
// 00588b65  7379                 jae 0x588be0
// 00588b67  8b16                 mov edx, dword ptr [esi]
// 00588b69  894c240c             mov dword ptr [esp + 0xc], ecx
// 00588b6d  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00588b70  894c2418             mov dword ptr [esp + 0x18], ecx
// 00588b74  8d4c240c             lea ecx, [esp + 0xc]
// 00588b78  89442410             mov dword ptr [esp + 0x10], eax
// 00588b7c  89542414             mov dword ptr [esp + 0x14], edx
// 00588b80  e8cbe60200           call 0x5b7250
// 00588b85  8d442414             lea eax, [esp + 0x14]
// 00588b89  50                   push eax
// 00588b8a  8d4c2410             lea ecx, [esp + 0x10]
// 00588b8e  e80d410600           call 0x5ecca0
// 00588b93  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00588b97  84c0                 test al, al
// 00588b99  7507                 jne 0x588ba2
// 00588b9b  8b17                 mov edx, dword ptr [edi]
// 00588b9d  3b510c               cmp edx, dword ptr [ecx + 0xc]
// 00588ba0  733e                 jae 0x588be0
// 00588ba2  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00588ba6  8b5008               mov edx, dword ptr [eax + 8]
// 00588ba9  807a1900             cmp byte ptr [edx + 0x19], 0
// 00588bad  57                   push edi
// 00588bae  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00588bb2  7416                 je 0x588bca
// 00588bb4  50                   push eax
// 00588bb5  6a00                 push 0
// 00588bb7  57                   push edi
// 00588bb8  8bce                 mov ecx, esi
// 00588bba  e861ecffff           call 0x587820
// 00588bbf  5b                   pop ebx
// 00588bc0  8bc7                 mov eax, edi
// 00588bc2  5f                   pop edi
// 00588bc3  5e                   pop esi
// 00588bc4  83c414               add esp, 0x14
// 00588bc7  c21000               ret 0x10
// 00588bca  51                   push ecx
// 00588bcb  6a01                 push 1
// 00588bcd  57                   push edi
// 00588bce  8bce                 mov ecx, esi
// 00588bd0  e84becffff           call 0x587820
// 00588bd5  5b                   pop ebx
// 00588bd6  8bc7                 mov eax, edi
// 00588bd8  5f                   pop edi
// 00588bd9  5e                   pop esi
// 00588bda  83c414               add esp, 0x14
// 00588bdd  c21000               ret 0x10
// 00588be0  57                   push edi
// 00588be1  8d442418             lea eax, [esp + 0x18]
// 00588be5  50                   push eax
// 00588be6  8bce                 mov ecx, esi
// 00588be8  e8d3f1ffff           call 0x587dc0
// 00588bed  8b10                 mov edx, dword ptr [eax]
// 00588bef  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00588bf3  5b                   pop ebx
// 00588bf4  8911                 mov dword ptr [ecx], edx
// 00588bf6  8b4004               mov eax, dword ptr [eax + 4]
// 00588bf9  5f                   pop edi
// 00588bfa  894104               mov dword ptr [ecx + 4], eax
// 00588bfd  8bc1                 mov eax, ecx
// 00588bff  5e                   pop esi
// 00588c00  83c414               add esp, 0x14
// 00588c03  c21000               ret 0x10
// standard library map_ptr<pod8> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod8>
struct E { int v[2]; };
#include <map>
struct K; template class std::map<K*, E>;
