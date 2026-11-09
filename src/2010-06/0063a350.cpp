// from server: 100% by auto
// roc 2010-06 0063a350  unit: RBX::PartInstance  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0063a350
//
// 0063a350  51                   push ecx
// 0063a351  8b542410             mov edx, dword ptr [esp + 0x10]
// 0063a355  56                   push esi
// 0063a356  8b742410             mov esi, dword ptr [esp + 0x10]
// 0063a35a  57                   push edi
// 0063a35b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0063a35f  c644240800           mov byte ptr [esp + 8], 0
// 0063a364  8b442408             mov eax, dword ptr [esp + 8]
// 0063a368  50                   push eax
// 0063a369  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0063a36d  52                   push edx
// 0063a36e  83c108               add ecx, 8
// 0063a371  51                   push ecx
// 0063a372  50                   push eax
// 0063a373  56                   push esi
// 0063a374  57                   push edi
// 0063a375  e8a6961200           call 0x763a20
// 0063a37a  83c418               add esp, 0x18
// 0063a37d  8d04f7               lea eax, [edi + esi*8]
// 0063a380  5f                   pop edi
// 0063a381  5e                   pop esi
// 0063a382  59                   pop ecx
// 0063a383  c20c00               ret 0xc
// standard library vector<pod8> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
