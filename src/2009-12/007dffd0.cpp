// from server: 100% by auto
// roc 2009-12 007dffd0  unit: RBX::CircleRadialNormal  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007dffd0
//
// 007dffd0  51                   push ecx
// 007dffd1  8b542410             mov edx, dword ptr [esp + 0x10]
// 007dffd5  56                   push esi
// 007dffd6  8b742410             mov esi, dword ptr [esp + 0x10]
// 007dffda  57                   push edi
// 007dffdb  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 007dffdf  c644240800           mov byte ptr [esp + 8], 0
// 007dffe4  8b442408             mov eax, dword ptr [esp + 8]
// 007dffe8  50                   push eax
// 007dffe9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007dffed  52                   push edx
// 007dffee  83c108               add ecx, 8
// 007dfff1  51                   push ecx
// 007dfff2  50                   push eax
// 007dfff3  56                   push esi
// 007dfff4  57                   push edi
// 007dfff5  e866ffffff           call 0x7dff60
// 007dfffa  83c418               add esp, 0x18
// 007dfffd  8d04f7               lea eax, [edi + esi*8]
// 007e0000  5f                   pop edi
// 007e0001  5e                   pop esi
// 007e0002  59                   pop ecx
// 007e0003  c20c00               ret 0xc
// standard library vector<pod8> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
