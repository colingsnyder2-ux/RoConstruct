// from server: 100% by auto
// roc 2009-06 006fd550  unit: Ogre::VRbxFont::?$SharedPtr  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006fd550
//
// 006fd550  64a100000000         mov eax, dword ptr fs:[0]
// 006fd556  6aff                 push -1
// 006fd558  68b2db8500           push 0x85dbb2
// 006fd55d  50                   push eax
// 006fd55e  64892500000000       mov dword ptr fs:[0], esp
// 006fd565  83ec44               sub esp, 0x44
// 006fd568  57                   push edi
// 006fd569  8bf9                 mov edi, ecx
// 006fd56b  817f1c65666606       cmp dword ptr [edi + 0x1c], 0x6666665
// 006fd572  7259                 jb 0x6fd5cd
// 006fd574  68c0c98a00           push 0x8ac9c0
// 006fd579  8d4c2408             lea ecx, [esp + 8]
// 006fd57d  ff15b4e48900         call dword ptr [0x89e4b4]
// 006fd583  8d4c2420             lea ecx, [esp + 0x20]
// 006fd587  c744245000000000     mov dword ptr [esp + 0x50], 0
// 006fd58f  ff15b8e98900         call dword ptr [0x89e9b8]
// 006fd595  8d442404             lea eax, [esp + 4]
// 006fd599  50                   push eax
// 006fd59a  8d4c2430             lea ecx, [esp + 0x30]
// 006fd59e  c644245401           mov byte ptr [esp + 0x54], 1
// 006fd5a3  c744242444c98a00     mov dword ptr [esp + 0x24], 0x8ac944
// 006fd5ab  ff15b8e48900         call dword ptr [0x89e4b8]
// 006fd5b1  6834929700           push 0x979234
// 006fd5b6  8d4c2424             lea ecx, [esp + 0x24]
// 006fd5ba  51                   push ecx
// 006fd5bb  c644245800           mov byte ptr [esp + 0x58], 0
// 006fd5c0  c744242850c98a00     mov dword ptr [esp + 0x28], 0x8ac950
// 006fd5c8  e87dc40100           call 0x719a4a
// 006fd5cd  8b542464             mov edx, dword ptr [esp + 0x64]
// 006fd5d1  8b4718               mov eax, dword ptr [edi + 0x18]
// 006fd5d4  53                   push ebx
// 006fd5d5  55                   push ebp
// 006fd5d6  56                   push esi
// 006fd5d7  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 006fd5db  6a00                 push 0
// 006fd5dd  52                   push edx
// 006fd5de  50                   push eax
// 006fd5df  56                   push esi
// 006fd5e0  50                   push eax
// 006fd5e1  e8cafeffff           call 0x6fd4b0
// 006fd5e6  8be8                 mov ebp, eax
// 006fd5e8  8b4718               mov eax, dword ptr [edi + 0x18]
// 006fd5eb  bb01000000           mov ebx, 1
// 006fd5f0  015f1c               add dword ptr [edi + 0x1c], ebx
// 006fd5f3  3bf0                 cmp esi, eax
// 006fd5f5  7510                 jne 0x6fd607
// 006fd5f7  896804               mov dword ptr [eax + 4], ebp
// 006fd5fa  8b4718               mov eax, dword ptr [edi + 0x18]
// 006fd5fd  8928                 mov dword ptr [eax], ebp
// 006fd5ff  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 006fd602  896908               mov dword ptr [ecx + 8], ebp
// 006fd605  eb22                 jmp 0x6fd629
// 006fd607  807c246800           cmp byte ptr [esp + 0x68], 0
// 006fd60c  740d                 je 0x6fd61b
// 006fd60e  892e                 mov dword ptr [esi], ebp
// 006fd610  8b4718               mov eax, dword ptr [edi + 0x18]
// 006fd613  3b30                 cmp esi, dword ptr [eax]
// 006fd615  7512                 jne 0x6fd629
// 006fd617  8928                 mov dword ptr [eax], ebp
// 006fd619  eb0e                 jmp 0x6fd629
// 006fd61b  896e08               mov dword ptr [esi + 8], ebp
// 006fd61e  8b4718               mov eax, dword ptr [edi + 0x18]
// 006fd621  3b7008               cmp esi, dword ptr [eax + 8]
// 006fd624  7503                 jne 0x6fd629
// 006fd626  896808               mov dword ptr [eax + 8], ebp
// 006fd629  8b5504               mov edx, dword ptr [ebp + 4]
// 006fd62c  807a3400             cmp byte ptr [edx + 0x34], 0
// 006fd630  8d4504               lea eax, [ebp + 4]
// 006fd633  8bf5                 mov esi, ebp
// 006fd635  0f85ea000000         jne 0x6fd725
// 006fd63b  eb03                 jmp 0x6fd640
// 006fd63d  8d4900               lea ecx, [ecx]
// 006fd640  8b08                 mov ecx, dword ptr [eax]
// 006fd642  8b5104               mov edx, dword ptr [ecx + 4]
// 006fd645  3b0a                 cmp ecx, dword ptr [edx]
// 006fd647  7551                 jne 0x6fd69a
// 006fd649  8b5208               mov edx, dword ptr [edx + 8]
// 006fd64c  807a3400             cmp byte ptr [edx + 0x34], 0
// 006fd650  7519                 jne 0x6fd66b
// 006fd652  885934               mov byte ptr [ecx + 0x34], bl
// 006fd655  885a34               mov byte ptr [edx + 0x34], bl
// 006fd658  8b10                 mov edx, dword ptr [eax]
// 006fd65a  8b4a04               mov ecx, dword ptr [edx + 4]
// 006fd65d  c6413400             mov byte ptr [ecx + 0x34], 0
// 006fd661  8b10                 mov edx, dword ptr [eax]
// 006fd663  8b7204               mov esi, dword ptr [edx + 4]
// 006fd666  e9aa000000           jmp 0x6fd715
// 006fd66b  3b7108               cmp esi, dword ptr [ecx + 8]
// 006fd66e  750a                 jne 0x6fd67a
// 006fd670  8bf1                 mov esi, ecx
// 006fd672  56                   push esi
// 006fd673  8bcf                 mov ecx, edi
// 006fd675  e866f4ffff           call 0x6fcae0
// 006fd67a  8b4604               mov eax, dword ptr [esi + 4]
// 006fd67d  885834               mov byte ptr [eax + 0x34], bl
// 006fd680  8b4e04               mov ecx, dword ptr [esi + 4]
// 006fd683  8b5104               mov edx, dword ptr [ecx + 4]
// 006fd686  c6423400             mov byte ptr [edx + 0x34], 0
// 006fd68a  8b4604               mov eax, dword ptr [esi + 4]
// 006fd68d  8b4804               mov ecx, dword ptr [eax + 4]
// 006fd690  51                   push ecx
// 006fd691  8bcf                 mov ecx, edi
// 006fd693  e898f4ffff           call 0x6fcb30
// 006fd698  eb7b                 jmp 0x6fd715
// 006fd69a  8b12                 mov edx, dword ptr [edx]
// 006fd69c  807a3400             cmp byte ptr [edx + 0x34], 0
// 006fd6a0  7516                 jne 0x6fd6b8
// 006fd6a2  885934               mov byte ptr [ecx + 0x34], bl
// 006fd6a5  885a34               mov byte ptr [edx + 0x34], bl
// 006fd6a8  8b10                 mov edx, dword ptr [eax]
// 006fd6aa  8b4a04               mov ecx, dword ptr [edx + 4]
// 006fd6ad  c6413400             mov byte ptr [ecx + 0x34], 0
// 006fd6b1  8b10                 mov edx, dword ptr [eax]
// 006fd6b3  8b7204               mov esi, dword ptr [edx + 4]
// 006fd6b6  eb5d                 jmp 0x6fd715
// 006fd6b8  3b31                 cmp esi, dword ptr [ecx]
// 006fd6ba  750a                 jne 0x6fd6c6
// 006fd6bc  8bf1                 mov esi, ecx
// 006fd6be  56                   push esi
// 006fd6bf  8bcf                 mov ecx, edi
// 006fd6c1  e86af4ffff           call 0x6fcb30
// 006fd6c6  8b4604               mov eax, dword ptr [esi + 4]
// 006fd6c9  885834               mov byte ptr [eax + 0x34], bl
// 006fd6cc  8b4e04               mov ecx, dword ptr [esi + 4]
// 006fd6cf  8b5104               mov edx, dword ptr [ecx + 4]
// 006fd6d2  c6423400             mov byte ptr [edx + 0x34], 0
// 006fd6d6  8b4604               mov eax, dword ptr [esi + 4]
// 006fd6d9  8b4004               mov eax, dword ptr [eax + 4]
// 006fd6dc  8b4808               mov ecx, dword ptr [eax + 8]
// 006fd6df  8b11                 mov edx, dword ptr [ecx]
// 006fd6e1  895008               mov dword ptr [eax + 8], edx
// 006fd6e4  8b11                 mov edx, dword ptr [ecx]
// 006fd6e6  807a3500             cmp byte ptr [edx + 0x35], 0
// 006fd6ea  7503                 jne 0x6fd6ef
// 006fd6ec  894204               mov dword ptr [edx + 4], eax
// 006fd6ef  8b5004               mov edx, dword ptr [eax + 4]
// 006fd6f2  895104               mov dword ptr [ecx + 4], edx
// 006fd6f5  8b5718               mov edx, dword ptr [edi + 0x18]
// 006fd6f8  3b4204               cmp eax, dword ptr [edx + 4]
// 006fd6fb  7505                 jne 0x6fd702
// 006fd6fd  894a04               mov dword ptr [edx + 4], ecx
// 006fd700  eb0e                 jmp 0x6fd710
// 006fd702  8b5004               mov edx, dword ptr [eax + 4]
// 006fd705  3b02                 cmp eax, dword ptr [edx]
// 006fd707  7504                 jne 0x6fd70d
// 006fd709  890a                 mov dword ptr [edx], ecx
// 006fd70b  eb03                 jmp 0x6fd710
// 006fd70d  894a08               mov dword ptr [edx + 8], ecx
// 006fd710  8901                 mov dword ptr [ecx], eax
// 006fd712  894804               mov dword ptr [eax + 4], ecx
// 006fd715  8b4e04               mov ecx, dword ptr [esi + 4]
// 006fd718  80793400             cmp byte ptr [ecx + 0x34], 0
// 006fd71c  8d4604               lea eax, [esi + 4]
// 006fd71f  0f841bffffff         je 0x6fd640
// 006fd725  8b5718               mov edx, dword ptr [edi + 0x18]
// 006fd728  8b4204               mov eax, dword ptr [edx + 4]
// 006fd72b  885834               mov byte ptr [eax + 0x34], bl
// 006fd72e  8b442464             mov eax, dword ptr [esp + 0x64]
// 006fd732  8b0f                 mov ecx, dword ptr [edi]
// 006fd734  5e                   pop esi
// 006fd735  896804               mov dword ptr [eax + 4], ebp
// 006fd738  5d                   pop ebp
// 006fd739  8908                 mov dword ptr [eax], ecx
// 006fd73b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 006fd73f  5b                   pop ebx
// 006fd740  5f                   pop edi
// 006fd741  64890d00000000       mov dword ptr fs:[0], ecx
// 006fd748  83c450               add esp, 0x50
// 006fd74b  c21000               ret 0x10
// standard library map_int<pod36> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod36>
struct E { int v[9]; };
#include <map>
template class std::map<int, E>;
