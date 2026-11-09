// from server: 100% by auto
// roc 2008-06 006481e0  unit: RBX::Block  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006481e0
//
// 006481e0  56                   push esi
// 006481e1  8bf1                 mov esi, ecx
// 006481e3  833e00               cmp dword ptr [esi], 0
// 006481e6  57                   push edi
// 006481e7  8b3d90288000         mov edi, dword ptr [0x802890]
// 006481ed  7502                 jne 0x6481f1
// 006481ef  ffd7                 call edi
// 006481f1  8b4604               mov eax, dword ptr [esi + 4]
// 006481f4  80781d00             cmp byte ptr [eax + 0x1d], 0
// 006481f8  7411                 je 0x64820b
// 006481fa  8b4008               mov eax, dword ptr [eax + 8]
// 006481fd  894604               mov dword ptr [esi + 4], eax
// 00648200  80781d00             cmp byte ptr [eax + 0x1d], 0
// 00648204  745b                 je 0x648261
// 00648206  ffd7                 call edi
// 00648208  5f                   pop edi
// 00648209  5e                   pop esi
// 0064820a  c3                   ret 
// 0064820b  8b08                 mov ecx, dword ptr [eax]
// 0064820d  80791d00             cmp byte ptr [ecx + 0x1d], 0
// 00648211  751e                 jne 0x648231
// 00648213  8b4108               mov eax, dword ptr [ecx + 8]
// 00648216  80781d00             cmp byte ptr [eax + 0x1d], 0
// 0064821a  750f                 jne 0x64822b
// 0064821c  8d642400             lea esp, [esp]
// 00648220  8bc8                 mov ecx, eax
// 00648222  8b4108               mov eax, dword ptr [ecx + 8]
// 00648225  80781d00             cmp byte ptr [eax + 0x1d], 0
// 00648229  74f5                 je 0x648220
// 0064822b  5f                   pop edi
// 0064822c  894e04               mov dword ptr [esi + 4], ecx
// 0064822f  5e                   pop esi
// 00648230  c3                   ret 
// 00648231  8b4004               mov eax, dword ptr [eax + 4]
// 00648234  80781d00             cmp byte ptr [eax + 0x1d], 0
// 00648238  751b                 jne 0x648255
// 0064823a  8d9b00000000         lea ebx, [ebx]
// 00648240  8b4e04               mov ecx, dword ptr [esi + 4]
// 00648243  3b08                 cmp ecx, dword ptr [eax]
// 00648245  750e                 jne 0x648255
// 00648247  894604               mov dword ptr [esi + 4], eax
// 0064824a  8bd0                 mov edx, eax
// 0064824c  8b4204               mov eax, dword ptr [edx + 4]
// 0064824f  80781d00             cmp byte ptr [eax + 0x1d], 0
// 00648253  74eb                 je 0x648240
// 00648255  8b4e04               mov ecx, dword ptr [esi + 4]
// 00648258  80791d00             cmp byte ptr [ecx + 0x1d], 0
// 0064825c  75a8                 jne 0x648206
// 0064825e  894604               mov dword ptr [esi + 4], eax
// 00648261  5f                   pop edi
// 00648262  5e                   pop esi
// 00648263  c3                   ret 
// standard library map_int<pod12> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: map_int<pod12>
struct E { int v[3]; };
#include <map>
template class std::map<int, E>;
