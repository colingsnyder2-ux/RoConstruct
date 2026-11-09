// from server: 100% by auto
// roc 2010-06 00559460  unit: G3D::BinaryInput  size: 439 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00559460
//
// 00559460  51                   push ecx
// 00559461  56                   push esi
// 00559462  8bf1                 mov esi, ecx
// 00559464  8b560c               mov edx, dword ptr [esi + 0xc]
// 00559467  57                   push edi
// 00559468  85d2                 test edx, edx
// 0055946a  7504                 jne 0x559470
// 0055946c  33c9                 xor ecx, ecx
// 0055946e  eb09                 jmp 0x559479
// 00559470  8b4614               mov eax, dword ptr [esi + 0x14]
// 00559473  2bc2                 sub eax, edx
// 00559475  d1f8                 sar eax, 1
// 00559477  8bc8                 mov ecx, eax
// 00559479  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 0055947d  85ff                 test edi, edi
// 0055947f  0f848c010000         je 0x559611
// 00559485  53                   push ebx
// 00559486  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 00559489  8bc3                 mov eax, ebx
// 0055948b  2bc2                 sub eax, edx
// 0055948d  d1f8                 sar eax, 1
// 0055948f  baffffff7f           mov edx, 0x7fffffff
// 00559494  2bd0                 sub edx, eax
// 00559496  3bd7                 cmp edx, edi
// 00559498  7305                 jae 0x55949f
// 0055949a  e851a9ecff           call 0x423df0
// 0055949f  8d1438               lea edx, [eax + edi]
// 005594a2  55                   push ebp
// 005594a3  3bca                 cmp ecx, edx
// 005594a5  0f83cb000000         jae 0x559576
// 005594ab  8bc1                 mov eax, ecx
// 005594ad  d1e8                 shr eax, 1
// 005594af  bbffffff7f           mov ebx, 0x7fffffff
// 005594b4  2bd8                 sub ebx, eax
// 005594b6  3bd9                 cmp ebx, ecx
// 005594b8  730e                 jae 0x5594c8
// 005594ba  c744241000000000     mov dword ptr [esp + 0x10], 0
// 005594c2  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005594c6  eb06                 jmp 0x5594ce
// 005594c8  03c8                 add ecx, eax
// 005594ca  894c2410             mov dword ptr [esp + 0x10], ecx
// 005594ce  3bca                 cmp ecx, edx
// 005594d0  7306                 jae 0x5594d8
// 005594d2  89542410             mov dword ptr [esp + 0x10], edx
// 005594d6  8bca                 mov ecx, edx
// 005594d8  6a00                 push 0
// 005594da  51                   push ecx
// 005594db  e89098fcff           call 0x522d70
// 005594e0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 005594e4  2b5e0c               sub ebx, dword ptr [esi + 0xc]
// 005594e7  83c408               add esp, 8
// 005594ea  8be8                 mov ebp, eax
// 005594ec  8b442424             mov eax, dword ptr [esp + 0x24]
// 005594f0  50                   push eax
// 005594f1  d1fb                 sar ebx, 1
// 005594f3  57                   push edi
// 005594f4  8d4c5d00             lea ecx, [ebp + ebx*2]
// 005594f8  51                   push ecx
// 005594f9  8bce                 mov ecx, esi
// 005594fb  e870fdffff           call 0x559270
// 00559500  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00559504  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00559507  8bc2                 mov eax, edx
// 00559509  2bc1                 sub eax, ecx
// 0055950b  d1f8                 sar eax, 1
// 0055950d  7413                 je 0x559522
// 0055950f  03c0                 add eax, eax
// 00559511  50                   push eax
// 00559512  51                   push ecx
// 00559513  50                   push eax
// 00559514  55                   push ebp
// 00559515  ff1580a89e00         call dword ptr [0x9ea880]
// 0055951b  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 0055951f  83c410               add esp, 0x10
// 00559522  8b4610               mov eax, dword ptr [esi + 0x10]
// 00559525  2bc2                 sub eax, edx
// 00559527  d1f8                 sar eax, 1
// 00559529  7415                 je 0x559540
// 0055952b  03c0                 add eax, eax
// 0055952d  50                   push eax
// 0055952e  52                   push edx
// 0055952f  03df                 add ebx, edi
// 00559531  50                   push eax
// 00559532  8d545d00             lea edx, [ebp + ebx*2]
// 00559536  52                   push edx
// 00559537  ff1580a89e00         call dword ptr [0x9ea880]
// 0055953d  83c410               add esp, 0x10
// 00559540  8b460c               mov eax, dword ptr [esi + 0xc]
// 00559543  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00559546  2bc8                 sub ecx, eax
// 00559548  d1f9                 sar ecx, 1
// 0055954a  03f9                 add edi, ecx
// 0055954c  85c0                 test eax, eax
// 0055954e  7409                 je 0x559559
// 00559550  50                   push eax
// 00559551  e844e42400           call 0x7a799a
// 00559556  83c404               add esp, 4
// 00559559  8b542410             mov edx, dword ptr [esp + 0x10]
// 0055955d  8d4c7d00             lea ecx, [ebp + edi*2]
// 00559561  8d445500             lea eax, [ebp + edx*2]
// 00559565  896e0c               mov dword ptr [esi + 0xc], ebp
// 00559568  5d                   pop ebp
// 00559569  5b                   pop ebx
// 0055956a  5f                   pop edi
// 0055956b  894614               mov dword ptr [esi + 0x14], eax
// 0055956e  894e10               mov dword ptr [esi + 0x10], ecx
// 00559571  5e                   pop esi
// 00559572  59                   pop ecx
// 00559573  c21000               ret 0x10
// 00559576  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0055957a  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0055957e  8bd3                 mov edx, ebx
// 00559580  2bd0                 sub edx, eax
// 00559582  d1fa                 sar edx, 1
// 00559584  3bd7                 cmp edx, edi
// 00559586  0fb711               movzx edx, word ptr [ecx]
// 00559589  8d2c3f               lea ebp, [edi + edi]
// 0055958c  89542424             mov dword ptr [esp + 0x24], edx
// 00559590  734b                 jae 0x5595dd
// 00559592  8d0c28               lea ecx, [eax + ebp]
// 00559595  51                   push ecx
// 00559596  53                   push ebx
// 00559597  50                   push eax
// 00559598  8bce                 mov ecx, esi
// 0055959a  e811fbffff           call 0x5590b0
// 0055959f  8b4610               mov eax, dword ptr [esi + 0x10]
// 005595a2  8bc8                 mov ecx, eax
// 005595a4  2b4c241c             sub ecx, dword ptr [esp + 0x1c]
// 005595a8  8d542424             lea edx, [esp + 0x24]
// 005595ac  d1f9                 sar ecx, 1
// 005595ae  52                   push edx
// 005595af  2bf9                 sub edi, ecx
// 005595b1  57                   push edi
// 005595b2  50                   push eax
// 005595b3  8bce                 mov ecx, esi
// 005595b5  e8b6fcffff           call 0x559270
// 005595ba  016e10               add dword ptr [esi + 0x10], ebp
// 005595bd  8b7610               mov esi, dword ptr [esi + 0x10]
// 005595c0  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005595c4  8d542424             lea edx, [esp + 0x24]
// 005595c8  52                   push edx
// 005595c9  2bf5                 sub esi, ebp
// 005595cb  56                   push esi
// 005595cc  50                   push eax
// 005595cd  e80efaffff           call 0x558fe0
// 005595d2  83c40c               add esp, 0xc
// 005595d5  5d                   pop ebp
// 005595d6  5b                   pop ebx
// 005595d7  5f                   pop edi
// 005595d8  5e                   pop esi
// 005595d9  59                   pop ecx
// 005595da  c21000               ret 0x10
// 005595dd  53                   push ebx
// 005595de  8bfb                 mov edi, ebx
// 005595e0  53                   push ebx
// 005595e1  2bfd                 sub edi, ebp
// 005595e3  57                   push edi
// 005595e4  8bce                 mov ecx, esi
// 005595e6  e8c5faffff           call 0x5590b0
// 005595eb  53                   push ebx
// 005595ec  894610               mov dword ptr [esi + 0x10], eax
// 005595ef  8b442420             mov eax, dword ptr [esp + 0x20]
// 005595f3  57                   push edi
// 005595f4  50                   push eax
// 005595f5  e806faffff           call 0x559000
// 005595fa  8b442428             mov eax, dword ptr [esp + 0x28]
// 005595fe  8d4c2430             lea ecx, [esp + 0x30]
// 00559602  51                   push ecx
// 00559603  03e8                 add ebp, eax
// 00559605  55                   push ebp
// 00559606  50                   push eax
// 00559607  e8d4f9ffff           call 0x558fe0
// 0055960c  83c418               add esp, 0x18
// 0055960f  5d                   pop ebp
// 00559610  5b                   pop ebx
// 00559611  5f                   pop edi
// 00559612  5e                   pop esi
// 00559613  59                   pop ecx
// 00559614  c21000               ret 0x10
// standard library vector<short> (function ?_Insert_n@?$vector@FV?$allocator@F@std@@@std@@IAEXV?$_Vector_const_iterator@FV?$allocator@F@std@@@2@IABF@Z)

// stl: vector<short>
typedef short E;
#include <vector>
template class std::vector<E>;
