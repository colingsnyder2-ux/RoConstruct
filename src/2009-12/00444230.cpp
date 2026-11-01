// from server: 100% by auto
// roc 2009-12 00444230  unit: RBX::RbxG3D::Material  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00444230
//
// 00444230  56                   push esi
// 00444231  8bf1                 mov esi, ecx
// 00444233  833e00               cmp dword ptr [esi], 0
// 00444236  57                   push edi
// 00444237  8b3d60b79800         mov edi, dword ptr [0x98b760]
// 0044423d  7502                 jne 0x444241
// 0044423f  ffd7                 call edi
// 00444241  8b4604               mov eax, dword ptr [esi + 4]
// 00444244  80781500             cmp byte ptr [eax + 0x15], 0
// 00444248  7411                 je 0x44425b
// 0044424a  8b4008               mov eax, dword ptr [eax + 8]
// 0044424d  894604               mov dword ptr [esi + 4], eax
// 00444250  80781500             cmp byte ptr [eax + 0x15], 0
// 00444254  745b                 je 0x4442b1
// 00444256  ffd7                 call edi
// 00444258  5f                   pop edi
// 00444259  5e                   pop esi
// 0044425a  c3                   ret 
// 0044425b  8b08                 mov ecx, dword ptr [eax]
// 0044425d  80791500             cmp byte ptr [ecx + 0x15], 0
// 00444261  751e                 jne 0x444281
// 00444263  8b4108               mov eax, dword ptr [ecx + 8]
// 00444266  80781500             cmp byte ptr [eax + 0x15], 0
// 0044426a  750f                 jne 0x44427b
// 0044426c  8d642400             lea esp, [esp]
// 00444270  8bc8                 mov ecx, eax
// 00444272  8b4108               mov eax, dword ptr [ecx + 8]
// 00444275  80781500             cmp byte ptr [eax + 0x15], 0
// 00444279  74f5                 je 0x444270
// 0044427b  5f                   pop edi
// 0044427c  894e04               mov dword ptr [esi + 4], ecx
// 0044427f  5e                   pop esi
// 00444280  c3                   ret 
// 00444281  8b4004               mov eax, dword ptr [eax + 4]
// 00444284  80781500             cmp byte ptr [eax + 0x15], 0
// 00444288  751b                 jne 0x4442a5
// 0044428a  8d9b00000000         lea ebx, [ebx]
// 00444290  8b4e04               mov ecx, dword ptr [esi + 4]
// 00444293  3b08                 cmp ecx, dword ptr [eax]
// 00444295  750e                 jne 0x4442a5
// 00444297  894604               mov dword ptr [esi + 4], eax
// 0044429a  8bd0                 mov edx, eax
// 0044429c  8b4204               mov eax, dword ptr [edx + 4]
// 0044429f  80781500             cmp byte ptr [eax + 0x15], 0
// 004442a3  74eb                 je 0x444290
// 004442a5  8b4e04               mov ecx, dword ptr [esi + 4]
// 004442a8  80791500             cmp byte ptr [ecx + 0x15], 0
// 004442ac  75a8                 jne 0x444256
// 004442ae  894604               mov dword ptr [esi + 4], eax
// 004442b1  5f                   pop edi
// 004442b2  5e                   pop esi
// 004442b3  c3                   ret 
// standard library map_int<ptr> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: map_int<ptr>
struct T; typedef T* E;
#include <map>
template class std::map<int, E>;
