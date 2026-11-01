// from server: 100% by auto
// roc 2009-12 00535430  unit: RBX::Network::IdSerializer  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00535430
//
// 00535430  51                   push ecx
// 00535431  8b542410             mov edx, dword ptr [esp + 0x10]
// 00535435  56                   push esi
// 00535436  8b742410             mov esi, dword ptr [esp + 0x10]
// 0053543a  57                   push edi
// 0053543b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0053543f  c644240800           mov byte ptr [esp + 8], 0
// 00535444  8b442408             mov eax, dword ptr [esp + 8]
// 00535448  50                   push eax
// 00535449  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0053544d  52                   push edx
// 0053544e  83c108               add ecx, 8
// 00535451  51                   push ecx
// 00535452  50                   push eax
// 00535453  56                   push esi
// 00535454  57                   push edi
// 00535455  e816fdffff           call 0x535170
// 0053545a  8d0c76               lea ecx, [esi + esi*2]
// 0053545d  83c418               add esp, 0x18
// 00535460  8d048f               lea eax, [edi + ecx*4]
// 00535463  5f                   pop edi
// 00535464  5e                   pop esi
// 00535465  59                   pop ecx
// 00535466  c20c00               ret 0xc
// standard library vector<pod12> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
