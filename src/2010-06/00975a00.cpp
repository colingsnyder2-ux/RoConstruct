// from server: 100% by auto
// roc 2010-06 00975a00  unit: RBX::RightAngleRampBuilder  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00975a00
//
// 00975a00  51                   push ecx
// 00975a01  8b542410             mov edx, dword ptr [esp + 0x10]
// 00975a05  56                   push esi
// 00975a06  8b742410             mov esi, dword ptr [esp + 0x10]
// 00975a0a  57                   push edi
// 00975a0b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00975a0f  c644240800           mov byte ptr [esp + 8], 0
// 00975a14  8b442408             mov eax, dword ptr [esp + 8]
// 00975a18  50                   push eax
// 00975a19  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00975a1d  52                   push edx
// 00975a1e  83c108               add ecx, 8
// 00975a21  51                   push ecx
// 00975a22  50                   push eax
// 00975a23  56                   push esi
// 00975a24  57                   push edi
// 00975a25  e836ffffff           call 0x975960
// 00975a2a  8bc6                 mov eax, esi
// 00975a2c  83c418               add esp, 0x18
// 00975a2f  c1e004               shl eax, 4
// 00975a32  03c7                 add eax, edi
// 00975a34  5f                   pop edi
// 00975a35  5e                   pop esi
// 00975a36  59                   pop ecx
// 00975a37  c20c00               ret 0xc
// standard library vector<pod16> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
