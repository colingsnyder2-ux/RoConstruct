// from server: 100% by auto
// roc 2010-06 004e3740  unit: RBX::Network::IdSerializer  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004e3740
//
// 004e3740  51                   push ecx
// 004e3741  8b542410             mov edx, dword ptr [esp + 0x10]
// 004e3745  56                   push esi
// 004e3746  8b742410             mov esi, dword ptr [esp + 0x10]
// 004e374a  57                   push edi
// 004e374b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004e374f  c644240800           mov byte ptr [esp + 8], 0
// 004e3754  8b442408             mov eax, dword ptr [esp + 8]
// 004e3758  50                   push eax
// 004e3759  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004e375d  52                   push edx
// 004e375e  83c108               add ecx, 8
// 004e3761  51                   push ecx
// 004e3762  50                   push eax
// 004e3763  56                   push esi
// 004e3764  57                   push edi
// 004e3765  e816fdffff           call 0x4e3480
// 004e376a  8d0c76               lea ecx, [esi + esi*2]
// 004e376d  83c418               add esp, 0x18
// 004e3770  8d048f               lea eax, [edi + ecx*4]
// 004e3773  5f                   pop edi
// 004e3774  5e                   pop esi
// 004e3775  59                   pop ecx
// 004e3776  c20c00               ret 0xc
// standard library vector<pod12> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
