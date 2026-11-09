// from server: 100% by auto
// roc 2010-06 0060f720  unit: RBX::Lua::VLiveThreadRef::?$sp_counted_impl_p  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0060f720
//
// 0060f720  64a100000000         mov eax, dword ptr fs:[0]
// 0060f726  6aff                 push -1
// 0060f728  68e22f9a00           push 0x9a2fe2
// 0060f72d  50                   push eax
// 0060f72e  64892500000000       mov dword ptr fs:[0], esp
// 0060f735  83ec44               sub esp, 0x44
// 0060f738  57                   push edi
// 0060f739  8bf9                 mov edi, ecx
// 0060f73b  817f1c43444404       cmp dword ptr [edi + 0x1c], 0x4444443
// 0060f742  7259                 jb 0x60f79d
// 0060f744  68a800a000           push 0xa000a8
// 0060f749  8d4c2408             lea ecx, [esp + 8]
// 0060f74d  ff1510a49e00         call dword ptr [0x9ea410]
// 0060f753  8d4c2420             lea ecx, [esp + 0x20]
// 0060f757  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0060f75f  ff1518a99e00         call dword ptr [0x9ea918]
// 0060f765  8d442404             lea eax, [esp + 4]
// 0060f769  50                   push eax
// 0060f76a  8d4c2430             lea ecx, [esp + 0x30]
// 0060f76e  c644245401           mov byte ptr [esp + 0x54], 1
// 0060f773  c74424242c00a000     mov dword ptr [esp + 0x24], 0xa0002c
// 0060f77b  ff150ca49e00         call dword ptr [0x9ea40c]
// 0060f781  68601bb000           push 0xb01b60
// 0060f786  8d4c2424             lea ecx, [esp + 0x24]
// 0060f78a  51                   push ecx
// 0060f78b  c644245800           mov byte ptr [esp + 0x58], 0
// 0060f790  c74424283800a000     mov dword ptr [esp + 0x28], 0xa00038
// 0060f798  e815921900           call 0x7a89b2
// 0060f79d  8b542464             mov edx, dword ptr [esp + 0x64]
// 0060f7a1  8b4718               mov eax, dword ptr [edi + 0x18]
// 0060f7a4  53                   push ebx
// 0060f7a5  55                   push ebp
// 0060f7a6  56                   push esi
// 0060f7a7  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0060f7ab  6a00                 push 0
// 0060f7ad  52                   push edx
// 0060f7ae  50                   push eax
// 0060f7af  56                   push esi
// 0060f7b0  50                   push eax
// 0060f7b1  e86af6ffff           call 0x60ee20
// 0060f7b6  8be8                 mov ebp, eax
// 0060f7b8  8b4718               mov eax, dword ptr [edi + 0x18]
// 0060f7bb  bb01000000           mov ebx, 1
// 0060f7c0  015f1c               add dword ptr [edi + 0x1c], ebx
// 0060f7c3  3bf0                 cmp esi, eax
// 0060f7c5  7510                 jne 0x60f7d7
// 0060f7c7  896804               mov dword ptr [eax + 4], ebp
// 0060f7ca  8b4718               mov eax, dword ptr [edi + 0x18]
// 0060f7cd  8928                 mov dword ptr [eax], ebp
// 0060f7cf  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 0060f7d2  896908               mov dword ptr [ecx + 8], ebp
// 0060f7d5  eb22                 jmp 0x60f7f9
// 0060f7d7  807c246800           cmp byte ptr [esp + 0x68], 0
// 0060f7dc  740d                 je 0x60f7eb
// 0060f7de  892e                 mov dword ptr [esi], ebp
// 0060f7e0  8b4718               mov eax, dword ptr [edi + 0x18]
// 0060f7e3  3b30                 cmp esi, dword ptr [eax]
// 0060f7e5  7512                 jne 0x60f7f9
// 0060f7e7  8928                 mov dword ptr [eax], ebp
// 0060f7e9  eb0e                 jmp 0x60f7f9
// 0060f7eb  896e08               mov dword ptr [esi + 8], ebp
// 0060f7ee  8b4718               mov eax, dword ptr [edi + 0x18]
// 0060f7f1  3b7008               cmp esi, dword ptr [eax + 8]
// 0060f7f4  7503                 jne 0x60f7f9
// 0060f7f6  896808               mov dword ptr [eax + 8], ebp
// 0060f7f9  8b5504               mov edx, dword ptr [ebp + 4]
// 0060f7fc  807a4800             cmp byte ptr [edx + 0x48], 0
// 0060f800  8d4504               lea eax, [ebp + 4]
// 0060f803  8bf5                 mov esi, ebp
// 0060f805  0f85ea000000         jne 0x60f8f5
// 0060f80b  eb03                 jmp 0x60f810
// 0060f80d  8d4900               lea ecx, [ecx]
// 0060f810  8b08                 mov ecx, dword ptr [eax]
// 0060f812  8b5104               mov edx, dword ptr [ecx + 4]
// 0060f815  3b0a                 cmp ecx, dword ptr [edx]
// 0060f817  7551                 jne 0x60f86a
// 0060f819  8b5208               mov edx, dword ptr [edx + 8]
// 0060f81c  807a4800             cmp byte ptr [edx + 0x48], 0
// 0060f820  7519                 jne 0x60f83b
// 0060f822  885948               mov byte ptr [ecx + 0x48], bl
// 0060f825  885a48               mov byte ptr [edx + 0x48], bl
// 0060f828  8b10                 mov edx, dword ptr [eax]
// 0060f82a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0060f82d  c6414800             mov byte ptr [ecx + 0x48], 0
// 0060f831  8b10                 mov edx, dword ptr [eax]
// 0060f833  8b7204               mov esi, dword ptr [edx + 4]
// 0060f836  e9aa000000           jmp 0x60f8e5
// 0060f83b  3b7108               cmp esi, dword ptr [ecx + 8]
// 0060f83e  750a                 jne 0x60f84a
// 0060f840  8bf1                 mov esi, ecx
// 0060f842  56                   push esi
// 0060f843  8bcf                 mov ecx, edi
// 0060f845  e806dbffff           call 0x60d350
// 0060f84a  8b4604               mov eax, dword ptr [esi + 4]
// 0060f84d  885848               mov byte ptr [eax + 0x48], bl
// 0060f850  8b4e04               mov ecx, dword ptr [esi + 4]
// 0060f853  8b5104               mov edx, dword ptr [ecx + 4]
// 0060f856  c6424800             mov byte ptr [edx + 0x48], 0
// 0060f85a  8b4604               mov eax, dword ptr [esi + 4]
// 0060f85d  8b4804               mov ecx, dword ptr [eax + 4]
// 0060f860  51                   push ecx
// 0060f861  8bcf                 mov ecx, edi
// 0060f863  e8d8fb1500           call 0x76f440
// 0060f868  eb7b                 jmp 0x60f8e5
// 0060f86a  8b12                 mov edx, dword ptr [edx]
// 0060f86c  807a4800             cmp byte ptr [edx + 0x48], 0
// 0060f870  7516                 jne 0x60f888
// 0060f872  885948               mov byte ptr [ecx + 0x48], bl
// 0060f875  885a48               mov byte ptr [edx + 0x48], bl
// 0060f878  8b10                 mov edx, dword ptr [eax]
// 0060f87a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0060f87d  c6414800             mov byte ptr [ecx + 0x48], 0
// 0060f881  8b10                 mov edx, dword ptr [eax]
// 0060f883  8b7204               mov esi, dword ptr [edx + 4]
// 0060f886  eb5d                 jmp 0x60f8e5
// 0060f888  3b31                 cmp esi, dword ptr [ecx]
// 0060f88a  750a                 jne 0x60f896
// 0060f88c  8bf1                 mov esi, ecx
// 0060f88e  56                   push esi
// 0060f88f  8bcf                 mov ecx, edi
// 0060f891  e8aafb1500           call 0x76f440
// 0060f896  8b4604               mov eax, dword ptr [esi + 4]
// 0060f899  885848               mov byte ptr [eax + 0x48], bl
// 0060f89c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0060f89f  8b5104               mov edx, dword ptr [ecx + 4]
// 0060f8a2  c6424800             mov byte ptr [edx + 0x48], 0
// 0060f8a6  8b4604               mov eax, dword ptr [esi + 4]
// 0060f8a9  8b4004               mov eax, dword ptr [eax + 4]
// 0060f8ac  8b4808               mov ecx, dword ptr [eax + 8]
// 0060f8af  8b11                 mov edx, dword ptr [ecx]
// 0060f8b1  895008               mov dword ptr [eax + 8], edx
// 0060f8b4  8b11                 mov edx, dword ptr [ecx]
// 0060f8b6  807a4900             cmp byte ptr [edx + 0x49], 0
// 0060f8ba  7503                 jne 0x60f8bf
// 0060f8bc  894204               mov dword ptr [edx + 4], eax
// 0060f8bf  8b5004               mov edx, dword ptr [eax + 4]
// 0060f8c2  895104               mov dword ptr [ecx + 4], edx
// 0060f8c5  8b5718               mov edx, dword ptr [edi + 0x18]
// 0060f8c8  3b4204               cmp eax, dword ptr [edx + 4]
// 0060f8cb  7505                 jne 0x60f8d2
// 0060f8cd  894a04               mov dword ptr [edx + 4], ecx
// 0060f8d0  eb0e                 jmp 0x60f8e0
// 0060f8d2  8b5004               mov edx, dword ptr [eax + 4]
// 0060f8d5  3b02                 cmp eax, dword ptr [edx]
// 0060f8d7  7504                 jne 0x60f8dd
// 0060f8d9  890a                 mov dword ptr [edx], ecx
// 0060f8db  eb03                 jmp 0x60f8e0
// 0060f8dd  894a08               mov dword ptr [edx + 8], ecx
// 0060f8e0  8901                 mov dword ptr [ecx], eax
// 0060f8e2  894804               mov dword ptr [eax + 4], ecx
// 0060f8e5  8b4e04               mov ecx, dword ptr [esi + 4]
// 0060f8e8  80794800             cmp byte ptr [ecx + 0x48], 0
// 0060f8ec  8d4604               lea eax, [esi + 4]
// 0060f8ef  0f841bffffff         je 0x60f810
// 0060f8f5  8b5718               mov edx, dword ptr [edi + 0x18]
// 0060f8f8  8b4204               mov eax, dword ptr [edx + 4]
// 0060f8fb  885848               mov byte ptr [eax + 0x48], bl
// 0060f8fe  8b442464             mov eax, dword ptr [esp + 0x64]
// 0060f902  8b0f                 mov ecx, dword ptr [edi]
// 0060f904  5e                   pop esi
// 0060f905  896804               mov dword ptr [eax + 4], ebp
// 0060f908  5d                   pop ebp
// 0060f909  8908                 mov dword ptr [eax], ecx
// 0060f90b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0060f90f  5b                   pop ebx
// 0060f910  5f                   pop edi
// 0060f911  64890d00000000       mov dword ptr fs:[0], ecx
// 0060f918  83c450               add esp, 0x50
// 0060f91b  c21000               ret 0x10
// standard library map_str<pod32> (function ?_Insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod32>
struct E { int v[8]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
