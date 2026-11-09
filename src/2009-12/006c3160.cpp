// from server: 100% by auto
// roc 2009-12 006c3160  unit: RBX::VContentProvider::?$BoundFuncDesc  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006c3160
//
// 006c3160  8b442404             mov eax, dword ptr [esp + 4]
// 006c3164  53                   push ebx
// 006c3165  56                   push esi
// 006c3166  57                   push edi
// 006c3167  8bf1                 mov esi, ecx
// 006c3169  8b7e14               mov edi, dword ptr [esi + 0x14]
// 006c316c  8b4f04               mov ecx, dword ptr [edi + 4]
// 006c316f  50                   push eax
// 006c3170  51                   push ecx
// 006c3171  57                   push edi
// 006c3172  8bce                 mov ecx, esi
// 006c3174  e8f7fbffff           call 0x6c2d70
// 006c3179  6a01                 push 1
// 006c317b  8bce                 mov ecx, esi
// 006c317d  8bd8                 mov ebx, eax
// 006c317f  e8eca8ffff           call 0x6bda70
// 006c3184  895f04               mov dword ptr [edi + 4], ebx
// 006c3187  8b5304               mov edx, dword ptr [ebx + 4]
// 006c318a  5f                   pop edi
// 006c318b  5e                   pop esi
// 006c318c  891a                 mov dword ptr [edx], ebx
// 006c318e  5b                   pop ebx
// 006c318f  c20400               ret 4
// standard library list<ptr> (function ?push_back@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXABQAUT@@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
