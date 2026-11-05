// from server: 100% by auto
// roc 2010-06 00611690  unit: RBX::VScriptContext::?$FactoryProduct  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00611690
//
// 00611690  51                   push ecx
// 00611691  8b542410             mov edx, dword ptr [esp + 0x10]
// 00611695  56                   push esi
// 00611696  8b742410             mov esi, dword ptr [esp + 0x10]
// 0061169a  57                   push edi
// 0061169b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0061169f  c644240800           mov byte ptr [esp + 8], 0
// 006116a4  8b442408             mov eax, dword ptr [esp + 8]
// 006116a8  50                   push eax
// 006116a9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006116ad  52                   push edx
// 006116ae  83c108               add ecx, 8
// 006116b1  51                   push ecx
// 006116b2  50                   push eax
// 006116b3  56                   push esi
// 006116b4  57                   push edi
// 006116b5  e866c91800           call 0x79e020
// 006116ba  83c418               add esp, 0x18
// 006116bd  8d04f7               lea eax, [edi + esi*8]
// 006116c0  5f                   pop edi
// 006116c1  5e                   pop esi
// 006116c2  59                   pop ecx
// 006116c3  c20c00               ret 0xc
// standard library vector<pod8> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
