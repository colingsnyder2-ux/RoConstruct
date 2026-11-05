// from server: 100% by auto
// roc 2009-06 00475f40  unit: Ogre::RbxMeshLoader  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00475f40
//
// 00475f40  56                   push esi
// 00475f41  8bf1                 mov esi, ecx
// 00475f43  833e00               cmp dword ptr [esi], 0
// 00475f46  57                   push edi
// 00475f47  8b3dace98900         mov edi, dword ptr [0x89e9ac]
// 00475f4d  7502                 jne 0x475f51
// 00475f4f  ffd7                 call edi
// 00475f51  8b4604               mov eax, dword ptr [esi + 4]
// 00475f54  80784500             cmp byte ptr [eax + 0x45], 0
// 00475f58  7411                 je 0x475f6b
// 00475f5a  8b4008               mov eax, dword ptr [eax + 8]
// 00475f5d  894604               mov dword ptr [esi + 4], eax
// 00475f60  80784500             cmp byte ptr [eax + 0x45], 0
// 00475f64  745b                 je 0x475fc1
// 00475f66  ffd7                 call edi
// 00475f68  5f                   pop edi
// 00475f69  5e                   pop esi
// 00475f6a  c3                   ret 
// 00475f6b  8b08                 mov ecx, dword ptr [eax]
// 00475f6d  80794500             cmp byte ptr [ecx + 0x45], 0
// 00475f71  751e                 jne 0x475f91
// 00475f73  8b4108               mov eax, dword ptr [ecx + 8]
// 00475f76  80784500             cmp byte ptr [eax + 0x45], 0
// 00475f7a  750f                 jne 0x475f8b
// 00475f7c  8d642400             lea esp, [esp]
// 00475f80  8bc8                 mov ecx, eax
// 00475f82  8b4108               mov eax, dword ptr [ecx + 8]
// 00475f85  80784500             cmp byte ptr [eax + 0x45], 0
// 00475f89  74f5                 je 0x475f80
// 00475f8b  5f                   pop edi
// 00475f8c  894e04               mov dword ptr [esi + 4], ecx
// 00475f8f  5e                   pop esi
// 00475f90  c3                   ret 
// 00475f91  8b4004               mov eax, dword ptr [eax + 4]
// 00475f94  80784500             cmp byte ptr [eax + 0x45], 0
// 00475f98  751b                 jne 0x475fb5
// 00475f9a  8d9b00000000         lea ebx, [ebx]
// 00475fa0  8b4e04               mov ecx, dword ptr [esi + 4]
// 00475fa3  3b08                 cmp ecx, dword ptr [eax]
// 00475fa5  750e                 jne 0x475fb5
// 00475fa7  894604               mov dword ptr [esi + 4], eax
// 00475faa  8bd0                 mov edx, eax
// 00475fac  8b4204               mov eax, dword ptr [edx + 4]
// 00475faf  80784500             cmp byte ptr [eax + 0x45], 0
// 00475fb3  74eb                 je 0x475fa0
// 00475fb5  8b4e04               mov ecx, dword ptr [esi + 4]
// 00475fb8  80794500             cmp byte ptr [ecx + 0x45], 0
// 00475fbc  75a8                 jne 0x475f66
// 00475fbe  894604               mov dword ptr [esi + 4], eax
// 00475fc1  5f                   pop edi
// 00475fc2  5e                   pop esi
// 00475fc3  c3                   ret 
// standard library map_str<string> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@QAEXXZ)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
