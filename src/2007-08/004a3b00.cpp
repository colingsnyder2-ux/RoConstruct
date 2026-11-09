// from server: 100% by auto
// roc 2007-08 004a3b00  unit: boost::Vmutex::?$sp_counted_impl_p  size: 446 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004a3b00
//
// 004a3b00  83ec0c               sub esp, 0xc
// 004a3b03  56                   push esi
// 004a3b04  8bf1                 mov esi, ecx
// 004a3b06  837e0800             cmp dword ptr [esi + 8], 0
// 004a3b0a  57                   push edi
// 004a3b0b  7521                 jne 0x4a3b2e
// 004a3b0d  8b442424             mov eax, dword ptr [esp + 0x24]
// 004a3b11  8b4e04               mov ecx, dword ptr [esi + 4]
// 004a3b14  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 004a3b18  50                   push eax
// 004a3b19  51                   push ecx
// 004a3b1a  6a01                 push 1
// 004a3b1c  57                   push edi
// 004a3b1d  8bce                 mov ecx, esi
// 004a3b1f  e88cf8f8ff           call 0x4333b0
// 004a3b24  8bc7                 mov eax, edi
// 004a3b26  5f                   pop edi
// 004a3b27  5e                   pop esi
// 004a3b28  83c40c               add esp, 0xc
// 004a3b2b  c21000               ret 0x10
// 004a3b2e  8b5604               mov edx, dword ptr [esi + 4]
// 004a3b31  8b3a                 mov edi, dword ptr [edx]
// 004a3b33  55                   push ebp
// 004a3b34  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 004a3b38  85ed                 test ebp, ebp
// 004a3b3a  7404                 je 0x4a3b40
// 004a3b3c  3bee                 cmp ebp, esi
// 004a3b3e  7406                 je 0x4a3b46
// 004a3b40  ff15d8e67700         call dword ptr [0x77e6d8]
// 004a3b46  53                   push ebx
// 004a3b47  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 004a3b4b  3bdf                 cmp ebx, edi
// 004a3b4d  752b                 jne 0x4a3b7a
// 004a3b4f  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 004a3b53  8b07                 mov eax, dword ptr [edi]
// 004a3b55  3b430c               cmp eax, dword ptr [ebx + 0xc]
// 004a3b58  0f8d39010000         jge 0x4a3c97
// 004a3b5e  57                   push edi
// 004a3b5f  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 004a3b63  53                   push ebx
// 004a3b64  6a01                 push 1
// 004a3b66  57                   push edi
// 004a3b67  8bce                 mov ecx, esi
// 004a3b69  e842f8f8ff           call 0x4333b0
// 004a3b6e  5b                   pop ebx
// 004a3b6f  5d                   pop ebp
// 004a3b70  8bc7                 mov eax, edi
// 004a3b72  5f                   pop edi
// 004a3b73  5e                   pop esi
// 004a3b74  83c40c               add esp, 0xc
// 004a3b77  c21000               ret 0x10
// 004a3b7a  85ed                 test ebp, ebp
// 004a3b7c  8b7e04               mov edi, dword ptr [esi + 4]
// 004a3b7f  7404                 je 0x4a3b85
// 004a3b81  3bee                 cmp ebp, esi
// 004a3b83  7406                 je 0x4a3b8b
// 004a3b85  ff15d8e67700         call dword ptr [0x77e6d8]
// 004a3b8b  3bdf                 cmp ebx, edi
// 004a3b8d  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 004a3b91  752d                 jne 0x4a3bc0
// 004a3b93  8b4e04               mov ecx, dword ptr [esi + 4]
// 004a3b96  8b4108               mov eax, dword ptr [ecx + 8]
// 004a3b99  8b500c               mov edx, dword ptr [eax + 0xc]
// 004a3b9c  3b17                 cmp edx, dword ptr [edi]
// 004a3b9e  0f8df3000000         jge 0x4a3c97
// 004a3ba4  57                   push edi
// 004a3ba5  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 004a3ba9  50                   push eax
// 004a3baa  6a00                 push 0
// 004a3bac  57                   push edi
// 004a3bad  8bce                 mov ecx, esi
// 004a3baf  e8fcf7f8ff           call 0x4333b0
// 004a3bb4  5b                   pop ebx
// 004a3bb5  5d                   pop ebp
// 004a3bb6  8bc7                 mov eax, edi
// 004a3bb8  5f                   pop edi
// 004a3bb9  5e                   pop esi
// 004a3bba  83c40c               add esp, 0xc
// 004a3bbd  c21000               ret 0x10
// 004a3bc0  8b07                 mov eax, dword ptr [edi]
// 004a3bc2  39430c               cmp dword ptr [ebx + 0xc], eax
// 004a3bc5  7e5b                 jle 0x4a3c22
// 004a3bc7  8d4c2424             lea ecx, [esp + 0x24]
// 004a3bcb  896c2424             mov dword ptr [esp + 0x24], ebp
// 004a3bcf  895c2428             mov dword ptr [esp + 0x28], ebx
// 004a3bd3  e858b60400           call 0x4ef230
// 004a3bd8  8b07                 mov eax, dword ptr [edi]
// 004a3bda  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004a3bde  39410c               cmp dword ptr [ecx + 0xc], eax
// 004a3be1  7d3c                 jge 0x4a3c1f
// 004a3be3  8b4108               mov eax, dword ptr [ecx + 8]
// 004a3be6  80781500             cmp byte ptr [eax + 0x15], 0
// 004a3bea  57                   push edi
// 004a3beb  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 004a3bef  7417                 je 0x4a3c08
// 004a3bf1  51                   push ecx
// 004a3bf2  6a00                 push 0
// 004a3bf4  57                   push edi
// 004a3bf5  8bce                 mov ecx, esi
// 004a3bf7  e8b4f7f8ff           call 0x4333b0
// 004a3bfc  5b                   pop ebx
// 004a3bfd  5d                   pop ebp
// 004a3bfe  8bc7                 mov eax, edi
// 004a3c00  5f                   pop edi
// 004a3c01  5e                   pop esi
// 004a3c02  83c40c               add esp, 0xc
// 004a3c05  c21000               ret 0x10
// 004a3c08  53                   push ebx
// 004a3c09  6a01                 push 1
// 004a3c0b  57                   push edi
// 004a3c0c  8bce                 mov ecx, esi
// 004a3c0e  e89df7f8ff           call 0x4333b0
// 004a3c13  5b                   pop ebx
// 004a3c14  5d                   pop ebp
// 004a3c15  8bc7                 mov eax, edi
// 004a3c17  5f                   pop edi
// 004a3c18  5e                   pop esi
// 004a3c19  83c40c               add esp, 0xc
// 004a3c1c  c21000               ret 0x10
// 004a3c1f  39430c               cmp dword ptr [ebx + 0xc], eax
// 004a3c22  7d73                 jge 0x4a3c97
// 004a3c24  8b4e04               mov ecx, dword ptr [esi + 4]
// 004a3c27  894c2414             mov dword ptr [esp + 0x14], ecx
// 004a3c2b  8d4c2424             lea ecx, [esp + 0x24]
// 004a3c2f  896c2424             mov dword ptr [esp + 0x24], ebp
// 004a3c33  895c2428             mov dword ptr [esp + 0x28], ebx
// 004a3c37  89742410             mov dword ptr [esp + 0x10], esi
// 004a3c3b  e87052f9ff           call 0x438eb0
// 004a3c40  8d542410             lea edx, [esp + 0x10]
// 004a3c44  52                   push edx
// 004a3c45  8d4c2428             lea ecx, [esp + 0x28]
// 004a3c49  e8622efcff           call 0x466ab0
// 004a3c4e  84c0                 test al, al
// 004a3c50  8b442428             mov eax, dword ptr [esp + 0x28]
// 004a3c54  7507                 jne 0x4a3c5d
// 004a3c56  8b0f                 mov ecx, dword ptr [edi]
// 004a3c58  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 004a3c5b  7d3a                 jge 0x4a3c97
// 004a3c5d  8b5308               mov edx, dword ptr [ebx + 8]
// 004a3c60  807a1500             cmp byte ptr [edx + 0x15], 0
// 004a3c64  57                   push edi
// 004a3c65  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 004a3c69  8bce                 mov ecx, esi
// 004a3c6b  7415                 je 0x4a3c82
// 004a3c6d  53                   push ebx
// 004a3c6e  6a00                 push 0
// 004a3c70  57                   push edi
// 004a3c71  e83af7f8ff           call 0x4333b0
// 004a3c76  5b                   pop ebx
// 004a3c77  5d                   pop ebp
// 004a3c78  8bc7                 mov eax, edi
// 004a3c7a  5f                   pop edi
// 004a3c7b  5e                   pop esi
// 004a3c7c  83c40c               add esp, 0xc
// 004a3c7f  c21000               ret 0x10
// 004a3c82  50                   push eax
// 004a3c83  6a01                 push 1
// 004a3c85  57                   push edi
// 004a3c86  e825f7f8ff           call 0x4333b0
// 004a3c8b  5b                   pop ebx
// 004a3c8c  5d                   pop ebp
// 004a3c8d  8bc7                 mov eax, edi
// 004a3c8f  5f                   pop edi
// 004a3c90  5e                   pop esi
// 004a3c91  83c40c               add esp, 0xc
// 004a3c94  c21000               ret 0x10
// 004a3c97  57                   push edi
// 004a3c98  8d442414             lea eax, [esp + 0x14]
// 004a3c9c  50                   push eax
// 004a3c9d  8bce                 mov ecx, esi
// 004a3c9f  e8bcfbffff           call 0x4a3860
// 004a3ca4  8b10                 mov edx, dword ptr [eax]
// 004a3ca6  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004a3caa  5b                   pop ebx
// 004a3cab  5d                   pop ebp
// 004a3cac  8911                 mov dword ptr [ecx], edx
// 004a3cae  8b4004               mov eax, dword ptr [eax + 4]
// 004a3cb1  5f                   pop edi
// 004a3cb2  894104               mov dword ptr [ecx + 4], eax
// 004a3cb5  8bc1                 mov eax, ecx
// 004a3cb7  5e                   pop esi
// 004a3cb8  83c40c               add esp, 0xc
// 004a3cbb  c21000               ret 0x10
// standard library map_int<ptr> (function ?insert@?$_Tree@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@std@@QAE?AViterator@12@V312@ABU?$pair@$$CBHPAUT@@@2@@Z)

// stl: map_int<ptr>
struct T; typedef T* E;
#include <map>
template class std::map<int, E>;
