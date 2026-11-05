// from server: 100% by auto
// roc 2008-06 0059c130  unit: RBX::PartInstance::W4FormFactor::?$EnumDesc  size: 180 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0059c130
//
// 0059c130  83ec08               sub esp, 8
// 0059c133  53                   push ebx
// 0059c134  55                   push ebp
// 0059c135  56                   push esi
// 0059c136  8bf1                 mov esi, ecx
// 0059c138  8b4610               mov eax, dword ptr [esi + 0x10]
// 0059c13b  57                   push edi
// 0059c13c  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0059c13f  8bc8                 mov ecx, eax
// 0059c141  2bcf                 sub ecx, edi
// 0059c143  f7c1f8ffffff         test ecx, 0xfffffff8
// 0059c149  7504                 jne 0x59c14f
// 0059c14b  33db                 xor ebx, ebx
// 0059c14d  eb27                 jmp 0x59c176
// 0059c14f  3bf8                 cmp edi, eax
// 0059c151  7606                 jbe 0x59c159
// 0059c153  ff1590288000         call dword ptr [0x802890]
// 0059c159  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0059c15d  8b06                 mov eax, dword ptr [esi]
// 0059c15f  85c9                 test ecx, ecx
// 0059c161  7404                 je 0x59c167
// 0059c163  3bc8                 cmp ecx, eax
// 0059c165  7406                 je 0x59c16d
// 0059c167  ff1590288000         call dword ptr [0x802890]
// 0059c16d  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0059c171  2bdf                 sub ebx, edi
// 0059c173  c1fb03               sar ebx, 3
// 0059c176  8b542428             mov edx, dword ptr [esp + 0x28]
// 0059c17a  8b442424             mov eax, dword ptr [esp + 0x24]
// 0059c17e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0059c182  52                   push edx
// 0059c183  6a01                 push 1
// 0059c185  50                   push eax
// 0059c186  51                   push ecx
// 0059c187  8bce                 mov ecx, esi
// 0059c189  e872fcffff           call 0x59be00
// 0059c18e  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0059c191  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 0059c194  7606                 jbe 0x59c19c
// 0059c196  ff1590288000         call dword ptr [0x802890]
// 0059c19c  8b36                 mov esi, dword ptr [esi]
// 0059c19e  8bee                 mov ebp, esi
// 0059c1a0  897c2414             mov dword ptr [esp + 0x14], edi
// 0059c1a4  85f6                 test esi, esi
// 0059c1a6  7518                 jne 0x59c1c0
// 0059c1a8  ff1590288000         call dword ptr [0x802890]
// 0059c1ae  33c0                 xor eax, eax
// 0059c1b0  8d3cdf               lea edi, [edi + ebx*8]
// 0059c1b3  3b7810               cmp edi, dword ptr [eax + 0x10]
// 0059c1b6  7713                 ja 0x59c1cb
// 0059c1b8  85f6                 test esi, esi
// 0059c1ba  7408                 je 0x59c1c4
// 0059c1bc  8b36                 mov esi, dword ptr [esi]
// 0059c1be  eb06                 jmp 0x59c1c6
// 0059c1c0  8b06                 mov eax, dword ptr [esi]
// 0059c1c2  ebec                 jmp 0x59c1b0
// 0059c1c4  33f6                 xor esi, esi
// 0059c1c6  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 0059c1c9  7306                 jae 0x59c1d1
// 0059c1cb  ff1590288000         call dword ptr [0x802890]
// 0059c1d1  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0059c1d5  897804               mov dword ptr [eax + 4], edi
// 0059c1d8  5f                   pop edi
// 0059c1d9  5e                   pop esi
// 0059c1da  8928                 mov dword ptr [eax], ebp
// 0059c1dc  5d                   pop ebp
// 0059c1dd  5b                   pop ebx
// 0059c1de  83c408               add esp, 8
// 0059c1e1  c21000               ret 0x10
// standard library vector<double> (function ?insert@?$vector@NV?$allocator@N@std@@@std@@QAE?AV?$_Vector_iterator@NV?$allocator@N@std@@@2@V?$_Vector_const_iterator@NV?$allocator@N@std@@@2@ABN@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
