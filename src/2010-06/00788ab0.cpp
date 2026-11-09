// from server: 100% by auto
// roc 2010-06 00788ab0  unit: RBX::HUMAN::GettingUp  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00788ab0
//
// 00788ab0  51                   push ecx
// 00788ab1  8b542410             mov edx, dword ptr [esp + 0x10]
// 00788ab5  56                   push esi
// 00788ab6  8b742410             mov esi, dword ptr [esp + 0x10]
// 00788aba  57                   push edi
// 00788abb  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00788abf  c644240800           mov byte ptr [esp + 8], 0
// 00788ac4  8b442408             mov eax, dword ptr [esp + 8]
// 00788ac8  50                   push eax
// 00788ac9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00788acd  52                   push edx
// 00788ace  83c108               add ecx, 8
// 00788ad1  51                   push ecx
// 00788ad2  50                   push eax
// 00788ad3  56                   push esi
// 00788ad4  57                   push edi
// 00788ad5  e846fbffff           call 0x788620
// 00788ada  8d0cb6               lea ecx, [esi + esi*4]
// 00788add  83c418               add esp, 0x18
// 00788ae0  8d04cf               lea eax, [edi + ecx*8]
// 00788ae3  5f                   pop edi
// 00788ae4  5e                   pop esi
// 00788ae5  59                   pop ecx
// 00788ae6  c20c00               ret 0xc
// standard library vector<pod40> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod40>
struct E { int v[10]; };
#include <vector>
template class std::vector<E>;
