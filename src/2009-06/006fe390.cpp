// from server: 100% by auto
// roc 2009-06 006fe390  unit: RBX::AdornRbxGfx  size: 424 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006fe390
//
// 006fe390  51                   push ecx
// 006fe391  56                   push esi
// 006fe392  8bf1                 mov esi, ecx
// 006fe394  8b560c               mov edx, dword ptr [esi + 0xc]
// 006fe397  57                   push edi
// 006fe398  85d2                 test edx, edx
// 006fe39a  7504                 jne 0x6fe3a0
// 006fe39c  33c9                 xor ecx, ecx
// 006fe39e  eb0a                 jmp 0x6fe3aa
// 006fe3a0  8b4614               mov eax, dword ptr [esi + 0x14]
// 006fe3a3  2bc2                 sub eax, edx
// 006fe3a5  c1f802               sar eax, 2
// 006fe3a8  8bc8                 mov ecx, eax
// 006fe3aa  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 006fe3ae  85ff                 test edi, edi
// 006fe3b0  0f847c010000         je 0x6fe532
// 006fe3b6  53                   push ebx
// 006fe3b7  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 006fe3ba  8bc3                 mov eax, ebx
// 006fe3bc  2bc2                 sub eax, edx
// 006fe3be  c1f802               sar eax, 2
// 006fe3c1  baffffff3f           mov edx, 0x3fffffff
// 006fe3c6  2bd0                 sub edx, eax
// 006fe3c8  3bd7                 cmp edx, edi
// 006fe3ca  7305                 jae 0x6fe3d1
// 006fe3cc  e88f1fd9ff           call 0x490360
// 006fe3d1  8d1438               lea edx, [eax + edi]
// 006fe3d4  55                   push ebp
// 006fe3d5  3bca                 cmp ecx, edx
// 006fe3d7  0f83b5000000         jae 0x6fe492
// 006fe3dd  8bc1                 mov eax, ecx
// 006fe3df  d1e8                 shr eax, 1
// 006fe3e1  bbffffff3f           mov ebx, 0x3fffffff
// 006fe3e6  2bd8                 sub ebx, eax
// 006fe3e8  3bd9                 cmp ebx, ecx
// 006fe3ea  730e                 jae 0x6fe3fa
// 006fe3ec  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006fe3f4  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006fe3f8  eb06                 jmp 0x6fe400
// 006fe3fa  03c8                 add ecx, eax
// 006fe3fc  894c2410             mov dword ptr [esp + 0x10], ecx
// 006fe400  3bca                 cmp ecx, edx
// 006fe402  7306                 jae 0x6fe40a
// 006fe404  89542410             mov dword ptr [esp + 0x10], edx
// 006fe408  8bca                 mov ecx, edx
// 006fe40a  6a00                 push 0
// 006fe40c  51                   push ecx
// 006fe40d  e8eea5efff           call 0x5f8a00
// 006fe412  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 006fe416  2b5e0c               sub ebx, dword ptr [esi + 0xc]
// 006fe419  83c408               add esp, 8
// 006fe41c  8be8                 mov ebp, eax
// 006fe41e  8b442424             mov eax, dword ptr [esp + 0x24]
// 006fe422  50                   push eax
// 006fe423  c1fb02               sar ebx, 2
// 006fe426  57                   push edi
// 006fe427  8d4c9d00             lea ecx, [ebp + ebx*4]
// 006fe42b  51                   push ecx
// 006fe42c  8bce                 mov ecx, esi
// 006fe42e  e82dcce3ff           call 0x53b060
// 006fe433  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 006fe437  8b460c               mov eax, dword ptr [esi + 0xc]
// 006fe43a  55                   push ebp
// 006fe43b  52                   push edx
// 006fe43c  50                   push eax
// 006fe43d  8bce                 mov ecx, esi
// 006fe43f  e87caefdff           call 0x6d92c0
// 006fe444  8b5610               mov edx, dword ptr [esi + 0x10]
// 006fe447  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006fe44b  03df                 add ebx, edi
// 006fe44d  8d4c9d00             lea ecx, [ebp + ebx*4]
// 006fe451  51                   push ecx
// 006fe452  52                   push edx
// 006fe453  50                   push eax
// 006fe454  8bce                 mov ecx, esi
// 006fe456  e865aefdff           call 0x6d92c0
// 006fe45b  8b460c               mov eax, dword ptr [esi + 0xc]
// 006fe45e  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 006fe461  2bc8                 sub ecx, eax
// 006fe463  c1f902               sar ecx, 2
// 006fe466  03f9                 add edi, ecx
// 006fe468  85c0                 test eax, eax
// 006fe46a  7409                 je 0x6fe475
// 006fe46c  50                   push eax
// 006fe46d  e8c0a50100           call 0x718a32
// 006fe472  83c404               add esp, 4
// 006fe475  8b542410             mov edx, dword ptr [esp + 0x10]
// 006fe479  8d4cbd00             lea ecx, [ebp + edi*4]
// 006fe47d  8d449500             lea eax, [ebp + edx*4]
// 006fe481  896e0c               mov dword ptr [esi + 0xc], ebp
// 006fe484  5d                   pop ebp
// 006fe485  5b                   pop ebx
// 006fe486  5f                   pop edi
// 006fe487  894614               mov dword ptr [esi + 0x14], eax
// 006fe48a  894e10               mov dword ptr [esi + 0x10], ecx
// 006fe48d  5e                   pop esi
// 006fe48e  59                   pop ecx
// 006fe48f  c21000               ret 0x10
// 006fe492  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006fe496  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 006fe49a  8bd3                 mov edx, ebx
// 006fe49c  2bd0                 sub edx, eax
// 006fe49e  c1fa02               sar edx, 2
// 006fe4a1  3bd7                 cmp edx, edi
// 006fe4a3  8b11                 mov edx, dword ptr [ecx]
// 006fe4a5  8d2cbd00000000       lea ebp, [edi*4]
// 006fe4ac  89542424             mov dword ptr [esp + 0x24], edx
// 006fe4b0  734c                 jae 0x6fe4fe
// 006fe4b2  8d0c28               lea ecx, [eax + ebp]
// 006fe4b5  51                   push ecx
// 006fe4b6  53                   push ebx
// 006fe4b7  50                   push eax
// 006fe4b8  8bce                 mov ecx, esi
// 006fe4ba  e801aefdff           call 0x6d92c0
// 006fe4bf  8b4610               mov eax, dword ptr [esi + 0x10]
// 006fe4c2  8bc8                 mov ecx, eax
// 006fe4c4  2b4c241c             sub ecx, dword ptr [esp + 0x1c]
// 006fe4c8  8d542424             lea edx, [esp + 0x24]
// 006fe4cc  c1f902               sar ecx, 2
// 006fe4cf  52                   push edx
// 006fe4d0  2bf9                 sub edi, ecx
// 006fe4d2  57                   push edi
// 006fe4d3  50                   push eax
// 006fe4d4  8bce                 mov ecx, esi
// 006fe4d6  e885cbe3ff           call 0x53b060
// 006fe4db  016e10               add dword ptr [esi + 0x10], ebp
// 006fe4de  8b7610               mov esi, dword ptr [esi + 0x10]
// 006fe4e1  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006fe4e5  8d542424             lea edx, [esp + 0x24]
// 006fe4e9  52                   push edx
// 006fe4ea  2bf5                 sub esi, ebp
// 006fe4ec  56                   push esi
// 006fe4ed  50                   push eax
// 006fe4ee  e80d99feff           call 0x6e7e00
// 006fe4f3  83c40c               add esp, 0xc
// 006fe4f6  5d                   pop ebp
// 006fe4f7  5b                   pop ebx
// 006fe4f8  5f                   pop edi
// 006fe4f9  5e                   pop esi
// 006fe4fa  59                   pop ecx
// 006fe4fb  c21000               ret 0x10
// 006fe4fe  53                   push ebx
// 006fe4ff  8bfb                 mov edi, ebx
// 006fe501  53                   push ebx
// 006fe502  2bfd                 sub edi, ebp
// 006fe504  57                   push edi
// 006fe505  8bce                 mov ecx, esi
// 006fe507  e8b4adfdff           call 0x6d92c0
// 006fe50c  53                   push ebx
// 006fe50d  894610               mov dword ptr [esi + 0x10], eax
// 006fe510  8b442420             mov eax, dword ptr [esp + 0x20]
// 006fe514  57                   push edi
// 006fe515  50                   push eax
// 006fe516  e8354fefff           call 0x5f3450
// 006fe51b  8b442428             mov eax, dword ptr [esp + 0x28]
// 006fe51f  8d4c2430             lea ecx, [esp + 0x30]
// 006fe523  51                   push ecx
// 006fe524  03e8                 add ebp, eax
// 006fe526  55                   push ebp
// 006fe527  50                   push eax
// 006fe528  e8d398feff           call 0x6e7e00
// 006fe52d  83c418               add esp, 0x18
// 006fe530  5d                   pop ebp
// 006fe531  5b                   pop ebx
// 006fe532  5f                   pop edi
// 006fe533  5e                   pop esi
// 006fe534  59                   pop ecx
// 006fe535  c21000               ret 0x10
// standard library vector<ptr> (function ?_Insert_n@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEXV?$_Vector_const_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@IABQAUT@@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
