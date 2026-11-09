// from server: 100% by auto
// roc 2007-08 005465b0  unit: RBX::MD5HasherImpl  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005465b0
//
// 005465b0  56                   push esi
// 005465b1  57                   push edi
// 005465b2  8bf9                 mov edi, ecx
// 005465b4  8b4704               mov eax, dword ptr [edi + 4]
// 005465b7  8b30                 mov esi, dword ptr [eax]
// 005465b9  8900                 mov dword ptr [eax], eax
// 005465bb  8b4704               mov eax, dword ptr [edi + 4]
// 005465be  894004               mov dword ptr [eax + 4], eax
// 005465c1  3b7704               cmp esi, dword ptr [edi + 4]
// 005465c4  c7470800000000       mov dword ptr [edi + 8], 0
// 005465cb  741f                 je 0x5465ec
// 005465cd  53                   push ebx
// 005465ce  8bff                 mov edi, edi
// 005465d0  8b1e                 mov ebx, dword ptr [esi]
// 005465d2  8d4e08               lea ecx, [esi + 8]
// 005465d5  ff15ace67700         call dword ptr [0x77e6ac]
// 005465db  56                   push esi
// 005465dc  e881960e00           call 0x62fc62
// 005465e1  83c404               add esp, 4
// 005465e4  3b5f04               cmp ebx, dword ptr [edi + 4]
// 005465e7  8bf3                 mov esi, ebx
// 005465e9  75e5                 jne 0x5465d0
// 005465eb  5b                   pop ebx
// 005465ec  5f                   pop edi
// 005465ed  5e                   pop esi
// 005465ee  c3                   ret 
// standard library list<string> (function ?clear@?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAEXXZ)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
