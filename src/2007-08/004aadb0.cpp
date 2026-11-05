// from server: 100% by auto
// roc 2007-08 004aadb0  unit: RBX::Network::Peer  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004aadb0
//
// 004aadb0  51                   push ecx
// 004aadb1  8b542410             mov edx, dword ptr [esp + 0x10]
// 004aadb5  56                   push esi
// 004aadb6  8b742410             mov esi, dword ptr [esp + 0x10]
// 004aadba  57                   push edi
// 004aadbb  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004aadbf  c644240800           mov byte ptr [esp + 8], 0
// 004aadc4  8b442408             mov eax, dword ptr [esp + 8]
// 004aadc8  50                   push eax
// 004aadc9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004aadcd  52                   push edx
// 004aadce  51                   push ecx
// 004aadcf  50                   push eax
// 004aadd0  56                   push esi
// 004aadd1  57                   push edi
// 004aadd2  e889e1ffff           call 0x4a8f60
// 004aadd7  8bc6                 mov eax, esi
// 004aadd9  83c418               add esp, 0x18
// 004aaddc  c1e004               shl eax, 4
// 004aaddf  03c7                 add eax, edi
// 004aade1  5f                   pop edi
// 004aade2  5e                   pop esi
// 004aade3  59                   pop ecx
// 004aade4  c20c00               ret 0xc
// standard library vector<pod16> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
