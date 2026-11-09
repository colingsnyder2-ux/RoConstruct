// from server: 100% by auto
// roc 2009-12 005f59a0  unit: G3D::BinaryInput  size: 442 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005f59a0
//
// 005f59a0  83ec08               sub esp, 8
// 005f59a3  56                   push esi
// 005f59a4  8bf1                 mov esi, ecx
// 005f59a6  8b560c               mov edx, dword ptr [esi + 0xc]
// 005f59a9  57                   push edi
// 005f59aa  85d2                 test edx, edx
// 005f59ac  7504                 jne 0x5f59b2
// 005f59ae  33c9                 xor ecx, ecx
// 005f59b0  eb0a                 jmp 0x5f59bc
// 005f59b2  8b4614               mov eax, dword ptr [esi + 0x14]
// 005f59b5  2bc2                 sub eax, edx
// 005f59b7  c1f803               sar eax, 3
// 005f59ba  8bc8                 mov ecx, eax
// 005f59bc  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 005f59c0  85ff                 test edi, edi
// 005f59c2  0f848a010000         je 0x5f5b52
// 005f59c8  53                   push ebx
// 005f59c9  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 005f59cc  8bc3                 mov eax, ebx
// 005f59ce  2bc2                 sub eax, edx
// 005f59d0  c1f803               sar eax, 3
// 005f59d3  baffffff1f           mov edx, 0x1fffffff
// 005f59d8  2bd0                 sub edx, eax
// 005f59da  3bd7                 cmp edx, edi
// 005f59dc  7305                 jae 0x5f59e3
// 005f59de  e8adbfefff           call 0x4f1990
// 005f59e3  8d1438               lea edx, [eax + edi]
// 005f59e6  55                   push ebp
// 005f59e7  3bca                 cmp ecx, edx
// 005f59e9  0f83b7000000         jae 0x5f5aa6
// 005f59ef  8bc1                 mov eax, ecx
// 005f59f1  d1e8                 shr eax, 1
// 005f59f3  bbffffff1f           mov ebx, 0x1fffffff
// 005f59f8  2bd8                 sub ebx, eax
// 005f59fa  3bd9                 cmp ebx, ecx
// 005f59fc  730e                 jae 0x5f5a0c
// 005f59fe  c744241000000000     mov dword ptr [esp + 0x10], 0
// 005f5a06  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005f5a0a  eb06                 jmp 0x5f5a12
// 005f5a0c  03c8                 add ecx, eax
// 005f5a0e  894c2410             mov dword ptr [esp + 0x10], ecx
// 005f5a12  3bca                 cmp ecx, edx
// 005f5a14  7306                 jae 0x5f5a1c
// 005f5a16  89542410             mov dword ptr [esp + 0x10], edx
// 005f5a1a  8bca                 mov ecx, edx
// 005f5a1c  6a00                 push 0
// 005f5a1e  51                   push ecx
// 005f5a1f  e88c7cefff           call 0x4ed6b0
// 005f5a24  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 005f5a28  2b5e0c               sub ebx, dword ptr [esi + 0xc]
// 005f5a2b  83c408               add esp, 8
// 005f5a2e  8be8                 mov ebp, eax
// 005f5a30  8b442428             mov eax, dword ptr [esp + 0x28]
// 005f5a34  50                   push eax
// 005f5a35  c1fb03               sar ebx, 3
// 005f5a38  57                   push edi
// 005f5a39  8d4cdd00             lea ecx, [ebp + ebx*8]
// 005f5a3d  51                   push ecx
// 005f5a3e  8bce                 mov ecx, esi
// 005f5a40  e82bffffff           call 0x5f5970
// 005f5a45  8b542420             mov edx, dword ptr [esp + 0x20]
// 005f5a49  8b460c               mov eax, dword ptr [esi + 0xc]
// 005f5a4c  55                   push ebp
// 005f5a4d  52                   push edx
// 005f5a4e  50                   push eax
// 005f5a4f  8bce                 mov ecx, esi
// 005f5a51  e84afeffff           call 0x5f58a0
// 005f5a56  8b5610               mov edx, dword ptr [esi + 0x10]
// 005f5a59  8b442420             mov eax, dword ptr [esp + 0x20]
// 005f5a5d  03df                 add ebx, edi
// 005f5a5f  8d4cdd00             lea ecx, [ebp + ebx*8]
// 005f5a63  51                   push ecx
// 005f5a64  52                   push edx
// 005f5a65  50                   push eax
// 005f5a66  8bce                 mov ecx, esi
// 005f5a68  e833feffff           call 0x5f58a0
// 005f5a6d  8b460c               mov eax, dword ptr [esi + 0xc]
// 005f5a70  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 005f5a73  2bc8                 sub ecx, eax
// 005f5a75  c1f903               sar ecx, 3
// 005f5a78  03f9                 add edi, ecx
// 005f5a7a  85c0                 test eax, eax
// 005f5a7c  7409                 je 0x5f5a87
// 005f5a7e  50                   push eax
// 005f5a7f  e8d6dd1f00           call 0x7f385a
// 005f5a84  83c404               add esp, 4
// 005f5a87  8b542410             mov edx, dword ptr [esp + 0x10]
// 005f5a8b  8d4cfd00             lea ecx, [ebp + edi*8]
// 005f5a8f  8d44d500             lea eax, [ebp + edx*8]
// 005f5a93  896e0c               mov dword ptr [esi + 0xc], ebp
// 005f5a96  5d                   pop ebp
// 005f5a97  5b                   pop ebx
// 005f5a98  5f                   pop edi
// 005f5a99  894614               mov dword ptr [esi + 0x14], eax
// 005f5a9c  894e10               mov dword ptr [esi + 0x10], ecx
// 005f5a9f  5e                   pop esi
// 005f5aa0  83c408               add esp, 8
// 005f5aa3  c21000               ret 0x10
// 005f5aa6  8b442420             mov eax, dword ptr [esp + 0x20]
// 005f5aaa  8bd3                 mov edx, ebx
// 005f5aac  2bd0                 sub edx, eax
// 005f5aae  c1fa03               sar edx, 3
// 005f5ab1  8d2cfd00000000       lea ebp, [edi*8]
// 005f5ab8  3bd7                 cmp edx, edi
// 005f5aba  7358                 jae 0x5f5b14
// 005f5abc  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005f5ac0  dd01                 fld qword ptr [ecx]
// 005f5ac2  8d1428               lea edx, [eax + ebp]
// 005f5ac5  52                   push edx
// 005f5ac6  dd5c2414             fstp qword ptr [esp + 0x14]
// 005f5aca  53                   push ebx
// 005f5acb  50                   push eax
// 005f5acc  8bce                 mov ecx, esi
// 005f5ace  e8cdfdffff           call 0x5f58a0
// 005f5ad3  8b4610               mov eax, dword ptr [esi + 0x10]
// 005f5ad6  8bd0                 mov edx, eax
// 005f5ad8  2b542420             sub edx, dword ptr [esp + 0x20]
// 005f5adc  8d4c2410             lea ecx, [esp + 0x10]
// 005f5ae0  51                   push ecx
// 005f5ae1  c1fa03               sar edx, 3
// 005f5ae4  2bfa                 sub edi, edx
// 005f5ae6  57                   push edi
// 005f5ae7  50                   push eax
// 005f5ae8  8bce                 mov ecx, esi
// 005f5aea  e881feffff           call 0x5f5970
// 005f5aef  016e10               add dword ptr [esi + 0x10], ebp
// 005f5af2  8b7610               mov esi, dword ptr [esi + 0x10]
// 005f5af5  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 005f5af9  8d442410             lea eax, [esp + 0x10]
// 005f5afd  50                   push eax
// 005f5afe  2bf5                 sub esi, ebp
// 005f5b00  56                   push esi
// 005f5b01  51                   push ecx
// 005f5b02  e849fdffff           call 0x5f5850
// 005f5b07  83c40c               add esp, 0xc
// 005f5b0a  5d                   pop ebp
// 005f5b0b  5b                   pop ebx
// 005f5b0c  5f                   pop edi
// 005f5b0d  5e                   pop esi
// 005f5b0e  83c408               add esp, 8
// 005f5b11  c21000               ret 0x10
// 005f5b14  8b542428             mov edx, dword ptr [esp + 0x28]
// 005f5b18  dd02                 fld qword ptr [edx]
// 005f5b1a  53                   push ebx
// 005f5b1b  8bfb                 mov edi, ebx
// 005f5b1d  dd5c2414             fstp qword ptr [esp + 0x14]
// 005f5b21  53                   push ebx
// 005f5b22  2bfd                 sub edi, ebp
// 005f5b24  57                   push edi
// 005f5b25  8bce                 mov ecx, esi
// 005f5b27  e874fdffff           call 0x5f58a0
// 005f5b2c  53                   push ebx
// 005f5b2d  894610               mov dword ptr [esi + 0x10], eax
// 005f5b30  8b442424             mov eax, dword ptr [esp + 0x24]
// 005f5b34  57                   push edi
// 005f5b35  50                   push eax
// 005f5b36  e835fdffff           call 0x5f5870
// 005f5b3b  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 005f5b3f  8d4c241c             lea ecx, [esp + 0x1c]
// 005f5b43  51                   push ecx
// 005f5b44  03e8                 add ebp, eax
// 005f5b46  55                   push ebp
// 005f5b47  50                   push eax
// 005f5b48  e803fdffff           call 0x5f5850
// 005f5b4d  83c418               add esp, 0x18
// 005f5b50  5d                   pop ebp
// 005f5b51  5b                   pop ebx
// 005f5b52  5f                   pop edi
// 005f5b53  5e                   pop esi
// 005f5b54  83c408               add esp, 8
// 005f5b57  c21000               ret 0x10
// standard library vector<double> (function ?_Insert_n@?$vector@NV?$allocator@N@std@@@std@@IAEXV?$_Vector_const_iterator@NV?$allocator@N@std@@@2@IABN@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
