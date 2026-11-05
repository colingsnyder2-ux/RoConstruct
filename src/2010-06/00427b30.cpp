// from server: 100% by auto
// roc 2010-06 00427b30  unit: std::D::DU?$char_traits::V?$basic_string::?$holder  size: 180 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00427b30
//
// 00427b30  83ec08               sub esp, 8
// 00427b33  53                   push ebx
// 00427b34  55                   push ebp
// 00427b35  56                   push esi
// 00427b36  8bf1                 mov esi, ecx
// 00427b38  8b4610               mov eax, dword ptr [esi + 0x10]
// 00427b3b  57                   push edi
// 00427b3c  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 00427b3f  8bc8                 mov ecx, eax
// 00427b41  2bcf                 sub ecx, edi
// 00427b43  f7c1f8ffffff         test ecx, 0xfffffff8
// 00427b49  7504                 jne 0x427b4f
// 00427b4b  33db                 xor ebx, ebx
// 00427b4d  eb27                 jmp 0x427b76
// 00427b4f  3bf8                 cmp edi, eax
// 00427b51  7606                 jbe 0x427b59
// 00427b53  ff150ca99e00         call dword ptr [0x9ea90c]
// 00427b59  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00427b5d  8b06                 mov eax, dword ptr [esi]
// 00427b5f  85c9                 test ecx, ecx
// 00427b61  7404                 je 0x427b67
// 00427b63  3bc8                 cmp ecx, eax
// 00427b65  7406                 je 0x427b6d
// 00427b67  ff150ca99e00         call dword ptr [0x9ea90c]
// 00427b6d  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00427b71  2bdf                 sub ebx, edi
// 00427b73  c1fb03               sar ebx, 3
// 00427b76  8b542428             mov edx, dword ptr [esp + 0x28]
// 00427b7a  8b442424             mov eax, dword ptr [esp + 0x24]
// 00427b7e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00427b82  52                   push edx
// 00427b83  6a01                 push 1
// 00427b85  50                   push eax
// 00427b86  51                   push ecx
// 00427b87  8bce                 mov ecx, esi
// 00427b89  e872fcffff           call 0x427800
// 00427b8e  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 00427b91  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 00427b94  7606                 jbe 0x427b9c
// 00427b96  ff150ca99e00         call dword ptr [0x9ea90c]
// 00427b9c  8b36                 mov esi, dword ptr [esi]
// 00427b9e  8bee                 mov ebp, esi
// 00427ba0  897c2414             mov dword ptr [esp + 0x14], edi
// 00427ba4  85f6                 test esi, esi
// 00427ba6  7518                 jne 0x427bc0
// 00427ba8  ff150ca99e00         call dword ptr [0x9ea90c]
// 00427bae  33c0                 xor eax, eax
// 00427bb0  8d3cdf               lea edi, [edi + ebx*8]
// 00427bb3  3b7810               cmp edi, dword ptr [eax + 0x10]
// 00427bb6  7713                 ja 0x427bcb
// 00427bb8  85f6                 test esi, esi
// 00427bba  7408                 je 0x427bc4
// 00427bbc  8b36                 mov esi, dword ptr [esi]
// 00427bbe  eb06                 jmp 0x427bc6
// 00427bc0  8b06                 mov eax, dword ptr [esi]
// 00427bc2  ebec                 jmp 0x427bb0
// 00427bc4  33f6                 xor esi, esi
// 00427bc6  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 00427bc9  7306                 jae 0x427bd1
// 00427bcb  ff150ca99e00         call dword ptr [0x9ea90c]
// 00427bd1  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00427bd5  897804               mov dword ptr [eax + 4], edi
// 00427bd8  5f                   pop edi
// 00427bd9  5e                   pop esi
// 00427bda  8928                 mov dword ptr [eax], ebp
// 00427bdc  5d                   pop ebp
// 00427bdd  5b                   pop ebx
// 00427bde  83c408               add esp, 8
// 00427be1  c21000               ret 0x10
// standard library vector<double> (function ?insert@?$vector@NV?$allocator@N@std@@@std@@QAE?AV?$_Vector_iterator@NV?$allocator@N@std@@@2@V?$_Vector_const_iterator@NV?$allocator@N@std@@@2@ABN@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
