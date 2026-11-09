// from server: 100% by auto
// roc 2011-06 00543840  unit: G3D::BinaryInput  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00543840
//
// 00543840  8b442408             mov eax, dword ptr [esp + 8]
// 00543844  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00543848  56                   push esi
// 00543849  8b742410             mov esi, dword ptr [esp + 0x10]
// 0054384d  2bc1                 sub eax, ecx
// 0054384f  2bf0                 sub esi, eax
// 00543851  85c0                 test eax, eax
// 00543853  7e0d                 jle 0x543862
// 00543855  50                   push eax
// 00543856  51                   push ecx
// 00543857  50                   push eax
// 00543858  56                   push esi
// 00543859  ff15fc09a400         call dword ptr [0xa409fc]
// 0054385f  83c410               add esp, 0x10
// 00543862  8bc6                 mov eax, esi
// 00543864  5e                   pop esi
// 00543865  c3                   ret 
// standard library vector<char> (function ??$_Copy_backward_opt@PADPADUrandom_access_iterator_tag@std@@@std@@YAPADPAD00Urandom_access_iterator_tag@0@U_Scalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<char>
typedef char E;
#include <vector>
template class std::vector<E>;
