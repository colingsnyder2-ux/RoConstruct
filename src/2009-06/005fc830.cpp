// from server: 100% by auto
// roc 2009-06 005fc830  unit: RBX::VInstance::$$A6AXV?$shared_ptr::?$signal::Vslot::?$sp_counted_impl_p  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005fc830
//
// 005fc830  64a100000000         mov eax, dword ptr fs:[0]
// 005fc836  6aff                 push -1
// 005fc838  68b2db8500           push 0x85dbb2
// 005fc83d  50                   push eax
// 005fc83e  64892500000000       mov dword ptr fs:[0], esp
// 005fc845  83ec44               sub esp, 0x44
// 005fc848  57                   push edi
// 005fc849  8bf9                 mov edi, ecx
// 005fc84b  817f1cfeffff07       cmp dword ptr [edi + 0x1c], 0x7fffffe
// 005fc852  7259                 jb 0x5fc8ad
// 005fc854  68c0c98a00           push 0x8ac9c0
// 005fc859  8d4c2408             lea ecx, [esp + 8]
// 005fc85d  ff15b4e48900         call dword ptr [0x89e4b4]
// 005fc863  8d4c2420             lea ecx, [esp + 0x20]
// 005fc867  c744245000000000     mov dword ptr [esp + 0x50], 0
// 005fc86f  ff15b8e98900         call dword ptr [0x89e9b8]
// 005fc875  8d442404             lea eax, [esp + 4]
// 005fc879  50                   push eax
// 005fc87a  8d4c2430             lea ecx, [esp + 0x30]
// 005fc87e  c644245401           mov byte ptr [esp + 0x54], 1
// 005fc883  c744242444c98a00     mov dword ptr [esp + 0x24], 0x8ac944
// 005fc88b  ff15b8e48900         call dword ptr [0x89e4b8]
// 005fc891  6834929700           push 0x979234
// 005fc896  8d4c2424             lea ecx, [esp + 0x24]
// 005fc89a  51                   push ecx
// 005fc89b  c644245800           mov byte ptr [esp + 0x58], 0
// 005fc8a0  c744242850c98a00     mov dword ptr [esp + 0x28], 0x8ac950
// 005fc8a8  e89dd11100           call 0x719a4a
// 005fc8ad  8b542464             mov edx, dword ptr [esp + 0x64]
// 005fc8b1  8b4718               mov eax, dword ptr [edi + 0x18]
// 005fc8b4  53                   push ebx
// 005fc8b5  55                   push ebp
// 005fc8b6  56                   push esi
// 005fc8b7  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 005fc8bb  6a00                 push 0
// 005fc8bd  52                   push edx
// 005fc8be  50                   push eax
// 005fc8bf  56                   push esi
// 005fc8c0  50                   push eax
// 005fc8c1  e84a74e7ff           call 0x473d10
// 005fc8c6  8be8                 mov ebp, eax
// 005fc8c8  8b4718               mov eax, dword ptr [edi + 0x18]
// 005fc8cb  bb01000000           mov ebx, 1
// 005fc8d0  015f1c               add dword ptr [edi + 0x1c], ebx
// 005fc8d3  3bf0                 cmp esi, eax
// 005fc8d5  7510                 jne 0x5fc8e7
// 005fc8d7  896804               mov dword ptr [eax + 4], ebp
// 005fc8da  8b4718               mov eax, dword ptr [edi + 0x18]
// 005fc8dd  8928                 mov dword ptr [eax], ebp
// 005fc8df  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 005fc8e2  896908               mov dword ptr [ecx + 8], ebp
// 005fc8e5  eb22                 jmp 0x5fc909
// 005fc8e7  807c246800           cmp byte ptr [esp + 0x68], 0
// 005fc8ec  740d                 je 0x5fc8fb
// 005fc8ee  892e                 mov dword ptr [esi], ebp
// 005fc8f0  8b4718               mov eax, dword ptr [edi + 0x18]
// 005fc8f3  3b30                 cmp esi, dword ptr [eax]
// 005fc8f5  7512                 jne 0x5fc909
// 005fc8f7  8928                 mov dword ptr [eax], ebp
// 005fc8f9  eb0e                 jmp 0x5fc909
// 005fc8fb  896e08               mov dword ptr [esi + 8], ebp
// 005fc8fe  8b4718               mov eax, dword ptr [edi + 0x18]
// 005fc901  3b7008               cmp esi, dword ptr [eax + 8]
// 005fc904  7503                 jne 0x5fc909
// 005fc906  896808               mov dword ptr [eax + 8], ebp
// 005fc909  8b5504               mov edx, dword ptr [ebp + 4]
// 005fc90c  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 005fc910  8d4504               lea eax, [ebp + 4]
// 005fc913  8bf5                 mov esi, ebp
// 005fc915  0f85ea000000         jne 0x5fca05
// 005fc91b  eb03                 jmp 0x5fc920
// 005fc91d  8d4900               lea ecx, [ecx]
// 005fc920  8b08                 mov ecx, dword ptr [eax]
// 005fc922  8b5104               mov edx, dword ptr [ecx + 4]
// 005fc925  3b0a                 cmp ecx, dword ptr [edx]
// 005fc927  7551                 jne 0x5fc97a
// 005fc929  8b5208               mov edx, dword ptr [edx + 8]
// 005fc92c  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 005fc930  7519                 jne 0x5fc94b
// 005fc932  88592c               mov byte ptr [ecx + 0x2c], bl
// 005fc935  885a2c               mov byte ptr [edx + 0x2c], bl
// 005fc938  8b10                 mov edx, dword ptr [eax]
// 005fc93a  8b4a04               mov ecx, dword ptr [edx + 4]
// 005fc93d  c6412c00             mov byte ptr [ecx + 0x2c], 0
// 005fc941  8b10                 mov edx, dword ptr [eax]
// 005fc943  8b7204               mov esi, dword ptr [edx + 4]
// 005fc946  e9aa000000           jmp 0x5fc9f5
// 005fc94b  3b7108               cmp esi, dword ptr [ecx + 8]
// 005fc94e  750a                 jne 0x5fc95a
// 005fc950  8bf1                 mov esi, ecx
// 005fc952  56                   push esi
// 005fc953  8bcf                 mov ecx, edi
// 005fc955  e86699fbff           call 0x5b62c0
// 005fc95a  8b4604               mov eax, dword ptr [esi + 4]
// 005fc95d  88582c               mov byte ptr [eax + 0x2c], bl
// 005fc960  8b4e04               mov ecx, dword ptr [esi + 4]
// 005fc963  8b5104               mov edx, dword ptr [ecx + 4]
// 005fc966  c6422c00             mov byte ptr [edx + 0x2c], 0
// 005fc96a  8b4604               mov eax, dword ptr [esi + 4]
// 005fc96d  8b4804               mov ecx, dword ptr [eax + 4]
// 005fc970  51                   push ecx
// 005fc971  8bcf                 mov ecx, edi
// 005fc973  e8f89afbff           call 0x5b6470
// 005fc978  eb7b                 jmp 0x5fc9f5
// 005fc97a  8b12                 mov edx, dword ptr [edx]
// 005fc97c  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 005fc980  7516                 jne 0x5fc998
// 005fc982  88592c               mov byte ptr [ecx + 0x2c], bl
// 005fc985  885a2c               mov byte ptr [edx + 0x2c], bl
// 005fc988  8b10                 mov edx, dword ptr [eax]
// 005fc98a  8b4a04               mov ecx, dword ptr [edx + 4]
// 005fc98d  c6412c00             mov byte ptr [ecx + 0x2c], 0
// 005fc991  8b10                 mov edx, dword ptr [eax]
// 005fc993  8b7204               mov esi, dword ptr [edx + 4]
// 005fc996  eb5d                 jmp 0x5fc9f5
// 005fc998  3b31                 cmp esi, dword ptr [ecx]
// 005fc99a  750a                 jne 0x5fc9a6
// 005fc99c  8bf1                 mov esi, ecx
// 005fc99e  56                   push esi
// 005fc99f  8bcf                 mov ecx, edi
// 005fc9a1  e8ca9afbff           call 0x5b6470
// 005fc9a6  8b4604               mov eax, dword ptr [esi + 4]
// 005fc9a9  88582c               mov byte ptr [eax + 0x2c], bl
// 005fc9ac  8b4e04               mov ecx, dword ptr [esi + 4]
// 005fc9af  8b5104               mov edx, dword ptr [ecx + 4]
// 005fc9b2  c6422c00             mov byte ptr [edx + 0x2c], 0
// 005fc9b6  8b4604               mov eax, dword ptr [esi + 4]
// 005fc9b9  8b4004               mov eax, dword ptr [eax + 4]
// 005fc9bc  8b4808               mov ecx, dword ptr [eax + 8]
// 005fc9bf  8b11                 mov edx, dword ptr [ecx]
// 005fc9c1  895008               mov dword ptr [eax + 8], edx
// 005fc9c4  8b11                 mov edx, dword ptr [ecx]
// 005fc9c6  807a2d00             cmp byte ptr [edx + 0x2d], 0
// 005fc9ca  7503                 jne 0x5fc9cf
// 005fc9cc  894204               mov dword ptr [edx + 4], eax
// 005fc9cf  8b5004               mov edx, dword ptr [eax + 4]
// 005fc9d2  895104               mov dword ptr [ecx + 4], edx
// 005fc9d5  8b5718               mov edx, dword ptr [edi + 0x18]
// 005fc9d8  3b4204               cmp eax, dword ptr [edx + 4]
// 005fc9db  7505                 jne 0x5fc9e2
// 005fc9dd  894a04               mov dword ptr [edx + 4], ecx
// 005fc9e0  eb0e                 jmp 0x5fc9f0
// 005fc9e2  8b5004               mov edx, dword ptr [eax + 4]
// 005fc9e5  3b02                 cmp eax, dword ptr [edx]
// 005fc9e7  7504                 jne 0x5fc9ed
// 005fc9e9  890a                 mov dword ptr [edx], ecx
// 005fc9eb  eb03                 jmp 0x5fc9f0
// 005fc9ed  894a08               mov dword ptr [edx + 8], ecx
// 005fc9f0  8901                 mov dword ptr [ecx], eax
// 005fc9f2  894804               mov dword ptr [eax + 4], ecx
// 005fc9f5  8b4e04               mov ecx, dword ptr [esi + 4]
// 005fc9f8  80792c00             cmp byte ptr [ecx + 0x2c], 0
// 005fc9fc  8d4604               lea eax, [esi + 4]
// 005fc9ff  0f841bffffff         je 0x5fc920
// 005fca05  8b5718               mov edx, dword ptr [edi + 0x18]
// 005fca08  8b4204               mov eax, dword ptr [edx + 4]
// 005fca0b  88582c               mov byte ptr [eax + 0x2c], bl
// 005fca0e  8b442464             mov eax, dword ptr [esp + 0x64]
// 005fca12  8b0f                 mov ecx, dword ptr [edi]
// 005fca14  5e                   pop esi
// 005fca15  896804               mov dword ptr [eax + 4], ebp
// 005fca18  5d                   pop ebp
// 005fca19  8908                 mov dword ptr [eax], ecx
// 005fca1b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 005fca1f  5b                   pop ebx
// 005fca20  5f                   pop edi
// 005fca21  64890d00000000       mov dword ptr fs:[0], ecx
// 005fca28  83c450               add esp, 0x50
// 005fca2b  c21000               ret 0x10
// standard library map_int<string> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@2@ABU?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@Z)

// stl: map_int<string>
#include <string>
typedef std::string E;
#include <map>
template class std::map<int, E>;
