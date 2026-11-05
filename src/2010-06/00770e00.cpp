// from server: 100% by auto
// roc 2010-06 00770e00  unit: RBX::ScoreHud  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00770e00
//
// 00770e00  64a100000000         mov eax, dword ptr fs:[0]
// 00770e06  6aff                 push -1
// 00770e08  68e22f9a00           push 0x9a2fe2
// 00770e0d  50                   push eax
// 00770e0e  64892500000000       mov dword ptr fs:[0], esp
// 00770e15  83ec44               sub esp, 0x44
// 00770e18  57                   push edi
// 00770e19  8bf9                 mov edi, ecx
// 00770e1b  817f1cc6711c07       cmp dword ptr [edi + 0x1c], 0x71c71c6
// 00770e22  7259                 jb 0x770e7d
// 00770e24  68a800a000           push 0xa000a8
// 00770e29  8d4c2408             lea ecx, [esp + 8]
// 00770e2d  ff1510a49e00         call dword ptr [0x9ea410]
// 00770e33  8d4c2420             lea ecx, [esp + 0x20]
// 00770e37  c744245000000000     mov dword ptr [esp + 0x50], 0
// 00770e3f  ff1518a99e00         call dword ptr [0x9ea918]
// 00770e45  8d442404             lea eax, [esp + 4]
// 00770e49  50                   push eax
// 00770e4a  8d4c2430             lea ecx, [esp + 0x30]
// 00770e4e  c644245401           mov byte ptr [esp + 0x54], 1
// 00770e53  c74424242c00a000     mov dword ptr [esp + 0x24], 0xa0002c
// 00770e5b  ff150ca49e00         call dword ptr [0x9ea40c]
// 00770e61  68601bb000           push 0xb01b60
// 00770e66  8d4c2424             lea ecx, [esp + 0x24]
// 00770e6a  51                   push ecx
// 00770e6b  c644245800           mov byte ptr [esp + 0x58], 0
// 00770e70  c74424283800a000     mov dword ptr [esp + 0x28], 0xa00038
// 00770e78  e8357b0300           call 0x7a89b2
// 00770e7d  8b542464             mov edx, dword ptr [esp + 0x64]
// 00770e81  8b4718               mov eax, dword ptr [edi + 0x18]
// 00770e84  53                   push ebx
// 00770e85  55                   push ebp
// 00770e86  56                   push esi
// 00770e87  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 00770e8b  6a00                 push 0
// 00770e8d  52                   push edx
// 00770e8e  50                   push eax
// 00770e8f  56                   push esi
// 00770e90  50                   push eax
// 00770e91  e8faf9ffff           call 0x770890
// 00770e96  8be8                 mov ebp, eax
// 00770e98  8b4718               mov eax, dword ptr [edi + 0x18]
// 00770e9b  bb01000000           mov ebx, 1
// 00770ea0  015f1c               add dword ptr [edi + 0x1c], ebx
// 00770ea3  3bf0                 cmp esi, eax
// 00770ea5  7510                 jne 0x770eb7
// 00770ea7  896804               mov dword ptr [eax + 4], ebp
// 00770eaa  8b4718               mov eax, dword ptr [edi + 0x18]
// 00770ead  8928                 mov dword ptr [eax], ebp
// 00770eaf  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 00770eb2  896908               mov dword ptr [ecx + 8], ebp
// 00770eb5  eb22                 jmp 0x770ed9
// 00770eb7  807c246800           cmp byte ptr [esp + 0x68], 0
// 00770ebc  740d                 je 0x770ecb
// 00770ebe  892e                 mov dword ptr [esi], ebp
// 00770ec0  8b4718               mov eax, dword ptr [edi + 0x18]
// 00770ec3  3b30                 cmp esi, dword ptr [eax]
// 00770ec5  7512                 jne 0x770ed9
// 00770ec7  8928                 mov dword ptr [eax], ebp
// 00770ec9  eb0e                 jmp 0x770ed9
// 00770ecb  896e08               mov dword ptr [esi + 8], ebp
// 00770ece  8b4718               mov eax, dword ptr [edi + 0x18]
// 00770ed1  3b7008               cmp esi, dword ptr [eax + 8]
// 00770ed4  7503                 jne 0x770ed9
// 00770ed6  896808               mov dword ptr [eax + 8], ebp
// 00770ed9  8b5504               mov edx, dword ptr [ebp + 4]
// 00770edc  807a3000             cmp byte ptr [edx + 0x30], 0
// 00770ee0  8d4504               lea eax, [ebp + 4]
// 00770ee3  8bf5                 mov esi, ebp
// 00770ee5  0f85ea000000         jne 0x770fd5
// 00770eeb  eb03                 jmp 0x770ef0
// 00770eed  8d4900               lea ecx, [ecx]
// 00770ef0  8b08                 mov ecx, dword ptr [eax]
// 00770ef2  8b5104               mov edx, dword ptr [ecx + 4]
// 00770ef5  3b0a                 cmp ecx, dword ptr [edx]
// 00770ef7  7551                 jne 0x770f4a
// 00770ef9  8b5208               mov edx, dword ptr [edx + 8]
// 00770efc  807a3000             cmp byte ptr [edx + 0x30], 0
// 00770f00  7519                 jne 0x770f1b
// 00770f02  885930               mov byte ptr [ecx + 0x30], bl
// 00770f05  885a30               mov byte ptr [edx + 0x30], bl
// 00770f08  8b10                 mov edx, dword ptr [eax]
// 00770f0a  8b4a04               mov ecx, dword ptr [edx + 4]
// 00770f0d  c6413000             mov byte ptr [ecx + 0x30], 0
// 00770f11  8b10                 mov edx, dword ptr [eax]
// 00770f13  8b7204               mov esi, dword ptr [edx + 4]
// 00770f16  e9aa000000           jmp 0x770fc5
// 00770f1b  3b7108               cmp esi, dword ptr [ecx + 8]
// 00770f1e  750a                 jne 0x770f2a
// 00770f20  8bf1                 mov esi, ecx
// 00770f22  56                   push esi
// 00770f23  8bcf                 mov ecx, edi
// 00770f25  e8f6e5eeff           call 0x65f520
// 00770f2a  8b4604               mov eax, dword ptr [esi + 4]
// 00770f2d  885830               mov byte ptr [eax + 0x30], bl
// 00770f30  8b4e04               mov ecx, dword ptr [esi + 4]
// 00770f33  8b5104               mov edx, dword ptr [ecx + 4]
// 00770f36  c6423000             mov byte ptr [edx + 0x30], 0
// 00770f3a  8b4604               mov eax, dword ptr [esi + 4]
// 00770f3d  8b4804               mov ecx, dword ptr [eax + 4]
// 00770f40  51                   push ecx
// 00770f41  8bcf                 mov ecx, edi
// 00770f43  e808efd4ff           call 0x4bfe50
// 00770f48  eb7b                 jmp 0x770fc5
// 00770f4a  8b12                 mov edx, dword ptr [edx]
// 00770f4c  807a3000             cmp byte ptr [edx + 0x30], 0
// 00770f50  7516                 jne 0x770f68
// 00770f52  885930               mov byte ptr [ecx + 0x30], bl
// 00770f55  885a30               mov byte ptr [edx + 0x30], bl
// 00770f58  8b10                 mov edx, dword ptr [eax]
// 00770f5a  8b4a04               mov ecx, dword ptr [edx + 4]
// 00770f5d  c6413000             mov byte ptr [ecx + 0x30], 0
// 00770f61  8b10                 mov edx, dword ptr [eax]
// 00770f63  8b7204               mov esi, dword ptr [edx + 4]
// 00770f66  eb5d                 jmp 0x770fc5
// 00770f68  3b31                 cmp esi, dword ptr [ecx]
// 00770f6a  750a                 jne 0x770f76
// 00770f6c  8bf1                 mov esi, ecx
// 00770f6e  56                   push esi
// 00770f6f  8bcf                 mov ecx, edi
// 00770f71  e8daeed4ff           call 0x4bfe50
// 00770f76  8b4604               mov eax, dword ptr [esi + 4]
// 00770f79  885830               mov byte ptr [eax + 0x30], bl
// 00770f7c  8b4e04               mov ecx, dword ptr [esi + 4]
// 00770f7f  8b5104               mov edx, dword ptr [ecx + 4]
// 00770f82  c6423000             mov byte ptr [edx + 0x30], 0
// 00770f86  8b4604               mov eax, dword ptr [esi + 4]
// 00770f89  8b4004               mov eax, dword ptr [eax + 4]
// 00770f8c  8b4808               mov ecx, dword ptr [eax + 8]
// 00770f8f  8b11                 mov edx, dword ptr [ecx]
// 00770f91  895008               mov dword ptr [eax + 8], edx
// 00770f94  8b11                 mov edx, dword ptr [ecx]
// 00770f96  807a3100             cmp byte ptr [edx + 0x31], 0
// 00770f9a  7503                 jne 0x770f9f
// 00770f9c  894204               mov dword ptr [edx + 4], eax
// 00770f9f  8b5004               mov edx, dword ptr [eax + 4]
// 00770fa2  895104               mov dword ptr [ecx + 4], edx
// 00770fa5  8b5718               mov edx, dword ptr [edi + 0x18]
// 00770fa8  3b4204               cmp eax, dword ptr [edx + 4]
// 00770fab  7505                 jne 0x770fb2
// 00770fad  894a04               mov dword ptr [edx + 4], ecx
// 00770fb0  eb0e                 jmp 0x770fc0
// 00770fb2  8b5004               mov edx, dword ptr [eax + 4]
// 00770fb5  3b02                 cmp eax, dword ptr [edx]
// 00770fb7  7504                 jne 0x770fbd
// 00770fb9  890a                 mov dword ptr [edx], ecx
// 00770fbb  eb03                 jmp 0x770fc0
// 00770fbd  894a08               mov dword ptr [edx + 8], ecx
// 00770fc0  8901                 mov dword ptr [ecx], eax
// 00770fc2  894804               mov dword ptr [eax + 4], ecx
// 00770fc5  8b4e04               mov ecx, dword ptr [esi + 4]
// 00770fc8  80793000             cmp byte ptr [ecx + 0x30], 0
// 00770fcc  8d4604               lea eax, [esi + 4]
// 00770fcf  0f841bffffff         je 0x770ef0
// 00770fd5  8b5718               mov edx, dword ptr [edi + 0x18]
// 00770fd8  8b4204               mov eax, dword ptr [edx + 4]
// 00770fdb  885830               mov byte ptr [eax + 0x30], bl
// 00770fde  8b442464             mov eax, dword ptr [esp + 0x64]
// 00770fe2  8b0f                 mov ecx, dword ptr [edi]
// 00770fe4  5e                   pop esi
// 00770fe5  896804               mov dword ptr [eax + 4], ebp
// 00770fe8  5d                   pop ebp
// 00770fe9  8908                 mov dword ptr [eax], ecx
// 00770feb  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00770fef  5b                   pop ebx
// 00770ff0  5f                   pop edi
// 00770ff1  64890d00000000       mov dword ptr fs:[0], ecx
// 00770ff8  83c450               add esp, 0x50
// 00770ffb  c21000               ret 0x10
// standard library map_int<pod32> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod32>
struct E { int v[8]; };
#include <map>
template class std::map<int, E>;
