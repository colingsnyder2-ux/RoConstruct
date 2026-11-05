// from server: 100% by auto
// roc 2009-06 0048b810  unit: Ogre::RbxManualTextureLoader  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0048b810
//
// 0048b810  56                   push esi
// 0048b811  8bf1                 mov esi, ecx
// 0048b813  833e00               cmp dword ptr [esi], 0
// 0048b816  57                   push edi
// 0048b817  8b3dace98900         mov edi, dword ptr [0x89e9ac]
// 0048b81d  7502                 jne 0x48b821
// 0048b81f  ffd7                 call edi
// 0048b821  8b4604               mov eax, dword ptr [esi + 4]
// 0048b824  80786900             cmp byte ptr [eax + 0x69], 0
// 0048b828  7411                 je 0x48b83b
// 0048b82a  8b4008               mov eax, dword ptr [eax + 8]
// 0048b82d  894604               mov dword ptr [esi + 4], eax
// 0048b830  80786900             cmp byte ptr [eax + 0x69], 0
// 0048b834  745b                 je 0x48b891
// 0048b836  ffd7                 call edi
// 0048b838  5f                   pop edi
// 0048b839  5e                   pop esi
// 0048b83a  c3                   ret 
// 0048b83b  8b08                 mov ecx, dword ptr [eax]
// 0048b83d  80796900             cmp byte ptr [ecx + 0x69], 0
// 0048b841  751e                 jne 0x48b861
// 0048b843  8b4108               mov eax, dword ptr [ecx + 8]
// 0048b846  80786900             cmp byte ptr [eax + 0x69], 0
// 0048b84a  750f                 jne 0x48b85b
// 0048b84c  8d642400             lea esp, [esp]
// 0048b850  8bc8                 mov ecx, eax
// 0048b852  8b4108               mov eax, dword ptr [ecx + 8]
// 0048b855  80786900             cmp byte ptr [eax + 0x69], 0
// 0048b859  74f5                 je 0x48b850
// 0048b85b  5f                   pop edi
// 0048b85c  894e04               mov dword ptr [esi + 4], ecx
// 0048b85f  5e                   pop esi
// 0048b860  c3                   ret 
// 0048b861  8b4004               mov eax, dword ptr [eax + 4]
// 0048b864  80786900             cmp byte ptr [eax + 0x69], 0
// 0048b868  751b                 jne 0x48b885
// 0048b86a  8d9b00000000         lea ebx, [ebx]
// 0048b870  8b4e04               mov ecx, dword ptr [esi + 4]
// 0048b873  3b08                 cmp ecx, dword ptr [eax]
// 0048b875  750e                 jne 0x48b885
// 0048b877  894604               mov dword ptr [esi + 4], eax
// 0048b87a  8bd0                 mov edx, eax
// 0048b87c  8b4204               mov eax, dword ptr [edx + 4]
// 0048b87f  80786900             cmp byte ptr [eax + 0x69], 0
// 0048b883  74eb                 je 0x48b870
// 0048b885  8b4e04               mov ecx, dword ptr [esi + 4]
// 0048b888  80796900             cmp byte ptr [ecx + 0x69], 0
// 0048b88c  75a8                 jne 0x48b836
// 0048b88e  894604               mov dword ptr [esi + 4], eax
// 0048b891  5f                   pop edi
// 0048b892  5e                   pop esi
// 0048b893  c3                   ret 
// standard library map_str<pod64> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAEXXZ)

// stl: map_str<pod64>
struct E { int v[16]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
