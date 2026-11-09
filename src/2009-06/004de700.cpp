// from server: 100% by auto
// roc 2009-06 004de700  unit: RBX::Network::IdSerializer  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004de700
//
// 004de700  64a100000000         mov eax, dword ptr fs:[0]
// 004de706  6aff                 push -1
// 004de708  68b2db8500           push 0x85dbb2
// 004de70d  50                   push eax
// 004de70e  64892500000000       mov dword ptr fs:[0], esp
// 004de715  83ec44               sub esp, 0x44
// 004de718  57                   push edi
// 004de719  8bf9                 mov edi, ecx
// 004de71b  817f1cfeffff07       cmp dword ptr [edi + 0x1c], 0x7fffffe
// 004de722  7259                 jb 0x4de77d
// 004de724  68c0c98a00           push 0x8ac9c0
// 004de729  8d4c2408             lea ecx, [esp + 8]
// 004de72d  ff15b4e48900         call dword ptr [0x89e4b4]
// 004de733  8d4c2420             lea ecx, [esp + 0x20]
// 004de737  c744245000000000     mov dword ptr [esp + 0x50], 0
// 004de73f  ff15b8e98900         call dword ptr [0x89e9b8]
// 004de745  8d442404             lea eax, [esp + 4]
// 004de749  50                   push eax
// 004de74a  8d4c2430             lea ecx, [esp + 0x30]
// 004de74e  c644245401           mov byte ptr [esp + 0x54], 1
// 004de753  c744242444c98a00     mov dword ptr [esp + 0x24], 0x8ac944
// 004de75b  ff15b8e48900         call dword ptr [0x89e4b8]
// 004de761  6834929700           push 0x979234
// 004de766  8d4c2424             lea ecx, [esp + 0x24]
// 004de76a  51                   push ecx
// 004de76b  c644245800           mov byte ptr [esp + 0x58], 0
// 004de770  c744242850c98a00     mov dword ptr [esp + 0x28], 0x8ac950
// 004de778  e8cdb22300           call 0x719a4a
// 004de77d  8b542464             mov edx, dword ptr [esp + 0x64]
// 004de781  8b4718               mov eax, dword ptr [edi + 0x18]
// 004de784  53                   push ebx
// 004de785  55                   push ebp
// 004de786  56                   push esi
// 004de787  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 004de78b  6a00                 push 0
// 004de78d  52                   push edx
// 004de78e  50                   push eax
// 004de78f  56                   push esi
// 004de790  50                   push eax
// 004de791  e82afaffff           call 0x4de1c0
// 004de796  8be8                 mov ebp, eax
// 004de798  8b4718               mov eax, dword ptr [edi + 0x18]
// 004de79b  bb01000000           mov ebx, 1
// 004de7a0  015f1c               add dword ptr [edi + 0x1c], ebx
// 004de7a3  3bf0                 cmp esi, eax
// 004de7a5  7510                 jne 0x4de7b7
// 004de7a7  896804               mov dword ptr [eax + 4], ebp
// 004de7aa  8b4718               mov eax, dword ptr [edi + 0x18]
// 004de7ad  8928                 mov dword ptr [eax], ebp
// 004de7af  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 004de7b2  896908               mov dword ptr [ecx + 8], ebp
// 004de7b5  eb22                 jmp 0x4de7d9
// 004de7b7  807c246800           cmp byte ptr [esp + 0x68], 0
// 004de7bc  740d                 je 0x4de7cb
// 004de7be  892e                 mov dword ptr [esi], ebp
// 004de7c0  8b4718               mov eax, dword ptr [edi + 0x18]
// 004de7c3  3b30                 cmp esi, dword ptr [eax]
// 004de7c5  7512                 jne 0x4de7d9
// 004de7c7  8928                 mov dword ptr [eax], ebp
// 004de7c9  eb0e                 jmp 0x4de7d9
// 004de7cb  896e08               mov dword ptr [esi + 8], ebp
// 004de7ce  8b4718               mov eax, dword ptr [edi + 0x18]
// 004de7d1  3b7008               cmp esi, dword ptr [eax + 8]
// 004de7d4  7503                 jne 0x4de7d9
// 004de7d6  896808               mov dword ptr [eax + 8], ebp
// 004de7d9  8b5504               mov edx, dword ptr [ebp + 4]
// 004de7dc  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 004de7e0  8d4504               lea eax, [ebp + 4]
// 004de7e3  8bf5                 mov esi, ebp
// 004de7e5  0f85ea000000         jne 0x4de8d5
// 004de7eb  eb03                 jmp 0x4de7f0
// 004de7ed  8d4900               lea ecx, [ecx]
// 004de7f0  8b08                 mov ecx, dword ptr [eax]
// 004de7f2  8b5104               mov edx, dword ptr [ecx + 4]
// 004de7f5  3b0a                 cmp ecx, dword ptr [edx]
// 004de7f7  7551                 jne 0x4de84a
// 004de7f9  8b5208               mov edx, dword ptr [edx + 8]
// 004de7fc  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 004de800  7519                 jne 0x4de81b
// 004de802  88592c               mov byte ptr [ecx + 0x2c], bl
// 004de805  885a2c               mov byte ptr [edx + 0x2c], bl
// 004de808  8b10                 mov edx, dword ptr [eax]
// 004de80a  8b4a04               mov ecx, dword ptr [edx + 4]
// 004de80d  c6412c00             mov byte ptr [ecx + 0x2c], 0
// 004de811  8b10                 mov edx, dword ptr [eax]
// 004de813  8b7204               mov esi, dword ptr [edx + 4]
// 004de816  e9aa000000           jmp 0x4de8c5
// 004de81b  3b7108               cmp esi, dword ptr [ecx + 8]
// 004de81e  750a                 jne 0x4de82a
// 004de820  8bf1                 mov esi, ecx
// 004de822  56                   push esi
// 004de823  8bcf                 mov ecx, edi
// 004de825  e856021600           call 0x63ea80
// 004de82a  8b4604               mov eax, dword ptr [esi + 4]
// 004de82d  88582c               mov byte ptr [eax + 0x2c], bl
// 004de830  8b4e04               mov ecx, dword ptr [esi + 4]
// 004de833  8b5104               mov edx, dword ptr [ecx + 4]
// 004de836  c6422c00             mov byte ptr [edx + 0x2c], 0
// 004de83a  8b4604               mov eax, dword ptr [esi + 4]
// 004de83d  8b4804               mov ecx, dword ptr [eax + 4]
// 004de840  51                   push ecx
// 004de841  8bcf                 mov ecx, edi
// 004de843  e8b8e1ffff           call 0x4dca00
// 004de848  eb7b                 jmp 0x4de8c5
// 004de84a  8b12                 mov edx, dword ptr [edx]
// 004de84c  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 004de850  7516                 jne 0x4de868
// 004de852  88592c               mov byte ptr [ecx + 0x2c], bl
// 004de855  885a2c               mov byte ptr [edx + 0x2c], bl
// 004de858  8b10                 mov edx, dword ptr [eax]
// 004de85a  8b4a04               mov ecx, dword ptr [edx + 4]
// 004de85d  c6412c00             mov byte ptr [ecx + 0x2c], 0
// 004de861  8b10                 mov edx, dword ptr [eax]
// 004de863  8b7204               mov esi, dword ptr [edx + 4]
// 004de866  eb5d                 jmp 0x4de8c5
// 004de868  3b31                 cmp esi, dword ptr [ecx]
// 004de86a  750a                 jne 0x4de876
// 004de86c  8bf1                 mov esi, ecx
// 004de86e  56                   push esi
// 004de86f  8bcf                 mov ecx, edi
// 004de871  e88ae1ffff           call 0x4dca00
// 004de876  8b4604               mov eax, dword ptr [esi + 4]
// 004de879  88582c               mov byte ptr [eax + 0x2c], bl
// 004de87c  8b4e04               mov ecx, dword ptr [esi + 4]
// 004de87f  8b5104               mov edx, dword ptr [ecx + 4]
// 004de882  c6422c00             mov byte ptr [edx + 0x2c], 0
// 004de886  8b4604               mov eax, dword ptr [esi + 4]
// 004de889  8b4004               mov eax, dword ptr [eax + 4]
// 004de88c  8b4808               mov ecx, dword ptr [eax + 8]
// 004de88f  8b11                 mov edx, dword ptr [ecx]
// 004de891  895008               mov dword ptr [eax + 8], edx
// 004de894  8b11                 mov edx, dword ptr [ecx]
// 004de896  807a2d00             cmp byte ptr [edx + 0x2d], 0
// 004de89a  7503                 jne 0x4de89f
// 004de89c  894204               mov dword ptr [edx + 4], eax
// 004de89f  8b5004               mov edx, dword ptr [eax + 4]
// 004de8a2  895104               mov dword ptr [ecx + 4], edx
// 004de8a5  8b5718               mov edx, dword ptr [edi + 0x18]
// 004de8a8  3b4204               cmp eax, dword ptr [edx + 4]
// 004de8ab  7505                 jne 0x4de8b2
// 004de8ad  894a04               mov dword ptr [edx + 4], ecx
// 004de8b0  eb0e                 jmp 0x4de8c0
// 004de8b2  8b5004               mov edx, dword ptr [eax + 4]
// 004de8b5  3b02                 cmp eax, dword ptr [edx]
// 004de8b7  7504                 jne 0x4de8bd
// 004de8b9  890a                 mov dword ptr [edx], ecx
// 004de8bb  eb03                 jmp 0x4de8c0
// 004de8bd  894a08               mov dword ptr [edx + 8], ecx
// 004de8c0  8901                 mov dword ptr [ecx], eax
// 004de8c2  894804               mov dword ptr [eax + 4], ecx
// 004de8c5  8b4e04               mov ecx, dword ptr [esi + 4]
// 004de8c8  80792c00             cmp byte ptr [ecx + 0x2c], 0
// 004de8cc  8d4604               lea eax, [esi + 4]
// 004de8cf  0f841bffffff         je 0x4de7f0
// 004de8d5  8b5718               mov edx, dword ptr [edi + 0x18]
// 004de8d8  8b4204               mov eax, dword ptr [edx + 4]
// 004de8db  88582c               mov byte ptr [eax + 0x2c], bl
// 004de8de  8b442464             mov eax, dword ptr [esp + 0x64]
// 004de8e2  8b0f                 mov ecx, dword ptr [edi]
// 004de8e4  5e                   pop esi
// 004de8e5  896804               mov dword ptr [eax + 4], ebp
// 004de8e8  5d                   pop ebp
// 004de8e9  8908                 mov dword ptr [eax], ecx
// 004de8eb  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 004de8ef  5b                   pop ebx
// 004de8f0  5f                   pop edi
// 004de8f1  64890d00000000       mov dword ptr fs:[0], ecx
// 004de8f8  83c450               add esp, 0x50
// 004de8fb  c21000               ret 0x10
// standard library map_int<string> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@2@ABU?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@Z)

// stl: map_int<string>
#include <string>
typedef std::string E;
#include <map>
template class std::map<int, E>;
