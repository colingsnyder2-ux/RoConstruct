// from server: 100% by auto
// roc 2009-12 0041edd0  unit: CSelectionTreeCtrl  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0041edd0
//
// 0041edd0  64a100000000         mov eax, dword ptr fs:[0]
// 0041edd6  6aff                 push -1
// 0041edd8  6812699500           push 0x956912
// 0041eddd  50                   push eax
// 0041edde  64892500000000       mov dword ptr fs:[0], esp
// 0041ede5  83ec44               sub esp, 0x44
// 0041ede8  57                   push edi
// 0041ede9  8bf9                 mov edi, ecx
// 0041edeb  817f1cfeffff1f       cmp dword ptr [edi + 0x1c], 0x1ffffffe
// 0041edf2  7259                 jb 0x41ee4d
// 0041edf4  6800f59900           push 0x99f500
// 0041edf9  8d4c2408             lea ecx, [esp + 8]
// 0041edfd  ff15f4b69800         call dword ptr [0x98b6f4]
// 0041ee03  8d4c2420             lea ecx, [esp + 0x20]
// 0041ee07  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0041ee0f  ff1554b79800         call dword ptr [0x98b754]
// 0041ee15  8d442404             lea eax, [esp + 4]
// 0041ee19  50                   push eax
// 0041ee1a  8d4c2430             lea ecx, [esp + 0x30]
// 0041ee1e  c644245401           mov byte ptr [esp + 0x54], 1
// 0041ee23  c744242484f49900     mov dword ptr [esp + 0x24], 0x99f484
// 0041ee2b  ff15f0b69800         call dword ptr [0x98b6f0]
// 0041ee31  68e4efa800           push 0xa8efe4
// 0041ee36  8d4c2424             lea ecx, [esp + 0x24]
// 0041ee3a  51                   push ecx
// 0041ee3b  c644245800           mov byte ptr [esp + 0x58], 0
// 0041ee40  c744242890f49900     mov dword ptr [esp + 0x28], 0x99f490
// 0041ee48  e82b5a3d00           call 0x7f4878
// 0041ee4d  8b542464             mov edx, dword ptr [esp + 0x64]
// 0041ee51  8b4718               mov eax, dword ptr [edi + 0x18]
// 0041ee54  53                   push ebx
// 0041ee55  55                   push ebp
// 0041ee56  56                   push esi
// 0041ee57  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0041ee5b  6a00                 push 0
// 0041ee5d  52                   push edx
// 0041ee5e  50                   push eax
// 0041ee5f  56                   push esi
// 0041ee60  50                   push eax
// 0041ee61  e89af7ffff           call 0x41e600
// 0041ee66  8be8                 mov ebp, eax
// 0041ee68  8b4718               mov eax, dword ptr [edi + 0x18]
// 0041ee6b  bb01000000           mov ebx, 1
// 0041ee70  015f1c               add dword ptr [edi + 0x1c], ebx
// 0041ee73  3bf0                 cmp esi, eax
// 0041ee75  7510                 jne 0x41ee87
// 0041ee77  896804               mov dword ptr [eax + 4], ebp
// 0041ee7a  8b4718               mov eax, dword ptr [edi + 0x18]
// 0041ee7d  8928                 mov dword ptr [eax], ebp
// 0041ee7f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 0041ee82  896908               mov dword ptr [ecx + 8], ebp
// 0041ee85  eb22                 jmp 0x41eea9
// 0041ee87  807c246800           cmp byte ptr [esp + 0x68], 0
// 0041ee8c  740d                 je 0x41ee9b
// 0041ee8e  892e                 mov dword ptr [esi], ebp
// 0041ee90  8b4718               mov eax, dword ptr [edi + 0x18]
// 0041ee93  3b30                 cmp esi, dword ptr [eax]
// 0041ee95  7512                 jne 0x41eea9
// 0041ee97  8928                 mov dword ptr [eax], ebp
// 0041ee99  eb0e                 jmp 0x41eea9
// 0041ee9b  896e08               mov dword ptr [esi + 8], ebp
// 0041ee9e  8b4718               mov eax, dword ptr [edi + 0x18]
// 0041eea1  3b7008               cmp esi, dword ptr [eax + 8]
// 0041eea4  7503                 jne 0x41eea9
// 0041eea6  896808               mov dword ptr [eax + 8], ebp
// 0041eea9  8b5504               mov edx, dword ptr [ebp + 4]
// 0041eeac  807a1400             cmp byte ptr [edx + 0x14], 0
// 0041eeb0  8d4504               lea eax, [ebp + 4]
// 0041eeb3  8bf5                 mov esi, ebp
// 0041eeb5  0f85ea000000         jne 0x41efa5
// 0041eebb  eb03                 jmp 0x41eec0
// 0041eebd  8d4900               lea ecx, [ecx]
// 0041eec0  8b08                 mov ecx, dword ptr [eax]
// 0041eec2  8b5104               mov edx, dword ptr [ecx + 4]
// 0041eec5  3b0a                 cmp ecx, dword ptr [edx]
// 0041eec7  7551                 jne 0x41ef1a
// 0041eec9  8b5208               mov edx, dword ptr [edx + 8]
// 0041eecc  807a1400             cmp byte ptr [edx + 0x14], 0
// 0041eed0  7519                 jne 0x41eeeb
// 0041eed2  885914               mov byte ptr [ecx + 0x14], bl
// 0041eed5  885a14               mov byte ptr [edx + 0x14], bl
// 0041eed8  8b10                 mov edx, dword ptr [eax]
// 0041eeda  8b4a04               mov ecx, dword ptr [edx + 4]
// 0041eedd  c6411400             mov byte ptr [ecx + 0x14], 0
// 0041eee1  8b10                 mov edx, dword ptr [eax]
// 0041eee3  8b7204               mov esi, dword ptr [edx + 4]
// 0041eee6  e9aa000000           jmp 0x41ef95
// 0041eeeb  3b7108               cmp esi, dword ptr [ecx + 8]
// 0041eeee  750a                 jne 0x41eefa
// 0041eef0  8bf1                 mov esi, ecx
// 0041eef2  56                   push esi
// 0041eef3  8bcf                 mov ecx, edi
// 0041eef5  e8d6723c00           call 0x7e61d0
// 0041eefa  8b4604               mov eax, dword ptr [esi + 4]
// 0041eefd  885814               mov byte ptr [eax + 0x14], bl
// 0041ef00  8b4e04               mov ecx, dword ptr [esi + 4]
// 0041ef03  8b5104               mov edx, dword ptr [ecx + 4]
// 0041ef06  c6421400             mov byte ptr [edx + 0x14], 0
// 0041ef0a  8b4604               mov eax, dword ptr [esi + 4]
// 0041ef0d  8b4804               mov ecx, dword ptr [eax + 4]
// 0041ef10  51                   push ecx
// 0041ef11  8bcf                 mov ecx, edi
// 0041ef13  e8585e0300           call 0x454d70
// 0041ef18  eb7b                 jmp 0x41ef95
// 0041ef1a  8b12                 mov edx, dword ptr [edx]
// 0041ef1c  807a1400             cmp byte ptr [edx + 0x14], 0
// 0041ef20  7516                 jne 0x41ef38
// 0041ef22  885914               mov byte ptr [ecx + 0x14], bl
// 0041ef25  885a14               mov byte ptr [edx + 0x14], bl
// 0041ef28  8b10                 mov edx, dword ptr [eax]
// 0041ef2a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0041ef2d  c6411400             mov byte ptr [ecx + 0x14], 0
// 0041ef31  8b10                 mov edx, dword ptr [eax]
// 0041ef33  8b7204               mov esi, dword ptr [edx + 4]
// 0041ef36  eb5d                 jmp 0x41ef95
// 0041ef38  3b31                 cmp esi, dword ptr [ecx]
// 0041ef3a  750a                 jne 0x41ef46
// 0041ef3c  8bf1                 mov esi, ecx
// 0041ef3e  56                   push esi
// 0041ef3f  8bcf                 mov ecx, edi
// 0041ef41  e82a5e0300           call 0x454d70
// 0041ef46  8b4604               mov eax, dword ptr [esi + 4]
// 0041ef49  885814               mov byte ptr [eax + 0x14], bl
// 0041ef4c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0041ef4f  8b5104               mov edx, dword ptr [ecx + 4]
// 0041ef52  c6421400             mov byte ptr [edx + 0x14], 0
// 0041ef56  8b4604               mov eax, dword ptr [esi + 4]
// 0041ef59  8b4004               mov eax, dword ptr [eax + 4]
// 0041ef5c  8b4808               mov ecx, dword ptr [eax + 8]
// 0041ef5f  8b11                 mov edx, dword ptr [ecx]
// 0041ef61  895008               mov dword ptr [eax + 8], edx
// 0041ef64  8b11                 mov edx, dword ptr [ecx]
// 0041ef66  807a1500             cmp byte ptr [edx + 0x15], 0
// 0041ef6a  7503                 jne 0x41ef6f
// 0041ef6c  894204               mov dword ptr [edx + 4], eax
// 0041ef6f  8b5004               mov edx, dword ptr [eax + 4]
// 0041ef72  895104               mov dword ptr [ecx + 4], edx
// 0041ef75  8b5718               mov edx, dword ptr [edi + 0x18]
// 0041ef78  3b4204               cmp eax, dword ptr [edx + 4]
// 0041ef7b  7505                 jne 0x41ef82
// 0041ef7d  894a04               mov dword ptr [edx + 4], ecx
// 0041ef80  eb0e                 jmp 0x41ef90
// 0041ef82  8b5004               mov edx, dword ptr [eax + 4]
// 0041ef85  3b02                 cmp eax, dword ptr [edx]
// 0041ef87  7504                 jne 0x41ef8d
// 0041ef89  890a                 mov dword ptr [edx], ecx
// 0041ef8b  eb03                 jmp 0x41ef90
// 0041ef8d  894a08               mov dword ptr [edx + 8], ecx
// 0041ef90  8901                 mov dword ptr [ecx], eax
// 0041ef92  894804               mov dword ptr [eax + 4], ecx
// 0041ef95  8b4e04               mov ecx, dword ptr [esi + 4]
// 0041ef98  80791400             cmp byte ptr [ecx + 0x14], 0
// 0041ef9c  8d4604               lea eax, [esi + 4]
// 0041ef9f  0f841bffffff         je 0x41eec0
// 0041efa5  8b5718               mov edx, dword ptr [edi + 0x18]
// 0041efa8  8b4204               mov eax, dword ptr [edx + 4]
// 0041efab  885814               mov byte ptr [eax + 0x14], bl
// 0041efae  8b442464             mov eax, dword ptr [esp + 0x64]
// 0041efb2  8b0f                 mov ecx, dword ptr [edi]
// 0041efb4  5e                   pop esi
// 0041efb5  896804               mov dword ptr [eax + 4], ebp
// 0041efb8  5d                   pop ebp
// 0041efb9  8908                 mov dword ptr [eax], ecx
// 0041efbb  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0041efbf  5b                   pop ebx
// 0041efc0  5f                   pop edi
// 0041efc1  64890d00000000       mov dword ptr fs:[0], ecx
// 0041efc8  83c450               add esp, 0x50
// 0041efcb  c21000               ret 0x10
// standard library map_int<ptr> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHPAUT@@@2@@Z)

// stl: map_int<ptr>
struct T; typedef T* E;
#include <map>
template class std::map<int, E>;
