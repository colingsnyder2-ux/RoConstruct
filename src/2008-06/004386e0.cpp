// from server: 100% by auto
// roc 2008-06 004386e0  unit: RBX::Soundscape::VSoundId::?$XItem  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004386e0
//
// 004386e0  56                   push esi
// 004386e1  8bf1                 mov esi, ecx
// 004386e3  833e00               cmp dword ptr [esi], 0
// 004386e6  57                   push edi
// 004386e7  8b3d90288000         mov edi, dword ptr [0x802890]
// 004386ed  7502                 jne 0x4386f1
// 004386ef  ffd7                 call edi
// 004386f1  8b4604               mov eax, dword ptr [esi + 4]
// 004386f4  80782900             cmp byte ptr [eax + 0x29], 0
// 004386f8  7411                 je 0x43870b
// 004386fa  8b4008               mov eax, dword ptr [eax + 8]
// 004386fd  894604               mov dword ptr [esi + 4], eax
// 00438700  80782900             cmp byte ptr [eax + 0x29], 0
// 00438704  745b                 je 0x438761
// 00438706  ffd7                 call edi
// 00438708  5f                   pop edi
// 00438709  5e                   pop esi
// 0043870a  c3                   ret 
// 0043870b  8b08                 mov ecx, dword ptr [eax]
// 0043870d  80792900             cmp byte ptr [ecx + 0x29], 0
// 00438711  751e                 jne 0x438731
// 00438713  8b4108               mov eax, dword ptr [ecx + 8]
// 00438716  80782900             cmp byte ptr [eax + 0x29], 0
// 0043871a  750f                 jne 0x43872b
// 0043871c  8d642400             lea esp, [esp]
// 00438720  8bc8                 mov ecx, eax
// 00438722  8b4108               mov eax, dword ptr [ecx + 8]
// 00438725  80782900             cmp byte ptr [eax + 0x29], 0
// 00438729  74f5                 je 0x438720
// 0043872b  5f                   pop edi
// 0043872c  894e04               mov dword ptr [esi + 4], ecx
// 0043872f  5e                   pop esi
// 00438730  c3                   ret 
// 00438731  8b4004               mov eax, dword ptr [eax + 4]
// 00438734  80782900             cmp byte ptr [eax + 0x29], 0
// 00438738  751b                 jne 0x438755
// 0043873a  8d9b00000000         lea ebx, [ebx]
// 00438740  8b4e04               mov ecx, dword ptr [esi + 4]
// 00438743  3b08                 cmp ecx, dword ptr [eax]
// 00438745  750e                 jne 0x438755
// 00438747  894604               mov dword ptr [esi + 4], eax
// 0043874a  8bd0                 mov edx, eax
// 0043874c  8b4204               mov eax, dword ptr [edx + 4]
// 0043874f  80782900             cmp byte ptr [eax + 0x29], 0
// 00438753  74eb                 je 0x438740
// 00438755  8b4e04               mov ecx, dword ptr [esi + 4]
// 00438758  80792900             cmp byte ptr [ecx + 0x29], 0
// 0043875c  75a8                 jne 0x438706
// 0043875e  894604               mov dword ptr [esi + 4], eax
// 00438761  5f                   pop edi
// 00438762  5e                   pop esi
// 00438763  c3                   ret 
// standard library map_int<pod24> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: map_int<pod24>
struct E { int v[6]; };
#include <map>
template class std::map<int, E>;
