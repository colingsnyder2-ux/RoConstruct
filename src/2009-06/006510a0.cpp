// from server: 100% by auto
// roc 2009-06 006510a0  unit: RBX::VExplosion::?$EventDesc  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006510a0
//
// 006510a0  8b442404             mov eax, dword ptr [esp + 4]
// 006510a4  56                   push esi
// 006510a5  50                   push eax
// 006510a6  8bf1                 mov esi, ecx
// 006510a8  e8a3ffffff           call 0x651050
// 006510ad  c70654f98d00         mov dword ptr [esi], 0x8df954
// 006510b3  8bc6                 mov eax, esi
// 006510b5  5e                   pop esi
// 006510b6  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
