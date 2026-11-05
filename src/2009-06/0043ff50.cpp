// from server: 100% by auto
// roc 2009-06 0043ff50  unit: VCRenderSettingsItem::?$FactoryProduct  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0043ff50
//
// 0043ff50  8b01                 mov eax, dword ptr [ecx]
// 0043ff52  50                   push eax
// 0043ff53  e8da8a2d00           call 0x718a32
// 0043ff58  59                   pop ecx
// 0043ff59  c3                   ret 
// standard library vector<ptr> (function ??1?$_Container_base_aux_alloc_real@V?$allocator@PAUT@@@std@@@std@@IAE@XZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
