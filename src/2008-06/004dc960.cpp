// from server: 100% by auto
// roc 2008-06 004dc960  unit: RBX::ViewNew::ViewG3D  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004dc960
//
// 004dc960  53                   push ebx
// 004dc961  8b1d90288000         mov ebx, dword ptr [0x802890]
// 004dc967  56                   push esi
// 004dc968  8b31                 mov esi, dword ptr [ecx]
// 004dc96a  57                   push edi
// 004dc96b  8b7904               mov edi, dword ptr [ecx + 4]
// 004dc96e  85f6                 test esi, esi
// 004dc970  7518                 jne 0x4dc98a
// 004dc972  ffd3                 call ebx
// 004dc974  33c0                 xor eax, eax
// 004dc976  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004dc97a  8d3c4f               lea edi, [edi + ecx*2]
// 004dc97d  3b7810               cmp edi, dword ptr [eax + 0x10]
// 004dc980  7713                 ja 0x4dc995
// 004dc982  85f6                 test esi, esi
// 004dc984  7408                 je 0x4dc98e
// 004dc986  8b06                 mov eax, dword ptr [esi]
// 004dc988  eb06                 jmp 0x4dc990
// 004dc98a  8b06                 mov eax, dword ptr [esi]
// 004dc98c  ebe8                 jmp 0x4dc976
// 004dc98e  33c0                 xor eax, eax
// 004dc990  3b780c               cmp edi, dword ptr [eax + 0xc]
// 004dc993  7302                 jae 0x4dc997
// 004dc995  ffd3                 call ebx
// 004dc997  8b442410             mov eax, dword ptr [esp + 0x10]
// 004dc99b  897804               mov dword ptr [eax + 4], edi
// 004dc99e  5f                   pop edi
// 004dc99f  8930                 mov dword ptr [eax], esi
// 004dc9a1  5e                   pop esi
// 004dc9a2  5b                   pop ebx
// 004dc9a3  c20800               ret 8
// standard library vector<short> (function ??H?$_Vector_const_iterator@FV?$allocator@F@std@@@std@@QBE?AV01@H@Z)

// stl: vector<short>
typedef short E;
#include <vector>
template class std::vector<E>;
