// from server: 100% by auto
// roc 2010-06 00741040  unit: RBX::VHttp::?$sp_counted_impl_p  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00741040
//
// 00741040  56                   push esi
// 00741041  57                   push edi
// 00741042  8bf9                 mov edi, ecx
// 00741044  8b4714               mov eax, dword ptr [edi + 0x14]
// 00741047  8b30                 mov esi, dword ptr [eax]
// 00741049  8900                 mov dword ptr [eax], eax
// 0074104b  8b4714               mov eax, dword ptr [edi + 0x14]
// 0074104e  894004               mov dword ptr [eax + 4], eax
// 00741051  c7471800000000       mov dword ptr [edi + 0x18], 0
// 00741058  3b7714               cmp esi, dword ptr [edi + 0x14]
// 0074105b  741f                 je 0x74107c
// 0074105d  53                   push ebx
// 0074105e  8bff                 mov edi, edi
// 00741060  8b1e                 mov ebx, dword ptr [esi]
// 00741062  8d4e08               lea ecx, [esi + 8]
// 00741065  ff1500a49e00         call dword ptr [0x9ea400]
// 0074106b  56                   push esi
// 0074106c  e829690600           call 0x7a799a
// 00741071  83c404               add esp, 4
// 00741074  8bf3                 mov esi, ebx
// 00741076  3b5f14               cmp ebx, dword ptr [edi + 0x14]
// 00741079  75e5                 jne 0x741060
// 0074107b  5b                   pop ebx
// 0074107c  5f                   pop edi
// 0074107d  5e                   pop esi
// 0074107e  c3                   ret 
// standard library list<string> (function ?clear@?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAEXXZ)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
