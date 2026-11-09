// from server: 100% by auto
// roc 2008-06 0040a050  unit: RBX::GlobalSettings::Item  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0040a050
//
// 0040a050  8b442404             mov eax, dword ptr [esp + 4]
// 0040a054  56                   push esi
// 0040a055  50                   push eax
// 0040a056  8bf1                 mov esi, ecx
// 0040a058  e833feffff           call 0x409e90
// 0040a05d  c706dcb88000         mov dword ptr [esi], 0x80b8dc
// 0040a063  8bc6                 mov eax, esi
// 0040a065  5e                   pop esi
// 0040a066  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
