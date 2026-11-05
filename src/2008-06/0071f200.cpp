// from server: 100% by auto
// roc 2008-06 0071f200  unit: CXTPShortcutManager  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0071f200
//
// 0071f200  8b01                 mov eax, dword ptr [ecx]
// 0071f202  50                   push eax
// 0071f203  e84217f8ff           call 0x6a094a
// 0071f208  59                   pop ecx
// 0071f209  c3                   ret 
// standard library vector<ptr> (function ??1?$_Container_base_aux_alloc_real@V?$allocator@PAUT@@@std@@@std@@IAE@XZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
