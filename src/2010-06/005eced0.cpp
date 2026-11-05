// from server: 100% by auto
// roc 2010-06 005eced0  unit: RBX::VChangeHistoryService::?$BoundFuncDesc  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005eced0
//
// 005eced0  64a100000000         mov eax, dword ptr fs:[0]
// 005eced6  6aff                 push -1
// 005eced8  68e22f9a00           push 0x9a2fe2
// 005ecedd  50                   push eax
// 005ecede  64892500000000       mov dword ptr fs:[0], esp
// 005ecee5  83ec44               sub esp, 0x44
// 005ecee8  57                   push edi
// 005ecee9  8bf9                 mov edi, ecx
// 005eceeb  817f1c43444404       cmp dword ptr [edi + 0x1c], 0x4444443
// 005ecef2  7259                 jb 0x5ecf4d
// 005ecef4  68a800a000           push 0xa000a8
// 005ecef9  8d4c2408             lea ecx, [esp + 8]
// 005ecefd  ff1510a49e00         call dword ptr [0x9ea410]
// 005ecf03  8d4c2420             lea ecx, [esp + 0x20]
// 005ecf07  c744245000000000     mov dword ptr [esp + 0x50], 0
// 005ecf0f  ff1518a99e00         call dword ptr [0x9ea918]
// 005ecf15  8d442404             lea eax, [esp + 4]
// 005ecf19  50                   push eax
// 005ecf1a  8d4c2430             lea ecx, [esp + 0x30]
// 005ecf1e  c644245401           mov byte ptr [esp + 0x54], 1
// 005ecf23  c74424242c00a000     mov dword ptr [esp + 0x24], 0xa0002c
// 005ecf2b  ff150ca49e00         call dword ptr [0x9ea40c]
// 005ecf31  68601bb000           push 0xb01b60
// 005ecf36  8d4c2424             lea ecx, [esp + 0x24]
// 005ecf3a  51                   push ecx
// 005ecf3b  c644245800           mov byte ptr [esp + 0x58], 0
// 005ecf40  c74424283800a000     mov dword ptr [esp + 0x28], 0xa00038
// 005ecf48  e865ba1b00           call 0x7a89b2
// 005ecf4d  8b542464             mov edx, dword ptr [esp + 0x64]
// 005ecf51  8b4718               mov eax, dword ptr [edi + 0x18]
// 005ecf54  53                   push ebx
// 005ecf55  55                   push ebp
// 005ecf56  56                   push esi
// 005ecf57  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 005ecf5b  6a00                 push 0
// 005ecf5d  52                   push edx
// 005ecf5e  50                   push eax
// 005ecf5f  56                   push esi
// 005ecf60  50                   push eax
// 005ecf61  e80af3ffff           call 0x5ec270
// 005ecf66  8be8                 mov ebp, eax
// 005ecf68  8b4718               mov eax, dword ptr [edi + 0x18]
// 005ecf6b  bb01000000           mov ebx, 1
// 005ecf70  015f1c               add dword ptr [edi + 0x1c], ebx
// 005ecf73  3bf0                 cmp esi, eax
// 005ecf75  7510                 jne 0x5ecf87
// 005ecf77  896804               mov dword ptr [eax + 4], ebp
// 005ecf7a  8b4718               mov eax, dword ptr [edi + 0x18]
// 005ecf7d  8928                 mov dword ptr [eax], ebp
// 005ecf7f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 005ecf82  896908               mov dword ptr [ecx + 8], ebp
// 005ecf85  eb22                 jmp 0x5ecfa9
// 005ecf87  807c246800           cmp byte ptr [esp + 0x68], 0
// 005ecf8c  740d                 je 0x5ecf9b
// 005ecf8e  892e                 mov dword ptr [esi], ebp
// 005ecf90  8b4718               mov eax, dword ptr [edi + 0x18]
// 005ecf93  3b30                 cmp esi, dword ptr [eax]
// 005ecf95  7512                 jne 0x5ecfa9
// 005ecf97  8928                 mov dword ptr [eax], ebp
// 005ecf99  eb0e                 jmp 0x5ecfa9
// 005ecf9b  896e08               mov dword ptr [esi + 8], ebp
// 005ecf9e  8b4718               mov eax, dword ptr [edi + 0x18]
// 005ecfa1  3b7008               cmp esi, dword ptr [eax + 8]
// 005ecfa4  7503                 jne 0x5ecfa9
// 005ecfa6  896808               mov dword ptr [eax + 8], ebp
// 005ecfa9  8b5504               mov edx, dword ptr [ebp + 4]
// 005ecfac  807a4800             cmp byte ptr [edx + 0x48], 0
// 005ecfb0  8d4504               lea eax, [ebp + 4]
// 005ecfb3  8bf5                 mov esi, ebp
// 005ecfb5  0f85ea000000         jne 0x5ed0a5
// 005ecfbb  eb03                 jmp 0x5ecfc0
// 005ecfbd  8d4900               lea ecx, [ecx]
// 005ecfc0  8b08                 mov ecx, dword ptr [eax]
// 005ecfc2  8b5104               mov edx, dword ptr [ecx + 4]
// 005ecfc5  3b0a                 cmp ecx, dword ptr [edx]
// 005ecfc7  7551                 jne 0x5ed01a
// 005ecfc9  8b5208               mov edx, dword ptr [edx + 8]
// 005ecfcc  807a4800             cmp byte ptr [edx + 0x48], 0
// 005ecfd0  7519                 jne 0x5ecfeb
// 005ecfd2  885948               mov byte ptr [ecx + 0x48], bl
// 005ecfd5  885a48               mov byte ptr [edx + 0x48], bl
// 005ecfd8  8b10                 mov edx, dword ptr [eax]
// 005ecfda  8b4a04               mov ecx, dword ptr [edx + 4]
// 005ecfdd  c6414800             mov byte ptr [ecx + 0x48], 0
// 005ecfe1  8b10                 mov edx, dword ptr [eax]
// 005ecfe3  8b7204               mov esi, dword ptr [edx + 4]
// 005ecfe6  e9aa000000           jmp 0x5ed095
// 005ecfeb  3b7108               cmp esi, dword ptr [ecx + 8]
// 005ecfee  750a                 jne 0x5ecffa
// 005ecff0  8bf1                 mov esi, ecx
// 005ecff2  56                   push esi
// 005ecff3  8bcf                 mov ecx, edi
// 005ecff5  e856030200           call 0x60d350
// 005ecffa  8b4604               mov eax, dword ptr [esi + 4]
// 005ecffd  885848               mov byte ptr [eax + 0x48], bl
// 005ed000  8b4e04               mov ecx, dword ptr [esi + 4]
// 005ed003  8b5104               mov edx, dword ptr [ecx + 4]
// 005ed006  c6424800             mov byte ptr [edx + 0x48], 0
// 005ed00a  8b4604               mov eax, dword ptr [esi + 4]
// 005ed00d  8b4804               mov ecx, dword ptr [eax + 4]
// 005ed010  51                   push ecx
// 005ed011  8bcf                 mov ecx, edi
// 005ed013  e828241800           call 0x76f440
// 005ed018  eb7b                 jmp 0x5ed095
// 005ed01a  8b12                 mov edx, dword ptr [edx]
// 005ed01c  807a4800             cmp byte ptr [edx + 0x48], 0
// 005ed020  7516                 jne 0x5ed038
// 005ed022  885948               mov byte ptr [ecx + 0x48], bl
// 005ed025  885a48               mov byte ptr [edx + 0x48], bl
// 005ed028  8b10                 mov edx, dword ptr [eax]
// 005ed02a  8b4a04               mov ecx, dword ptr [edx + 4]
// 005ed02d  c6414800             mov byte ptr [ecx + 0x48], 0
// 005ed031  8b10                 mov edx, dword ptr [eax]
// 005ed033  8b7204               mov esi, dword ptr [edx + 4]
// 005ed036  eb5d                 jmp 0x5ed095
// 005ed038  3b31                 cmp esi, dword ptr [ecx]
// 005ed03a  750a                 jne 0x5ed046
// 005ed03c  8bf1                 mov esi, ecx
// 005ed03e  56                   push esi
// 005ed03f  8bcf                 mov ecx, edi
// 005ed041  e8fa231800           call 0x76f440
// 005ed046  8b4604               mov eax, dword ptr [esi + 4]
// 005ed049  885848               mov byte ptr [eax + 0x48], bl
// 005ed04c  8b4e04               mov ecx, dword ptr [esi + 4]
// 005ed04f  8b5104               mov edx, dword ptr [ecx + 4]
// 005ed052  c6424800             mov byte ptr [edx + 0x48], 0
// 005ed056  8b4604               mov eax, dword ptr [esi + 4]
// 005ed059  8b4004               mov eax, dword ptr [eax + 4]
// 005ed05c  8b4808               mov ecx, dword ptr [eax + 8]
// 005ed05f  8b11                 mov edx, dword ptr [ecx]
// 005ed061  895008               mov dword ptr [eax + 8], edx
// 005ed064  8b11                 mov edx, dword ptr [ecx]
// 005ed066  807a4900             cmp byte ptr [edx + 0x49], 0
// 005ed06a  7503                 jne 0x5ed06f
// 005ed06c  894204               mov dword ptr [edx + 4], eax
// 005ed06f  8b5004               mov edx, dword ptr [eax + 4]
// 005ed072  895104               mov dword ptr [ecx + 4], edx
// 005ed075  8b5718               mov edx, dword ptr [edi + 0x18]
// 005ed078  3b4204               cmp eax, dword ptr [edx + 4]
// 005ed07b  7505                 jne 0x5ed082
// 005ed07d  894a04               mov dword ptr [edx + 4], ecx
// 005ed080  eb0e                 jmp 0x5ed090
// 005ed082  8b5004               mov edx, dword ptr [eax + 4]
// 005ed085  3b02                 cmp eax, dword ptr [edx]
// 005ed087  7504                 jne 0x5ed08d
// 005ed089  890a                 mov dword ptr [edx], ecx
// 005ed08b  eb03                 jmp 0x5ed090
// 005ed08d  894a08               mov dword ptr [edx + 8], ecx
// 005ed090  8901                 mov dword ptr [ecx], eax
// 005ed092  894804               mov dword ptr [eax + 4], ecx
// 005ed095  8b4e04               mov ecx, dword ptr [esi + 4]
// 005ed098  80794800             cmp byte ptr [ecx + 0x48], 0
// 005ed09c  8d4604               lea eax, [esi + 4]
// 005ed09f  0f841bffffff         je 0x5ecfc0
// 005ed0a5  8b5718               mov edx, dword ptr [edi + 0x18]
// 005ed0a8  8b4204               mov eax, dword ptr [edx + 4]
// 005ed0ab  885848               mov byte ptr [eax + 0x48], bl
// 005ed0ae  8b442464             mov eax, dword ptr [esp + 0x64]
// 005ed0b2  8b0f                 mov ecx, dword ptr [edi]
// 005ed0b4  5e                   pop esi
// 005ed0b5  896804               mov dword ptr [eax + 4], ebp
// 005ed0b8  5d                   pop ebp
// 005ed0b9  8908                 mov dword ptr [eax], ecx
// 005ed0bb  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 005ed0bf  5b                   pop ebx
// 005ed0c0  5f                   pop edi
// 005ed0c1  64890d00000000       mov dword ptr fs:[0], ecx
// 005ed0c8  83c450               add esp, 0x50
// 005ed0cb  c21000               ret 0x10
// standard library map_str<pod32> (function ?_Insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod32>
struct E { int v[8]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
