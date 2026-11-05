// from server: 100% by auto
// roc 2008-06 00438770  unit: RBX::Soundscape::VSoundId::?$XItem  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00438770
//
// 00438770  56                   push esi
// 00438771  8bf1                 mov esi, ecx
// 00438773  833e00               cmp dword ptr [esi], 0
// 00438776  57                   push edi
// 00438777  8b3d90288000         mov edi, dword ptr [0x802890]
// 0043877d  7502                 jne 0x438781
// 0043877f  ffd7                 call edi
// 00438781  8b4604               mov eax, dword ptr [esi + 4]
// 00438784  80782900             cmp byte ptr [eax + 0x29], 0
// 00438788  7405                 je 0x43878f
// 0043878a  ffd7                 call edi
// 0043878c  5f                   pop edi
// 0043878d  5e                   pop esi
// 0043878e  c3                   ret 
// 0043878f  8b4808               mov ecx, dword ptr [eax + 8]
// 00438792  80792900             cmp byte ptr [ecx + 0x29], 0
// 00438796  7518                 jne 0x4387b0
// 00438798  8b01                 mov eax, dword ptr [ecx]
// 0043879a  80782900             cmp byte ptr [eax + 0x29], 0
// 0043879e  750a                 jne 0x4387aa
// 004387a0  8bc8                 mov ecx, eax
// 004387a2  8b01                 mov eax, dword ptr [ecx]
// 004387a4  80782900             cmp byte ptr [eax + 0x29], 0
// 004387a8  74f6                 je 0x4387a0
// 004387aa  5f                   pop edi
// 004387ab  894e04               mov dword ptr [esi + 4], ecx
// 004387ae  5e                   pop esi
// 004387af  c3                   ret 
// 004387b0  8b4004               mov eax, dword ptr [eax + 4]
// 004387b3  80782900             cmp byte ptr [eax + 0x29], 0
// 004387b7  751d                 jne 0x4387d6
// 004387b9  8da42400000000       lea esp, [esp]
// 004387c0  8b4e04               mov ecx, dword ptr [esi + 4]
// 004387c3  3b4808               cmp ecx, dword ptr [eax + 8]
// 004387c6  750e                 jne 0x4387d6
// 004387c8  894604               mov dword ptr [esi + 4], eax
// 004387cb  8bd0                 mov edx, eax
// 004387cd  8b4204               mov eax, dword ptr [edx + 4]
// 004387d0  80782900             cmp byte ptr [eax + 0x29], 0
// 004387d4  74ea                 je 0x4387c0
// 004387d6  5f                   pop edi
// 004387d7  894604               mov dword ptr [esi + 4], eax
// 004387da  5e                   pop esi
// 004387db  c3                   ret 
// standard library set<string> (function ?_Inc@const_iterator@?$_Tree@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@std@@QAEXXZ)

// stl: set<string>
#include <string>
typedef std::string E;
#include <set>
template class std::set<E>;
