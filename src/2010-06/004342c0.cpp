// from server: 100% by auto
// roc 2010-06 004342c0  unit: HVCXTPPropertyGridItemEnum::?$XItem  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004342c0
//
// 004342c0  56                   push esi
// 004342c1  8bf1                 mov esi, ecx
// 004342c3  833e00               cmp dword ptr [esi], 0
// 004342c6  57                   push edi
// 004342c7  8b3d0ca99e00         mov edi, dword ptr [0x9ea90c]
// 004342cd  7502                 jne 0x4342d1
// 004342cf  ffd7                 call edi
// 004342d1  8b4604               mov eax, dword ptr [esi + 4]
// 004342d4  80781900             cmp byte ptr [eax + 0x19], 0
// 004342d8  7411                 je 0x4342eb
// 004342da  8b4008               mov eax, dword ptr [eax + 8]
// 004342dd  894604               mov dword ptr [esi + 4], eax
// 004342e0  80781900             cmp byte ptr [eax + 0x19], 0
// 004342e4  745b                 je 0x434341
// 004342e6  ffd7                 call edi
// 004342e8  5f                   pop edi
// 004342e9  5e                   pop esi
// 004342ea  c3                   ret 
// 004342eb  8b08                 mov ecx, dword ptr [eax]
// 004342ed  80791900             cmp byte ptr [ecx + 0x19], 0
// 004342f1  751e                 jne 0x434311
// 004342f3  8b4108               mov eax, dword ptr [ecx + 8]
// 004342f6  80781900             cmp byte ptr [eax + 0x19], 0
// 004342fa  750f                 jne 0x43430b
// 004342fc  8d642400             lea esp, [esp]
// 00434300  8bc8                 mov ecx, eax
// 00434302  8b4108               mov eax, dword ptr [ecx + 8]
// 00434305  80781900             cmp byte ptr [eax + 0x19], 0
// 00434309  74f5                 je 0x434300
// 0043430b  5f                   pop edi
// 0043430c  894e04               mov dword ptr [esi + 4], ecx
// 0043430f  5e                   pop esi
// 00434310  c3                   ret 
// 00434311  8b4004               mov eax, dword ptr [eax + 4]
// 00434314  80781900             cmp byte ptr [eax + 0x19], 0
// 00434318  751b                 jne 0x434335
// 0043431a  8d9b00000000         lea ebx, [ebx]
// 00434320  8b4e04               mov ecx, dword ptr [esi + 4]
// 00434323  3b08                 cmp ecx, dword ptr [eax]
// 00434325  750e                 jne 0x434335
// 00434327  894604               mov dword ptr [esi + 4], eax
// 0043432a  8bd0                 mov edx, eax
// 0043432c  8b4204               mov eax, dword ptr [edx + 4]
// 0043432f  80781900             cmp byte ptr [eax + 0x19], 0
// 00434333  74eb                 je 0x434320
// 00434335  8b4e04               mov ecx, dword ptr [esi + 4]
// 00434338  80791900             cmp byte ptr [ecx + 0x19], 0
// 0043433c  75a8                 jne 0x4342e6
// 0043433e  894604               mov dword ptr [esi + 4], eax
// 00434341  5f                   pop edi
// 00434342  5e                   pop esi
// 00434343  c3                   ret 
// standard library map_int<pod8> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: map_int<pod8>
struct E { int v[2]; };
#include <map>
template class std::map<int, E>;
