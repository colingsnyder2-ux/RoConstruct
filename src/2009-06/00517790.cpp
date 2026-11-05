// from server: 100% by auto
// roc 2009-06 00517790  unit: RBX::VMaterialBase::?$WeakReferenceCountedPointer  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00517790
//
// 00517790  56                   push esi
// 00517791  8bf1                 mov esi, ecx
// 00517793  833e00               cmp dword ptr [esi], 0
// 00517796  57                   push edi
// 00517797  8b3dace98900         mov edi, dword ptr [0x89e9ac]
// 0051779d  7502                 jne 0x5177a1
// 0051779f  ffd7                 call edi
// 005177a1  8b4604               mov eax, dword ptr [esi + 4]
// 005177a4  80782100             cmp byte ptr [eax + 0x21], 0
// 005177a8  7411                 je 0x5177bb
// 005177aa  8b4008               mov eax, dword ptr [eax + 8]
// 005177ad  894604               mov dword ptr [esi + 4], eax
// 005177b0  80782100             cmp byte ptr [eax + 0x21], 0
// 005177b4  745b                 je 0x517811
// 005177b6  ffd7                 call edi
// 005177b8  5f                   pop edi
// 005177b9  5e                   pop esi
// 005177ba  c3                   ret 
// 005177bb  8b08                 mov ecx, dword ptr [eax]
// 005177bd  80792100             cmp byte ptr [ecx + 0x21], 0
// 005177c1  751e                 jne 0x5177e1
// 005177c3  8b4108               mov eax, dword ptr [ecx + 8]
// 005177c6  80782100             cmp byte ptr [eax + 0x21], 0
// 005177ca  750f                 jne 0x5177db
// 005177cc  8d642400             lea esp, [esp]
// 005177d0  8bc8                 mov ecx, eax
// 005177d2  8b4108               mov eax, dword ptr [ecx + 8]
// 005177d5  80782100             cmp byte ptr [eax + 0x21], 0
// 005177d9  74f5                 je 0x5177d0
// 005177db  5f                   pop edi
// 005177dc  894e04               mov dword ptr [esi + 4], ecx
// 005177df  5e                   pop esi
// 005177e0  c3                   ret 
// 005177e1  8b4004               mov eax, dword ptr [eax + 4]
// 005177e4  80782100             cmp byte ptr [eax + 0x21], 0
// 005177e8  751b                 jne 0x517805
// 005177ea  8d9b00000000         lea ebx, [ebx]
// 005177f0  8b4e04               mov ecx, dword ptr [esi + 4]
// 005177f3  3b08                 cmp ecx, dword ptr [eax]
// 005177f5  750e                 jne 0x517805
// 005177f7  894604               mov dword ptr [esi + 4], eax
// 005177fa  8bd0                 mov edx, eax
// 005177fc  8b4204               mov eax, dword ptr [edx + 4]
// 005177ff  80782100             cmp byte ptr [eax + 0x21], 0
// 00517803  74eb                 je 0x5177f0
// 00517805  8b4e04               mov ecx, dword ptr [esi + 4]
// 00517808  80792100             cmp byte ptr [ecx + 0x21], 0
// 0051780c  75a8                 jne 0x5177b6
// 0051780e  894604               mov dword ptr [esi + 4], eax
// 00517811  5f                   pop edi
// 00517812  5e                   pop esi
// 00517813  c3                   ret 
// standard library map_int<double> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@HNU?$less@H@std@@V?$allocator@U?$pair@$$CBHN@std@@@2@$0A@@std@@@std@@QAEXXZ)

// stl: map_int<double>
typedef double E;
#include <map>
template class std::map<int, E>;
