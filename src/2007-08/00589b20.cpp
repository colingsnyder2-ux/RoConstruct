// from server: 100% by auto
// roc 2007-08 00589b20  unit: VStockSound::?$FactoryProduct  size: 446 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00589b20
//
// 00589b20  83ec0c               sub esp, 0xc
// 00589b23  56                   push esi
// 00589b24  8bf1                 mov esi, ecx
// 00589b26  837e0800             cmp dword ptr [esi + 8], 0
// 00589b2a  57                   push edi
// 00589b2b  7521                 jne 0x589b4e
// 00589b2d  8b442424             mov eax, dword ptr [esp + 0x24]
// 00589b31  8b4e04               mov ecx, dword ptr [esi + 4]
// 00589b34  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 00589b38  50                   push eax
// 00589b39  51                   push ecx
// 00589b3a  6a01                 push 1
// 00589b3c  57                   push edi
// 00589b3d  8bce                 mov ecx, esi
// 00589b3f  e89cf4ffff           call 0x588fe0
// 00589b44  8bc7                 mov eax, edi
// 00589b46  5f                   pop edi
// 00589b47  5e                   pop esi
// 00589b48  83c40c               add esp, 0xc
// 00589b4b  c21000               ret 0x10
// 00589b4e  8b5604               mov edx, dword ptr [esi + 4]
// 00589b51  8b3a                 mov edi, dword ptr [edx]
// 00589b53  55                   push ebp
// 00589b54  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 00589b58  85ed                 test ebp, ebp
// 00589b5a  7404                 je 0x589b60
// 00589b5c  3bee                 cmp ebp, esi
// 00589b5e  7406                 je 0x589b66
// 00589b60  ff15d8e67700         call dword ptr [0x77e6d8]
// 00589b66  53                   push ebx
// 00589b67  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 00589b6b  3bdf                 cmp ebx, edi
// 00589b6d  752b                 jne 0x589b9a
// 00589b6f  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00589b73  8b07                 mov eax, dword ptr [edi]
// 00589b75  3b430c               cmp eax, dword ptr [ebx + 0xc]
// 00589b78  0f8d39010000         jge 0x589cb7
// 00589b7e  57                   push edi
// 00589b7f  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00589b83  53                   push ebx
// 00589b84  6a01                 push 1
// 00589b86  57                   push edi
// 00589b87  8bce                 mov ecx, esi
// 00589b89  e852f4ffff           call 0x588fe0
// 00589b8e  5b                   pop ebx
// 00589b8f  5d                   pop ebp
// 00589b90  8bc7                 mov eax, edi
// 00589b92  5f                   pop edi
// 00589b93  5e                   pop esi
// 00589b94  83c40c               add esp, 0xc
// 00589b97  c21000               ret 0x10
// 00589b9a  85ed                 test ebp, ebp
// 00589b9c  8b7e04               mov edi, dword ptr [esi + 4]
// 00589b9f  7404                 je 0x589ba5
// 00589ba1  3bee                 cmp ebp, esi
// 00589ba3  7406                 je 0x589bab
// 00589ba5  ff15d8e67700         call dword ptr [0x77e6d8]
// 00589bab  3bdf                 cmp ebx, edi
// 00589bad  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00589bb1  752d                 jne 0x589be0
// 00589bb3  8b4e04               mov ecx, dword ptr [esi + 4]
// 00589bb6  8b4108               mov eax, dword ptr [ecx + 8]
// 00589bb9  8b500c               mov edx, dword ptr [eax + 0xc]
// 00589bbc  3b17                 cmp edx, dword ptr [edi]
// 00589bbe  0f8df3000000         jge 0x589cb7
// 00589bc4  57                   push edi
// 00589bc5  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00589bc9  50                   push eax
// 00589bca  6a00                 push 0
// 00589bcc  57                   push edi
// 00589bcd  8bce                 mov ecx, esi
// 00589bcf  e80cf4ffff           call 0x588fe0
// 00589bd4  5b                   pop ebx
// 00589bd5  5d                   pop ebp
// 00589bd6  8bc7                 mov eax, edi
// 00589bd8  5f                   pop edi
// 00589bd9  5e                   pop esi
// 00589bda  83c40c               add esp, 0xc
// 00589bdd  c21000               ret 0x10
// 00589be0  8b07                 mov eax, dword ptr [edi]
// 00589be2  39430c               cmp dword ptr [ebx + 0xc], eax
// 00589be5  7e5b                 jle 0x589c42
// 00589be7  8d4c2424             lea ecx, [esp + 0x24]
// 00589beb  896c2424             mov dword ptr [esp + 0x24], ebp
// 00589bef  895c2428             mov dword ptr [esp + 0x28], ebx
// 00589bf3  e838e0ffff           call 0x587c30
// 00589bf8  8b07                 mov eax, dword ptr [edi]
// 00589bfa  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00589bfe  39410c               cmp dword ptr [ecx + 0xc], eax
// 00589c01  7d3c                 jge 0x589c3f
// 00589c03  8b4108               mov eax, dword ptr [ecx + 8]
// 00589c06  80781900             cmp byte ptr [eax + 0x19], 0
// 00589c0a  57                   push edi
// 00589c0b  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00589c0f  7417                 je 0x589c28
// 00589c11  51                   push ecx
// 00589c12  6a00                 push 0
// 00589c14  57                   push edi
// 00589c15  8bce                 mov ecx, esi
// 00589c17  e8c4f3ffff           call 0x588fe0
// 00589c1c  5b                   pop ebx
// 00589c1d  5d                   pop ebp
// 00589c1e  8bc7                 mov eax, edi
// 00589c20  5f                   pop edi
// 00589c21  5e                   pop esi
// 00589c22  83c40c               add esp, 0xc
// 00589c25  c21000               ret 0x10
// 00589c28  53                   push ebx
// 00589c29  6a01                 push 1
// 00589c2b  57                   push edi
// 00589c2c  8bce                 mov ecx, esi
// 00589c2e  e8adf3ffff           call 0x588fe0
// 00589c33  5b                   pop ebx
// 00589c34  5d                   pop ebp
// 00589c35  8bc7                 mov eax, edi
// 00589c37  5f                   pop edi
// 00589c38  5e                   pop esi
// 00589c39  83c40c               add esp, 0xc
// 00589c3c  c21000               ret 0x10
// 00589c3f  39430c               cmp dword ptr [ebx + 0xc], eax
// 00589c42  7d73                 jge 0x589cb7
// 00589c44  8b4e04               mov ecx, dword ptr [esi + 4]
// 00589c47  894c2414             mov dword ptr [esp + 0x14], ecx
// 00589c4b  8d4c2424             lea ecx, [esp + 0x24]
// 00589c4f  896c2424             mov dword ptr [esp + 0x24], ebp
// 00589c53  895c2428             mov dword ptr [esp + 0x28], ebx
// 00589c57  89742410             mov dword ptr [esp + 0x10], esi
// 00589c5b  e860e0ffff           call 0x587cc0
// 00589c60  8d542410             lea edx, [esp + 0x10]
// 00589c64  52                   push edx
// 00589c65  8d4c2428             lea ecx, [esp + 0x28]
// 00589c69  e842ceedff           call 0x466ab0
// 00589c6e  84c0                 test al, al
// 00589c70  8b442428             mov eax, dword ptr [esp + 0x28]
// 00589c74  7507                 jne 0x589c7d
// 00589c76  8b0f                 mov ecx, dword ptr [edi]
// 00589c78  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 00589c7b  7d3a                 jge 0x589cb7
// 00589c7d  8b5308               mov edx, dword ptr [ebx + 8]
// 00589c80  807a1900             cmp byte ptr [edx + 0x19], 0
// 00589c84  57                   push edi
// 00589c85  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00589c89  8bce                 mov ecx, esi
// 00589c8b  7415                 je 0x589ca2
// 00589c8d  53                   push ebx
// 00589c8e  6a00                 push 0
// 00589c90  57                   push edi
// 00589c91  e84af3ffff           call 0x588fe0
// 00589c96  5b                   pop ebx
// 00589c97  5d                   pop ebp
// 00589c98  8bc7                 mov eax, edi
// 00589c9a  5f                   pop edi
// 00589c9b  5e                   pop esi
// 00589c9c  83c40c               add esp, 0xc
// 00589c9f  c21000               ret 0x10
// 00589ca2  50                   push eax
// 00589ca3  6a01                 push 1
// 00589ca5  57                   push edi
// 00589ca6  e835f3ffff           call 0x588fe0
// 00589cab  5b                   pop ebx
// 00589cac  5d                   pop ebp
// 00589cad  8bc7                 mov eax, edi
// 00589caf  5f                   pop edi
// 00589cb0  5e                   pop esi
// 00589cb1  83c40c               add esp, 0xc
// 00589cb4  c21000               ret 0x10
// 00589cb7  57                   push edi
// 00589cb8  8d442414             lea eax, [esp + 0x14]
// 00589cbc  50                   push eax
// 00589cbd  8bce                 mov ecx, esi
// 00589cbf  e8ccfbffff           call 0x589890
// 00589cc4  8b10                 mov edx, dword ptr [eax]
// 00589cc6  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00589cca  5b                   pop ebx
// 00589ccb  5d                   pop ebp
// 00589ccc  8911                 mov dword ptr [ecx], edx
// 00589cce  8b4004               mov eax, dword ptr [eax + 4]
// 00589cd1  5f                   pop edi
// 00589cd2  894104               mov dword ptr [ecx + 4], eax
// 00589cd5  8bc1                 mov eax, ecx
// 00589cd7  5e                   pop esi
// 00589cd8  83c40c               add esp, 0xc
// 00589cdb  c21000               ret 0x10
// standard library map_int<pod8> (function ?insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAE?AViterator@12@V312@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod8>
struct E { int v[2]; };
#include <map>
template class std::map<int, E>;
