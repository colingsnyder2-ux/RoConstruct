// from server: 100% by auto
// roc 2009-12 005cc360  unit: RBX::MeshRefPartAdapter  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005cc360
//
// 005cc360  56                   push esi
// 005cc361  8bf1                 mov esi, ecx
// 005cc363  8b06                 mov eax, dword ptr [esi]
// 005cc365  57                   push edi
// 005cc366  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 005cc36a  85c0                 test eax, eax
// 005cc36c  7404                 je 0x5cc372
// 005cc36e  3b07                 cmp eax, dword ptr [edi]
// 005cc370  7406                 je 0x5cc378
// 005cc372  ff1560b79800         call dword ptr [0x98b760]
// 005cc378  8b4604               mov eax, dword ptr [esi + 4]
// 005cc37b  33c9                 xor ecx, ecx
// 005cc37d  3b4704               cmp eax, dword ptr [edi + 4]
// 005cc380  5f                   pop edi
// 005cc381  0f94c1               sete cl
// 005cc384  8ac1                 mov al, cl
// 005cc386  5e                   pop esi
// 005cc387  c20400               ret 4
// standard library vector<ptr> (function ??8?$_Vector_const_iterator@PAUT@@V?$allocator@PAUT@@@std@@@std@@QBE_NABV01@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
