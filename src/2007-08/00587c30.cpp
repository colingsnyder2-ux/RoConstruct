// from server: 100% by auto
// roc 2007-08 00587c30  unit: RBX::Reflection::EnumDescriptor  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00587c30
//
// 00587c30  56                   push esi
// 00587c31  8bf1                 mov esi, ecx
// 00587c33  833e00               cmp dword ptr [esi], 0
// 00587c36  57                   push edi
// 00587c37  8b3dd8e67700         mov edi, dword ptr [0x77e6d8]
// 00587c3d  7502                 jne 0x587c41
// 00587c3f  ffd7                 call edi
// 00587c41  8b4604               mov eax, dword ptr [esi + 4]
// 00587c44  80781900             cmp byte ptr [eax + 0x19], 0
// 00587c48  7411                 je 0x587c5b
// 00587c4a  8b4008               mov eax, dword ptr [eax + 8]
// 00587c4d  894604               mov dword ptr [esi + 4], eax
// 00587c50  80781900             cmp byte ptr [eax + 0x19], 0
// 00587c54  745b                 je 0x587cb1
// 00587c56  ffd7                 call edi
// 00587c58  5f                   pop edi
// 00587c59  5e                   pop esi
// 00587c5a  c3                   ret 
// 00587c5b  8b08                 mov ecx, dword ptr [eax]
// 00587c5d  80791900             cmp byte ptr [ecx + 0x19], 0
// 00587c61  751e                 jne 0x587c81
// 00587c63  8b4108               mov eax, dword ptr [ecx + 8]
// 00587c66  80781900             cmp byte ptr [eax + 0x19], 0
// 00587c6a  750f                 jne 0x587c7b
// 00587c6c  8d642400             lea esp, [esp]
// 00587c70  8bc8                 mov ecx, eax
// 00587c72  8b4108               mov eax, dword ptr [ecx + 8]
// 00587c75  80781900             cmp byte ptr [eax + 0x19], 0
// 00587c79  74f5                 je 0x587c70
// 00587c7b  5f                   pop edi
// 00587c7c  894e04               mov dword ptr [esi + 4], ecx
// 00587c7f  5e                   pop esi
// 00587c80  c3                   ret 
// 00587c81  8b4004               mov eax, dword ptr [eax + 4]
// 00587c84  80781900             cmp byte ptr [eax + 0x19], 0
// 00587c88  751b                 jne 0x587ca5
// 00587c8a  8d9b00000000         lea ebx, [ebx]
// 00587c90  8b4e04               mov ecx, dword ptr [esi + 4]
// 00587c93  3b08                 cmp ecx, dword ptr [eax]
// 00587c95  750e                 jne 0x587ca5
// 00587c97  894604               mov dword ptr [esi + 4], eax
// 00587c9a  8bd0                 mov edx, eax
// 00587c9c  8b4204               mov eax, dword ptr [edx + 4]
// 00587c9f  80781900             cmp byte ptr [eax + 0x19], 0
// 00587ca3  74eb                 je 0x587c90
// 00587ca5  8b4e04               mov ecx, dword ptr [esi + 4]
// 00587ca8  80791900             cmp byte ptr [ecx + 0x19], 0
// 00587cac  75a8                 jne 0x587c56
// 00587cae  894604               mov dword ptr [esi + 4], eax
// 00587cb1  5f                   pop edi
// 00587cb2  5e                   pop esi
// 00587cb3  c3                   ret 
// standard library map_int<pod8> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: map_int<pod8>
struct E { int v[2]; };
#include <map>
template class std::map<int, E>;
