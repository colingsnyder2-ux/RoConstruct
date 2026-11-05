// from server: 100% by auto
// roc 2009-06 0043af00  unit: MVCXTPPropertyGridItem::?$XItem  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0043af00
//
// 0043af00  64a100000000         mov eax, dword ptr fs:[0]
// 0043af06  6aff                 push -1
// 0043af08  68b2db8500           push 0x85dbb2
// 0043af0d  50                   push eax
// 0043af0e  64892500000000       mov dword ptr fs:[0], esp
// 0043af15  83ec44               sub esp, 0x44
// 0043af18  57                   push edi
// 0043af19  8bf9                 mov edi, ecx
// 0043af1b  817f1c48922409       cmp dword ptr [edi + 0x1c], 0x9249248
// 0043af22  7259                 jb 0x43af7d
// 0043af24  68c0c98a00           push 0x8ac9c0
// 0043af29  8d4c2408             lea ecx, [esp + 8]
// 0043af2d  ff15b4e48900         call dword ptr [0x89e4b4]
// 0043af33  8d4c2420             lea ecx, [esp + 0x20]
// 0043af37  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0043af3f  ff15b8e98900         call dword ptr [0x89e9b8]
// 0043af45  8d442404             lea eax, [esp + 4]
// 0043af49  50                   push eax
// 0043af4a  8d4c2430             lea ecx, [esp + 0x30]
// 0043af4e  c644245401           mov byte ptr [esp + 0x54], 1
// 0043af53  c744242444c98a00     mov dword ptr [esp + 0x24], 0x8ac944
// 0043af5b  ff15b8e48900         call dword ptr [0x89e4b8]
// 0043af61  6834929700           push 0x979234
// 0043af66  8d4c2424             lea ecx, [esp + 0x24]
// 0043af6a  51                   push ecx
// 0043af6b  c644245800           mov byte ptr [esp + 0x58], 0
// 0043af70  c744242850c98a00     mov dword ptr [esp + 0x28], 0x8ac950
// 0043af78  e8cdea2d00           call 0x719a4a
// 0043af7d  8b542464             mov edx, dword ptr [esp + 0x64]
// 0043af81  8b4718               mov eax, dword ptr [edi + 0x18]
// 0043af84  53                   push ebx
// 0043af85  55                   push ebp
// 0043af86  56                   push esi
// 0043af87  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0043af8b  6a00                 push 0
// 0043af8d  52                   push edx
// 0043af8e  50                   push eax
// 0043af8f  56                   push esi
// 0043af90  50                   push eax
// 0043af91  e84ac2ffff           call 0x4371e0
// 0043af96  8be8                 mov ebp, eax
// 0043af98  8b4718               mov eax, dword ptr [edi + 0x18]
// 0043af9b  bb01000000           mov ebx, 1
// 0043afa0  015f1c               add dword ptr [edi + 0x1c], ebx
// 0043afa3  3bf0                 cmp esi, eax
// 0043afa5  7510                 jne 0x43afb7
// 0043afa7  896804               mov dword ptr [eax + 4], ebp
// 0043afaa  8b4718               mov eax, dword ptr [edi + 0x18]
// 0043afad  8928                 mov dword ptr [eax], ebp
// 0043afaf  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 0043afb2  896908               mov dword ptr [ecx + 8], ebp
// 0043afb5  eb22                 jmp 0x43afd9
// 0043afb7  807c246800           cmp byte ptr [esp + 0x68], 0
// 0043afbc  740d                 je 0x43afcb
// 0043afbe  892e                 mov dword ptr [esi], ebp
// 0043afc0  8b4718               mov eax, dword ptr [edi + 0x18]
// 0043afc3  3b30                 cmp esi, dword ptr [eax]
// 0043afc5  7512                 jne 0x43afd9
// 0043afc7  8928                 mov dword ptr [eax], ebp
// 0043afc9  eb0e                 jmp 0x43afd9
// 0043afcb  896e08               mov dword ptr [esi + 8], ebp
// 0043afce  8b4718               mov eax, dword ptr [edi + 0x18]
// 0043afd1  3b7008               cmp esi, dword ptr [eax + 8]
// 0043afd4  7503                 jne 0x43afd9
// 0043afd6  896808               mov dword ptr [eax + 8], ebp
// 0043afd9  8b5504               mov edx, dword ptr [ebp + 4]
// 0043afdc  807a2800             cmp byte ptr [edx + 0x28], 0
// 0043afe0  8d4504               lea eax, [ebp + 4]
// 0043afe3  8bf5                 mov esi, ebp
// 0043afe5  0f85ea000000         jne 0x43b0d5
// 0043afeb  eb03                 jmp 0x43aff0
// 0043afed  8d4900               lea ecx, [ecx]
// 0043aff0  8b08                 mov ecx, dword ptr [eax]
// 0043aff2  8b5104               mov edx, dword ptr [ecx + 4]
// 0043aff5  3b0a                 cmp ecx, dword ptr [edx]
// 0043aff7  7551                 jne 0x43b04a
// 0043aff9  8b5208               mov edx, dword ptr [edx + 8]
// 0043affc  807a2800             cmp byte ptr [edx + 0x28], 0
// 0043b000  7519                 jne 0x43b01b
// 0043b002  885928               mov byte ptr [ecx + 0x28], bl
// 0043b005  885a28               mov byte ptr [edx + 0x28], bl
// 0043b008  8b10                 mov edx, dword ptr [eax]
// 0043b00a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0043b00d  c6412800             mov byte ptr [ecx + 0x28], 0
// 0043b011  8b10                 mov edx, dword ptr [eax]
// 0043b013  8b7204               mov esi, dword ptr [edx + 4]
// 0043b016  e9aa000000           jmp 0x43b0c5
// 0043b01b  3b7108               cmp esi, dword ptr [ecx + 8]
// 0043b01e  750a                 jne 0x43b02a
// 0043b020  8bf1                 mov esi, ecx
// 0043b022  56                   push esi
// 0043b023  8bcf                 mov ecx, edi
// 0043b025  e8a6712a00           call 0x6e21d0
// 0043b02a  8b4604               mov eax, dword ptr [esi + 4]
// 0043b02d  885828               mov byte ptr [eax + 0x28], bl
// 0043b030  8b4e04               mov ecx, dword ptr [esi + 4]
// 0043b033  8b5104               mov edx, dword ptr [ecx + 4]
// 0043b036  c6422800             mov byte ptr [edx + 0x28], 0
// 0043b03a  8b4604               mov eax, dword ptr [esi + 4]
// 0043b03d  8b4804               mov ecx, dword ptr [eax + 4]
// 0043b040  51                   push ecx
// 0043b041  8bcf                 mov ecx, edi
// 0043b043  e8a8b90d00           call 0x5169f0
// 0043b048  eb7b                 jmp 0x43b0c5
// 0043b04a  8b12                 mov edx, dword ptr [edx]
// 0043b04c  807a2800             cmp byte ptr [edx + 0x28], 0
// 0043b050  7516                 jne 0x43b068
// 0043b052  885928               mov byte ptr [ecx + 0x28], bl
// 0043b055  885a28               mov byte ptr [edx + 0x28], bl
// 0043b058  8b10                 mov edx, dword ptr [eax]
// 0043b05a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0043b05d  c6412800             mov byte ptr [ecx + 0x28], 0
// 0043b061  8b10                 mov edx, dword ptr [eax]
// 0043b063  8b7204               mov esi, dword ptr [edx + 4]
// 0043b066  eb5d                 jmp 0x43b0c5
// 0043b068  3b31                 cmp esi, dword ptr [ecx]
// 0043b06a  750a                 jne 0x43b076
// 0043b06c  8bf1                 mov esi, ecx
// 0043b06e  56                   push esi
// 0043b06f  8bcf                 mov ecx, edi
// 0043b071  e87ab90d00           call 0x5169f0
// 0043b076  8b4604               mov eax, dword ptr [esi + 4]
// 0043b079  885828               mov byte ptr [eax + 0x28], bl
// 0043b07c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0043b07f  8b5104               mov edx, dword ptr [ecx + 4]
// 0043b082  c6422800             mov byte ptr [edx + 0x28], 0
// 0043b086  8b4604               mov eax, dword ptr [esi + 4]
// 0043b089  8b4004               mov eax, dword ptr [eax + 4]
// 0043b08c  8b4808               mov ecx, dword ptr [eax + 8]
// 0043b08f  8b11                 mov edx, dword ptr [ecx]
// 0043b091  895008               mov dword ptr [eax + 8], edx
// 0043b094  8b11                 mov edx, dword ptr [ecx]
// 0043b096  807a2900             cmp byte ptr [edx + 0x29], 0
// 0043b09a  7503                 jne 0x43b09f
// 0043b09c  894204               mov dword ptr [edx + 4], eax
// 0043b09f  8b5004               mov edx, dword ptr [eax + 4]
// 0043b0a2  895104               mov dword ptr [ecx + 4], edx
// 0043b0a5  8b5718               mov edx, dword ptr [edi + 0x18]
// 0043b0a8  3b4204               cmp eax, dword ptr [edx + 4]
// 0043b0ab  7505                 jne 0x43b0b2
// 0043b0ad  894a04               mov dword ptr [edx + 4], ecx
// 0043b0b0  eb0e                 jmp 0x43b0c0
// 0043b0b2  8b5004               mov edx, dword ptr [eax + 4]
// 0043b0b5  3b02                 cmp eax, dword ptr [edx]
// 0043b0b7  7504                 jne 0x43b0bd
// 0043b0b9  890a                 mov dword ptr [edx], ecx
// 0043b0bb  eb03                 jmp 0x43b0c0
// 0043b0bd  894a08               mov dword ptr [edx + 8], ecx
// 0043b0c0  8901                 mov dword ptr [ecx], eax
// 0043b0c2  894804               mov dword ptr [eax + 4], ecx
// 0043b0c5  8b4e04               mov ecx, dword ptr [esi + 4]
// 0043b0c8  80792800             cmp byte ptr [ecx + 0x28], 0
// 0043b0cc  8d4604               lea eax, [esi + 4]
// 0043b0cf  0f841bffffff         je 0x43aff0
// 0043b0d5  8b5718               mov edx, dword ptr [edi + 0x18]
// 0043b0d8  8b4204               mov eax, dword ptr [edx + 4]
// 0043b0db  885828               mov byte ptr [eax + 0x28], bl
// 0043b0de  8b442464             mov eax, dword ptr [esp + 0x64]
// 0043b0e2  8b0f                 mov ecx, dword ptr [edi]
// 0043b0e4  5e                   pop esi
// 0043b0e5  896804               mov dword ptr [eax + 4], ebp
// 0043b0e8  5d                   pop ebp
// 0043b0e9  8908                 mov dword ptr [eax], ecx
// 0043b0eb  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0043b0ef  5b                   pop ebx
// 0043b0f0  5f                   pop edi
// 0043b0f1  64890d00000000       mov dword ptr fs:[0], ecx
// 0043b0f8  83c450               add esp, 0x50
// 0043b0fb  c21000               ret 0x10
// standard library map_int<pod24> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod24>
struct E { int v[6]; };
#include <map>
template class std::map<int, E>;
