// from server: 100% by auto
// roc 2009-12 007c4630  unit: RBX::ChatOutput  size: 562 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007c4630
//
// 007c4630  83ec14               sub esp, 0x14
// 007c4633  56                   push esi
// 007c4634  8bf1                 mov esi, ecx
// 007c4636  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 007c463a  57                   push edi
// 007c463b  7521                 jne 0x7c465e
// 007c463d  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 007c4641  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 007c4644  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007c4648  50                   push eax
// 007c4649  51                   push ecx
// 007c464a  6a01                 push 1
// 007c464c  57                   push edi
// 007c464d  8bce                 mov ecx, esi
// 007c464f  e88cefffff           call 0x7c35e0
// 007c4654  8bc7                 mov eax, edi
// 007c4656  5f                   pop edi
// 007c4657  5e                   pop esi
// 007c4658  83c414               add esp, 0x14
// 007c465b  c21000               ret 0x10
// 007c465e  8b442424             mov eax, dword ptr [esp + 0x24]
// 007c4662  8b5618               mov edx, dword ptr [esi + 0x18]
// 007c4665  8b3a                 mov edi, dword ptr [edx]
// 007c4667  8b0e                 mov ecx, dword ptr [esi]
// 007c4669  53                   push ebx
// 007c466a  8b1d60b79800         mov ebx, dword ptr [0x98b760]
// 007c4670  85c0                 test eax, eax
// 007c4672  7404                 je 0x7c4678
// 007c4674  3bc1                 cmp eax, ecx
// 007c4676  7406                 je 0x7c467e
// 007c4678  ffd3                 call ebx
// 007c467a  8b442428             mov eax, dword ptr [esp + 0x28]
// 007c467e  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 007c4682  55                   push ebp
// 007c4683  3bd7                 cmp edx, edi
// 007c4685  753a                 jne 0x7c46c1
// 007c4687  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 007c468b  83c20c               add edx, 0xc
// 007c468e  52                   push edx
// 007c468f  57                   push edi
// 007c4690  ff15d8b59800         call dword ptr [0x98b5d8]
// 007c4696  83c408               add esp, 8
// 007c4699  84c0                 test al, al
// 007c469b  0f849a010000         je 0x7c483b
// 007c46a1  8b442430             mov eax, dword ptr [esp + 0x30]
// 007c46a5  57                   push edi
// 007c46a6  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 007c46aa  50                   push eax
// 007c46ab  6a01                 push 1
// 007c46ad  57                   push edi
// 007c46ae  8bce                 mov ecx, esi
// 007c46b0  e82befffff           call 0x7c35e0
// 007c46b5  5d                   pop ebp
// 007c46b6  5b                   pop ebx
// 007c46b7  8bc7                 mov eax, edi
// 007c46b9  5f                   pop edi
// 007c46ba  5e                   pop esi
// 007c46bb  83c414               add esp, 0x14
// 007c46be  c21000               ret 0x10
// 007c46c1  8b7e18               mov edi, dword ptr [esi + 0x18]
// 007c46c4  8b0e                 mov ecx, dword ptr [esi]
// 007c46c6  85c0                 test eax, eax
// 007c46c8  7404                 je 0x7c46ce
// 007c46ca  3bc1                 cmp eax, ecx
// 007c46cc  7406                 je 0x7c46d4
// 007c46ce  ffd3                 call ebx
// 007c46d0  8b542430             mov edx, dword ptr [esp + 0x30]
// 007c46d4  3bd7                 cmp edx, edi
// 007c46d6  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 007c46da  753e                 jne 0x7c471a
// 007c46dc  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 007c46df  8b4108               mov eax, dword ptr [ecx + 8]
// 007c46e2  83c00c               add eax, 0xc
// 007c46e5  57                   push edi
// 007c46e6  50                   push eax
// 007c46e7  ff15d8b59800         call dword ptr [0x98b5d8]
// 007c46ed  83c408               add esp, 8
// 007c46f0  84c0                 test al, al
// 007c46f2  0f8443010000         je 0x7c483b
// 007c46f8  8b5618               mov edx, dword ptr [esi + 0x18]
// 007c46fb  8b4208               mov eax, dword ptr [edx + 8]
// 007c46fe  57                   push edi
// 007c46ff  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 007c4703  50                   push eax
// 007c4704  6a00                 push 0
// 007c4706  57                   push edi
// 007c4707  8bce                 mov ecx, esi
// 007c4709  e8d2eeffff           call 0x7c35e0
// 007c470e  5d                   pop ebp
// 007c470f  5b                   pop ebx
// 007c4710  8bc7                 mov eax, edi
// 007c4712  5f                   pop edi
// 007c4713  5e                   pop esi
// 007c4714  83c414               add esp, 0x14
// 007c4717  c21000               ret 0x10
// 007c471a  8b2dd8b59800         mov ebp, dword ptr [0x98b5d8]
// 007c4720  83c20c               add edx, 0xc
// 007c4723  52                   push edx
// 007c4724  57                   push edi
// 007c4725  ffd5                 call ebp
// 007c4727  83c408               add esp, 8
// 007c472a  84c0                 test al, al
// 007c472c  746c                 je 0x7c479a
// 007c472e  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 007c4732  8b542430             mov edx, dword ptr [esp + 0x30]
// 007c4736  894c2410             mov dword ptr [esp + 0x10], ecx
// 007c473a  8d4c2410             lea ecx, [esp + 0x10]
// 007c473e  89542414             mov dword ptr [esp + 0x14], edx
// 007c4742  e899d7ffff           call 0x7c1ee0
// 007c4747  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 007c474b  57                   push edi
// 007c474c  8d430c               lea eax, [ebx + 0xc]
// 007c474f  50                   push eax
// 007c4750  8d4e08               lea ecx, [esi + 8]
// 007c4753  e8f860cbff           call 0x47a850
// 007c4758  84c0                 test al, al
// 007c475a  743e                 je 0x7c479a
// 007c475c  8b4b08               mov ecx, dword ptr [ebx + 8]
// 007c475f  80794d00             cmp byte ptr [ecx + 0x4d], 0
// 007c4763  57                   push edi
// 007c4764  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 007c4768  8bce                 mov ecx, esi
// 007c476a  7415                 je 0x7c4781
// 007c476c  53                   push ebx
// 007c476d  6a00                 push 0
// 007c476f  57                   push edi
// 007c4770  e86beeffff           call 0x7c35e0
// 007c4775  5d                   pop ebp
// 007c4776  5b                   pop ebx
// 007c4777  8bc7                 mov eax, edi
// 007c4779  5f                   pop edi
// 007c477a  5e                   pop esi
// 007c477b  83c414               add esp, 0x14
// 007c477e  c21000               ret 0x10
// 007c4781  8b542434             mov edx, dword ptr [esp + 0x34]
// 007c4785  52                   push edx
// 007c4786  6a01                 push 1
// 007c4788  57                   push edi
// 007c4789  e852eeffff           call 0x7c35e0
// 007c478e  5d                   pop ebp
// 007c478f  5b                   pop ebx
// 007c4790  8bc7                 mov eax, edi
// 007c4792  5f                   pop edi
// 007c4793  5e                   pop esi
// 007c4794  83c414               add esp, 0x14
// 007c4797  c21000               ret 0x10
// 007c479a  8b442430             mov eax, dword ptr [esp + 0x30]
// 007c479e  83c00c               add eax, 0xc
// 007c47a1  57                   push edi
// 007c47a2  50                   push eax
// 007c47a3  ffd5                 call ebp
// 007c47a5  83c408               add esp, 8
// 007c47a8  84c0                 test al, al
// 007c47aa  0f848b000000         je 0x7c483b
// 007c47b0  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 007c47b4  8b542430             mov edx, dword ptr [esp + 0x30]
// 007c47b8  8b4618               mov eax, dword ptr [esi + 0x18]
// 007c47bb  894c2410             mov dword ptr [esp + 0x10], ecx
// 007c47bf  8b0e                 mov ecx, dword ptr [esi]
// 007c47c1  894c2418             mov dword ptr [esp + 0x18], ecx
// 007c47c5  8d4c2410             lea ecx, [esp + 0x10]
// 007c47c9  89542414             mov dword ptr [esp + 0x14], edx
// 007c47cd  8944241c             mov dword ptr [esp + 0x1c], eax
// 007c47d1  e89ad6ffff           call 0x7c1e70
// 007c47d6  8d542418             lea edx, [esp + 0x18]
// 007c47da  52                   push edx
// 007c47db  8d4c2414             lea ecx, [esp + 0x14]
// 007c47df  e87c7be0ff           call 0x5cc360
// 007c47e4  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 007c47e8  84c0                 test al, al
// 007c47ea  7511                 jne 0x7c47fd
// 007c47ec  8d430c               lea eax, [ebx + 0xc]
// 007c47ef  50                   push eax
// 007c47f0  57                   push edi
// 007c47f1  8d4e08               lea ecx, [esi + 8]
// 007c47f4  e85760cbff           call 0x47a850
// 007c47f9  84c0                 test al, al
// 007c47fb  743e                 je 0x7c483b
// 007c47fd  8b442430             mov eax, dword ptr [esp + 0x30]
// 007c4801  8b4808               mov ecx, dword ptr [eax + 8]
// 007c4804  80794d00             cmp byte ptr [ecx + 0x4d], 0
// 007c4808  57                   push edi
// 007c4809  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 007c480d  8bce                 mov ecx, esi
// 007c480f  7415                 je 0x7c4826
// 007c4811  50                   push eax
// 007c4812  6a00                 push 0
// 007c4814  57                   push edi
// 007c4815  e8c6edffff           call 0x7c35e0
// 007c481a  5d                   pop ebp
// 007c481b  5b                   pop ebx
// 007c481c  8bc7                 mov eax, edi
// 007c481e  5f                   pop edi
// 007c481f  5e                   pop esi
// 007c4820  83c414               add esp, 0x14
// 007c4823  c21000               ret 0x10
// 007c4826  53                   push ebx
// 007c4827  6a01                 push 1
// 007c4829  57                   push edi
// 007c482a  e8b1edffff           call 0x7c35e0
// 007c482f  5d                   pop ebp
// 007c4830  5b                   pop ebx
// 007c4831  8bc7                 mov eax, edi
// 007c4833  5f                   pop edi
// 007c4834  5e                   pop esi
// 007c4835  83c414               add esp, 0x14
// 007c4838  c21000               ret 0x10
// 007c483b  57                   push edi
// 007c483c  8d54241c             lea edx, [esp + 0x1c]
// 007c4840  52                   push edx
// 007c4841  8bce                 mov ecx, esi
// 007c4843  e848fbffff           call 0x7c4390
// 007c4848  8b10                 mov edx, dword ptr [eax]
// 007c484a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007c484e  5d                   pop ebp
// 007c484f  5b                   pop ebx
// 007c4850  8911                 mov dword ptr [ecx], edx
// 007c4852  8b4004               mov eax, dword ptr [eax + 4]
// 007c4855  5f                   pop edi
// 007c4856  894104               mov dword ptr [ecx + 4], eax
// 007c4859  8bc1                 mov eax, ecx
// 007c485b  5e                   pop esi
// 007c485c  83c414               add esp, 0x14
// 007c485f  c21000               ret 0x10
// standard library map_str<pod36> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod36>
struct E { int v[9]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
