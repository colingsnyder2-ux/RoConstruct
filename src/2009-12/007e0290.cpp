// from server: 100% by auto
// roc 2009-12 007e0290  unit: RBX::CircleRadialNormal  size: 180 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007e0290
//
// 007e0290  83ec08               sub esp, 8
// 007e0293  53                   push ebx
// 007e0294  55                   push ebp
// 007e0295  56                   push esi
// 007e0296  8bf1                 mov esi, ecx
// 007e0298  8b4610               mov eax, dword ptr [esi + 0x10]
// 007e029b  57                   push edi
// 007e029c  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 007e029f  8bc8                 mov ecx, eax
// 007e02a1  2bcf                 sub ecx, edi
// 007e02a3  f7c1f8ffffff         test ecx, 0xfffffff8
// 007e02a9  7504                 jne 0x7e02af
// 007e02ab  33db                 xor ebx, ebx
// 007e02ad  eb27                 jmp 0x7e02d6
// 007e02af  3bf8                 cmp edi, eax
// 007e02b1  7606                 jbe 0x7e02b9
// 007e02b3  ff1560b79800         call dword ptr [0x98b760]
// 007e02b9  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 007e02bd  8b06                 mov eax, dword ptr [esi]
// 007e02bf  85c9                 test ecx, ecx
// 007e02c1  7404                 je 0x7e02c7
// 007e02c3  3bc8                 cmp ecx, eax
// 007e02c5  7406                 je 0x7e02cd
// 007e02c7  ff1560b79800         call dword ptr [0x98b760]
// 007e02cd  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 007e02d1  2bdf                 sub ebx, edi
// 007e02d3  c1fb03               sar ebx, 3
// 007e02d6  8b542428             mov edx, dword ptr [esp + 0x28]
// 007e02da  8b442424             mov eax, dword ptr [esp + 0x24]
// 007e02de  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 007e02e2  52                   push edx
// 007e02e3  6a01                 push 1
// 007e02e5  50                   push eax
// 007e02e6  51                   push ecx
// 007e02e7  8bce                 mov ecx, esi
// 007e02e9  e852fdffff           call 0x7e0040
// 007e02ee  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 007e02f1  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 007e02f4  7606                 jbe 0x7e02fc
// 007e02f6  ff1560b79800         call dword ptr [0x98b760]
// 007e02fc  8b36                 mov esi, dword ptr [esi]
// 007e02fe  8bee                 mov ebp, esi
// 007e0300  897c2414             mov dword ptr [esp + 0x14], edi
// 007e0304  85f6                 test esi, esi
// 007e0306  7518                 jne 0x7e0320
// 007e0308  ff1560b79800         call dword ptr [0x98b760]
// 007e030e  33c0                 xor eax, eax
// 007e0310  8d3cdf               lea edi, [edi + ebx*8]
// 007e0313  3b7810               cmp edi, dword ptr [eax + 0x10]
// 007e0316  7713                 ja 0x7e032b
// 007e0318  85f6                 test esi, esi
// 007e031a  7408                 je 0x7e0324
// 007e031c  8b36                 mov esi, dword ptr [esi]
// 007e031e  eb06                 jmp 0x7e0326
// 007e0320  8b06                 mov eax, dword ptr [esi]
// 007e0322  ebec                 jmp 0x7e0310
// 007e0324  33f6                 xor esi, esi
// 007e0326  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 007e0329  7306                 jae 0x7e0331
// 007e032b  ff1560b79800         call dword ptr [0x98b760]
// 007e0331  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007e0335  897804               mov dword ptr [eax + 4], edi
// 007e0338  5f                   pop edi
// 007e0339  5e                   pop esi
// 007e033a  8928                 mov dword ptr [eax], ebp
// 007e033c  5d                   pop ebp
// 007e033d  5b                   pop ebx
// 007e033e  83c408               add esp, 8
// 007e0341  c21000               ret 0x10
// standard library vector<double> (function ?insert@?$vector@NV?$allocator@N@std@@@std@@QAE?AV?$_Vector_iterator@NV?$allocator@N@std@@@2@V?$_Vector_const_iterator@NV?$allocator@N@std@@@2@ABN@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
