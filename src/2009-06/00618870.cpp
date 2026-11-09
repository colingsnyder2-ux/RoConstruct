// from server: 100% by auto
// roc 2009-06 00618870  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00618870
//
// 00618870  64a100000000         mov eax, dword ptr fs:[0]
// 00618876  6aff                 push -1
// 00618878  68b2db8500           push 0x85dbb2
// 0061887d  50                   push eax
// 0061887e  64892500000000       mov dword ptr fs:[0], esp
// 00618885  83ec44               sub esp, 0x44
// 00618888  57                   push edi
// 00618889  8bf9                 mov edi, ecx
// 0061888b  817f1c54555515       cmp dword ptr [edi + 0x1c], 0x15555554
// 00618892  7259                 jb 0x6188ed
// 00618894  68c0c98a00           push 0x8ac9c0
// 00618899  8d4c2408             lea ecx, [esp + 8]
// 0061889d  ff15b4e48900         call dword ptr [0x89e4b4]
// 006188a3  8d4c2420             lea ecx, [esp + 0x20]
// 006188a7  c744245000000000     mov dword ptr [esp + 0x50], 0
// 006188af  ff15b8e98900         call dword ptr [0x89e9b8]
// 006188b5  8d442404             lea eax, [esp + 4]
// 006188b9  50                   push eax
// 006188ba  8d4c2430             lea ecx, [esp + 0x30]
// 006188be  c644245401           mov byte ptr [esp + 0x54], 1
// 006188c3  c744242444c98a00     mov dword ptr [esp + 0x24], 0x8ac944
// 006188cb  ff15b8e48900         call dword ptr [0x89e4b8]
// 006188d1  6834929700           push 0x979234
// 006188d6  8d4c2424             lea ecx, [esp + 0x24]
// 006188da  51                   push ecx
// 006188db  c644245800           mov byte ptr [esp + 0x58], 0
// 006188e0  c744242850c98a00     mov dword ptr [esp + 0x28], 0x8ac950
// 006188e8  e85d111000           call 0x719a4a
// 006188ed  8b542464             mov edx, dword ptr [esp + 0x64]
// 006188f1  8b4718               mov eax, dword ptr [edi + 0x18]
// 006188f4  53                   push ebx
// 006188f5  55                   push ebp
// 006188f6  56                   push esi
// 006188f7  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 006188fb  6a00                 push 0
// 006188fd  52                   push edx
// 006188fe  50                   push eax
// 006188ff  56                   push esi
// 00618900  50                   push eax
// 00618901  e84afeffff           call 0x618750
// 00618906  8be8                 mov ebp, eax
// 00618908  8b4718               mov eax, dword ptr [edi + 0x18]
// 0061890b  bb01000000           mov ebx, 1
// 00618910  015f1c               add dword ptr [edi + 0x1c], ebx
// 00618913  3bf0                 cmp esi, eax
// 00618915  7510                 jne 0x618927
// 00618917  896804               mov dword ptr [eax + 4], ebp
// 0061891a  8b4718               mov eax, dword ptr [edi + 0x18]
// 0061891d  8928                 mov dword ptr [eax], ebp
// 0061891f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 00618922  896908               mov dword ptr [ecx + 8], ebp
// 00618925  eb22                 jmp 0x618949
// 00618927  807c246800           cmp byte ptr [esp + 0x68], 0
// 0061892c  740d                 je 0x61893b
// 0061892e  892e                 mov dword ptr [esi], ebp
// 00618930  8b4718               mov eax, dword ptr [edi + 0x18]
// 00618933  3b30                 cmp esi, dword ptr [eax]
// 00618935  7512                 jne 0x618949
// 00618937  8928                 mov dword ptr [eax], ebp
// 00618939  eb0e                 jmp 0x618949
// 0061893b  896e08               mov dword ptr [esi + 8], ebp
// 0061893e  8b4718               mov eax, dword ptr [edi + 0x18]
// 00618941  3b7008               cmp esi, dword ptr [eax + 8]
// 00618944  7503                 jne 0x618949
// 00618946  896808               mov dword ptr [eax + 8], ebp
// 00618949  8b5504               mov edx, dword ptr [ebp + 4]
// 0061894c  807a1800             cmp byte ptr [edx + 0x18], 0
// 00618950  8d4504               lea eax, [ebp + 4]
// 00618953  8bf5                 mov esi, ebp
// 00618955  0f85ea000000         jne 0x618a45
// 0061895b  eb03                 jmp 0x618960
// 0061895d  8d4900               lea ecx, [ecx]
// 00618960  8b08                 mov ecx, dword ptr [eax]
// 00618962  8b5104               mov edx, dword ptr [ecx + 4]
// 00618965  3b0a                 cmp ecx, dword ptr [edx]
// 00618967  7551                 jne 0x6189ba
// 00618969  8b5208               mov edx, dword ptr [edx + 8]
// 0061896c  807a1800             cmp byte ptr [edx + 0x18], 0
// 00618970  7519                 jne 0x61898b
// 00618972  885918               mov byte ptr [ecx + 0x18], bl
// 00618975  885a18               mov byte ptr [edx + 0x18], bl
// 00618978  8b10                 mov edx, dword ptr [eax]
// 0061897a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0061897d  c6411800             mov byte ptr [ecx + 0x18], 0
// 00618981  8b10                 mov edx, dword ptr [eax]
// 00618983  8b7204               mov esi, dword ptr [edx + 4]
// 00618986  e9aa000000           jmp 0x618a35
// 0061898b  3b7108               cmp esi, dword ptr [ecx + 8]
// 0061898e  750a                 jne 0x61899a
// 00618990  8bf1                 mov esi, ecx
// 00618992  56                   push esi
// 00618993  8bcf                 mov ecx, edi
// 00618995  e8a6fcffff           call 0x618640
// 0061899a  8b4604               mov eax, dword ptr [esi + 4]
// 0061899d  885818               mov byte ptr [eax + 0x18], bl
// 006189a0  8b4e04               mov ecx, dword ptr [esi + 4]
// 006189a3  8b5104               mov edx, dword ptr [ecx + 4]
// 006189a6  c6421800             mov byte ptr [edx + 0x18], 0
// 006189aa  8b4604               mov eax, dword ptr [esi + 4]
// 006189ad  8b4804               mov ecx, dword ptr [eax + 4]
// 006189b0  51                   push ecx
// 006189b1  8bcf                 mov ecx, edi
// 006189b3  e808b10200           call 0x643ac0
// 006189b8  eb7b                 jmp 0x618a35
// 006189ba  8b12                 mov edx, dword ptr [edx]
// 006189bc  807a1800             cmp byte ptr [edx + 0x18], 0
// 006189c0  7516                 jne 0x6189d8
// 006189c2  885918               mov byte ptr [ecx + 0x18], bl
// 006189c5  885a18               mov byte ptr [edx + 0x18], bl
// 006189c8  8b10                 mov edx, dword ptr [eax]
// 006189ca  8b4a04               mov ecx, dword ptr [edx + 4]
// 006189cd  c6411800             mov byte ptr [ecx + 0x18], 0
// 006189d1  8b10                 mov edx, dword ptr [eax]
// 006189d3  8b7204               mov esi, dword ptr [edx + 4]
// 006189d6  eb5d                 jmp 0x618a35
// 006189d8  3b31                 cmp esi, dword ptr [ecx]
// 006189da  750a                 jne 0x6189e6
// 006189dc  8bf1                 mov esi, ecx
// 006189de  56                   push esi
// 006189df  8bcf                 mov ecx, edi
// 006189e1  e8dab00200           call 0x643ac0
// 006189e6  8b4604               mov eax, dword ptr [esi + 4]
// 006189e9  885818               mov byte ptr [eax + 0x18], bl
// 006189ec  8b4e04               mov ecx, dword ptr [esi + 4]
// 006189ef  8b5104               mov edx, dword ptr [ecx + 4]
// 006189f2  c6421800             mov byte ptr [edx + 0x18], 0
// 006189f6  8b4604               mov eax, dword ptr [esi + 4]
// 006189f9  8b4004               mov eax, dword ptr [eax + 4]
// 006189fc  8b4808               mov ecx, dword ptr [eax + 8]
// 006189ff  8b11                 mov edx, dword ptr [ecx]
// 00618a01  895008               mov dword ptr [eax + 8], edx
// 00618a04  8b11                 mov edx, dword ptr [ecx]
// 00618a06  807a1900             cmp byte ptr [edx + 0x19], 0
// 00618a0a  7503                 jne 0x618a0f
// 00618a0c  894204               mov dword ptr [edx + 4], eax
// 00618a0f  8b5004               mov edx, dword ptr [eax + 4]
// 00618a12  895104               mov dword ptr [ecx + 4], edx
// 00618a15  8b5718               mov edx, dword ptr [edi + 0x18]
// 00618a18  3b4204               cmp eax, dword ptr [edx + 4]
// 00618a1b  7505                 jne 0x618a22
// 00618a1d  894a04               mov dword ptr [edx + 4], ecx
// 00618a20  eb0e                 jmp 0x618a30
// 00618a22  8b5004               mov edx, dword ptr [eax + 4]
// 00618a25  3b02                 cmp eax, dword ptr [edx]
// 00618a27  7504                 jne 0x618a2d
// 00618a29  890a                 mov dword ptr [edx], ecx
// 00618a2b  eb03                 jmp 0x618a30
// 00618a2d  894a08               mov dword ptr [edx + 8], ecx
// 00618a30  8901                 mov dword ptr [ecx], eax
// 00618a32  894804               mov dword ptr [eax + 4], ecx
// 00618a35  8b4e04               mov ecx, dword ptr [esi + 4]
// 00618a38  80791800             cmp byte ptr [ecx + 0x18], 0
// 00618a3c  8d4604               lea eax, [esi + 4]
// 00618a3f  0f841bffffff         je 0x618960
// 00618a45  8b5718               mov edx, dword ptr [edi + 0x18]
// 00618a48  8b4204               mov eax, dword ptr [edx + 4]
// 00618a4b  885818               mov byte ptr [eax + 0x18], bl
// 00618a4e  8b442464             mov eax, dword ptr [esp + 0x64]
// 00618a52  8b0f                 mov ecx, dword ptr [edi]
// 00618a54  5e                   pop esi
// 00618a55  896804               mov dword ptr [eax + 4], ebp
// 00618a58  5d                   pop ebp
// 00618a59  8908                 mov dword ptr [eax], ecx
// 00618a5b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00618a5f  5b                   pop ebx
// 00618a60  5f                   pop edi
// 00618a61  64890d00000000       mov dword ptr fs:[0], ecx
// 00618a68  83c450               add esp, 0x50
// 00618a6b  c21000               ret 0x10
// standard library map_int<pod8> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod8>
struct E { int v[2]; };
#include <map>
template class std::map<int, E>;
