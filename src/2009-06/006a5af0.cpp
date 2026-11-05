// from server: 100% by auto
// roc 2009-06 006a5af0  unit: RBX::VMouse::?$EventDesc  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006a5af0
//
// 006a5af0  56                   push esi
// 006a5af1  8bf1                 mov esi, ecx
// 006a5af3  833e00               cmp dword ptr [esi], 0
// 006a5af6  57                   push edi
// 006a5af7  8b3dace98900         mov edi, dword ptr [0x89e9ac]
// 006a5afd  7502                 jne 0x6a5b01
// 006a5aff  ffd7                 call edi
// 006a5b01  8b4604               mov eax, dword ptr [esi + 4]
// 006a5b04  80781500             cmp byte ptr [eax + 0x15], 0
// 006a5b08  7411                 je 0x6a5b1b
// 006a5b0a  8b4008               mov eax, dword ptr [eax + 8]
// 006a5b0d  894604               mov dword ptr [esi + 4], eax
// 006a5b10  80781500             cmp byte ptr [eax + 0x15], 0
// 006a5b14  745b                 je 0x6a5b71
// 006a5b16  ffd7                 call edi
// 006a5b18  5f                   pop edi
// 006a5b19  5e                   pop esi
// 006a5b1a  c3                   ret 
// 006a5b1b  8b08                 mov ecx, dword ptr [eax]
// 006a5b1d  80791500             cmp byte ptr [ecx + 0x15], 0
// 006a5b21  751e                 jne 0x6a5b41
// 006a5b23  8b4108               mov eax, dword ptr [ecx + 8]
// 006a5b26  80781500             cmp byte ptr [eax + 0x15], 0
// 006a5b2a  750f                 jne 0x6a5b3b
// 006a5b2c  8d642400             lea esp, [esp]
// 006a5b30  8bc8                 mov ecx, eax
// 006a5b32  8b4108               mov eax, dword ptr [ecx + 8]
// 006a5b35  80781500             cmp byte ptr [eax + 0x15], 0
// 006a5b39  74f5                 je 0x6a5b30
// 006a5b3b  5f                   pop edi
// 006a5b3c  894e04               mov dword ptr [esi + 4], ecx
// 006a5b3f  5e                   pop esi
// 006a5b40  c3                   ret 
// 006a5b41  8b4004               mov eax, dword ptr [eax + 4]
// 006a5b44  80781500             cmp byte ptr [eax + 0x15], 0
// 006a5b48  751b                 jne 0x6a5b65
// 006a5b4a  8d9b00000000         lea ebx, [ebx]
// 006a5b50  8b4e04               mov ecx, dword ptr [esi + 4]
// 006a5b53  3b08                 cmp ecx, dword ptr [eax]
// 006a5b55  750e                 jne 0x6a5b65
// 006a5b57  894604               mov dword ptr [esi + 4], eax
// 006a5b5a  8bd0                 mov edx, eax
// 006a5b5c  8b4204               mov eax, dword ptr [edx + 4]
// 006a5b5f  80781500             cmp byte ptr [eax + 0x15], 0
// 006a5b63  74eb                 je 0x6a5b50
// 006a5b65  8b4e04               mov ecx, dword ptr [esi + 4]
// 006a5b68  80791500             cmp byte ptr [ecx + 0x15], 0
// 006a5b6c  75a8                 jne 0x6a5b16
// 006a5b6e  894604               mov dword ptr [esi + 4], eax
// 006a5b71  5f                   pop edi
// 006a5b72  5e                   pop esi
// 006a5b73  c3                   ret 
// standard library map_int<ptr> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: map_int<ptr>
struct T; typedef T* E;
#include <map>
template class std::map<int, E>;
