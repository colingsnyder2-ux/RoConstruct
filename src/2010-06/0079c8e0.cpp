// from server: 100% by auto
// roc 2010-06 0079c8e0  unit: std::Vlength_error::U?$error_info_injector::?$clone_impl  size: 180 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0079c8e0
//
// 0079c8e0  83ec08               sub esp, 8
// 0079c8e3  53                   push ebx
// 0079c8e4  55                   push ebp
// 0079c8e5  56                   push esi
// 0079c8e6  8bf1                 mov esi, ecx
// 0079c8e8  8b4610               mov eax, dword ptr [esi + 0x10]
// 0079c8eb  57                   push edi
// 0079c8ec  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0079c8ef  8bc8                 mov ecx, eax
// 0079c8f1  2bcf                 sub ecx, edi
// 0079c8f3  f7c1f8ffffff         test ecx, 0xfffffff8
// 0079c8f9  7504                 jne 0x79c8ff
// 0079c8fb  33db                 xor ebx, ebx
// 0079c8fd  eb27                 jmp 0x79c926
// 0079c8ff  3bf8                 cmp edi, eax
// 0079c901  7606                 jbe 0x79c909
// 0079c903  ff150ca99e00         call dword ptr [0x9ea90c]
// 0079c909  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0079c90d  8b06                 mov eax, dword ptr [esi]
// 0079c90f  85c9                 test ecx, ecx
// 0079c911  7404                 je 0x79c917
// 0079c913  3bc8                 cmp ecx, eax
// 0079c915  7406                 je 0x79c91d
// 0079c917  ff150ca99e00         call dword ptr [0x9ea90c]
// 0079c91d  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0079c921  2bdf                 sub ebx, edi
// 0079c923  c1fb03               sar ebx, 3
// 0079c926  8b542428             mov edx, dword ptr [esp + 0x28]
// 0079c92a  8b442424             mov eax, dword ptr [esp + 0x24]
// 0079c92e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0079c932  52                   push edx
// 0079c933  6a01                 push 1
// 0079c935  50                   push eax
// 0079c936  51                   push ecx
// 0079c937  8bce                 mov ecx, esi
// 0079c939  e842eff0ff           call 0x6ab880
// 0079c93e  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0079c941  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 0079c944  7606                 jbe 0x79c94c
// 0079c946  ff150ca99e00         call dword ptr [0x9ea90c]
// 0079c94c  8b36                 mov esi, dword ptr [esi]
// 0079c94e  8bee                 mov ebp, esi
// 0079c950  897c2414             mov dword ptr [esp + 0x14], edi
// 0079c954  85f6                 test esi, esi
// 0079c956  7518                 jne 0x79c970
// 0079c958  ff150ca99e00         call dword ptr [0x9ea90c]
// 0079c95e  33c0                 xor eax, eax
// 0079c960  8d3cdf               lea edi, [edi + ebx*8]
// 0079c963  3b7810               cmp edi, dword ptr [eax + 0x10]
// 0079c966  7713                 ja 0x79c97b
// 0079c968  85f6                 test esi, esi
// 0079c96a  7408                 je 0x79c974
// 0079c96c  8b36                 mov esi, dword ptr [esi]
// 0079c96e  eb06                 jmp 0x79c976
// 0079c970  8b06                 mov eax, dword ptr [esi]
// 0079c972  ebec                 jmp 0x79c960
// 0079c974  33f6                 xor esi, esi
// 0079c976  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 0079c979  7306                 jae 0x79c981
// 0079c97b  ff150ca99e00         call dword ptr [0x9ea90c]
// 0079c981  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0079c985  897804               mov dword ptr [eax + 4], edi
// 0079c988  5f                   pop edi
// 0079c989  5e                   pop esi
// 0079c98a  8928                 mov dword ptr [eax], ebp
// 0079c98c  5d                   pop ebp
// 0079c98d  5b                   pop ebx
// 0079c98e  83c408               add esp, 8
// 0079c991  c21000               ret 0x10
// standard library vector<double> (function ?insert@?$vector@NV?$allocator@N@std@@@std@@QAE?AV?$_Vector_iterator@NV?$allocator@N@std@@@2@V?$_Vector_const_iterator@NV?$allocator@N@std@@@2@ABN@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
