// from server: 100% by auto
// roc 2008-06 0042d980  unit: boost::any::H::?$holder  size: 180 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0042d980
//
// 0042d980  83ec08               sub esp, 8
// 0042d983  53                   push ebx
// 0042d984  55                   push ebp
// 0042d985  56                   push esi
// 0042d986  8bf1                 mov esi, ecx
// 0042d988  8b4610               mov eax, dword ptr [esi + 0x10]
// 0042d98b  57                   push edi
// 0042d98c  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0042d98f  8bc8                 mov ecx, eax
// 0042d991  2bcf                 sub ecx, edi
// 0042d993  f7c1f8ffffff         test ecx, 0xfffffff8
// 0042d999  7504                 jne 0x42d99f
// 0042d99b  33db                 xor ebx, ebx
// 0042d99d  eb27                 jmp 0x42d9c6
// 0042d99f  3bf8                 cmp edi, eax
// 0042d9a1  7606                 jbe 0x42d9a9
// 0042d9a3  ff1590288000         call dword ptr [0x802890]
// 0042d9a9  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0042d9ad  8b06                 mov eax, dword ptr [esi]
// 0042d9af  85c9                 test ecx, ecx
// 0042d9b1  7404                 je 0x42d9b7
// 0042d9b3  3bc8                 cmp ecx, eax
// 0042d9b5  7406                 je 0x42d9bd
// 0042d9b7  ff1590288000         call dword ptr [0x802890]
// 0042d9bd  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0042d9c1  2bdf                 sub ebx, edi
// 0042d9c3  c1fb03               sar ebx, 3
// 0042d9c6  8b542428             mov edx, dword ptr [esp + 0x28]
// 0042d9ca  8b442424             mov eax, dword ptr [esp + 0x24]
// 0042d9ce  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0042d9d2  52                   push edx
// 0042d9d3  6a01                 push 1
// 0042d9d5  50                   push eax
// 0042d9d6  51                   push ecx
// 0042d9d7  8bce                 mov ecx, esi
// 0042d9d9  e8c2fcffff           call 0x42d6a0
// 0042d9de  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0042d9e1  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 0042d9e4  7606                 jbe 0x42d9ec
// 0042d9e6  ff1590288000         call dword ptr [0x802890]
// 0042d9ec  8b36                 mov esi, dword ptr [esi]
// 0042d9ee  8bee                 mov ebp, esi
// 0042d9f0  897c2414             mov dword ptr [esp + 0x14], edi
// 0042d9f4  85f6                 test esi, esi
// 0042d9f6  7518                 jne 0x42da10
// 0042d9f8  ff1590288000         call dword ptr [0x802890]
// 0042d9fe  33c0                 xor eax, eax
// 0042da00  8d3cdf               lea edi, [edi + ebx*8]
// 0042da03  3b7810               cmp edi, dword ptr [eax + 0x10]
// 0042da06  7713                 ja 0x42da1b
// 0042da08  85f6                 test esi, esi
// 0042da0a  7408                 je 0x42da14
// 0042da0c  8b36                 mov esi, dword ptr [esi]
// 0042da0e  eb06                 jmp 0x42da16
// 0042da10  8b06                 mov eax, dword ptr [esi]
// 0042da12  ebec                 jmp 0x42da00
// 0042da14  33f6                 xor esi, esi
// 0042da16  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 0042da19  7306                 jae 0x42da21
// 0042da1b  ff1590288000         call dword ptr [0x802890]
// 0042da21  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0042da25  897804               mov dword ptr [eax + 4], edi
// 0042da28  5f                   pop edi
// 0042da29  5e                   pop esi
// 0042da2a  8928                 mov dword ptr [eax], ebp
// 0042da2c  5d                   pop ebp
// 0042da2d  5b                   pop ebx
// 0042da2e  83c408               add esp, 8
// 0042da31  c21000               ret 0x10
// standard library vector<double> (function ?insert@?$vector@NV?$allocator@N@std@@@std@@QAE?AV?$_Vector_iterator@NV?$allocator@N@std@@@2@V?$_Vector_const_iterator@NV?$allocator@N@std@@@2@ABN@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
