// from server: 100% by auto
// roc 2010-06 008d2e60  unit: Ogre::VisualEngine  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008d2e60
//
// 008d2e60  51                   push ecx
// 008d2e61  8b542410             mov edx, dword ptr [esp + 0x10]
// 008d2e65  56                   push esi
// 008d2e66  8b742410             mov esi, dword ptr [esp + 0x10]
// 008d2e6a  57                   push edi
// 008d2e6b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 008d2e6f  c644240800           mov byte ptr [esp + 8], 0
// 008d2e74  8b442408             mov eax, dword ptr [esp + 8]
// 008d2e78  50                   push eax
// 008d2e79  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008d2e7d  52                   push edx
// 008d2e7e  83c108               add ecx, 8
// 008d2e81  51                   push ecx
// 008d2e82  50                   push eax
// 008d2e83  56                   push esi
// 008d2e84  57                   push edi
// 008d2e85  e8d6fdffff           call 0x8d2c60
// 008d2e8a  8d0c76               lea ecx, [esi + esi*2]
// 008d2e8d  83c418               add esp, 0x18
// 008d2e90  8d04cf               lea eax, [edi + ecx*8]
// 008d2e93  5f                   pop edi
// 008d2e94  5e                   pop esi
// 008d2e95  59                   pop ecx
// 008d2e96  c20c00               ret 0xc
// standard library vector<pod24> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
