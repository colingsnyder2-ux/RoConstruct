// from server: 100% by auto
// roc 2007-08 005d9f20  unit: RBX::VVelocityMotor::?$FactoryProduct  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005d9f20
//
// 005d9f20  56                   push esi
// 005d9f21  8bf1                 mov esi, ecx
// 005d9f23  833e00               cmp dword ptr [esi], 0
// 005d9f26  57                   push edi
// 005d9f27  8b3dd8e67700         mov edi, dword ptr [0x77e6d8]
// 005d9f2d  7502                 jne 0x5d9f31
// 005d9f2f  ffd7                 call edi
// 005d9f31  8b4604               mov eax, dword ptr [esi + 4]
// 005d9f34  80782d00             cmp byte ptr [eax + 0x2d], 0
// 005d9f38  7405                 je 0x5d9f3f
// 005d9f3a  ffd7                 call edi
// 005d9f3c  5f                   pop edi
// 005d9f3d  5e                   pop esi
// 005d9f3e  c3                   ret 
// 005d9f3f  8b4808               mov ecx, dword ptr [eax + 8]
// 005d9f42  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 005d9f46  7518                 jne 0x5d9f60
// 005d9f48  8b01                 mov eax, dword ptr [ecx]
// 005d9f4a  80782d00             cmp byte ptr [eax + 0x2d], 0
// 005d9f4e  750a                 jne 0x5d9f5a
// 005d9f50  8bc8                 mov ecx, eax
// 005d9f52  8b01                 mov eax, dword ptr [ecx]
// 005d9f54  80782d00             cmp byte ptr [eax + 0x2d], 0
// 005d9f58  74f6                 je 0x5d9f50
// 005d9f5a  5f                   pop edi
// 005d9f5b  894e04               mov dword ptr [esi + 4], ecx
// 005d9f5e  5e                   pop esi
// 005d9f5f  c3                   ret 
// 005d9f60  8b4004               mov eax, dword ptr [eax + 4]
// 005d9f63  80782d00             cmp byte ptr [eax + 0x2d], 0
// 005d9f67  751d                 jne 0x5d9f86
// 005d9f69  8da42400000000       lea esp, [esp]
// 005d9f70  8b4e04               mov ecx, dword ptr [esi + 4]
// 005d9f73  3b4808               cmp ecx, dword ptr [eax + 8]
// 005d9f76  750e                 jne 0x5d9f86
// 005d9f78  894604               mov dword ptr [esi + 4], eax
// 005d9f7b  8bd0                 mov edx, eax
// 005d9f7d  8b4204               mov eax, dword ptr [edx + 4]
// 005d9f80  80782d00             cmp byte ptr [eax + 0x2d], 0
// 005d9f84  74ea                 je 0x5d9f70
// 005d9f86  5f                   pop edi
// 005d9f87  894604               mov dword ptr [esi + 4], eax
// 005d9f8a  5e                   pop esi
// 005d9f8b  c3                   ret 
// standard library set<pod32> (function ?_Inc@const_iterator@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: set<pod32>
struct E { int v[8]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
