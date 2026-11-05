// from server: 100% by auto
// roc 2009-06 00575040  unit: G3D::BinaryInput  size: 442 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00575040
//
// 00575040  83ec08               sub esp, 8
// 00575043  56                   push esi
// 00575044  8bf1                 mov esi, ecx
// 00575046  8b560c               mov edx, dword ptr [esi + 0xc]
// 00575049  57                   push edi
// 0057504a  85d2                 test edx, edx
// 0057504c  7504                 jne 0x575052
// 0057504e  33c9                 xor ecx, ecx
// 00575050  eb0a                 jmp 0x57505c
// 00575052  8b4614               mov eax, dword ptr [esi + 0x14]
// 00575055  2bc2                 sub eax, edx
// 00575057  c1f803               sar eax, 3
// 0057505a  8bc8                 mov ecx, eax
// 0057505c  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 00575060  85ff                 test edi, edi
// 00575062  0f848a010000         je 0x5751f2
// 00575068  53                   push ebx
// 00575069  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 0057506c  8bc3                 mov eax, ebx
// 0057506e  2bc2                 sub eax, edx
// 00575070  c1f803               sar eax, 3
// 00575073  baffffff1f           mov edx, 0x1fffffff
// 00575078  2bd0                 sub edx, eax
// 0057507a  3bd7                 cmp edx, edi
// 0057507c  7305                 jae 0x575083
// 0057507e  e8ddb2f1ff           call 0x490360
// 00575083  8d1438               lea edx, [eax + edi]
// 00575086  55                   push ebp
// 00575087  3bca                 cmp ecx, edx
// 00575089  0f83b7000000         jae 0x575146
// 0057508f  8bc1                 mov eax, ecx
// 00575091  d1e8                 shr eax, 1
// 00575093  bbffffff1f           mov ebx, 0x1fffffff
// 00575098  2bd8                 sub ebx, eax
// 0057509a  3bd9                 cmp ebx, ecx
// 0057509c  730e                 jae 0x5750ac
// 0057509e  c744241000000000     mov dword ptr [esp + 0x10], 0
// 005750a6  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005750aa  eb06                 jmp 0x5750b2
// 005750ac  03c8                 add ecx, eax
// 005750ae  894c2410             mov dword ptr [esp + 0x10], ecx
// 005750b2  3bca                 cmp ecx, edx
// 005750b4  7306                 jae 0x5750bc
// 005750b6  89542410             mov dword ptr [esp + 0x10], edx
// 005750ba  8bca                 mov ecx, edx
// 005750bc  6a00                 push 0
// 005750be  51                   push ecx
// 005750bf  e82cfef0ff           call 0x484ef0
// 005750c4  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 005750c8  2b5e0c               sub ebx, dword ptr [esi + 0xc]
// 005750cb  83c408               add esp, 8
// 005750ce  8be8                 mov ebp, eax
// 005750d0  8b442428             mov eax, dword ptr [esp + 0x28]
// 005750d4  50                   push eax
// 005750d5  c1fb03               sar ebx, 3
// 005750d8  57                   push edi
// 005750d9  8d4cdd00             lea ecx, [ebp + ebx*8]
// 005750dd  51                   push ecx
// 005750de  8bce                 mov ecx, esi
// 005750e0  e82bffffff           call 0x575010
// 005750e5  8b542420             mov edx, dword ptr [esp + 0x20]
// 005750e9  8b460c               mov eax, dword ptr [esi + 0xc]
// 005750ec  55                   push ebp
// 005750ed  52                   push edx
// 005750ee  50                   push eax
// 005750ef  8bce                 mov ecx, esi
// 005750f1  e84afeffff           call 0x574f40
// 005750f6  8b5610               mov edx, dword ptr [esi + 0x10]
// 005750f9  8b442420             mov eax, dword ptr [esp + 0x20]
// 005750fd  03df                 add ebx, edi
// 005750ff  8d4cdd00             lea ecx, [ebp + ebx*8]
// 00575103  51                   push ecx
// 00575104  52                   push edx
// 00575105  50                   push eax
// 00575106  8bce                 mov ecx, esi
// 00575108  e833feffff           call 0x574f40
// 0057510d  8b460c               mov eax, dword ptr [esi + 0xc]
// 00575110  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00575113  2bc8                 sub ecx, eax
// 00575115  c1f903               sar ecx, 3
// 00575118  03f9                 add edi, ecx
// 0057511a  85c0                 test eax, eax
// 0057511c  7409                 je 0x575127
// 0057511e  50                   push eax
// 0057511f  e80e391a00           call 0x718a32
// 00575124  83c404               add esp, 4
// 00575127  8b542410             mov edx, dword ptr [esp + 0x10]
// 0057512b  8d4cfd00             lea ecx, [ebp + edi*8]
// 0057512f  8d44d500             lea eax, [ebp + edx*8]
// 00575133  896e0c               mov dword ptr [esi + 0xc], ebp
// 00575136  5d                   pop ebp
// 00575137  5b                   pop ebx
// 00575138  5f                   pop edi
// 00575139  894614               mov dword ptr [esi + 0x14], eax
// 0057513c  894e10               mov dword ptr [esi + 0x10], ecx
// 0057513f  5e                   pop esi
// 00575140  83c408               add esp, 8
// 00575143  c21000               ret 0x10
// 00575146  8b442420             mov eax, dword ptr [esp + 0x20]
// 0057514a  8bd3                 mov edx, ebx
// 0057514c  2bd0                 sub edx, eax
// 0057514e  c1fa03               sar edx, 3
// 00575151  8d2cfd00000000       lea ebp, [edi*8]
// 00575158  3bd7                 cmp edx, edi
// 0057515a  7358                 jae 0x5751b4
// 0057515c  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00575160  dd01                 fld qword ptr [ecx]
// 00575162  8d1428               lea edx, [eax + ebp]
// 00575165  52                   push edx
// 00575166  dd5c2414             fstp qword ptr [esp + 0x14]
// 0057516a  53                   push ebx
// 0057516b  50                   push eax
// 0057516c  8bce                 mov ecx, esi
// 0057516e  e8cdfdffff           call 0x574f40
// 00575173  8b4610               mov eax, dword ptr [esi + 0x10]
// 00575176  8bd0                 mov edx, eax
// 00575178  2b542420             sub edx, dword ptr [esp + 0x20]
// 0057517c  8d4c2410             lea ecx, [esp + 0x10]
// 00575180  51                   push ecx
// 00575181  c1fa03               sar edx, 3
// 00575184  2bfa                 sub edi, edx
// 00575186  57                   push edi
// 00575187  50                   push eax
// 00575188  8bce                 mov ecx, esi
// 0057518a  e881feffff           call 0x575010
// 0057518f  016e10               add dword ptr [esi + 0x10], ebp
// 00575192  8b7610               mov esi, dword ptr [esi + 0x10]
// 00575195  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00575199  8d442410             lea eax, [esp + 0x10]
// 0057519d  50                   push eax
// 0057519e  2bf5                 sub esi, ebp
// 005751a0  56                   push esi
// 005751a1  51                   push ecx
// 005751a2  e849fdffff           call 0x574ef0
// 005751a7  83c40c               add esp, 0xc
// 005751aa  5d                   pop ebp
// 005751ab  5b                   pop ebx
// 005751ac  5f                   pop edi
// 005751ad  5e                   pop esi
// 005751ae  83c408               add esp, 8
// 005751b1  c21000               ret 0x10
// 005751b4  8b542428             mov edx, dword ptr [esp + 0x28]
// 005751b8  dd02                 fld qword ptr [edx]
// 005751ba  53                   push ebx
// 005751bb  8bfb                 mov edi, ebx
// 005751bd  dd5c2414             fstp qword ptr [esp + 0x14]
// 005751c1  53                   push ebx
// 005751c2  2bfd                 sub edi, ebp
// 005751c4  57                   push edi
// 005751c5  8bce                 mov ecx, esi
// 005751c7  e874fdffff           call 0x574f40
// 005751cc  53                   push ebx
// 005751cd  894610               mov dword ptr [esi + 0x10], eax
// 005751d0  8b442424             mov eax, dword ptr [esp + 0x24]
// 005751d4  57                   push edi
// 005751d5  50                   push eax
// 005751d6  e835fdffff           call 0x574f10
// 005751db  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 005751df  8d4c241c             lea ecx, [esp + 0x1c]
// 005751e3  51                   push ecx
// 005751e4  03e8                 add ebp, eax
// 005751e6  55                   push ebp
// 005751e7  50                   push eax
// 005751e8  e803fdffff           call 0x574ef0
// 005751ed  83c418               add esp, 0x18
// 005751f0  5d                   pop ebp
// 005751f1  5b                   pop ebx
// 005751f2  5f                   pop edi
// 005751f3  5e                   pop esi
// 005751f4  83c408               add esp, 8
// 005751f7  c21000               ret 0x10
// standard library vector<double> (function ?_Insert_n@?$vector@NV?$allocator@N@std@@@std@@IAEXV?$_Vector_const_iterator@NV?$allocator@N@std@@@2@IABN@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
