// from server: 100% by auto
// roc 2008-06 00653ea0  unit: RBX::ScoreHud  size: 470 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00653ea0
//
// 00653ea0  83ec14               sub esp, 0x14
// 00653ea3  56                   push esi
// 00653ea4  8bf1                 mov esi, ecx
// 00653ea6  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 00653eaa  57                   push edi
// 00653eab  7521                 jne 0x653ece
// 00653ead  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00653eb1  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00653eb4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00653eb8  50                   push eax
// 00653eb9  51                   push ecx
// 00653eba  6a01                 push 1
// 00653ebc  57                   push edi
// 00653ebd  8bce                 mov ecx, esi
// 00653ebf  e87cebffff           call 0x652a40
// 00653ec4  8bc7                 mov eax, edi
// 00653ec6  5f                   pop edi
// 00653ec7  5e                   pop esi
// 00653ec8  83c414               add esp, 0x14
// 00653ecb  c21000               ret 0x10
// 00653ece  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00653ed2  8b5618               mov edx, dword ptr [esi + 0x18]
// 00653ed5  8b3a                 mov edi, dword ptr [edx]
// 00653ed7  8b06                 mov eax, dword ptr [esi]
// 00653ed9  53                   push ebx
// 00653eda  8b1d90288000         mov ebx, dword ptr [0x802890]
// 00653ee0  85c9                 test ecx, ecx
// 00653ee2  7404                 je 0x653ee8
// 00653ee4  3bc8                 cmp ecx, eax
// 00653ee6  7406                 je 0x653eee
// 00653ee8  ffd3                 call ebx
// 00653eea  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00653eee  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00653ef2  3bc7                 cmp eax, edi
// 00653ef4  752a                 jne 0x653f20
// 00653ef6  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 00653efa  8b0f                 mov ecx, dword ptr [edi]
// 00653efc  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 00653eff  0f834b010000         jae 0x654050
// 00653f05  57                   push edi
// 00653f06  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00653f0a  50                   push eax
// 00653f0b  6a01                 push 1
// 00653f0d  57                   push edi
// 00653f0e  8bce                 mov ecx, esi
// 00653f10  e82bebffff           call 0x652a40
// 00653f15  5b                   pop ebx
// 00653f16  8bc7                 mov eax, edi
// 00653f18  5f                   pop edi
// 00653f19  5e                   pop esi
// 00653f1a  83c414               add esp, 0x14
// 00653f1d  c21000               ret 0x10
// 00653f20  8b7e18               mov edi, dword ptr [esi + 0x18]
// 00653f23  8b16                 mov edx, dword ptr [esi]
// 00653f25  85c9                 test ecx, ecx
// 00653f27  7404                 je 0x653f2d
// 00653f29  3bca                 cmp ecx, edx
// 00653f2b  740a                 je 0x653f37
// 00653f2d  ffd3                 call ebx
// 00653f2f  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00653f33  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00653f37  3bc7                 cmp eax, edi
// 00653f39  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 00653f3d  752c                 jne 0x653f6b
// 00653f3f  8b5618               mov edx, dword ptr [esi + 0x18]
// 00653f42  8b4208               mov eax, dword ptr [edx + 8]
// 00653f45  8b480c               mov ecx, dword ptr [eax + 0xc]
// 00653f48  3b0f                 cmp ecx, dword ptr [edi]
// 00653f4a  0f8300010000         jae 0x654050
// 00653f50  57                   push edi
// 00653f51  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00653f55  50                   push eax
// 00653f56  6a00                 push 0
// 00653f58  57                   push edi
// 00653f59  8bce                 mov ecx, esi
// 00653f5b  e8e0eaffff           call 0x652a40
// 00653f60  5b                   pop ebx
// 00653f61  8bc7                 mov eax, edi
// 00653f63  5f                   pop edi
// 00653f64  5e                   pop esi
// 00653f65  83c414               add esp, 0x14
// 00653f68  c21000               ret 0x10
// 00653f6b  8b17                 mov edx, dword ptr [edi]
// 00653f6d  39500c               cmp dword ptr [eax + 0xc], edx
// 00653f70  7663                 jbe 0x653fd5
// 00653f72  894c240c             mov dword ptr [esp + 0xc], ecx
// 00653f76  8d4c240c             lea ecx, [esp + 0xc]
// 00653f7a  89442410             mov dword ptr [esp + 0x10], eax
// 00653f7e  e8ddd1ffff           call 0x651160
// 00653f83  8b17                 mov edx, dword ptr [edi]
// 00653f85  8b442410             mov eax, dword ptr [esp + 0x10]
// 00653f89  39500c               cmp dword ptr [eax + 0xc], edx
// 00653f8c  733c                 jae 0x653fca
// 00653f8e  8b5008               mov edx, dword ptr [eax + 8]
// 00653f91  807a3100             cmp byte ptr [edx + 0x31], 0
// 00653f95  57                   push edi
// 00653f96  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00653f9a  8bce                 mov ecx, esi
// 00653f9c  7414                 je 0x653fb2
// 00653f9e  50                   push eax
// 00653f9f  6a00                 push 0
// 00653fa1  57                   push edi
// 00653fa2  e899eaffff           call 0x652a40
// 00653fa7  5b                   pop ebx
// 00653fa8  8bc7                 mov eax, edi
// 00653faa  5f                   pop edi
// 00653fab  5e                   pop esi
// 00653fac  83c414               add esp, 0x14
// 00653faf  c21000               ret 0x10
// 00653fb2  8b442430             mov eax, dword ptr [esp + 0x30]
// 00653fb6  50                   push eax
// 00653fb7  6a01                 push 1
// 00653fb9  57                   push edi
// 00653fba  e881eaffff           call 0x652a40
// 00653fbf  5b                   pop ebx
// 00653fc0  8bc7                 mov eax, edi
// 00653fc2  5f                   pop edi
// 00653fc3  5e                   pop esi
// 00653fc4  83c414               add esp, 0x14
// 00653fc7  c21000               ret 0x10
// 00653fca  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00653fce  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00653fd2  39500c               cmp dword ptr [eax + 0xc], edx
// 00653fd5  7379                 jae 0x654050
// 00653fd7  8b16                 mov edx, dword ptr [esi]
// 00653fd9  894c240c             mov dword ptr [esp + 0xc], ecx
// 00653fdd  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00653fe0  894c2418             mov dword ptr [esp + 0x18], ecx
// 00653fe4  8d4c240c             lea ecx, [esp + 0xc]
// 00653fe8  89442410             mov dword ptr [esp + 0x10], eax
// 00653fec  89542414             mov dword ptr [esp + 0x14], edx
// 00653ff0  e88bd8f3ff           call 0x591880
// 00653ff5  8d442414             lea eax, [esp + 0x14]
// 00653ff9  50                   push eax
// 00653ffa  8d4c2410             lea ecx, [esp + 0x10]
// 00653ffe  e89d8cf9ff           call 0x5ecca0
// 00654003  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00654007  84c0                 test al, al
// 00654009  7507                 jne 0x654012
// 0065400b  8b17                 mov edx, dword ptr [edi]
// 0065400d  3b510c               cmp edx, dword ptr [ecx + 0xc]
// 00654010  733e                 jae 0x654050
// 00654012  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00654016  8b5008               mov edx, dword ptr [eax + 8]
// 00654019  807a3100             cmp byte ptr [edx + 0x31], 0
// 0065401d  57                   push edi
// 0065401e  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00654022  7416                 je 0x65403a
// 00654024  50                   push eax
// 00654025  6a00                 push 0
// 00654027  57                   push edi
// 00654028  8bce                 mov ecx, esi
// 0065402a  e811eaffff           call 0x652a40
// 0065402f  5b                   pop ebx
// 00654030  8bc7                 mov eax, edi
// 00654032  5f                   pop edi
// 00654033  5e                   pop esi
// 00654034  83c414               add esp, 0x14
// 00654037  c21000               ret 0x10
// 0065403a  51                   push ecx
// 0065403b  6a01                 push 1
// 0065403d  57                   push edi
// 0065403e  8bce                 mov ecx, esi
// 00654040  e8fbe9ffff           call 0x652a40
// 00654045  5b                   pop ebx
// 00654046  8bc7                 mov eax, edi
// 00654048  5f                   pop edi
// 00654049  5e                   pop esi
// 0065404a  83c414               add esp, 0x14
// 0065404d  c21000               ret 0x10
// 00654050  57                   push edi
// 00654051  8d442418             lea eax, [esp + 0x18]
// 00654055  50                   push eax
// 00654056  8bce                 mov ecx, esi
// 00654058  e8e3f2ffff           call 0x653340
// 0065405d  8b10                 mov edx, dword ptr [eax]
// 0065405f  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00654063  5b                   pop ebx
// 00654064  8911                 mov dword ptr [ecx], edx
// 00654066  8b4004               mov eax, dword ptr [eax + 4]
// 00654069  5f                   pop edi
// 0065406a  894104               mov dword ptr [ecx + 4], eax
// 0065406d  8bc1                 mov eax, ecx
// 0065406f  5e                   pop esi
// 00654070  83c414               add esp, 0x14
// 00654073  c21000               ret 0x10
// standard library map_ptr<pod32> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod32>
struct E { int v[8]; };
#include <map>
struct K; template class std::map<K*, E>;
