// from server: 100% by auto
// roc 2009-12 007bc610  unit: RBX::SpatialFilter  size: 180 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007bc610
//
// 007bc610  83ec08               sub esp, 8
// 007bc613  53                   push ebx
// 007bc614  55                   push ebp
// 007bc615  56                   push esi
// 007bc616  8bf1                 mov esi, ecx
// 007bc618  8b4610               mov eax, dword ptr [esi + 0x10]
// 007bc61b  57                   push edi
// 007bc61c  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 007bc61f  8bc8                 mov ecx, eax
// 007bc621  2bcf                 sub ecx, edi
// 007bc623  f7c1f8ffffff         test ecx, 0xfffffff8
// 007bc629  7504                 jne 0x7bc62f
// 007bc62b  33db                 xor ebx, ebx
// 007bc62d  eb27                 jmp 0x7bc656
// 007bc62f  3bf8                 cmp edi, eax
// 007bc631  7606                 jbe 0x7bc639
// 007bc633  ff1560b79800         call dword ptr [0x98b760]
// 007bc639  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 007bc63d  8b06                 mov eax, dword ptr [esi]
// 007bc63f  85c9                 test ecx, ecx
// 007bc641  7404                 je 0x7bc647
// 007bc643  3bc8                 cmp ecx, eax
// 007bc645  7406                 je 0x7bc64d
// 007bc647  ff1560b79800         call dword ptr [0x98b760]
// 007bc64d  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 007bc651  2bdf                 sub ebx, edi
// 007bc653  c1fb03               sar ebx, 3
// 007bc656  8b542428             mov edx, dword ptr [esp + 0x28]
// 007bc65a  8b442424             mov eax, dword ptr [esp + 0x24]
// 007bc65e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 007bc662  52                   push edx
// 007bc663  6a01                 push 1
// 007bc665  50                   push eax
// 007bc666  51                   push ecx
// 007bc667  8bce                 mov ecx, esi
// 007bc669  e882fbffff           call 0x7bc1f0
// 007bc66e  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 007bc671  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 007bc674  7606                 jbe 0x7bc67c
// 007bc676  ff1560b79800         call dword ptr [0x98b760]
// 007bc67c  8b36                 mov esi, dword ptr [esi]
// 007bc67e  8bee                 mov ebp, esi
// 007bc680  897c2414             mov dword ptr [esp + 0x14], edi
// 007bc684  85f6                 test esi, esi
// 007bc686  7518                 jne 0x7bc6a0
// 007bc688  ff1560b79800         call dword ptr [0x98b760]
// 007bc68e  33c0                 xor eax, eax
// 007bc690  8d3cdf               lea edi, [edi + ebx*8]
// 007bc693  3b7810               cmp edi, dword ptr [eax + 0x10]
// 007bc696  7713                 ja 0x7bc6ab
// 007bc698  85f6                 test esi, esi
// 007bc69a  7408                 je 0x7bc6a4
// 007bc69c  8b36                 mov esi, dword ptr [esi]
// 007bc69e  eb06                 jmp 0x7bc6a6
// 007bc6a0  8b06                 mov eax, dword ptr [esi]
// 007bc6a2  ebec                 jmp 0x7bc690
// 007bc6a4  33f6                 xor esi, esi
// 007bc6a6  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 007bc6a9  7306                 jae 0x7bc6b1
// 007bc6ab  ff1560b79800         call dword ptr [0x98b760]
// 007bc6b1  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007bc6b5  897804               mov dword ptr [eax + 4], edi
// 007bc6b8  5f                   pop edi
// 007bc6b9  5e                   pop esi
// 007bc6ba  8928                 mov dword ptr [eax], ebp
// 007bc6bc  5d                   pop ebp
// 007bc6bd  5b                   pop ebx
// 007bc6be  83c408               add esp, 8
// 007bc6c1  c21000               ret 0x10
// standard library vector<double> (function ?insert@?$vector@NV?$allocator@N@std@@@std@@QAE?AV?$_Vector_iterator@NV?$allocator@N@std@@@2@V?$_Vector_const_iterator@NV?$allocator@N@std@@@2@ABN@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
