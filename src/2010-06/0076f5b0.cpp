// from server: 100% by auto
// roc 2010-06 0076f5b0  unit: RBX::ScoreHud  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0076f5b0
//
// 0076f5b0  56                   push esi
// 0076f5b1  8bf1                 mov esi, ecx
// 0076f5b3  833e00               cmp dword ptr [esi], 0
// 0076f5b6  57                   push edi
// 0076f5b7  8b3d0ca99e00         mov edi, dword ptr [0x9ea90c]
// 0076f5bd  7502                 jne 0x76f5c1
// 0076f5bf  ffd7                 call edi
// 0076f5c1  8b4604               mov eax, dword ptr [esi + 4]
// 0076f5c4  80782900             cmp byte ptr [eax + 0x29], 0
// 0076f5c8  7405                 je 0x76f5cf
// 0076f5ca  ffd7                 call edi
// 0076f5cc  5f                   pop edi
// 0076f5cd  5e                   pop esi
// 0076f5ce  c3                   ret 
// 0076f5cf  8b4808               mov ecx, dword ptr [eax + 8]
// 0076f5d2  80792900             cmp byte ptr [ecx + 0x29], 0
// 0076f5d6  7518                 jne 0x76f5f0
// 0076f5d8  8b01                 mov eax, dword ptr [ecx]
// 0076f5da  80782900             cmp byte ptr [eax + 0x29], 0
// 0076f5de  750a                 jne 0x76f5ea
// 0076f5e0  8bc8                 mov ecx, eax
// 0076f5e2  8b01                 mov eax, dword ptr [ecx]
// 0076f5e4  80782900             cmp byte ptr [eax + 0x29], 0
// 0076f5e8  74f6                 je 0x76f5e0
// 0076f5ea  5f                   pop edi
// 0076f5eb  894e04               mov dword ptr [esi + 4], ecx
// 0076f5ee  5e                   pop esi
// 0076f5ef  c3                   ret 
// 0076f5f0  8b4004               mov eax, dword ptr [eax + 4]
// 0076f5f3  80782900             cmp byte ptr [eax + 0x29], 0
// 0076f5f7  751d                 jne 0x76f616
// 0076f5f9  8da42400000000       lea esp, [esp]
// 0076f600  8b4e04               mov ecx, dword ptr [esi + 4]
// 0076f603  3b4808               cmp ecx, dword ptr [eax + 8]
// 0076f606  750e                 jne 0x76f616
// 0076f608  894604               mov dword ptr [esi + 4], eax
// 0076f60b  8bd0                 mov edx, eax
// 0076f60d  8b4204               mov eax, dword ptr [edx + 4]
// 0076f610  80782900             cmp byte ptr [eax + 0x29], 0
// 0076f614  74ea                 je 0x76f600
// 0076f616  5f                   pop edi
// 0076f617  894604               mov dword ptr [esi + 4], eax
// 0076f61a  5e                   pop esi
// 0076f61b  c3                   ret 
// standard library set<string> (function ?_Inc@const_iterator@?$_Tree@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@std@@QAEXXZ)

// stl: set<string>
#include <string>
typedef std::string E;
#include <set>
template class std::set<E>;
