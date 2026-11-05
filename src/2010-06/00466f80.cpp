// from server: 100% by auto
// roc 2010-06 00466f80  unit: CRobloxWnd::PartDropTarget  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00466f80
//
// 00466f80  56                   push esi
// 00466f81  8bf1                 mov esi, ecx
// 00466f83  8b06                 mov eax, dword ptr [esi]
// 00466f85  57                   push edi
// 00466f86  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00466f8a  85c0                 test eax, eax
// 00466f8c  7404                 je 0x466f92
// 00466f8e  3b07                 cmp eax, dword ptr [edi]
// 00466f90  7406                 je 0x466f98
// 00466f92  ff150ca99e00         call dword ptr [0x9ea90c]
// 00466f98  8b4604               mov eax, dword ptr [esi + 4]
// 00466f9b  33c9                 xor ecx, ecx
// 00466f9d  3b4704               cmp eax, dword ptr [edi + 4]
// 00466fa0  5f                   pop edi
// 00466fa1  0f94c1               sete cl
// 00466fa4  8ac1                 mov al, cl
// 00466fa6  5e                   pop esi
// 00466fa7  c20400               ret 4
// standard library vector<ptr> (function ??8?$_Vector_const_iterator@PAUT@@V?$allocator@PAUT@@@std@@@std@@QBE_NABV01@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
