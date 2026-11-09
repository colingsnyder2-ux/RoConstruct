// from server: 100% by auto
// roc 2008-06 004e6270  unit: RBX::ViewNew::PartChunk  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004e6270
//
// 004e6270  56                   push esi
// 004e6271  8bf1                 mov esi, ecx
// 004e6273  833e00               cmp dword ptr [esi], 0
// 004e6276  57                   push edi
// 004e6277  8b3d90288000         mov edi, dword ptr [0x802890]
// 004e627d  7502                 jne 0x4e6281
// 004e627f  ffd7                 call edi
// 004e6281  8b4604               mov eax, dword ptr [esi + 4]
// 004e6284  80782100             cmp byte ptr [eax + 0x21], 0
// 004e6288  7411                 je 0x4e629b
// 004e628a  8b4008               mov eax, dword ptr [eax + 8]
// 004e628d  894604               mov dword ptr [esi + 4], eax
// 004e6290  80782100             cmp byte ptr [eax + 0x21], 0
// 004e6294  745b                 je 0x4e62f1
// 004e6296  ffd7                 call edi
// 004e6298  5f                   pop edi
// 004e6299  5e                   pop esi
// 004e629a  c3                   ret 
// 004e629b  8b08                 mov ecx, dword ptr [eax]
// 004e629d  80792100             cmp byte ptr [ecx + 0x21], 0
// 004e62a1  751e                 jne 0x4e62c1
// 004e62a3  8b4108               mov eax, dword ptr [ecx + 8]
// 004e62a6  80782100             cmp byte ptr [eax + 0x21], 0
// 004e62aa  750f                 jne 0x4e62bb
// 004e62ac  8d642400             lea esp, [esp]
// 004e62b0  8bc8                 mov ecx, eax
// 004e62b2  8b4108               mov eax, dword ptr [ecx + 8]
// 004e62b5  80782100             cmp byte ptr [eax + 0x21], 0
// 004e62b9  74f5                 je 0x4e62b0
// 004e62bb  5f                   pop edi
// 004e62bc  894e04               mov dword ptr [esi + 4], ecx
// 004e62bf  5e                   pop esi
// 004e62c0  c3                   ret 
// 004e62c1  8b4004               mov eax, dword ptr [eax + 4]
// 004e62c4  80782100             cmp byte ptr [eax + 0x21], 0
// 004e62c8  751b                 jne 0x4e62e5
// 004e62ca  8d9b00000000         lea ebx, [ebx]
// 004e62d0  8b4e04               mov ecx, dword ptr [esi + 4]
// 004e62d3  3b08                 cmp ecx, dword ptr [eax]
// 004e62d5  750e                 jne 0x4e62e5
// 004e62d7  894604               mov dword ptr [esi + 4], eax
// 004e62da  8bd0                 mov edx, eax
// 004e62dc  8b4204               mov eax, dword ptr [edx + 4]
// 004e62df  80782100             cmp byte ptr [eax + 0x21], 0
// 004e62e3  74eb                 je 0x4e62d0
// 004e62e5  8b4e04               mov ecx, dword ptr [esi + 4]
// 004e62e8  80792100             cmp byte ptr [ecx + 0x21], 0
// 004e62ec  75a8                 jne 0x4e6296
// 004e62ee  894604               mov dword ptr [esi + 4], eax
// 004e62f1  5f                   pop edi
// 004e62f2  5e                   pop esi
// 004e62f3  c3                   ret 
// standard library map_int<double> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@HNU?$less@H@std@@V?$allocator@U?$pair@$$CBHN@std@@@2@$0A@@std@@@std@@QAEXXZ)

// stl: map_int<double>
typedef double E;
#include <map>
template class std::map<int, E>;
