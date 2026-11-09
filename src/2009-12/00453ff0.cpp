// from server: 100% by auto
// roc 2009-12 00453ff0  unit: CRobloxControlMaterialSelector  size: 206 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00453ff0
//
// 00453ff0  83ec08               sub esp, 8
// 00453ff3  53                   push ebx
// 00453ff4  55                   push ebp
// 00453ff5  56                   push esi
// 00453ff6  8bf1                 mov esi, ecx
// 00453ff8  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 00453ffb  57                   push edi
// 00453ffc  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 00453fff  8bcb                 mov ecx, ebx
// 00454001  2bcf                 sub ecx, edi
// 00454003  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00454008  f7e9                 imul ecx
// 0045400a  d1fa                 sar edx, 1
// 0045400c  8bc2                 mov eax, edx
// 0045400e  c1e81f               shr eax, 0x1f
// 00454011  03c2                 add eax, edx
// 00454013  7504                 jne 0x454019
// 00454015  33ff                 xor edi, edi
// 00454017  eb34                 jmp 0x45404d
// 00454019  3bfb                 cmp edi, ebx
// 0045401b  7606                 jbe 0x454023
// 0045401d  ff1560b79800         call dword ptr [0x98b760]
// 00454023  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00454027  8b06                 mov eax, dword ptr [esi]
// 00454029  85c9                 test ecx, ecx
// 0045402b  7404                 je 0x454031
// 0045402d  3bc8                 cmp ecx, eax
// 0045402f  7406                 je 0x454037
// 00454031  ff1560b79800         call dword ptr [0x98b760]
// 00454037  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0045403b  2bcf                 sub ecx, edi
// 0045403d  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00454042  f7e9                 imul ecx
// 00454044  d1fa                 sar edx, 1
// 00454046  8bfa                 mov edi, edx
// 00454048  c1ef1f               shr edi, 0x1f
// 0045404b  03fa                 add edi, edx
// 0045404d  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00454051  8b542424             mov edx, dword ptr [esp + 0x24]
// 00454055  8b442420             mov eax, dword ptr [esp + 0x20]
// 00454059  51                   push ecx
// 0045405a  6a01                 push 1
// 0045405c  52                   push edx
// 0045405d  50                   push eax
// 0045405e  8bce                 mov ecx, esi
// 00454060  e84bfcffff           call 0x453cb0
// 00454065  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 00454068  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 0045406b  7606                 jbe 0x454073
// 0045406d  ff1560b79800         call dword ptr [0x98b760]
// 00454073  8b36                 mov esi, dword ptr [esi]
// 00454075  8bee                 mov ebp, esi
// 00454077  895c2414             mov dword ptr [esp + 0x14], ebx
// 0045407b  85f6                 test esi, esi
// 0045407d  751b                 jne 0x45409a
// 0045407f  ff1560b79800         call dword ptr [0x98b760]
// 00454085  33c0                 xor eax, eax
// 00454087  8d0c7f               lea ecx, [edi + edi*2]
// 0045408a  8d3c8b               lea edi, [ebx + ecx*4]
// 0045408d  3b7810               cmp edi, dword ptr [eax + 0x10]
// 00454090  7713                 ja 0x4540a5
// 00454092  85f6                 test esi, esi
// 00454094  7408                 je 0x45409e
// 00454096  8b36                 mov esi, dword ptr [esi]
// 00454098  eb06                 jmp 0x4540a0
// 0045409a  8b06                 mov eax, dword ptr [esi]
// 0045409c  ebe9                 jmp 0x454087
// 0045409e  33f6                 xor esi, esi
// 004540a0  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 004540a3  7306                 jae 0x4540ab
// 004540a5  ff1560b79800         call dword ptr [0x98b760]
// 004540ab  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004540af  897804               mov dword ptr [eax + 4], edi
// 004540b2  5f                   pop edi
// 004540b3  5e                   pop esi
// 004540b4  8928                 mov dword ptr [eax], ebp
// 004540b6  5d                   pop ebp
// 004540b7  5b                   pop ebx
// 004540b8  83c408               add esp, 8
// 004540bb  c21000               ret 0x10
// standard library vector<pod12> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
