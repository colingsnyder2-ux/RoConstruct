// from server: 100% by auto
// roc 2008-06 005ecca0  unit: RBX::Sky  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005ecca0
//
// 005ecca0  56                   push esi
// 005ecca1  8bf1                 mov esi, ecx
// 005ecca3  8b06                 mov eax, dword ptr [esi]
// 005ecca5  57                   push edi
// 005ecca6  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 005eccaa  85c0                 test eax, eax
// 005eccac  7404                 je 0x5eccb2
// 005eccae  3b07                 cmp eax, dword ptr [edi]
// 005eccb0  7406                 je 0x5eccb8
// 005eccb2  ff1590288000         call dword ptr [0x802890]
// 005eccb8  8b4604               mov eax, dword ptr [esi + 4]
// 005eccbb  33c9                 xor ecx, ecx
// 005eccbd  3b4704               cmp eax, dword ptr [edi + 4]
// 005eccc0  5f                   pop edi
// 005eccc1  0f94c1               sete cl
// 005eccc4  8ac1                 mov al, cl
// 005eccc6  5e                   pop esi
// 005eccc7  c20400               ret 4
// standard library vector<ptr> (function ??8?$_Vector_const_iterator@PAUT@@V?$allocator@PAUT@@@std@@@std@@QBE_NABV01@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
