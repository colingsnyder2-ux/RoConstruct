// from server: 100% by auto
// roc 2007-08 0041fd10  unit: CXTTreeCtrl  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0041fd10
//
// 0041fd10  56                   push esi
// 0041fd11  8bf1                 mov esi, ecx
// 0041fd13  8b06                 mov eax, dword ptr [esi]
// 0041fd15  85c0                 test eax, eax
// 0041fd17  57                   push edi
// 0041fd18  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0041fd1c  7404                 je 0x41fd22
// 0041fd1e  3b07                 cmp eax, dword ptr [edi]
// 0041fd20  7406                 je 0x41fd28
// 0041fd22  ff15d8e67700         call dword ptr [0x77e6d8]
// 0041fd28  8b4604               mov eax, dword ptr [esi + 4]
// 0041fd2b  2b4704               sub eax, dword ptr [edi + 4]
// 0041fd2e  5f                   pop edi
// 0041fd2f  c1f803               sar eax, 3
// 0041fd32  5e                   pop esi
// 0041fd33  c20400               ret 4
// standard library vector<double> (function ??G?$_Vector_const_iterator@NV?$allocator@N@std@@@std@@QBEHABV01@@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
