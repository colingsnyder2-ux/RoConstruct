// from server: 100% by auto
// roc 2010-06 0052ef50  unit: RBX::VAggregateChunk::?$WeakReferenceCountedPointer  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0052ef50
//
// 0052ef50  64a100000000         mov eax, dword ptr fs:[0]
// 0052ef56  6aff                 push -1
// 0052ef58  68e22f9a00           push 0x9a2fe2
// 0052ef5d  50                   push eax
// 0052ef5e  64892500000000       mov dword ptr fs:[0], esp
// 0052ef65  83ec44               sub esp, 0x44
// 0052ef68  57                   push edi
// 0052ef69  8bf9                 mov edi, ecx
// 0052ef6b  817f1ccbcccc0c       cmp dword ptr [edi + 0x1c], 0xccccccb
// 0052ef72  7259                 jb 0x52efcd
// 0052ef74  68a800a000           push 0xa000a8
// 0052ef79  8d4c2408             lea ecx, [esp + 8]
// 0052ef7d  ff1510a49e00         call dword ptr [0x9ea410]
// 0052ef83  8d4c2420             lea ecx, [esp + 0x20]
// 0052ef87  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0052ef8f  ff1518a99e00         call dword ptr [0x9ea918]
// 0052ef95  8d442404             lea eax, [esp + 4]
// 0052ef99  50                   push eax
// 0052ef9a  8d4c2430             lea ecx, [esp + 0x30]
// 0052ef9e  c644245401           mov byte ptr [esp + 0x54], 1
// 0052efa3  c74424242c00a000     mov dword ptr [esp + 0x24], 0xa0002c
// 0052efab  ff150ca49e00         call dword ptr [0x9ea40c]
// 0052efb1  68601bb000           push 0xb01b60
// 0052efb6  8d4c2424             lea ecx, [esp + 0x24]
// 0052efba  51                   push ecx
// 0052efbb  c644245800           mov byte ptr [esp + 0x58], 0
// 0052efc0  c74424283800a000     mov dword ptr [esp + 0x28], 0xa00038
// 0052efc8  e8e5992700           call 0x7a89b2
// 0052efcd  8b542464             mov edx, dword ptr [esp + 0x64]
// 0052efd1  8b4718               mov eax, dword ptr [edi + 0x18]
// 0052efd4  53                   push ebx
// 0052efd5  55                   push ebp
// 0052efd6  56                   push esi
// 0052efd7  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0052efdb  6a00                 push 0
// 0052efdd  52                   push edx
// 0052efde  50                   push eax
// 0052efdf  56                   push esi
// 0052efe0  50                   push eax
// 0052efe1  e85afaffff           call 0x52ea40
// 0052efe6  8be8                 mov ebp, eax
// 0052efe8  8b4718               mov eax, dword ptr [edi + 0x18]
// 0052efeb  bb01000000           mov ebx, 1
// 0052eff0  015f1c               add dword ptr [edi + 0x1c], ebx
// 0052eff3  3bf0                 cmp esi, eax
// 0052eff5  7510                 jne 0x52f007
// 0052eff7  896804               mov dword ptr [eax + 4], ebp
// 0052effa  8b4718               mov eax, dword ptr [edi + 0x18]
// 0052effd  8928                 mov dword ptr [eax], ebp
// 0052efff  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 0052f002  896908               mov dword ptr [ecx + 8], ebp
// 0052f005  eb22                 jmp 0x52f029
// 0052f007  807c246800           cmp byte ptr [esp + 0x68], 0
// 0052f00c  740d                 je 0x52f01b
// 0052f00e  892e                 mov dword ptr [esi], ebp
// 0052f010  8b4718               mov eax, dword ptr [edi + 0x18]
// 0052f013  3b30                 cmp esi, dword ptr [eax]
// 0052f015  7512                 jne 0x52f029
// 0052f017  8928                 mov dword ptr [eax], ebp
// 0052f019  eb0e                 jmp 0x52f029
// 0052f01b  896e08               mov dword ptr [esi + 8], ebp
// 0052f01e  8b4718               mov eax, dword ptr [edi + 0x18]
// 0052f021  3b7008               cmp esi, dword ptr [eax + 8]
// 0052f024  7503                 jne 0x52f029
// 0052f026  896808               mov dword ptr [eax + 8], ebp
// 0052f029  8b5504               mov edx, dword ptr [ebp + 4]
// 0052f02c  807a2000             cmp byte ptr [edx + 0x20], 0
// 0052f030  8d4504               lea eax, [ebp + 4]
// 0052f033  8bf5                 mov esi, ebp
// 0052f035  0f85ea000000         jne 0x52f125
// 0052f03b  eb03                 jmp 0x52f040
// 0052f03d  8d4900               lea ecx, [ecx]
// 0052f040  8b08                 mov ecx, dword ptr [eax]
// 0052f042  8b5104               mov edx, dword ptr [ecx + 4]
// 0052f045  3b0a                 cmp ecx, dword ptr [edx]
// 0052f047  7551                 jne 0x52f09a
// 0052f049  8b5208               mov edx, dword ptr [edx + 8]
// 0052f04c  807a2000             cmp byte ptr [edx + 0x20], 0
// 0052f050  7519                 jne 0x52f06b
// 0052f052  885920               mov byte ptr [ecx + 0x20], bl
// 0052f055  885a20               mov byte ptr [edx + 0x20], bl
// 0052f058  8b10                 mov edx, dword ptr [eax]
// 0052f05a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0052f05d  c6412000             mov byte ptr [ecx + 0x20], 0
// 0052f061  8b10                 mov edx, dword ptr [eax]
// 0052f063  8b7204               mov esi, dword ptr [edx + 4]
// 0052f066  e9aa000000           jmp 0x52f115
// 0052f06b  3b7108               cmp esi, dword ptr [ecx + 8]
// 0052f06e  750a                 jne 0x52f07a
// 0052f070  8bf1                 mov esi, ecx
// 0052f072  56                   push esi
// 0052f073  8bcf                 mov ecx, edi
// 0052f075  e836e0ffff           call 0x52d0b0
// 0052f07a  8b4604               mov eax, dword ptr [esi + 4]
// 0052f07d  885820               mov byte ptr [eax + 0x20], bl
// 0052f080  8b4e04               mov ecx, dword ptr [esi + 4]
// 0052f083  8b5104               mov edx, dword ptr [ecx + 4]
// 0052f086  c6422000             mov byte ptr [edx + 0x20], 0
// 0052f08a  8b4604               mov eax, dword ptr [esi + 4]
// 0052f08d  8b4804               mov ecx, dword ptr [eax + 4]
// 0052f090  51                   push ecx
// 0052f091  8bcf                 mov ecx, edi
// 0052f093  e808c00e00           call 0x61b0a0
// 0052f098  eb7b                 jmp 0x52f115
// 0052f09a  8b12                 mov edx, dword ptr [edx]
// 0052f09c  807a2000             cmp byte ptr [edx + 0x20], 0
// 0052f0a0  7516                 jne 0x52f0b8
// 0052f0a2  885920               mov byte ptr [ecx + 0x20], bl
// 0052f0a5  885a20               mov byte ptr [edx + 0x20], bl
// 0052f0a8  8b10                 mov edx, dword ptr [eax]
// 0052f0aa  8b4a04               mov ecx, dword ptr [edx + 4]
// 0052f0ad  c6412000             mov byte ptr [ecx + 0x20], 0
// 0052f0b1  8b10                 mov edx, dword ptr [eax]
// 0052f0b3  8b7204               mov esi, dword ptr [edx + 4]
// 0052f0b6  eb5d                 jmp 0x52f115
// 0052f0b8  3b31                 cmp esi, dword ptr [ecx]
// 0052f0ba  750a                 jne 0x52f0c6
// 0052f0bc  8bf1                 mov esi, ecx
// 0052f0be  56                   push esi
// 0052f0bf  8bcf                 mov ecx, edi
// 0052f0c1  e8dabf0e00           call 0x61b0a0
// 0052f0c6  8b4604               mov eax, dword ptr [esi + 4]
// 0052f0c9  885820               mov byte ptr [eax + 0x20], bl
// 0052f0cc  8b4e04               mov ecx, dword ptr [esi + 4]
// 0052f0cf  8b5104               mov edx, dword ptr [ecx + 4]
// 0052f0d2  c6422000             mov byte ptr [edx + 0x20], 0
// 0052f0d6  8b4604               mov eax, dword ptr [esi + 4]
// 0052f0d9  8b4004               mov eax, dword ptr [eax + 4]
// 0052f0dc  8b4808               mov ecx, dword ptr [eax + 8]
// 0052f0df  8b11                 mov edx, dword ptr [ecx]
// 0052f0e1  895008               mov dword ptr [eax + 8], edx
// 0052f0e4  8b11                 mov edx, dword ptr [ecx]
// 0052f0e6  807a2100             cmp byte ptr [edx + 0x21], 0
// 0052f0ea  7503                 jne 0x52f0ef
// 0052f0ec  894204               mov dword ptr [edx + 4], eax
// 0052f0ef  8b5004               mov edx, dword ptr [eax + 4]
// 0052f0f2  895104               mov dword ptr [ecx + 4], edx
// 0052f0f5  8b5718               mov edx, dword ptr [edi + 0x18]
// 0052f0f8  3b4204               cmp eax, dword ptr [edx + 4]
// 0052f0fb  7505                 jne 0x52f102
// 0052f0fd  894a04               mov dword ptr [edx + 4], ecx
// 0052f100  eb0e                 jmp 0x52f110
// 0052f102  8b5004               mov edx, dword ptr [eax + 4]
// 0052f105  3b02                 cmp eax, dword ptr [edx]
// 0052f107  7504                 jne 0x52f10d
// 0052f109  890a                 mov dword ptr [edx], ecx
// 0052f10b  eb03                 jmp 0x52f110
// 0052f10d  894a08               mov dword ptr [edx + 8], ecx
// 0052f110  8901                 mov dword ptr [ecx], eax
// 0052f112  894804               mov dword ptr [eax + 4], ecx
// 0052f115  8b4e04               mov ecx, dword ptr [esi + 4]
// 0052f118  80792000             cmp byte ptr [ecx + 0x20], 0
// 0052f11c  8d4604               lea eax, [esi + 4]
// 0052f11f  0f841bffffff         je 0x52f040
// 0052f125  8b5718               mov edx, dword ptr [edi + 0x18]
// 0052f128  8b4204               mov eax, dword ptr [edx + 4]
// 0052f12b  885820               mov byte ptr [eax + 0x20], bl
// 0052f12e  8b442464             mov eax, dword ptr [esp + 0x64]
// 0052f132  8b0f                 mov ecx, dword ptr [edi]
// 0052f134  5e                   pop esi
// 0052f135  896804               mov dword ptr [eax + 4], ebp
// 0052f138  5d                   pop ebp
// 0052f139  8908                 mov dword ptr [eax], ecx
// 0052f13b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0052f13f  5b                   pop ebx
// 0052f140  5f                   pop edi
// 0052f141  64890d00000000       mov dword ptr fs:[0], ecx
// 0052f148  83c450               add esp, 0x50
// 0052f14b  c21000               ret 0x10
// standard library map_int<pod16> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod16>
struct E { int v[4]; };
#include <map>
template class std::map<int, E>;
