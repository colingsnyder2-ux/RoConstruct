// from server: 100% by auto
// roc 2007-08 0056ab90  unit: ArchiveBinder  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0056ab90
//
// 0056ab90  56                   push esi
// 0056ab91  8bf1                 mov esi, ecx
// 0056ab93  833e00               cmp dword ptr [esi], 0
// 0056ab96  57                   push edi
// 0056ab97  8b3dd8e67700         mov edi, dword ptr [0x77e6d8]
// 0056ab9d  7502                 jne 0x56aba1
// 0056ab9f  ffd7                 call edi
// 0056aba1  8b4604               mov eax, dword ptr [esi + 4]
// 0056aba4  80783100             cmp byte ptr [eax + 0x31], 0
// 0056aba8  7411                 je 0x56abbb
// 0056abaa  8b4008               mov eax, dword ptr [eax + 8]
// 0056abad  894604               mov dword ptr [esi + 4], eax
// 0056abb0  80783100             cmp byte ptr [eax + 0x31], 0
// 0056abb4  745b                 je 0x56ac11
// 0056abb6  ffd7                 call edi
// 0056abb8  5f                   pop edi
// 0056abb9  5e                   pop esi
// 0056abba  c3                   ret 
// 0056abbb  8b08                 mov ecx, dword ptr [eax]
// 0056abbd  80793100             cmp byte ptr [ecx + 0x31], 0
// 0056abc1  751e                 jne 0x56abe1
// 0056abc3  8b4108               mov eax, dword ptr [ecx + 8]
// 0056abc6  80783100             cmp byte ptr [eax + 0x31], 0
// 0056abca  750f                 jne 0x56abdb
// 0056abcc  8d642400             lea esp, [esp]
// 0056abd0  8bc8                 mov ecx, eax
// 0056abd2  8b4108               mov eax, dword ptr [ecx + 8]
// 0056abd5  80783100             cmp byte ptr [eax + 0x31], 0
// 0056abd9  74f5                 je 0x56abd0
// 0056abdb  5f                   pop edi
// 0056abdc  894e04               mov dword ptr [esi + 4], ecx
// 0056abdf  5e                   pop esi
// 0056abe0  c3                   ret 
// 0056abe1  8b4004               mov eax, dword ptr [eax + 4]
// 0056abe4  80783100             cmp byte ptr [eax + 0x31], 0
// 0056abe8  751b                 jne 0x56ac05
// 0056abea  8d9b00000000         lea ebx, [ebx]
// 0056abf0  8b4e04               mov ecx, dword ptr [esi + 4]
// 0056abf3  3b08                 cmp ecx, dword ptr [eax]
// 0056abf5  750e                 jne 0x56ac05
// 0056abf7  894604               mov dword ptr [esi + 4], eax
// 0056abfa  8bd0                 mov edx, eax
// 0056abfc  8b4204               mov eax, dword ptr [edx + 4]
// 0056abff  80783100             cmp byte ptr [eax + 0x31], 0
// 0056ac03  74eb                 je 0x56abf0
// 0056ac05  8b4e04               mov ecx, dword ptr [esi + 4]
// 0056ac08  80793100             cmp byte ptr [ecx + 0x31], 0
// 0056ac0c  75a8                 jne 0x56abb6
// 0056ac0e  894604               mov dword ptr [esi + 4], eax
// 0056ac11  5f                   pop edi
// 0056ac12  5e                   pop esi
// 0056ac13  c3                   ret 
// standard library map_int<pod32> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: map_int<pod32>
struct E { int v[8]; };
#include <map>
template class std::map<int, E>;
