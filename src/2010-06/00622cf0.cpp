// from server: 100% by auto
// roc 2010-06 00622cf0  unit: RBX::Soundscape::VSoundId::?$TypedPropertyDescriptor  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00622cf0
//
// 00622cf0  64a100000000         mov eax, dword ptr fs:[0]
// 00622cf6  6aff                 push -1
// 00622cf8  68e22f9a00           push 0x9a2fe2
// 00622cfd  50                   push eax
// 00622cfe  64892500000000       mov dword ptr fs:[0], esp
// 00622d05  83ec44               sub esp, 0x44
// 00622d08  57                   push edi
// 00622d09  8bf9                 mov edi, ecx
// 00622d0b  817f1c65666606       cmp dword ptr [edi + 0x1c], 0x6666665
// 00622d12  7259                 jb 0x622d6d
// 00622d14  68a800a000           push 0xa000a8
// 00622d19  8d4c2408             lea ecx, [esp + 8]
// 00622d1d  ff1510a49e00         call dword ptr [0x9ea410]
// 00622d23  8d4c2420             lea ecx, [esp + 0x20]
// 00622d27  c744245000000000     mov dword ptr [esp + 0x50], 0
// 00622d2f  ff1518a99e00         call dword ptr [0x9ea918]
// 00622d35  8d442404             lea eax, [esp + 4]
// 00622d39  50                   push eax
// 00622d3a  8d4c2430             lea ecx, [esp + 0x30]
// 00622d3e  c644245401           mov byte ptr [esp + 0x54], 1
// 00622d43  c74424242c00a000     mov dword ptr [esp + 0x24], 0xa0002c
// 00622d4b  ff150ca49e00         call dword ptr [0x9ea40c]
// 00622d51  68601bb000           push 0xb01b60
// 00622d56  8d4c2424             lea ecx, [esp + 0x24]
// 00622d5a  51                   push ecx
// 00622d5b  c644245800           mov byte ptr [esp + 0x58], 0
// 00622d60  c74424283800a000     mov dword ptr [esp + 0x28], 0xa00038
// 00622d68  e8455c1800           call 0x7a89b2
// 00622d6d  8b542464             mov edx, dword ptr [esp + 0x64]
// 00622d71  8b4718               mov eax, dword ptr [edi + 0x18]
// 00622d74  53                   push ebx
// 00622d75  55                   push ebp
// 00622d76  56                   push esi
// 00622d77  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 00622d7b  6a00                 push 0
// 00622d7d  52                   push edx
// 00622d7e  50                   push eax
// 00622d7f  56                   push esi
// 00622d80  50                   push eax
// 00622d81  e85afbffff           call 0x6228e0
// 00622d86  8be8                 mov ebp, eax
// 00622d88  8b4718               mov eax, dword ptr [edi + 0x18]
// 00622d8b  bb01000000           mov ebx, 1
// 00622d90  015f1c               add dword ptr [edi + 0x1c], ebx
// 00622d93  3bf0                 cmp esi, eax
// 00622d95  7510                 jne 0x622da7
// 00622d97  896804               mov dword ptr [eax + 4], ebp
// 00622d9a  8b4718               mov eax, dword ptr [edi + 0x18]
// 00622d9d  8928                 mov dword ptr [eax], ebp
// 00622d9f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 00622da2  896908               mov dword ptr [ecx + 8], ebp
// 00622da5  eb22                 jmp 0x622dc9
// 00622da7  807c246800           cmp byte ptr [esp + 0x68], 0
// 00622dac  740d                 je 0x622dbb
// 00622dae  892e                 mov dword ptr [esi], ebp
// 00622db0  8b4718               mov eax, dword ptr [edi + 0x18]
// 00622db3  3b30                 cmp esi, dword ptr [eax]
// 00622db5  7512                 jne 0x622dc9
// 00622db7  8928                 mov dword ptr [eax], ebp
// 00622db9  eb0e                 jmp 0x622dc9
// 00622dbb  896e08               mov dword ptr [esi + 8], ebp
// 00622dbe  8b4718               mov eax, dword ptr [edi + 0x18]
// 00622dc1  3b7008               cmp esi, dword ptr [eax + 8]
// 00622dc4  7503                 jne 0x622dc9
// 00622dc6  896808               mov dword ptr [eax + 8], ebp
// 00622dc9  8b5504               mov edx, dword ptr [ebp + 4]
// 00622dcc  807a3400             cmp byte ptr [edx + 0x34], 0
// 00622dd0  8d4504               lea eax, [ebp + 4]
// 00622dd3  8bf5                 mov esi, ebp
// 00622dd5  0f85ea000000         jne 0x622ec5
// 00622ddb  eb03                 jmp 0x622de0
// 00622ddd  8d4900               lea ecx, [ecx]
// 00622de0  8b08                 mov ecx, dword ptr [eax]
// 00622de2  8b5104               mov edx, dword ptr [ecx + 4]
// 00622de5  3b0a                 cmp ecx, dword ptr [edx]
// 00622de7  7551                 jne 0x622e3a
// 00622de9  8b5208               mov edx, dword ptr [edx + 8]
// 00622dec  807a3400             cmp byte ptr [edx + 0x34], 0
// 00622df0  7519                 jne 0x622e0b
// 00622df2  885934               mov byte ptr [ecx + 0x34], bl
// 00622df5  885a34               mov byte ptr [edx + 0x34], bl
// 00622df8  8b10                 mov edx, dword ptr [eax]
// 00622dfa  8b4a04               mov ecx, dword ptr [edx + 4]
// 00622dfd  c6413400             mov byte ptr [ecx + 0x34], 0
// 00622e01  8b10                 mov edx, dword ptr [eax]
// 00622e03  8b7204               mov esi, dword ptr [edx + 4]
// 00622e06  e9aa000000           jmp 0x622eb5
// 00622e0b  3b7108               cmp esi, dword ptr [ecx + 8]
// 00622e0e  750a                 jne 0x622e1a
// 00622e10  8bf1                 mov esi, ecx
// 00622e12  56                   push esi
// 00622e13  8bcf                 mov ecx, edi
// 00622e15  e896ce0100           call 0x63fcb0
// 00622e1a  8b4604               mov eax, dword ptr [esi + 4]
// 00622e1d  885834               mov byte ptr [eax + 0x34], bl
// 00622e20  8b4e04               mov ecx, dword ptr [esi + 4]
// 00622e23  8b5104               mov edx, dword ptr [ecx + 4]
// 00622e26  c6423400             mov byte ptr [edx + 0x34], 0
// 00622e2a  8b4604               mov eax, dword ptr [esi + 4]
// 00622e2d  8b4804               mov ecx, dword ptr [eax + 4]
// 00622e30  51                   push ecx
// 00622e31  8bcf                 mov ecx, edi
// 00622e33  e8c8ce0100           call 0x63fd00
// 00622e38  eb7b                 jmp 0x622eb5
// 00622e3a  8b12                 mov edx, dword ptr [edx]
// 00622e3c  807a3400             cmp byte ptr [edx + 0x34], 0
// 00622e40  7516                 jne 0x622e58
// 00622e42  885934               mov byte ptr [ecx + 0x34], bl
// 00622e45  885a34               mov byte ptr [edx + 0x34], bl
// 00622e48  8b10                 mov edx, dword ptr [eax]
// 00622e4a  8b4a04               mov ecx, dword ptr [edx + 4]
// 00622e4d  c6413400             mov byte ptr [ecx + 0x34], 0
// 00622e51  8b10                 mov edx, dword ptr [eax]
// 00622e53  8b7204               mov esi, dword ptr [edx + 4]
// 00622e56  eb5d                 jmp 0x622eb5
// 00622e58  3b31                 cmp esi, dword ptr [ecx]
// 00622e5a  750a                 jne 0x622e66
// 00622e5c  8bf1                 mov esi, ecx
// 00622e5e  56                   push esi
// 00622e5f  8bcf                 mov ecx, edi
// 00622e61  e89ace0100           call 0x63fd00
// 00622e66  8b4604               mov eax, dword ptr [esi + 4]
// 00622e69  885834               mov byte ptr [eax + 0x34], bl
// 00622e6c  8b4e04               mov ecx, dword ptr [esi + 4]
// 00622e6f  8b5104               mov edx, dword ptr [ecx + 4]
// 00622e72  c6423400             mov byte ptr [edx + 0x34], 0
// 00622e76  8b4604               mov eax, dword ptr [esi + 4]
// 00622e79  8b4004               mov eax, dword ptr [eax + 4]
// 00622e7c  8b4808               mov ecx, dword ptr [eax + 8]
// 00622e7f  8b11                 mov edx, dword ptr [ecx]
// 00622e81  895008               mov dword ptr [eax + 8], edx
// 00622e84  8b11                 mov edx, dword ptr [ecx]
// 00622e86  807a3500             cmp byte ptr [edx + 0x35], 0
// 00622e8a  7503                 jne 0x622e8f
// 00622e8c  894204               mov dword ptr [edx + 4], eax
// 00622e8f  8b5004               mov edx, dword ptr [eax + 4]
// 00622e92  895104               mov dword ptr [ecx + 4], edx
// 00622e95  8b5718               mov edx, dword ptr [edi + 0x18]
// 00622e98  3b4204               cmp eax, dword ptr [edx + 4]
// 00622e9b  7505                 jne 0x622ea2
// 00622e9d  894a04               mov dword ptr [edx + 4], ecx
// 00622ea0  eb0e                 jmp 0x622eb0
// 00622ea2  8b5004               mov edx, dword ptr [eax + 4]
// 00622ea5  3b02                 cmp eax, dword ptr [edx]
// 00622ea7  7504                 jne 0x622ead
// 00622ea9  890a                 mov dword ptr [edx], ecx
// 00622eab  eb03                 jmp 0x622eb0
// 00622ead  894a08               mov dword ptr [edx + 8], ecx
// 00622eb0  8901                 mov dword ptr [ecx], eax
// 00622eb2  894804               mov dword ptr [eax + 4], ecx
// 00622eb5  8b4e04               mov ecx, dword ptr [esi + 4]
// 00622eb8  80793400             cmp byte ptr [ecx + 0x34], 0
// 00622ebc  8d4604               lea eax, [esi + 4]
// 00622ebf  0f841bffffff         je 0x622de0
// 00622ec5  8b5718               mov edx, dword ptr [edi + 0x18]
// 00622ec8  8b4204               mov eax, dword ptr [edx + 4]
// 00622ecb  885834               mov byte ptr [eax + 0x34], bl
// 00622ece  8b442464             mov eax, dword ptr [esp + 0x64]
// 00622ed2  8b0f                 mov ecx, dword ptr [edi]
// 00622ed4  5e                   pop esi
// 00622ed5  896804               mov dword ptr [eax + 4], ebp
// 00622ed8  5d                   pop ebp
// 00622ed9  8908                 mov dword ptr [eax], ecx
// 00622edb  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00622edf  5b                   pop ebx
// 00622ee0  5f                   pop edi
// 00622ee1  64890d00000000       mov dword ptr fs:[0], ecx
// 00622ee8  83c450               add esp, 0x50
// 00622eeb  c21000               ret 0x10
// standard library map_int<pod36> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod36>
struct E { int v[9]; };
#include <map>
template class std::map<int, E>;
