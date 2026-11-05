// from server: 100% by auto
// roc 2010-06 00770c00  unit: RBX::ScoreHud  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00770c00
//
// 00770c00  64a100000000         mov eax, dword ptr fs:[0]
// 00770c06  6aff                 push -1
// 00770c08  68e22f9a00           push 0x9a2fe2
// 00770c0d  50                   push eax
// 00770c0e  64892500000000       mov dword ptr fs:[0], esp
// 00770c15  83ec44               sub esp, 0x44
// 00770c18  57                   push edi
// 00770c19  8bf9                 mov edi, ecx
// 00770c1b  817f1c43444404       cmp dword ptr [edi + 0x1c], 0x4444443
// 00770c22  7259                 jb 0x770c7d
// 00770c24  68a800a000           push 0xa000a8
// 00770c29  8d4c2408             lea ecx, [esp + 8]
// 00770c2d  ff1510a49e00         call dword ptr [0x9ea410]
// 00770c33  8d4c2420             lea ecx, [esp + 0x20]
// 00770c37  c744245000000000     mov dword ptr [esp + 0x50], 0
// 00770c3f  ff1518a99e00         call dword ptr [0x9ea918]
// 00770c45  8d442404             lea eax, [esp + 4]
// 00770c49  50                   push eax
// 00770c4a  8d4c2430             lea ecx, [esp + 0x30]
// 00770c4e  c644245401           mov byte ptr [esp + 0x54], 1
// 00770c53  c74424242c00a000     mov dword ptr [esp + 0x24], 0xa0002c
// 00770c5b  ff150ca49e00         call dword ptr [0x9ea40c]
// 00770c61  68601bb000           push 0xb01b60
// 00770c66  8d4c2424             lea ecx, [esp + 0x24]
// 00770c6a  51                   push ecx
// 00770c6b  c644245800           mov byte ptr [esp + 0x58], 0
// 00770c70  c74424283800a000     mov dword ptr [esp + 0x28], 0xa00038
// 00770c78  e8357d0300           call 0x7a89b2
// 00770c7d  8b542464             mov edx, dword ptr [esp + 0x64]
// 00770c81  8b4718               mov eax, dword ptr [edi + 0x18]
// 00770c84  53                   push ebx
// 00770c85  55                   push ebp
// 00770c86  56                   push esi
// 00770c87  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 00770c8b  6a00                 push 0
// 00770c8d  52                   push edx
// 00770c8e  50                   push eax
// 00770c8f  56                   push esi
// 00770c90  50                   push eax
// 00770c91  e85afbffff           call 0x7707f0
// 00770c96  8be8                 mov ebp, eax
// 00770c98  8b4718               mov eax, dword ptr [edi + 0x18]
// 00770c9b  bb01000000           mov ebx, 1
// 00770ca0  015f1c               add dword ptr [edi + 0x1c], ebx
// 00770ca3  3bf0                 cmp esi, eax
// 00770ca5  7510                 jne 0x770cb7
// 00770ca7  896804               mov dword ptr [eax + 4], ebp
// 00770caa  8b4718               mov eax, dword ptr [edi + 0x18]
// 00770cad  8928                 mov dword ptr [eax], ebp
// 00770caf  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 00770cb2  896908               mov dword ptr [ecx + 8], ebp
// 00770cb5  eb22                 jmp 0x770cd9
// 00770cb7  807c246800           cmp byte ptr [esp + 0x68], 0
// 00770cbc  740d                 je 0x770ccb
// 00770cbe  892e                 mov dword ptr [esi], ebp
// 00770cc0  8b4718               mov eax, dword ptr [edi + 0x18]
// 00770cc3  3b30                 cmp esi, dword ptr [eax]
// 00770cc5  7512                 jne 0x770cd9
// 00770cc7  8928                 mov dword ptr [eax], ebp
// 00770cc9  eb0e                 jmp 0x770cd9
// 00770ccb  896e08               mov dword ptr [esi + 8], ebp
// 00770cce  8b4718               mov eax, dword ptr [edi + 0x18]
// 00770cd1  3b7008               cmp esi, dword ptr [eax + 8]
// 00770cd4  7503                 jne 0x770cd9
// 00770cd6  896808               mov dword ptr [eax + 8], ebp
// 00770cd9  8b5504               mov edx, dword ptr [ebp + 4]
// 00770cdc  807a4800             cmp byte ptr [edx + 0x48], 0
// 00770ce0  8d4504               lea eax, [ebp + 4]
// 00770ce3  8bf5                 mov esi, ebp
// 00770ce5  0f85ea000000         jne 0x770dd5
// 00770ceb  eb03                 jmp 0x770cf0
// 00770ced  8d4900               lea ecx, [ecx]
// 00770cf0  8b08                 mov ecx, dword ptr [eax]
// 00770cf2  8b5104               mov edx, dword ptr [ecx + 4]
// 00770cf5  3b0a                 cmp ecx, dword ptr [edx]
// 00770cf7  7551                 jne 0x770d4a
// 00770cf9  8b5208               mov edx, dword ptr [edx + 8]
// 00770cfc  807a4800             cmp byte ptr [edx + 0x48], 0
// 00770d00  7519                 jne 0x770d1b
// 00770d02  885948               mov byte ptr [ecx + 0x48], bl
// 00770d05  885a48               mov byte ptr [edx + 0x48], bl
// 00770d08  8b10                 mov edx, dword ptr [eax]
// 00770d0a  8b4a04               mov ecx, dword ptr [edx + 4]
// 00770d0d  c6414800             mov byte ptr [ecx + 0x48], 0
// 00770d11  8b10                 mov edx, dword ptr [eax]
// 00770d13  8b7204               mov esi, dword ptr [edx + 4]
// 00770d16  e9aa000000           jmp 0x770dc5
// 00770d1b  3b7108               cmp esi, dword ptr [ecx + 8]
// 00770d1e  750a                 jne 0x770d2a
// 00770d20  8bf1                 mov esi, ecx
// 00770d22  56                   push esi
// 00770d23  8bcf                 mov ecx, edi
// 00770d25  e826c6e9ff           call 0x60d350
// 00770d2a  8b4604               mov eax, dword ptr [esi + 4]
// 00770d2d  885848               mov byte ptr [eax + 0x48], bl
// 00770d30  8b4e04               mov ecx, dword ptr [esi + 4]
// 00770d33  8b5104               mov edx, dword ptr [ecx + 4]
// 00770d36  c6424800             mov byte ptr [edx + 0x48], 0
// 00770d3a  8b4604               mov eax, dword ptr [esi + 4]
// 00770d3d  8b4804               mov ecx, dword ptr [eax + 4]
// 00770d40  51                   push ecx
// 00770d41  8bcf                 mov ecx, edi
// 00770d43  e8f8e6ffff           call 0x76f440
// 00770d48  eb7b                 jmp 0x770dc5
// 00770d4a  8b12                 mov edx, dword ptr [edx]
// 00770d4c  807a4800             cmp byte ptr [edx + 0x48], 0
// 00770d50  7516                 jne 0x770d68
// 00770d52  885948               mov byte ptr [ecx + 0x48], bl
// 00770d55  885a48               mov byte ptr [edx + 0x48], bl
// 00770d58  8b10                 mov edx, dword ptr [eax]
// 00770d5a  8b4a04               mov ecx, dword ptr [edx + 4]
// 00770d5d  c6414800             mov byte ptr [ecx + 0x48], 0
// 00770d61  8b10                 mov edx, dword ptr [eax]
// 00770d63  8b7204               mov esi, dword ptr [edx + 4]
// 00770d66  eb5d                 jmp 0x770dc5
// 00770d68  3b31                 cmp esi, dword ptr [ecx]
// 00770d6a  750a                 jne 0x770d76
// 00770d6c  8bf1                 mov esi, ecx
// 00770d6e  56                   push esi
// 00770d6f  8bcf                 mov ecx, edi
// 00770d71  e8cae6ffff           call 0x76f440
// 00770d76  8b4604               mov eax, dword ptr [esi + 4]
// 00770d79  885848               mov byte ptr [eax + 0x48], bl
// 00770d7c  8b4e04               mov ecx, dword ptr [esi + 4]
// 00770d7f  8b5104               mov edx, dword ptr [ecx + 4]
// 00770d82  c6424800             mov byte ptr [edx + 0x48], 0
// 00770d86  8b4604               mov eax, dword ptr [esi + 4]
// 00770d89  8b4004               mov eax, dword ptr [eax + 4]
// 00770d8c  8b4808               mov ecx, dword ptr [eax + 8]
// 00770d8f  8b11                 mov edx, dword ptr [ecx]
// 00770d91  895008               mov dword ptr [eax + 8], edx
// 00770d94  8b11                 mov edx, dword ptr [ecx]
// 00770d96  807a4900             cmp byte ptr [edx + 0x49], 0
// 00770d9a  7503                 jne 0x770d9f
// 00770d9c  894204               mov dword ptr [edx + 4], eax
// 00770d9f  8b5004               mov edx, dword ptr [eax + 4]
// 00770da2  895104               mov dword ptr [ecx + 4], edx
// 00770da5  8b5718               mov edx, dword ptr [edi + 0x18]
// 00770da8  3b4204               cmp eax, dword ptr [edx + 4]
// 00770dab  7505                 jne 0x770db2
// 00770dad  894a04               mov dword ptr [edx + 4], ecx
// 00770db0  eb0e                 jmp 0x770dc0
// 00770db2  8b5004               mov edx, dword ptr [eax + 4]
// 00770db5  3b02                 cmp eax, dword ptr [edx]
// 00770db7  7504                 jne 0x770dbd
// 00770db9  890a                 mov dword ptr [edx], ecx
// 00770dbb  eb03                 jmp 0x770dc0
// 00770dbd  894a08               mov dword ptr [edx + 8], ecx
// 00770dc0  8901                 mov dword ptr [ecx], eax
// 00770dc2  894804               mov dword ptr [eax + 4], ecx
// 00770dc5  8b4e04               mov ecx, dword ptr [esi + 4]
// 00770dc8  80794800             cmp byte ptr [ecx + 0x48], 0
// 00770dcc  8d4604               lea eax, [esi + 4]
// 00770dcf  0f841bffffff         je 0x770cf0
// 00770dd5  8b5718               mov edx, dword ptr [edi + 0x18]
// 00770dd8  8b4204               mov eax, dword ptr [edx + 4]
// 00770ddb  885848               mov byte ptr [eax + 0x48], bl
// 00770dde  8b442464             mov eax, dword ptr [esp + 0x64]
// 00770de2  8b0f                 mov ecx, dword ptr [edi]
// 00770de4  5e                   pop esi
// 00770de5  896804               mov dword ptr [eax + 4], ebp
// 00770de8  5d                   pop ebp
// 00770de9  8908                 mov dword ptr [eax], ecx
// 00770deb  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00770def  5b                   pop ebx
// 00770df0  5f                   pop edi
// 00770df1  64890d00000000       mov dword ptr fs:[0], ecx
// 00770df8  83c450               add esp, 0x50
// 00770dfb  c21000               ret 0x10
// standard library map_str<pod32> (function ?_Insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod32>
struct E { int v[8]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
