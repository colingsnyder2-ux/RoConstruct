// from server: 100% by auto
// roc 2009-06 00426a60  unit: boost::any::H::?$holder  size: 180 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00426a60
//
// 00426a60  83ec08               sub esp, 8
// 00426a63  53                   push ebx
// 00426a64  55                   push ebp
// 00426a65  56                   push esi
// 00426a66  8bf1                 mov esi, ecx
// 00426a68  8b4610               mov eax, dword ptr [esi + 0x10]
// 00426a6b  57                   push edi
// 00426a6c  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 00426a6f  8bc8                 mov ecx, eax
// 00426a71  2bcf                 sub ecx, edi
// 00426a73  f7c1f8ffffff         test ecx, 0xfffffff8
// 00426a79  7504                 jne 0x426a7f
// 00426a7b  33db                 xor ebx, ebx
// 00426a7d  eb27                 jmp 0x426aa6
// 00426a7f  3bf8                 cmp edi, eax
// 00426a81  7606                 jbe 0x426a89
// 00426a83  ff15ace98900         call dword ptr [0x89e9ac]
// 00426a89  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00426a8d  8b06                 mov eax, dword ptr [esi]
// 00426a8f  85c9                 test ecx, ecx
// 00426a91  7404                 je 0x426a97
// 00426a93  3bc8                 cmp ecx, eax
// 00426a95  7406                 je 0x426a9d
// 00426a97  ff15ace98900         call dword ptr [0x89e9ac]
// 00426a9d  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00426aa1  2bdf                 sub ebx, edi
// 00426aa3  c1fb03               sar ebx, 3
// 00426aa6  8b542428             mov edx, dword ptr [esp + 0x28]
// 00426aaa  8b442424             mov eax, dword ptr [esp + 0x24]
// 00426aae  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00426ab2  52                   push edx
// 00426ab3  6a01                 push 1
// 00426ab5  50                   push eax
// 00426ab6  51                   push ecx
// 00426ab7  8bce                 mov ecx, esi
// 00426ab9  e872fcffff           call 0x426730
// 00426abe  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 00426ac1  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 00426ac4  7606                 jbe 0x426acc
// 00426ac6  ff15ace98900         call dword ptr [0x89e9ac]
// 00426acc  8b36                 mov esi, dword ptr [esi]
// 00426ace  8bee                 mov ebp, esi
// 00426ad0  897c2414             mov dword ptr [esp + 0x14], edi
// 00426ad4  85f6                 test esi, esi
// 00426ad6  7518                 jne 0x426af0
// 00426ad8  ff15ace98900         call dword ptr [0x89e9ac]
// 00426ade  33c0                 xor eax, eax
// 00426ae0  8d3cdf               lea edi, [edi + ebx*8]
// 00426ae3  3b7810               cmp edi, dword ptr [eax + 0x10]
// 00426ae6  7713                 ja 0x426afb
// 00426ae8  85f6                 test esi, esi
// 00426aea  7408                 je 0x426af4
// 00426aec  8b36                 mov esi, dword ptr [esi]
// 00426aee  eb06                 jmp 0x426af6
// 00426af0  8b06                 mov eax, dword ptr [esi]
// 00426af2  ebec                 jmp 0x426ae0
// 00426af4  33f6                 xor esi, esi
// 00426af6  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 00426af9  7306                 jae 0x426b01
// 00426afb  ff15ace98900         call dword ptr [0x89e9ac]
// 00426b01  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00426b05  897804               mov dword ptr [eax + 4], edi
// 00426b08  5f                   pop edi
// 00426b09  5e                   pop esi
// 00426b0a  8928                 mov dword ptr [eax], ebp
// 00426b0c  5d                   pop ebp
// 00426b0d  5b                   pop ebx
// 00426b0e  83c408               add esp, 8
// 00426b11  c21000               ret 0x10
// standard library vector<double> (function ?insert@?$vector@NV?$allocator@N@std@@@std@@QAE?AV?$_Vector_iterator@NV?$allocator@N@std@@@2@V?$_Vector_const_iterator@NV?$allocator@N@std@@@2@ABN@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
