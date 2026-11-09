// from server: 100% by auto
// roc 2009-06 0061be50  unit: RBX::Network::VPlayer::?$BoundFuncDesc  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0061be50
//
// 0061be50  64a100000000         mov eax, dword ptr fs:[0]
// 0061be56  6aff                 push -1
// 0061be58  68b2db8500           push 0x85dbb2
// 0061be5d  50                   push eax
// 0061be5e  64892500000000       mov dword ptr fs:[0], esp
// 0061be65  83ec44               sub esp, 0x44
// 0061be68  57                   push edi
// 0061be69  8bf9                 mov edi, ecx
// 0061be6b  817f1c43444404       cmp dword ptr [edi + 0x1c], 0x4444443
// 0061be72  7259                 jb 0x61becd
// 0061be74  68c0c98a00           push 0x8ac9c0
// 0061be79  8d4c2408             lea ecx, [esp + 8]
// 0061be7d  ff15b4e48900         call dword ptr [0x89e4b4]
// 0061be83  8d4c2420             lea ecx, [esp + 0x20]
// 0061be87  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0061be8f  ff15b8e98900         call dword ptr [0x89e9b8]
// 0061be95  8d442404             lea eax, [esp + 4]
// 0061be99  50                   push eax
// 0061be9a  8d4c2430             lea ecx, [esp + 0x30]
// 0061be9e  c644245401           mov byte ptr [esp + 0x54], 1
// 0061bea3  c744242444c98a00     mov dword ptr [esp + 0x24], 0x8ac944
// 0061beab  ff15b8e48900         call dword ptr [0x89e4b8]
// 0061beb1  6834929700           push 0x979234
// 0061beb6  8d4c2424             lea ecx, [esp + 0x24]
// 0061beba  51                   push ecx
// 0061bebb  c644245800           mov byte ptr [esp + 0x58], 0
// 0061bec0  c744242850c98a00     mov dword ptr [esp + 0x28], 0x8ac950
// 0061bec8  e87ddb0f00           call 0x719a4a
// 0061becd  8b542464             mov edx, dword ptr [esp + 0x64]
// 0061bed1  8b4718               mov eax, dword ptr [edi + 0x18]
// 0061bed4  53                   push ebx
// 0061bed5  55                   push ebp
// 0061bed6  56                   push esi
// 0061bed7  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0061bedb  6a00                 push 0
// 0061bedd  52                   push edx
// 0061bede  50                   push eax
// 0061bedf  56                   push esi
// 0061bee0  50                   push eax
// 0061bee1  e80af3ffff           call 0x61b1f0
// 0061bee6  8be8                 mov ebp, eax
// 0061bee8  8b4718               mov eax, dword ptr [edi + 0x18]
// 0061beeb  bb01000000           mov ebx, 1
// 0061bef0  015f1c               add dword ptr [edi + 0x1c], ebx
// 0061bef3  3bf0                 cmp esi, eax
// 0061bef5  7510                 jne 0x61bf07
// 0061bef7  896804               mov dword ptr [eax + 4], ebp
// 0061befa  8b4718               mov eax, dword ptr [edi + 0x18]
// 0061befd  8928                 mov dword ptr [eax], ebp
// 0061beff  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 0061bf02  896908               mov dword ptr [ecx + 8], ebp
// 0061bf05  eb22                 jmp 0x61bf29
// 0061bf07  807c246800           cmp byte ptr [esp + 0x68], 0
// 0061bf0c  740d                 je 0x61bf1b
// 0061bf0e  892e                 mov dword ptr [esi], ebp
// 0061bf10  8b4718               mov eax, dword ptr [edi + 0x18]
// 0061bf13  3b30                 cmp esi, dword ptr [eax]
// 0061bf15  7512                 jne 0x61bf29
// 0061bf17  8928                 mov dword ptr [eax], ebp
// 0061bf19  eb0e                 jmp 0x61bf29
// 0061bf1b  896e08               mov dword ptr [esi + 8], ebp
// 0061bf1e  8b4718               mov eax, dword ptr [edi + 0x18]
// 0061bf21  3b7008               cmp esi, dword ptr [eax + 8]
// 0061bf24  7503                 jne 0x61bf29
// 0061bf26  896808               mov dword ptr [eax + 8], ebp
// 0061bf29  8b5504               mov edx, dword ptr [ebp + 4]
// 0061bf2c  807a4800             cmp byte ptr [edx + 0x48], 0
// 0061bf30  8d4504               lea eax, [ebp + 4]
// 0061bf33  8bf5                 mov esi, ebp
// 0061bf35  0f85ea000000         jne 0x61c025
// 0061bf3b  eb03                 jmp 0x61bf40
// 0061bf3d  8d4900               lea ecx, [ecx]
// 0061bf40  8b08                 mov ecx, dword ptr [eax]
// 0061bf42  8b5104               mov edx, dword ptr [ecx + 4]
// 0061bf45  3b0a                 cmp ecx, dword ptr [edx]
// 0061bf47  7551                 jne 0x61bf9a
// 0061bf49  8b5208               mov edx, dword ptr [edx + 8]
// 0061bf4c  807a4800             cmp byte ptr [edx + 0x48], 0
// 0061bf50  7519                 jne 0x61bf6b
// 0061bf52  885948               mov byte ptr [ecx + 0x48], bl
// 0061bf55  885a48               mov byte ptr [edx + 0x48], bl
// 0061bf58  8b10                 mov edx, dword ptr [eax]
// 0061bf5a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0061bf5d  c6414800             mov byte ptr [ecx + 0x48], 0
// 0061bf61  8b10                 mov edx, dword ptr [eax]
// 0061bf63  8b7204               mov esi, dword ptr [edx + 4]
// 0061bf66  e9aa000000           jmp 0x61c015
// 0061bf6b  3b7108               cmp esi, dword ptr [ecx + 8]
// 0061bf6e  750a                 jne 0x61bf7a
// 0061bf70  8bf1                 mov esi, ecx
// 0061bf72  56                   push esi
// 0061bf73  8bcf                 mov ecx, edi
// 0061bf75  e876c6ffff           call 0x6185f0
// 0061bf7a  8b4604               mov eax, dword ptr [esi + 4]
// 0061bf7d  885848               mov byte ptr [eax + 0x48], bl
// 0061bf80  8b4e04               mov ecx, dword ptr [esi + 4]
// 0061bf83  8b5104               mov edx, dword ptr [ecx + 4]
// 0061bf86  c6424800             mov byte ptr [edx + 0x48], 0
// 0061bf8a  8b4604               mov eax, dword ptr [esi + 4]
// 0061bf8d  8b4804               mov ecx, dword ptr [eax + 4]
// 0061bf90  51                   push ecx
// 0061bf91  8bcf                 mov ecx, edi
// 0061bf93  e878c3ffff           call 0x618310
// 0061bf98  eb7b                 jmp 0x61c015
// 0061bf9a  8b12                 mov edx, dword ptr [edx]
// 0061bf9c  807a4800             cmp byte ptr [edx + 0x48], 0
// 0061bfa0  7516                 jne 0x61bfb8
// 0061bfa2  885948               mov byte ptr [ecx + 0x48], bl
// 0061bfa5  885a48               mov byte ptr [edx + 0x48], bl
// 0061bfa8  8b10                 mov edx, dword ptr [eax]
// 0061bfaa  8b4a04               mov ecx, dword ptr [edx + 4]
// 0061bfad  c6414800             mov byte ptr [ecx + 0x48], 0
// 0061bfb1  8b10                 mov edx, dword ptr [eax]
// 0061bfb3  8b7204               mov esi, dword ptr [edx + 4]
// 0061bfb6  eb5d                 jmp 0x61c015
// 0061bfb8  3b31                 cmp esi, dword ptr [ecx]
// 0061bfba  750a                 jne 0x61bfc6
// 0061bfbc  8bf1                 mov esi, ecx
// 0061bfbe  56                   push esi
// 0061bfbf  8bcf                 mov ecx, edi
// 0061bfc1  e84ac3ffff           call 0x618310
// 0061bfc6  8b4604               mov eax, dword ptr [esi + 4]
// 0061bfc9  885848               mov byte ptr [eax + 0x48], bl
// 0061bfcc  8b4e04               mov ecx, dword ptr [esi + 4]
// 0061bfcf  8b5104               mov edx, dword ptr [ecx + 4]
// 0061bfd2  c6424800             mov byte ptr [edx + 0x48], 0
// 0061bfd6  8b4604               mov eax, dword ptr [esi + 4]
// 0061bfd9  8b4004               mov eax, dword ptr [eax + 4]
// 0061bfdc  8b4808               mov ecx, dword ptr [eax + 8]
// 0061bfdf  8b11                 mov edx, dword ptr [ecx]
// 0061bfe1  895008               mov dword ptr [eax + 8], edx
// 0061bfe4  8b11                 mov edx, dword ptr [ecx]
// 0061bfe6  807a4900             cmp byte ptr [edx + 0x49], 0
// 0061bfea  7503                 jne 0x61bfef
// 0061bfec  894204               mov dword ptr [edx + 4], eax
// 0061bfef  8b5004               mov edx, dword ptr [eax + 4]
// 0061bff2  895104               mov dword ptr [ecx + 4], edx
// 0061bff5  8b5718               mov edx, dword ptr [edi + 0x18]
// 0061bff8  3b4204               cmp eax, dword ptr [edx + 4]
// 0061bffb  7505                 jne 0x61c002
// 0061bffd  894a04               mov dword ptr [edx + 4], ecx
// 0061c000  eb0e                 jmp 0x61c010
// 0061c002  8b5004               mov edx, dword ptr [eax + 4]
// 0061c005  3b02                 cmp eax, dword ptr [edx]
// 0061c007  7504                 jne 0x61c00d
// 0061c009  890a                 mov dword ptr [edx], ecx
// 0061c00b  eb03                 jmp 0x61c010
// 0061c00d  894a08               mov dword ptr [edx + 8], ecx
// 0061c010  8901                 mov dword ptr [ecx], eax
// 0061c012  894804               mov dword ptr [eax + 4], ecx
// 0061c015  8b4e04               mov ecx, dword ptr [esi + 4]
// 0061c018  80794800             cmp byte ptr [ecx + 0x48], 0
// 0061c01c  8d4604               lea eax, [esi + 4]
// 0061c01f  0f841bffffff         je 0x61bf40
// 0061c025  8b5718               mov edx, dword ptr [edi + 0x18]
// 0061c028  8b4204               mov eax, dword ptr [edx + 4]
// 0061c02b  885848               mov byte ptr [eax + 0x48], bl
// 0061c02e  8b442464             mov eax, dword ptr [esp + 0x64]
// 0061c032  8b0f                 mov ecx, dword ptr [edi]
// 0061c034  5e                   pop esi
// 0061c035  896804               mov dword ptr [eax + 4], ebp
// 0061c038  5d                   pop ebp
// 0061c039  8908                 mov dword ptr [eax], ecx
// 0061c03b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0061c03f  5b                   pop ebx
// 0061c040  5f                   pop edi
// 0061c041  64890d00000000       mov dword ptr fs:[0], ecx
// 0061c048  83c450               add esp, 0x50
// 0061c04b  c21000               ret 0x10
// standard library map_str<pod32> (function ?_Insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod32>
struct E { int v[8]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
