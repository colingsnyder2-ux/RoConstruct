// from server: 100% by auto
// roc 2010-06 008c6d60  unit: Ogre::VRbxFont::?$SharedPtr  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008c6d60
//
// 008c6d60  56                   push esi
// 008c6d61  8bf1                 mov esi, ecx
// 008c6d63  833e00               cmp dword ptr [esi], 0
// 008c6d66  57                   push edi
// 008c6d67  8b3d0ca99e00         mov edi, dword ptr [0x9ea90c]
// 008c6d6d  7502                 jne 0x8c6d71
// 008c6d6f  ffd7                 call edi
// 008c6d71  8b4604               mov eax, dword ptr [esi + 4]
// 008c6d74  80783900             cmp byte ptr [eax + 0x39], 0
// 008c6d78  7411                 je 0x8c6d8b
// 008c6d7a  8b4008               mov eax, dword ptr [eax + 8]
// 008c6d7d  894604               mov dword ptr [esi + 4], eax
// 008c6d80  80783900             cmp byte ptr [eax + 0x39], 0
// 008c6d84  745b                 je 0x8c6de1
// 008c6d86  ffd7                 call edi
// 008c6d88  5f                   pop edi
// 008c6d89  5e                   pop esi
// 008c6d8a  c3                   ret 
// 008c6d8b  8b08                 mov ecx, dword ptr [eax]
// 008c6d8d  80793900             cmp byte ptr [ecx + 0x39], 0
// 008c6d91  751e                 jne 0x8c6db1
// 008c6d93  8b4108               mov eax, dword ptr [ecx + 8]
// 008c6d96  80783900             cmp byte ptr [eax + 0x39], 0
// 008c6d9a  750f                 jne 0x8c6dab
// 008c6d9c  8d642400             lea esp, [esp]
// 008c6da0  8bc8                 mov ecx, eax
// 008c6da2  8b4108               mov eax, dword ptr [ecx + 8]
// 008c6da5  80783900             cmp byte ptr [eax + 0x39], 0
// 008c6da9  74f5                 je 0x8c6da0
// 008c6dab  5f                   pop edi
// 008c6dac  894e04               mov dword ptr [esi + 4], ecx
// 008c6daf  5e                   pop esi
// 008c6db0  c3                   ret 
// 008c6db1  8b4004               mov eax, dword ptr [eax + 4]
// 008c6db4  80783900             cmp byte ptr [eax + 0x39], 0
// 008c6db8  751b                 jne 0x8c6dd5
// 008c6dba  8d9b00000000         lea ebx, [ebx]
// 008c6dc0  8b4e04               mov ecx, dword ptr [esi + 4]
// 008c6dc3  3b08                 cmp ecx, dword ptr [eax]
// 008c6dc5  750e                 jne 0x8c6dd5
// 008c6dc7  894604               mov dword ptr [esi + 4], eax
// 008c6dca  8bd0                 mov edx, eax
// 008c6dcc  8b4204               mov eax, dword ptr [edx + 4]
// 008c6dcf  80783900             cmp byte ptr [eax + 0x39], 0
// 008c6dd3  74eb                 je 0x8c6dc0
// 008c6dd5  8b4e04               mov ecx, dword ptr [esi + 4]
// 008c6dd8  80793900             cmp byte ptr [ecx + 0x39], 0
// 008c6ddc  75a8                 jne 0x8c6d86
// 008c6dde  894604               mov dword ptr [esi + 4], eax
// 008c6de1  5f                   pop edi
// 008c6de2  5e                   pop esi
// 008c6de3  c3                   ret 
// standard library map_int<pod40> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: map_int<pod40>
struct E { int v[10]; };
#include <map>
template class std::map<int, E>;
