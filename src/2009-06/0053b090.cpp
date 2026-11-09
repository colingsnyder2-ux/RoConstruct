// from server: 100% by auto
// roc 2009-06 0053b090  unit: RBX::VerticalCylinderBuilder  size: 179 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0053b090
//
// 0053b090  83ec08               sub esp, 8
// 0053b093  53                   push ebx
// 0053b094  55                   push ebp
// 0053b095  56                   push esi
// 0053b096  8bf1                 mov esi, ecx
// 0053b098  8b4610               mov eax, dword ptr [esi + 0x10]
// 0053b09b  57                   push edi
// 0053b09c  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0053b09f  8bc8                 mov ecx, eax
// 0053b0a1  2bcf                 sub ecx, edi
// 0053b0a3  f7c1feffffff         test ecx, 0xfffffffe
// 0053b0a9  7504                 jne 0x53b0af
// 0053b0ab  33db                 xor ebx, ebx
// 0053b0ad  eb26                 jmp 0x53b0d5
// 0053b0af  3bf8                 cmp edi, eax
// 0053b0b1  7606                 jbe 0x53b0b9
// 0053b0b3  ff15ace98900         call dword ptr [0x89e9ac]
// 0053b0b9  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0053b0bd  8b06                 mov eax, dword ptr [esi]
// 0053b0bf  85c9                 test ecx, ecx
// 0053b0c1  7404                 je 0x53b0c7
// 0053b0c3  3bc8                 cmp ecx, eax
// 0053b0c5  7406                 je 0x53b0cd
// 0053b0c7  ff15ace98900         call dword ptr [0x89e9ac]
// 0053b0cd  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0053b0d1  2bdf                 sub ebx, edi
// 0053b0d3  d1fb                 sar ebx, 1
// 0053b0d5  8b542428             mov edx, dword ptr [esp + 0x28]
// 0053b0d9  8b442424             mov eax, dword ptr [esp + 0x24]
// 0053b0dd  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0053b0e1  52                   push edx
// 0053b0e2  6a01                 push 1
// 0053b0e4  50                   push eax
// 0053b0e5  51                   push ecx
// 0053b0e6  8bce                 mov ecx, esi
// 0053b0e8  e8b3fdffff           call 0x53aea0
// 0053b0ed  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0053b0f0  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 0053b0f3  7606                 jbe 0x53b0fb
// 0053b0f5  ff15ace98900         call dword ptr [0x89e9ac]
// 0053b0fb  8b36                 mov esi, dword ptr [esi]
// 0053b0fd  8bee                 mov ebp, esi
// 0053b0ff  897c2414             mov dword ptr [esp + 0x14], edi
// 0053b103  85f6                 test esi, esi
// 0053b105  7518                 jne 0x53b11f
// 0053b107  ff15ace98900         call dword ptr [0x89e9ac]
// 0053b10d  33c0                 xor eax, eax
// 0053b10f  8d3c5f               lea edi, [edi + ebx*2]
// 0053b112  3b7810               cmp edi, dword ptr [eax + 0x10]
// 0053b115  7713                 ja 0x53b12a
// 0053b117  85f6                 test esi, esi
// 0053b119  7408                 je 0x53b123
// 0053b11b  8b36                 mov esi, dword ptr [esi]
// 0053b11d  eb06                 jmp 0x53b125
// 0053b11f  8b06                 mov eax, dword ptr [esi]
// 0053b121  ebec                 jmp 0x53b10f
// 0053b123  33f6                 xor esi, esi
// 0053b125  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 0053b128  7306                 jae 0x53b130
// 0053b12a  ff15ace98900         call dword ptr [0x89e9ac]
// 0053b130  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0053b134  897804               mov dword ptr [eax + 4], edi
// 0053b137  5f                   pop edi
// 0053b138  5e                   pop esi
// 0053b139  8928                 mov dword ptr [eax], ebp
// 0053b13b  5d                   pop ebp
// 0053b13c  5b                   pop ebx
// 0053b13d  83c408               add esp, 8
// 0053b140  c21000               ret 0x10
// standard library vector<short> (function ?insert@?$vector@FV?$allocator@F@std@@@std@@QAE?AV?$_Vector_iterator@FV?$allocator@F@std@@@2@V?$_Vector_const_iterator@FV?$allocator@F@std@@@2@ABF@Z)

// stl: vector<short>
typedef short E;
#include <vector>
template class std::vector<E>;
