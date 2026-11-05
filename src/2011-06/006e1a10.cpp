// from server: 100% by auto
// roc 2011-06 006e1a10  unit: UString_sink::?$stream_buffer  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 006e1a10
//
// 006e1a10  8b442404             mov eax, dword ptr [esp + 4]
// 006e1a14  56                   push esi
// 006e1a15  50                   push eax
// 006e1a16  8bf1                 mov esi, ecx
// 006e1a18  e8c38fd2ff           call 0x40a9e0
// 006e1a1d  c7064882aa00         mov dword ptr [esi], 0xaa8248
// 006e1a23  8bc6                 mov eax, esi
// 006e1a25  5e                   pop esi
// 006e1a26  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
