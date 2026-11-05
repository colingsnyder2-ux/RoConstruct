// from server: 100% by auto
// roc 2007-08 004a03b0  unit: RBX::Network::VServer::?$BoundFuncDesc  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004a03b0
//
// 004a03b0  56                   push esi
// 004a03b1  8bf1                 mov esi, ecx
// 004a03b3  833e00               cmp dword ptr [esi], 0
// 004a03b6  57                   push edi
// 004a03b7  8b3dd8e67700         mov edi, dword ptr [0x77e6d8]
// 004a03bd  7502                 jne 0x4a03c1
// 004a03bf  ffd7                 call edi
// 004a03c1  8b4604               mov eax, dword ptr [esi + 4]
// 004a03c4  80782100             cmp byte ptr [eax + 0x21], 0
// 004a03c8  7411                 je 0x4a03db
// 004a03ca  8b4008               mov eax, dword ptr [eax + 8]
// 004a03cd  894604               mov dword ptr [esi + 4], eax
// 004a03d0  80782100             cmp byte ptr [eax + 0x21], 0
// 004a03d4  745b                 je 0x4a0431
// 004a03d6  ffd7                 call edi
// 004a03d8  5f                   pop edi
// 004a03d9  5e                   pop esi
// 004a03da  c3                   ret 
// 004a03db  8b08                 mov ecx, dword ptr [eax]
// 004a03dd  80792100             cmp byte ptr [ecx + 0x21], 0
// 004a03e1  751e                 jne 0x4a0401
// 004a03e3  8b4108               mov eax, dword ptr [ecx + 8]
// 004a03e6  80782100             cmp byte ptr [eax + 0x21], 0
// 004a03ea  750f                 jne 0x4a03fb
// 004a03ec  8d642400             lea esp, [esp]
// 004a03f0  8bc8                 mov ecx, eax
// 004a03f2  8b4108               mov eax, dword ptr [ecx + 8]
// 004a03f5  80782100             cmp byte ptr [eax + 0x21], 0
// 004a03f9  74f5                 je 0x4a03f0
// 004a03fb  5f                   pop edi
// 004a03fc  894e04               mov dword ptr [esi + 4], ecx
// 004a03ff  5e                   pop esi
// 004a0400  c3                   ret 
// 004a0401  8b4004               mov eax, dword ptr [eax + 4]
// 004a0404  80782100             cmp byte ptr [eax + 0x21], 0
// 004a0408  751b                 jne 0x4a0425
// 004a040a  8d9b00000000         lea ebx, [ebx]
// 004a0410  8b4e04               mov ecx, dword ptr [esi + 4]
// 004a0413  3b08                 cmp ecx, dword ptr [eax]
// 004a0415  750e                 jne 0x4a0425
// 004a0417  894604               mov dword ptr [esi + 4], eax
// 004a041a  8bd0                 mov edx, eax
// 004a041c  8b4204               mov eax, dword ptr [edx + 4]
// 004a041f  80782100             cmp byte ptr [eax + 0x21], 0
// 004a0423  74eb                 je 0x4a0410
// 004a0425  8b4e04               mov ecx, dword ptr [esi + 4]
// 004a0428  80792100             cmp byte ptr [ecx + 0x21], 0
// 004a042c  75a8                 jne 0x4a03d6
// 004a042e  894604               mov dword ptr [esi + 4], eax
// 004a0431  5f                   pop edi
// 004a0432  5e                   pop esi
// 004a0433  c3                   ret 
// standard library map_int<double> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@HNU?$less@H@std@@V?$allocator@U?$pair@$$CBHN@std@@@2@$0A@@std@@@std@@QAEXXZ)

// stl: map_int<double>
typedef double E;
#include <map>
template class std::map<int, E>;
