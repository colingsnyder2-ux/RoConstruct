// from server: 100% by auto
// roc 2012-06 006c8540  unit: RBX::Reflection::PAVPropertyDescriptor::?$trie::depth_exceeded_exception  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006c8540
//
// 006c8540  8b442404             mov eax, dword ptr [esp + 4]
// 006c8544  56                   push esi
// 006c8545  50                   push eax
// 006c8546  8bf1                 mov esi, ecx
// 006c8548  ff15e429b200         call dword ptr [0xb229e4]
// 006c854e  c706bc70b900         mov dword ptr [esi], 0xb970bc
// 006c8554  8bc6                 mov eax, esi
// 006c8556  5e                   pop esi
// 006c8557  c20400               ret 4
// standard library vector<ptr> (function ??0bad_alloc@std@@QAE@ABV01@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
