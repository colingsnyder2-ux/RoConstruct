// from server: 100% by auto
// roc 2009-06 0065ed00  unit: RBX::VBasicPartInstance::?$SeatImpl  size: 180 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0065ed00
//
// 0065ed00  83ec08               sub esp, 8
// 0065ed03  53                   push ebx
// 0065ed04  55                   push ebp
// 0065ed05  56                   push esi
// 0065ed06  8bf1                 mov esi, ecx
// 0065ed08  8b4610               mov eax, dword ptr [esi + 0x10]
// 0065ed0b  57                   push edi
// 0065ed0c  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0065ed0f  8bc8                 mov ecx, eax
// 0065ed11  2bcf                 sub ecx, edi
// 0065ed13  f7c1f8ffffff         test ecx, 0xfffffff8
// 0065ed19  7504                 jne 0x65ed1f
// 0065ed1b  33db                 xor ebx, ebx
// 0065ed1d  eb27                 jmp 0x65ed46
// 0065ed1f  3bf8                 cmp edi, eax
// 0065ed21  7606                 jbe 0x65ed29
// 0065ed23  ff15ace98900         call dword ptr [0x89e9ac]
// 0065ed29  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0065ed2d  8b06                 mov eax, dword ptr [esi]
// 0065ed2f  85c9                 test ecx, ecx
// 0065ed31  7404                 je 0x65ed37
// 0065ed33  3bc8                 cmp ecx, eax
// 0065ed35  7406                 je 0x65ed3d
// 0065ed37  ff15ace98900         call dword ptr [0x89e9ac]
// 0065ed3d  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0065ed41  2bdf                 sub ebx, edi
// 0065ed43  c1fb03               sar ebx, 3
// 0065ed46  8b542428             mov edx, dword ptr [esp + 0x28]
// 0065ed4a  8b442424             mov eax, dword ptr [esp + 0x24]
// 0065ed4e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0065ed52  52                   push edx
// 0065ed53  6a01                 push 1
// 0065ed55  50                   push eax
// 0065ed56  51                   push ecx
// 0065ed57  8bce                 mov ecx, esi
// 0065ed59  e8a2fbffff           call 0x65e900
// 0065ed5e  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0065ed61  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 0065ed64  7606                 jbe 0x65ed6c
// 0065ed66  ff15ace98900         call dword ptr [0x89e9ac]
// 0065ed6c  8b36                 mov esi, dword ptr [esi]
// 0065ed6e  8bee                 mov ebp, esi
// 0065ed70  897c2414             mov dword ptr [esp + 0x14], edi
// 0065ed74  85f6                 test esi, esi
// 0065ed76  7518                 jne 0x65ed90
// 0065ed78  ff15ace98900         call dword ptr [0x89e9ac]
// 0065ed7e  33c0                 xor eax, eax
// 0065ed80  8d3cdf               lea edi, [edi + ebx*8]
// 0065ed83  3b7810               cmp edi, dword ptr [eax + 0x10]
// 0065ed86  7713                 ja 0x65ed9b
// 0065ed88  85f6                 test esi, esi
// 0065ed8a  7408                 je 0x65ed94
// 0065ed8c  8b36                 mov esi, dword ptr [esi]
// 0065ed8e  eb06                 jmp 0x65ed96
// 0065ed90  8b06                 mov eax, dword ptr [esi]
// 0065ed92  ebec                 jmp 0x65ed80
// 0065ed94  33f6                 xor esi, esi
// 0065ed96  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 0065ed99  7306                 jae 0x65eda1
// 0065ed9b  ff15ace98900         call dword ptr [0x89e9ac]
// 0065eda1  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0065eda5  897804               mov dword ptr [eax + 4], edi
// 0065eda8  5f                   pop edi
// 0065eda9  5e                   pop esi
// 0065edaa  8928                 mov dword ptr [eax], ebp
// 0065edac  5d                   pop ebp
// 0065edad  5b                   pop ebx
// 0065edae  83c408               add esp, 8
// 0065edb1  c21000               ret 0x10
// standard library vector<double> (function ?insert@?$vector@NV?$allocator@N@std@@@std@@QAE?AV?$_Vector_iterator@NV?$allocator@N@std@@@2@V?$_Vector_const_iterator@NV?$allocator@N@std@@@2@ABN@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
