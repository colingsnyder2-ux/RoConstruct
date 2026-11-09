// from server: 100% by auto
// roc 2012-06 006c83c0  unit: RBX::Reflection::PAVPropertyDescriptor::?$trie::depth_exceeded_exception  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006c83c0
//
// 006c83c0  8b442404             mov eax, dword ptr [esp + 4]
// 006c83c4  56                   push esi
// 006c83c5  50                   push eax
// 006c83c6  8bf1                 mov esi, ecx
// 006c83c8  ff15e429b200         call dword ptr [0xb229e4]
// 006c83ce  c7069870b900         mov dword ptr [esi], 0xb97098
// 006c83d4  8bc6                 mov eax, esi
// 006c83d6  5e                   pop esi
// 006c83d7  c20400               ret 4
// standard library vector<ptr> (function ??0bad_alloc@std@@QAE@ABV01@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
