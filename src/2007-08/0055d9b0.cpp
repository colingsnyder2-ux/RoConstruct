// from server: 100% by auto
// roc 2007-08 0055d9b0  unit: RBX::DataModel  size: 508 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0055d9b0
//
// 0055d9b0  64a100000000         mov eax, dword ptr fs:[0]
// 0055d9b6  6aff                 push -1
// 0055d9b8  68b2417500           push 0x7541b2
// 0055d9bd  50                   push eax
// 0055d9be  64892500000000       mov dword ptr fs:[0], esp
// 0055d9c5  83ec44               sub esp, 0x44
// 0055d9c8  57                   push edi
// 0055d9c9  8bf9                 mov edi, ecx
// 0055d9cb  817f0854555515       cmp dword ptr [edi + 8], 0x15555554
// 0055d9d2  7259                 jb 0x55da2d
// 0055d9d4  68904f7800           push 0x784f90
// 0055d9d9  8d4c2408             lea ecx, [esp + 8]
// 0055d9dd  ff1598e67700         call dword ptr [0x77e698]
// 0055d9e3  8d4c2420             lea ecx, [esp + 0x20]
// 0055d9e7  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0055d9ef  ff15f8e67700         call dword ptr [0x77e6f8]
// 0055d9f5  8d442404             lea eax, [esp + 4]
// 0055d9f9  50                   push eax
// 0055d9fa  8d4c2430             lea ecx, [esp + 0x30]
// 0055d9fe  c644245401           mov byte ptr [esp + 0x54], 1
// 0055da03  c7442424604e7800     mov dword ptr [esp + 0x24], 0x784e60
// 0055da0b  ff159ce67700         call dword ptr [0x77e69c]
// 0055da11  6878f78300           push 0x83f778
// 0055da16  8d4c2424             lea ecx, [esp + 0x24]
// 0055da1a  51                   push ecx
// 0055da1b  c644245800           mov byte ptr [esp + 0x58], 0
// 0055da20  c74424286c4e7800     mov dword ptr [esp + 0x28], 0x784e6c
// 0055da28  e871310d00           call 0x630b9e
// 0055da2d  8b542464             mov edx, dword ptr [esp + 0x64]
// 0055da31  8b4704               mov eax, dword ptr [edi + 4]
// 0055da34  53                   push ebx
// 0055da35  55                   push ebp
// 0055da36  56                   push esi
// 0055da37  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0055da3b  6a00                 push 0
// 0055da3d  52                   push edx
// 0055da3e  50                   push eax
// 0055da3f  56                   push esi
// 0055da40  50                   push eax
// 0055da41  e80affffff           call 0x55d950
// 0055da46  8be8                 mov ebp, eax
// 0055da48  8b4704               mov eax, dword ptr [edi + 4]
// 0055da4b  bb01000000           mov ebx, 1
// 0055da50  015f08               add dword ptr [edi + 8], ebx
// 0055da53  3bf0                 cmp esi, eax
// 0055da55  7510                 jne 0x55da67
// 0055da57  896804               mov dword ptr [eax + 4], ebp
// 0055da5a  8b4704               mov eax, dword ptr [edi + 4]
// 0055da5d  8928                 mov dword ptr [eax], ebp
// 0055da5f  8b4f04               mov ecx, dword ptr [edi + 4]
// 0055da62  896908               mov dword ptr [ecx + 8], ebp
// 0055da65  eb22                 jmp 0x55da89
// 0055da67  807c246800           cmp byte ptr [esp + 0x68], 0
// 0055da6c  740d                 je 0x55da7b
// 0055da6e  892e                 mov dword ptr [esi], ebp
// 0055da70  8b4704               mov eax, dword ptr [edi + 4]
// 0055da73  3b30                 cmp esi, dword ptr [eax]
// 0055da75  7512                 jne 0x55da89
// 0055da77  8928                 mov dword ptr [eax], ebp
// 0055da79  eb0e                 jmp 0x55da89
// 0055da7b  896e08               mov dword ptr [esi + 8], ebp
// 0055da7e  8b4704               mov eax, dword ptr [edi + 4]
// 0055da81  3b7008               cmp esi, dword ptr [eax + 8]
// 0055da84  7503                 jne 0x55da89
// 0055da86  896808               mov dword ptr [eax + 8], ebp
// 0055da89  8b5504               mov edx, dword ptr [ebp + 4]
// 0055da8c  807a1800             cmp byte ptr [edx + 0x18], 0
// 0055da90  8d4504               lea eax, [ebp + 4]
// 0055da93  8bf5                 mov esi, ebp
// 0055da95  0f85ea000000         jne 0x55db85
// 0055da9b  eb03                 jmp 0x55daa0
// 0055da9d  8d4900               lea ecx, [ecx]
// 0055daa0  8b08                 mov ecx, dword ptr [eax]
// 0055daa2  8b5104               mov edx, dword ptr [ecx + 4]
// 0055daa5  3b0a                 cmp ecx, dword ptr [edx]
// 0055daa7  7551                 jne 0x55dafa
// 0055daa9  8b5208               mov edx, dword ptr [edx + 8]
// 0055daac  807a1800             cmp byte ptr [edx + 0x18], 0
// 0055dab0  7519                 jne 0x55dacb
// 0055dab2  885918               mov byte ptr [ecx + 0x18], bl
// 0055dab5  885a18               mov byte ptr [edx + 0x18], bl
// 0055dab8  8b10                 mov edx, dword ptr [eax]
// 0055daba  8b4a04               mov ecx, dword ptr [edx + 4]
// 0055dabd  c6411800             mov byte ptr [ecx + 0x18], 0
// 0055dac1  8b10                 mov edx, dword ptr [eax]
// 0055dac3  8b7204               mov esi, dword ptr [edx + 4]
// 0055dac6  e9aa000000           jmp 0x55db75
// 0055dacb  3b7108               cmp esi, dword ptr [ecx + 8]
// 0055dace  750a                 jne 0x55dada
// 0055dad0  8bf1                 mov esi, ecx
// 0055dad2  56                   push esi
// 0055dad3  8bcf                 mov ecx, edi
// 0055dad5  e8e6090800           call 0x5de4c0
// 0055dada  8b4604               mov eax, dword ptr [esi + 4]
// 0055dadd  885818               mov byte ptr [eax + 0x18], bl
// 0055dae0  8b4e04               mov ecx, dword ptr [esi + 4]
// 0055dae3  8b5104               mov edx, dword ptr [ecx + 4]
// 0055dae6  c6421800             mov byte ptr [edx + 0x18], 0
// 0055daea  8b4604               mov eax, dword ptr [esi + 4]
// 0055daed  8b4804               mov ecx, dword ptr [eax + 4]
// 0055daf0  51                   push ecx
// 0055daf1  8bcf                 mov ecx, edi
// 0055daf3  e89819ebff           call 0x40f490
// 0055daf8  eb7b                 jmp 0x55db75
// 0055dafa  8b12                 mov edx, dword ptr [edx]
// 0055dafc  807a1800             cmp byte ptr [edx + 0x18], 0
// 0055db00  7516                 jne 0x55db18
// 0055db02  885918               mov byte ptr [ecx + 0x18], bl
// 0055db05  885a18               mov byte ptr [edx + 0x18], bl
// 0055db08  8b10                 mov edx, dword ptr [eax]
// 0055db0a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0055db0d  c6411800             mov byte ptr [ecx + 0x18], 0
// 0055db11  8b10                 mov edx, dword ptr [eax]
// 0055db13  8b7204               mov esi, dword ptr [edx + 4]
// 0055db16  eb5d                 jmp 0x55db75
// 0055db18  3b31                 cmp esi, dword ptr [ecx]
// 0055db1a  750a                 jne 0x55db26
// 0055db1c  8bf1                 mov esi, ecx
// 0055db1e  56                   push esi
// 0055db1f  8bcf                 mov ecx, edi
// 0055db21  e86a19ebff           call 0x40f490
// 0055db26  8b4604               mov eax, dword ptr [esi + 4]
// 0055db29  885818               mov byte ptr [eax + 0x18], bl
// 0055db2c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0055db2f  8b5104               mov edx, dword ptr [ecx + 4]
// 0055db32  c6421800             mov byte ptr [edx + 0x18], 0
// 0055db36  8b4604               mov eax, dword ptr [esi + 4]
// 0055db39  8b4004               mov eax, dword ptr [eax + 4]
// 0055db3c  8b4808               mov ecx, dword ptr [eax + 8]
// 0055db3f  8b11                 mov edx, dword ptr [ecx]
// 0055db41  895008               mov dword ptr [eax + 8], edx
// 0055db44  8b11                 mov edx, dword ptr [ecx]
// 0055db46  807a1900             cmp byte ptr [edx + 0x19], 0
// 0055db4a  7503                 jne 0x55db4f
// 0055db4c  894204               mov dword ptr [edx + 4], eax
// 0055db4f  8b5004               mov edx, dword ptr [eax + 4]
// 0055db52  895104               mov dword ptr [ecx + 4], edx
// 0055db55  8b5704               mov edx, dword ptr [edi + 4]
// 0055db58  3b4204               cmp eax, dword ptr [edx + 4]
// 0055db5b  7505                 jne 0x55db62
// 0055db5d  894a04               mov dword ptr [edx + 4], ecx
// 0055db60  eb0e                 jmp 0x55db70
// 0055db62  8b5004               mov edx, dword ptr [eax + 4]
// 0055db65  3b02                 cmp eax, dword ptr [edx]
// 0055db67  7504                 jne 0x55db6d
// 0055db69  890a                 mov dword ptr [edx], ecx
// 0055db6b  eb03                 jmp 0x55db70
// 0055db6d  894a08               mov dword ptr [edx + 8], ecx
// 0055db70  8901                 mov dword ptr [ecx], eax
// 0055db72  894804               mov dword ptr [eax + 4], ecx
// 0055db75  8b4e04               mov ecx, dword ptr [esi + 4]
// 0055db78  80791800             cmp byte ptr [ecx + 0x18], 0
// 0055db7c  8d4604               lea eax, [esi + 4]
// 0055db7f  0f841bffffff         je 0x55daa0
// 0055db85  8b5704               mov edx, dword ptr [edi + 4]
// 0055db88  8b4204               mov eax, dword ptr [edx + 4]
// 0055db8b  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 0055db8f  885818               mov byte ptr [eax + 0x18], bl
// 0055db92  8b442464             mov eax, dword ptr [esp + 0x64]
// 0055db96  5e                   pop esi
// 0055db97  896804               mov dword ptr [eax + 4], ebp
// 0055db9a  5d                   pop ebp
// 0055db9b  8938                 mov dword ptr [eax], edi
// 0055db9d  5b                   pop ebx
// 0055db9e  5f                   pop edi
// 0055db9f  64890d00000000       mov dword ptr fs:[0], ecx
// 0055dba6  83c450               add esp, 0x50
// 0055dba9  c21000               ret 0x10
// standard library map_int<pod8> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod8>
struct E { int v[2]; };
#include <map>
template class std::map<int, E>;
