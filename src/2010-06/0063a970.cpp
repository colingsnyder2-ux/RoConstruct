// from server: 100% by auto
// roc 2010-06 0063a970  unit: RBX::VBasicPartInstance::?$ActionStation  size: 180 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0063a970
//
// 0063a970  83ec08               sub esp, 8
// 0063a973  53                   push ebx
// 0063a974  55                   push ebp
// 0063a975  56                   push esi
// 0063a976  8bf1                 mov esi, ecx
// 0063a978  8b4610               mov eax, dword ptr [esi + 0x10]
// 0063a97b  57                   push edi
// 0063a97c  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0063a97f  8bc8                 mov ecx, eax
// 0063a981  2bcf                 sub ecx, edi
// 0063a983  f7c1f8ffffff         test ecx, 0xfffffff8
// 0063a989  7504                 jne 0x63a98f
// 0063a98b  33db                 xor ebx, ebx
// 0063a98d  eb27                 jmp 0x63a9b6
// 0063a98f  3bf8                 cmp edi, eax
// 0063a991  7606                 jbe 0x63a999
// 0063a993  ff150ca99e00         call dword ptr [0x9ea90c]
// 0063a999  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0063a99d  8b06                 mov eax, dword ptr [esi]
// 0063a99f  85c9                 test ecx, ecx
// 0063a9a1  7404                 je 0x63a9a7
// 0063a9a3  3bc8                 cmp ecx, eax
// 0063a9a5  7406                 je 0x63a9ad
// 0063a9a7  ff150ca99e00         call dword ptr [0x9ea90c]
// 0063a9ad  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0063a9b1  2bdf                 sub ebx, edi
// 0063a9b3  c1fb03               sar ebx, 3
// 0063a9b6  8b542428             mov edx, dword ptr [esp + 0x28]
// 0063a9ba  8b442424             mov eax, dword ptr [esp + 0x24]
// 0063a9be  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0063a9c2  52                   push edx
// 0063a9c3  6a01                 push 1
// 0063a9c5  50                   push eax
// 0063a9c6  51                   push ecx
// 0063a9c7  8bce                 mov ecx, esi
// 0063a9c9  e8a2fbffff           call 0x63a570
// 0063a9ce  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0063a9d1  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 0063a9d4  7606                 jbe 0x63a9dc
// 0063a9d6  ff150ca99e00         call dword ptr [0x9ea90c]
// 0063a9dc  8b36                 mov esi, dword ptr [esi]
// 0063a9de  8bee                 mov ebp, esi
// 0063a9e0  897c2414             mov dword ptr [esp + 0x14], edi
// 0063a9e4  85f6                 test esi, esi
// 0063a9e6  7518                 jne 0x63aa00
// 0063a9e8  ff150ca99e00         call dword ptr [0x9ea90c]
// 0063a9ee  33c0                 xor eax, eax
// 0063a9f0  8d3cdf               lea edi, [edi + ebx*8]
// 0063a9f3  3b7810               cmp edi, dword ptr [eax + 0x10]
// 0063a9f6  7713                 ja 0x63aa0b
// 0063a9f8  85f6                 test esi, esi
// 0063a9fa  7408                 je 0x63aa04
// 0063a9fc  8b36                 mov esi, dword ptr [esi]
// 0063a9fe  eb06                 jmp 0x63aa06
// 0063aa00  8b06                 mov eax, dword ptr [esi]
// 0063aa02  ebec                 jmp 0x63a9f0
// 0063aa04  33f6                 xor esi, esi
// 0063aa06  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 0063aa09  7306                 jae 0x63aa11
// 0063aa0b  ff150ca99e00         call dword ptr [0x9ea90c]
// 0063aa11  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0063aa15  897804               mov dword ptr [eax + 4], edi
// 0063aa18  5f                   pop edi
// 0063aa19  5e                   pop esi
// 0063aa1a  8928                 mov dword ptr [eax], ebp
// 0063aa1c  5d                   pop ebp
// 0063aa1d  5b                   pop ebx
// 0063aa1e  83c408               add esp, 8
// 0063aa21  c21000               ret 0x10
// standard library vector<double> (function ?insert@?$vector@NV?$allocator@N@std@@@std@@QAE?AV?$_Vector_iterator@NV?$allocator@N@std@@@2@V?$_Vector_const_iterator@NV?$allocator@N@std@@@2@ABN@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
