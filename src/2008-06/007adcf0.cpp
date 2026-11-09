// from server: 100% by auto
// roc 2008-06 007adcf0  unit: RBX::RenderNew::TextureProxy  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 007adcf0
//
// 007adcf0  8b442404             mov eax, dword ptr [esp + 4]
// 007adcf4  56                   push esi
// 007adcf5  50                   push eax
// 007adcf6  8bf1                 mov esi, ecx
// 007adcf8  e893c1c5ff           call 0x409e90
// 007adcfd  c706344b8700         mov dword ptr [esi], 0x874b34
// 007add03  8bc6                 mov eax, esi
// 007add05  5e                   pop esi
// 007add06  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
