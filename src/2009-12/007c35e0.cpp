// from server: 100% by auto
// roc 2009-12 007c35e0  unit: RBX::Network::$$A6AXABVChatMessage::?$signal::slot  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007c35e0
//
// 007c35e0  64a100000000         mov eax, dword ptr fs:[0]
// 007c35e6  6aff                 push -1
// 007c35e8  6812699500           push 0x956912
// 007c35ed  50                   push eax
// 007c35ee  64892500000000       mov dword ptr fs:[0], esp
// 007c35f5  83ec44               sub esp, 0x44
// 007c35f8  57                   push edi
// 007c35f9  8bf9                 mov edi, ecx
// 007c35fb  817f1cfeffff03       cmp dword ptr [edi + 0x1c], 0x3fffffe
// 007c3602  7259                 jb 0x7c365d
// 007c3604  6800f59900           push 0x99f500
// 007c3609  8d4c2408             lea ecx, [esp + 8]
// 007c360d  ff15f4b69800         call dword ptr [0x98b6f4]
// 007c3613  8d4c2420             lea ecx, [esp + 0x20]
// 007c3617  c744245000000000     mov dword ptr [esp + 0x50], 0
// 007c361f  ff1554b79800         call dword ptr [0x98b754]
// 007c3625  8d442404             lea eax, [esp + 4]
// 007c3629  50                   push eax
// 007c362a  8d4c2430             lea ecx, [esp + 0x30]
// 007c362e  c644245401           mov byte ptr [esp + 0x54], 1
// 007c3633  c744242484f49900     mov dword ptr [esp + 0x24], 0x99f484
// 007c363b  ff15f0b69800         call dword ptr [0x98b6f0]
// 007c3641  68e4efa800           push 0xa8efe4
// 007c3646  8d4c2424             lea ecx, [esp + 0x24]
// 007c364a  51                   push ecx
// 007c364b  c644245800           mov byte ptr [esp + 0x58], 0
// 007c3650  c744242890f49900     mov dword ptr [esp + 0x28], 0x99f490
// 007c3658  e81b120300           call 0x7f4878
// 007c365d  8b542464             mov edx, dword ptr [esp + 0x64]
// 007c3661  8b4718               mov eax, dword ptr [edi + 0x18]
// 007c3664  53                   push ebx
// 007c3665  55                   push ebp
// 007c3666  56                   push esi
// 007c3667  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 007c366b  6a00                 push 0
// 007c366d  52                   push edx
// 007c366e  50                   push eax
// 007c366f  56                   push esi
// 007c3670  50                   push eax
// 007c3671  e85afeffff           call 0x7c34d0
// 007c3676  8be8                 mov ebp, eax
// 007c3678  8b4718               mov eax, dword ptr [edi + 0x18]
// 007c367b  bb01000000           mov ebx, 1
// 007c3680  015f1c               add dword ptr [edi + 0x1c], ebx
// 007c3683  3bf0                 cmp esi, eax
// 007c3685  7510                 jne 0x7c3697
// 007c3687  896804               mov dword ptr [eax + 4], ebp
// 007c368a  8b4718               mov eax, dword ptr [edi + 0x18]
// 007c368d  8928                 mov dword ptr [eax], ebp
// 007c368f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 007c3692  896908               mov dword ptr [ecx + 8], ebp
// 007c3695  eb22                 jmp 0x7c36b9
// 007c3697  807c246800           cmp byte ptr [esp + 0x68], 0
// 007c369c  740d                 je 0x7c36ab
// 007c369e  892e                 mov dword ptr [esi], ebp
// 007c36a0  8b4718               mov eax, dword ptr [edi + 0x18]
// 007c36a3  3b30                 cmp esi, dword ptr [eax]
// 007c36a5  7512                 jne 0x7c36b9
// 007c36a7  8928                 mov dword ptr [eax], ebp
// 007c36a9  eb0e                 jmp 0x7c36b9
// 007c36ab  896e08               mov dword ptr [esi + 8], ebp
// 007c36ae  8b4718               mov eax, dword ptr [edi + 0x18]
// 007c36b1  3b7008               cmp esi, dword ptr [eax + 8]
// 007c36b4  7503                 jne 0x7c36b9
// 007c36b6  896808               mov dword ptr [eax + 8], ebp
// 007c36b9  8b5504               mov edx, dword ptr [ebp + 4]
// 007c36bc  807a4c00             cmp byte ptr [edx + 0x4c], 0
// 007c36c0  8d4504               lea eax, [ebp + 4]
// 007c36c3  8bf5                 mov esi, ebp
// 007c36c5  0f85ea000000         jne 0x7c37b5
// 007c36cb  eb03                 jmp 0x7c36d0
// 007c36cd  8d4900               lea ecx, [ecx]
// 007c36d0  8b08                 mov ecx, dword ptr [eax]
// 007c36d2  8b5104               mov edx, dword ptr [ecx + 4]
// 007c36d5  3b0a                 cmp ecx, dword ptr [edx]
// 007c36d7  7551                 jne 0x7c372a
// 007c36d9  8b5208               mov edx, dword ptr [edx + 8]
// 007c36dc  807a4c00             cmp byte ptr [edx + 0x4c], 0
// 007c36e0  7519                 jne 0x7c36fb
// 007c36e2  88594c               mov byte ptr [ecx + 0x4c], bl
// 007c36e5  885a4c               mov byte ptr [edx + 0x4c], bl
// 007c36e8  8b10                 mov edx, dword ptr [eax]
// 007c36ea  8b4a04               mov ecx, dword ptr [edx + 4]
// 007c36ed  c6414c00             mov byte ptr [ecx + 0x4c], 0
// 007c36f1  8b10                 mov edx, dword ptr [eax]
// 007c36f3  8b7204               mov esi, dword ptr [edx + 4]
// 007c36f6  e9aa000000           jmp 0x7c37a5
// 007c36fb  3b7108               cmp esi, dword ptr [ecx + 8]
// 007c36fe  750a                 jne 0x7c370a
// 007c3700  8bf1                 mov esi, ecx
// 007c3702  56                   push esi
// 007c3703  8bcf                 mov ecx, edi
// 007c3705  e8b6e9ffff           call 0x7c20c0
// 007c370a  8b4604               mov eax, dword ptr [esi + 4]
// 007c370d  88584c               mov byte ptr [eax + 0x4c], bl
// 007c3710  8b4e04               mov ecx, dword ptr [esi + 4]
// 007c3713  8b5104               mov edx, dword ptr [ecx + 4]
// 007c3716  c6424c00             mov byte ptr [edx + 0x4c], 0
// 007c371a  8b4604               mov eax, dword ptr [esi + 4]
// 007c371d  8b4804               mov ecx, dword ptr [eax + 4]
// 007c3720  51                   push ecx
// 007c3721  8bcf                 mov ecx, edi
// 007c3723  e8e8e6ffff           call 0x7c1e10
// 007c3728  eb7b                 jmp 0x7c37a5
// 007c372a  8b12                 mov edx, dword ptr [edx]
// 007c372c  807a4c00             cmp byte ptr [edx + 0x4c], 0
// 007c3730  7516                 jne 0x7c3748
// 007c3732  88594c               mov byte ptr [ecx + 0x4c], bl
// 007c3735  885a4c               mov byte ptr [edx + 0x4c], bl
// 007c3738  8b10                 mov edx, dword ptr [eax]
// 007c373a  8b4a04               mov ecx, dword ptr [edx + 4]
// 007c373d  c6414c00             mov byte ptr [ecx + 0x4c], 0
// 007c3741  8b10                 mov edx, dword ptr [eax]
// 007c3743  8b7204               mov esi, dword ptr [edx + 4]
// 007c3746  eb5d                 jmp 0x7c37a5
// 007c3748  3b31                 cmp esi, dword ptr [ecx]
// 007c374a  750a                 jne 0x7c3756
// 007c374c  8bf1                 mov esi, ecx
// 007c374e  56                   push esi
// 007c374f  8bcf                 mov ecx, edi
// 007c3751  e8bae6ffff           call 0x7c1e10
// 007c3756  8b4604               mov eax, dword ptr [esi + 4]
// 007c3759  88584c               mov byte ptr [eax + 0x4c], bl
// 007c375c  8b4e04               mov ecx, dword ptr [esi + 4]
// 007c375f  8b5104               mov edx, dword ptr [ecx + 4]
// 007c3762  c6424c00             mov byte ptr [edx + 0x4c], 0
// 007c3766  8b4604               mov eax, dword ptr [esi + 4]
// 007c3769  8b4004               mov eax, dword ptr [eax + 4]
// 007c376c  8b4808               mov ecx, dword ptr [eax + 8]
// 007c376f  8b11                 mov edx, dword ptr [ecx]
// 007c3771  895008               mov dword ptr [eax + 8], edx
// 007c3774  8b11                 mov edx, dword ptr [ecx]
// 007c3776  807a4d00             cmp byte ptr [edx + 0x4d], 0
// 007c377a  7503                 jne 0x7c377f
// 007c377c  894204               mov dword ptr [edx + 4], eax
// 007c377f  8b5004               mov edx, dword ptr [eax + 4]
// 007c3782  895104               mov dword ptr [ecx + 4], edx
// 007c3785  8b5718               mov edx, dword ptr [edi + 0x18]
// 007c3788  3b4204               cmp eax, dword ptr [edx + 4]
// 007c378b  7505                 jne 0x7c3792
// 007c378d  894a04               mov dword ptr [edx + 4], ecx
// 007c3790  eb0e                 jmp 0x7c37a0
// 007c3792  8b5004               mov edx, dword ptr [eax + 4]
// 007c3795  3b02                 cmp eax, dword ptr [edx]
// 007c3797  7504                 jne 0x7c379d
// 007c3799  890a                 mov dword ptr [edx], ecx
// 007c379b  eb03                 jmp 0x7c37a0
// 007c379d  894a08               mov dword ptr [edx + 8], ecx
// 007c37a0  8901                 mov dword ptr [ecx], eax
// 007c37a2  894804               mov dword ptr [eax + 4], ecx
// 007c37a5  8b4e04               mov ecx, dword ptr [esi + 4]
// 007c37a8  80794c00             cmp byte ptr [ecx + 0x4c], 0
// 007c37ac  8d4604               lea eax, [esi + 4]
// 007c37af  0f841bffffff         je 0x7c36d0
// 007c37b5  8b5718               mov edx, dword ptr [edi + 0x18]
// 007c37b8  8b4204               mov eax, dword ptr [edx + 4]
// 007c37bb  88584c               mov byte ptr [eax + 0x4c], bl
// 007c37be  8b442464             mov eax, dword ptr [esp + 0x64]
// 007c37c2  8b0f                 mov ecx, dword ptr [edi]
// 007c37c4  5e                   pop esi
// 007c37c5  896804               mov dword ptr [eax + 4], ebp
// 007c37c8  5d                   pop ebp
// 007c37c9  8908                 mov dword ptr [eax], ecx
// 007c37cb  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 007c37cf  5b                   pop ebx
// 007c37d0  5f                   pop edi
// 007c37d1  64890d00000000       mov dword ptr fs:[0], ecx
// 007c37d8  83c450               add esp, 0x50
// 007c37db  c21000               ret 0x10
// standard library map_str<pod36> (function ?_Insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod36>
struct E { int v[9]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
