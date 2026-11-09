// from server: 100% by auto
// roc 2008-06 00560890  unit: RBX::VContentProvider::?$DescribedNonCreatable  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00560890
//
// 00560890  51                   push ecx
// 00560891  8b542410             mov edx, dword ptr [esp + 0x10]
// 00560895  56                   push esi
// 00560896  8b742410             mov esi, dword ptr [esp + 0x10]
// 0056089a  57                   push edi
// 0056089b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0056089f  c644240800           mov byte ptr [esp + 8], 0
// 005608a4  8b442408             mov eax, dword ptr [esp + 8]
// 005608a8  50                   push eax
// 005608a9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005608ad  52                   push edx
// 005608ae  83c108               add ecx, 8
// 005608b1  51                   push ecx
// 005608b2  50                   push eax
// 005608b3  56                   push esi
// 005608b4  57                   push edi
// 005608b5  e836edffff           call 0x55f5f0
// 005608ba  8bc6                 mov eax, esi
// 005608bc  83c418               add esp, 0x18
// 005608bf  c1e005               shl eax, 5
// 005608c2  03c7                 add eax, edi
// 005608c4  5f                   pop edi
// 005608c5  5e                   pop esi
// 005608c6  59                   pop ecx
// 005608c7  c20c00               ret 0xc
// standard library vector<pod32> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod32>
struct E { int v[8]; };
#include <vector>
template class std::vector<E>;
