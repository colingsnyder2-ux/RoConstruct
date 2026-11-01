// from server: 100% by auto
// roc 2009-12 00750680  unit: RBX::VLocalBackpack::?$FactoryProduct  size: 180 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00750680
//
// 00750680  83ec08               sub esp, 8
// 00750683  53                   push ebx
// 00750684  55                   push ebp
// 00750685  56                   push esi
// 00750686  8bf1                 mov esi, ecx
// 00750688  8b4610               mov eax, dword ptr [esi + 0x10]
// 0075068b  57                   push edi
// 0075068c  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0075068f  8bc8                 mov ecx, eax
// 00750691  2bcf                 sub ecx, edi
// 00750693  f7c1f8ffffff         test ecx, 0xfffffff8
// 00750699  7504                 jne 0x75069f
// 0075069b  33db                 xor ebx, ebx
// 0075069d  eb27                 jmp 0x7506c6
// 0075069f  3bf8                 cmp edi, eax
// 007506a1  7606                 jbe 0x7506a9
// 007506a3  ff1560b79800         call dword ptr [0x98b760]
// 007506a9  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 007506ad  8b06                 mov eax, dword ptr [esi]
// 007506af  85c9                 test ecx, ecx
// 007506b1  7404                 je 0x7506b7
// 007506b3  3bc8                 cmp ecx, eax
// 007506b5  7406                 je 0x7506bd
// 007506b7  ff1560b79800         call dword ptr [0x98b760]
// 007506bd  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 007506c1  2bdf                 sub ebx, edi
// 007506c3  c1fb03               sar ebx, 3
// 007506c6  8b542428             mov edx, dword ptr [esp + 0x28]
// 007506ca  8b442424             mov eax, dword ptr [esp + 0x24]
// 007506ce  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 007506d2  52                   push edx
// 007506d3  6a01                 push 1
// 007506d5  50                   push eax
// 007506d6  51                   push ecx
// 007506d7  8bce                 mov ecx, esi
// 007506d9  e8e2fbffff           call 0x7502c0
// 007506de  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 007506e1  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 007506e4  7606                 jbe 0x7506ec
// 007506e6  ff1560b79800         call dword ptr [0x98b760]
// 007506ec  8b36                 mov esi, dword ptr [esi]
// 007506ee  8bee                 mov ebp, esi
// 007506f0  897c2414             mov dword ptr [esp + 0x14], edi
// 007506f4  85f6                 test esi, esi
// 007506f6  7518                 jne 0x750710
// 007506f8  ff1560b79800         call dword ptr [0x98b760]
// 007506fe  33c0                 xor eax, eax
// 00750700  8d3cdf               lea edi, [edi + ebx*8]
// 00750703  3b7810               cmp edi, dword ptr [eax + 0x10]
// 00750706  7713                 ja 0x75071b
// 00750708  85f6                 test esi, esi
// 0075070a  7408                 je 0x750714
// 0075070c  8b36                 mov esi, dword ptr [esi]
// 0075070e  eb06                 jmp 0x750716
// 00750710  8b06                 mov eax, dword ptr [esi]
// 00750712  ebec                 jmp 0x750700
// 00750714  33f6                 xor esi, esi
// 00750716  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 00750719  7306                 jae 0x750721
// 0075071b  ff1560b79800         call dword ptr [0x98b760]
// 00750721  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00750725  897804               mov dword ptr [eax + 4], edi
// 00750728  5f                   pop edi
// 00750729  5e                   pop esi
// 0075072a  8928                 mov dword ptr [eax], ebp
// 0075072c  5d                   pop ebp
// 0075072d  5b                   pop ebx
// 0075072e  83c408               add esp, 8
// 00750731  c21000               ret 0x10
// standard library vector<double> (function ?insert@?$vector@NV?$allocator@N@std@@@std@@QAE?AV?$_Vector_iterator@NV?$allocator@N@std@@@2@V?$_Vector_const_iterator@NV?$allocator@N@std@@@2@ABN@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
