// from server: 100% by auto
// roc 2008-06 005b3d30  unit: RBX::VHat::?$FactoryProduct  size: 470 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005b3d30
//
// 005b3d30  83ec14               sub esp, 0x14
// 005b3d33  56                   push esi
// 005b3d34  8bf1                 mov esi, ecx
// 005b3d36  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 005b3d3a  57                   push edi
// 005b3d3b  7521                 jne 0x5b3d5e
// 005b3d3d  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 005b3d41  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 005b3d44  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005b3d48  50                   push eax
// 005b3d49  51                   push ecx
// 005b3d4a  6a01                 push 1
// 005b3d4c  57                   push edi
// 005b3d4d  8bce                 mov ecx, esi
// 005b3d4f  e84cf3ffff           call 0x5b30a0
// 005b3d54  8bc7                 mov eax, edi
// 005b3d56  5f                   pop edi
// 005b3d57  5e                   pop esi
// 005b3d58  83c414               add esp, 0x14
// 005b3d5b  c21000               ret 0x10
// 005b3d5e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 005b3d62  8b5618               mov edx, dword ptr [esi + 0x18]
// 005b3d65  8b3a                 mov edi, dword ptr [edx]
// 005b3d67  8b06                 mov eax, dword ptr [esi]
// 005b3d69  53                   push ebx
// 005b3d6a  8b1d90288000         mov ebx, dword ptr [0x802890]
// 005b3d70  85c9                 test ecx, ecx
// 005b3d72  7404                 je 0x5b3d78
// 005b3d74  3bc8                 cmp ecx, eax
// 005b3d76  7406                 je 0x5b3d7e
// 005b3d78  ffd3                 call ebx
// 005b3d7a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005b3d7e  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 005b3d82  3bc7                 cmp eax, edi
// 005b3d84  752a                 jne 0x5b3db0
// 005b3d86  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 005b3d8a  8b0f                 mov ecx, dword ptr [edi]
// 005b3d8c  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 005b3d8f  0f8d4b010000         jge 0x5b3ee0
// 005b3d95  57                   push edi
// 005b3d96  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 005b3d9a  50                   push eax
// 005b3d9b  6a01                 push 1
// 005b3d9d  57                   push edi
// 005b3d9e  8bce                 mov ecx, esi
// 005b3da0  e8fbf2ffff           call 0x5b30a0
// 005b3da5  5b                   pop ebx
// 005b3da6  8bc7                 mov eax, edi
// 005b3da8  5f                   pop edi
// 005b3da9  5e                   pop esi
// 005b3daa  83c414               add esp, 0x14
// 005b3dad  c21000               ret 0x10
// 005b3db0  8b7e18               mov edi, dword ptr [esi + 0x18]
// 005b3db3  8b16                 mov edx, dword ptr [esi]
// 005b3db5  85c9                 test ecx, ecx
// 005b3db7  7404                 je 0x5b3dbd
// 005b3db9  3bca                 cmp ecx, edx
// 005b3dbb  740a                 je 0x5b3dc7
// 005b3dbd  ffd3                 call ebx
// 005b3dbf  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 005b3dc3  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005b3dc7  3bc7                 cmp eax, edi
// 005b3dc9  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 005b3dcd  752c                 jne 0x5b3dfb
// 005b3dcf  8b5618               mov edx, dword ptr [esi + 0x18]
// 005b3dd2  8b4208               mov eax, dword ptr [edx + 8]
// 005b3dd5  8b480c               mov ecx, dword ptr [eax + 0xc]
// 005b3dd8  3b0f                 cmp ecx, dword ptr [edi]
// 005b3dda  0f8d00010000         jge 0x5b3ee0
// 005b3de0  57                   push edi
// 005b3de1  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 005b3de5  50                   push eax
// 005b3de6  6a00                 push 0
// 005b3de8  57                   push edi
// 005b3de9  8bce                 mov ecx, esi
// 005b3deb  e8b0f2ffff           call 0x5b30a0
// 005b3df0  5b                   pop ebx
// 005b3df1  8bc7                 mov eax, edi
// 005b3df3  5f                   pop edi
// 005b3df4  5e                   pop esi
// 005b3df5  83c414               add esp, 0x14
// 005b3df8  c21000               ret 0x10
// 005b3dfb  8b17                 mov edx, dword ptr [edi]
// 005b3dfd  39500c               cmp dword ptr [eax + 0xc], edx
// 005b3e00  7e63                 jle 0x5b3e65
// 005b3e02  894c240c             mov dword ptr [esp + 0xc], ecx
// 005b3e06  8d4c240c             lea ecx, [esp + 0xc]
// 005b3e0a  89442410             mov dword ptr [esp + 0x10], eax
// 005b3e0e  e85d24f3ff           call 0x4e6270
// 005b3e13  8b17                 mov edx, dword ptr [edi]
// 005b3e15  8b442410             mov eax, dword ptr [esp + 0x10]
// 005b3e19  39500c               cmp dword ptr [eax + 0xc], edx
// 005b3e1c  7d3c                 jge 0x5b3e5a
// 005b3e1e  8b5008               mov edx, dword ptr [eax + 8]
// 005b3e21  807a2100             cmp byte ptr [edx + 0x21], 0
// 005b3e25  57                   push edi
// 005b3e26  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 005b3e2a  8bce                 mov ecx, esi
// 005b3e2c  7414                 je 0x5b3e42
// 005b3e2e  50                   push eax
// 005b3e2f  6a00                 push 0
// 005b3e31  57                   push edi
// 005b3e32  e869f2ffff           call 0x5b30a0
// 005b3e37  5b                   pop ebx
// 005b3e38  8bc7                 mov eax, edi
// 005b3e3a  5f                   pop edi
// 005b3e3b  5e                   pop esi
// 005b3e3c  83c414               add esp, 0x14
// 005b3e3f  c21000               ret 0x10
// 005b3e42  8b442430             mov eax, dword ptr [esp + 0x30]
// 005b3e46  50                   push eax
// 005b3e47  6a01                 push 1
// 005b3e49  57                   push edi
// 005b3e4a  e851f2ffff           call 0x5b30a0
// 005b3e4f  5b                   pop ebx
// 005b3e50  8bc7                 mov eax, edi
// 005b3e52  5f                   pop edi
// 005b3e53  5e                   pop esi
// 005b3e54  83c414               add esp, 0x14
// 005b3e57  c21000               ret 0x10
// 005b3e5a  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 005b3e5e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005b3e62  39500c               cmp dword ptr [eax + 0xc], edx
// 005b3e65  7d79                 jge 0x5b3ee0
// 005b3e67  8b16                 mov edx, dword ptr [esi]
// 005b3e69  894c240c             mov dword ptr [esp + 0xc], ecx
// 005b3e6d  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 005b3e70  894c2418             mov dword ptr [esp + 0x18], ecx
// 005b3e74  8d4c240c             lea ecx, [esp + 0xc]
// 005b3e78  89442410             mov dword ptr [esp + 0x10], eax
// 005b3e7c  89542414             mov dword ptr [esp + 0x14], edx
// 005b3e80  e8bb33f2ff           call 0x4d7240
// 005b3e85  8d442414             lea eax, [esp + 0x14]
// 005b3e89  50                   push eax
// 005b3e8a  8d4c2410             lea ecx, [esp + 0x10]
// 005b3e8e  e80d8e0300           call 0x5ecca0
// 005b3e93  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005b3e97  84c0                 test al, al
// 005b3e99  7507                 jne 0x5b3ea2
// 005b3e9b  8b17                 mov edx, dword ptr [edi]
// 005b3e9d  3b510c               cmp edx, dword ptr [ecx + 0xc]
// 005b3ea0  7d3e                 jge 0x5b3ee0
// 005b3ea2  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 005b3ea6  8b5008               mov edx, dword ptr [eax + 8]
// 005b3ea9  807a2100             cmp byte ptr [edx + 0x21], 0
// 005b3ead  57                   push edi
// 005b3eae  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 005b3eb2  7416                 je 0x5b3eca
// 005b3eb4  50                   push eax
// 005b3eb5  6a00                 push 0
// 005b3eb7  57                   push edi
// 005b3eb8  8bce                 mov ecx, esi
// 005b3eba  e8e1f1ffff           call 0x5b30a0
// 005b3ebf  5b                   pop ebx
// 005b3ec0  8bc7                 mov eax, edi
// 005b3ec2  5f                   pop edi
// 005b3ec3  5e                   pop esi
// 005b3ec4  83c414               add esp, 0x14
// 005b3ec7  c21000               ret 0x10
// 005b3eca  51                   push ecx
// 005b3ecb  6a01                 push 1
// 005b3ecd  57                   push edi
// 005b3ece  8bce                 mov ecx, esi
// 005b3ed0  e8cbf1ffff           call 0x5b30a0
// 005b3ed5  5b                   pop ebx
// 005b3ed6  8bc7                 mov eax, edi
// 005b3ed8  5f                   pop edi
// 005b3ed9  5e                   pop esi
// 005b3eda  83c414               add esp, 0x14
// 005b3edd  c21000               ret 0x10
// 005b3ee0  57                   push edi
// 005b3ee1  8d442418             lea eax, [esp + 0x18]
// 005b3ee5  50                   push eax
// 005b3ee6  8bce                 mov ecx, esi
// 005b3ee8  e833fbffff           call 0x5b3a20
// 005b3eed  8b10                 mov edx, dword ptr [eax]
// 005b3eef  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 005b3ef3  5b                   pop ebx
// 005b3ef4  8911                 mov dword ptr [ecx], edx
// 005b3ef6  8b4004               mov eax, dword ptr [eax + 4]
// 005b3ef9  5f                   pop edi
// 005b3efa  894104               mov dword ptr [ecx + 4], eax
// 005b3efd  8bc1                 mov eax, ecx
// 005b3eff  5e                   pop esi
// 005b3f00  83c414               add esp, 0x14
// 005b3f03  c21000               ret 0x10
// standard library map_int<pod16> (function ?insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod16>
struct E { int v[4]; };
#include <map>
template class std::map<int, E>;
