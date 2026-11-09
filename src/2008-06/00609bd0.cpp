// from server: 100% by auto
// roc 2008-06 00609bd0  unit: RBX::Controller::W4ControllerType::?$EnumDesc  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00609bd0
//
// 00609bd0  56                   push esi
// 00609bd1  8bf1                 mov esi, ecx
// 00609bd3  833e00               cmp dword ptr [esi], 0
// 00609bd6  57                   push edi
// 00609bd7  8b3d90288000         mov edi, dword ptr [0x802890]
// 00609bdd  7502                 jne 0x609be1
// 00609bdf  ffd7                 call edi
// 00609be1  8b4604               mov eax, dword ptr [esi + 4]
// 00609be4  80781500             cmp byte ptr [eax + 0x15], 0
// 00609be8  7411                 je 0x609bfb
// 00609bea  8b4008               mov eax, dword ptr [eax + 8]
// 00609bed  894604               mov dword ptr [esi + 4], eax
// 00609bf0  80781500             cmp byte ptr [eax + 0x15], 0
// 00609bf4  745b                 je 0x609c51
// 00609bf6  ffd7                 call edi
// 00609bf8  5f                   pop edi
// 00609bf9  5e                   pop esi
// 00609bfa  c3                   ret 
// 00609bfb  8b08                 mov ecx, dword ptr [eax]
// 00609bfd  80791500             cmp byte ptr [ecx + 0x15], 0
// 00609c01  751e                 jne 0x609c21
// 00609c03  8b4108               mov eax, dword ptr [ecx + 8]
// 00609c06  80781500             cmp byte ptr [eax + 0x15], 0
// 00609c0a  750f                 jne 0x609c1b
// 00609c0c  8d642400             lea esp, [esp]
// 00609c10  8bc8                 mov ecx, eax
// 00609c12  8b4108               mov eax, dword ptr [ecx + 8]
// 00609c15  80781500             cmp byte ptr [eax + 0x15], 0
// 00609c19  74f5                 je 0x609c10
// 00609c1b  5f                   pop edi
// 00609c1c  894e04               mov dword ptr [esi + 4], ecx
// 00609c1f  5e                   pop esi
// 00609c20  c3                   ret 
// 00609c21  8b4004               mov eax, dword ptr [eax + 4]
// 00609c24  80781500             cmp byte ptr [eax + 0x15], 0
// 00609c28  751b                 jne 0x609c45
// 00609c2a  8d9b00000000         lea ebx, [ebx]
// 00609c30  8b4e04               mov ecx, dword ptr [esi + 4]
// 00609c33  3b08                 cmp ecx, dword ptr [eax]
// 00609c35  750e                 jne 0x609c45
// 00609c37  894604               mov dword ptr [esi + 4], eax
// 00609c3a  8bd0                 mov edx, eax
// 00609c3c  8b4204               mov eax, dword ptr [edx + 4]
// 00609c3f  80781500             cmp byte ptr [eax + 0x15], 0
// 00609c43  74eb                 je 0x609c30
// 00609c45  8b4e04               mov ecx, dword ptr [esi + 4]
// 00609c48  80791500             cmp byte ptr [ecx + 0x15], 0
// 00609c4c  75a8                 jne 0x609bf6
// 00609c4e  894604               mov dword ptr [esi + 4], eax
// 00609c51  5f                   pop edi
// 00609c52  5e                   pop esi
// 00609c53  c3                   ret 
// standard library map_int<ptr> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: map_int<ptr>
struct T; typedef T* E;
#include <map>
template class std::map<int, E>;
