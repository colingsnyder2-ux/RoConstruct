// from server: 100% by auto
// roc 2008-06 004969c0  unit: RBX::Network::Players::Plugin  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004969c0
//
// 004969c0  56                   push esi
// 004969c1  8bf1                 mov esi, ecx
// 004969c3  8b06                 mov eax, dword ptr [esi]
// 004969c5  57                   push edi
// 004969c6  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 004969ca  85c0                 test eax, eax
// 004969cc  7404                 je 0x4969d2
// 004969ce  3b07                 cmp eax, dword ptr [edi]
// 004969d0  7406                 je 0x4969d8
// 004969d2  ff1590288000         call dword ptr [0x802890]
// 004969d8  8b4604               mov eax, dword ptr [esi + 4]
// 004969db  33c9                 xor ecx, ecx
// 004969dd  3b4704               cmp eax, dword ptr [edi + 4]
// 004969e0  5f                   pop edi
// 004969e1  0f95c1               setne cl
// 004969e4  8ac1                 mov al, cl
// 004969e6  5e                   pop esi
// 004969e7  c20400               ret 4
// standard library vector<ptr> (function ??9?$_Vector_const_iterator@PAUT@@V?$allocator@PAUT@@@std@@@std@@QBE_NABV01@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
