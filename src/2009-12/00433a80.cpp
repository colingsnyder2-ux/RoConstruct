// from server: 100% by auto
// roc 2009-12 00433a80  unit: CPropGrid::UpdateItemsJob  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00433a80
//
// 00433a80  53                   push ebx
// 00433a81  8b1d60b79800         mov ebx, dword ptr [0x98b760]
// 00433a87  56                   push esi
// 00433a88  8b31                 mov esi, dword ptr [ecx]
// 00433a8a  57                   push edi
// 00433a8b  8b7904               mov edi, dword ptr [ecx + 4]
// 00433a8e  85f6                 test esi, esi
// 00433a90  7518                 jne 0x433aaa
// 00433a92  ffd3                 call ebx
// 00433a94  33c0                 xor eax, eax
// 00433a96  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00433a9a  8d3c8f               lea edi, [edi + ecx*4]
// 00433a9d  3b7810               cmp edi, dword ptr [eax + 0x10]
// 00433aa0  7713                 ja 0x433ab5
// 00433aa2  85f6                 test esi, esi
// 00433aa4  7408                 je 0x433aae
// 00433aa6  8b06                 mov eax, dword ptr [esi]
// 00433aa8  eb06                 jmp 0x433ab0
// 00433aaa  8b06                 mov eax, dword ptr [esi]
// 00433aac  ebe8                 jmp 0x433a96
// 00433aae  33c0                 xor eax, eax
// 00433ab0  3b780c               cmp edi, dword ptr [eax + 0xc]
// 00433ab3  7302                 jae 0x433ab7
// 00433ab5  ffd3                 call ebx
// 00433ab7  8b442410             mov eax, dword ptr [esp + 0x10]
// 00433abb  897804               mov dword ptr [eax + 4], edi
// 00433abe  5f                   pop edi
// 00433abf  8930                 mov dword ptr [eax], esi
// 00433ac1  5e                   pop esi
// 00433ac2  5b                   pop ebx
// 00433ac3  c20800               ret 8
// standard library vector<ptr> (function ??H?$_Vector_const_iterator@PAUT@@V?$allocator@PAUT@@@std@@@std@@QBE?AV01@H@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
