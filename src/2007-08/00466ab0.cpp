// from server: 100% by auto
// roc 2007-08 00466ab0  unit: CWebToolbox  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00466ab0
//
// 00466ab0  56                   push esi
// 00466ab1  8bf1                 mov esi, ecx
// 00466ab3  8b06                 mov eax, dword ptr [esi]
// 00466ab5  85c0                 test eax, eax
// 00466ab7  57                   push edi
// 00466ab8  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00466abc  7404                 je 0x466ac2
// 00466abe  3b07                 cmp eax, dword ptr [edi]
// 00466ac0  7406                 je 0x466ac8
// 00466ac2  ff15d8e67700         call dword ptr [0x77e6d8]
// 00466ac8  8b4604               mov eax, dword ptr [esi + 4]
// 00466acb  33c9                 xor ecx, ecx
// 00466acd  3b4704               cmp eax, dword ptr [edi + 4]
// 00466ad0  5f                   pop edi
// 00466ad1  0f94c1               sete cl
// 00466ad4  8ac1                 mov al, cl
// 00466ad6  5e                   pop esi
// 00466ad7  c20400               ret 4
// standard library vector<ptr> (function ??8?$_Vector_const_iterator@PAUT@@V?$allocator@PAUT@@@std@@@std@@QBE_NABV01@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
