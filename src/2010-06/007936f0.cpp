// from server: 100% by auto
// roc 2010-06 007936f0  unit: RBX::CircleRadialNormal  size: 180 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007936f0
//
// 007936f0  83ec08               sub esp, 8
// 007936f3  53                   push ebx
// 007936f4  55                   push ebp
// 007936f5  56                   push esi
// 007936f6  8bf1                 mov esi, ecx
// 007936f8  8b4610               mov eax, dword ptr [esi + 0x10]
// 007936fb  57                   push edi
// 007936fc  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 007936ff  8bc8                 mov ecx, eax
// 00793701  2bcf                 sub ecx, edi
// 00793703  f7c1f8ffffff         test ecx, 0xfffffff8
// 00793709  7504                 jne 0x79370f
// 0079370b  33db                 xor ebx, ebx
// 0079370d  eb27                 jmp 0x793736
// 0079370f  3bf8                 cmp edi, eax
// 00793711  7606                 jbe 0x793719
// 00793713  ff150ca99e00         call dword ptr [0x9ea90c]
// 00793719  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0079371d  8b06                 mov eax, dword ptr [esi]
// 0079371f  85c9                 test ecx, ecx
// 00793721  7404                 je 0x793727
// 00793723  3bc8                 cmp ecx, eax
// 00793725  7406                 je 0x79372d
// 00793727  ff150ca99e00         call dword ptr [0x9ea90c]
// 0079372d  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00793731  2bdf                 sub ebx, edi
// 00793733  c1fb03               sar ebx, 3
// 00793736  8b542428             mov edx, dword ptr [esp + 0x28]
// 0079373a  8b442424             mov eax, dword ptr [esp + 0x24]
// 0079373e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00793742  52                   push edx
// 00793743  6a01                 push 1
// 00793745  50                   push eax
// 00793746  51                   push ecx
// 00793747  8bce                 mov ecx, esi
// 00793749  e852fdffff           call 0x7934a0
// 0079374e  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 00793751  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 00793754  7606                 jbe 0x79375c
// 00793756  ff150ca99e00         call dword ptr [0x9ea90c]
// 0079375c  8b36                 mov esi, dword ptr [esi]
// 0079375e  8bee                 mov ebp, esi
// 00793760  897c2414             mov dword ptr [esp + 0x14], edi
// 00793764  85f6                 test esi, esi
// 00793766  7518                 jne 0x793780
// 00793768  ff150ca99e00         call dword ptr [0x9ea90c]
// 0079376e  33c0                 xor eax, eax
// 00793770  8d3cdf               lea edi, [edi + ebx*8]
// 00793773  3b7810               cmp edi, dword ptr [eax + 0x10]
// 00793776  7713                 ja 0x79378b
// 00793778  85f6                 test esi, esi
// 0079377a  7408                 je 0x793784
// 0079377c  8b36                 mov esi, dword ptr [esi]
// 0079377e  eb06                 jmp 0x793786
// 00793780  8b06                 mov eax, dword ptr [esi]
// 00793782  ebec                 jmp 0x793770
// 00793784  33f6                 xor esi, esi
// 00793786  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 00793789  7306                 jae 0x793791
// 0079378b  ff150ca99e00         call dword ptr [0x9ea90c]
// 00793791  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00793795  897804               mov dword ptr [eax + 4], edi
// 00793798  5f                   pop edi
// 00793799  5e                   pop esi
// 0079379a  8928                 mov dword ptr [eax], ebp
// 0079379c  5d                   pop ebp
// 0079379d  5b                   pop ebx
// 0079379e  83c408               add esp, 8
// 007937a1  c21000               ret 0x10
// standard library vector<double> (function ?insert@?$vector@NV?$allocator@N@std@@@std@@QAE?AV?$_Vector_iterator@NV?$allocator@N@std@@@2@V?$_Vector_const_iterator@NV?$allocator@N@std@@@2@ABN@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
