// from server: 100% by auto
// roc 2008-06 004a7720  unit: RBX::VHint::?$FactoryProduct::Creator  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004a7720
//
// 004a7720  64a100000000         mov eax, dword ptr fs:[0]
// 004a7726  6aff                 push -1
// 004a7728  6842e87d00           push 0x7de842
// 004a772d  50                   push eax
// 004a772e  64892500000000       mov dword ptr fs:[0], esp
// 004a7735  83ec44               sub esp, 0x44
// 004a7738  57                   push edi
// 004a7739  8bf9                 mov edi, ecx
// 004a773b  817f1cfeffff07       cmp dword ptr [edi + 0x1c], 0x7fffffe
// 004a7742  7259                 jb 0x4a779d
// 004a7744  688cb28000           push 0x80b28c
// 004a7749  8d4c2408             lea ecx, [esp + 8]
// 004a774d  ff1558248000         call dword ptr [0x802458]
// 004a7753  8d4c2420             lea ecx, [esp + 0x20]
// 004a7757  c744245000000000     mov dword ptr [esp + 0x50], 0
// 004a775f  ff1598288000         call dword ptr [0x802898]
// 004a7765  8d442404             lea eax, [esp + 4]
// 004a7769  50                   push eax
// 004a776a  8d4c2430             lea ecx, [esp + 0x30]
// 004a776e  c644245401           mov byte ptr [esp + 0x54], 1
// 004a7773  c744242410b18000     mov dword ptr [esp + 0x24], 0x80b110
// 004a777b  ff155c248000         call dword ptr [0x80245c]
// 004a7781  68c00c8d00           push 0x8d0cc0
// 004a7786  8d4c2424             lea ecx, [esp + 0x24]
// 004a778a  51                   push ecx
// 004a778b  c644245800           mov byte ptr [esp + 0x58], 0
// 004a7790  c74424281cb18000     mov dword ptr [esp + 0x28], 0x80b11c
// 004a7798  e8ef9d1f00           call 0x6a158c
// 004a779d  8b542464             mov edx, dword ptr [esp + 0x64]
// 004a77a1  8b4718               mov eax, dword ptr [edi + 0x18]
// 004a77a4  53                   push ebx
// 004a77a5  55                   push ebp
// 004a77a6  56                   push esi
// 004a77a7  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 004a77ab  6a00                 push 0
// 004a77ad  52                   push edx
// 004a77ae  50                   push eax
// 004a77af  56                   push esi
// 004a77b0  50                   push eax
// 004a77b1  e82afaffff           call 0x4a71e0
// 004a77b6  8be8                 mov ebp, eax
// 004a77b8  8b4718               mov eax, dword ptr [edi + 0x18]
// 004a77bb  bb01000000           mov ebx, 1
// 004a77c0  015f1c               add dword ptr [edi + 0x1c], ebx
// 004a77c3  3bf0                 cmp esi, eax
// 004a77c5  7510                 jne 0x4a77d7
// 004a77c7  896804               mov dword ptr [eax + 4], ebp
// 004a77ca  8b4718               mov eax, dword ptr [edi + 0x18]
// 004a77cd  8928                 mov dword ptr [eax], ebp
// 004a77cf  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 004a77d2  896908               mov dword ptr [ecx + 8], ebp
// 004a77d5  eb22                 jmp 0x4a77f9
// 004a77d7  807c246800           cmp byte ptr [esp + 0x68], 0
// 004a77dc  740d                 je 0x4a77eb
// 004a77de  892e                 mov dword ptr [esi], ebp
// 004a77e0  8b4718               mov eax, dword ptr [edi + 0x18]
// 004a77e3  3b30                 cmp esi, dword ptr [eax]
// 004a77e5  7512                 jne 0x4a77f9
// 004a77e7  8928                 mov dword ptr [eax], ebp
// 004a77e9  eb0e                 jmp 0x4a77f9
// 004a77eb  896e08               mov dword ptr [esi + 8], ebp
// 004a77ee  8b4718               mov eax, dword ptr [edi + 0x18]
// 004a77f1  3b7008               cmp esi, dword ptr [eax + 8]
// 004a77f4  7503                 jne 0x4a77f9
// 004a77f6  896808               mov dword ptr [eax + 8], ebp
// 004a77f9  8b5504               mov edx, dword ptr [ebp + 4]
// 004a77fc  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 004a7800  8d4504               lea eax, [ebp + 4]
// 004a7803  8bf5                 mov esi, ebp
// 004a7805  0f85ea000000         jne 0x4a78f5
// 004a780b  eb03                 jmp 0x4a7810
// 004a780d  8d4900               lea ecx, [ecx]
// 004a7810  8b08                 mov ecx, dword ptr [eax]
// 004a7812  8b5104               mov edx, dword ptr [ecx + 4]
// 004a7815  3b0a                 cmp ecx, dword ptr [edx]
// 004a7817  7551                 jne 0x4a786a
// 004a7819  8b5208               mov edx, dword ptr [edx + 8]
// 004a781c  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 004a7820  7519                 jne 0x4a783b
// 004a7822  88592c               mov byte ptr [ecx + 0x2c], bl
// 004a7825  885a2c               mov byte ptr [edx + 0x2c], bl
// 004a7828  8b10                 mov edx, dword ptr [eax]
// 004a782a  8b4a04               mov ecx, dword ptr [edx + 4]
// 004a782d  c6412c00             mov byte ptr [ecx + 0x2c], 0
// 004a7831  8b10                 mov edx, dword ptr [eax]
// 004a7833  8b7204               mov esi, dword ptr [edx + 4]
// 004a7836  e9aa000000           jmp 0x4a78e5
// 004a783b  3b7108               cmp esi, dword ptr [ecx + 8]
// 004a783e  750a                 jne 0x4a784a
// 004a7840  8bf1                 mov esi, ecx
// 004a7842  56                   push esi
// 004a7843  8bcf                 mov ecx, edi
// 004a7845  e8b6661e00           call 0x68df00
// 004a784a  8b4604               mov eax, dword ptr [esi + 4]
// 004a784d  88582c               mov byte ptr [eax + 0x2c], bl
// 004a7850  8b4e04               mov ecx, dword ptr [esi + 4]
// 004a7853  8b5104               mov edx, dword ptr [ecx + 4]
// 004a7856  c6422c00             mov byte ptr [edx + 0x2c], 0
// 004a785a  8b4604               mov eax, dword ptr [esi + 4]
// 004a785d  8b4804               mov ecx, dword ptr [eax + 4]
// 004a7860  51                   push ecx
// 004a7861  8bcf                 mov ecx, edi
// 004a7863  e868571e00           call 0x68cfd0
// 004a7868  eb7b                 jmp 0x4a78e5
// 004a786a  8b12                 mov edx, dword ptr [edx]
// 004a786c  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 004a7870  7516                 jne 0x4a7888
// 004a7872  88592c               mov byte ptr [ecx + 0x2c], bl
// 004a7875  885a2c               mov byte ptr [edx + 0x2c], bl
// 004a7878  8b10                 mov edx, dword ptr [eax]
// 004a787a  8b4a04               mov ecx, dword ptr [edx + 4]
// 004a787d  c6412c00             mov byte ptr [ecx + 0x2c], 0
// 004a7881  8b10                 mov edx, dword ptr [eax]
// 004a7883  8b7204               mov esi, dword ptr [edx + 4]
// 004a7886  eb5d                 jmp 0x4a78e5
// 004a7888  3b31                 cmp esi, dword ptr [ecx]
// 004a788a  750a                 jne 0x4a7896
// 004a788c  8bf1                 mov esi, ecx
// 004a788e  56                   push esi
// 004a788f  8bcf                 mov ecx, edi
// 004a7891  e83a571e00           call 0x68cfd0
// 004a7896  8b4604               mov eax, dword ptr [esi + 4]
// 004a7899  88582c               mov byte ptr [eax + 0x2c], bl
// 004a789c  8b4e04               mov ecx, dword ptr [esi + 4]
// 004a789f  8b5104               mov edx, dword ptr [ecx + 4]
// 004a78a2  c6422c00             mov byte ptr [edx + 0x2c], 0
// 004a78a6  8b4604               mov eax, dword ptr [esi + 4]
// 004a78a9  8b4004               mov eax, dword ptr [eax + 4]
// 004a78ac  8b4808               mov ecx, dword ptr [eax + 8]
// 004a78af  8b11                 mov edx, dword ptr [ecx]
// 004a78b1  895008               mov dword ptr [eax + 8], edx
// 004a78b4  8b11                 mov edx, dword ptr [ecx]
// 004a78b6  807a2d00             cmp byte ptr [edx + 0x2d], 0
// 004a78ba  7503                 jne 0x4a78bf
// 004a78bc  894204               mov dword ptr [edx + 4], eax
// 004a78bf  8b5004               mov edx, dword ptr [eax + 4]
// 004a78c2  895104               mov dword ptr [ecx + 4], edx
// 004a78c5  8b5718               mov edx, dword ptr [edi + 0x18]
// 004a78c8  3b4204               cmp eax, dword ptr [edx + 4]
// 004a78cb  7505                 jne 0x4a78d2
// 004a78cd  894a04               mov dword ptr [edx + 4], ecx
// 004a78d0  eb0e                 jmp 0x4a78e0
// 004a78d2  8b5004               mov edx, dword ptr [eax + 4]
// 004a78d5  3b02                 cmp eax, dword ptr [edx]
// 004a78d7  7504                 jne 0x4a78dd
// 004a78d9  890a                 mov dword ptr [edx], ecx
// 004a78db  eb03                 jmp 0x4a78e0
// 004a78dd  894a08               mov dword ptr [edx + 8], ecx
// 004a78e0  8901                 mov dword ptr [ecx], eax
// 004a78e2  894804               mov dword ptr [eax + 4], ecx
// 004a78e5  8b4e04               mov ecx, dword ptr [esi + 4]
// 004a78e8  80792c00             cmp byte ptr [ecx + 0x2c], 0
// 004a78ec  8d4604               lea eax, [esi + 4]
// 004a78ef  0f841bffffff         je 0x4a7810
// 004a78f5  8b5718               mov edx, dword ptr [edi + 0x18]
// 004a78f8  8b4204               mov eax, dword ptr [edx + 4]
// 004a78fb  88582c               mov byte ptr [eax + 0x2c], bl
// 004a78fe  8b442464             mov eax, dword ptr [esp + 0x64]
// 004a7902  8b0f                 mov ecx, dword ptr [edi]
// 004a7904  5e                   pop esi
// 004a7905  896804               mov dword ptr [eax + 4], ebp
// 004a7908  5d                   pop ebp
// 004a7909  8908                 mov dword ptr [eax], ecx
// 004a790b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 004a790f  5b                   pop ebx
// 004a7910  5f                   pop edi
// 004a7911  64890d00000000       mov dword ptr fs:[0], ecx
// 004a7918  83c450               add esp, 0x50
// 004a791b  c21000               ret 0x10
// standard library map_int<string> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@2@ABU?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@Z)

// stl: map_int<string>
#include <string>
typedef std::string E;
#include <map>
template class std::map<int, E>;
