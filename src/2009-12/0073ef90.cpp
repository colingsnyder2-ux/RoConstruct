// from server: 100% by auto
// roc 2009-12 0073ef90  unit: RBX::VInstance::V?$shared_ptr::V?$vector::V?$copy_on_write_ptr::?$sp_counted_impl_p  size: 562 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0073ef90
//
// 0073ef90  83ec14               sub esp, 0x14
// 0073ef93  56                   push esi
// 0073ef94  8bf1                 mov esi, ecx
// 0073ef96  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 0073ef9a  57                   push edi
// 0073ef9b  7521                 jne 0x73efbe
// 0073ef9d  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0073efa1  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0073efa4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0073efa8  50                   push eax
// 0073efa9  51                   push ecx
// 0073efaa  6a01                 push 1
// 0073efac  57                   push edi
// 0073efad  8bce                 mov ecx, esi
// 0073efaf  e83cc7f4ff           call 0x68b6f0
// 0073efb4  8bc7                 mov eax, edi
// 0073efb6  5f                   pop edi
// 0073efb7  5e                   pop esi
// 0073efb8  83c414               add esp, 0x14
// 0073efbb  c21000               ret 0x10
// 0073efbe  8b442424             mov eax, dword ptr [esp + 0x24]
// 0073efc2  8b5618               mov edx, dword ptr [esi + 0x18]
// 0073efc5  8b3a                 mov edi, dword ptr [edx]
// 0073efc7  8b0e                 mov ecx, dword ptr [esi]
// 0073efc9  53                   push ebx
// 0073efca  8b1d60b79800         mov ebx, dword ptr [0x98b760]
// 0073efd0  85c0                 test eax, eax
// 0073efd2  7404                 je 0x73efd8
// 0073efd4  3bc1                 cmp eax, ecx
// 0073efd6  7406                 je 0x73efde
// 0073efd8  ffd3                 call ebx
// 0073efda  8b442428             mov eax, dword ptr [esp + 0x28]
// 0073efde  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 0073efe2  55                   push ebp
// 0073efe3  3bd7                 cmp edx, edi
// 0073efe5  753a                 jne 0x73f021
// 0073efe7  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 0073efeb  83c20c               add edx, 0xc
// 0073efee  52                   push edx
// 0073efef  57                   push edi
// 0073eff0  ff15d8b59800         call dword ptr [0x98b5d8]
// 0073eff6  83c408               add esp, 8
// 0073eff9  84c0                 test al, al
// 0073effb  0f849a010000         je 0x73f19b
// 0073f001  8b442430             mov eax, dword ptr [esp + 0x30]
// 0073f005  57                   push edi
// 0073f006  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0073f00a  50                   push eax
// 0073f00b  6a01                 push 1
// 0073f00d  57                   push edi
// 0073f00e  8bce                 mov ecx, esi
// 0073f010  e8dbc6f4ff           call 0x68b6f0
// 0073f015  5d                   pop ebp
// 0073f016  5b                   pop ebx
// 0073f017  8bc7                 mov eax, edi
// 0073f019  5f                   pop edi
// 0073f01a  5e                   pop esi
// 0073f01b  83c414               add esp, 0x14
// 0073f01e  c21000               ret 0x10
// 0073f021  8b7e18               mov edi, dword ptr [esi + 0x18]
// 0073f024  8b0e                 mov ecx, dword ptr [esi]
// 0073f026  85c0                 test eax, eax
// 0073f028  7404                 je 0x73f02e
// 0073f02a  3bc1                 cmp eax, ecx
// 0073f02c  7406                 je 0x73f034
// 0073f02e  ffd3                 call ebx
// 0073f030  8b542430             mov edx, dword ptr [esp + 0x30]
// 0073f034  3bd7                 cmp edx, edi
// 0073f036  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 0073f03a  753e                 jne 0x73f07a
// 0073f03c  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0073f03f  8b4108               mov eax, dword ptr [ecx + 8]
// 0073f042  83c00c               add eax, 0xc
// 0073f045  57                   push edi
// 0073f046  50                   push eax
// 0073f047  ff15d8b59800         call dword ptr [0x98b5d8]
// 0073f04d  83c408               add esp, 8
// 0073f050  84c0                 test al, al
// 0073f052  0f8443010000         je 0x73f19b
// 0073f058  8b5618               mov edx, dword ptr [esi + 0x18]
// 0073f05b  8b4208               mov eax, dword ptr [edx + 8]
// 0073f05e  57                   push edi
// 0073f05f  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0073f063  50                   push eax
// 0073f064  6a00                 push 0
// 0073f066  57                   push edi
// 0073f067  8bce                 mov ecx, esi
// 0073f069  e882c6f4ff           call 0x68b6f0
// 0073f06e  5d                   pop ebp
// 0073f06f  5b                   pop ebx
// 0073f070  8bc7                 mov eax, edi
// 0073f072  5f                   pop edi
// 0073f073  5e                   pop esi
// 0073f074  83c414               add esp, 0x14
// 0073f077  c21000               ret 0x10
// 0073f07a  8b2dd8b59800         mov ebp, dword ptr [0x98b5d8]
// 0073f080  83c20c               add edx, 0xc
// 0073f083  52                   push edx
// 0073f084  57                   push edi
// 0073f085  ffd5                 call ebp
// 0073f087  83c408               add esp, 8
// 0073f08a  84c0                 test al, al
// 0073f08c  746c                 je 0x73f0fa
// 0073f08e  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0073f092  8b542430             mov edx, dword ptr [esp + 0x30]
// 0073f096  894c2410             mov dword ptr [esp + 0x10], ecx
// 0073f09a  8d4c2410             lea ecx, [esp + 0x10]
// 0073f09e  89542414             mov dword ptr [esp + 0x14], edx
// 0073f0a2  e8b947ddff           call 0x513860
// 0073f0a7  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 0073f0ab  57                   push edi
// 0073f0ac  8d430c               lea eax, [ebx + 0xc]
// 0073f0af  50                   push eax
// 0073f0b0  8d4e08               lea ecx, [esi + 8]
// 0073f0b3  e898b7d3ff           call 0x47a850
// 0073f0b8  84c0                 test al, al
// 0073f0ba  743e                 je 0x73f0fa
// 0073f0bc  8b4b08               mov ecx, dword ptr [ebx + 8]
// 0073f0bf  80793100             cmp byte ptr [ecx + 0x31], 0
// 0073f0c3  57                   push edi
// 0073f0c4  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0073f0c8  8bce                 mov ecx, esi
// 0073f0ca  7415                 je 0x73f0e1
// 0073f0cc  53                   push ebx
// 0073f0cd  6a00                 push 0
// 0073f0cf  57                   push edi
// 0073f0d0  e81bc6f4ff           call 0x68b6f0
// 0073f0d5  5d                   pop ebp
// 0073f0d6  5b                   pop ebx
// 0073f0d7  8bc7                 mov eax, edi
// 0073f0d9  5f                   pop edi
// 0073f0da  5e                   pop esi
// 0073f0db  83c414               add esp, 0x14
// 0073f0de  c21000               ret 0x10
// 0073f0e1  8b542434             mov edx, dword ptr [esp + 0x34]
// 0073f0e5  52                   push edx
// 0073f0e6  6a01                 push 1
// 0073f0e8  57                   push edi
// 0073f0e9  e802c6f4ff           call 0x68b6f0
// 0073f0ee  5d                   pop ebp
// 0073f0ef  5b                   pop ebx
// 0073f0f0  8bc7                 mov eax, edi
// 0073f0f2  5f                   pop edi
// 0073f0f3  5e                   pop esi
// 0073f0f4  83c414               add esp, 0x14
// 0073f0f7  c21000               ret 0x10
// 0073f0fa  8b442430             mov eax, dword ptr [esp + 0x30]
// 0073f0fe  83c00c               add eax, 0xc
// 0073f101  57                   push edi
// 0073f102  50                   push eax
// 0073f103  ffd5                 call ebp
// 0073f105  83c408               add esp, 8
// 0073f108  84c0                 test al, al
// 0073f10a  0f848b000000         je 0x73f19b
// 0073f110  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0073f114  8b542430             mov edx, dword ptr [esp + 0x30]
// 0073f118  8b4618               mov eax, dword ptr [esi + 0x18]
// 0073f11b  894c2410             mov dword ptr [esp + 0x10], ecx
// 0073f11f  8b0e                 mov ecx, dword ptr [esi]
// 0073f121  894c2418             mov dword ptr [esp + 0x18], ecx
// 0073f125  8d4c2410             lea ecx, [esp + 0x10]
// 0073f129  89542414             mov dword ptr [esp + 0x14], edx
// 0073f12d  8944241c             mov dword ptr [esp + 0x1c], eax
// 0073f131  e8ba47ddff           call 0x5138f0
// 0073f136  8d542418             lea edx, [esp + 0x18]
// 0073f13a  52                   push edx
// 0073f13b  8d4c2414             lea ecx, [esp + 0x14]
// 0073f13f  e81cd2e8ff           call 0x5cc360
// 0073f144  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 0073f148  84c0                 test al, al
// 0073f14a  7511                 jne 0x73f15d
// 0073f14c  8d430c               lea eax, [ebx + 0xc]
// 0073f14f  50                   push eax
// 0073f150  57                   push edi
// 0073f151  8d4e08               lea ecx, [esi + 8]
// 0073f154  e8f7b6d3ff           call 0x47a850
// 0073f159  84c0                 test al, al
// 0073f15b  743e                 je 0x73f19b
// 0073f15d  8b442430             mov eax, dword ptr [esp + 0x30]
// 0073f161  8b4808               mov ecx, dword ptr [eax + 8]
// 0073f164  80793100             cmp byte ptr [ecx + 0x31], 0
// 0073f168  57                   push edi
// 0073f169  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0073f16d  8bce                 mov ecx, esi
// 0073f16f  7415                 je 0x73f186
// 0073f171  50                   push eax
// 0073f172  6a00                 push 0
// 0073f174  57                   push edi
// 0073f175  e876c5f4ff           call 0x68b6f0
// 0073f17a  5d                   pop ebp
// 0073f17b  5b                   pop ebx
// 0073f17c  8bc7                 mov eax, edi
// 0073f17e  5f                   pop edi
// 0073f17f  5e                   pop esi
// 0073f180  83c414               add esp, 0x14
// 0073f183  c21000               ret 0x10
// 0073f186  53                   push ebx
// 0073f187  6a01                 push 1
// 0073f189  57                   push edi
// 0073f18a  e861c5f4ff           call 0x68b6f0
// 0073f18f  5d                   pop ebp
// 0073f190  5b                   pop ebx
// 0073f191  8bc7                 mov eax, edi
// 0073f193  5f                   pop edi
// 0073f194  5e                   pop esi
// 0073f195  83c414               add esp, 0x14
// 0073f198  c21000               ret 0x10
// 0073f19b  57                   push edi
// 0073f19c  8d54241c             lea edx, [esp + 0x1c]
// 0073f1a0  52                   push edx
// 0073f1a1  8bce                 mov ecx, esi
// 0073f1a3  e848c7f4ff           call 0x68b8f0
// 0073f1a8  8b10                 mov edx, dword ptr [eax]
// 0073f1aa  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0073f1ae  5d                   pop ebp
// 0073f1af  5b                   pop ebx
// 0073f1b0  8911                 mov dword ptr [ecx], edx
// 0073f1b2  8b4004               mov eax, dword ptr [eax + 4]
// 0073f1b5  5f                   pop edi
// 0073f1b6  894104               mov dword ptr [ecx + 4], eax
// 0073f1b9  8bc1                 mov eax, ecx
// 0073f1bb  5e                   pop esi
// 0073f1bc  83c414               add esp, 0x14
// 0073f1bf  c21000               ret 0x10
// standard library map_str<pod8> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod8>
struct E { int v[2]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
