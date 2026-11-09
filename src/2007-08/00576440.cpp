// from server: 100% by auto
// roc 2007-08 00576440  unit: RBX::VPartInstance::?$Notifier  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00576440
//
// 00576440  51                   push ecx
// 00576441  8b542410             mov edx, dword ptr [esp + 0x10]
// 00576445  56                   push esi
// 00576446  8b742410             mov esi, dword ptr [esp + 0x10]
// 0057644a  57                   push edi
// 0057644b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0057644f  c644240800           mov byte ptr [esp + 8], 0
// 00576454  8b442408             mov eax, dword ptr [esp + 8]
// 00576458  50                   push eax
// 00576459  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0057645d  52                   push edx
// 0057645e  51                   push ecx
// 0057645f  50                   push eax
// 00576460  56                   push esi
// 00576461  57                   push edi
// 00576462  e859fdffff           call 0x5761c0
// 00576467  83c418               add esp, 0x18
// 0057646a  8d04f7               lea eax, [edi + esi*8]
// 0057646d  5f                   pop edi
// 0057646e  5e                   pop esi
// 0057646f  59                   pop ecx
// 00576470  c20c00               ret 0xc
// standard library vector<pod8> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
