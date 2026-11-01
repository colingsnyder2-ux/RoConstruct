// from server: 100% by auto
// roc 2009-12 00513b30  unit: RBX::Network::Players::W4ChatOption::?$holder  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00513b30
//
// 00513b30  56                   push esi
// 00513b31  8bf1                 mov esi, ecx
// 00513b33  8b06                 mov eax, dword ptr [esi]
// 00513b35  57                   push edi
// 00513b36  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00513b3a  85c0                 test eax, eax
// 00513b3c  7404                 je 0x513b42
// 00513b3e  3b07                 cmp eax, dword ptr [edi]
// 00513b40  7406                 je 0x513b48
// 00513b42  ff1560b79800         call dword ptr [0x98b760]
// 00513b48  8b4604               mov eax, dword ptr [esi + 4]
// 00513b4b  33c9                 xor ecx, ecx
// 00513b4d  3b4704               cmp eax, dword ptr [edi + 4]
// 00513b50  5f                   pop edi
// 00513b51  0f95c1               setne cl
// 00513b54  8ac1                 mov al, cl
// 00513b56  5e                   pop esi
// 00513b57  c20400               ret 4
// standard library vector<ptr> (function ??9?$_Vector_const_iterator@PAUT@@V?$allocator@PAUT@@@std@@@std@@QBE_NABV01@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
