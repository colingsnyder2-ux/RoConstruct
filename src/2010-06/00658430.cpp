// from server: 100% by auto
// roc 2010-06 00658430  unit: RBX::VKeyframeSequence::?$FactoryProduct  size: 180 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00658430
//
// 00658430  83ec08               sub esp, 8
// 00658433  53                   push ebx
// 00658434  55                   push ebp
// 00658435  56                   push esi
// 00658436  8bf1                 mov esi, ecx
// 00658438  8b4610               mov eax, dword ptr [esi + 0x10]
// 0065843b  57                   push edi
// 0065843c  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0065843f  8bc8                 mov ecx, eax
// 00658441  2bcf                 sub ecx, edi
// 00658443  f7c1f8ffffff         test ecx, 0xfffffff8
// 00658449  7504                 jne 0x65844f
// 0065844b  33db                 xor ebx, ebx
// 0065844d  eb27                 jmp 0x658476
// 0065844f  3bf8                 cmp edi, eax
// 00658451  7606                 jbe 0x658459
// 00658453  ff150ca99e00         call dword ptr [0x9ea90c]
// 00658459  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0065845d  8b06                 mov eax, dword ptr [esi]
// 0065845f  85c9                 test ecx, ecx
// 00658461  7404                 je 0x658467
// 00658463  3bc8                 cmp ecx, eax
// 00658465  7406                 je 0x65846d
// 00658467  ff150ca99e00         call dword ptr [0x9ea90c]
// 0065846d  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00658471  2bdf                 sub ebx, edi
// 00658473  c1fb03               sar ebx, 3
// 00658476  8b542428             mov edx, dword ptr [esp + 0x28]
// 0065847a  8b442424             mov eax, dword ptr [esp + 0x24]
// 0065847e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00658482  52                   push edx
// 00658483  6a01                 push 1
// 00658485  50                   push eax
// 00658486  51                   push ecx
// 00658487  8bce                 mov ecx, esi
// 00658489  e892faffff           call 0x657f20
// 0065848e  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 00658491  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 00658494  7606                 jbe 0x65849c
// 00658496  ff150ca99e00         call dword ptr [0x9ea90c]
// 0065849c  8b36                 mov esi, dword ptr [esi]
// 0065849e  8bee                 mov ebp, esi
// 006584a0  897c2414             mov dword ptr [esp + 0x14], edi
// 006584a4  85f6                 test esi, esi
// 006584a6  7518                 jne 0x6584c0
// 006584a8  ff150ca99e00         call dword ptr [0x9ea90c]
// 006584ae  33c0                 xor eax, eax
// 006584b0  8d3cdf               lea edi, [edi + ebx*8]
// 006584b3  3b7810               cmp edi, dword ptr [eax + 0x10]
// 006584b6  7713                 ja 0x6584cb
// 006584b8  85f6                 test esi, esi
// 006584ba  7408                 je 0x6584c4
// 006584bc  8b36                 mov esi, dword ptr [esi]
// 006584be  eb06                 jmp 0x6584c6
// 006584c0  8b06                 mov eax, dword ptr [esi]
// 006584c2  ebec                 jmp 0x6584b0
// 006584c4  33f6                 xor esi, esi
// 006584c6  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 006584c9  7306                 jae 0x6584d1
// 006584cb  ff150ca99e00         call dword ptr [0x9ea90c]
// 006584d1  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006584d5  897804               mov dword ptr [eax + 4], edi
// 006584d8  5f                   pop edi
// 006584d9  5e                   pop esi
// 006584da  8928                 mov dword ptr [eax], ebp
// 006584dc  5d                   pop ebp
// 006584dd  5b                   pop ebx
// 006584de  83c408               add esp, 8
// 006584e1  c21000               ret 0x10
// standard library vector<double> (function ?insert@?$vector@NV?$allocator@N@std@@@std@@QAE?AV?$_Vector_iterator@NV?$allocator@N@std@@@2@V?$_Vector_const_iterator@NV?$allocator@N@std@@@2@ABN@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
