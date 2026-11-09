// from server: 100% by auto
// roc 2008-06 00671c90  unit: RBX::AdornRbxGfx  size: 180 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00671c90
//
// 00671c90  83ec08               sub esp, 8
// 00671c93  53                   push ebx
// 00671c94  55                   push ebp
// 00671c95  56                   push esi
// 00671c96  8bf1                 mov esi, ecx
// 00671c98  8b4610               mov eax, dword ptr [esi + 0x10]
// 00671c9b  57                   push edi
// 00671c9c  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 00671c9f  8bc8                 mov ecx, eax
// 00671ca1  2bcf                 sub ecx, edi
// 00671ca3  f7c1f8ffffff         test ecx, 0xfffffff8
// 00671ca9  7504                 jne 0x671caf
// 00671cab  33db                 xor ebx, ebx
// 00671cad  eb27                 jmp 0x671cd6
// 00671caf  3bf8                 cmp edi, eax
// 00671cb1  7606                 jbe 0x671cb9
// 00671cb3  ff1590288000         call dword ptr [0x802890]
// 00671cb9  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00671cbd  8b06                 mov eax, dword ptr [esi]
// 00671cbf  85c9                 test ecx, ecx
// 00671cc1  7404                 je 0x671cc7
// 00671cc3  3bc8                 cmp ecx, eax
// 00671cc5  7406                 je 0x671ccd
// 00671cc7  ff1590288000         call dword ptr [0x802890]
// 00671ccd  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00671cd1  2bdf                 sub ebx, edi
// 00671cd3  c1fb03               sar ebx, 3
// 00671cd6  8b542428             mov edx, dword ptr [esp + 0x28]
// 00671cda  8b442424             mov eax, dword ptr [esp + 0x24]
// 00671cde  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00671ce2  52                   push edx
// 00671ce3  6a01                 push 1
// 00671ce5  50                   push eax
// 00671ce6  51                   push ecx
// 00671ce7  8bce                 mov ecx, esi
// 00671ce9  e89292feff           call 0x65af80
// 00671cee  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 00671cf1  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 00671cf4  7606                 jbe 0x671cfc
// 00671cf6  ff1590288000         call dword ptr [0x802890]
// 00671cfc  8b36                 mov esi, dword ptr [esi]
// 00671cfe  8bee                 mov ebp, esi
// 00671d00  897c2414             mov dword ptr [esp + 0x14], edi
// 00671d04  85f6                 test esi, esi
// 00671d06  7518                 jne 0x671d20
// 00671d08  ff1590288000         call dword ptr [0x802890]
// 00671d0e  33c0                 xor eax, eax
// 00671d10  8d3cdf               lea edi, [edi + ebx*8]
// 00671d13  3b7810               cmp edi, dword ptr [eax + 0x10]
// 00671d16  7713                 ja 0x671d2b
// 00671d18  85f6                 test esi, esi
// 00671d1a  7408                 je 0x671d24
// 00671d1c  8b36                 mov esi, dword ptr [esi]
// 00671d1e  eb06                 jmp 0x671d26
// 00671d20  8b06                 mov eax, dword ptr [esi]
// 00671d22  ebec                 jmp 0x671d10
// 00671d24  33f6                 xor esi, esi
// 00671d26  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 00671d29  7306                 jae 0x671d31
// 00671d2b  ff1590288000         call dword ptr [0x802890]
// 00671d31  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00671d35  897804               mov dword ptr [eax + 4], edi
// 00671d38  5f                   pop edi
// 00671d39  5e                   pop esi
// 00671d3a  8928                 mov dword ptr [eax], ebp
// 00671d3c  5d                   pop ebp
// 00671d3d  5b                   pop ebx
// 00671d3e  83c408               add esp, 8
// 00671d41  c21000               ret 0x10
// standard library vector<double> (function ?insert@?$vector@NV?$allocator@N@std@@@std@@QAE?AV?$_Vector_iterator@NV?$allocator@N@std@@@2@V?$_Vector_const_iterator@NV?$allocator@N@std@@@2@ABN@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
