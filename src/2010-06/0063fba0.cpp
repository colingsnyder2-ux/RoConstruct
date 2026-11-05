// from server: 100% by auto
// roc 2010-06 0063fba0  unit: RBX::VVisit::?$BoundFuncDesc  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0063fba0
//
// 0063fba0  56                   push esi
// 0063fba1  8bf1                 mov esi, ecx
// 0063fba3  833e00               cmp dword ptr [esi], 0
// 0063fba6  57                   push edi
// 0063fba7  8b3d0ca99e00         mov edi, dword ptr [0x9ea90c]
// 0063fbad  7502                 jne 0x63fbb1
// 0063fbaf  ffd7                 call edi
// 0063fbb1  8b4604               mov eax, dword ptr [esi + 4]
// 0063fbb4  80783500             cmp byte ptr [eax + 0x35], 0
// 0063fbb8  7411                 je 0x63fbcb
// 0063fbba  8b4008               mov eax, dword ptr [eax + 8]
// 0063fbbd  894604               mov dword ptr [esi + 4], eax
// 0063fbc0  80783500             cmp byte ptr [eax + 0x35], 0
// 0063fbc4  745b                 je 0x63fc21
// 0063fbc6  ffd7                 call edi
// 0063fbc8  5f                   pop edi
// 0063fbc9  5e                   pop esi
// 0063fbca  c3                   ret 
// 0063fbcb  8b08                 mov ecx, dword ptr [eax]
// 0063fbcd  80793500             cmp byte ptr [ecx + 0x35], 0
// 0063fbd1  751e                 jne 0x63fbf1
// 0063fbd3  8b4108               mov eax, dword ptr [ecx + 8]
// 0063fbd6  80783500             cmp byte ptr [eax + 0x35], 0
// 0063fbda  750f                 jne 0x63fbeb
// 0063fbdc  8d642400             lea esp, [esp]
// 0063fbe0  8bc8                 mov ecx, eax
// 0063fbe2  8b4108               mov eax, dword ptr [ecx + 8]
// 0063fbe5  80783500             cmp byte ptr [eax + 0x35], 0
// 0063fbe9  74f5                 je 0x63fbe0
// 0063fbeb  5f                   pop edi
// 0063fbec  894e04               mov dword ptr [esi + 4], ecx
// 0063fbef  5e                   pop esi
// 0063fbf0  c3                   ret 
// 0063fbf1  8b4004               mov eax, dword ptr [eax + 4]
// 0063fbf4  80783500             cmp byte ptr [eax + 0x35], 0
// 0063fbf8  751b                 jne 0x63fc15
// 0063fbfa  8d9b00000000         lea ebx, [ebx]
// 0063fc00  8b4e04               mov ecx, dword ptr [esi + 4]
// 0063fc03  3b08                 cmp ecx, dword ptr [eax]
// 0063fc05  750e                 jne 0x63fc15
// 0063fc07  894604               mov dword ptr [esi + 4], eax
// 0063fc0a  8bd0                 mov edx, eax
// 0063fc0c  8b4204               mov eax, dword ptr [edx + 4]
// 0063fc0f  80783500             cmp byte ptr [eax + 0x35], 0
// 0063fc13  74eb                 je 0x63fc00
// 0063fc15  8b4e04               mov ecx, dword ptr [esi + 4]
// 0063fc18  80793500             cmp byte ptr [ecx + 0x35], 0
// 0063fc1c  75a8                 jne 0x63fbc6
// 0063fc1e  894604               mov dword ptr [esi + 4], eax
// 0063fc21  5f                   pop edi
// 0063fc22  5e                   pop esi
// 0063fc23  c3                   ret 
// standard library map_int<pod36> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: map_int<pod36>
struct E { int v[9]; };
#include <map>
template class std::map<int, E>;
