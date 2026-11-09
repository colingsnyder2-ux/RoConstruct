// from server: 100% by auto
// roc 2009-06 004775a0  unit: Ogre::RbxMeshLoader  size: 562 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004775a0
//
// 004775a0  83ec14               sub esp, 0x14
// 004775a3  56                   push esi
// 004775a4  8bf1                 mov esi, ecx
// 004775a6  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 004775aa  57                   push edi
// 004775ab  7521                 jne 0x4775ce
// 004775ad  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 004775b1  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004775b4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004775b8  50                   push eax
// 004775b9  51                   push ecx
// 004775ba  6a01                 push 1
// 004775bc  57                   push edi
// 004775bd  8bce                 mov ecx, esi
// 004775bf  e82cf1ffff           call 0x4766f0
// 004775c4  8bc7                 mov eax, edi
// 004775c6  5f                   pop edi
// 004775c7  5e                   pop esi
// 004775c8  83c414               add esp, 0x14
// 004775cb  c21000               ret 0x10
// 004775ce  8b442424             mov eax, dword ptr [esp + 0x24]
// 004775d2  8b5618               mov edx, dword ptr [esi + 0x18]
// 004775d5  8b3a                 mov edi, dword ptr [edx]
// 004775d7  8b0e                 mov ecx, dword ptr [esi]
// 004775d9  53                   push ebx
// 004775da  8b1dace98900         mov ebx, dword ptr [0x89e9ac]
// 004775e0  85c0                 test eax, eax
// 004775e2  7404                 je 0x4775e8
// 004775e4  3bc1                 cmp eax, ecx
// 004775e6  7406                 je 0x4775ee
// 004775e8  ffd3                 call ebx
// 004775ea  8b442428             mov eax, dword ptr [esp + 0x28]
// 004775ee  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 004775f2  55                   push ebp
// 004775f3  3bd7                 cmp edx, edi
// 004775f5  753a                 jne 0x477631
// 004775f7  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 004775fb  83c20c               add edx, 0xc
// 004775fe  52                   push edx
// 004775ff  57                   push edi
// 00477600  ff15e0e48900         call dword ptr [0x89e4e0]
// 00477606  83c408               add esp, 8
// 00477609  84c0                 test al, al
// 0047760b  0f849a010000         je 0x4777ab
// 00477611  8b442430             mov eax, dword ptr [esp + 0x30]
// 00477615  57                   push edi
// 00477616  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0047761a  50                   push eax
// 0047761b  6a01                 push 1
// 0047761d  57                   push edi
// 0047761e  8bce                 mov ecx, esi
// 00477620  e8cbf0ffff           call 0x4766f0
// 00477625  5d                   pop ebp
// 00477626  5b                   pop ebx
// 00477627  8bc7                 mov eax, edi
// 00477629  5f                   pop edi
// 0047762a  5e                   pop esi
// 0047762b  83c414               add esp, 0x14
// 0047762e  c21000               ret 0x10
// 00477631  8b7e18               mov edi, dword ptr [esi + 0x18]
// 00477634  8b0e                 mov ecx, dword ptr [esi]
// 00477636  85c0                 test eax, eax
// 00477638  7404                 je 0x47763e
// 0047763a  3bc1                 cmp eax, ecx
// 0047763c  7406                 je 0x477644
// 0047763e  ffd3                 call ebx
// 00477640  8b542430             mov edx, dword ptr [esp + 0x30]
// 00477644  3bd7                 cmp edx, edi
// 00477646  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 0047764a  753e                 jne 0x47768a
// 0047764c  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0047764f  8b4108               mov eax, dword ptr [ecx + 8]
// 00477652  83c00c               add eax, 0xc
// 00477655  57                   push edi
// 00477656  50                   push eax
// 00477657  ff15e0e48900         call dword ptr [0x89e4e0]
// 0047765d  83c408               add esp, 8
// 00477660  84c0                 test al, al
// 00477662  0f8443010000         je 0x4777ab
// 00477668  8b5618               mov edx, dword ptr [esi + 0x18]
// 0047766b  8b4208               mov eax, dword ptr [edx + 8]
// 0047766e  57                   push edi
// 0047766f  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00477673  50                   push eax
// 00477674  6a00                 push 0
// 00477676  57                   push edi
// 00477677  8bce                 mov ecx, esi
// 00477679  e872f0ffff           call 0x4766f0
// 0047767e  5d                   pop ebp
// 0047767f  5b                   pop ebx
// 00477680  8bc7                 mov eax, edi
// 00477682  5f                   pop edi
// 00477683  5e                   pop esi
// 00477684  83c414               add esp, 0x14
// 00477687  c21000               ret 0x10
// 0047768a  8b2de0e48900         mov ebp, dword ptr [0x89e4e0]
// 00477690  83c20c               add edx, 0xc
// 00477693  52                   push edx
// 00477694  57                   push edi
// 00477695  ffd5                 call ebp
// 00477697  83c408               add esp, 8
// 0047769a  84c0                 test al, al
// 0047769c  746c                 je 0x47770a
// 0047769e  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 004776a2  8b542430             mov edx, dword ptr [esp + 0x30]
// 004776a6  894c2410             mov dword ptr [esp + 0x10], ecx
// 004776aa  8d4c2410             lea ecx, [esp + 0x10]
// 004776ae  89542414             mov dword ptr [esp + 0x14], edx
// 004776b2  e889e8ffff           call 0x475f40
// 004776b7  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 004776bb  57                   push edi
// 004776bc  8d430c               lea eax, [ebx + 0xc]
// 004776bf  50                   push eax
// 004776c0  8d4e08               lea ecx, [esi + 8]
// 004776c3  e848191600           call 0x5d9010
// 004776c8  84c0                 test al, al
// 004776ca  743e                 je 0x47770a
// 004776cc  8b4b08               mov ecx, dword ptr [ebx + 8]
// 004776cf  80794500             cmp byte ptr [ecx + 0x45], 0
// 004776d3  57                   push edi
// 004776d4  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 004776d8  8bce                 mov ecx, esi
// 004776da  7415                 je 0x4776f1
// 004776dc  53                   push ebx
// 004776dd  6a00                 push 0
// 004776df  57                   push edi
// 004776e0  e80bf0ffff           call 0x4766f0
// 004776e5  5d                   pop ebp
// 004776e6  5b                   pop ebx
// 004776e7  8bc7                 mov eax, edi
// 004776e9  5f                   pop edi
// 004776ea  5e                   pop esi
// 004776eb  83c414               add esp, 0x14
// 004776ee  c21000               ret 0x10
// 004776f1  8b542434             mov edx, dword ptr [esp + 0x34]
// 004776f5  52                   push edx
// 004776f6  6a01                 push 1
// 004776f8  57                   push edi
// 004776f9  e8f2efffff           call 0x4766f0
// 004776fe  5d                   pop ebp
// 004776ff  5b                   pop ebx
// 00477700  8bc7                 mov eax, edi
// 00477702  5f                   pop edi
// 00477703  5e                   pop esi
// 00477704  83c414               add esp, 0x14
// 00477707  c21000               ret 0x10
// 0047770a  8b442430             mov eax, dword ptr [esp + 0x30]
// 0047770e  83c00c               add eax, 0xc
// 00477711  57                   push edi
// 00477712  50                   push eax
// 00477713  ffd5                 call ebp
// 00477715  83c408               add esp, 8
// 00477718  84c0                 test al, al
// 0047771a  0f848b000000         je 0x4777ab
// 00477720  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00477724  8b542430             mov edx, dword ptr [esp + 0x30]
// 00477728  8b4618               mov eax, dword ptr [esi + 0x18]
// 0047772b  894c2410             mov dword ptr [esp + 0x10], ecx
// 0047772f  8b0e                 mov ecx, dword ptr [esi]
// 00477731  894c2418             mov dword ptr [esp + 0x18], ecx
// 00477735  8d4c2410             lea ecx, [esp + 0x10]
// 00477739  89542414             mov dword ptr [esp + 0x14], edx
// 0047773d  8944241c             mov dword ptr [esp + 0x1c], eax
// 00477741  e86ac8f9ff           call 0x413fb0
// 00477746  8d542418             lea edx, [esp + 0x18]
// 0047774a  52                   push edx
// 0047774b  8d4c2414             lea ecx, [esp + 0x14]
// 0047774f  e84cbd1c00           call 0x6434a0
// 00477754  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 00477758  84c0                 test al, al
// 0047775a  7511                 jne 0x47776d
// 0047775c  8d430c               lea eax, [ebx + 0xc]
// 0047775f  50                   push eax
// 00477760  57                   push edi
// 00477761  8d4e08               lea ecx, [esi + 8]
// 00477764  e8a7181600           call 0x5d9010
// 00477769  84c0                 test al, al
// 0047776b  743e                 je 0x4777ab
// 0047776d  8b442430             mov eax, dword ptr [esp + 0x30]
// 00477771  8b4808               mov ecx, dword ptr [eax + 8]
// 00477774  80794500             cmp byte ptr [ecx + 0x45], 0
// 00477778  57                   push edi
// 00477779  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0047777d  8bce                 mov ecx, esi
// 0047777f  7415                 je 0x477796
// 00477781  50                   push eax
// 00477782  6a00                 push 0
// 00477784  57                   push edi
// 00477785  e866efffff           call 0x4766f0
// 0047778a  5d                   pop ebp
// 0047778b  5b                   pop ebx
// 0047778c  8bc7                 mov eax, edi
// 0047778e  5f                   pop edi
// 0047778f  5e                   pop esi
// 00477790  83c414               add esp, 0x14
// 00477793  c21000               ret 0x10
// 00477796  53                   push ebx
// 00477797  6a01                 push 1
// 00477799  57                   push edi
// 0047779a  e851efffff           call 0x4766f0
// 0047779f  5d                   pop ebp
// 004777a0  5b                   pop ebx
// 004777a1  8bc7                 mov eax, edi
// 004777a3  5f                   pop edi
// 004777a4  5e                   pop esi
// 004777a5  83c414               add esp, 0x14
// 004777a8  c21000               ret 0x10
// 004777ab  57                   push edi
// 004777ac  8d54241c             lea edx, [esp + 0x1c]
// 004777b0  52                   push edx
// 004777b1  8bce                 mov ecx, esi
// 004777b3  e8f8f1ffff           call 0x4769b0
// 004777b8  8b10                 mov edx, dword ptr [eax]
// 004777ba  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004777be  5d                   pop ebp
// 004777bf  5b                   pop ebx
// 004777c0  8911                 mov dword ptr [ecx], edx
// 004777c2  8b4004               mov eax, dword ptr [eax + 4]
// 004777c5  5f                   pop edi
// 004777c6  894104               mov dword ptr [ecx + 4], eax
// 004777c9  8bc1                 mov eax, ecx
// 004777cb  5e                   pop esi
// 004777cc  83c414               add esp, 0x14
// 004777cf  c21000               ret 0x10
// standard library map_str<string> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@2@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
