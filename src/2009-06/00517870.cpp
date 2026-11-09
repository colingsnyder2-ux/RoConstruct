// from server: 100% by auto
// roc 2009-06 00517870  unit: RBX::VMaterialBase::?$WeakReferenceCountedPointer  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00517870
//
// 00517870  56                   push esi
// 00517871  8bf1                 mov esi, ecx
// 00517873  833e00               cmp dword ptr [esi], 0
// 00517876  57                   push edi
// 00517877  8b3dace98900         mov edi, dword ptr [0x89e9ac]
// 0051787d  7502                 jne 0x517881
// 0051787f  ffd7                 call edi
// 00517881  8b4604               mov eax, dword ptr [esi + 4]
// 00517884  80782900             cmp byte ptr [eax + 0x29], 0
// 00517888  7405                 je 0x51788f
// 0051788a  ffd7                 call edi
// 0051788c  5f                   pop edi
// 0051788d  5e                   pop esi
// 0051788e  c3                   ret 
// 0051788f  8b4808               mov ecx, dword ptr [eax + 8]
// 00517892  80792900             cmp byte ptr [ecx + 0x29], 0
// 00517896  7518                 jne 0x5178b0
// 00517898  8b01                 mov eax, dword ptr [ecx]
// 0051789a  80782900             cmp byte ptr [eax + 0x29], 0
// 0051789e  750a                 jne 0x5178aa
// 005178a0  8bc8                 mov ecx, eax
// 005178a2  8b01                 mov eax, dword ptr [ecx]
// 005178a4  80782900             cmp byte ptr [eax + 0x29], 0
// 005178a8  74f6                 je 0x5178a0
// 005178aa  5f                   pop edi
// 005178ab  894e04               mov dword ptr [esi + 4], ecx
// 005178ae  5e                   pop esi
// 005178af  c3                   ret 
// 005178b0  8b4004               mov eax, dword ptr [eax + 4]
// 005178b3  80782900             cmp byte ptr [eax + 0x29], 0
// 005178b7  751d                 jne 0x5178d6
// 005178b9  8da42400000000       lea esp, [esp]
// 005178c0  8b4e04               mov ecx, dword ptr [esi + 4]
// 005178c3  3b4808               cmp ecx, dword ptr [eax + 8]
// 005178c6  750e                 jne 0x5178d6
// 005178c8  894604               mov dword ptr [esi + 4], eax
// 005178cb  8bd0                 mov edx, eax
// 005178cd  8b4204               mov eax, dword ptr [edx + 4]
// 005178d0  80782900             cmp byte ptr [eax + 0x29], 0
// 005178d4  74ea                 je 0x5178c0
// 005178d6  5f                   pop edi
// 005178d7  894604               mov dword ptr [esi + 4], eax
// 005178da  5e                   pop esi
// 005178db  c3                   ret 
// standard library set<string> (function ?_Inc@const_iterator@?$_Tree@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@std@@QAEXXZ)

// stl: set<string>
#include <string>
typedef std::string E;
#include <set>
template class std::set<E>;
