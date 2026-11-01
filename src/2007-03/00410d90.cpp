// from server: 100% by auto
// roc 2007-03 00410d90  unit: seg_00410000  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00410d90
//
// 00410d90  51                   push ecx
// 00410d91  8b542410             mov edx, dword ptr [esp + 0x10]
// 00410d95  56                   push esi
// 00410d96  8b742410             mov esi, dword ptr [esp + 0x10]
// 00410d9a  57                   push edi
// 00410d9b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00410d9f  c644240800           mov byte ptr [esp + 8], 0
// 00410da4  8b442408             mov eax, dword ptr [esp + 8]
// 00410da8  50                   push eax
// 00410da9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00410dad  52                   push edx
// 00410dae  51                   push ecx
// 00410daf  50                   push eax
// 00410db0  56                   push esi
// 00410db1  57                   push edi
// 00410db2  e8a9fdffff           call 0x410b60
// 00410db7  8d0cf6               lea ecx, [esi + esi*8]
// 00410dba  83c418               add esp, 0x18
// 00410dbd  8d048f               lea eax, [edi + ecx*4]
// 00410dc0  5f                   pop edi
// 00410dc1  5e                   pop esi
// 00410dc2  59                   pop ecx
// 00410dc3  c20c00               ret 0xc
// standard library vector<pod36> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod36>
struct E { int v[9]; };
#include <vector>
template class std::vector<E>;
