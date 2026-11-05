// from server: 100% by auto
// roc 2010-06 006a0900  unit: UString_sink::?$stream_buffer  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006a0900
//
// 006a0900  8b442404             mov eax, dword ptr [esp + 4]
// 006a0904  56                   push esi
// 006a0905  50                   push eax
// 006a0906  8bf1                 mov esi, ecx
// 006a0908  e8138bd6ff           call 0x409420
// 006a090d  c706f808a400         mov dword ptr [esi], 0xa408f8
// 006a0913  8bc6                 mov eax, esi
// 006a0915  5e                   pop esi
// 006a0916  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
