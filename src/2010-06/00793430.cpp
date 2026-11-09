// from server: 100% by auto
// roc 2010-06 00793430  unit: RBX::CircleRadialNormal  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00793430
//
// 00793430  51                   push ecx
// 00793431  8b542410             mov edx, dword ptr [esp + 0x10]
// 00793435  56                   push esi
// 00793436  8b742410             mov esi, dword ptr [esp + 0x10]
// 0079343a  57                   push edi
// 0079343b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0079343f  c644240800           mov byte ptr [esp + 8], 0
// 00793444  8b442408             mov eax, dword ptr [esp + 8]
// 00793448  50                   push eax
// 00793449  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0079344d  52                   push edx
// 0079344e  83c108               add ecx, 8
// 00793451  51                   push ecx
// 00793452  50                   push eax
// 00793453  56                   push esi
// 00793454  57                   push edi
// 00793455  e866ffffff           call 0x7933c0
// 0079345a  83c418               add esp, 0x18
// 0079345d  8d04f7               lea eax, [edi + esi*8]
// 00793460  5f                   pop edi
// 00793461  5e                   pop esi
// 00793462  59                   pop ecx
// 00793463  c20c00               ret 0xc
// standard library vector<pod8> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
