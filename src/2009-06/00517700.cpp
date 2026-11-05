// from server: 100% by auto
// roc 2009-06 00517700  unit: RBX::VMaterialBase::?$WeakReferenceCountedPointer  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00517700
//
// 00517700  56                   push esi
// 00517701  8bf1                 mov esi, ecx
// 00517703  833e00               cmp dword ptr [esi], 0
// 00517706  57                   push edi
// 00517707  8b3dace98900         mov edi, dword ptr [0x89e9ac]
// 0051770d  7502                 jne 0x517711
// 0051770f  ffd7                 call edi
// 00517711  8b4604               mov eax, dword ptr [esi + 4]
// 00517714  80782900             cmp byte ptr [eax + 0x29], 0
// 00517718  7411                 je 0x51772b
// 0051771a  8b4008               mov eax, dword ptr [eax + 8]
// 0051771d  894604               mov dword ptr [esi + 4], eax
// 00517720  80782900             cmp byte ptr [eax + 0x29], 0
// 00517724  745b                 je 0x517781
// 00517726  ffd7                 call edi
// 00517728  5f                   pop edi
// 00517729  5e                   pop esi
// 0051772a  c3                   ret 
// 0051772b  8b08                 mov ecx, dword ptr [eax]
// 0051772d  80792900             cmp byte ptr [ecx + 0x29], 0
// 00517731  751e                 jne 0x517751
// 00517733  8b4108               mov eax, dword ptr [ecx + 8]
// 00517736  80782900             cmp byte ptr [eax + 0x29], 0
// 0051773a  750f                 jne 0x51774b
// 0051773c  8d642400             lea esp, [esp]
// 00517740  8bc8                 mov ecx, eax
// 00517742  8b4108               mov eax, dword ptr [ecx + 8]
// 00517745  80782900             cmp byte ptr [eax + 0x29], 0
// 00517749  74f5                 je 0x517740
// 0051774b  5f                   pop edi
// 0051774c  894e04               mov dword ptr [esi + 4], ecx
// 0051774f  5e                   pop esi
// 00517750  c3                   ret 
// 00517751  8b4004               mov eax, dword ptr [eax + 4]
// 00517754  80782900             cmp byte ptr [eax + 0x29], 0
// 00517758  751b                 jne 0x517775
// 0051775a  8d9b00000000         lea ebx, [ebx]
// 00517760  8b4e04               mov ecx, dword ptr [esi + 4]
// 00517763  3b08                 cmp ecx, dword ptr [eax]
// 00517765  750e                 jne 0x517775
// 00517767  894604               mov dword ptr [esi + 4], eax
// 0051776a  8bd0                 mov edx, eax
// 0051776c  8b4204               mov eax, dword ptr [edx + 4]
// 0051776f  80782900             cmp byte ptr [eax + 0x29], 0
// 00517773  74eb                 je 0x517760
// 00517775  8b4e04               mov ecx, dword ptr [esi + 4]
// 00517778  80792900             cmp byte ptr [ecx + 0x29], 0
// 0051777c  75a8                 jne 0x517726
// 0051777e  894604               mov dword ptr [esi + 4], eax
// 00517781  5f                   pop edi
// 00517782  5e                   pop esi
// 00517783  c3                   ret 
// standard library map_int<pod24> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: map_int<pod24>
struct E { int v[6]; };
#include <map>
template class std::map<int, E>;
