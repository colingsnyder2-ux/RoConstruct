// from server: 100% by auto
// roc 2012-06 0041a9d0  unit: PasteVerb  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0041a9d0
//
// 0041a9d0  8b442404             mov eax, dword ptr [esp + 4]
// 0041a9d4  56                   push esi
// 0041a9d5  50                   push eax
// 0041a9d6  8bf1                 mov esi, ecx
// 0041a9d8  e8638e2e00           call 0x703840
// 0041a9dd  c706c06fb400         mov dword ptr [esi], 0xb46fc0
// 0041a9e3  8bc6                 mov eax, esi
// 0041a9e5  5e                   pop esi
// 0041a9e6  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
