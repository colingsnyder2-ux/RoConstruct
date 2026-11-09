// from server: 100% by auto
// roc 2009-06 006d9cc0  unit: RBX::SleepStage  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006d9cc0
//
// 006d9cc0  51                   push ecx
// 006d9cc1  56                   push esi
// 006d9cc2  8bf1                 mov esi, ecx
// 006d9cc4  8d442407             lea eax, [esp + 7]
// 006d9cc8  50                   push eax
// 006d9cc9  8d4c240b             lea ecx, [esp + 0xb]
// 006d9ccd  51                   push ecx
// 006d9cce  8bce                 mov ecx, esi
// 006d9cd0  e86b55faff           call 0x67f240
// 006d9cd5  8bc6                 mov eax, esi
// 006d9cd7  5e                   pop esi
// 006d9cd8  59                   pop ecx
// 006d9cd9  c3                   ret 
// standard library set<ptr> (function ??0?$set@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
