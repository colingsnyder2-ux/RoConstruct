// from server: 100% by auto
// roc 2010-06 00907160  unit: RBX::RbxParticleEmitter  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00907160
//
// 00907160  51                   push ecx
// 00907161  8b542410             mov edx, dword ptr [esp + 0x10]
// 00907165  56                   push esi
// 00907166  8b742410             mov esi, dword ptr [esp + 0x10]
// 0090716a  57                   push edi
// 0090716b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0090716f  c644240800           mov byte ptr [esp + 8], 0
// 00907174  8b442408             mov eax, dword ptr [esp + 8]
// 00907178  50                   push eax
// 00907179  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0090717d  52                   push edx
// 0090717e  83c108               add ecx, 8
// 00907181  51                   push ecx
// 00907182  50                   push eax
// 00907183  56                   push esi
// 00907184  57                   push edi
// 00907185  e876ffffff           call 0x907100
// 0090718a  83c418               add esp, 0x18
// 0090718d  8d04f7               lea eax, [edi + esi*8]
// 00907190  5f                   pop edi
// 00907191  5e                   pop esi
// 00907192  59                   pop ecx
// 00907193  c20c00               ret 0xc
// standard library vector<pod8> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
