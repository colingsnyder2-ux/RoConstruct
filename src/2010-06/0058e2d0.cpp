// from server: 100% by auto
// roc 2010-06 0058e2d0  unit: seg_00580000  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0058e2d0
//
// 0058e2d0  56                   push esi
// 0058e2d1  8bf1                 mov esi, ecx
// 0058e2d3  833e00               cmp dword ptr [esi], 0
// 0058e2d6  57                   push edi
// 0058e2d7  8b3d0ca99e00         mov edi, dword ptr [0x9ea90c]
// 0058e2dd  7502                 jne 0x58e2e1
// 0058e2df  ffd7                 call edi
// 0058e2e1  8b4604               mov eax, dword ptr [esi + 4]
// 0058e2e4  80781d00             cmp byte ptr [eax + 0x1d], 0
// 0058e2e8  7405                 je 0x58e2ef
// 0058e2ea  ffd7                 call edi
// 0058e2ec  5f                   pop edi
// 0058e2ed  5e                   pop esi
// 0058e2ee  c3                   ret 
// 0058e2ef  8b4808               mov ecx, dword ptr [eax + 8]
// 0058e2f2  80791d00             cmp byte ptr [ecx + 0x1d], 0
// 0058e2f6  7518                 jne 0x58e310
// 0058e2f8  8b01                 mov eax, dword ptr [ecx]
// 0058e2fa  80781d00             cmp byte ptr [eax + 0x1d], 0
// 0058e2fe  750a                 jne 0x58e30a
// 0058e300  8bc8                 mov ecx, eax
// 0058e302  8b01                 mov eax, dword ptr [ecx]
// 0058e304  80781d00             cmp byte ptr [eax + 0x1d], 0
// 0058e308  74f6                 je 0x58e300
// 0058e30a  5f                   pop edi
// 0058e30b  894e04               mov dword ptr [esi + 4], ecx
// 0058e30e  5e                   pop esi
// 0058e30f  c3                   ret 
// 0058e310  8b4004               mov eax, dword ptr [eax + 4]
// 0058e313  80781d00             cmp byte ptr [eax + 0x1d], 0
// 0058e317  751d                 jne 0x58e336
// 0058e319  8da42400000000       lea esp, [esp]
// 0058e320  8b4e04               mov ecx, dword ptr [esi + 4]
// 0058e323  3b4808               cmp ecx, dword ptr [eax + 8]
// 0058e326  750e                 jne 0x58e336
// 0058e328  894604               mov dword ptr [esi + 4], eax
// 0058e32b  8bd0                 mov edx, eax
// 0058e32d  8b4204               mov eax, dword ptr [edx + 4]
// 0058e330  80781d00             cmp byte ptr [eax + 0x1d], 0
// 0058e334  74ea                 je 0x58e320
// 0058e336  5f                   pop edi
// 0058e337  894604               mov dword ptr [esi + 4], eax
// 0058e33a  5e                   pop esi
// 0058e33b  c3                   ret 
// standard library set<pod16> (function ?_Inc@const_iterator@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: set<pod16>
struct E { int v[4]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
