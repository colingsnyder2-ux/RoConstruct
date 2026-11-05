// from server: 100% by auto
// roc 2008-06 006715f0  unit: RBX::AdornRbxGfx  size: 562 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006715f0
//
// 006715f0  83ec14               sub esp, 0x14
// 006715f3  56                   push esi
// 006715f4  8bf1                 mov esi, ecx
// 006715f6  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 006715fa  57                   push edi
// 006715fb  7521                 jne 0x67161e
// 006715fd  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00671601  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00671604  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00671608  50                   push eax
// 00671609  51                   push ecx
// 0067160a  6a01                 push 1
// 0067160c  57                   push edi
// 0067160d  8bce                 mov ecx, esi
// 0067160f  e83cf2ffff           call 0x670850
// 00671614  8bc7                 mov eax, edi
// 00671616  5f                   pop edi
// 00671617  5e                   pop esi
// 00671618  83c414               add esp, 0x14
// 0067161b  c21000               ret 0x10
// 0067161e  8b442424             mov eax, dword ptr [esp + 0x24]
// 00671622  8b5618               mov edx, dword ptr [esi + 0x18]
// 00671625  8b3a                 mov edi, dword ptr [edx]
// 00671627  8b0e                 mov ecx, dword ptr [esi]
// 00671629  53                   push ebx
// 0067162a  8b1d90288000         mov ebx, dword ptr [0x802890]
// 00671630  85c0                 test eax, eax
// 00671632  7404                 je 0x671638
// 00671634  3bc1                 cmp eax, ecx
// 00671636  7406                 je 0x67163e
// 00671638  ffd3                 call ebx
// 0067163a  8b442428             mov eax, dword ptr [esp + 0x28]
// 0067163e  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 00671642  55                   push ebp
// 00671643  3bd7                 cmp edx, edi
// 00671645  753a                 jne 0x671681
// 00671647  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 0067164b  83c20c               add edx, 0xc
// 0067164e  52                   push edx
// 0067164f  57                   push edi
// 00671650  ff155c238000         call dword ptr [0x80235c]
// 00671656  83c408               add esp, 8
// 00671659  84c0                 test al, al
// 0067165b  0f849a010000         je 0x6717fb
// 00671661  8b442430             mov eax, dword ptr [esp + 0x30]
// 00671665  57                   push edi
// 00671666  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0067166a  50                   push eax
// 0067166b  6a01                 push 1
// 0067166d  57                   push edi
// 0067166e  8bce                 mov ecx, esi
// 00671670  e8dbf1ffff           call 0x670850
// 00671675  5d                   pop ebp
// 00671676  5b                   pop ebx
// 00671677  8bc7                 mov eax, edi
// 00671679  5f                   pop edi
// 0067167a  5e                   pop esi
// 0067167b  83c414               add esp, 0x14
// 0067167e  c21000               ret 0x10
// 00671681  8b7e18               mov edi, dword ptr [esi + 0x18]
// 00671684  8b0e                 mov ecx, dword ptr [esi]
// 00671686  85c0                 test eax, eax
// 00671688  7404                 je 0x67168e
// 0067168a  3bc1                 cmp eax, ecx
// 0067168c  7406                 je 0x671694
// 0067168e  ffd3                 call ebx
// 00671690  8b542430             mov edx, dword ptr [esp + 0x30]
// 00671694  3bd7                 cmp edx, edi
// 00671696  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 0067169a  753e                 jne 0x6716da
// 0067169c  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0067169f  8b4108               mov eax, dword ptr [ecx + 8]
// 006716a2  83c00c               add eax, 0xc
// 006716a5  57                   push edi
// 006716a6  50                   push eax
// 006716a7  ff155c238000         call dword ptr [0x80235c]
// 006716ad  83c408               add esp, 8
// 006716b0  84c0                 test al, al
// 006716b2  0f8443010000         je 0x6717fb
// 006716b8  8b5618               mov edx, dword ptr [esi + 0x18]
// 006716bb  8b4208               mov eax, dword ptr [edx + 8]
// 006716be  57                   push edi
// 006716bf  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 006716c3  50                   push eax
// 006716c4  6a00                 push 0
// 006716c6  57                   push edi
// 006716c7  8bce                 mov ecx, esi
// 006716c9  e882f1ffff           call 0x670850
// 006716ce  5d                   pop ebp
// 006716cf  5b                   pop ebx
// 006716d0  8bc7                 mov eax, edi
// 006716d2  5f                   pop edi
// 006716d3  5e                   pop esi
// 006716d4  83c414               add esp, 0x14
// 006716d7  c21000               ret 0x10
// 006716da  8b2d5c238000         mov ebp, dword ptr [0x80235c]
// 006716e0  83c20c               add edx, 0xc
// 006716e3  52                   push edx
// 006716e4  57                   push edi
// 006716e5  ffd5                 call ebp
// 006716e7  83c408               add esp, 8
// 006716ea  84c0                 test al, al
// 006716ec  746c                 je 0x67175a
// 006716ee  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 006716f2  8b542430             mov edx, dword ptr [esp + 0x30]
// 006716f6  894c2410             mov dword ptr [esp + 0x10], ecx
// 006716fa  8d4c2410             lea ecx, [esp + 0x10]
// 006716fe  89542414             mov dword ptr [esp + 0x14], edx
// 00671702  e819e8ffff           call 0x66ff20
// 00671707  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 0067170b  57                   push edi
// 0067170c  8d430c               lea eax, [ebx + 0xc]
// 0067170f  50                   push eax
// 00671710  8d4e08               lea ecx, [esi + 8]
// 00671713  e8e8a8eeff           call 0x55c000
// 00671718  84c0                 test al, al
// 0067171a  743e                 je 0x67175a
// 0067171c  8b4b08               mov ecx, dword ptr [ebx + 8]
// 0067171f  80793500             cmp byte ptr [ecx + 0x35], 0
// 00671723  57                   push edi
// 00671724  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00671728  8bce                 mov ecx, esi
// 0067172a  7415                 je 0x671741
// 0067172c  53                   push ebx
// 0067172d  6a00                 push 0
// 0067172f  57                   push edi
// 00671730  e81bf1ffff           call 0x670850
// 00671735  5d                   pop ebp
// 00671736  5b                   pop ebx
// 00671737  8bc7                 mov eax, edi
// 00671739  5f                   pop edi
// 0067173a  5e                   pop esi
// 0067173b  83c414               add esp, 0x14
// 0067173e  c21000               ret 0x10
// 00671741  8b542434             mov edx, dword ptr [esp + 0x34]
// 00671745  52                   push edx
// 00671746  6a01                 push 1
// 00671748  57                   push edi
// 00671749  e802f1ffff           call 0x670850
// 0067174e  5d                   pop ebp
// 0067174f  5b                   pop ebx
// 00671750  8bc7                 mov eax, edi
// 00671752  5f                   pop edi
// 00671753  5e                   pop esi
// 00671754  83c414               add esp, 0x14
// 00671757  c21000               ret 0x10
// 0067175a  8b442430             mov eax, dword ptr [esp + 0x30]
// 0067175e  83c00c               add eax, 0xc
// 00671761  57                   push edi
// 00671762  50                   push eax
// 00671763  ffd5                 call ebp
// 00671765  83c408               add esp, 8
// 00671768  84c0                 test al, al
// 0067176a  0f848b000000         je 0x6717fb
// 00671770  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00671774  8b542430             mov edx, dword ptr [esp + 0x30]
// 00671778  8b4618               mov eax, dword ptr [esi + 0x18]
// 0067177b  894c2410             mov dword ptr [esp + 0x10], ecx
// 0067177f  8b0e                 mov ecx, dword ptr [esi]
// 00671781  894c2418             mov dword ptr [esp + 0x18], ecx
// 00671785  8d4c2410             lea ecx, [esp + 0x10]
// 00671789  89542414             mov dword ptr [esp + 0x14], edx
// 0067178d  8944241c             mov dword ptr [esp + 0x1c], eax
// 00671791  e8ca87d9ff           call 0x409f60
// 00671796  8d542418             lea edx, [esp + 0x18]
// 0067179a  52                   push edx
// 0067179b  8d4c2414             lea ecx, [esp + 0x14]
// 0067179f  e8fcb4f7ff           call 0x5ecca0
// 006717a4  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 006717a8  84c0                 test al, al
// 006717aa  7511                 jne 0x6717bd
// 006717ac  8d430c               lea eax, [ebx + 0xc]
// 006717af  50                   push eax
// 006717b0  57                   push edi
// 006717b1  8d4e08               lea ecx, [esi + 8]
// 006717b4  e847a8eeff           call 0x55c000
// 006717b9  84c0                 test al, al
// 006717bb  743e                 je 0x6717fb
// 006717bd  8b442430             mov eax, dword ptr [esp + 0x30]
// 006717c1  8b4808               mov ecx, dword ptr [eax + 8]
// 006717c4  80793500             cmp byte ptr [ecx + 0x35], 0
// 006717c8  57                   push edi
// 006717c9  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 006717cd  8bce                 mov ecx, esi
// 006717cf  7415                 je 0x6717e6
// 006717d1  50                   push eax
// 006717d2  6a00                 push 0
// 006717d4  57                   push edi
// 006717d5  e876f0ffff           call 0x670850
// 006717da  5d                   pop ebp
// 006717db  5b                   pop ebx
// 006717dc  8bc7                 mov eax, edi
// 006717de  5f                   pop edi
// 006717df  5e                   pop esi
// 006717e0  83c414               add esp, 0x14
// 006717e3  c21000               ret 0x10
// 006717e6  53                   push ebx
// 006717e7  6a01                 push 1
// 006717e9  57                   push edi
// 006717ea  e861f0ffff           call 0x670850
// 006717ef  5d                   pop ebp
// 006717f0  5b                   pop ebx
// 006717f1  8bc7                 mov eax, edi
// 006717f3  5f                   pop edi
// 006717f4  5e                   pop esi
// 006717f5  83c414               add esp, 0x14
// 006717f8  c21000               ret 0x10
// 006717fb  57                   push edi
// 006717fc  8d54241c             lea edx, [esp + 0x1c]
// 00671800  52                   push edx
// 00671801  8bce                 mov ecx, esi
// 00671803  e8e8f9ffff           call 0x6711f0
// 00671808  8b10                 mov edx, dword ptr [eax]
// 0067180a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0067180e  5d                   pop ebp
// 0067180f  5b                   pop ebx
// 00671810  8911                 mov dword ptr [ecx], edx
// 00671812  8b4004               mov eax, dword ptr [eax + 4]
// 00671815  5f                   pop edi
// 00671816  894104               mov dword ptr [ecx + 4], eax
// 00671819  8bc1                 mov eax, ecx
// 0067181b  5e                   pop esi
// 0067181c  83c414               add esp, 0x14
// 0067181f  c21000               ret 0x10
// standard library map_str<pod12> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod12>
struct E { int v[3]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
