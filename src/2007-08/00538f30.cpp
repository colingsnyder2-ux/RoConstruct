// from server: 100% by auto
// roc 2007-08 00538f30  unit: RBX::VScriptContext::?$FactoryProduct  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00538f30
//
// 00538f30  51                   push ecx
// 00538f31  8b542410             mov edx, dword ptr [esp + 0x10]
// 00538f35  56                   push esi
// 00538f36  8b742410             mov esi, dword ptr [esp + 0x10]
// 00538f3a  57                   push edi
// 00538f3b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00538f3f  c644240800           mov byte ptr [esp + 8], 0
// 00538f44  8b442408             mov eax, dword ptr [esp + 8]
// 00538f48  50                   push eax
// 00538f49  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00538f4d  52                   push edx
// 00538f4e  51                   push ecx
// 00538f4f  50                   push eax
// 00538f50  56                   push esi
// 00538f51  57                   push edi
// 00538f52  e8494cedff           call 0x40dba0
// 00538f57  83c418               add esp, 0x18
// 00538f5a  8d04f7               lea eax, [edi + esi*8]
// 00538f5d  5f                   pop edi
// 00538f5e  5e                   pop esi
// 00538f5f  59                   pop ecx
// 00538f60  c20c00               ret 0xc
// standard library vector<pod8> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
