// from server: 100% by auto
// roc 2010-06 0067e0c0  unit: RBX::VInstance::?$NonFactoryProduct  size: 562 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0067e0c0
//
// 0067e0c0  83ec14               sub esp, 0x14
// 0067e0c3  56                   push esi
// 0067e0c4  8bf1                 mov esi, ecx
// 0067e0c6  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 0067e0ca  57                   push edi
// 0067e0cb  7521                 jne 0x67e0ee
// 0067e0cd  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0067e0d1  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0067e0d4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0067e0d8  50                   push eax
// 0067e0d9  51                   push ecx
// 0067e0da  6a01                 push 1
// 0067e0dc  57                   push edi
// 0067e0dd  8bce                 mov ecx, esi
// 0067e0df  e8ecdcffff           call 0x67bdd0
// 0067e0e4  8bc7                 mov eax, edi
// 0067e0e6  5f                   pop edi
// 0067e0e7  5e                   pop esi
// 0067e0e8  83c414               add esp, 0x14
// 0067e0eb  c21000               ret 0x10
// 0067e0ee  8b442424             mov eax, dword ptr [esp + 0x24]
// 0067e0f2  8b5618               mov edx, dword ptr [esi + 0x18]
// 0067e0f5  8b3a                 mov edi, dword ptr [edx]
// 0067e0f7  8b0e                 mov ecx, dword ptr [esi]
// 0067e0f9  53                   push ebx
// 0067e0fa  8b1d0ca99e00         mov ebx, dword ptr [0x9ea90c]
// 0067e100  85c0                 test eax, eax
// 0067e102  7404                 je 0x67e108
// 0067e104  3bc1                 cmp eax, ecx
// 0067e106  7406                 je 0x67e10e
// 0067e108  ffd3                 call ebx
// 0067e10a  8b442428             mov eax, dword ptr [esp + 0x28]
// 0067e10e  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 0067e112  55                   push ebp
// 0067e113  3bd7                 cmp edx, edi
// 0067e115  753a                 jne 0x67e151
// 0067e117  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 0067e11b  83c20c               add edx, 0xc
// 0067e11e  52                   push edx
// 0067e11f  57                   push edi
// 0067e120  ff151ca59e00         call dword ptr [0x9ea51c]
// 0067e126  83c408               add esp, 8
// 0067e129  84c0                 test al, al
// 0067e12b  0f849a010000         je 0x67e2cb
// 0067e131  8b442430             mov eax, dword ptr [esp + 0x30]
// 0067e135  57                   push edi
// 0067e136  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0067e13a  50                   push eax
// 0067e13b  6a01                 push 1
// 0067e13d  57                   push edi
// 0067e13e  8bce                 mov ecx, esi
// 0067e140  e88bdcffff           call 0x67bdd0
// 0067e145  5d                   pop ebp
// 0067e146  5b                   pop ebx
// 0067e147  8bc7                 mov eax, edi
// 0067e149  5f                   pop edi
// 0067e14a  5e                   pop esi
// 0067e14b  83c414               add esp, 0x14
// 0067e14e  c21000               ret 0x10
// 0067e151  8b7e18               mov edi, dword ptr [esi + 0x18]
// 0067e154  8b0e                 mov ecx, dword ptr [esi]
// 0067e156  85c0                 test eax, eax
// 0067e158  7404                 je 0x67e15e
// 0067e15a  3bc1                 cmp eax, ecx
// 0067e15c  7406                 je 0x67e164
// 0067e15e  ffd3                 call ebx
// 0067e160  8b542430             mov edx, dword ptr [esp + 0x30]
// 0067e164  3bd7                 cmp edx, edi
// 0067e166  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 0067e16a  753e                 jne 0x67e1aa
// 0067e16c  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0067e16f  8b4108               mov eax, dword ptr [ecx + 8]
// 0067e172  83c00c               add eax, 0xc
// 0067e175  57                   push edi
// 0067e176  50                   push eax
// 0067e177  ff151ca59e00         call dword ptr [0x9ea51c]
// 0067e17d  83c408               add esp, 8
// 0067e180  84c0                 test al, al
// 0067e182  0f8443010000         je 0x67e2cb
// 0067e188  8b5618               mov edx, dword ptr [esi + 0x18]
// 0067e18b  8b4208               mov eax, dword ptr [edx + 8]
// 0067e18e  57                   push edi
// 0067e18f  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0067e193  50                   push eax
// 0067e194  6a00                 push 0
// 0067e196  57                   push edi
// 0067e197  8bce                 mov ecx, esi
// 0067e199  e832dcffff           call 0x67bdd0
// 0067e19e  5d                   pop ebp
// 0067e19f  5b                   pop ebx
// 0067e1a0  8bc7                 mov eax, edi
// 0067e1a2  5f                   pop edi
// 0067e1a3  5e                   pop esi
// 0067e1a4  83c414               add esp, 0x14
// 0067e1a7  c21000               ret 0x10
// 0067e1aa  8b2d1ca59e00         mov ebp, dword ptr [0x9ea51c]
// 0067e1b0  83c20c               add edx, 0xc
// 0067e1b3  52                   push edx
// 0067e1b4  57                   push edi
// 0067e1b5  ffd5                 call ebp
// 0067e1b7  83c408               add esp, 8
// 0067e1ba  84c0                 test al, al
// 0067e1bc  746c                 je 0x67e22a
// 0067e1be  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0067e1c2  8b542430             mov edx, dword ptr [esp + 0x30]
// 0067e1c6  894c2410             mov dword ptr [esp + 0x10], ecx
// 0067e1ca  8d4c2410             lea ecx, [esp + 0x10]
// 0067e1ce  89542414             mov dword ptr [esp + 0x14], edx
// 0067e1d2  e80953dfff           call 0x4734e0
// 0067e1d7  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 0067e1db  57                   push edi
// 0067e1dc  8d430c               lea eax, [ebx + 0xc]
// 0067e1df  50                   push eax
// 0067e1e0  8d4e08               lea ecx, [esi + 8]
// 0067e1e3  e86850dfff           call 0x473250
// 0067e1e8  84c0                 test al, al
// 0067e1ea  743e                 je 0x67e22a
// 0067e1ec  8b4b08               mov ecx, dword ptr [ebx + 8]
// 0067e1ef  80793100             cmp byte ptr [ecx + 0x31], 0
// 0067e1f3  57                   push edi
// 0067e1f4  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0067e1f8  8bce                 mov ecx, esi
// 0067e1fa  7415                 je 0x67e211
// 0067e1fc  53                   push ebx
// 0067e1fd  6a00                 push 0
// 0067e1ff  57                   push edi
// 0067e200  e8cbdbffff           call 0x67bdd0
// 0067e205  5d                   pop ebp
// 0067e206  5b                   pop ebx
// 0067e207  8bc7                 mov eax, edi
// 0067e209  5f                   pop edi
// 0067e20a  5e                   pop esi
// 0067e20b  83c414               add esp, 0x14
// 0067e20e  c21000               ret 0x10
// 0067e211  8b542434             mov edx, dword ptr [esp + 0x34]
// 0067e215  52                   push edx
// 0067e216  6a01                 push 1
// 0067e218  57                   push edi
// 0067e219  e8b2dbffff           call 0x67bdd0
// 0067e21e  5d                   pop ebp
// 0067e21f  5b                   pop ebx
// 0067e220  8bc7                 mov eax, edi
// 0067e222  5f                   pop edi
// 0067e223  5e                   pop esi
// 0067e224  83c414               add esp, 0x14
// 0067e227  c21000               ret 0x10
// 0067e22a  8b442430             mov eax, dword ptr [esp + 0x30]
// 0067e22e  83c00c               add eax, 0xc
// 0067e231  57                   push edi
// 0067e232  50                   push eax
// 0067e233  ffd5                 call ebp
// 0067e235  83c408               add esp, 8
// 0067e238  84c0                 test al, al
// 0067e23a  0f848b000000         je 0x67e2cb
// 0067e240  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0067e244  8b542430             mov edx, dword ptr [esp + 0x30]
// 0067e248  8b4618               mov eax, dword ptr [esi + 0x18]
// 0067e24b  894c2410             mov dword ptr [esp + 0x10], ecx
// 0067e24f  8b0e                 mov ecx, dword ptr [esi]
// 0067e251  894c2418             mov dword ptr [esp + 0x18], ecx
// 0067e255  8d4c2410             lea ecx, [esp + 0x10]
// 0067e259  89542414             mov dword ptr [esp + 0x14], edx
// 0067e25d  8944241c             mov dword ptr [esp + 0x1c], eax
// 0067e261  e84a12feff           call 0x65f4b0
// 0067e266  8d542418             lea edx, [esp + 0x18]
// 0067e26a  52                   push edx
// 0067e26b  8d4c2414             lea ecx, [esp + 0x14]
// 0067e26f  e80c8ddeff           call 0x466f80
// 0067e274  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 0067e278  84c0                 test al, al
// 0067e27a  7511                 jne 0x67e28d
// 0067e27c  8d430c               lea eax, [ebx + 0xc]
// 0067e27f  50                   push eax
// 0067e280  57                   push edi
// 0067e281  8d4e08               lea ecx, [esi + 8]
// 0067e284  e8c74fdfff           call 0x473250
// 0067e289  84c0                 test al, al
// 0067e28b  743e                 je 0x67e2cb
// 0067e28d  8b442430             mov eax, dword ptr [esp + 0x30]
// 0067e291  8b4808               mov ecx, dword ptr [eax + 8]
// 0067e294  80793100             cmp byte ptr [ecx + 0x31], 0
// 0067e298  57                   push edi
// 0067e299  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0067e29d  8bce                 mov ecx, esi
// 0067e29f  7415                 je 0x67e2b6
// 0067e2a1  50                   push eax
// 0067e2a2  6a00                 push 0
// 0067e2a4  57                   push edi
// 0067e2a5  e826dbffff           call 0x67bdd0
// 0067e2aa  5d                   pop ebp
// 0067e2ab  5b                   pop ebx
// 0067e2ac  8bc7                 mov eax, edi
// 0067e2ae  5f                   pop edi
// 0067e2af  5e                   pop esi
// 0067e2b0  83c414               add esp, 0x14
// 0067e2b3  c21000               ret 0x10
// 0067e2b6  53                   push ebx
// 0067e2b7  6a01                 push 1
// 0067e2b9  57                   push edi
// 0067e2ba  e811dbffff           call 0x67bdd0
// 0067e2bf  5d                   pop ebp
// 0067e2c0  5b                   pop ebx
// 0067e2c1  8bc7                 mov eax, edi
// 0067e2c3  5f                   pop edi
// 0067e2c4  5e                   pop esi
// 0067e2c5  83c414               add esp, 0x14
// 0067e2c8  c21000               ret 0x10
// 0067e2cb  57                   push edi
// 0067e2cc  8d54241c             lea edx, [esp + 0x1c]
// 0067e2d0  52                   push edx
// 0067e2d1  8bce                 mov ecx, esi
// 0067e2d3  e888e8ffff           call 0x67cb60
// 0067e2d8  8b10                 mov edx, dword ptr [eax]
// 0067e2da  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0067e2de  5d                   pop ebp
// 0067e2df  5b                   pop ebx
// 0067e2e0  8911                 mov dword ptr [ecx], edx
// 0067e2e2  8b4004               mov eax, dword ptr [eax + 4]
// 0067e2e5  5f                   pop edi
// 0067e2e6  894104               mov dword ptr [ecx + 4], eax
// 0067e2e9  8bc1                 mov eax, ecx
// 0067e2eb  5e                   pop esi
// 0067e2ec  83c414               add esp, 0x14
// 0067e2ef  c21000               ret 0x10
// standard library map_str<pod8> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod8>
struct E { int v[2]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
