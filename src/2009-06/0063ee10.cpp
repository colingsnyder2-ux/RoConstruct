// from server: 100% by auto
// roc 2009-06 0063ee10  unit: RBX::Accoutrement  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0063ee10
//
// 0063ee10  64a100000000         mov eax, dword ptr fs:[0]
// 0063ee16  6aff                 push -1
// 0063ee18  68b2db8500           push 0x85dbb2
// 0063ee1d  50                   push eax
// 0063ee1e  64892500000000       mov dword ptr fs:[0], esp
// 0063ee25  83ec44               sub esp, 0x44
// 0063ee28  57                   push edi
// 0063ee29  8bf9                 mov edi, ecx
// 0063ee2b  817f1cfeffff07       cmp dword ptr [edi + 0x1c], 0x7fffffe
// 0063ee32  7259                 jb 0x63ee8d
// 0063ee34  68c0c98a00           push 0x8ac9c0
// 0063ee39  8d4c2408             lea ecx, [esp + 8]
// 0063ee3d  ff15b4e48900         call dword ptr [0x89e4b4]
// 0063ee43  8d4c2420             lea ecx, [esp + 0x20]
// 0063ee47  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0063ee4f  ff15b8e98900         call dword ptr [0x89e9b8]
// 0063ee55  8d442404             lea eax, [esp + 4]
// 0063ee59  50                   push eax
// 0063ee5a  8d4c2430             lea ecx, [esp + 0x30]
// 0063ee5e  c644245401           mov byte ptr [esp + 0x54], 1
// 0063ee63  c744242444c98a00     mov dword ptr [esp + 0x24], 0x8ac944
// 0063ee6b  ff15b8e48900         call dword ptr [0x89e4b8]
// 0063ee71  6834929700           push 0x979234
// 0063ee76  8d4c2424             lea ecx, [esp + 0x24]
// 0063ee7a  51                   push ecx
// 0063ee7b  c644245800           mov byte ptr [esp + 0x58], 0
// 0063ee80  c744242850c98a00     mov dword ptr [esp + 0x28], 0x8ac950
// 0063ee88  e8bdab0d00           call 0x719a4a
// 0063ee8d  8b542464             mov edx, dword ptr [esp + 0x64]
// 0063ee91  8b4718               mov eax, dword ptr [edi + 0x18]
// 0063ee94  53                   push ebx
// 0063ee95  55                   push ebp
// 0063ee96  56                   push esi
// 0063ee97  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0063ee9b  6a00                 push 0
// 0063ee9d  52                   push edx
// 0063ee9e  50                   push eax
// 0063ee9f  56                   push esi
// 0063eea0  50                   push eax
// 0063eea1  e88afcffff           call 0x63eb30
// 0063eea6  8be8                 mov ebp, eax
// 0063eea8  8b4718               mov eax, dword ptr [edi + 0x18]
// 0063eeab  bb01000000           mov ebx, 1
// 0063eeb0  015f1c               add dword ptr [edi + 0x1c], ebx
// 0063eeb3  3bf0                 cmp esi, eax
// 0063eeb5  7510                 jne 0x63eec7
// 0063eeb7  896804               mov dword ptr [eax + 4], ebp
// 0063eeba  8b4718               mov eax, dword ptr [edi + 0x18]
// 0063eebd  8928                 mov dword ptr [eax], ebp
// 0063eebf  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 0063eec2  896908               mov dword ptr [ecx + 8], ebp
// 0063eec5  eb22                 jmp 0x63eee9
// 0063eec7  807c246800           cmp byte ptr [esp + 0x68], 0
// 0063eecc  740d                 je 0x63eedb
// 0063eece  892e                 mov dword ptr [esi], ebp
// 0063eed0  8b4718               mov eax, dword ptr [edi + 0x18]
// 0063eed3  3b30                 cmp esi, dword ptr [eax]
// 0063eed5  7512                 jne 0x63eee9
// 0063eed7  8928                 mov dword ptr [eax], ebp
// 0063eed9  eb0e                 jmp 0x63eee9
// 0063eedb  896e08               mov dword ptr [esi + 8], ebp
// 0063eede  8b4718               mov eax, dword ptr [edi + 0x18]
// 0063eee1  3b7008               cmp esi, dword ptr [eax + 8]
// 0063eee4  7503                 jne 0x63eee9
// 0063eee6  896808               mov dword ptr [eax + 8], ebp
// 0063eee9  8b5504               mov edx, dword ptr [ebp + 4]
// 0063eeec  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 0063eef0  8d4504               lea eax, [ebp + 4]
// 0063eef3  8bf5                 mov esi, ebp
// 0063eef5  0f85ea000000         jne 0x63efe5
// 0063eefb  eb03                 jmp 0x63ef00
// 0063eefd  8d4900               lea ecx, [ecx]
// 0063ef00  8b08                 mov ecx, dword ptr [eax]
// 0063ef02  8b5104               mov edx, dword ptr [ecx + 4]
// 0063ef05  3b0a                 cmp ecx, dword ptr [edx]
// 0063ef07  7551                 jne 0x63ef5a
// 0063ef09  8b5208               mov edx, dword ptr [edx + 8]
// 0063ef0c  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 0063ef10  7519                 jne 0x63ef2b
// 0063ef12  88592c               mov byte ptr [ecx + 0x2c], bl
// 0063ef15  885a2c               mov byte ptr [edx + 0x2c], bl
// 0063ef18  8b10                 mov edx, dword ptr [eax]
// 0063ef1a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0063ef1d  c6412c00             mov byte ptr [ecx + 0x2c], 0
// 0063ef21  8b10                 mov edx, dword ptr [eax]
// 0063ef23  8b7204               mov esi, dword ptr [edx + 4]
// 0063ef26  e9aa000000           jmp 0x63efd5
// 0063ef2b  3b7108               cmp esi, dword ptr [ecx + 8]
// 0063ef2e  750a                 jne 0x63ef3a
// 0063ef30  8bf1                 mov esi, ecx
// 0063ef32  56                   push esi
// 0063ef33  8bcf                 mov ecx, edi
// 0063ef35  e846fbffff           call 0x63ea80
// 0063ef3a  8b4604               mov eax, dword ptr [esi + 4]
// 0063ef3d  88582c               mov byte ptr [eax + 0x2c], bl
// 0063ef40  8b4e04               mov ecx, dword ptr [esi + 4]
// 0063ef43  8b5104               mov edx, dword ptr [ecx + 4]
// 0063ef46  c6422c00             mov byte ptr [edx + 0x2c], 0
// 0063ef4a  8b4604               mov eax, dword ptr [esi + 4]
// 0063ef4d  8b4804               mov ecx, dword ptr [eax + 4]
// 0063ef50  51                   push ecx
// 0063ef51  8bcf                 mov ecx, edi
// 0063ef53  e8a8dae9ff           call 0x4dca00
// 0063ef58  eb7b                 jmp 0x63efd5
// 0063ef5a  8b12                 mov edx, dword ptr [edx]
// 0063ef5c  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 0063ef60  7516                 jne 0x63ef78
// 0063ef62  88592c               mov byte ptr [ecx + 0x2c], bl
// 0063ef65  885a2c               mov byte ptr [edx + 0x2c], bl
// 0063ef68  8b10                 mov edx, dword ptr [eax]
// 0063ef6a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0063ef6d  c6412c00             mov byte ptr [ecx + 0x2c], 0
// 0063ef71  8b10                 mov edx, dword ptr [eax]
// 0063ef73  8b7204               mov esi, dword ptr [edx + 4]
// 0063ef76  eb5d                 jmp 0x63efd5
// 0063ef78  3b31                 cmp esi, dword ptr [ecx]
// 0063ef7a  750a                 jne 0x63ef86
// 0063ef7c  8bf1                 mov esi, ecx
// 0063ef7e  56                   push esi
// 0063ef7f  8bcf                 mov ecx, edi
// 0063ef81  e87adae9ff           call 0x4dca00
// 0063ef86  8b4604               mov eax, dword ptr [esi + 4]
// 0063ef89  88582c               mov byte ptr [eax + 0x2c], bl
// 0063ef8c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0063ef8f  8b5104               mov edx, dword ptr [ecx + 4]
// 0063ef92  c6422c00             mov byte ptr [edx + 0x2c], 0
// 0063ef96  8b4604               mov eax, dword ptr [esi + 4]
// 0063ef99  8b4004               mov eax, dword ptr [eax + 4]
// 0063ef9c  8b4808               mov ecx, dword ptr [eax + 8]
// 0063ef9f  8b11                 mov edx, dword ptr [ecx]
// 0063efa1  895008               mov dword ptr [eax + 8], edx
// 0063efa4  8b11                 mov edx, dword ptr [ecx]
// 0063efa6  807a2d00             cmp byte ptr [edx + 0x2d], 0
// 0063efaa  7503                 jne 0x63efaf
// 0063efac  894204               mov dword ptr [edx + 4], eax
// 0063efaf  8b5004               mov edx, dword ptr [eax + 4]
// 0063efb2  895104               mov dword ptr [ecx + 4], edx
// 0063efb5  8b5718               mov edx, dword ptr [edi + 0x18]
// 0063efb8  3b4204               cmp eax, dword ptr [edx + 4]
// 0063efbb  7505                 jne 0x63efc2
// 0063efbd  894a04               mov dword ptr [edx + 4], ecx
// 0063efc0  eb0e                 jmp 0x63efd0
// 0063efc2  8b5004               mov edx, dword ptr [eax + 4]
// 0063efc5  3b02                 cmp eax, dword ptr [edx]
// 0063efc7  7504                 jne 0x63efcd
// 0063efc9  890a                 mov dword ptr [edx], ecx
// 0063efcb  eb03                 jmp 0x63efd0
// 0063efcd  894a08               mov dword ptr [edx + 8], ecx
// 0063efd0  8901                 mov dword ptr [ecx], eax
// 0063efd2  894804               mov dword ptr [eax + 4], ecx
// 0063efd5  8b4e04               mov ecx, dword ptr [esi + 4]
// 0063efd8  80792c00             cmp byte ptr [ecx + 0x2c], 0
// 0063efdc  8d4604               lea eax, [esi + 4]
// 0063efdf  0f841bffffff         je 0x63ef00
// 0063efe5  8b5718               mov edx, dword ptr [edi + 0x18]
// 0063efe8  8b4204               mov eax, dword ptr [edx + 4]
// 0063efeb  88582c               mov byte ptr [eax + 0x2c], bl
// 0063efee  8b442464             mov eax, dword ptr [esp + 0x64]
// 0063eff2  8b0f                 mov ecx, dword ptr [edi]
// 0063eff4  5e                   pop esi
// 0063eff5  896804               mov dword ptr [eax + 4], ebp
// 0063eff8  5d                   pop ebp
// 0063eff9  8908                 mov dword ptr [eax], ecx
// 0063effb  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0063efff  5b                   pop ebx
// 0063f000  5f                   pop edi
// 0063f001  64890d00000000       mov dword ptr fs:[0], ecx
// 0063f008  83c450               add esp, 0x50
// 0063f00b  c21000               ret 0x10
// standard library map_int<string> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@2@ABU?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@Z)

// stl: map_int<string>
#include <string>
typedef std::string E;
#include <map>
template class std::map<int, E>;
