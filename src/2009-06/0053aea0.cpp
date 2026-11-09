// from server: 100% by auto
// roc 2009-06 0053aea0  unit: RBX::VerticalCylinderBuilder  size: 439 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0053aea0
//
// 0053aea0  51                   push ecx
// 0053aea1  56                   push esi
// 0053aea2  8bf1                 mov esi, ecx
// 0053aea4  8b560c               mov edx, dword ptr [esi + 0xc]
// 0053aea7  57                   push edi
// 0053aea8  85d2                 test edx, edx
// 0053aeaa  7504                 jne 0x53aeb0
// 0053aeac  33c9                 xor ecx, ecx
// 0053aeae  eb09                 jmp 0x53aeb9
// 0053aeb0  8b4614               mov eax, dword ptr [esi + 0x14]
// 0053aeb3  2bc2                 sub eax, edx
// 0053aeb5  d1f8                 sar eax, 1
// 0053aeb7  8bc8                 mov ecx, eax
// 0053aeb9  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 0053aebd  85ff                 test edi, edi
// 0053aebf  0f848c010000         je 0x53b051
// 0053aec5  53                   push ebx
// 0053aec6  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 0053aec9  8bc3                 mov eax, ebx
// 0053aecb  2bc2                 sub eax, edx
// 0053aecd  d1f8                 sar eax, 1
// 0053aecf  baffffff7f           mov edx, 0x7fffffff
// 0053aed4  2bd0                 sub edx, eax
// 0053aed6  3bd7                 cmp edx, edi
// 0053aed8  7305                 jae 0x53aedf
// 0053aeda  e88154f5ff           call 0x490360
// 0053aedf  8d1438               lea edx, [eax + edi]
// 0053aee2  55                   push ebp
// 0053aee3  3bca                 cmp ecx, edx
// 0053aee5  0f83cb000000         jae 0x53afb6
// 0053aeeb  8bc1                 mov eax, ecx
// 0053aeed  d1e8                 shr eax, 1
// 0053aeef  bbffffff7f           mov ebx, 0x7fffffff
// 0053aef4  2bd8                 sub ebx, eax
// 0053aef6  3bd9                 cmp ebx, ecx
// 0053aef8  730e                 jae 0x53af08
// 0053aefa  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0053af02  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0053af06  eb06                 jmp 0x53af0e
// 0053af08  03c8                 add ecx, eax
// 0053af0a  894c2410             mov dword ptr [esp + 0x10], ecx
// 0053af0e  3bca                 cmp ecx, edx
// 0053af10  7306                 jae 0x53af18
// 0053af12  89542410             mov dword ptr [esp + 0x10], edx
// 0053af16  8bca                 mov ecx, edx
// 0053af18  6a00                 push 0
// 0053af1a  51                   push ecx
// 0053af1b  e830a0f4ff           call 0x484f50
// 0053af20  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0053af24  2b5e0c               sub ebx, dword ptr [esi + 0xc]
// 0053af27  83c408               add esp, 8
// 0053af2a  8be8                 mov ebp, eax
// 0053af2c  8b442424             mov eax, dword ptr [esp + 0x24]
// 0053af30  50                   push eax
// 0053af31  d1fb                 sar ebx, 1
// 0053af33  57                   push edi
// 0053af34  8d4c5d00             lea ecx, [ebp + ebx*2]
// 0053af38  51                   push ecx
// 0053af39  8bce                 mov ecx, esi
// 0053af3b  e830ffffff           call 0x53ae70
// 0053af40  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0053af44  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0053af47  8bc2                 mov eax, edx
// 0053af49  2bc1                 sub eax, ecx
// 0053af4b  d1f8                 sar eax, 1
// 0053af4d  7413                 je 0x53af62
// 0053af4f  03c0                 add eax, eax
// 0053af51  50                   push eax
// 0053af52  51                   push ecx
// 0053af53  50                   push eax
// 0053af54  55                   push ebp
// 0053af55  ff155ce98900         call dword ptr [0x89e95c]
// 0053af5b  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 0053af5f  83c410               add esp, 0x10
// 0053af62  8b4610               mov eax, dword ptr [esi + 0x10]
// 0053af65  2bc2                 sub eax, edx
// 0053af67  d1f8                 sar eax, 1
// 0053af69  7415                 je 0x53af80
// 0053af6b  03c0                 add eax, eax
// 0053af6d  50                   push eax
// 0053af6e  52                   push edx
// 0053af6f  03df                 add ebx, edi
// 0053af71  50                   push eax
// 0053af72  8d545d00             lea edx, [ebp + ebx*2]
// 0053af76  52                   push edx
// 0053af77  ff155ce98900         call dword ptr [0x89e95c]
// 0053af7d  83c410               add esp, 0x10
// 0053af80  8b460c               mov eax, dword ptr [esi + 0xc]
// 0053af83  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0053af86  2bc8                 sub ecx, eax
// 0053af88  d1f9                 sar ecx, 1
// 0053af8a  03f9                 add edi, ecx
// 0053af8c  85c0                 test eax, eax
// 0053af8e  7409                 je 0x53af99
// 0053af90  50                   push eax
// 0053af91  e89cda1d00           call 0x718a32
// 0053af96  83c404               add esp, 4
// 0053af99  8b542410             mov edx, dword ptr [esp + 0x10]
// 0053af9d  8d4c7d00             lea ecx, [ebp + edi*2]
// 0053afa1  8d445500             lea eax, [ebp + edx*2]
// 0053afa5  896e0c               mov dword ptr [esi + 0xc], ebp
// 0053afa8  5d                   pop ebp
// 0053afa9  5b                   pop ebx
// 0053afaa  5f                   pop edi
// 0053afab  894614               mov dword ptr [esi + 0x14], eax
// 0053afae  894e10               mov dword ptr [esi + 0x10], ecx
// 0053afb1  5e                   pop esi
// 0053afb2  59                   pop ecx
// 0053afb3  c21000               ret 0x10
// 0053afb6  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0053afba  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0053afbe  8bd3                 mov edx, ebx
// 0053afc0  2bd0                 sub edx, eax
// 0053afc2  d1fa                 sar edx, 1
// 0053afc4  3bd7                 cmp edx, edi
// 0053afc6  0fb711               movzx edx, word ptr [ecx]
// 0053afc9  8d2c3f               lea ebp, [edi + edi]
// 0053afcc  89542424             mov dword ptr [esp + 0x24], edx
// 0053afd0  734b                 jae 0x53b01d
// 0053afd2  8d0c28               lea ecx, [eax + ebp]
// 0053afd5  51                   push ecx
// 0053afd6  53                   push ebx
// 0053afd7  50                   push eax
// 0053afd8  8bce                 mov ecx, esi
// 0053afda  e8c1fdffff           call 0x53ada0
// 0053afdf  8b4610               mov eax, dword ptr [esi + 0x10]
// 0053afe2  8bc8                 mov ecx, eax
// 0053afe4  2b4c241c             sub ecx, dword ptr [esp + 0x1c]
// 0053afe8  8d542424             lea edx, [esp + 0x24]
// 0053afec  d1f9                 sar ecx, 1
// 0053afee  52                   push edx
// 0053afef  2bf9                 sub edi, ecx
// 0053aff1  57                   push edi
// 0053aff2  50                   push eax
// 0053aff3  8bce                 mov ecx, esi
// 0053aff5  e876feffff           call 0x53ae70
// 0053affa  016e10               add dword ptr [esi + 0x10], ebp
// 0053affd  8b7610               mov esi, dword ptr [esi + 0x10]
// 0053b000  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0053b004  8d542424             lea edx, [esp + 0x24]
// 0053b008  52                   push edx
// 0053b009  2bf5                 sub esi, ebp
// 0053b00b  56                   push esi
// 0053b00c  50                   push eax
// 0053b00d  e83efdffff           call 0x53ad50
// 0053b012  83c40c               add esp, 0xc
// 0053b015  5d                   pop ebp
// 0053b016  5b                   pop ebx
// 0053b017  5f                   pop edi
// 0053b018  5e                   pop esi
// 0053b019  59                   pop ecx
// 0053b01a  c21000               ret 0x10
// 0053b01d  53                   push ebx
// 0053b01e  8bfb                 mov edi, ebx
// 0053b020  53                   push ebx
// 0053b021  2bfd                 sub edi, ebp
// 0053b023  57                   push edi
// 0053b024  8bce                 mov ecx, esi
// 0053b026  e875fdffff           call 0x53ada0
// 0053b02b  53                   push ebx
// 0053b02c  894610               mov dword ptr [esi + 0x10], eax
// 0053b02f  8b442420             mov eax, dword ptr [esp + 0x20]
// 0053b033  57                   push edi
// 0053b034  50                   push eax
// 0053b035  e836fdffff           call 0x53ad70
// 0053b03a  8b442428             mov eax, dword ptr [esp + 0x28]
// 0053b03e  8d4c2430             lea ecx, [esp + 0x30]
// 0053b042  51                   push ecx
// 0053b043  03e8                 add ebp, eax
// 0053b045  55                   push ebp
// 0053b046  50                   push eax
// 0053b047  e804fdffff           call 0x53ad50
// 0053b04c  83c418               add esp, 0x18
// 0053b04f  5d                   pop ebp
// 0053b050  5b                   pop ebx
// 0053b051  5f                   pop edi
// 0053b052  5e                   pop esi
// 0053b053  59                   pop ecx
// 0053b054  c21000               ret 0x10
// standard library vector<short> (function ?_Insert_n@?$vector@FV?$allocator@F@std@@@std@@IAEXV?$_Vector_const_iterator@FV?$allocator@F@std@@@2@IABF@Z)

// stl: vector<short>
typedef short E;
#include <vector>
template class std::vector<E>;
