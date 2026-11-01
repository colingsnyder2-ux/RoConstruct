// from server: 100% by auto
// roc 2009-12 006f9de0  unit: RBX::Network::VPlayer::?$RemoteEventDesc  size: 470 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006f9de0
//
// 006f9de0  83ec14               sub esp, 0x14
// 006f9de3  56                   push esi
// 006f9de4  8bf1                 mov esi, ecx
// 006f9de6  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 006f9dea  57                   push edi
// 006f9deb  7521                 jne 0x6f9e0e
// 006f9ded  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 006f9df1  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006f9df4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006f9df8  50                   push eax
// 006f9df9  51                   push ecx
// 006f9dfa  6a01                 push 1
// 006f9dfc  57                   push edi
// 006f9dfd  8bce                 mov ecx, esi
// 006f9dff  e82cf0ffff           call 0x6f8e30
// 006f9e04  8bc7                 mov eax, edi
// 006f9e06  5f                   pop edi
// 006f9e07  5e                   pop esi
// 006f9e08  83c414               add esp, 0x14
// 006f9e0b  c21000               ret 0x10
// 006f9e0e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 006f9e12  8b5618               mov edx, dword ptr [esi + 0x18]
// 006f9e15  8b3a                 mov edi, dword ptr [edx]
// 006f9e17  8b06                 mov eax, dword ptr [esi]
// 006f9e19  53                   push ebx
// 006f9e1a  8b1d60b79800         mov ebx, dword ptr [0x98b760]
// 006f9e20  85c9                 test ecx, ecx
// 006f9e22  7404                 je 0x6f9e28
// 006f9e24  3bc8                 cmp ecx, eax
// 006f9e26  7406                 je 0x6f9e2e
// 006f9e28  ffd3                 call ebx
// 006f9e2a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006f9e2e  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 006f9e32  3bc7                 cmp eax, edi
// 006f9e34  752a                 jne 0x6f9e60
// 006f9e36  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 006f9e3a  8b0f                 mov ecx, dword ptr [edi]
// 006f9e3c  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 006f9e3f  0f8d4b010000         jge 0x6f9f90
// 006f9e45  57                   push edi
// 006f9e46  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 006f9e4a  50                   push eax
// 006f9e4b  6a01                 push 1
// 006f9e4d  57                   push edi
// 006f9e4e  8bce                 mov ecx, esi
// 006f9e50  e8dbefffff           call 0x6f8e30
// 006f9e55  5b                   pop ebx
// 006f9e56  8bc7                 mov eax, edi
// 006f9e58  5f                   pop edi
// 006f9e59  5e                   pop esi
// 006f9e5a  83c414               add esp, 0x14
// 006f9e5d  c21000               ret 0x10
// 006f9e60  8b7e18               mov edi, dword ptr [esi + 0x18]
// 006f9e63  8b16                 mov edx, dword ptr [esi]
// 006f9e65  85c9                 test ecx, ecx
// 006f9e67  7404                 je 0x6f9e6d
// 006f9e69  3bca                 cmp ecx, edx
// 006f9e6b  740a                 je 0x6f9e77
// 006f9e6d  ffd3                 call ebx
// 006f9e6f  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 006f9e73  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006f9e77  3bc7                 cmp eax, edi
// 006f9e79  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 006f9e7d  752c                 jne 0x6f9eab
// 006f9e7f  8b5618               mov edx, dword ptr [esi + 0x18]
// 006f9e82  8b4208               mov eax, dword ptr [edx + 8]
// 006f9e85  8b480c               mov ecx, dword ptr [eax + 0xc]
// 006f9e88  3b0f                 cmp ecx, dword ptr [edi]
// 006f9e8a  0f8d00010000         jge 0x6f9f90
// 006f9e90  57                   push edi
// 006f9e91  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 006f9e95  50                   push eax
// 006f9e96  6a00                 push 0
// 006f9e98  57                   push edi
// 006f9e99  8bce                 mov ecx, esi
// 006f9e9b  e890efffff           call 0x6f8e30
// 006f9ea0  5b                   pop ebx
// 006f9ea1  8bc7                 mov eax, edi
// 006f9ea3  5f                   pop edi
// 006f9ea4  5e                   pop esi
// 006f9ea5  83c414               add esp, 0x14
// 006f9ea8  c21000               ret 0x10
// 006f9eab  8b17                 mov edx, dword ptr [edi]
// 006f9ead  39500c               cmp dword ptr [eax + 0xc], edx
// 006f9eb0  7e63                 jle 0x6f9f15
// 006f9eb2  894c240c             mov dword ptr [esp + 0xc], ecx
// 006f9eb6  8d4c240c             lea ecx, [esp + 0xc]
// 006f9eba  89442410             mov dword ptr [esp + 0x10], eax
// 006f9ebe  e89d99e1ff           call 0x513860
// 006f9ec3  8b17                 mov edx, dword ptr [edi]
// 006f9ec5  8b442410             mov eax, dword ptr [esp + 0x10]
// 006f9ec9  39500c               cmp dword ptr [eax + 0xc], edx
// 006f9ecc  7d3c                 jge 0x6f9f0a
// 006f9ece  8b5008               mov edx, dword ptr [eax + 8]
// 006f9ed1  807a3100             cmp byte ptr [edx + 0x31], 0
// 006f9ed5  57                   push edi
// 006f9ed6  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 006f9eda  8bce                 mov ecx, esi
// 006f9edc  7414                 je 0x6f9ef2
// 006f9ede  50                   push eax
// 006f9edf  6a00                 push 0
// 006f9ee1  57                   push edi
// 006f9ee2  e849efffff           call 0x6f8e30
// 006f9ee7  5b                   pop ebx
// 006f9ee8  8bc7                 mov eax, edi
// 006f9eea  5f                   pop edi
// 006f9eeb  5e                   pop esi
// 006f9eec  83c414               add esp, 0x14
// 006f9eef  c21000               ret 0x10
// 006f9ef2  8b442430             mov eax, dword ptr [esp + 0x30]
// 006f9ef6  50                   push eax
// 006f9ef7  6a01                 push 1
// 006f9ef9  57                   push edi
// 006f9efa  e831efffff           call 0x6f8e30
// 006f9eff  5b                   pop ebx
// 006f9f00  8bc7                 mov eax, edi
// 006f9f02  5f                   pop edi
// 006f9f03  5e                   pop esi
// 006f9f04  83c414               add esp, 0x14
// 006f9f07  c21000               ret 0x10
// 006f9f0a  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 006f9f0e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006f9f12  39500c               cmp dword ptr [eax + 0xc], edx
// 006f9f15  7d79                 jge 0x6f9f90
// 006f9f17  8b16                 mov edx, dword ptr [esi]
// 006f9f19  894c240c             mov dword ptr [esp + 0xc], ecx
// 006f9f1d  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006f9f20  894c2418             mov dword ptr [esp + 0x18], ecx
// 006f9f24  8d4c240c             lea ecx, [esp + 0xc]
// 006f9f28  89442410             mov dword ptr [esp + 0x10], eax
// 006f9f2c  89542414             mov dword ptr [esp + 0x14], edx
// 006f9f30  e8bb99e1ff           call 0x5138f0
// 006f9f35  8d442414             lea eax, [esp + 0x14]
// 006f9f39  50                   push eax
// 006f9f3a  8d4c2410             lea ecx, [esp + 0x10]
// 006f9f3e  e81d24edff           call 0x5cc360
// 006f9f43  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006f9f47  84c0                 test al, al
// 006f9f49  7507                 jne 0x6f9f52
// 006f9f4b  8b17                 mov edx, dword ptr [edi]
// 006f9f4d  3b510c               cmp edx, dword ptr [ecx + 0xc]
// 006f9f50  7d3e                 jge 0x6f9f90
// 006f9f52  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 006f9f56  8b5008               mov edx, dword ptr [eax + 8]
// 006f9f59  807a3100             cmp byte ptr [edx + 0x31], 0
// 006f9f5d  57                   push edi
// 006f9f5e  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 006f9f62  7416                 je 0x6f9f7a
// 006f9f64  50                   push eax
// 006f9f65  6a00                 push 0
// 006f9f67  57                   push edi
// 006f9f68  8bce                 mov ecx, esi
// 006f9f6a  e8c1eeffff           call 0x6f8e30
// 006f9f6f  5b                   pop ebx
// 006f9f70  8bc7                 mov eax, edi
// 006f9f72  5f                   pop edi
// 006f9f73  5e                   pop esi
// 006f9f74  83c414               add esp, 0x14
// 006f9f77  c21000               ret 0x10
// 006f9f7a  51                   push ecx
// 006f9f7b  6a01                 push 1
// 006f9f7d  57                   push edi
// 006f9f7e  8bce                 mov ecx, esi
// 006f9f80  e8abeeffff           call 0x6f8e30
// 006f9f85  5b                   pop ebx
// 006f9f86  8bc7                 mov eax, edi
// 006f9f88  5f                   pop edi
// 006f9f89  5e                   pop esi
// 006f9f8a  83c414               add esp, 0x14
// 006f9f8d  c21000               ret 0x10
// 006f9f90  57                   push edi
// 006f9f91  8d442418             lea eax, [esp + 0x18]
// 006f9f95  50                   push eax
// 006f9f96  8bce                 mov ecx, esi
// 006f9f98  e893f6ffff           call 0x6f9630
// 006f9f9d  8b10                 mov edx, dword ptr [eax]
// 006f9f9f  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 006f9fa3  5b                   pop ebx
// 006f9fa4  8911                 mov dword ptr [ecx], edx
// 006f9fa6  8b4004               mov eax, dword ptr [eax + 4]
// 006f9fa9  5f                   pop edi
// 006f9faa  894104               mov dword ptr [ecx + 4], eax
// 006f9fad  8bc1                 mov eax, ecx
// 006f9faf  5e                   pop esi
// 006f9fb0  83c414               add esp, 0x14
// 006f9fb3  c21000               ret 0x10
// standard library map_int<pod32> (function ?insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod32>
struct E { int v[8]; };
#include <map>
template class std::map<int, E>;
