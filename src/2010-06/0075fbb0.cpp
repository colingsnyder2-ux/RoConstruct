// from server: 100% by auto
// roc 2010-06 0075fbb0  unit: RBX::SleepStage  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0075fbb0
//
// 0075fbb0  51                   push ecx
// 0075fbb1  56                   push esi
// 0075fbb2  8bf1                 mov esi, ecx
// 0075fbb4  8d442407             lea eax, [esp + 7]
// 0075fbb8  50                   push eax
// 0075fbb9  8d4c240b             lea ecx, [esp + 0xb]
// 0075fbbd  51                   push ecx
// 0075fbbe  8bce                 mov ecx, esi
// 0075fbc0  e8fbf9ffff           call 0x75f5c0
// 0075fbc5  8bc6                 mov eax, esi
// 0075fbc7  5e                   pop esi
// 0075fbc8  59                   pop ecx
// 0075fbc9  c3                   ret 
// standard library set<ptr> (function ??0?$set@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
