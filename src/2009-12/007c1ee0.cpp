// from server: 100% by auto
// roc 2009-12 007c1ee0  unit: RBX::ImageButton  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007c1ee0
//
// 007c1ee0  56                   push esi
// 007c1ee1  8bf1                 mov esi, ecx
// 007c1ee3  833e00               cmp dword ptr [esi], 0
// 007c1ee6  57                   push edi
// 007c1ee7  8b3d60b79800         mov edi, dword ptr [0x98b760]
// 007c1eed  7502                 jne 0x7c1ef1
// 007c1eef  ffd7                 call edi
// 007c1ef1  8b4604               mov eax, dword ptr [esi + 4]
// 007c1ef4  80784d00             cmp byte ptr [eax + 0x4d], 0
// 007c1ef8  7411                 je 0x7c1f0b
// 007c1efa  8b4008               mov eax, dword ptr [eax + 8]
// 007c1efd  894604               mov dword ptr [esi + 4], eax
// 007c1f00  80784d00             cmp byte ptr [eax + 0x4d], 0
// 007c1f04  745b                 je 0x7c1f61
// 007c1f06  ffd7                 call edi
// 007c1f08  5f                   pop edi
// 007c1f09  5e                   pop esi
// 007c1f0a  c3                   ret 
// 007c1f0b  8b08                 mov ecx, dword ptr [eax]
// 007c1f0d  80794d00             cmp byte ptr [ecx + 0x4d], 0
// 007c1f11  751e                 jne 0x7c1f31
// 007c1f13  8b4108               mov eax, dword ptr [ecx + 8]
// 007c1f16  80784d00             cmp byte ptr [eax + 0x4d], 0
// 007c1f1a  750f                 jne 0x7c1f2b
// 007c1f1c  8d642400             lea esp, [esp]
// 007c1f20  8bc8                 mov ecx, eax
// 007c1f22  8b4108               mov eax, dword ptr [ecx + 8]
// 007c1f25  80784d00             cmp byte ptr [eax + 0x4d], 0
// 007c1f29  74f5                 je 0x7c1f20
// 007c1f2b  5f                   pop edi
// 007c1f2c  894e04               mov dword ptr [esi + 4], ecx
// 007c1f2f  5e                   pop esi
// 007c1f30  c3                   ret 
// 007c1f31  8b4004               mov eax, dword ptr [eax + 4]
// 007c1f34  80784d00             cmp byte ptr [eax + 0x4d], 0
// 007c1f38  751b                 jne 0x7c1f55
// 007c1f3a  8d9b00000000         lea ebx, [ebx]
// 007c1f40  8b4e04               mov ecx, dword ptr [esi + 4]
// 007c1f43  3b08                 cmp ecx, dword ptr [eax]
// 007c1f45  750e                 jne 0x7c1f55
// 007c1f47  894604               mov dword ptr [esi + 4], eax
// 007c1f4a  8bd0                 mov edx, eax
// 007c1f4c  8b4204               mov eax, dword ptr [edx + 4]
// 007c1f4f  80784d00             cmp byte ptr [eax + 0x4d], 0
// 007c1f53  74eb                 je 0x7c1f40
// 007c1f55  8b4e04               mov ecx, dword ptr [esi + 4]
// 007c1f58  80794d00             cmp byte ptr [ecx + 0x4d], 0
// 007c1f5c  75a8                 jne 0x7c1f06
// 007c1f5e  894604               mov dword ptr [esi + 4], eax
// 007c1f61  5f                   pop edi
// 007c1f62  5e                   pop esi
// 007c1f63  c3                   ret 
// standard library map_str<pod36> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAEXXZ)

// stl: map_str<pod36>
struct E { int v[9]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
