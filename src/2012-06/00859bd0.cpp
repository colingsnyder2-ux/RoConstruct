// from server: 100% by auto
// roc 2012-06 00859bd0  unit: UString_sink::?$stream_buffer  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00859bd0
//
// 00859bd0  8b442404             mov eax, dword ptr [esp + 4]
// 00859bd4  56                   push esi
// 00859bd5  50                   push eax
// 00859bd6  8bf1                 mov esi, ecx
// 00859bd8  e83325bbff           call 0x40c110
// 00859bdd  c7065444bd00         mov dword ptr [esi], 0xbd4454
// 00859be3  8bc6                 mov eax, esi
// 00859be5  5e                   pop esi
// 00859be6  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
