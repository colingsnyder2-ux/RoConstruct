// from server: 100% by auto
// roc 2009-06 00424660  unit: MainLogManager  size: 484 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00424660
//
// 00424660  55                   push ebp
// 00424661  8bec                 mov ebp, esp
// 00424663  6aff                 push -1
// 00424665  6852eb8400           push 0x84eb52
// 0042466a  64a100000000         mov eax, dword ptr fs:[0]
// 00424670  50                   push eax
// 00424671  64892500000000       mov dword ptr fs:[0], esp
// 00424678  83ec50               sub esp, 0x50
// 0042467b  53                   push ebx
// 0042467c  56                   push esi
// 0042467d  8bf1                 mov esi, ecx
// 0042467f  8b460c               mov eax, dword ptr [esi + 0xc]
// 00424682  57                   push edi
// 00424683  8965f0               mov dword ptr [ebp - 0x10], esp
// 00424686  8975e0               mov dword ptr [ebp - 0x20], esi
// 00424689  85c0                 test eax, eax
// 0042468b  7505                 jne 0x424692
// 0042468d  8945ec               mov dword ptr [ebp - 0x14], eax
// 00424690  eb1b                 jmp 0x4246ad
// 00424692  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00424695  2bc8                 sub ecx, eax
// 00424697  b893244992           mov eax, 0x92492493
// 0042469c  f7e9                 imul ecx
// 0042469e  03d1                 add edx, ecx
// 004246a0  c1fa04               sar edx, 4
// 004246a3  8bc2                 mov eax, edx
// 004246a5  c1e81f               shr eax, 0x1f
// 004246a8  03c2                 add eax, edx
// 004246aa  8945ec               mov dword ptr [ebp - 0x14], eax
// 004246ad  8b7d10               mov edi, dword ptr [ebp + 0x10]
// 004246b0  85ff                 test edi, edi
// 004246b2  0f842d030000         je 0x4249e5
// 004246b8  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 004246bb  8bcb                 mov ecx, ebx
// 004246bd  2b4e0c               sub ecx, dword ptr [esi + 0xc]
// 004246c0  b893244992           mov eax, 0x92492493
// 004246c5  f7e9                 imul ecx
// 004246c7  03d1                 add edx, ecx
// 004246c9  c1fa04               sar edx, 4
// 004246cc  8bc2                 mov eax, edx
// 004246ce  c1e81f               shr eax, 0x1f
// 004246d1  03c2                 add eax, edx
// 004246d3  b949922409           mov ecx, 0x9249249
// 004246d8  2bc8                 sub ecx, eax
// 004246da  3bcf                 cmp ecx, edi
// 004246dc  7305                 jae 0x4246e3
// 004246de  e87dbc0600           call 0x490360
// 004246e3  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 004246e6  03c7                 add eax, edi
// 004246e8  3bc8                 cmp ecx, eax
// 004246ea  0f83b6010000         jae 0x4248a6
// 004246f0  8bd1                 mov edx, ecx
// 004246f2  d1ea                 shr edx, 1
// 004246f4  bb49922409           mov ebx, 0x9249249
// 004246f9  2bda                 sub ebx, edx
// 004246fb  3bd9                 cmp ebx, ecx
// 004246fd  730c                 jae 0x42470b
// 004246ff  c745ec00000000       mov dword ptr [ebp - 0x14], 0
// 00424706  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 00424709  eb05                 jmp 0x424710
// 0042470b  03ca                 add ecx, edx
// 0042470d  894dec               mov dword ptr [ebp - 0x14], ecx
// 00424710  3bc8                 cmp ecx, eax
// 00424712  7305                 jae 0x424719
// 00424714  8945ec               mov dword ptr [ebp - 0x14], eax
// 00424717  8bc8                 mov ecx, eax
// 00424719  6a00                 push 0
// 0042471b  51                   push ecx
// 0042471c  e8bf39ffff           call 0x4180e0
// 00424721  8b5d0c               mov ebx, dword ptr [ebp + 0xc]
// 00424724  2b5e0c               sub ebx, dword ptr [esi + 0xc]
// 00424727  8bc8                 mov ecx, eax
// 00424729  b893244992           mov eax, 0x92492493
// 0042472e  f7eb                 imul ebx
// 00424730  03d3                 add edx, ebx
// 00424732  c1fa04               sar edx, 4
// 00424735  8bda                 mov ebx, edx
// 00424737  33c0                 xor eax, eax
// 00424739  c1eb1f               shr ebx, 0x1f
// 0042473c  03da                 add ebx, edx
// 0042473e  8b5514               mov edx, dword ptr [ebp + 0x14]
// 00424741  83c408               add esp, 8
// 00424744  8945e4               mov dword ptr [ebp - 0x1c], eax
// 00424747  8945fc               mov dword ptr [ebp - 4], eax
// 0042474a  52                   push edx
// 0042474b  8d04dd00000000       lea eax, [ebx*8]
// 00424752  894de8               mov dword ptr [ebp - 0x18], ecx
// 00424755  2bc3                 sub eax, ebx
// 00424757  8d0c81               lea ecx, [ecx + eax*4]
// 0042475a  57                   push edi
// 0042475b  51                   push ecx
// 0042475c  8bce                 mov ecx, esi
// 0042475e  895ddc               mov dword ptr [ebp - 0x24], ebx
// 00424761  e8bafeffff           call 0x424620
// 00424766  8b460c               mov eax, dword ptr [esi + 0xc]
// 00424769  c6451400             mov byte ptr [ebp + 0x14], 0
// 0042476d  8b5514               mov edx, dword ptr [ebp + 0x14]
// 00424770  52                   push edx
// 00424771  8b5510               mov edx, dword ptr [ebp + 0x10]
// 00424774  52                   push edx
// 00424775  8b550c               mov edx, dword ptr [ebp + 0xc]
// 00424778  8d4e08               lea ecx, [esi + 8]
// 0042477b  51                   push ecx
// 0042477c  8b4de8               mov ecx, dword ptr [ebp - 0x18]
// 0042477f  51                   push ecx
// 00424780  52                   push edx
// 00424781  50                   push eax
// 00424782  c745e401000000       mov dword ptr [ebp - 0x1c], 1
// 00424789  e812f4ffff           call 0x423ba0
// 0042478e  8b55e8               mov edx, dword ptr [ebp - 0x18]
// 00424791  8b4610               mov eax, dword ptr [esi + 0x10]
// 00424794  03df                 add ebx, edi
// 00424796  83c418               add esp, 0x18
// 00424799  8d0cdd00000000       lea ecx, [ebx*8]
// 004247a0  2bcb                 sub ecx, ebx
// 004247a2  8d0c8a               lea ecx, [edx + ecx*4]
// 004247a5  c6451400             mov byte ptr [ebp + 0x14], 0
// 004247a9  8b5514               mov edx, dword ptr [ebp + 0x14]
// 004247ac  52                   push edx
// 004247ad  8b5510               mov edx, dword ptr [ebp + 0x10]
// 004247b0  52                   push edx
// 004247b1  8d5608               lea edx, [esi + 8]
// 004247b4  52                   push edx
// 004247b5  51                   push ecx
// 004247b6  50                   push eax
// 004247b7  8b450c               mov eax, dword ptr [ebp + 0xc]
// 004247ba  50                   push eax
// 004247bb  c745e402000000       mov dword ptr [ebp - 0x1c], 2
// 004247c2  e8d9f3ffff           call 0x423ba0
// 004247c7  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 004247ca  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 004247cd  2bcb                 sub ecx, ebx
// 004247cf  b893244992           mov eax, 0x92492493
// 004247d4  f7e9                 imul ecx
// 004247d6  03d1                 add edx, ecx
// 004247d8  c1fa04               sar edx, 4
// 004247db  8bca                 mov ecx, edx
// 004247dd  c1e91f               shr ecx, 0x1f
// 004247e0  03ca                 add ecx, edx
// 004247e2  83c418               add esp, 0x18
// 004247e5  03f9                 add edi, ecx
// 004247e7  c745fcffffffff       mov dword ptr [ebp - 4], 0xffffffff
// 004247ee  85db                 test ebx, ebx
// 004247f0  7418                 je 0x42480a
// 004247f2  8b5610               mov edx, dword ptr [esi + 0x10]
// 004247f5  52                   push edx
// 004247f6  53                   push ebx
// 004247f7  8bce                 mov ecx, esi
// 004247f9  e8a239ffff           call 0x4181a0
// 004247fe  8b460c               mov eax, dword ptr [esi + 0xc]
// 00424801  50                   push eax
// 00424802  e82b422f00           call 0x718a32
// 00424807  83c404               add esp, 4
// 0042480a  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 0042480d  8d0cc500000000       lea ecx, [eax*8]
// 00424814  2bc8                 sub ecx, eax
// 00424816  8b45e8               mov eax, dword ptr [ebp - 0x18]
// 00424819  8d1488               lea edx, [eax + ecx*4]
// 0042481c  8d0cfd00000000       lea ecx, [edi*8]
// 00424823  2bcf                 sub ecx, edi
// 00424825  895614               mov dword ptr [esi + 0x14], edx
// 00424828  8d1488               lea edx, [eax + ecx*4]
// 0042482b  895610               mov dword ptr [esi + 0x10], edx
// 0042482e  89460c               mov dword ptr [esi + 0xc], eax
// 00424831  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00424834  64890d00000000       mov dword ptr fs:[0], ecx
// 0042483b  5f                   pop edi
// 0042483c  5e                   pop esi
// 0042483d  5b                   pop ebx
// 0042483e  8be5                 mov esp, ebp
// 00424840  5d                   pop ebp
// 00424841  c21000               ret 0x10
// standard library vector<string> (function ?_Insert_n@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEXV?$_Vector_const_iterator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@IABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
