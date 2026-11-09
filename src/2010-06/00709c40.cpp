// from server: 100% by auto
// roc 2010-06 00709c40  unit: RBX::Joint  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00709c40
//
// 00709c40  56                   push esi
// 00709c41  8bf1                 mov esi, ecx
// 00709c43  833e00               cmp dword ptr [esi], 0
// 00709c46  57                   push edi
// 00709c47  8b3d0ca99e00         mov edi, dword ptr [0x9ea90c]
// 00709c4d  7502                 jne 0x709c51
// 00709c4f  ffd7                 call edi
// 00709c51  8b4604               mov eax, dword ptr [esi + 4]
// 00709c54  80781500             cmp byte ptr [eax + 0x15], 0
// 00709c58  7411                 je 0x709c6b
// 00709c5a  8b4008               mov eax, dword ptr [eax + 8]
// 00709c5d  894604               mov dword ptr [esi + 4], eax
// 00709c60  80781500             cmp byte ptr [eax + 0x15], 0
// 00709c64  745b                 je 0x709cc1
// 00709c66  ffd7                 call edi
// 00709c68  5f                   pop edi
// 00709c69  5e                   pop esi
// 00709c6a  c3                   ret 
// 00709c6b  8b08                 mov ecx, dword ptr [eax]
// 00709c6d  80791500             cmp byte ptr [ecx + 0x15], 0
// 00709c71  751e                 jne 0x709c91
// 00709c73  8b4108               mov eax, dword ptr [ecx + 8]
// 00709c76  80781500             cmp byte ptr [eax + 0x15], 0
// 00709c7a  750f                 jne 0x709c8b
// 00709c7c  8d642400             lea esp, [esp]
// 00709c80  8bc8                 mov ecx, eax
// 00709c82  8b4108               mov eax, dword ptr [ecx + 8]
// 00709c85  80781500             cmp byte ptr [eax + 0x15], 0
// 00709c89  74f5                 je 0x709c80
// 00709c8b  5f                   pop edi
// 00709c8c  894e04               mov dword ptr [esi + 4], ecx
// 00709c8f  5e                   pop esi
// 00709c90  c3                   ret 
// 00709c91  8b4004               mov eax, dword ptr [eax + 4]
// 00709c94  80781500             cmp byte ptr [eax + 0x15], 0
// 00709c98  751b                 jne 0x709cb5
// 00709c9a  8d9b00000000         lea ebx, [ebx]
// 00709ca0  8b4e04               mov ecx, dword ptr [esi + 4]
// 00709ca3  3b08                 cmp ecx, dword ptr [eax]
// 00709ca5  750e                 jne 0x709cb5
// 00709ca7  894604               mov dword ptr [esi + 4], eax
// 00709caa  8bd0                 mov edx, eax
// 00709cac  8b4204               mov eax, dword ptr [edx + 4]
// 00709caf  80781500             cmp byte ptr [eax + 0x15], 0
// 00709cb3  74eb                 je 0x709ca0
// 00709cb5  8b4e04               mov ecx, dword ptr [esi + 4]
// 00709cb8  80791500             cmp byte ptr [ecx + 0x15], 0
// 00709cbc  75a8                 jne 0x709c66
// 00709cbe  894604               mov dword ptr [esi + 4], eax
// 00709cc1  5f                   pop edi
// 00709cc2  5e                   pop esi
// 00709cc3  c3                   ret 
// standard library map_int<ptr> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: map_int<ptr>
struct T; typedef T* E;
#include <map>
template class std::map<int, E>;
