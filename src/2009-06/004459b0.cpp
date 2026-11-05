// from server: 100% by auto
// roc 2009-06 004459b0  unit: CRobloxApp  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004459b0
//
// 004459b0  56                   push esi
// 004459b1  8bf1                 mov esi, ecx
// 004459b3  833e00               cmp dword ptr [esi], 0
// 004459b6  57                   push edi
// 004459b7  8b3dace98900         mov edi, dword ptr [0x89e9ac]
// 004459bd  7502                 jne 0x4459c1
// 004459bf  ffd7                 call edi
// 004459c1  8b4604               mov eax, dword ptr [esi + 4]
// 004459c4  80782500             cmp byte ptr [eax + 0x25], 0
// 004459c8  7405                 je 0x4459cf
// 004459ca  ffd7                 call edi
// 004459cc  5f                   pop edi
// 004459cd  5e                   pop esi
// 004459ce  c3                   ret 
// 004459cf  8b4808               mov ecx, dword ptr [eax + 8]
// 004459d2  80792500             cmp byte ptr [ecx + 0x25], 0
// 004459d6  7518                 jne 0x4459f0
// 004459d8  8b01                 mov eax, dword ptr [ecx]
// 004459da  80782500             cmp byte ptr [eax + 0x25], 0
// 004459de  750a                 jne 0x4459ea
// 004459e0  8bc8                 mov ecx, eax
// 004459e2  8b01                 mov eax, dword ptr [ecx]
// 004459e4  80782500             cmp byte ptr [eax + 0x25], 0
// 004459e8  74f6                 je 0x4459e0
// 004459ea  5f                   pop edi
// 004459eb  894e04               mov dword ptr [esi + 4], ecx
// 004459ee  5e                   pop esi
// 004459ef  c3                   ret 
// 004459f0  8b4004               mov eax, dword ptr [eax + 4]
// 004459f3  80782500             cmp byte ptr [eax + 0x25], 0
// 004459f7  751d                 jne 0x445a16
// 004459f9  8da42400000000       lea esp, [esp]
// 00445a00  8b4e04               mov ecx, dword ptr [esi + 4]
// 00445a03  3b4808               cmp ecx, dword ptr [eax + 8]
// 00445a06  750e                 jne 0x445a16
// 00445a08  894604               mov dword ptr [esi + 4], eax
// 00445a0b  8bd0                 mov edx, eax
// 00445a0d  8b4204               mov eax, dword ptr [edx + 4]
// 00445a10  80782500             cmp byte ptr [eax + 0x25], 0
// 00445a14  74ea                 je 0x445a00
// 00445a16  5f                   pop edi
// 00445a17  894604               mov dword ptr [esi + 4], eax
// 00445a1a  5e                   pop esi
// 00445a1b  c3                   ret 
// standard library set<pod24> (function ?_Inc@const_iterator@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: set<pod24>
struct E { int v[6]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
