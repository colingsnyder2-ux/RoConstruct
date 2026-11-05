// from server: 100% by auto
// roc 2010-06 0052d020  unit: RBX::VTextureProxyBase::?$sp_counted_impl_p  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0052d020
//
// 0052d020  56                   push esi
// 0052d021  8bf1                 mov esi, ecx
// 0052d023  833e00               cmp dword ptr [esi], 0
// 0052d026  57                   push edi
// 0052d027  8b3d0ca99e00         mov edi, dword ptr [0x9ea90c]
// 0052d02d  7502                 jne 0x52d031
// 0052d02f  ffd7                 call edi
// 0052d031  8b4604               mov eax, dword ptr [esi + 4]
// 0052d034  80782100             cmp byte ptr [eax + 0x21], 0
// 0052d038  7411                 je 0x52d04b
// 0052d03a  8b4008               mov eax, dword ptr [eax + 8]
// 0052d03d  894604               mov dword ptr [esi + 4], eax
// 0052d040  80782100             cmp byte ptr [eax + 0x21], 0
// 0052d044  745b                 je 0x52d0a1
// 0052d046  ffd7                 call edi
// 0052d048  5f                   pop edi
// 0052d049  5e                   pop esi
// 0052d04a  c3                   ret 
// 0052d04b  8b08                 mov ecx, dword ptr [eax]
// 0052d04d  80792100             cmp byte ptr [ecx + 0x21], 0
// 0052d051  751e                 jne 0x52d071
// 0052d053  8b4108               mov eax, dword ptr [ecx + 8]
// 0052d056  80782100             cmp byte ptr [eax + 0x21], 0
// 0052d05a  750f                 jne 0x52d06b
// 0052d05c  8d642400             lea esp, [esp]
// 0052d060  8bc8                 mov ecx, eax
// 0052d062  8b4108               mov eax, dword ptr [ecx + 8]
// 0052d065  80782100             cmp byte ptr [eax + 0x21], 0
// 0052d069  74f5                 je 0x52d060
// 0052d06b  5f                   pop edi
// 0052d06c  894e04               mov dword ptr [esi + 4], ecx
// 0052d06f  5e                   pop esi
// 0052d070  c3                   ret 
// 0052d071  8b4004               mov eax, dword ptr [eax + 4]
// 0052d074  80782100             cmp byte ptr [eax + 0x21], 0
// 0052d078  751b                 jne 0x52d095
// 0052d07a  8d9b00000000         lea ebx, [ebx]
// 0052d080  8b4e04               mov ecx, dword ptr [esi + 4]
// 0052d083  3b08                 cmp ecx, dword ptr [eax]
// 0052d085  750e                 jne 0x52d095
// 0052d087  894604               mov dword ptr [esi + 4], eax
// 0052d08a  8bd0                 mov edx, eax
// 0052d08c  8b4204               mov eax, dword ptr [edx + 4]
// 0052d08f  80782100             cmp byte ptr [eax + 0x21], 0
// 0052d093  74eb                 je 0x52d080
// 0052d095  8b4e04               mov ecx, dword ptr [esi + 4]
// 0052d098  80792100             cmp byte ptr [ecx + 0x21], 0
// 0052d09c  75a8                 jne 0x52d046
// 0052d09e  894604               mov dword ptr [esi + 4], eax
// 0052d0a1  5f                   pop edi
// 0052d0a2  5e                   pop esi
// 0052d0a3  c3                   ret 
// standard library map_int<double> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@HNU?$less@H@std@@V?$allocator@U?$pair@$$CBHN@std@@@2@$0A@@std@@@std@@QAEXXZ)

// stl: map_int<double>
typedef double E;
#include <map>
template class std::map<int, E>;
