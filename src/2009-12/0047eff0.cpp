// from server: 100% by auto
// roc 2009-12 0047eff0  unit: Ogre::VRbxFont::?$SharedPtr  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0047eff0
//
// 0047eff0  56                   push esi
// 0047eff1  8bf1                 mov esi, ecx
// 0047eff3  833e00               cmp dword ptr [esi], 0
// 0047eff6  57                   push edi
// 0047eff7  8b3d60b79800         mov edi, dword ptr [0x98b760]
// 0047effd  7502                 jne 0x47f001
// 0047efff  ffd7                 call edi
// 0047f001  8b4604               mov eax, dword ptr [esi + 4]
// 0047f004  80783900             cmp byte ptr [eax + 0x39], 0
// 0047f008  7411                 je 0x47f01b
// 0047f00a  8b4008               mov eax, dword ptr [eax + 8]
// 0047f00d  894604               mov dword ptr [esi + 4], eax
// 0047f010  80783900             cmp byte ptr [eax + 0x39], 0
// 0047f014  745b                 je 0x47f071
// 0047f016  ffd7                 call edi
// 0047f018  5f                   pop edi
// 0047f019  5e                   pop esi
// 0047f01a  c3                   ret 
// 0047f01b  8b08                 mov ecx, dword ptr [eax]
// 0047f01d  80793900             cmp byte ptr [ecx + 0x39], 0
// 0047f021  751e                 jne 0x47f041
// 0047f023  8b4108               mov eax, dword ptr [ecx + 8]
// 0047f026  80783900             cmp byte ptr [eax + 0x39], 0
// 0047f02a  750f                 jne 0x47f03b
// 0047f02c  8d642400             lea esp, [esp]
// 0047f030  8bc8                 mov ecx, eax
// 0047f032  8b4108               mov eax, dword ptr [ecx + 8]
// 0047f035  80783900             cmp byte ptr [eax + 0x39], 0
// 0047f039  74f5                 je 0x47f030
// 0047f03b  5f                   pop edi
// 0047f03c  894e04               mov dword ptr [esi + 4], ecx
// 0047f03f  5e                   pop esi
// 0047f040  c3                   ret 
// 0047f041  8b4004               mov eax, dword ptr [eax + 4]
// 0047f044  80783900             cmp byte ptr [eax + 0x39], 0
// 0047f048  751b                 jne 0x47f065
// 0047f04a  8d9b00000000         lea ebx, [ebx]
// 0047f050  8b4e04               mov ecx, dword ptr [esi + 4]
// 0047f053  3b08                 cmp ecx, dword ptr [eax]
// 0047f055  750e                 jne 0x47f065
// 0047f057  894604               mov dword ptr [esi + 4], eax
// 0047f05a  8bd0                 mov edx, eax
// 0047f05c  8b4204               mov eax, dword ptr [edx + 4]
// 0047f05f  80783900             cmp byte ptr [eax + 0x39], 0
// 0047f063  74eb                 je 0x47f050
// 0047f065  8b4e04               mov ecx, dword ptr [esi + 4]
// 0047f068  80793900             cmp byte ptr [ecx + 0x39], 0
// 0047f06c  75a8                 jne 0x47f016
// 0047f06e  894604               mov dword ptr [esi + 4], eax
// 0047f071  5f                   pop edi
// 0047f072  5e                   pop esi
// 0047f073  c3                   ret 
// standard library map_int<pod40> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: map_int<pod40>
struct E { int v[10]; };
#include <map>
template class std::map<int, E>;
