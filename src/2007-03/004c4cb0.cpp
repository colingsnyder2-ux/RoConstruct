// from server: 100% by auto
// roc 2007-03 004c4cb0  unit: seg_004c0000  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 004c4cb0
//
// 004c4cb0  56                   push esi
// 004c4cb1  8bf1                 mov esi, ecx
// 004c4cb3  833e00               cmp dword ptr [esi], 0
// 004c4cb6  57                   push edi
// 004c4cb7  8b3d44e97700         mov edi, dword ptr [0x77e944]
// 004c4cbd  7502                 jne 0x4c4cc1
// 004c4cbf  ffd7                 call edi
// 004c4cc1  8b4604               mov eax, dword ptr [esi + 4]
// 004c4cc4  80782100             cmp byte ptr [eax + 0x21], 0
// 004c4cc8  7411                 je 0x4c4cdb
// 004c4cca  8b4008               mov eax, dword ptr [eax + 8]
// 004c4ccd  894604               mov dword ptr [esi + 4], eax
// 004c4cd0  80782100             cmp byte ptr [eax + 0x21], 0
// 004c4cd4  745b                 je 0x4c4d31
// 004c4cd6  ffd7                 call edi
// 004c4cd8  5f                   pop edi
// 004c4cd9  5e                   pop esi
// 004c4cda  c3                   ret 
// 004c4cdb  8b08                 mov ecx, dword ptr [eax]
// 004c4cdd  80792100             cmp byte ptr [ecx + 0x21], 0
// 004c4ce1  751e                 jne 0x4c4d01
// 004c4ce3  8b4108               mov eax, dword ptr [ecx + 8]
// 004c4ce6  80782100             cmp byte ptr [eax + 0x21], 0
// 004c4cea  750f                 jne 0x4c4cfb
// 004c4cec  8d642400             lea esp, [esp]
// 004c4cf0  8bc8                 mov ecx, eax
// 004c4cf2  8b4108               mov eax, dword ptr [ecx + 8]
// 004c4cf5  80782100             cmp byte ptr [eax + 0x21], 0
// 004c4cf9  74f5                 je 0x4c4cf0
// 004c4cfb  5f                   pop edi
// 004c4cfc  894e04               mov dword ptr [esi + 4], ecx
// 004c4cff  5e                   pop esi
// 004c4d00  c3                   ret 
// 004c4d01  8b4004               mov eax, dword ptr [eax + 4]
// 004c4d04  80782100             cmp byte ptr [eax + 0x21], 0
// 004c4d08  751b                 jne 0x4c4d25
// 004c4d0a  8d9b00000000         lea ebx, [ebx]
// 004c4d10  8b4e04               mov ecx, dword ptr [esi + 4]
// 004c4d13  3b08                 cmp ecx, dword ptr [eax]
// 004c4d15  750e                 jne 0x4c4d25
// 004c4d17  894604               mov dword ptr [esi + 4], eax
// 004c4d1a  8bd0                 mov edx, eax
// 004c4d1c  8b4204               mov eax, dword ptr [edx + 4]
// 004c4d1f  80782100             cmp byte ptr [eax + 0x21], 0
// 004c4d23  74eb                 je 0x4c4d10
// 004c4d25  8b4e04               mov ecx, dword ptr [esi + 4]
// 004c4d28  80792100             cmp byte ptr [ecx + 0x21], 0
// 004c4d2c  75a8                 jne 0x4c4cd6
// 004c4d2e  894604               mov dword ptr [esi + 4], eax
// 004c4d31  5f                   pop edi
// 004c4d32  5e                   pop esi
// 004c4d33  c3                   ret 
// standard library map_int<double> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@HNU?$less@H@std@@V?$allocator@U?$pair@$$CBHN@std@@@2@$0A@@std@@@std@@QAEXXZ)

// stl: map_int<double>
typedef double E;
#include <map>
template class std::map<int, E>;
