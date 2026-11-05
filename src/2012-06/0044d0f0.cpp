// from server: 100% by auto
// roc 2012-06 0044d0f0  unit: PasteVerb  size: 74 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0044d0f0
//
// 0044d0f0  56                   push esi
// 0044d0f1  8bf1                 mov esi, ecx
// 0044d0f3  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 0044d0f7  743f                 je 0x44d138
// 0044d0f9  8b4618               mov eax, dword ptr [esi + 0x18]
// 0044d0fc  8b5610               mov edx, dword ptr [esi + 0x10]
// 0044d0ff  8bc8                 mov ecx, eax
// 0044d101  c1e904               shr ecx, 4
// 0044d104  83e00f               and eax, 0xf
// 0044d107  03048a               add eax, dword ptr [edx + ecx*4]
// 0044d10a  8d4e0c               lea ecx, [esi + 0xc]
// 0044d10d  50                   push eax
// 0044d10e  ff152826b200         call dword ptr [0xb22628]
// 0044d114  ff4618               inc dword ptr [esi + 0x18]
// 0044d117  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 0044d11a  8b4618               mov eax, dword ptr [esi + 0x18]
// 0044d11d  c1e104               shl ecx, 4
// 0044d120  3bc8                 cmp ecx, eax
// 0044d122  7707                 ja 0x44d12b
// 0044d124  c7461800000000       mov dword ptr [esi + 0x18], 0
// 0044d12b  83461cff             add dword ptr [esi + 0x1c], -1
// 0044d12f  7507                 jne 0x44d138
// 0044d131  c7461800000000       mov dword ptr [esi + 0x18], 0
// 0044d138  5e                   pop esi
// 0044d139  c3                   ret 
// standard library deque<char> (function ?pop_front@?$deque@DV?$allocator@D@std@@@std@@QAEXXZ)

// stl: deque<char>
typedef char E;
#include <deque>
template class std::deque<E>;
