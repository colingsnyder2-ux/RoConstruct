// from server: 100% by auto
// roc 2012-06 009ecd00  unit: CXTPToolTipContext  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009ecd00
//
// 009ecd00  8b442404             mov eax, dword ptr [esp + 4]
// 009ecd04  56                   push esi
// 009ecd05  50                   push eax
// 009ecd06  8bf1                 mov esi, ecx
// 009ecd08  e853eeffff           call 0x9ebb60
// 009ecd0d  c7068484c100         mov dword ptr [esi], 0xc18484
// 009ecd13  8bc6                 mov eax, esi
// 009ecd15  5e                   pop esi
// 009ecd16  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
