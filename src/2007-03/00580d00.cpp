// from server: 100% by auto
// roc 2007-03 00580d00  unit: seg_00580000  size: 446 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00580d00
//
// 00580d00  83ec0c               sub esp, 0xc
// 00580d03  56                   push esi
// 00580d04  8bf1                 mov esi, ecx
// 00580d06  837e0800             cmp dword ptr [esi + 8], 0
// 00580d0a  57                   push edi
// 00580d0b  7521                 jne 0x580d2e
// 00580d0d  8b442424             mov eax, dword ptr [esp + 0x24]
// 00580d11  8b4e04               mov ecx, dword ptr [esi + 4]
// 00580d14  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 00580d18  50                   push eax
// 00580d19  51                   push ecx
// 00580d1a  6a01                 push 1
// 00580d1c  57                   push edi
// 00580d1d  8bce                 mov ecx, esi
// 00580d1f  e86cf6ffff           call 0x580390
// 00580d24  8bc7                 mov eax, edi
// 00580d26  5f                   pop edi
// 00580d27  5e                   pop esi
// 00580d28  83c40c               add esp, 0xc
// 00580d2b  c21000               ret 0x10
// 00580d2e  8b5604               mov edx, dword ptr [esi + 4]
// 00580d31  8b3a                 mov edi, dword ptr [edx]
// 00580d33  55                   push ebp
// 00580d34  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 00580d38  85ed                 test ebp, ebp
// 00580d3a  7404                 je 0x580d40
// 00580d3c  3bee                 cmp ebp, esi
// 00580d3e  7406                 je 0x580d46
// 00580d40  ff1544e97700         call dword ptr [0x77e944]
// 00580d46  53                   push ebx
// 00580d47  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 00580d4b  3bdf                 cmp ebx, edi
// 00580d4d  752b                 jne 0x580d7a
// 00580d4f  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00580d53  8b07                 mov eax, dword ptr [edi]
// 00580d55  3b430c               cmp eax, dword ptr [ebx + 0xc]
// 00580d58  0f8d39010000         jge 0x580e97
// 00580d5e  57                   push edi
// 00580d5f  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00580d63  53                   push ebx
// 00580d64  6a01                 push 1
// 00580d66  57                   push edi
// 00580d67  8bce                 mov ecx, esi
// 00580d69  e822f6ffff           call 0x580390
// 00580d6e  5b                   pop ebx
// 00580d6f  5d                   pop ebp
// 00580d70  8bc7                 mov eax, edi
// 00580d72  5f                   pop edi
// 00580d73  5e                   pop esi
// 00580d74  83c40c               add esp, 0xc
// 00580d77  c21000               ret 0x10
// 00580d7a  85ed                 test ebp, ebp
// 00580d7c  8b7e04               mov edi, dword ptr [esi + 4]
// 00580d7f  7404                 je 0x580d85
// 00580d81  3bee                 cmp ebp, esi
// 00580d83  7406                 je 0x580d8b
// 00580d85  ff1544e97700         call dword ptr [0x77e944]
// 00580d8b  3bdf                 cmp ebx, edi
// 00580d8d  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00580d91  752d                 jne 0x580dc0
// 00580d93  8b4e04               mov ecx, dword ptr [esi + 4]
// 00580d96  8b4108               mov eax, dword ptr [ecx + 8]
// 00580d99  8b500c               mov edx, dword ptr [eax + 0xc]
// 00580d9c  3b17                 cmp edx, dword ptr [edi]
// 00580d9e  0f8df3000000         jge 0x580e97
// 00580da4  57                   push edi
// 00580da5  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00580da9  50                   push eax
// 00580daa  6a00                 push 0
// 00580dac  57                   push edi
// 00580dad  8bce                 mov ecx, esi
// 00580daf  e8dcf5ffff           call 0x580390
// 00580db4  5b                   pop ebx
// 00580db5  5d                   pop ebp
// 00580db6  8bc7                 mov eax, edi
// 00580db8  5f                   pop edi
// 00580db9  5e                   pop esi
// 00580dba  83c40c               add esp, 0xc
// 00580dbd  c21000               ret 0x10
// 00580dc0  8b07                 mov eax, dword ptr [edi]
// 00580dc2  39430c               cmp dword ptr [ebx + 0xc], eax
// 00580dc5  7e5b                 jle 0x580e22
// 00580dc7  8d4c2424             lea ecx, [esp + 0x24]
// 00580dcb  896c2424             mov dword ptr [esp + 0x24], ebp
// 00580dcf  895c2428             mov dword ptr [esp + 0x28], ebx
// 00580dd3  e8d83ef4ff           call 0x4c4cb0
// 00580dd8  8b07                 mov eax, dword ptr [edi]
// 00580dda  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00580dde  39410c               cmp dword ptr [ecx + 0xc], eax
// 00580de1  7d3c                 jge 0x580e1f
// 00580de3  8b4108               mov eax, dword ptr [ecx + 8]
// 00580de6  80782100             cmp byte ptr [eax + 0x21], 0
// 00580dea  57                   push edi
// 00580deb  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00580def  7417                 je 0x580e08
// 00580df1  51                   push ecx
// 00580df2  6a00                 push 0
// 00580df4  57                   push edi
// 00580df5  8bce                 mov ecx, esi
// 00580df7  e894f5ffff           call 0x580390
// 00580dfc  5b                   pop ebx
// 00580dfd  5d                   pop ebp
// 00580dfe  8bc7                 mov eax, edi
// 00580e00  5f                   pop edi
// 00580e01  5e                   pop esi
// 00580e02  83c40c               add esp, 0xc
// 00580e05  c21000               ret 0x10
// 00580e08  53                   push ebx
// 00580e09  6a01                 push 1
// 00580e0b  57                   push edi
// 00580e0c  8bce                 mov ecx, esi
// 00580e0e  e87df5ffff           call 0x580390
// 00580e13  5b                   pop ebx
// 00580e14  5d                   pop ebp
// 00580e15  8bc7                 mov eax, edi
// 00580e17  5f                   pop edi
// 00580e18  5e                   pop esi
// 00580e19  83c40c               add esp, 0xc
// 00580e1c  c21000               ret 0x10
// 00580e1f  39430c               cmp dword ptr [ebx + 0xc], eax
// 00580e22  7d73                 jge 0x580e97
// 00580e24  8b4e04               mov ecx, dword ptr [esi + 4]
// 00580e27  894c2414             mov dword ptr [esp + 0x14], ecx
// 00580e2b  8d4c2424             lea ecx, [esp + 0x24]
// 00580e2f  896c2424             mov dword ptr [esp + 0x24], ebp
// 00580e33  895c2428             mov dword ptr [esp + 0x28], ebx
// 00580e37  89742410             mov dword ptr [esp + 0x10], esi
// 00580e3b  e8e073f1ff           call 0x498220
// 00580e40  8d542410             lea edx, [esp + 0x10]
// 00580e44  52                   push edx
// 00580e45  8d4c2428             lea ecx, [esp + 0x28]
// 00580e49  e812aeecff           call 0x44bc60
// 00580e4e  84c0                 test al, al
// 00580e50  8b442428             mov eax, dword ptr [esp + 0x28]
// 00580e54  7507                 jne 0x580e5d
// 00580e56  8b0f                 mov ecx, dword ptr [edi]
// 00580e58  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 00580e5b  7d3a                 jge 0x580e97
// 00580e5d  8b5308               mov edx, dword ptr [ebx + 8]
// 00580e60  807a2100             cmp byte ptr [edx + 0x21], 0
// 00580e64  57                   push edi
// 00580e65  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00580e69  8bce                 mov ecx, esi
// 00580e6b  7415                 je 0x580e82
// 00580e6d  53                   push ebx
// 00580e6e  6a00                 push 0
// 00580e70  57                   push edi
// 00580e71  e81af5ffff           call 0x580390
// 00580e76  5b                   pop ebx
// 00580e77  5d                   pop ebp
// 00580e78  8bc7                 mov eax, edi
// 00580e7a  5f                   pop edi
// 00580e7b  5e                   pop esi
// 00580e7c  83c40c               add esp, 0xc
// 00580e7f  c21000               ret 0x10
// 00580e82  50                   push eax
// 00580e83  6a01                 push 1
// 00580e85  57                   push edi
// 00580e86  e805f5ffff           call 0x580390
// 00580e8b  5b                   pop ebx
// 00580e8c  5d                   pop ebp
// 00580e8d  8bc7                 mov eax, edi
// 00580e8f  5f                   pop edi
// 00580e90  5e                   pop esi
// 00580e91  83c40c               add esp, 0xc
// 00580e94  c21000               ret 0x10
// 00580e97  57                   push edi
// 00580e98  8d442414             lea eax, [esp + 0x14]
// 00580e9c  50                   push eax
// 00580e9d  8bce                 mov ecx, esi
// 00580e9f  e86cfcffff           call 0x580b10
// 00580ea4  8b10                 mov edx, dword ptr [eax]
// 00580ea6  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00580eaa  5b                   pop ebx
// 00580eab  5d                   pop ebp
// 00580eac  8911                 mov dword ptr [ecx], edx
// 00580eae  8b4004               mov eax, dword ptr [eax + 4]
// 00580eb1  5f                   pop edi
// 00580eb2  894104               mov dword ptr [ecx + 4], eax
// 00580eb5  8bc1                 mov eax, ecx
// 00580eb7  5e                   pop esi
// 00580eb8  83c40c               add esp, 0xc
// 00580ebb  c21000               ret 0x10
// standard library map_int<pod16> (function ?insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAE?AViterator@12@V312@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod16>
struct E { int v[4]; };
#include <map>
template class std::map<int, E>;
