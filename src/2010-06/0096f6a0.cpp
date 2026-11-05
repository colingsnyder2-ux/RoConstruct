// from server: 100% by auto
// roc 2010-06 0096f6a0  unit: seg_00960000  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0096f6a0
//
// 0096f6a0  51                   push ecx
// 0096f6a1  8b542410             mov edx, dword ptr [esp + 0x10]
// 0096f6a5  56                   push esi
// 0096f6a6  8b742410             mov esi, dword ptr [esp + 0x10]
// 0096f6aa  57                   push edi
// 0096f6ab  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0096f6af  c644240800           mov byte ptr [esp + 8], 0
// 0096f6b4  8b442408             mov eax, dword ptr [esp + 8]
// 0096f6b8  50                   push eax
// 0096f6b9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0096f6bd  52                   push edx
// 0096f6be  83c108               add ecx, 8
// 0096f6c1  51                   push ecx
// 0096f6c2  50                   push eax
// 0096f6c3  56                   push esi
// 0096f6c4  57                   push edi
// 0096f6c5  e86606f7ff           call 0x8dfd30
// 0096f6ca  8d0c76               lea ecx, [esi + esi*2]
// 0096f6cd  83c418               add esp, 0x18
// 0096f6d0  8d048f               lea eax, [edi + ecx*4]
// 0096f6d3  5f                   pop edi
// 0096f6d4  5e                   pop esi
// 0096f6d5  59                   pop ecx
// 0096f6d6  c20c00               ret 0xc
// standard library vector<pod12> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
