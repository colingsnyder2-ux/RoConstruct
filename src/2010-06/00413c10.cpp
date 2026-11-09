// from server: 100% by auto
// roc 2010-06 00413c10  unit: CopyVerb  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00413c10
//
// 00413c10  56                   push esi
// 00413c11  8bf1                 mov esi, ecx
// 00413c13  8b06                 mov eax, dword ptr [esi]
// 00413c15  57                   push edi
// 00413c16  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00413c1a  85c0                 test eax, eax
// 00413c1c  7404                 je 0x413c22
// 00413c1e  3b07                 cmp eax, dword ptr [edi]
// 00413c20  7406                 je 0x413c28
// 00413c22  ff150ca99e00         call dword ptr [0x9ea90c]
// 00413c28  8b4604               mov eax, dword ptr [esi + 4]
// 00413c2b  33c9                 xor ecx, ecx
// 00413c2d  3b4704               cmp eax, dword ptr [edi + 4]
// 00413c30  5f                   pop edi
// 00413c31  0f95c1               setne cl
// 00413c34  8ac1                 mov al, cl
// 00413c36  5e                   pop esi
// 00413c37  c20400               ret 4
// standard library vector<ptr> (function ??9?$_Vector_const_iterator@PAUT@@V?$allocator@PAUT@@@std@@@std@@QBE_NABV01@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
