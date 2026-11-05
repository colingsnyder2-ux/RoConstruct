// from server: 100% by auto
// roc 2012-06 00637770  unit: G3D::TextInput::TokenException  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00637770
//
// 00637770  8b442404             mov eax, dword ptr [esp + 4]
// 00637774  56                   push esi
// 00637775  50                   push eax
// 00637776  8bf1                 mov esi, ecx
// 00637778  e893ffffff           call 0x637710
// 0063777d  c7065c3db800         mov dword ptr [esi], 0xb83d5c
// 00637783  8bc6                 mov eax, esi
// 00637785  5e                   pop esi
// 00637786  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
