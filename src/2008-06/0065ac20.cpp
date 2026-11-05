// from server: 100% by auto
// roc 2008-06 0065ac20  unit: RBX::BallBallContact  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0065ac20
//
// 0065ac20  51                   push ecx
// 0065ac21  8b542410             mov edx, dword ptr [esp + 0x10]
// 0065ac25  56                   push esi
// 0065ac26  8b742410             mov esi, dword ptr [esp + 0x10]
// 0065ac2a  57                   push edi
// 0065ac2b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0065ac2f  c644240800           mov byte ptr [esp + 8], 0
// 0065ac34  8b442408             mov eax, dword ptr [esp + 8]
// 0065ac38  50                   push eax
// 0065ac39  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0065ac3d  52                   push edx
// 0065ac3e  83c108               add ecx, 8
// 0065ac41  51                   push ecx
// 0065ac42  50                   push eax
// 0065ac43  56                   push esi
// 0065ac44  57                   push edi
// 0065ac45  e8d61d0200           call 0x67ca20
// 0065ac4a  83c418               add esp, 0x18
// 0065ac4d  8d04f7               lea eax, [edi + esi*8]
// 0065ac50  5f                   pop edi
// 0065ac51  5e                   pop esi
// 0065ac52  59                   pop ecx
// 0065ac53  c20c00               ret 0xc
// standard library vector<pod8> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
