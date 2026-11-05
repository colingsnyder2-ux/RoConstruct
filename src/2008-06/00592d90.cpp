// from server: 100% by auto
// roc 2008-06 00592d90  unit: ArchiveBinder  size: 562 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00592d90
//
// 00592d90  83ec14               sub esp, 0x14
// 00592d93  56                   push esi
// 00592d94  8bf1                 mov esi, ecx
// 00592d96  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 00592d9a  57                   push edi
// 00592d9b  7521                 jne 0x592dbe
// 00592d9d  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00592da1  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00592da4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00592da8  50                   push eax
// 00592da9  51                   push ecx
// 00592daa  6a01                 push 1
// 00592dac  57                   push edi
// 00592dad  8bce                 mov ecx, esi
// 00592daf  e8ecfcffff           call 0x592aa0
// 00592db4  8bc7                 mov eax, edi
// 00592db6  5f                   pop edi
// 00592db7  5e                   pop esi
// 00592db8  83c414               add esp, 0x14
// 00592dbb  c21000               ret 0x10
// 00592dbe  8b442424             mov eax, dword ptr [esp + 0x24]
// 00592dc2  8b5618               mov edx, dword ptr [esi + 0x18]
// 00592dc5  8b3a                 mov edi, dword ptr [edx]
// 00592dc7  8b0e                 mov ecx, dword ptr [esi]
// 00592dc9  53                   push ebx
// 00592dca  8b1d90288000         mov ebx, dword ptr [0x802890]
// 00592dd0  85c0                 test eax, eax
// 00592dd2  7404                 je 0x592dd8
// 00592dd4  3bc1                 cmp eax, ecx
// 00592dd6  7406                 je 0x592dde
// 00592dd8  ffd3                 call ebx
// 00592dda  8b442428             mov eax, dword ptr [esp + 0x28]
// 00592dde  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 00592de2  55                   push ebp
// 00592de3  3bd7                 cmp edx, edi
// 00592de5  753a                 jne 0x592e21
// 00592de7  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 00592deb  83c20c               add edx, 0xc
// 00592dee  52                   push edx
// 00592def  57                   push edi
// 00592df0  ff155c238000         call dword ptr [0x80235c]
// 00592df6  83c408               add esp, 8
// 00592df9  84c0                 test al, al
// 00592dfb  0f849a010000         je 0x592f9b
// 00592e01  8b442430             mov eax, dword ptr [esp + 0x30]
// 00592e05  57                   push edi
// 00592e06  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00592e0a  50                   push eax
// 00592e0b  6a01                 push 1
// 00592e0d  57                   push edi
// 00592e0e  8bce                 mov ecx, esi
// 00592e10  e88bfcffff           call 0x592aa0
// 00592e15  5d                   pop ebp
// 00592e16  5b                   pop ebx
// 00592e17  8bc7                 mov eax, edi
// 00592e19  5f                   pop edi
// 00592e1a  5e                   pop esi
// 00592e1b  83c414               add esp, 0x14
// 00592e1e  c21000               ret 0x10
// 00592e21  8b7e18               mov edi, dword ptr [esi + 0x18]
// 00592e24  8b0e                 mov ecx, dword ptr [esi]
// 00592e26  85c0                 test eax, eax
// 00592e28  7404                 je 0x592e2e
// 00592e2a  3bc1                 cmp eax, ecx
// 00592e2c  7406                 je 0x592e34
// 00592e2e  ffd3                 call ebx
// 00592e30  8b542430             mov edx, dword ptr [esp + 0x30]
// 00592e34  3bd7                 cmp edx, edi
// 00592e36  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 00592e3a  753e                 jne 0x592e7a
// 00592e3c  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00592e3f  8b4108               mov eax, dword ptr [ecx + 8]
// 00592e42  83c00c               add eax, 0xc
// 00592e45  57                   push edi
// 00592e46  50                   push eax
// 00592e47  ff155c238000         call dword ptr [0x80235c]
// 00592e4d  83c408               add esp, 8
// 00592e50  84c0                 test al, al
// 00592e52  0f8443010000         je 0x592f9b
// 00592e58  8b5618               mov edx, dword ptr [esi + 0x18]
// 00592e5b  8b4208               mov eax, dword ptr [edx + 8]
// 00592e5e  57                   push edi
// 00592e5f  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00592e63  50                   push eax
// 00592e64  6a00                 push 0
// 00592e66  57                   push edi
// 00592e67  8bce                 mov ecx, esi
// 00592e69  e832fcffff           call 0x592aa0
// 00592e6e  5d                   pop ebp
// 00592e6f  5b                   pop ebx
// 00592e70  8bc7                 mov eax, edi
// 00592e72  5f                   pop edi
// 00592e73  5e                   pop esi
// 00592e74  83c414               add esp, 0x14
// 00592e77  c21000               ret 0x10
// 00592e7a  8b2d5c238000         mov ebp, dword ptr [0x80235c]
// 00592e80  83c20c               add edx, 0xc
// 00592e83  52                   push edx
// 00592e84  57                   push edi
// 00592e85  ffd5                 call ebp
// 00592e87  83c408               add esp, 8
// 00592e8a  84c0                 test al, al
// 00592e8c  746c                 je 0x592efa
// 00592e8e  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00592e92  8b542430             mov edx, dword ptr [esp + 0x30]
// 00592e96  894c2410             mov dword ptr [esp + 0x10], ecx
// 00592e9a  8d4c2410             lea ecx, [esp + 0x10]
// 00592e9e  89542414             mov dword ptr [esp + 0x14], edx
// 00592ea2  e8b9e20b00           call 0x651160
// 00592ea7  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 00592eab  57                   push edi
// 00592eac  8d430c               lea eax, [ebx + 0xc]
// 00592eaf  50                   push eax
// 00592eb0  8d4e08               lea ecx, [esi + 8]
// 00592eb3  e84891fcff           call 0x55c000
// 00592eb8  84c0                 test al, al
// 00592eba  743e                 je 0x592efa
// 00592ebc  8b4b08               mov ecx, dword ptr [ebx + 8]
// 00592ebf  80793100             cmp byte ptr [ecx + 0x31], 0
// 00592ec3  57                   push edi
// 00592ec4  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00592ec8  8bce                 mov ecx, esi
// 00592eca  7415                 je 0x592ee1
// 00592ecc  53                   push ebx
// 00592ecd  6a00                 push 0
// 00592ecf  57                   push edi
// 00592ed0  e8cbfbffff           call 0x592aa0
// 00592ed5  5d                   pop ebp
// 00592ed6  5b                   pop ebx
// 00592ed7  8bc7                 mov eax, edi
// 00592ed9  5f                   pop edi
// 00592eda  5e                   pop esi
// 00592edb  83c414               add esp, 0x14
// 00592ede  c21000               ret 0x10
// 00592ee1  8b542434             mov edx, dword ptr [esp + 0x34]
// 00592ee5  52                   push edx
// 00592ee6  6a01                 push 1
// 00592ee8  57                   push edi
// 00592ee9  e8b2fbffff           call 0x592aa0
// 00592eee  5d                   pop ebp
// 00592eef  5b                   pop ebx
// 00592ef0  8bc7                 mov eax, edi
// 00592ef2  5f                   pop edi
// 00592ef3  5e                   pop esi
// 00592ef4  83c414               add esp, 0x14
// 00592ef7  c21000               ret 0x10
// 00592efa  8b442430             mov eax, dword ptr [esp + 0x30]
// 00592efe  83c00c               add eax, 0xc
// 00592f01  57                   push edi
// 00592f02  50                   push eax
// 00592f03  ffd5                 call ebp
// 00592f05  83c408               add esp, 8
// 00592f08  84c0                 test al, al
// 00592f0a  0f848b000000         je 0x592f9b
// 00592f10  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00592f14  8b542430             mov edx, dword ptr [esp + 0x30]
// 00592f18  8b4618               mov eax, dword ptr [esi + 0x18]
// 00592f1b  894c2410             mov dword ptr [esp + 0x10], ecx
// 00592f1f  8b0e                 mov ecx, dword ptr [esi]
// 00592f21  894c2418             mov dword ptr [esp + 0x18], ecx
// 00592f25  8d4c2410             lea ecx, [esp + 0x10]
// 00592f29  89542414             mov dword ptr [esp + 0x14], edx
// 00592f2d  8944241c             mov dword ptr [esp + 0x1c], eax
// 00592f31  e84ae9ffff           call 0x591880
// 00592f36  8d542418             lea edx, [esp + 0x18]
// 00592f3a  52                   push edx
// 00592f3b  8d4c2414             lea ecx, [esp + 0x14]
// 00592f3f  e85c9d0500           call 0x5ecca0
// 00592f44  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 00592f48  84c0                 test al, al
// 00592f4a  7511                 jne 0x592f5d
// 00592f4c  8d430c               lea eax, [ebx + 0xc]
// 00592f4f  50                   push eax
// 00592f50  57                   push edi
// 00592f51  8d4e08               lea ecx, [esi + 8]
// 00592f54  e8a790fcff           call 0x55c000
// 00592f59  84c0                 test al, al
// 00592f5b  743e                 je 0x592f9b
// 00592f5d  8b442430             mov eax, dword ptr [esp + 0x30]
// 00592f61  8b4808               mov ecx, dword ptr [eax + 8]
// 00592f64  80793100             cmp byte ptr [ecx + 0x31], 0
// 00592f68  57                   push edi
// 00592f69  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00592f6d  8bce                 mov ecx, esi
// 00592f6f  7415                 je 0x592f86
// 00592f71  50                   push eax
// 00592f72  6a00                 push 0
// 00592f74  57                   push edi
// 00592f75  e826fbffff           call 0x592aa0
// 00592f7a  5d                   pop ebp
// 00592f7b  5b                   pop ebx
// 00592f7c  8bc7                 mov eax, edi
// 00592f7e  5f                   pop edi
// 00592f7f  5e                   pop esi
// 00592f80  83c414               add esp, 0x14
// 00592f83  c21000               ret 0x10
// 00592f86  53                   push ebx
// 00592f87  6a01                 push 1
// 00592f89  57                   push edi
// 00592f8a  e811fbffff           call 0x592aa0
// 00592f8f  5d                   pop ebp
// 00592f90  5b                   pop ebx
// 00592f91  8bc7                 mov eax, edi
// 00592f93  5f                   pop edi
// 00592f94  5e                   pop esi
// 00592f95  83c414               add esp, 0x14
// 00592f98  c21000               ret 0x10
// 00592f9b  57                   push edi
// 00592f9c  8d54241c             lea edx, [esp + 0x1c]
// 00592fa0  52                   push edx
// 00592fa1  8bce                 mov ecx, esi
// 00592fa3  e8f8fcffff           call 0x592ca0
// 00592fa8  8b10                 mov edx, dword ptr [eax]
// 00592faa  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00592fae  5d                   pop ebp
// 00592faf  5b                   pop ebx
// 00592fb0  8911                 mov dword ptr [ecx], edx
// 00592fb2  8b4004               mov eax, dword ptr [eax + 4]
// 00592fb5  5f                   pop edi
// 00592fb6  894104               mov dword ptr [ecx + 4], eax
// 00592fb9  8bc1                 mov eax, ecx
// 00592fbb  5e                   pop esi
// 00592fbc  83c414               add esp, 0x14
// 00592fbf  c21000               ret 0x10
// standard library map_str<pod8> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod8>
struct E { int v[2]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
