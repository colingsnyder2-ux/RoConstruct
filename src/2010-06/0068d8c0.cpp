// from server: 100% by auto
// roc 2010-06 0068d8c0  unit: RBX::InsertService  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0068d8c0
//
// 0068d8c0  56                   push esi
// 0068d8c1  8bf1                 mov esi, ecx
// 0068d8c3  833e00               cmp dword ptr [esi], 0
// 0068d8c6  57                   push edi
// 0068d8c7  8b3d0ca99e00         mov edi, dword ptr [0x9ea90c]
// 0068d8cd  7502                 jne 0x68d8d1
// 0068d8cf  ffd7                 call edi
// 0068d8d1  8b4604               mov eax, dword ptr [esi + 4]
// 0068d8d4  80782900             cmp byte ptr [eax + 0x29], 0
// 0068d8d8  7411                 je 0x68d8eb
// 0068d8da  8b4008               mov eax, dword ptr [eax + 8]
// 0068d8dd  894604               mov dword ptr [esi + 4], eax
// 0068d8e0  80782900             cmp byte ptr [eax + 0x29], 0
// 0068d8e4  745b                 je 0x68d941
// 0068d8e6  ffd7                 call edi
// 0068d8e8  5f                   pop edi
// 0068d8e9  5e                   pop esi
// 0068d8ea  c3                   ret 
// 0068d8eb  8b08                 mov ecx, dword ptr [eax]
// 0068d8ed  80792900             cmp byte ptr [ecx + 0x29], 0
// 0068d8f1  751e                 jne 0x68d911
// 0068d8f3  8b4108               mov eax, dword ptr [ecx + 8]
// 0068d8f6  80782900             cmp byte ptr [eax + 0x29], 0
// 0068d8fa  750f                 jne 0x68d90b
// 0068d8fc  8d642400             lea esp, [esp]
// 0068d900  8bc8                 mov ecx, eax
// 0068d902  8b4108               mov eax, dword ptr [ecx + 8]
// 0068d905  80782900             cmp byte ptr [eax + 0x29], 0
// 0068d909  74f5                 je 0x68d900
// 0068d90b  5f                   pop edi
// 0068d90c  894e04               mov dword ptr [esi + 4], ecx
// 0068d90f  5e                   pop esi
// 0068d910  c3                   ret 
// 0068d911  8b4004               mov eax, dword ptr [eax + 4]
// 0068d914  80782900             cmp byte ptr [eax + 0x29], 0
// 0068d918  751b                 jne 0x68d935
// 0068d91a  8d9b00000000         lea ebx, [ebx]
// 0068d920  8b4e04               mov ecx, dword ptr [esi + 4]
// 0068d923  3b08                 cmp ecx, dword ptr [eax]
// 0068d925  750e                 jne 0x68d935
// 0068d927  894604               mov dword ptr [esi + 4], eax
// 0068d92a  8bd0                 mov edx, eax
// 0068d92c  8b4204               mov eax, dword ptr [edx + 4]
// 0068d92f  80782900             cmp byte ptr [eax + 0x29], 0
// 0068d933  74eb                 je 0x68d920
// 0068d935  8b4e04               mov ecx, dword ptr [esi + 4]
// 0068d938  80792900             cmp byte ptr [ecx + 0x29], 0
// 0068d93c  75a8                 jne 0x68d8e6
// 0068d93e  894604               mov dword ptr [esi + 4], eax
// 0068d941  5f                   pop edi
// 0068d942  5e                   pop esi
// 0068d943  c3                   ret 
// standard library map_int<pod24> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: map_int<pod24>
struct E { int v[6]; };
#include <map>
template class std::map<int, E>;
