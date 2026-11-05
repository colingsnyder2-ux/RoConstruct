// from server: 100% by auto
// roc 2009-06 006434a0  unit: RBX::WoodTool  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006434a0
//
// 006434a0  56                   push esi
// 006434a1  8bf1                 mov esi, ecx
// 006434a3  8b06                 mov eax, dword ptr [esi]
// 006434a5  57                   push edi
// 006434a6  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 006434aa  85c0                 test eax, eax
// 006434ac  7404                 je 0x6434b2
// 006434ae  3b07                 cmp eax, dword ptr [edi]
// 006434b0  7406                 je 0x6434b8
// 006434b2  ff15ace98900         call dword ptr [0x89e9ac]
// 006434b8  8b4604               mov eax, dword ptr [esi + 4]
// 006434bb  33c9                 xor ecx, ecx
// 006434bd  3b4704               cmp eax, dword ptr [edi + 4]
// 006434c0  5f                   pop edi
// 006434c1  0f94c1               sete cl
// 006434c4  8ac1                 mov al, cl
// 006434c6  5e                   pop esi
// 006434c7  c20400               ret 4
// standard library vector<ptr> (function ??8?$_Vector_const_iterator@PAUT@@V?$allocator@PAUT@@@std@@@std@@QBE_NABV01@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
