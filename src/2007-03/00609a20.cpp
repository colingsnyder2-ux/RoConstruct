// from server: 100% by auto
// roc 2007-03 00609a20  unit: seg_00600000  size: 446 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00609a20
//
// 00609a20  83ec0c               sub esp, 0xc
// 00609a23  56                   push esi
// 00609a24  8bf1                 mov esi, ecx
// 00609a26  837e0800             cmp dword ptr [esi + 8], 0
// 00609a2a  57                   push edi
// 00609a2b  7521                 jne 0x609a4e
// 00609a2d  8b442424             mov eax, dword ptr [esp + 0x24]
// 00609a31  8b4e04               mov ecx, dword ptr [esi + 4]
// 00609a34  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 00609a38  50                   push eax
// 00609a39  51                   push ecx
// 00609a3a  6a01                 push 1
// 00609a3c  57                   push edi
// 00609a3d  8bce                 mov ecx, esi
// 00609a3f  e89cf5ffff           call 0x608fe0
// 00609a44  8bc7                 mov eax, edi
// 00609a46  5f                   pop edi
// 00609a47  5e                   pop esi
// 00609a48  83c40c               add esp, 0xc
// 00609a4b  c21000               ret 0x10
// 00609a4e  8b5604               mov edx, dword ptr [esi + 4]
// 00609a51  8b3a                 mov edi, dword ptr [edx]
// 00609a53  55                   push ebp
// 00609a54  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 00609a58  85ed                 test ebp, ebp
// 00609a5a  7404                 je 0x609a60
// 00609a5c  3bee                 cmp ebp, esi
// 00609a5e  7406                 je 0x609a66
// 00609a60  ff1544e97700         call dword ptr [0x77e944]
// 00609a66  53                   push ebx
// 00609a67  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 00609a6b  3bdf                 cmp ebx, edi
// 00609a6d  752b                 jne 0x609a9a
// 00609a6f  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00609a73  8b07                 mov eax, dword ptr [edi]
// 00609a75  3b430c               cmp eax, dword ptr [ebx + 0xc]
// 00609a78  0f8339010000         jae 0x609bb7
// 00609a7e  57                   push edi
// 00609a7f  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00609a83  53                   push ebx
// 00609a84  6a01                 push 1
// 00609a86  57                   push edi
// 00609a87  8bce                 mov ecx, esi
// 00609a89  e852f5ffff           call 0x608fe0
// 00609a8e  5b                   pop ebx
// 00609a8f  5d                   pop ebp
// 00609a90  8bc7                 mov eax, edi
// 00609a92  5f                   pop edi
// 00609a93  5e                   pop esi
// 00609a94  83c40c               add esp, 0xc
// 00609a97  c21000               ret 0x10
// 00609a9a  85ed                 test ebp, ebp
// 00609a9c  8b7e04               mov edi, dword ptr [esi + 4]
// 00609a9f  7404                 je 0x609aa5
// 00609aa1  3bee                 cmp ebp, esi
// 00609aa3  7406                 je 0x609aab
// 00609aa5  ff1544e97700         call dword ptr [0x77e944]
// 00609aab  3bdf                 cmp ebx, edi
// 00609aad  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00609ab1  752d                 jne 0x609ae0
// 00609ab3  8b4e04               mov ecx, dword ptr [esi + 4]
// 00609ab6  8b4108               mov eax, dword ptr [ecx + 8]
// 00609ab9  8b500c               mov edx, dword ptr [eax + 0xc]
// 00609abc  3b17                 cmp edx, dword ptr [edi]
// 00609abe  0f83f3000000         jae 0x609bb7
// 00609ac4  57                   push edi
// 00609ac5  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00609ac9  50                   push eax
// 00609aca  6a00                 push 0
// 00609acc  57                   push edi
// 00609acd  8bce                 mov ecx, esi
// 00609acf  e80cf5ffff           call 0x608fe0
// 00609ad4  5b                   pop ebx
// 00609ad5  5d                   pop ebp
// 00609ad6  8bc7                 mov eax, edi
// 00609ad8  5f                   pop edi
// 00609ad9  5e                   pop esi
// 00609ada  83c40c               add esp, 0xc
// 00609add  c21000               ret 0x10
// 00609ae0  8b07                 mov eax, dword ptr [edi]
// 00609ae2  39430c               cmp dword ptr [ebx + 0xc], eax
// 00609ae5  765b                 jbe 0x609b42
// 00609ae7  8d4c2424             lea ecx, [esp + 0x24]
// 00609aeb  896c2424             mov dword ptr [esp + 0x24], ebp
// 00609aef  895c2428             mov dword ptr [esp + 0x28], ebx
// 00609af3  e8b8b1ebff           call 0x4c4cb0
// 00609af8  8b07                 mov eax, dword ptr [edi]
// 00609afa  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00609afe  39410c               cmp dword ptr [ecx + 0xc], eax
// 00609b01  733c                 jae 0x609b3f
// 00609b03  8b4108               mov eax, dword ptr [ecx + 8]
// 00609b06  80782100             cmp byte ptr [eax + 0x21], 0
// 00609b0a  57                   push edi
// 00609b0b  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00609b0f  7417                 je 0x609b28
// 00609b11  51                   push ecx
// 00609b12  6a00                 push 0
// 00609b14  57                   push edi
// 00609b15  8bce                 mov ecx, esi
// 00609b17  e8c4f4ffff           call 0x608fe0
// 00609b1c  5b                   pop ebx
// 00609b1d  5d                   pop ebp
// 00609b1e  8bc7                 mov eax, edi
// 00609b20  5f                   pop edi
// 00609b21  5e                   pop esi
// 00609b22  83c40c               add esp, 0xc
// 00609b25  c21000               ret 0x10
// 00609b28  53                   push ebx
// 00609b29  6a01                 push 1
// 00609b2b  57                   push edi
// 00609b2c  8bce                 mov ecx, esi
// 00609b2e  e8adf4ffff           call 0x608fe0
// 00609b33  5b                   pop ebx
// 00609b34  5d                   pop ebp
// 00609b35  8bc7                 mov eax, edi
// 00609b37  5f                   pop edi
// 00609b38  5e                   pop esi
// 00609b39  83c40c               add esp, 0xc
// 00609b3c  c21000               ret 0x10
// 00609b3f  39430c               cmp dword ptr [ebx + 0xc], eax
// 00609b42  7373                 jae 0x609bb7
// 00609b44  8b4e04               mov ecx, dword ptr [esi + 4]
// 00609b47  894c2414             mov dword ptr [esp + 0x14], ecx
// 00609b4b  8d4c2424             lea ecx, [esp + 0x24]
// 00609b4f  896c2424             mov dword ptr [esp + 0x24], ebp
// 00609b53  895c2428             mov dword ptr [esp + 0x28], ebx
// 00609b57  89742410             mov dword ptr [esp + 0x10], esi
// 00609b5b  e8c0e6e8ff           call 0x498220
// 00609b60  8d542410             lea edx, [esp + 0x10]
// 00609b64  52                   push edx
// 00609b65  8d4c2428             lea ecx, [esp + 0x28]
// 00609b69  e8f220e4ff           call 0x44bc60
// 00609b6e  84c0                 test al, al
// 00609b70  8b442428             mov eax, dword ptr [esp + 0x28]
// 00609b74  7507                 jne 0x609b7d
// 00609b76  8b0f                 mov ecx, dword ptr [edi]
// 00609b78  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 00609b7b  733a                 jae 0x609bb7
// 00609b7d  8b5308               mov edx, dword ptr [ebx + 8]
// 00609b80  807a2100             cmp byte ptr [edx + 0x21], 0
// 00609b84  57                   push edi
// 00609b85  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00609b89  8bce                 mov ecx, esi
// 00609b8b  7415                 je 0x609ba2
// 00609b8d  53                   push ebx
// 00609b8e  6a00                 push 0
// 00609b90  57                   push edi
// 00609b91  e84af4ffff           call 0x608fe0
// 00609b96  5b                   pop ebx
// 00609b97  5d                   pop ebp
// 00609b98  8bc7                 mov eax, edi
// 00609b9a  5f                   pop edi
// 00609b9b  5e                   pop esi
// 00609b9c  83c40c               add esp, 0xc
// 00609b9f  c21000               ret 0x10
// 00609ba2  50                   push eax
// 00609ba3  6a01                 push 1
// 00609ba5  57                   push edi
// 00609ba6  e835f4ffff           call 0x608fe0
// 00609bab  5b                   pop ebx
// 00609bac  5d                   pop ebp
// 00609bad  8bc7                 mov eax, edi
// 00609baf  5f                   pop edi
// 00609bb0  5e                   pop esi
// 00609bb1  83c40c               add esp, 0xc
// 00609bb4  c21000               ret 0x10
// 00609bb7  57                   push edi
// 00609bb8  8d442414             lea eax, [esp + 0x14]
// 00609bbc  50                   push eax
// 00609bbd  8bce                 mov ecx, esi
// 00609bbf  e80cf7ffff           call 0x6092d0
// 00609bc4  8b10                 mov edx, dword ptr [eax]
// 00609bc6  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00609bca  5b                   pop ebx
// 00609bcb  5d                   pop ebp
// 00609bcc  8911                 mov dword ptr [ecx], edx
// 00609bce  8b4004               mov eax, dword ptr [eax + 4]
// 00609bd1  5f                   pop edi
// 00609bd2  894104               mov dword ptr [ecx + 4], eax
// 00609bd5  8bc1                 mov eax, ecx
// 00609bd7  5e                   pop esi
// 00609bd8  83c40c               add esp, 0xc
// 00609bdb  c21000               ret 0x10
// standard library map_ptr<pod16> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AViterator@12@V312@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod16>
struct E { int v[4]; };
#include <map>
struct K; template class std::map<K*, E>;
