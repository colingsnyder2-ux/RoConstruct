// from server: 100% by auto
// roc 2009-12 005b0850  unit: seg_005b0000  size: 439 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005b0850
//
// 005b0850  51                   push ecx
// 005b0851  56                   push esi
// 005b0852  8bf1                 mov esi, ecx
// 005b0854  8b560c               mov edx, dword ptr [esi + 0xc]
// 005b0857  57                   push edi
// 005b0858  85d2                 test edx, edx
// 005b085a  7504                 jne 0x5b0860
// 005b085c  33c9                 xor ecx, ecx
// 005b085e  eb09                 jmp 0x5b0869
// 005b0860  8b4614               mov eax, dword ptr [esi + 0x14]
// 005b0863  2bc2                 sub eax, edx
// 005b0865  d1f8                 sar eax, 1
// 005b0867  8bc8                 mov ecx, eax
// 005b0869  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 005b086d  85ff                 test edi, edi
// 005b086f  0f848c010000         je 0x5b0a01
// 005b0875  53                   push ebx
// 005b0876  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 005b0879  8bc3                 mov eax, ebx
// 005b087b  2bc2                 sub eax, edx
// 005b087d  d1f8                 sar eax, 1
// 005b087f  baffffff7f           mov edx, 0x7fffffff
// 005b0884  2bd0                 sub edx, eax
// 005b0886  3bd7                 cmp edx, edi
// 005b0888  7305                 jae 0x5b088f
// 005b088a  e8d118e9ff           call 0x442160
// 005b088f  8d1438               lea edx, [eax + edi]
// 005b0892  55                   push ebp
// 005b0893  3bca                 cmp ecx, edx
// 005b0895  0f83cb000000         jae 0x5b0966
// 005b089b  8bc1                 mov eax, ecx
// 005b089d  d1e8                 shr eax, 1
// 005b089f  bbffffff7f           mov ebx, 0x7fffffff
// 005b08a4  2bd8                 sub ebx, eax
// 005b08a6  3bd9                 cmp ebx, ecx
// 005b08a8  730e                 jae 0x5b08b8
// 005b08aa  c744241000000000     mov dword ptr [esp + 0x10], 0
// 005b08b2  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005b08b6  eb06                 jmp 0x5b08be
// 005b08b8  03c8                 add ecx, eax
// 005b08ba  894c2410             mov dword ptr [esp + 0x10], ecx
// 005b08be  3bca                 cmp ecx, edx
// 005b08c0  7306                 jae 0x5b08c8
// 005b08c2  89542410             mov dword ptr [esp + 0x10], edx
// 005b08c6  8bca                 mov ecx, edx
// 005b08c8  6a00                 push 0
// 005b08ca  51                   push ecx
// 005b08cb  e8909eeeff           call 0x49a760
// 005b08d0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 005b08d4  2b5e0c               sub ebx, dword ptr [esi + 0xc]
// 005b08d7  83c408               add esp, 8
// 005b08da  8be8                 mov ebp, eax
// 005b08dc  8b442424             mov eax, dword ptr [esp + 0x24]
// 005b08e0  50                   push eax
// 005b08e1  d1fb                 sar ebx, 1
// 005b08e3  57                   push edi
// 005b08e4  8d4c5d00             lea ecx, [ebp + ebx*2]
// 005b08e8  51                   push ecx
// 005b08e9  8bce                 mov ecx, esi
// 005b08eb  e830ffffff           call 0x5b0820
// 005b08f0  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 005b08f4  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 005b08f7  8bc2                 mov eax, edx
// 005b08f9  2bc1                 sub eax, ecx
// 005b08fb  d1f8                 sar eax, 1
// 005b08fd  7413                 je 0x5b0912
// 005b08ff  03c0                 add eax, eax
// 005b0901  50                   push eax
// 005b0902  51                   push ecx
// 005b0903  50                   push eax
// 005b0904  55                   push ebp
// 005b0905  ff15c0b79800         call dword ptr [0x98b7c0]
// 005b090b  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 005b090f  83c410               add esp, 0x10
// 005b0912  8b4610               mov eax, dword ptr [esi + 0x10]
// 005b0915  2bc2                 sub eax, edx
// 005b0917  d1f8                 sar eax, 1
// 005b0919  7415                 je 0x5b0930
// 005b091b  03c0                 add eax, eax
// 005b091d  50                   push eax
// 005b091e  52                   push edx
// 005b091f  03df                 add ebx, edi
// 005b0921  50                   push eax
// 005b0922  8d545d00             lea edx, [ebp + ebx*2]
// 005b0926  52                   push edx
// 005b0927  ff15c0b79800         call dword ptr [0x98b7c0]
// 005b092d  83c410               add esp, 0x10
// 005b0930  8b460c               mov eax, dword ptr [esi + 0xc]
// 005b0933  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 005b0936  2bc8                 sub ecx, eax
// 005b0938  d1f9                 sar ecx, 1
// 005b093a  03f9                 add edi, ecx
// 005b093c  85c0                 test eax, eax
// 005b093e  7409                 je 0x5b0949
// 005b0940  50                   push eax
// 005b0941  e8142f2400           call 0x7f385a
// 005b0946  83c404               add esp, 4
// 005b0949  8b542410             mov edx, dword ptr [esp + 0x10]
// 005b094d  8d4c7d00             lea ecx, [ebp + edi*2]
// 005b0951  8d445500             lea eax, [ebp + edx*2]
// 005b0955  896e0c               mov dword ptr [esi + 0xc], ebp
// 005b0958  5d                   pop ebp
// 005b0959  5b                   pop ebx
// 005b095a  5f                   pop edi
// 005b095b  894614               mov dword ptr [esi + 0x14], eax
// 005b095e  894e10               mov dword ptr [esi + 0x10], ecx
// 005b0961  5e                   pop esi
// 005b0962  59                   pop ecx
// 005b0963  c21000               ret 0x10
// 005b0966  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005b096a  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 005b096e  8bd3                 mov edx, ebx
// 005b0970  2bd0                 sub edx, eax
// 005b0972  d1fa                 sar edx, 1
// 005b0974  3bd7                 cmp edx, edi
// 005b0976  0fb711               movzx edx, word ptr [ecx]
// 005b0979  8d2c3f               lea ebp, [edi + edi]
// 005b097c  89542424             mov dword ptr [esp + 0x24], edx
// 005b0980  734b                 jae 0x5b09cd
// 005b0982  8d0c28               lea ecx, [eax + ebp]
// 005b0985  51                   push ecx
// 005b0986  53                   push ebx
// 005b0987  50                   push eax
// 005b0988  8bce                 mov ecx, esi
// 005b098a  e8c1fdffff           call 0x5b0750
// 005b098f  8b4610               mov eax, dword ptr [esi + 0x10]
// 005b0992  8bc8                 mov ecx, eax
// 005b0994  2b4c241c             sub ecx, dword ptr [esp + 0x1c]
// 005b0998  8d542424             lea edx, [esp + 0x24]
// 005b099c  d1f9                 sar ecx, 1
// 005b099e  52                   push edx
// 005b099f  2bf9                 sub edi, ecx
// 005b09a1  57                   push edi
// 005b09a2  50                   push eax
// 005b09a3  8bce                 mov ecx, esi
// 005b09a5  e876feffff           call 0x5b0820
// 005b09aa  016e10               add dword ptr [esi + 0x10], ebp
// 005b09ad  8b7610               mov esi, dword ptr [esi + 0x10]
// 005b09b0  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005b09b4  8d542424             lea edx, [esp + 0x24]
// 005b09b8  52                   push edx
// 005b09b9  2bf5                 sub esi, ebp
// 005b09bb  56                   push esi
// 005b09bc  50                   push eax
// 005b09bd  e89efcffff           call 0x5b0660
// 005b09c2  83c40c               add esp, 0xc
// 005b09c5  5d                   pop ebp
// 005b09c6  5b                   pop ebx
// 005b09c7  5f                   pop edi
// 005b09c8  5e                   pop esi
// 005b09c9  59                   pop ecx
// 005b09ca  c21000               ret 0x10
// 005b09cd  53                   push ebx
// 005b09ce  8bfb                 mov edi, ebx
// 005b09d0  53                   push ebx
// 005b09d1  2bfd                 sub edi, ebp
// 005b09d3  57                   push edi
// 005b09d4  8bce                 mov ecx, esi
// 005b09d6  e875fdffff           call 0x5b0750
// 005b09db  53                   push ebx
// 005b09dc  894610               mov dword ptr [esi + 0x10], eax
// 005b09df  8b442420             mov eax, dword ptr [esp + 0x20]
// 005b09e3  57                   push edi
// 005b09e4  50                   push eax
// 005b09e5  e896fcffff           call 0x5b0680
// 005b09ea  8b442428             mov eax, dword ptr [esp + 0x28]
// 005b09ee  8d4c2430             lea ecx, [esp + 0x30]
// 005b09f2  51                   push ecx
// 005b09f3  03e8                 add ebp, eax
// 005b09f5  55                   push ebp
// 005b09f6  50                   push eax
// 005b09f7  e864fcffff           call 0x5b0660
// 005b09fc  83c418               add esp, 0x18
// 005b09ff  5d                   pop ebp
// 005b0a00  5b                   pop ebx
// 005b0a01  5f                   pop edi
// 005b0a02  5e                   pop esi
// 005b0a03  59                   pop ecx
// 005b0a04  c21000               ret 0x10
// standard library vector<short> (function ?_Insert_n@?$vector@FV?$allocator@F@std@@@std@@IAEXV?$_Vector_const_iterator@FV?$allocator@F@std@@@2@IABF@Z)

// stl: vector<short>
typedef short E;
#include <vector>
template class std::vector<E>;
