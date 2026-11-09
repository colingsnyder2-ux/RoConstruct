// from server: 100% by auto
// roc 2009-12 00685d90  unit: RBX::VChangeHistoryService::?$BoundFuncDesc  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00685d90
//
// 00685d90  64a100000000         mov eax, dword ptr fs:[0]
// 00685d96  6aff                 push -1
// 00685d98  6812699500           push 0x956912
// 00685d9d  50                   push eax
// 00685d9e  64892500000000       mov dword ptr fs:[0], esp
// 00685da5  83ec44               sub esp, 0x44
// 00685da8  57                   push edi
// 00685da9  8bf9                 mov edi, ecx
// 00685dab  817f1c43444404       cmp dword ptr [edi + 0x1c], 0x4444443
// 00685db2  7259                 jb 0x685e0d
// 00685db4  6800f59900           push 0x99f500
// 00685db9  8d4c2408             lea ecx, [esp + 8]
// 00685dbd  ff15f4b69800         call dword ptr [0x98b6f4]
// 00685dc3  8d4c2420             lea ecx, [esp + 0x20]
// 00685dc7  c744245000000000     mov dword ptr [esp + 0x50], 0
// 00685dcf  ff1554b79800         call dword ptr [0x98b754]
// 00685dd5  8d442404             lea eax, [esp + 4]
// 00685dd9  50                   push eax
// 00685dda  8d4c2430             lea ecx, [esp + 0x30]
// 00685dde  c644245401           mov byte ptr [esp + 0x54], 1
// 00685de3  c744242484f49900     mov dword ptr [esp + 0x24], 0x99f484
// 00685deb  ff15f0b69800         call dword ptr [0x98b6f0]
// 00685df1  68e4efa800           push 0xa8efe4
// 00685df6  8d4c2424             lea ecx, [esp + 0x24]
// 00685dfa  51                   push ecx
// 00685dfb  c644245800           mov byte ptr [esp + 0x58], 0
// 00685e00  c744242890f49900     mov dword ptr [esp + 0x28], 0x99f490
// 00685e08  e86bea1600           call 0x7f4878
// 00685e0d  8b542464             mov edx, dword ptr [esp + 0x64]
// 00685e11  8b4718               mov eax, dword ptr [edi + 0x18]
// 00685e14  53                   push ebx
// 00685e15  55                   push ebp
// 00685e16  56                   push esi
// 00685e17  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 00685e1b  6a00                 push 0
// 00685e1d  52                   push edx
// 00685e1e  50                   push eax
// 00685e1f  56                   push esi
// 00685e20  50                   push eax
// 00685e21  e80af3ffff           call 0x685130
// 00685e26  8be8                 mov ebp, eax
// 00685e28  8b4718               mov eax, dword ptr [edi + 0x18]
// 00685e2b  bb01000000           mov ebx, 1
// 00685e30  015f1c               add dword ptr [edi + 0x1c], ebx
// 00685e33  3bf0                 cmp esi, eax
// 00685e35  7510                 jne 0x685e47
// 00685e37  896804               mov dword ptr [eax + 4], ebp
// 00685e3a  8b4718               mov eax, dword ptr [edi + 0x18]
// 00685e3d  8928                 mov dword ptr [eax], ebp
// 00685e3f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 00685e42  896908               mov dword ptr [ecx + 8], ebp
// 00685e45  eb22                 jmp 0x685e69
// 00685e47  807c246800           cmp byte ptr [esp + 0x68], 0
// 00685e4c  740d                 je 0x685e5b
// 00685e4e  892e                 mov dword ptr [esi], ebp
// 00685e50  8b4718               mov eax, dword ptr [edi + 0x18]
// 00685e53  3b30                 cmp esi, dword ptr [eax]
// 00685e55  7512                 jne 0x685e69
// 00685e57  8928                 mov dword ptr [eax], ebp
// 00685e59  eb0e                 jmp 0x685e69
// 00685e5b  896e08               mov dword ptr [esi + 8], ebp
// 00685e5e  8b4718               mov eax, dword ptr [edi + 0x18]
// 00685e61  3b7008               cmp esi, dword ptr [eax + 8]
// 00685e64  7503                 jne 0x685e69
// 00685e66  896808               mov dword ptr [eax + 8], ebp
// 00685e69  8b5504               mov edx, dword ptr [ebp + 4]
// 00685e6c  807a4800             cmp byte ptr [edx + 0x48], 0
// 00685e70  8d4504               lea eax, [ebp + 4]
// 00685e73  8bf5                 mov esi, ebp
// 00685e75  0f85ea000000         jne 0x685f65
// 00685e7b  eb03                 jmp 0x685e80
// 00685e7d  8d4900               lea ecx, [ecx]
// 00685e80  8b08                 mov ecx, dword ptr [eax]
// 00685e82  8b5104               mov edx, dword ptr [ecx + 4]
// 00685e85  3b0a                 cmp ecx, dword ptr [edx]
// 00685e87  7551                 jne 0x685eda
// 00685e89  8b5208               mov edx, dword ptr [edx + 8]
// 00685e8c  807a4800             cmp byte ptr [edx + 0x48], 0
// 00685e90  7519                 jne 0x685eab
// 00685e92  885948               mov byte ptr [ecx + 0x48], bl
// 00685e95  885a48               mov byte ptr [edx + 0x48], bl
// 00685e98  8b10                 mov edx, dword ptr [eax]
// 00685e9a  8b4a04               mov ecx, dword ptr [edx + 4]
// 00685e9d  c6414800             mov byte ptr [ecx + 0x48], 0
// 00685ea1  8b10                 mov edx, dword ptr [eax]
// 00685ea3  8b7204               mov esi, dword ptr [edx + 4]
// 00685ea6  e9aa000000           jmp 0x685f55
// 00685eab  3b7108               cmp esi, dword ptr [ecx + 8]
// 00685eae  750a                 jne 0x685eba
// 00685eb0  8bf1                 mov esi, ecx
// 00685eb2  56                   push esi
// 00685eb3  8bcf                 mov ecx, edi
// 00685eb5  e866071400           call 0x7c6620
// 00685eba  8b4604               mov eax, dword ptr [esi + 4]
// 00685ebd  885848               mov byte ptr [eax + 0x48], bl
// 00685ec0  8b4e04               mov ecx, dword ptr [esi + 4]
// 00685ec3  8b5104               mov edx, dword ptr [ecx + 4]
// 00685ec6  c6424800             mov byte ptr [edx + 0x48], 0
// 00685eca  8b4604               mov eax, dword ptr [esi + 4]
// 00685ecd  8b4804               mov ecx, dword ptr [eax + 4]
// 00685ed0  51                   push ecx
// 00685ed1  8bcf                 mov ecx, edi
// 00685ed3  e848c9ffff           call 0x682820
// 00685ed8  eb7b                 jmp 0x685f55
// 00685eda  8b12                 mov edx, dword ptr [edx]
// 00685edc  807a4800             cmp byte ptr [edx + 0x48], 0
// 00685ee0  7516                 jne 0x685ef8
// 00685ee2  885948               mov byte ptr [ecx + 0x48], bl
// 00685ee5  885a48               mov byte ptr [edx + 0x48], bl
// 00685ee8  8b10                 mov edx, dword ptr [eax]
// 00685eea  8b4a04               mov ecx, dword ptr [edx + 4]
// 00685eed  c6414800             mov byte ptr [ecx + 0x48], 0
// 00685ef1  8b10                 mov edx, dword ptr [eax]
// 00685ef3  8b7204               mov esi, dword ptr [edx + 4]
// 00685ef6  eb5d                 jmp 0x685f55
// 00685ef8  3b31                 cmp esi, dword ptr [ecx]
// 00685efa  750a                 jne 0x685f06
// 00685efc  8bf1                 mov esi, ecx
// 00685efe  56                   push esi
// 00685eff  8bcf                 mov ecx, edi
// 00685f01  e81ac9ffff           call 0x682820
// 00685f06  8b4604               mov eax, dword ptr [esi + 4]
// 00685f09  885848               mov byte ptr [eax + 0x48], bl
// 00685f0c  8b4e04               mov ecx, dword ptr [esi + 4]
// 00685f0f  8b5104               mov edx, dword ptr [ecx + 4]
// 00685f12  c6424800             mov byte ptr [edx + 0x48], 0
// 00685f16  8b4604               mov eax, dword ptr [esi + 4]
// 00685f19  8b4004               mov eax, dword ptr [eax + 4]
// 00685f1c  8b4808               mov ecx, dword ptr [eax + 8]
// 00685f1f  8b11                 mov edx, dword ptr [ecx]
// 00685f21  895008               mov dword ptr [eax + 8], edx
// 00685f24  8b11                 mov edx, dword ptr [ecx]
// 00685f26  807a4900             cmp byte ptr [edx + 0x49], 0
// 00685f2a  7503                 jne 0x685f2f
// 00685f2c  894204               mov dword ptr [edx + 4], eax
// 00685f2f  8b5004               mov edx, dword ptr [eax + 4]
// 00685f32  895104               mov dword ptr [ecx + 4], edx
// 00685f35  8b5718               mov edx, dword ptr [edi + 0x18]
// 00685f38  3b4204               cmp eax, dword ptr [edx + 4]
// 00685f3b  7505                 jne 0x685f42
// 00685f3d  894a04               mov dword ptr [edx + 4], ecx
// 00685f40  eb0e                 jmp 0x685f50
// 00685f42  8b5004               mov edx, dword ptr [eax + 4]
// 00685f45  3b02                 cmp eax, dword ptr [edx]
// 00685f47  7504                 jne 0x685f4d
// 00685f49  890a                 mov dword ptr [edx], ecx
// 00685f4b  eb03                 jmp 0x685f50
// 00685f4d  894a08               mov dword ptr [edx + 8], ecx
// 00685f50  8901                 mov dword ptr [ecx], eax
// 00685f52  894804               mov dword ptr [eax + 4], ecx
// 00685f55  8b4e04               mov ecx, dword ptr [esi + 4]
// 00685f58  80794800             cmp byte ptr [ecx + 0x48], 0
// 00685f5c  8d4604               lea eax, [esi + 4]
// 00685f5f  0f841bffffff         je 0x685e80
// 00685f65  8b5718               mov edx, dword ptr [edi + 0x18]
// 00685f68  8b4204               mov eax, dword ptr [edx + 4]
// 00685f6b  885848               mov byte ptr [eax + 0x48], bl
// 00685f6e  8b442464             mov eax, dword ptr [esp + 0x64]
// 00685f72  8b0f                 mov ecx, dword ptr [edi]
// 00685f74  5e                   pop esi
// 00685f75  896804               mov dword ptr [eax + 4], ebp
// 00685f78  5d                   pop ebp
// 00685f79  8908                 mov dword ptr [eax], ecx
// 00685f7b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00685f7f  5b                   pop ebx
// 00685f80  5f                   pop edi
// 00685f81  64890d00000000       mov dword ptr fs:[0], ecx
// 00685f88  83c450               add esp, 0x50
// 00685f8b  c21000               ret 0x10
// standard library map_str<pod32> (function ?_Insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod32>
struct E { int v[8]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
