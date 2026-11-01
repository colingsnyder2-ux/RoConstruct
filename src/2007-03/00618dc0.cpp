// from server: 100% by auto
// roc 2007-03 00618dc0  unit: seg_00610000  size: 696 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00618dc0
//
// 00618dc0  64a100000000         mov eax, dword ptr fs:[0]
// 00618dc6  6aff                 push -1
// 00618dc8  68926f7500           push 0x756f92
// 00618dcd  50                   push eax
// 00618dce  64892500000000       mov dword ptr fs:[0], esp
// 00618dd5  8b442418             mov eax, dword ptr [esp + 0x18]
// 00618dd9  83ec48               sub esp, 0x48
// 00618ddc  80780e00             cmp byte ptr [eax + 0xe], 0
// 00618de0  55                   push ebp
// 00618de1  8be9                 mov ebp, ecx
// 00618de3  7459                 je 0x618e3e
// 00618de5  68dc3e7800           push 0x783edc
// 00618dea  8d4c240c             lea ecx, [esp + 0xc]
// 00618dee  ff1578e77700         call dword ptr [0x77e778]
// 00618df4  8d4c2424             lea ecx, [esp + 0x24]
// 00618df8  c744245400000000     mov dword ptr [esp + 0x54], 0
// 00618e00  ff1560e97700         call dword ptr [0x77e960]
// 00618e06  8d442408             lea eax, [esp + 8]
// 00618e0a  50                   push eax
// 00618e0b  8d4c2434             lea ecx, [esp + 0x34]
// 00618e0f  c644245801           mov byte ptr [esp + 0x58], 1
// 00618e14  c7442428383e7800     mov dword ptr [esp + 0x28], 0x783e38
// 00618e1c  ff157ce77700         call dword ptr [0x77e77c]
// 00618e22  68ccf38300           push 0x83f3cc
// 00618e27  8d4c2428             lea ecx, [esp + 0x28]
// 00618e2b  51                   push ecx
// 00618e2c  c644245c00           mov byte ptr [esp + 0x5c], 0
// 00618e31  c744242c503e7800     mov dword ptr [esp + 0x2c], 0x783e50
// 00618e39  e8f0610000           call 0x61f02e
// 00618e3e  53                   push ebx
// 00618e3f  56                   push esi
// 00618e40  8bd8                 mov ebx, eax
// 00618e42  57                   push edi
// 00618e43  8d4c246c             lea ecx, [esp + 0x6c]
// 00618e47  895c2410             mov dword ptr [esp + 0x10], ebx
// 00618e4b  e8e0f7ffff           call 0x618630
// 00618e50  8b03                 mov eax, dword ptr [ebx]
// 00618e52  80780e00             cmp byte ptr [eax + 0xe], 0
// 00618e56  7405                 je 0x618e5d
// 00618e58  8b7b08               mov edi, dword ptr [ebx + 8]
// 00618e5b  eb18                 jmp 0x618e75
// 00618e5d  8b5308               mov edx, dword ptr [ebx + 8]
// 00618e60  807a0e00             cmp byte ptr [edx + 0xe], 0
// 00618e64  7404                 je 0x618e6a
// 00618e66  8bf8                 mov edi, eax
// 00618e68  eb0b                 jmp 0x618e75
// 00618e6a  8b4c2470             mov ecx, dword ptr [esp + 0x70]
// 00618e6e  3bcb                 cmp ecx, ebx
// 00618e70  8b7908               mov edi, dword ptr [ecx + 8]
// 00618e73  756b                 jne 0x618ee0
// 00618e75  807f0e00             cmp byte ptr [edi + 0xe], 0
// 00618e79  8b7304               mov esi, dword ptr [ebx + 4]
// 00618e7c  7503                 jne 0x618e81
// 00618e7e  897704               mov dword ptr [edi + 4], esi
// 00618e81  8b4504               mov eax, dword ptr [ebp + 4]
// 00618e84  395804               cmp dword ptr [eax + 4], ebx
// 00618e87  7505                 jne 0x618e8e
// 00618e89  897804               mov dword ptr [eax + 4], edi
// 00618e8c  eb0b                 jmp 0x618e99
// 00618e8e  391e                 cmp dword ptr [esi], ebx
// 00618e90  7504                 jne 0x618e96
// 00618e92  893e                 mov dword ptr [esi], edi
// 00618e94  eb03                 jmp 0x618e99
// 00618e96  897e08               mov dword ptr [esi + 8], edi
// 00618e99  8b5d04               mov ebx, dword ptr [ebp + 4]
// 00618e9c  8b03                 mov eax, dword ptr [ebx]
// 00618e9e  3b442410             cmp eax, dword ptr [esp + 0x10]
// 00618ea2  7515                 jne 0x618eb9
// 00618ea4  807f0e00             cmp byte ptr [edi + 0xe], 0
// 00618ea8  7404                 je 0x618eae
// 00618eaa  8bc6                 mov eax, esi
// 00618eac  eb09                 jmp 0x618eb7
// 00618eae  57                   push edi
// 00618eaf  e8fcf6ffff           call 0x6185b0
// 00618eb4  83c404               add esp, 4
// 00618eb7  8903                 mov dword ptr [ebx], eax
// 00618eb9  8b5d04               mov ebx, dword ptr [ebp + 4]
// 00618ebc  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00618ec0  394b08               cmp dword ptr [ebx + 8], ecx
// 00618ec3  7572                 jne 0x618f37
// 00618ec5  807f0e00             cmp byte ptr [edi + 0xe], 0
// 00618ec9  7407                 je 0x618ed2
// 00618ecb  8bc6                 mov eax, esi
// 00618ecd  894308               mov dword ptr [ebx + 8], eax
// 00618ed0  eb65                 jmp 0x618f37
// 00618ed2  57                   push edi
// 00618ed3  e8b8f6ffff           call 0x618590
// 00618ed8  83c404               add esp, 4
// 00618edb  894308               mov dword ptr [ebx + 8], eax
// 00618ede  eb57                 jmp 0x618f37
// 00618ee0  894804               mov dword ptr [eax + 4], ecx
// 00618ee3  8b13                 mov edx, dword ptr [ebx]
// 00618ee5  8911                 mov dword ptr [ecx], edx
// 00618ee7  3b4b08               cmp ecx, dword ptr [ebx + 8]
// 00618eea  7504                 jne 0x618ef0
// 00618eec  8bf1                 mov esi, ecx
// 00618eee  eb1a                 jmp 0x618f0a
// 00618ef0  807f0e00             cmp byte ptr [edi + 0xe], 0
// 00618ef4  8b7104               mov esi, dword ptr [ecx + 4]
// 00618ef7  7503                 jne 0x618efc
// 00618ef9  897704               mov dword ptr [edi + 4], esi
// 00618efc  893e                 mov dword ptr [esi], edi
// 00618efe  8b4308               mov eax, dword ptr [ebx + 8]
// 00618f01  894108               mov dword ptr [ecx + 8], eax
// 00618f04  8b5308               mov edx, dword ptr [ebx + 8]
// 00618f07  894a04               mov dword ptr [edx + 4], ecx
// 00618f0a  8b4504               mov eax, dword ptr [ebp + 4]
// 00618f0d  395804               cmp dword ptr [eax + 4], ebx
// 00618f10  7505                 jne 0x618f17
// 00618f12  894804               mov dword ptr [eax + 4], ecx
// 00618f15  eb0e                 jmp 0x618f25
// 00618f17  8b4304               mov eax, dword ptr [ebx + 4]
// 00618f1a  3918                 cmp dword ptr [eax], ebx
// 00618f1c  7504                 jne 0x618f22
// 00618f1e  8908                 mov dword ptr [eax], ecx
// 00618f20  eb03                 jmp 0x618f25
// 00618f22  894808               mov dword ptr [eax + 8], ecx
// 00618f25  8b4304               mov eax, dword ptr [ebx + 4]
// 00618f28  894104               mov dword ptr [ecx + 4], eax
// 00618f2b  8a530d               mov dl, byte ptr [ebx + 0xd]
// 00618f2e  8a410d               mov al, byte ptr [ecx + 0xd]
// 00618f31  88510d               mov byte ptr [ecx + 0xd], dl
// 00618f34  88430d               mov byte ptr [ebx + 0xd], al
// 00618f37  8b442410             mov eax, dword ptr [esp + 0x10]
// 00618f3b  b301                 mov bl, 1
// 00618f3d  38580d               cmp byte ptr [eax + 0xd], bl
// 00618f40  0f85f2000000         jne 0x619038
// 00618f46  8b4d04               mov ecx, dword ptr [ebp + 4]
// 00618f49  3b7904               cmp edi, dword ptr [ecx + 4]
// 00618f4c  0f84e3000000         je 0x619035
// 00618f52  385f0d               cmp byte ptr [edi + 0xd], bl
// 00618f55  0f85da000000         jne 0x619035
// 00618f5b  8b06                 mov eax, dword ptr [esi]
// 00618f5d  3bf8                 cmp edi, eax
// 00618f5f  7563                 jne 0x618fc4
// 00618f61  8b4608               mov eax, dword ptr [esi + 8]
// 00618f64  80780d00             cmp byte ptr [eax + 0xd], 0
// 00618f68  7512                 jne 0x618f7c
// 00618f6a  88580d               mov byte ptr [eax + 0xd], bl
// 00618f6d  56                   push esi
// 00618f6e  8bcd                 mov ecx, ebp
// 00618f70  c6460d00             mov byte ptr [esi + 0xd], 0
// 00618f74  e807f8ffff           call 0x618780
// 00618f79  8b4608               mov eax, dword ptr [esi + 8]
// 00618f7c  80780e00             cmp byte ptr [eax + 0xe], 0
// 00618f80  7572                 jne 0x618ff4
// 00618f82  8b10                 mov edx, dword ptr [eax]
// 00618f84  385a0d               cmp byte ptr [edx + 0xd], bl
// 00618f87  7508                 jne 0x618f91
// 00618f89  8b4808               mov ecx, dword ptr [eax + 8]
// 00618f8c  38590d               cmp byte ptr [ecx + 0xd], bl
// 00618f8f  745f                 je 0x618ff0
// 00618f91  8b4808               mov ecx, dword ptr [eax + 8]
// 00618f94  38590d               cmp byte ptr [ecx + 0xd], bl
// 00618f97  7512                 jne 0x618fab
// 00618f99  885a0d               mov byte ptr [edx + 0xd], bl
// 00618f9c  50                   push eax
// 00618f9d  8bcd                 mov ecx, ebp
// 00618f9f  c6400d00             mov byte ptr [eax + 0xd], 0
// 00618fa3  e828f6ffff           call 0x6185d0
// 00618fa8  8b4608               mov eax, dword ptr [esi + 8]
// 00618fab  8a4e0d               mov cl, byte ptr [esi + 0xd]
// 00618fae  88480d               mov byte ptr [eax + 0xd], cl
// 00618fb1  885e0d               mov byte ptr [esi + 0xd], bl
// 00618fb4  8b5008               mov edx, dword ptr [eax + 8]
// 00618fb7  56                   push esi
// 00618fb8  8bcd                 mov ecx, ebp
// 00618fba  885a0d               mov byte ptr [edx + 0xd], bl
// 00618fbd  e8bef7ffff           call 0x618780
// 00618fc2  eb71                 jmp 0x619035
// 00618fc4  80780d00             cmp byte ptr [eax + 0xd], 0
// 00618fc8  7511                 jne 0x618fdb
// 00618fca  88580d               mov byte ptr [eax + 0xd], bl
// 00618fcd  56                   push esi
// 00618fce  8bcd                 mov ecx, ebp
// 00618fd0  c6460d00             mov byte ptr [esi + 0xd], 0
// 00618fd4  e8f7f5ffff           call 0x6185d0
// 00618fd9  8b06                 mov eax, dword ptr [esi]
// 00618fdb  80780e00             cmp byte ptr [eax + 0xe], 0
// 00618fdf  7513                 jne 0x618ff4
// 00618fe1  8b5008               mov edx, dword ptr [eax + 8]
// 00618fe4  385a0d               cmp byte ptr [edx + 0xd], bl
// 00618fe7  751e                 jne 0x619007
// 00618fe9  8b08                 mov ecx, dword ptr [eax]
// 00618feb  38590d               cmp byte ptr [ecx + 0xd], bl
// 00618fee  7517                 jne 0x619007
// 00618ff0  c6400d00             mov byte ptr [eax + 0xd], 0
// 00618ff4  8b5504               mov edx, dword ptr [ebp + 4]
// 00618ff7  8bfe                 mov edi, esi
// 00618ff9  3b7a04               cmp edi, dword ptr [edx + 4]
// 00618ffc  8b7604               mov esi, dword ptr [esi + 4]
// 00618fff  0f854dffffff         jne 0x618f52
// 00619005  eb2e                 jmp 0x619035
// 00619007  8b08                 mov ecx, dword ptr [eax]
// 00619009  38590d               cmp byte ptr [ecx + 0xd], bl
// 0061900c  7511                 jne 0x61901f
// 0061900e  885a0d               mov byte ptr [edx + 0xd], bl
// 00619011  50                   push eax
// 00619012  8bcd                 mov ecx, ebp
// 00619014  c6400d00             mov byte ptr [eax + 0xd], 0
// 00619018  e863f7ffff           call 0x618780
// 0061901d  8b06                 mov eax, dword ptr [esi]
// 0061901f  8a4e0d               mov cl, byte ptr [esi + 0xd]
// 00619022  88480d               mov byte ptr [eax + 0xd], cl
// 00619025  885e0d               mov byte ptr [esi + 0xd], bl
// 00619028  8b10                 mov edx, dword ptr [eax]
// 0061902a  56                   push esi
// 0061902b  8bcd                 mov ecx, ebp
// 0061902d  885a0d               mov byte ptr [edx + 0xd], bl
// 00619030  e89bf5ffff           call 0x6185d0
// 00619035  885f0d               mov byte ptr [edi + 0xd], bl
// 00619038  8b442410             mov eax, dword ptr [esp + 0x10]
// 0061903c  50                   push eax
// 0061903d  e8ae500000           call 0x61e0f0
// 00619042  8b4508               mov eax, dword ptr [ebp + 8]
// 00619045  83c404               add esp, 4
// 00619048  85c0                 test eax, eax
// 0061904a  5f                   pop edi
// 0061904b  5e                   pop esi
// 0061904c  5b                   pop ebx
// 0061904d  7606                 jbe 0x619055
// 0061904f  83c0ff               add eax, -1
// 00619052  894508               mov dword ptr [ebp + 8], eax
// 00619055  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 00619059  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 0061905d  8b542464             mov edx, dword ptr [esp + 0x64]
// 00619061  8908                 mov dword ptr [eax], ecx
// 00619063  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00619067  895004               mov dword ptr [eax + 4], edx
// 0061906a  5d                   pop ebp
// 0061906b  64890d00000000       mov dword ptr fs:[0], ecx
// 00619072  83c454               add esp, 0x54
// 00619075  c20c00               ret 0xc
// standard library set<char> (function ?erase@?$_Tree@V?$_Tset_traits@DU?$less@D@std@@V?$allocator@D@2@$0A@@std@@@std@@QAE?AViterator@12@V312@@Z)

// stl: set<char>
typedef char E;
#include <set>
template class std::set<E>;
