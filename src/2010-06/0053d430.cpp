// from server: 100% by auto
// roc 2010-06 0053d430  unit: RBX::ImmediateMeshGenAdapter  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0053d430
//
// 0053d430  51                   push ecx
// 0053d431  8b542410             mov edx, dword ptr [esp + 0x10]
// 0053d435  56                   push esi
// 0053d436  8b742410             mov esi, dword ptr [esp + 0x10]
// 0053d43a  57                   push edi
// 0053d43b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0053d43f  c644240800           mov byte ptr [esp + 8], 0
// 0053d444  8b442408             mov eax, dword ptr [esp + 8]
// 0053d448  50                   push eax
// 0053d449  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0053d44d  52                   push edx
// 0053d44e  83c108               add ecx, 8
// 0053d451  51                   push ecx
// 0053d452  50                   push eax
// 0053d453  56                   push esi
// 0053d454  57                   push edi
// 0053d455  e856ffffff           call 0x53d3b0
// 0053d45a  8d0c76               lea ecx, [esi + esi*2]
// 0053d45d  83c418               add esp, 0x18
// 0053d460  8d04cf               lea eax, [edi + ecx*8]
// 0053d463  5f                   pop edi
// 0053d464  5e                   pop esi
// 0053d465  59                   pop ecx
// 0053d466  c20c00               ret 0xc
// standard library vector<pod24> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
