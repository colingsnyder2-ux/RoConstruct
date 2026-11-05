// from server: 100% by auto
// roc 2009-12 00683ea0  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 470 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00683ea0
//
// 00683ea0  83ec14               sub esp, 0x14
// 00683ea3  56                   push esi
// 00683ea4  8bf1                 mov esi, ecx
// 00683ea6  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 00683eaa  57                   push edi
// 00683eab  7521                 jne 0x683ece
// 00683ead  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00683eb1  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00683eb4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00683eb8  50                   push eax
// 00683eb9  51                   push ecx
// 00683eba  6a01                 push 1
// 00683ebc  57                   push edi
// 00683ebd  8bce                 mov ecx, esi
// 00683ebf  e8ccedffff           call 0x682c90
// 00683ec4  8bc7                 mov eax, edi
// 00683ec6  5f                   pop edi
// 00683ec7  5e                   pop esi
// 00683ec8  83c414               add esp, 0x14
// 00683ecb  c21000               ret 0x10
// 00683ece  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00683ed2  8b5618               mov edx, dword ptr [esi + 0x18]
// 00683ed5  8b3a                 mov edi, dword ptr [edx]
// 00683ed7  8b06                 mov eax, dword ptr [esi]
// 00683ed9  53                   push ebx
// 00683eda  8b1d60b79800         mov ebx, dword ptr [0x98b760]
// 00683ee0  85c9                 test ecx, ecx
// 00683ee2  7404                 je 0x683ee8
// 00683ee4  3bc8                 cmp ecx, eax
// 00683ee6  7406                 je 0x683eee
// 00683ee8  ffd3                 call ebx
// 00683eea  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00683eee  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00683ef2  3bc7                 cmp eax, edi
// 00683ef4  752a                 jne 0x683f20
// 00683ef6  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 00683efa  8b0f                 mov ecx, dword ptr [edi]
// 00683efc  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 00683eff  0f834b010000         jae 0x684050
// 00683f05  57                   push edi
// 00683f06  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00683f0a  50                   push eax
// 00683f0b  6a01                 push 1
// 00683f0d  57                   push edi
// 00683f0e  8bce                 mov ecx, esi
// 00683f10  e87bedffff           call 0x682c90
// 00683f15  5b                   pop ebx
// 00683f16  8bc7                 mov eax, edi
// 00683f18  5f                   pop edi
// 00683f19  5e                   pop esi
// 00683f1a  83c414               add esp, 0x14
// 00683f1d  c21000               ret 0x10
// 00683f20  8b7e18               mov edi, dword ptr [esi + 0x18]
// 00683f23  8b16                 mov edx, dword ptr [esi]
// 00683f25  85c9                 test ecx, ecx
// 00683f27  7404                 je 0x683f2d
// 00683f29  3bca                 cmp ecx, edx
// 00683f2b  740a                 je 0x683f37
// 00683f2d  ffd3                 call ebx
// 00683f2f  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00683f33  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00683f37  3bc7                 cmp eax, edi
// 00683f39  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 00683f3d  752c                 jne 0x683f6b
// 00683f3f  8b5618               mov edx, dword ptr [esi + 0x18]
// 00683f42  8b4208               mov eax, dword ptr [edx + 8]
// 00683f45  8b480c               mov ecx, dword ptr [eax + 0xc]
// 00683f48  3b0f                 cmp ecx, dword ptr [edi]
// 00683f4a  0f8300010000         jae 0x684050
// 00683f50  57                   push edi
// 00683f51  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00683f55  50                   push eax
// 00683f56  6a00                 push 0
// 00683f58  57                   push edi
// 00683f59  8bce                 mov ecx, esi
// 00683f5b  e830edffff           call 0x682c90
// 00683f60  5b                   pop ebx
// 00683f61  8bc7                 mov eax, edi
// 00683f63  5f                   pop edi
// 00683f64  5e                   pop esi
// 00683f65  83c414               add esp, 0x14
// 00683f68  c21000               ret 0x10
// 00683f6b  8b17                 mov edx, dword ptr [edi]
// 00683f6d  39500c               cmp dword ptr [eax + 0xc], edx
// 00683f70  7663                 jbe 0x683fd5
// 00683f72  894c240c             mov dword ptr [esp + 0xc], ecx
// 00683f76  8d4c240c             lea ecx, [esp + 0xc]
// 00683f7a  89442410             mov dword ptr [esp + 0x10], eax
// 00683f7e  e82d2fffff           call 0x676eb0
// 00683f83  8b17                 mov edx, dword ptr [edi]
// 00683f85  8b442410             mov eax, dword ptr [esp + 0x10]
// 00683f89  39500c               cmp dword ptr [eax + 0xc], edx
// 00683f8c  733c                 jae 0x683fca
// 00683f8e  8b5008               mov edx, dword ptr [eax + 8]
// 00683f91  807a1900             cmp byte ptr [edx + 0x19], 0
// 00683f95  57                   push edi
// 00683f96  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00683f9a  8bce                 mov ecx, esi
// 00683f9c  7414                 je 0x683fb2
// 00683f9e  50                   push eax
// 00683f9f  6a00                 push 0
// 00683fa1  57                   push edi
// 00683fa2  e8e9ecffff           call 0x682c90
// 00683fa7  5b                   pop ebx
// 00683fa8  8bc7                 mov eax, edi
// 00683faa  5f                   pop edi
// 00683fab  5e                   pop esi
// 00683fac  83c414               add esp, 0x14
// 00683faf  c21000               ret 0x10
// 00683fb2  8b442430             mov eax, dword ptr [esp + 0x30]
// 00683fb6  50                   push eax
// 00683fb7  6a01                 push 1
// 00683fb9  57                   push edi
// 00683fba  e8d1ecffff           call 0x682c90
// 00683fbf  5b                   pop ebx
// 00683fc0  8bc7                 mov eax, edi
// 00683fc2  5f                   pop edi
// 00683fc3  5e                   pop esi
// 00683fc4  83c414               add esp, 0x14
// 00683fc7  c21000               ret 0x10
// 00683fca  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00683fce  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00683fd2  39500c               cmp dword ptr [eax + 0xc], edx
// 00683fd5  7379                 jae 0x684050
// 00683fd7  8b16                 mov edx, dword ptr [esi]
// 00683fd9  894c240c             mov dword ptr [esp + 0xc], ecx
// 00683fdd  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00683fe0  894c2418             mov dword ptr [esp + 0x18], ecx
// 00683fe4  8d4c240c             lea ecx, [esp + 0xc]
// 00683fe8  89442410             mov dword ptr [esp + 0x10], eax
// 00683fec  89542414             mov dword ptr [esp + 0x14], edx
// 00683ff0  e88b45ebff           call 0x538580
// 00683ff5  8d442414             lea eax, [esp + 0x14]
// 00683ff9  50                   push eax
// 00683ffa  8d4c2410             lea ecx, [esp + 0x10]
// 00683ffe  e85d83f4ff           call 0x5cc360
// 00684003  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00684007  84c0                 test al, al
// 00684009  7507                 jne 0x684012
// 0068400b  8b17                 mov edx, dword ptr [edi]
// 0068400d  3b510c               cmp edx, dword ptr [ecx + 0xc]
// 00684010  733e                 jae 0x684050
// 00684012  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00684016  8b5008               mov edx, dword ptr [eax + 8]
// 00684019  807a1900             cmp byte ptr [edx + 0x19], 0
// 0068401d  57                   push edi
// 0068401e  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00684022  7416                 je 0x68403a
// 00684024  50                   push eax
// 00684025  6a00                 push 0
// 00684027  57                   push edi
// 00684028  8bce                 mov ecx, esi
// 0068402a  e861ecffff           call 0x682c90
// 0068402f  5b                   pop ebx
// 00684030  8bc7                 mov eax, edi
// 00684032  5f                   pop edi
// 00684033  5e                   pop esi
// 00684034  83c414               add esp, 0x14
// 00684037  c21000               ret 0x10
// 0068403a  51                   push ecx
// 0068403b  6a01                 push 1
// 0068403d  57                   push edi
// 0068403e  8bce                 mov ecx, esi
// 00684040  e84becffff           call 0x682c90
// 00684045  5b                   pop ebx
// 00684046  8bc7                 mov eax, edi
// 00684048  5f                   pop edi
// 00684049  5e                   pop esi
// 0068404a  83c414               add esp, 0x14
// 0068404d  c21000               ret 0x10
// 00684050  57                   push edi
// 00684051  8d442418             lea eax, [esp + 0x18]
// 00684055  50                   push eax
// 00684056  8bce                 mov ecx, esi
// 00684058  e833f2ffff           call 0x683290
// 0068405d  8b10                 mov edx, dword ptr [eax]
// 0068405f  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00684063  5b                   pop ebx
// 00684064  8911                 mov dword ptr [ecx], edx
// 00684066  8b4004               mov eax, dword ptr [eax + 4]
// 00684069  5f                   pop edi
// 0068406a  894104               mov dword ptr [ecx + 4], eax
// 0068406d  8bc1                 mov eax, ecx
// 0068406f  5e                   pop esi
// 00684070  83c414               add esp, 0x14
// 00684073  c21000               ret 0x10
// standard library map_ptr<pod8> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod8>
struct E { int v[2]; };
#include <map>
struct K; template class std::map<K*, E>;
