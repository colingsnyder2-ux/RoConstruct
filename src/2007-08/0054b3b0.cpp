// from server: 100% by auto
// roc 2007-08 0054b3b0  unit: UString_sink::?$stream_buffer  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0054b3b0
//
// 0054b3b0  8b442404             mov eax, dword ptr [esp + 4]
// 0054b3b4  56                   push esi
// 0054b3b5  50                   push eax
// 0054b3b6  8bf1                 mov esi, ecx
// 0054b3b8  e8f382ecff           call 0x4136b0
// 0054b3bd  c7063c787a00         mov dword ptr [esi], 0x7a783c
// 0054b3c3  8bc6                 mov eax, esi
// 0054b3c5  5e                   pop esi
// 0054b3c6  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
