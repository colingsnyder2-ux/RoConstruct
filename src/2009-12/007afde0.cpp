// from server: 100% by auto
// roc 2009-12 007afde0  unit: RBX::Block  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007afde0
//
// 007afde0  64a100000000         mov eax, dword ptr fs:[0]
// 007afde6  6aff                 push -1
// 007afde8  6812699500           push 0x956912
// 007afded  50                   push eax
// 007afdee  64892500000000       mov dword ptr fs:[0], esp
// 007afdf5  83ec44               sub esp, 0x44
// 007afdf8  57                   push edi
// 007afdf9  8bf9                 mov edi, ecx
// 007afdfb  817f1cfeffff0f       cmp dword ptr [edi + 0x1c], 0xffffffe
// 007afe02  7259                 jb 0x7afe5d
// 007afe04  6800f59900           push 0x99f500
// 007afe09  8d4c2408             lea ecx, [esp + 8]
// 007afe0d  ff15f4b69800         call dword ptr [0x98b6f4]
// 007afe13  8d4c2420             lea ecx, [esp + 0x20]
// 007afe17  c744245000000000     mov dword ptr [esp + 0x50], 0
// 007afe1f  ff1554b79800         call dword ptr [0x98b754]
// 007afe25  8d442404             lea eax, [esp + 4]
// 007afe29  50                   push eax
// 007afe2a  8d4c2430             lea ecx, [esp + 0x30]
// 007afe2e  c644245401           mov byte ptr [esp + 0x54], 1
// 007afe33  c744242484f49900     mov dword ptr [esp + 0x24], 0x99f484
// 007afe3b  ff15f0b69800         call dword ptr [0x98b6f0]
// 007afe41  68e4efa800           push 0xa8efe4
// 007afe46  8d4c2424             lea ecx, [esp + 0x24]
// 007afe4a  51                   push ecx
// 007afe4b  c644245800           mov byte ptr [esp + 0x58], 0
// 007afe50  c744242890f49900     mov dword ptr [esp + 0x28], 0x99f490
// 007afe58  e81b4a0400           call 0x7f4878
// 007afe5d  8b542464             mov edx, dword ptr [esp + 0x64]
// 007afe61  8b4718               mov eax, dword ptr [edi + 0x18]
// 007afe64  53                   push ebx
// 007afe65  55                   push ebp
// 007afe66  56                   push esi
// 007afe67  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 007afe6b  6a00                 push 0
// 007afe6d  52                   push edx
// 007afe6e  50                   push eax
// 007afe6f  56                   push esi
// 007afe70  50                   push eax
// 007afe71  e8dafeffff           call 0x7afd50
// 007afe76  8be8                 mov ebp, eax
// 007afe78  8b4718               mov eax, dword ptr [edi + 0x18]
// 007afe7b  bb01000000           mov ebx, 1
// 007afe80  015f1c               add dword ptr [edi + 0x1c], ebx
// 007afe83  3bf0                 cmp esi, eax
// 007afe85  7510                 jne 0x7afe97
// 007afe87  896804               mov dword ptr [eax + 4], ebp
// 007afe8a  8b4718               mov eax, dword ptr [edi + 0x18]
// 007afe8d  8928                 mov dword ptr [eax], ebp
// 007afe8f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 007afe92  896908               mov dword ptr [ecx + 8], ebp
// 007afe95  eb22                 jmp 0x7afeb9
// 007afe97  807c246800           cmp byte ptr [esp + 0x68], 0
// 007afe9c  740d                 je 0x7afeab
// 007afe9e  892e                 mov dword ptr [esi], ebp
// 007afea0  8b4718               mov eax, dword ptr [edi + 0x18]
// 007afea3  3b30                 cmp esi, dword ptr [eax]
// 007afea5  7512                 jne 0x7afeb9
// 007afea7  8928                 mov dword ptr [eax], ebp
// 007afea9  eb0e                 jmp 0x7afeb9
// 007afeab  896e08               mov dword ptr [esi + 8], ebp
// 007afeae  8b4718               mov eax, dword ptr [edi + 0x18]
// 007afeb1  3b7008               cmp esi, dword ptr [eax + 8]
// 007afeb4  7503                 jne 0x7afeb9
// 007afeb6  896808               mov dword ptr [eax + 8], ebp
// 007afeb9  8b5504               mov edx, dword ptr [ebp + 4]
// 007afebc  807a1c00             cmp byte ptr [edx + 0x1c], 0
// 007afec0  8d4504               lea eax, [ebp + 4]
// 007afec3  8bf5                 mov esi, ebp
// 007afec5  0f85ea000000         jne 0x7affb5
// 007afecb  eb03                 jmp 0x7afed0
// 007afecd  8d4900               lea ecx, [ecx]
// 007afed0  8b08                 mov ecx, dword ptr [eax]
// 007afed2  8b5104               mov edx, dword ptr [ecx + 4]
// 007afed5  3b0a                 cmp ecx, dword ptr [edx]
// 007afed7  7551                 jne 0x7aff2a
// 007afed9  8b5208               mov edx, dword ptr [edx + 8]
// 007afedc  807a1c00             cmp byte ptr [edx + 0x1c], 0
// 007afee0  7519                 jne 0x7afefb
// 007afee2  88591c               mov byte ptr [ecx + 0x1c], bl
// 007afee5  885a1c               mov byte ptr [edx + 0x1c], bl
// 007afee8  8b10                 mov edx, dword ptr [eax]
// 007afeea  8b4a04               mov ecx, dword ptr [edx + 4]
// 007afeed  c6411c00             mov byte ptr [ecx + 0x1c], 0
// 007afef1  8b10                 mov edx, dword ptr [eax]
// 007afef3  8b7204               mov esi, dword ptr [edx + 4]
// 007afef6  e9aa000000           jmp 0x7affa5
// 007afefb  3b7108               cmp esi, dword ptr [ecx + 8]
// 007afefe  750a                 jne 0x7aff0a
// 007aff00  8bf1                 mov esi, ecx
// 007aff02  56                   push esi
// 007aff03  8bcf                 mov ecx, edi
// 007aff05  e8d6faffff           call 0x7af9e0
// 007aff0a  8b4604               mov eax, dword ptr [esi + 4]
// 007aff0d  88581c               mov byte ptr [eax + 0x1c], bl
// 007aff10  8b4e04               mov ecx, dword ptr [esi + 4]
// 007aff13  8b5104               mov edx, dword ptr [ecx + 4]
// 007aff16  c6421c00             mov byte ptr [edx + 0x1c], 0
// 007aff1a  8b4604               mov eax, dword ptr [esi + 4]
// 007aff1d  8b4804               mov ecx, dword ptr [eax + 4]
// 007aff20  51                   push ecx
// 007aff21  8bcf                 mov ecx, edi
// 007aff23  e8d8f6ffff           call 0x7af600
// 007aff28  eb7b                 jmp 0x7affa5
// 007aff2a  8b12                 mov edx, dword ptr [edx]
// 007aff2c  807a1c00             cmp byte ptr [edx + 0x1c], 0
// 007aff30  7516                 jne 0x7aff48
// 007aff32  88591c               mov byte ptr [ecx + 0x1c], bl
// 007aff35  885a1c               mov byte ptr [edx + 0x1c], bl
// 007aff38  8b10                 mov edx, dword ptr [eax]
// 007aff3a  8b4a04               mov ecx, dword ptr [edx + 4]
// 007aff3d  c6411c00             mov byte ptr [ecx + 0x1c], 0
// 007aff41  8b10                 mov edx, dword ptr [eax]
// 007aff43  8b7204               mov esi, dword ptr [edx + 4]
// 007aff46  eb5d                 jmp 0x7affa5
// 007aff48  3b31                 cmp esi, dword ptr [ecx]
// 007aff4a  750a                 jne 0x7aff56
// 007aff4c  8bf1                 mov esi, ecx
// 007aff4e  56                   push esi
// 007aff4f  8bcf                 mov ecx, edi
// 007aff51  e8aaf6ffff           call 0x7af600
// 007aff56  8b4604               mov eax, dword ptr [esi + 4]
// 007aff59  88581c               mov byte ptr [eax + 0x1c], bl
// 007aff5c  8b4e04               mov ecx, dword ptr [esi + 4]
// 007aff5f  8b5104               mov edx, dword ptr [ecx + 4]
// 007aff62  c6421c00             mov byte ptr [edx + 0x1c], 0
// 007aff66  8b4604               mov eax, dword ptr [esi + 4]
// 007aff69  8b4004               mov eax, dword ptr [eax + 4]
// 007aff6c  8b4808               mov ecx, dword ptr [eax + 8]
// 007aff6f  8b11                 mov edx, dword ptr [ecx]
// 007aff71  895008               mov dword ptr [eax + 8], edx
// 007aff74  8b11                 mov edx, dword ptr [ecx]
// 007aff76  807a1d00             cmp byte ptr [edx + 0x1d], 0
// 007aff7a  7503                 jne 0x7aff7f
// 007aff7c  894204               mov dword ptr [edx + 4], eax
// 007aff7f  8b5004               mov edx, dword ptr [eax + 4]
// 007aff82  895104               mov dword ptr [ecx + 4], edx
// 007aff85  8b5718               mov edx, dword ptr [edi + 0x18]
// 007aff88  3b4204               cmp eax, dword ptr [edx + 4]
// 007aff8b  7505                 jne 0x7aff92
// 007aff8d  894a04               mov dword ptr [edx + 4], ecx
// 007aff90  eb0e                 jmp 0x7affa0
// 007aff92  8b5004               mov edx, dword ptr [eax + 4]
// 007aff95  3b02                 cmp eax, dword ptr [edx]
// 007aff97  7504                 jne 0x7aff9d
// 007aff99  890a                 mov dword ptr [edx], ecx
// 007aff9b  eb03                 jmp 0x7affa0
// 007aff9d  894a08               mov dword ptr [edx + 8], ecx
// 007affa0  8901                 mov dword ptr [ecx], eax
// 007affa2  894804               mov dword ptr [eax + 4], ecx
// 007affa5  8b4e04               mov ecx, dword ptr [esi + 4]
// 007affa8  80791c00             cmp byte ptr [ecx + 0x1c], 0
// 007affac  8d4604               lea eax, [esi + 4]
// 007affaf  0f841bffffff         je 0x7afed0
// 007affb5  8b5718               mov edx, dword ptr [edi + 0x18]
// 007affb8  8b4204               mov eax, dword ptr [edx + 4]
// 007affbb  88581c               mov byte ptr [eax + 0x1c], bl
// 007affbe  8b442464             mov eax, dword ptr [esp + 0x64]
// 007affc2  8b0f                 mov ecx, dword ptr [edi]
// 007affc4  5e                   pop esi
// 007affc5  896804               mov dword ptr [eax + 4], ebp
// 007affc8  5d                   pop ebp
// 007affc9  8908                 mov dword ptr [eax], ecx
// 007affcb  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 007affcf  5b                   pop ebx
// 007affd0  5f                   pop edi
// 007affd1  64890d00000000       mov dword ptr fs:[0], ecx
// 007affd8  83c450               add esp, 0x50
// 007affdb  c21000               ret 0x10
// standard library map_int<pod12> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod12>
struct E { int v[3]; };
#include <map>
template class std::map<int, E>;
