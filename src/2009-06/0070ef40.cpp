// from server: 100% by auto
// roc 2009-06 0070ef40  unit: RBX::TaskScheduler::VThread::?$sp_counted_impl_p  size: 180 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0070ef40
//
// 0070ef40  83ec08               sub esp, 8
// 0070ef43  53                   push ebx
// 0070ef44  55                   push ebp
// 0070ef45  56                   push esi
// 0070ef46  8bf1                 mov esi, ecx
// 0070ef48  8b4610               mov eax, dword ptr [esi + 0x10]
// 0070ef4b  57                   push edi
// 0070ef4c  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0070ef4f  8bc8                 mov ecx, eax
// 0070ef51  2bcf                 sub ecx, edi
// 0070ef53  f7c1f8ffffff         test ecx, 0xfffffff8
// 0070ef59  7504                 jne 0x70ef5f
// 0070ef5b  33db                 xor ebx, ebx
// 0070ef5d  eb27                 jmp 0x70ef86
// 0070ef5f  3bf8                 cmp edi, eax
// 0070ef61  7606                 jbe 0x70ef69
// 0070ef63  ff15ace98900         call dword ptr [0x89e9ac]
// 0070ef69  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0070ef6d  8b06                 mov eax, dword ptr [esi]
// 0070ef6f  85c9                 test ecx, ecx
// 0070ef71  7404                 je 0x70ef77
// 0070ef73  3bc8                 cmp ecx, eax
// 0070ef75  7406                 je 0x70ef7d
// 0070ef77  ff15ace98900         call dword ptr [0x89e9ac]
// 0070ef7d  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0070ef81  2bdf                 sub ebx, edi
// 0070ef83  c1fb03               sar ebx, 3
// 0070ef86  8b542428             mov edx, dword ptr [esp + 0x28]
// 0070ef8a  8b442424             mov eax, dword ptr [esp + 0x24]
// 0070ef8e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0070ef92  52                   push edx
// 0070ef93  6a01                 push 1
// 0070ef95  50                   push eax
// 0070ef96  51                   push ecx
// 0070ef97  8bce                 mov ecx, esi
// 0070ef99  e882f8ffff           call 0x70e820
// 0070ef9e  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0070efa1  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 0070efa4  7606                 jbe 0x70efac
// 0070efa6  ff15ace98900         call dword ptr [0x89e9ac]
// 0070efac  8b36                 mov esi, dword ptr [esi]
// 0070efae  8bee                 mov ebp, esi
// 0070efb0  897c2414             mov dword ptr [esp + 0x14], edi
// 0070efb4  85f6                 test esi, esi
// 0070efb6  7518                 jne 0x70efd0
// 0070efb8  ff15ace98900         call dword ptr [0x89e9ac]
// 0070efbe  33c0                 xor eax, eax
// 0070efc0  8d3cdf               lea edi, [edi + ebx*8]
// 0070efc3  3b7810               cmp edi, dword ptr [eax + 0x10]
// 0070efc6  7713                 ja 0x70efdb
// 0070efc8  85f6                 test esi, esi
// 0070efca  7408                 je 0x70efd4
// 0070efcc  8b36                 mov esi, dword ptr [esi]
// 0070efce  eb06                 jmp 0x70efd6
// 0070efd0  8b06                 mov eax, dword ptr [esi]
// 0070efd2  ebec                 jmp 0x70efc0
// 0070efd4  33f6                 xor esi, esi
// 0070efd6  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 0070efd9  7306                 jae 0x70efe1
// 0070efdb  ff15ace98900         call dword ptr [0x89e9ac]
// 0070efe1  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0070efe5  897804               mov dword ptr [eax + 4], edi
// 0070efe8  5f                   pop edi
// 0070efe9  5e                   pop esi
// 0070efea  8928                 mov dword ptr [eax], ebp
// 0070efec  5d                   pop ebp
// 0070efed  5b                   pop ebx
// 0070efee  83c408               add esp, 8
// 0070eff1  c21000               ret 0x10
// standard library vector<double> (function ?insert@?$vector@NV?$allocator@N@std@@@std@@QAE?AV?$_Vector_iterator@NV?$allocator@N@std@@@2@V?$_Vector_const_iterator@NV?$allocator@N@std@@@2@ABN@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
