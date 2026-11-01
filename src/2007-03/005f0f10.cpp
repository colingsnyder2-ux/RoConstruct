// from server: 100% by auto
// roc 2007-03 005f0f10  unit: seg_005f0000  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005f0f10
//
// 005f0f10  56                   push esi
// 005f0f11  8bf1                 mov esi, ecx
// 005f0f13  833e00               cmp dword ptr [esi], 0
// 005f0f16  57                   push edi
// 005f0f17  8b3d44e97700         mov edi, dword ptr [0x77e944]
// 005f0f1d  7502                 jne 0x5f0f21
// 005f0f1f  ffd7                 call edi
// 005f0f21  8b4604               mov eax, dword ptr [esi + 4]
// 005f0f24  80781900             cmp byte ptr [eax + 0x19], 0
// 005f0f28  7411                 je 0x5f0f3b
// 005f0f2a  8b4008               mov eax, dword ptr [eax + 8]
// 005f0f2d  894604               mov dword ptr [esi + 4], eax
// 005f0f30  80781900             cmp byte ptr [eax + 0x19], 0
// 005f0f34  745b                 je 0x5f0f91
// 005f0f36  ffd7                 call edi
// 005f0f38  5f                   pop edi
// 005f0f39  5e                   pop esi
// 005f0f3a  c3                   ret 
// 005f0f3b  8b08                 mov ecx, dword ptr [eax]
// 005f0f3d  80791900             cmp byte ptr [ecx + 0x19], 0
// 005f0f41  751e                 jne 0x5f0f61
// 005f0f43  8b4108               mov eax, dword ptr [ecx + 8]
// 005f0f46  80781900             cmp byte ptr [eax + 0x19], 0
// 005f0f4a  750f                 jne 0x5f0f5b
// 005f0f4c  8d642400             lea esp, [esp]
// 005f0f50  8bc8                 mov ecx, eax
// 005f0f52  8b4108               mov eax, dword ptr [ecx + 8]
// 005f0f55  80781900             cmp byte ptr [eax + 0x19], 0
// 005f0f59  74f5                 je 0x5f0f50
// 005f0f5b  5f                   pop edi
// 005f0f5c  894e04               mov dword ptr [esi + 4], ecx
// 005f0f5f  5e                   pop esi
// 005f0f60  c3                   ret 
// 005f0f61  8b4004               mov eax, dword ptr [eax + 4]
// 005f0f64  80781900             cmp byte ptr [eax + 0x19], 0
// 005f0f68  751b                 jne 0x5f0f85
// 005f0f6a  8d9b00000000         lea ebx, [ebx]
// 005f0f70  8b4e04               mov ecx, dword ptr [esi + 4]
// 005f0f73  3b08                 cmp ecx, dword ptr [eax]
// 005f0f75  750e                 jne 0x5f0f85
// 005f0f77  894604               mov dword ptr [esi + 4], eax
// 005f0f7a  8bd0                 mov edx, eax
// 005f0f7c  8b4204               mov eax, dword ptr [edx + 4]
// 005f0f7f  80781900             cmp byte ptr [eax + 0x19], 0
// 005f0f83  74eb                 je 0x5f0f70
// 005f0f85  8b4e04               mov ecx, dword ptr [esi + 4]
// 005f0f88  80791900             cmp byte ptr [ecx + 0x19], 0
// 005f0f8c  75a8                 jne 0x5f0f36
// 005f0f8e  894604               mov dword ptr [esi + 4], eax
// 005f0f91  5f                   pop edi
// 005f0f92  5e                   pop esi
// 005f0f93  c3                   ret 
// standard library map_int<pod8> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: map_int<pod8>
struct E { int v[2]; };
#include <map>
template class std::map<int, E>;
