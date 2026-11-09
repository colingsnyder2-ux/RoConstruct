// from server: 100% by auto
// roc 2007-08 00534c60  unit: std::logic_error  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00534c60
//
// 00534c60  8b442404             mov eax, dword ptr [esp + 4]
// 00534c64  56                   push esi
// 00534c65  50                   push eax
// 00534c66  8bf1                 mov esi, ecx
// 00534c68  e823f0ecff           call 0x403c90
// 00534c6d  c706c4557a00         mov dword ptr [esi], 0x7a55c4
// 00534c73  8bc6                 mov eax, esi
// 00534c75  5e                   pop esi
// 00534c76  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
