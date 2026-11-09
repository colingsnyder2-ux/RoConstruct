// from server: 100% by auto
// roc 2009-12 00413bf0  unit: CopyVerb  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00413bf0
//
// 00413bf0  53                   push ebx
// 00413bf1  56                   push esi
// 00413bf2  8bf1                 mov esi, ecx
// 00413bf4  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 00413bf7  57                   push edi
// 00413bf8  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00413bfc  c70700000000         mov dword ptr [edi], 0
// 00413c02  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 00413c05  7606                 jbe 0x413c0d
// 00413c07  ff1560b79800         call dword ptr [0x98b760]
// 00413c0d  8b06                 mov eax, dword ptr [esi]
// 00413c0f  8907                 mov dword ptr [edi], eax
// 00413c11  895f04               mov dword ptr [edi + 4], ebx
// 00413c14  8bc7                 mov eax, edi
// 00413c16  5f                   pop edi
// 00413c17  5e                   pop esi
// 00413c18  5b                   pop ebx
// 00413c19  c20400               ret 4
// standard library vector<ptr> (function ?begin@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Vector_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@XZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
