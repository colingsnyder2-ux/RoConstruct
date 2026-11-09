// from server: 100% by auto
// roc 2008-06 00653c60  unit: RBX::ScoreHud  size: 562 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00653c60
//
// 00653c60  83ec14               sub esp, 0x14
// 00653c63  56                   push esi
// 00653c64  8bf1                 mov esi, ecx
// 00653c66  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 00653c6a  57                   push edi
// 00653c6b  7521                 jne 0x653c8e
// 00653c6d  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00653c71  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00653c74  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00653c78  50                   push eax
// 00653c79  51                   push ecx
// 00653c7a  6a01                 push 1
// 00653c7c  57                   push edi
// 00653c7d  8bce                 mov ecx, esi
// 00653c7f  e8bcebffff           call 0x652840
// 00653c84  8bc7                 mov eax, edi
// 00653c86  5f                   pop edi
// 00653c87  5e                   pop esi
// 00653c88  83c414               add esp, 0x14
// 00653c8b  c21000               ret 0x10
// 00653c8e  8b442424             mov eax, dword ptr [esp + 0x24]
// 00653c92  8b5618               mov edx, dword ptr [esi + 0x18]
// 00653c95  8b3a                 mov edi, dword ptr [edx]
// 00653c97  8b0e                 mov ecx, dword ptr [esi]
// 00653c99  53                   push ebx
// 00653c9a  8b1d90288000         mov ebx, dword ptr [0x802890]
// 00653ca0  85c0                 test eax, eax
// 00653ca2  7404                 je 0x653ca8
// 00653ca4  3bc1                 cmp eax, ecx
// 00653ca6  7406                 je 0x653cae
// 00653ca8  ffd3                 call ebx
// 00653caa  8b442428             mov eax, dword ptr [esp + 0x28]
// 00653cae  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 00653cb2  55                   push ebp
// 00653cb3  3bd7                 cmp edx, edi
// 00653cb5  753a                 jne 0x653cf1
// 00653cb7  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 00653cbb  83c20c               add edx, 0xc
// 00653cbe  52                   push edx
// 00653cbf  57                   push edi
// 00653cc0  ff155c238000         call dword ptr [0x80235c]
// 00653cc6  83c408               add esp, 8
// 00653cc9  84c0                 test al, al
// 00653ccb  0f849a010000         je 0x653e6b
// 00653cd1  8b442430             mov eax, dword ptr [esp + 0x30]
// 00653cd5  57                   push edi
// 00653cd6  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00653cda  50                   push eax
// 00653cdb  6a01                 push 1
// 00653cdd  57                   push edi
// 00653cde  8bce                 mov ecx, esi
// 00653ce0  e85bebffff           call 0x652840
// 00653ce5  5d                   pop ebp
// 00653ce6  5b                   pop ebx
// 00653ce7  8bc7                 mov eax, edi
// 00653ce9  5f                   pop edi
// 00653cea  5e                   pop esi
// 00653ceb  83c414               add esp, 0x14
// 00653cee  c21000               ret 0x10
// 00653cf1  8b7e18               mov edi, dword ptr [esi + 0x18]
// 00653cf4  8b0e                 mov ecx, dword ptr [esi]
// 00653cf6  85c0                 test eax, eax
// 00653cf8  7404                 je 0x653cfe
// 00653cfa  3bc1                 cmp eax, ecx
// 00653cfc  7406                 je 0x653d04
// 00653cfe  ffd3                 call ebx
// 00653d00  8b542430             mov edx, dword ptr [esp + 0x30]
// 00653d04  3bd7                 cmp edx, edi
// 00653d06  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 00653d0a  753e                 jne 0x653d4a
// 00653d0c  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00653d0f  8b4108               mov eax, dword ptr [ecx + 8]
// 00653d12  83c00c               add eax, 0xc
// 00653d15  57                   push edi
// 00653d16  50                   push eax
// 00653d17  ff155c238000         call dword ptr [0x80235c]
// 00653d1d  83c408               add esp, 8
// 00653d20  84c0                 test al, al
// 00653d22  0f8443010000         je 0x653e6b
// 00653d28  8b5618               mov edx, dword ptr [esi + 0x18]
// 00653d2b  8b4208               mov eax, dword ptr [edx + 8]
// 00653d2e  57                   push edi
// 00653d2f  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00653d33  50                   push eax
// 00653d34  6a00                 push 0
// 00653d36  57                   push edi
// 00653d37  8bce                 mov ecx, esi
// 00653d39  e802ebffff           call 0x652840
// 00653d3e  5d                   pop ebp
// 00653d3f  5b                   pop ebx
// 00653d40  8bc7                 mov eax, edi
// 00653d42  5f                   pop edi
// 00653d43  5e                   pop esi
// 00653d44  83c414               add esp, 0x14
// 00653d47  c21000               ret 0x10
// 00653d4a  8b2d5c238000         mov ebp, dword ptr [0x80235c]
// 00653d50  83c20c               add edx, 0xc
// 00653d53  52                   push edx
// 00653d54  57                   push edi
// 00653d55  ffd5                 call ebp
// 00653d57  83c408               add esp, 8
// 00653d5a  84c0                 test al, al
// 00653d5c  746c                 je 0x653dca
// 00653d5e  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00653d62  8b542430             mov edx, dword ptr [esp + 0x30]
// 00653d66  894c2410             mov dword ptr [esp + 0x10], ecx
// 00653d6a  8d4c2410             lea ecx, [esp + 0x10]
// 00653d6e  89542414             mov dword ptr [esp + 0x14], edx
// 00653d72  e8c933f3ff           call 0x587140
// 00653d77  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 00653d7b  57                   push edi
// 00653d7c  8d430c               lea eax, [ebx + 0xc]
// 00653d7f  50                   push eax
// 00653d80  8d4e08               lea ecx, [esi + 8]
// 00653d83  e87882f0ff           call 0x55c000
// 00653d88  84c0                 test al, al
// 00653d8a  743e                 je 0x653dca
// 00653d8c  8b4b08               mov ecx, dword ptr [ebx + 8]
// 00653d8f  80794900             cmp byte ptr [ecx + 0x49], 0
// 00653d93  57                   push edi
// 00653d94  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00653d98  8bce                 mov ecx, esi
// 00653d9a  7415                 je 0x653db1
// 00653d9c  53                   push ebx
// 00653d9d  6a00                 push 0
// 00653d9f  57                   push edi
// 00653da0  e89beaffff           call 0x652840
// 00653da5  5d                   pop ebp
// 00653da6  5b                   pop ebx
// 00653da7  8bc7                 mov eax, edi
// 00653da9  5f                   pop edi
// 00653daa  5e                   pop esi
// 00653dab  83c414               add esp, 0x14
// 00653dae  c21000               ret 0x10
// 00653db1  8b542434             mov edx, dword ptr [esp + 0x34]
// 00653db5  52                   push edx
// 00653db6  6a01                 push 1
// 00653db8  57                   push edi
// 00653db9  e882eaffff           call 0x652840
// 00653dbe  5d                   pop ebp
// 00653dbf  5b                   pop ebx
// 00653dc0  8bc7                 mov eax, edi
// 00653dc2  5f                   pop edi
// 00653dc3  5e                   pop esi
// 00653dc4  83c414               add esp, 0x14
// 00653dc7  c21000               ret 0x10
// 00653dca  8b442430             mov eax, dword ptr [esp + 0x30]
// 00653dce  83c00c               add eax, 0xc
// 00653dd1  57                   push edi
// 00653dd2  50                   push eax
// 00653dd3  ffd5                 call ebp
// 00653dd5  83c408               add esp, 8
// 00653dd8  84c0                 test al, al
// 00653dda  0f848b000000         je 0x653e6b
// 00653de0  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00653de4  8b542430             mov edx, dword ptr [esp + 0x30]
// 00653de8  8b4618               mov eax, dword ptr [esi + 0x18]
// 00653deb  894c2410             mov dword ptr [esp + 0x10], ecx
// 00653def  8b0e                 mov ecx, dword ptr [esi]
// 00653df1  894c2418             mov dword ptr [esp + 0x18], ecx
// 00653df5  8d4c2410             lea ecx, [esp + 0x10]
// 00653df9  89542414             mov dword ptr [esp + 0x14], edx
// 00653dfd  8944241c             mov dword ptr [esp + 0x1c], eax
// 00653e01  e8ead2ffff           call 0x6510f0
// 00653e06  8d542418             lea edx, [esp + 0x18]
// 00653e0a  52                   push edx
// 00653e0b  8d4c2414             lea ecx, [esp + 0x14]
// 00653e0f  e88c8ef9ff           call 0x5ecca0
// 00653e14  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 00653e18  84c0                 test al, al
// 00653e1a  7511                 jne 0x653e2d
// 00653e1c  8d430c               lea eax, [ebx + 0xc]
// 00653e1f  50                   push eax
// 00653e20  57                   push edi
// 00653e21  8d4e08               lea ecx, [esi + 8]
// 00653e24  e8d781f0ff           call 0x55c000
// 00653e29  84c0                 test al, al
// 00653e2b  743e                 je 0x653e6b
// 00653e2d  8b442430             mov eax, dword ptr [esp + 0x30]
// 00653e31  8b4808               mov ecx, dword ptr [eax + 8]
// 00653e34  80794900             cmp byte ptr [ecx + 0x49], 0
// 00653e38  57                   push edi
// 00653e39  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00653e3d  8bce                 mov ecx, esi
// 00653e3f  7415                 je 0x653e56
// 00653e41  50                   push eax
// 00653e42  6a00                 push 0
// 00653e44  57                   push edi
// 00653e45  e8f6e9ffff           call 0x652840
// 00653e4a  5d                   pop ebp
// 00653e4b  5b                   pop ebx
// 00653e4c  8bc7                 mov eax, edi
// 00653e4e  5f                   pop edi
// 00653e4f  5e                   pop esi
// 00653e50  83c414               add esp, 0x14
// 00653e53  c21000               ret 0x10
// 00653e56  53                   push ebx
// 00653e57  6a01                 push 1
// 00653e59  57                   push edi
// 00653e5a  e8e1e9ffff           call 0x652840
// 00653e5f  5d                   pop ebp
// 00653e60  5b                   pop ebx
// 00653e61  8bc7                 mov eax, edi
// 00653e63  5f                   pop edi
// 00653e64  5e                   pop esi
// 00653e65  83c414               add esp, 0x14
// 00653e68  c21000               ret 0x10
// 00653e6b  57                   push edi
// 00653e6c  8d54241c             lea edx, [esp + 0x1c]
// 00653e70  52                   push edx
// 00653e71  8bce                 mov ecx, esi
// 00653e73  e8d8f3ffff           call 0x653250
// 00653e78  8b10                 mov edx, dword ptr [eax]
// 00653e7a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00653e7e  5d                   pop ebp
// 00653e7f  5b                   pop ebx
// 00653e80  8911                 mov dword ptr [ecx], edx
// 00653e82  8b4004               mov eax, dword ptr [eax + 4]
// 00653e85  5f                   pop edi
// 00653e86  894104               mov dword ptr [ecx + 4], eax
// 00653e89  8bc1                 mov eax, ecx
// 00653e8b  5e                   pop esi
// 00653e8c  83c414               add esp, 0x14
// 00653e8f  c21000               ret 0x10
// standard library map_str<pod32> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod32>
struct E { int v[8]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
