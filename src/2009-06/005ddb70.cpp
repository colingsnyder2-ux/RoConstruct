// from server: 100% by auto
// roc 2009-06 005ddb70  unit: RBX::VInstance::?$NonFactoryProduct  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005ddb70
//
// 005ddb70  51                   push ecx
// 005ddb71  8b542410             mov edx, dword ptr [esp + 0x10]
// 005ddb75  56                   push esi
// 005ddb76  8b742410             mov esi, dword ptr [esp + 0x10]
// 005ddb7a  57                   push edi
// 005ddb7b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 005ddb7f  c644240800           mov byte ptr [esp + 8], 0
// 005ddb84  8b442408             mov eax, dword ptr [esp + 8]
// 005ddb88  50                   push eax
// 005ddb89  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005ddb8d  52                   push edx
// 005ddb8e  83c108               add ecx, 8
// 005ddb91  51                   push ecx
// 005ddb92  50                   push eax
// 005ddb93  56                   push esi
// 005ddb94  57                   push edi
// 005ddb95  e8c6ebffff           call 0x5dc760
// 005ddb9a  8bc6                 mov eax, esi
// 005ddb9c  83c418               add esp, 0x18
// 005ddb9f  c1e005               shl eax, 5
// 005ddba2  03c7                 add eax, edi
// 005ddba4  5f                   pop edi
// 005ddba5  5e                   pop esi
// 005ddba6  59                   pop ecx
// 005ddba7  c20c00               ret 0xc
// standard library vector<pod32> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod32>
struct E { int v[8]; };
#include <vector>
template class std::vector<E>;
