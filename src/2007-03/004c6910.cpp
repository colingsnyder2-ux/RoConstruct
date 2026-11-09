// from server: 100% by auto
// roc 2007-03 004c6910  unit: seg_004c0000  size: 508 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 004c6910
//
// 004c6910  64a100000000         mov eax, dword ptr fs:[0]
// 004c6916  6aff                 push -1
// 004c6918  68926f7500           push 0x756f92
// 004c691d  50                   push eax
// 004c691e  64892500000000       mov dword ptr fs:[0], esp
// 004c6925  83ec44               sub esp, 0x44
// 004c6928  57                   push edi
// 004c6929  8bf9                 mov edi, ecx
// 004c692b  817f0848922409       cmp dword ptr [edi + 8], 0x9249248
// 004c6932  7259                 jb 0x4c698d
// 004c6934  68903f7800           push 0x783f90
// 004c6939  8d4c2408             lea ecx, [esp + 8]
// 004c693d  ff1578e77700         call dword ptr [0x77e778]
// 004c6943  8d4c2420             lea ecx, [esp + 0x20]
// 004c6947  c744245000000000     mov dword ptr [esp + 0x50], 0
// 004c694f  ff1560e97700         call dword ptr [0x77e960]
// 004c6955  8d442404             lea eax, [esp + 4]
// 004c6959  50                   push eax
// 004c695a  8d4c2430             lea ecx, [esp + 0x30]
// 004c695e  c644245401           mov byte ptr [esp + 0x54], 1
// 004c6963  c7442424383e7800     mov dword ptr [esp + 0x24], 0x783e38
// 004c696b  ff157ce77700         call dword ptr [0x77e77c]
// 004c6971  6870f78300           push 0x83f770
// 004c6976  8d4c2424             lea ecx, [esp + 0x24]
// 004c697a  51                   push ecx
// 004c697b  c644245800           mov byte ptr [esp + 0x58], 0
// 004c6980  c7442428443e7800     mov dword ptr [esp + 0x28], 0x783e44
// 004c6988  e8a1861500           call 0x61f02e
// 004c698d  8b542464             mov edx, dword ptr [esp + 0x64]
// 004c6991  8b4704               mov eax, dword ptr [edi + 4]
// 004c6994  53                   push ebx
// 004c6995  55                   push ebp
// 004c6996  56                   push esi
// 004c6997  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 004c699b  6a00                 push 0
// 004c699d  52                   push edx
// 004c699e  50                   push eax
// 004c699f  56                   push esi
// 004c69a0  50                   push eax
// 004c69a1  e89afcffff           call 0x4c6640
// 004c69a6  8be8                 mov ebp, eax
// 004c69a8  8b4704               mov eax, dword ptr [edi + 4]
// 004c69ab  bb01000000           mov ebx, 1
// 004c69b0  015f08               add dword ptr [edi + 8], ebx
// 004c69b3  3bf0                 cmp esi, eax
// 004c69b5  7510                 jne 0x4c69c7
// 004c69b7  896804               mov dword ptr [eax + 4], ebp
// 004c69ba  8b4704               mov eax, dword ptr [edi + 4]
// 004c69bd  8928                 mov dword ptr [eax], ebp
// 004c69bf  8b4f04               mov ecx, dword ptr [edi + 4]
// 004c69c2  896908               mov dword ptr [ecx + 8], ebp
// 004c69c5  eb22                 jmp 0x4c69e9
// 004c69c7  807c246800           cmp byte ptr [esp + 0x68], 0
// 004c69cc  740d                 je 0x4c69db
// 004c69ce  892e                 mov dword ptr [esi], ebp
// 004c69d0  8b4704               mov eax, dword ptr [edi + 4]
// 004c69d3  3b30                 cmp esi, dword ptr [eax]
// 004c69d5  7512                 jne 0x4c69e9
// 004c69d7  8928                 mov dword ptr [eax], ebp
// 004c69d9  eb0e                 jmp 0x4c69e9
// 004c69db  896e08               mov dword ptr [esi + 8], ebp
// 004c69de  8b4704               mov eax, dword ptr [edi + 4]
// 004c69e1  3b7008               cmp esi, dword ptr [eax + 8]
// 004c69e4  7503                 jne 0x4c69e9
// 004c69e6  896808               mov dword ptr [eax + 8], ebp
// 004c69e9  8b5504               mov edx, dword ptr [ebp + 4]
// 004c69ec  807a2800             cmp byte ptr [edx + 0x28], 0
// 004c69f0  8d4504               lea eax, [ebp + 4]
// 004c69f3  8bf5                 mov esi, ebp
// 004c69f5  0f85ea000000         jne 0x4c6ae5
// 004c69fb  eb03                 jmp 0x4c6a00
// 004c69fd  8d4900               lea ecx, [ecx]
// 004c6a00  8b08                 mov ecx, dword ptr [eax]
// 004c6a02  8b5104               mov edx, dword ptr [ecx + 4]
// 004c6a05  3b0a                 cmp ecx, dword ptr [edx]
// 004c6a07  7551                 jne 0x4c6a5a
// 004c6a09  8b5208               mov edx, dword ptr [edx + 8]
// 004c6a0c  807a2800             cmp byte ptr [edx + 0x28], 0
// 004c6a10  7519                 jne 0x4c6a2b
// 004c6a12  885928               mov byte ptr [ecx + 0x28], bl
// 004c6a15  885a28               mov byte ptr [edx + 0x28], bl
// 004c6a18  8b10                 mov edx, dword ptr [eax]
// 004c6a1a  8b4a04               mov ecx, dword ptr [edx + 4]
// 004c6a1d  c6412800             mov byte ptr [ecx + 0x28], 0
// 004c6a21  8b10                 mov edx, dword ptr [eax]
// 004c6a23  8b7204               mov esi, dword ptr [edx + 4]
// 004c6a26  e9aa000000           jmp 0x4c6ad5
// 004c6a2b  3b7108               cmp esi, dword ptr [ecx + 8]
// 004c6a2e  750a                 jne 0x4c6a3a
// 004c6a30  8bf1                 mov esi, ecx
// 004c6a32  56                   push esi
// 004c6a33  8bcf                 mov ecx, edi
// 004c6a35  e8b6e1ffff           call 0x4c4bf0
// 004c6a3a  8b4604               mov eax, dword ptr [esi + 4]
// 004c6a3d  885828               mov byte ptr [eax + 0x28], bl
// 004c6a40  8b4e04               mov ecx, dword ptr [esi + 4]
// 004c6a43  8b5104               mov edx, dword ptr [ecx + 4]
// 004c6a46  c6422800             mov byte ptr [edx + 0x28], 0
// 004c6a4a  8b4604               mov eax, dword ptr [esi + 4]
// 004c6a4d  8b4804               mov ecx, dword ptr [eax + 4]
// 004c6a50  51                   push ecx
// 004c6a51  8bcf                 mov ecx, edi
// 004c6a53  e828dcffff           call 0x4c4680
// 004c6a58  eb7b                 jmp 0x4c6ad5
// 004c6a5a  8b12                 mov edx, dword ptr [edx]
// 004c6a5c  807a2800             cmp byte ptr [edx + 0x28], 0
// 004c6a60  7516                 jne 0x4c6a78
// 004c6a62  885928               mov byte ptr [ecx + 0x28], bl
// 004c6a65  885a28               mov byte ptr [edx + 0x28], bl
// 004c6a68  8b10                 mov edx, dword ptr [eax]
// 004c6a6a  8b4a04               mov ecx, dword ptr [edx + 4]
// 004c6a6d  c6412800             mov byte ptr [ecx + 0x28], 0
// 004c6a71  8b10                 mov edx, dword ptr [eax]
// 004c6a73  8b7204               mov esi, dword ptr [edx + 4]
// 004c6a76  eb5d                 jmp 0x4c6ad5
// 004c6a78  3b31                 cmp esi, dword ptr [ecx]
// 004c6a7a  750a                 jne 0x4c6a86
// 004c6a7c  8bf1                 mov esi, ecx
// 004c6a7e  56                   push esi
// 004c6a7f  8bcf                 mov ecx, edi
// 004c6a81  e8fadbffff           call 0x4c4680
// 004c6a86  8b4604               mov eax, dword ptr [esi + 4]
// 004c6a89  885828               mov byte ptr [eax + 0x28], bl
// 004c6a8c  8b4e04               mov ecx, dword ptr [esi + 4]
// 004c6a8f  8b5104               mov edx, dword ptr [ecx + 4]
// 004c6a92  c6422800             mov byte ptr [edx + 0x28], 0
// 004c6a96  8b4604               mov eax, dword ptr [esi + 4]
// 004c6a99  8b4004               mov eax, dword ptr [eax + 4]
// 004c6a9c  8b4808               mov ecx, dword ptr [eax + 8]
// 004c6a9f  8b11                 mov edx, dword ptr [ecx]
// 004c6aa1  895008               mov dword ptr [eax + 8], edx
// 004c6aa4  8b11                 mov edx, dword ptr [ecx]
// 004c6aa6  807a2900             cmp byte ptr [edx + 0x29], 0
// 004c6aaa  7503                 jne 0x4c6aaf
// 004c6aac  894204               mov dword ptr [edx + 4], eax
// 004c6aaf  8b5004               mov edx, dword ptr [eax + 4]
// 004c6ab2  895104               mov dword ptr [ecx + 4], edx
// 004c6ab5  8b5704               mov edx, dword ptr [edi + 4]
// 004c6ab8  3b4204               cmp eax, dword ptr [edx + 4]
// 004c6abb  7505                 jne 0x4c6ac2
// 004c6abd  894a04               mov dword ptr [edx + 4], ecx
// 004c6ac0  eb0e                 jmp 0x4c6ad0
// 004c6ac2  8b5004               mov edx, dword ptr [eax + 4]
// 004c6ac5  3b02                 cmp eax, dword ptr [edx]
// 004c6ac7  7504                 jne 0x4c6acd
// 004c6ac9  890a                 mov dword ptr [edx], ecx
// 004c6acb  eb03                 jmp 0x4c6ad0
// 004c6acd  894a08               mov dword ptr [edx + 8], ecx
// 004c6ad0  8901                 mov dword ptr [ecx], eax
// 004c6ad2  894804               mov dword ptr [eax + 4], ecx
// 004c6ad5  8b4e04               mov ecx, dword ptr [esi + 4]
// 004c6ad8  80792800             cmp byte ptr [ecx + 0x28], 0
// 004c6adc  8d4604               lea eax, [esi + 4]
// 004c6adf  0f841bffffff         je 0x4c6a00
// 004c6ae5  8b5704               mov edx, dword ptr [edi + 4]
// 004c6ae8  8b4204               mov eax, dword ptr [edx + 4]
// 004c6aeb  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 004c6aef  885828               mov byte ptr [eax + 0x28], bl
// 004c6af2  8b442464             mov eax, dword ptr [esp + 0x64]
// 004c6af6  5e                   pop esi
// 004c6af7  896804               mov dword ptr [eax + 4], ebp
// 004c6afa  5d                   pop ebp
// 004c6afb  8938                 mov dword ptr [eax], edi
// 004c6afd  5b                   pop ebx
// 004c6afe  5f                   pop edi
// 004c6aff  64890d00000000       mov dword ptr fs:[0], ecx
// 004c6b06  83c450               add esp, 0x50
// 004c6b09  c21000               ret 0x10
// standard library map_int<pod24> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod24>
struct E { int v[6]; };
#include <map>
template class std::map<int, E>;
