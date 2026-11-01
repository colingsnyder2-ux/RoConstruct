// from server: 100% by auto
// roc 2009-12 007b7ec0  unit: RBX::SleepStage  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007b7ec0
//
// 007b7ec0  51                   push ecx
// 007b7ec1  56                   push esi
// 007b7ec2  8bf1                 mov esi, ecx
// 007b7ec4  8d442407             lea eax, [esp + 7]
// 007b7ec8  50                   push eax
// 007b7ec9  8d4c240b             lea ecx, [esp + 0xb]
// 007b7ecd  51                   push ecx
// 007b7ece  8bce                 mov ecx, esi
// 007b7ed0  e8bba5c4ff           call 0x402490
// 007b7ed5  8bc6                 mov eax, esi
// 007b7ed7  5e                   pop esi
// 007b7ed8  59                   pop ecx
// 007b7ed9  c3                   ret 
// standard library set<ptr> (function ??0?$set@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
