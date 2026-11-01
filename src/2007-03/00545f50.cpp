// from server: 100% by auto
// roc 2007-03 00545f50  unit: seg_00540000  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00545f50
//
// 00545f50  56                   push esi
// 00545f51  57                   push edi
// 00545f52  8bf9                 mov edi, ecx
// 00545f54  8b4704               mov eax, dword ptr [edi + 4]
// 00545f57  8b30                 mov esi, dword ptr [eax]
// 00545f59  8900                 mov dword ptr [eax], eax
// 00545f5b  8b4704               mov eax, dword ptr [edi + 4]
// 00545f5e  894004               mov dword ptr [eax + 4], eax
// 00545f61  3b7704               cmp esi, dword ptr [edi + 4]
// 00545f64  c7470800000000       mov dword ptr [edi + 8], 0
// 00545f6b  741f                 je 0x545f8c
// 00545f6d  53                   push ebx
// 00545f6e  8bff                 mov edi, edi
// 00545f70  8b1e                 mov ebx, dword ptr [esi]
// 00545f72  8d4e08               lea ecx, [esi + 8]
// 00545f75  ff158ce77700         call dword ptr [0x77e78c]
// 00545f7b  56                   push esi
// 00545f7c  e86f810d00           call 0x61e0f0
// 00545f81  83c404               add esp, 4
// 00545f84  3b5f04               cmp ebx, dword ptr [edi + 4]
// 00545f87  8bf3                 mov esi, ebx
// 00545f89  75e5                 jne 0x545f70
// 00545f8b  5b                   pop ebx
// 00545f8c  5f                   pop edi
// 00545f8d  5e                   pop esi
// 00545f8e  c3                   ret 
// standard library list<string> (function ?clear@?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAEXXZ)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
