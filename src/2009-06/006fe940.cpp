// from server: 100% by auto
// roc 2009-06 006fe940  unit: RBX::AdornRbxGfx  size: 180 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006fe940
//
// 006fe940  83ec08               sub esp, 8
// 006fe943  53                   push ebx
// 006fe944  55                   push ebp
// 006fe945  56                   push esi
// 006fe946  8bf1                 mov esi, ecx
// 006fe948  8b4610               mov eax, dword ptr [esi + 0x10]
// 006fe94b  57                   push edi
// 006fe94c  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 006fe94f  8bc8                 mov ecx, eax
// 006fe951  2bcf                 sub ecx, edi
// 006fe953  f7c1f8ffffff         test ecx, 0xfffffff8
// 006fe959  7504                 jne 0x6fe95f
// 006fe95b  33db                 xor ebx, ebx
// 006fe95d  eb27                 jmp 0x6fe986
// 006fe95f  3bf8                 cmp edi, eax
// 006fe961  7606                 jbe 0x6fe969
// 006fe963  ff15ace98900         call dword ptr [0x89e9ac]
// 006fe969  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 006fe96d  8b06                 mov eax, dword ptr [esi]
// 006fe96f  85c9                 test ecx, ecx
// 006fe971  7404                 je 0x6fe977
// 006fe973  3bc8                 cmp ecx, eax
// 006fe975  7406                 je 0x6fe97d
// 006fe977  ff15ace98900         call dword ptr [0x89e9ac]
// 006fe97d  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 006fe981  2bdf                 sub ebx, edi
// 006fe983  c1fb03               sar ebx, 3
// 006fe986  8b542428             mov edx, dword ptr [esp + 0x28]
// 006fe98a  8b442424             mov eax, dword ptr [esp + 0x24]
// 006fe98e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 006fe992  52                   push edx
// 006fe993  6a01                 push 1
// 006fe995  50                   push eax
// 006fe996  51                   push ecx
// 006fe997  8bce                 mov ecx, esi
// 006fe999  e8f247d8ff           call 0x483190
// 006fe99e  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 006fe9a1  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 006fe9a4  7606                 jbe 0x6fe9ac
// 006fe9a6  ff15ace98900         call dword ptr [0x89e9ac]
// 006fe9ac  8b36                 mov esi, dword ptr [esi]
// 006fe9ae  8bee                 mov ebp, esi
// 006fe9b0  897c2414             mov dword ptr [esp + 0x14], edi
// 006fe9b4  85f6                 test esi, esi
// 006fe9b6  7518                 jne 0x6fe9d0
// 006fe9b8  ff15ace98900         call dword ptr [0x89e9ac]
// 006fe9be  33c0                 xor eax, eax
// 006fe9c0  8d3cdf               lea edi, [edi + ebx*8]
// 006fe9c3  3b7810               cmp edi, dword ptr [eax + 0x10]
// 006fe9c6  7713                 ja 0x6fe9db
// 006fe9c8  85f6                 test esi, esi
// 006fe9ca  7408                 je 0x6fe9d4
// 006fe9cc  8b36                 mov esi, dword ptr [esi]
// 006fe9ce  eb06                 jmp 0x6fe9d6
// 006fe9d0  8b06                 mov eax, dword ptr [esi]
// 006fe9d2  ebec                 jmp 0x6fe9c0
// 006fe9d4  33f6                 xor esi, esi
// 006fe9d6  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 006fe9d9  7306                 jae 0x6fe9e1
// 006fe9db  ff15ace98900         call dword ptr [0x89e9ac]
// 006fe9e1  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006fe9e5  897804               mov dword ptr [eax + 4], edi
// 006fe9e8  5f                   pop edi
// 006fe9e9  5e                   pop esi
// 006fe9ea  8928                 mov dword ptr [eax], ebp
// 006fe9ec  5d                   pop ebp
// 006fe9ed  5b                   pop ebx
// 006fe9ee  83c408               add esp, 8
// 006fe9f1  c21000               ret 0x10
// standard library vector<double> (function ?insert@?$vector@NV?$allocator@N@std@@@std@@QAE?AV?$_Vector_iterator@NV?$allocator@N@std@@@2@V?$_Vector_const_iterator@NV?$allocator@N@std@@@2@ABN@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
