// from server: 100% by auto
// roc 2009-06 00835460  unit: RBX::RenderNew::TextureProxy  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00835460
//
// 00835460  8b442404             mov eax, dword ptr [esp + 4]
// 00835464  56                   push esi
// 00835465  50                   push eax
// 00835466  8bf1                 mov esi, ecx
// 00835468  e81340bdff           call 0x409480
// 0083546d  c70664389200         mov dword ptr [esi], 0x923864
// 00835473  8bc6                 mov eax, esi
// 00835475  5e                   pop esi
// 00835476  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
