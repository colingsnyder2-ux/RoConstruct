// from server: 100% by auto
// roc 2012-06 00792d50  unit: RBX::LuaAllocator  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00792d50
//
// 00792d50  8b442404             mov eax, dword ptr [esp + 4]
// 00792d54  56                   push esi
// 00792d55  50                   push eax
// 00792d56  8bf1                 mov esi, ecx
// 00792d58  e893ffffff           call 0x792cf0
// 00792d5d  c706702bbb00         mov dword ptr [esi], 0xbb2b70
// 00792d63  8bc6                 mov eax, esi
// 00792d65  5e                   pop esi
// 00792d66  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
