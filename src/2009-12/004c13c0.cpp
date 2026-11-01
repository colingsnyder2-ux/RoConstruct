// from server: 100% by auto
// roc 2009-12 004c13c0  unit: RBX::RbxParticleEmitter  size: 180 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004c13c0
//
// 004c13c0  83ec08               sub esp, 8
// 004c13c3  53                   push ebx
// 004c13c4  55                   push ebp
// 004c13c5  56                   push esi
// 004c13c6  8bf1                 mov esi, ecx
// 004c13c8  8b4610               mov eax, dword ptr [esi + 0x10]
// 004c13cb  57                   push edi
// 004c13cc  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 004c13cf  8bc8                 mov ecx, eax
// 004c13d1  2bcf                 sub ecx, edi
// 004c13d3  f7c1f8ffffff         test ecx, 0xfffffff8
// 004c13d9  7504                 jne 0x4c13df
// 004c13db  33db                 xor ebx, ebx
// 004c13dd  eb27                 jmp 0x4c1406
// 004c13df  3bf8                 cmp edi, eax
// 004c13e1  7606                 jbe 0x4c13e9
// 004c13e3  ff1560b79800         call dword ptr [0x98b760]
// 004c13e9  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004c13ed  8b06                 mov eax, dword ptr [esi]
// 004c13ef  85c9                 test ecx, ecx
// 004c13f1  7404                 je 0x4c13f7
// 004c13f3  3bc8                 cmp ecx, eax
// 004c13f5  7406                 je 0x4c13fd
// 004c13f7  ff1560b79800         call dword ptr [0x98b760]
// 004c13fd  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 004c1401  2bdf                 sub ebx, edi
// 004c1403  c1fb03               sar ebx, 3
// 004c1406  8b542428             mov edx, dword ptr [esp + 0x28]
// 004c140a  8b442424             mov eax, dword ptr [esp + 0x24]
// 004c140e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004c1412  52                   push edx
// 004c1413  6a01                 push 1
// 004c1415  50                   push eax
// 004c1416  51                   push ecx
// 004c1417  8bce                 mov ecx, esi
// 004c1419  e872f9ffff           call 0x4c0d90
// 004c141e  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 004c1421  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 004c1424  7606                 jbe 0x4c142c
// 004c1426  ff1560b79800         call dword ptr [0x98b760]
// 004c142c  8b36                 mov esi, dword ptr [esi]
// 004c142e  8bee                 mov ebp, esi
// 004c1430  897c2414             mov dword ptr [esp + 0x14], edi
// 004c1434  85f6                 test esi, esi
// 004c1436  7518                 jne 0x4c1450
// 004c1438  ff1560b79800         call dword ptr [0x98b760]
// 004c143e  33c0                 xor eax, eax
// 004c1440  8d3cdf               lea edi, [edi + ebx*8]
// 004c1443  3b7810               cmp edi, dword ptr [eax + 0x10]
// 004c1446  7713                 ja 0x4c145b
// 004c1448  85f6                 test esi, esi
// 004c144a  7408                 je 0x4c1454
// 004c144c  8b36                 mov esi, dword ptr [esi]
// 004c144e  eb06                 jmp 0x4c1456
// 004c1450  8b06                 mov eax, dword ptr [esi]
// 004c1452  ebec                 jmp 0x4c1440
// 004c1454  33f6                 xor esi, esi
// 004c1456  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 004c1459  7306                 jae 0x4c1461
// 004c145b  ff1560b79800         call dword ptr [0x98b760]
// 004c1461  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004c1465  897804               mov dword ptr [eax + 4], edi
// 004c1468  5f                   pop edi
// 004c1469  5e                   pop esi
// 004c146a  8928                 mov dword ptr [eax], ebp
// 004c146c  5d                   pop ebp
// 004c146d  5b                   pop ebx
// 004c146e  83c408               add esp, 8
// 004c1471  c21000               ret 0x10
// standard library vector<double> (function ?insert@?$vector@NV?$allocator@N@std@@@std@@QAE?AV?$_Vector_iterator@NV?$allocator@N@std@@@2@V?$_Vector_const_iterator@NV?$allocator@N@std@@@2@ABN@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
