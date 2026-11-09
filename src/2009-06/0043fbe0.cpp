// from server: 100% by auto
// roc 2009-06 0043fbe0  unit: CXTPDockingPaneAutoHidePanel::CAutoHidePanelTabManager  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0043fbe0
//
// 0043fbe0  53                   push ebx
// 0043fbe1  55                   push ebp
// 0043fbe2  56                   push esi
// 0043fbe3  8b742410             mov esi, dword ptr [esp + 0x10]
// 0043fbe7  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0043fbeb  57                   push edi
// 0043fbec  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 0043fbf0  8bcf                 mov ecx, edi
// 0043fbf2  2bce                 sub ecx, esi
// 0043fbf4  b893244992           mov eax, 0x92492493
// 0043fbf9  f7e9                 imul ecx
// 0043fbfb  03d1                 add edx, ecx
// 0043fbfd  c1fa04               sar edx, 4
// 0043fc00  8bc2                 mov eax, edx
// 0043fc02  c1e81f               shr eax, 0x1f
// 0043fc05  03c2                 add eax, edx
// 0043fc07  8d0cc500000000       lea ecx, [eax*8]
// 0043fc0e  2bc8                 sub ecx, eax
// 0043fc10  8d2c8b               lea ebp, [ebx + ecx*4]
// 0043fc13  3bf7                 cmp esi, edi
// 0043fc15  741a                 je 0x43fc31
// 0043fc17  2bde                 sub ebx, esi
// 0043fc19  8da42400000000       lea esp, [esp]
// 0043fc20  56                   push esi
// 0043fc21  8d0c33               lea ecx, [ebx + esi]
// 0043fc24  ff1564e48900         call dword ptr [0x89e464]
// 0043fc2a  83c61c               add esi, 0x1c
// 0043fc2d  3bf7                 cmp esi, edi
// 0043fc2f  75ef                 jne 0x43fc20
// 0043fc31  5f                   pop edi
// 0043fc32  5e                   pop esi
// 0043fc33  8bc5                 mov eax, ebp
// 0043fc35  5d                   pop ebp
// 0043fc36  5b                   pop ebx
// 0043fc37  c3                   ret 
// standard library vector<string> (function ??$_Copy_opt@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAV12@@std@@YAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@0@PAV10@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
