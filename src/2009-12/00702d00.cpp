// from server: 100% by auto
// roc 2009-12 00702d00  unit: RBX::Assembly  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00702d00
//
// 00702d00  56                   push esi
// 00702d01  8bf1                 mov esi, ecx
// 00702d03  833e00               cmp dword ptr [esi], 0
// 00702d06  57                   push edi
// 00702d07  8b3d60b79800         mov edi, dword ptr [0x98b760]
// 00702d0d  7502                 jne 0x702d11
// 00702d0f  ffd7                 call edi
// 00702d11  8b4604               mov eax, dword ptr [esi + 4]
// 00702d14  80785100             cmp byte ptr [eax + 0x51], 0
// 00702d18  7411                 je 0x702d2b
// 00702d1a  8b4008               mov eax, dword ptr [eax + 8]
// 00702d1d  894604               mov dword ptr [esi + 4], eax
// 00702d20  80785100             cmp byte ptr [eax + 0x51], 0
// 00702d24  745b                 je 0x702d81
// 00702d26  ffd7                 call edi
// 00702d28  5f                   pop edi
// 00702d29  5e                   pop esi
// 00702d2a  c3                   ret 
// 00702d2b  8b08                 mov ecx, dword ptr [eax]
// 00702d2d  80795100             cmp byte ptr [ecx + 0x51], 0
// 00702d31  751e                 jne 0x702d51
// 00702d33  8b4108               mov eax, dword ptr [ecx + 8]
// 00702d36  80785100             cmp byte ptr [eax + 0x51], 0
// 00702d3a  750f                 jne 0x702d4b
// 00702d3c  8d642400             lea esp, [esp]
// 00702d40  8bc8                 mov ecx, eax
// 00702d42  8b4108               mov eax, dword ptr [ecx + 8]
// 00702d45  80785100             cmp byte ptr [eax + 0x51], 0
// 00702d49  74f5                 je 0x702d40
// 00702d4b  5f                   pop edi
// 00702d4c  894e04               mov dword ptr [esi + 4], ecx
// 00702d4f  5e                   pop esi
// 00702d50  c3                   ret 
// 00702d51  8b4004               mov eax, dword ptr [eax + 4]
// 00702d54  80785100             cmp byte ptr [eax + 0x51], 0
// 00702d58  751b                 jne 0x702d75
// 00702d5a  8d9b00000000         lea ebx, [ebx]
// 00702d60  8b4e04               mov ecx, dword ptr [esi + 4]
// 00702d63  3b08                 cmp ecx, dword ptr [eax]
// 00702d65  750e                 jne 0x702d75
// 00702d67  894604               mov dword ptr [esi + 4], eax
// 00702d6a  8bd0                 mov edx, eax
// 00702d6c  8b4204               mov eax, dword ptr [edx + 4]
// 00702d6f  80785100             cmp byte ptr [eax + 0x51], 0
// 00702d73  74eb                 je 0x702d60
// 00702d75  8b4e04               mov ecx, dword ptr [esi + 4]
// 00702d78  80795100             cmp byte ptr [ecx + 0x51], 0
// 00702d7c  75a8                 jne 0x702d26
// 00702d7e  894604               mov dword ptr [esi + 4], eax
// 00702d81  5f                   pop edi
// 00702d82  5e                   pop esi
// 00702d83  c3                   ret 
// standard library map_int<pod64> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: map_int<pod64>
struct E { int v[16]; };
#include <map>
template class std::map<int, E>;
