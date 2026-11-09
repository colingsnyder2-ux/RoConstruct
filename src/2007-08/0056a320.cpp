// from server: 100% by auto
// roc 2007-08 0056a320  unit: RBX::ModelInstance  size: 446 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0056a320
//
// 0056a320  83ec0c               sub esp, 0xc
// 0056a323  56                   push esi
// 0056a324  8bf1                 mov esi, ecx
// 0056a326  837e0800             cmp dword ptr [esi + 8], 0
// 0056a32a  57                   push edi
// 0056a32b  7521                 jne 0x56a34e
// 0056a32d  8b442424             mov eax, dword ptr [esp + 0x24]
// 0056a331  8b4e04               mov ecx, dword ptr [esi + 4]
// 0056a334  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 0056a338  50                   push eax
// 0056a339  51                   push ecx
// 0056a33a  6a01                 push 1
// 0056a33c  57                   push edi
// 0056a33d  8bce                 mov ecx, esi
// 0056a33f  e89cec0100           call 0x588fe0
// 0056a344  8bc7                 mov eax, edi
// 0056a346  5f                   pop edi
// 0056a347  5e                   pop esi
// 0056a348  83c40c               add esp, 0xc
// 0056a34b  c21000               ret 0x10
// 0056a34e  8b5604               mov edx, dword ptr [esi + 4]
// 0056a351  8b3a                 mov edi, dword ptr [edx]
// 0056a353  55                   push ebp
// 0056a354  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 0056a358  85ed                 test ebp, ebp
// 0056a35a  7404                 je 0x56a360
// 0056a35c  3bee                 cmp ebp, esi
// 0056a35e  7406                 je 0x56a366
// 0056a360  ff15d8e67700         call dword ptr [0x77e6d8]
// 0056a366  53                   push ebx
// 0056a367  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 0056a36b  3bdf                 cmp ebx, edi
// 0056a36d  752b                 jne 0x56a39a
// 0056a36f  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0056a373  8b07                 mov eax, dword ptr [edi]
// 0056a375  3b430c               cmp eax, dword ptr [ebx + 0xc]
// 0056a378  0f8339010000         jae 0x56a4b7
// 0056a37e  57                   push edi
// 0056a37f  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0056a383  53                   push ebx
// 0056a384  6a01                 push 1
// 0056a386  57                   push edi
// 0056a387  8bce                 mov ecx, esi
// 0056a389  e852ec0100           call 0x588fe0
// 0056a38e  5b                   pop ebx
// 0056a38f  5d                   pop ebp
// 0056a390  8bc7                 mov eax, edi
// 0056a392  5f                   pop edi
// 0056a393  5e                   pop esi
// 0056a394  83c40c               add esp, 0xc
// 0056a397  c21000               ret 0x10
// 0056a39a  85ed                 test ebp, ebp
// 0056a39c  8b7e04               mov edi, dword ptr [esi + 4]
// 0056a39f  7404                 je 0x56a3a5
// 0056a3a1  3bee                 cmp ebp, esi
// 0056a3a3  7406                 je 0x56a3ab
// 0056a3a5  ff15d8e67700         call dword ptr [0x77e6d8]
// 0056a3ab  3bdf                 cmp ebx, edi
// 0056a3ad  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0056a3b1  752d                 jne 0x56a3e0
// 0056a3b3  8b4e04               mov ecx, dword ptr [esi + 4]
// 0056a3b6  8b4108               mov eax, dword ptr [ecx + 8]
// 0056a3b9  8b500c               mov edx, dword ptr [eax + 0xc]
// 0056a3bc  3b17                 cmp edx, dword ptr [edi]
// 0056a3be  0f83f3000000         jae 0x56a4b7
// 0056a3c4  57                   push edi
// 0056a3c5  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0056a3c9  50                   push eax
// 0056a3ca  6a00                 push 0
// 0056a3cc  57                   push edi
// 0056a3cd  8bce                 mov ecx, esi
// 0056a3cf  e80cec0100           call 0x588fe0
// 0056a3d4  5b                   pop ebx
// 0056a3d5  5d                   pop ebp
// 0056a3d6  8bc7                 mov eax, edi
// 0056a3d8  5f                   pop edi
// 0056a3d9  5e                   pop esi
// 0056a3da  83c40c               add esp, 0xc
// 0056a3dd  c21000               ret 0x10
// 0056a3e0  8b07                 mov eax, dword ptr [edi]
// 0056a3e2  39430c               cmp dword ptr [ebx + 0xc], eax
// 0056a3e5  765b                 jbe 0x56a442
// 0056a3e7  8d4c2424             lea ecx, [esp + 0x24]
// 0056a3eb  896c2424             mov dword ptr [esp + 0x24], ebp
// 0056a3ef  895c2428             mov dword ptr [esp + 0x28], ebx
// 0056a3f3  e838d80100           call 0x587c30
// 0056a3f8  8b07                 mov eax, dword ptr [edi]
// 0056a3fa  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0056a3fe  39410c               cmp dword ptr [ecx + 0xc], eax
// 0056a401  733c                 jae 0x56a43f
// 0056a403  8b4108               mov eax, dword ptr [ecx + 8]
// 0056a406  80781900             cmp byte ptr [eax + 0x19], 0
// 0056a40a  57                   push edi
// 0056a40b  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0056a40f  7417                 je 0x56a428
// 0056a411  51                   push ecx
// 0056a412  6a00                 push 0
// 0056a414  57                   push edi
// 0056a415  8bce                 mov ecx, esi
// 0056a417  e8c4eb0100           call 0x588fe0
// 0056a41c  5b                   pop ebx
// 0056a41d  5d                   pop ebp
// 0056a41e  8bc7                 mov eax, edi
// 0056a420  5f                   pop edi
// 0056a421  5e                   pop esi
// 0056a422  83c40c               add esp, 0xc
// 0056a425  c21000               ret 0x10
// 0056a428  53                   push ebx
// 0056a429  6a01                 push 1
// 0056a42b  57                   push edi
// 0056a42c  8bce                 mov ecx, esi
// 0056a42e  e8adeb0100           call 0x588fe0
// 0056a433  5b                   pop ebx
// 0056a434  5d                   pop ebp
// 0056a435  8bc7                 mov eax, edi
// 0056a437  5f                   pop edi
// 0056a438  5e                   pop esi
// 0056a439  83c40c               add esp, 0xc
// 0056a43c  c21000               ret 0x10
// 0056a43f  39430c               cmp dword ptr [ebx + 0xc], eax
// 0056a442  7373                 jae 0x56a4b7
// 0056a444  8b4e04               mov ecx, dword ptr [esi + 4]
// 0056a447  894c2414             mov dword ptr [esp + 0x14], ecx
// 0056a44b  8d4c2424             lea ecx, [esp + 0x24]
// 0056a44f  896c2424             mov dword ptr [esp + 0x24], ebp
// 0056a453  895c2428             mov dword ptr [esp + 0x28], ebx
// 0056a457  89742410             mov dword ptr [esp + 0x10], esi
// 0056a45b  e860d80100           call 0x587cc0
// 0056a460  8d542410             lea edx, [esp + 0x10]
// 0056a464  52                   push edx
// 0056a465  8d4c2428             lea ecx, [esp + 0x28]
// 0056a469  e842c6efff           call 0x466ab0
// 0056a46e  84c0                 test al, al
// 0056a470  8b442428             mov eax, dword ptr [esp + 0x28]
// 0056a474  7507                 jne 0x56a47d
// 0056a476  8b0f                 mov ecx, dword ptr [edi]
// 0056a478  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 0056a47b  733a                 jae 0x56a4b7
// 0056a47d  8b5308               mov edx, dword ptr [ebx + 8]
// 0056a480  807a1900             cmp byte ptr [edx + 0x19], 0
// 0056a484  57                   push edi
// 0056a485  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0056a489  8bce                 mov ecx, esi
// 0056a48b  7415                 je 0x56a4a2
// 0056a48d  53                   push ebx
// 0056a48e  6a00                 push 0
// 0056a490  57                   push edi
// 0056a491  e84aeb0100           call 0x588fe0
// 0056a496  5b                   pop ebx
// 0056a497  5d                   pop ebp
// 0056a498  8bc7                 mov eax, edi
// 0056a49a  5f                   pop edi
// 0056a49b  5e                   pop esi
// 0056a49c  83c40c               add esp, 0xc
// 0056a49f  c21000               ret 0x10
// 0056a4a2  50                   push eax
// 0056a4a3  6a01                 push 1
// 0056a4a5  57                   push edi
// 0056a4a6  e835eb0100           call 0x588fe0
// 0056a4ab  5b                   pop ebx
// 0056a4ac  5d                   pop ebp
// 0056a4ad  8bc7                 mov eax, edi
// 0056a4af  5f                   pop edi
// 0056a4b0  5e                   pop esi
// 0056a4b1  83c40c               add esp, 0xc
// 0056a4b4  c21000               ret 0x10
// 0056a4b7  57                   push edi
// 0056a4b8  8d442414             lea eax, [esp + 0x14]
// 0056a4bc  50                   push eax
// 0056a4bd  8bce                 mov ecx, esi
// 0056a4bf  e89cfdffff           call 0x56a260
// 0056a4c4  8b10                 mov edx, dword ptr [eax]
// 0056a4c6  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0056a4ca  5b                   pop ebx
// 0056a4cb  5d                   pop ebp
// 0056a4cc  8911                 mov dword ptr [ecx], edx
// 0056a4ce  8b4004               mov eax, dword ptr [eax + 4]
// 0056a4d1  5f                   pop edi
// 0056a4d2  894104               mov dword ptr [ecx + 4], eax
// 0056a4d5  8bc1                 mov eax, ecx
// 0056a4d7  5e                   pop esi
// 0056a4d8  83c40c               add esp, 0xc
// 0056a4db  c21000               ret 0x10
// standard library map_ptr<pod8> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AViterator@12@V312@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod8>
struct E { int v[2]; };
#include <map>
struct K; template class std::map<K*, E>;
