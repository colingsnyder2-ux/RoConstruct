// from server: 100% by auto
// roc 2011-06 006e0ed0  unit: RBX::PAVPrimitive::$$A6AXU?$pair::?$signal::Vslot::?$callable  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 006e0ed0
//
// 006e0ed0  8b442404             mov eax, dword ptr [esp + 4]
// 006e0ed4  56                   push esi
// 006e0ed5  50                   push eax
// 006e0ed6  8bf1                 mov esi, ecx
// 006e0ed8  e8739ad2ff           call 0x40a950
// 006e0edd  c7064882aa00         mov dword ptr [esi], 0xaa8248
// 006e0ee3  8bc6                 mov eax, esi
// 006e0ee5  5e                   pop esi
// 006e0ee6  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
