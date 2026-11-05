// from server: 100% by auto
// roc 2007-08 004920f0  unit: RBX::Network::P8Players::?$GetImpl  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004920f0
//
// 004920f0  56                   push esi
// 004920f1  8bf1                 mov esi, ecx
// 004920f3  8b06                 mov eax, dword ptr [esi]
// 004920f5  85c0                 test eax, eax
// 004920f7  57                   push edi
// 004920f8  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 004920fc  7404                 je 0x492102
// 004920fe  3b07                 cmp eax, dword ptr [edi]
// 00492100  7406                 je 0x492108
// 00492102  ff15d8e67700         call dword ptr [0x77e6d8]
// 00492108  8b4604               mov eax, dword ptr [esi + 4]
// 0049210b  33c9                 xor ecx, ecx
// 0049210d  3b4704               cmp eax, dword ptr [edi + 4]
// 00492110  5f                   pop edi
// 00492111  0f95c1               setne cl
// 00492114  8ac1                 mov al, cl
// 00492116  5e                   pop esi
// 00492117  c20400               ret 4
// standard library vector<ptr> (function ??9?$_Vector_const_iterator@PAUT@@V?$allocator@PAUT@@@std@@@std@@QBE_NABV01@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
