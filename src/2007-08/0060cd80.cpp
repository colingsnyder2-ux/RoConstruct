// from server: 100% by auto
// roc 2007-08 0060cd80  unit: RBX::Block  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0060cd80
//
// 0060cd80  56                   push esi
// 0060cd81  8bf1                 mov esi, ecx
// 0060cd83  833e00               cmp dword ptr [esi], 0
// 0060cd86  57                   push edi
// 0060cd87  8b3dd8e67700         mov edi, dword ptr [0x77e6d8]
// 0060cd8d  7502                 jne 0x60cd91
// 0060cd8f  ffd7                 call edi
// 0060cd91  8b4604               mov eax, dword ptr [esi + 4]
// 0060cd94  80781d00             cmp byte ptr [eax + 0x1d], 0
// 0060cd98  7405                 je 0x60cd9f
// 0060cd9a  ffd7                 call edi
// 0060cd9c  5f                   pop edi
// 0060cd9d  5e                   pop esi
// 0060cd9e  c3                   ret 
// 0060cd9f  8b4808               mov ecx, dword ptr [eax + 8]
// 0060cda2  80791d00             cmp byte ptr [ecx + 0x1d], 0
// 0060cda6  7518                 jne 0x60cdc0
// 0060cda8  8b01                 mov eax, dword ptr [ecx]
// 0060cdaa  80781d00             cmp byte ptr [eax + 0x1d], 0
// 0060cdae  750a                 jne 0x60cdba
// 0060cdb0  8bc8                 mov ecx, eax
// 0060cdb2  8b01                 mov eax, dword ptr [ecx]
// 0060cdb4  80781d00             cmp byte ptr [eax + 0x1d], 0
// 0060cdb8  74f6                 je 0x60cdb0
// 0060cdba  5f                   pop edi
// 0060cdbb  894e04               mov dword ptr [esi + 4], ecx
// 0060cdbe  5e                   pop esi
// 0060cdbf  c3                   ret 
// 0060cdc0  8b4004               mov eax, dword ptr [eax + 4]
// 0060cdc3  80781d00             cmp byte ptr [eax + 0x1d], 0
// 0060cdc7  751d                 jne 0x60cde6
// 0060cdc9  8da42400000000       lea esp, [esp]
// 0060cdd0  8b4e04               mov ecx, dword ptr [esi + 4]
// 0060cdd3  3b4808               cmp ecx, dword ptr [eax + 8]
// 0060cdd6  750e                 jne 0x60cde6
// 0060cdd8  894604               mov dword ptr [esi + 4], eax
// 0060cddb  8bd0                 mov edx, eax
// 0060cddd  8b4204               mov eax, dword ptr [edx + 4]
// 0060cde0  80781d00             cmp byte ptr [eax + 0x1d], 0
// 0060cde4  74ea                 je 0x60cdd0
// 0060cde6  5f                   pop edi
// 0060cde7  894604               mov dword ptr [esi + 4], eax
// 0060cdea  5e                   pop esi
// 0060cdeb  c3                   ret 
// standard library set<pod16> (function ?_Inc@const_iterator@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: set<pod16>
struct E { int v[4]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
