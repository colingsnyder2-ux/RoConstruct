// from server: 100% by auto
// roc 2009-12 004c0cc0  unit: RBX::RbxParticleEmitter  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004c0cc0
//
// 004c0cc0  51                   push ecx
// 004c0cc1  8b542410             mov edx, dword ptr [esp + 0x10]
// 004c0cc5  56                   push esi
// 004c0cc6  8b742410             mov esi, dword ptr [esp + 0x10]
// 004c0cca  57                   push edi
// 004c0ccb  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004c0ccf  c644240800           mov byte ptr [esp + 8], 0
// 004c0cd4  8b442408             mov eax, dword ptr [esp + 8]
// 004c0cd8  50                   push eax
// 004c0cd9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004c0cdd  52                   push edx
// 004c0cde  83c108               add ecx, 8
// 004c0ce1  51                   push ecx
// 004c0ce2  50                   push eax
// 004c0ce3  56                   push esi
// 004c0ce4  57                   push edi
// 004c0ce5  e876ffffff           call 0x4c0c60
// 004c0cea  83c418               add esp, 0x18
// 004c0ced  8d04f7               lea eax, [edi + esi*8]
// 004c0cf0  5f                   pop edi
// 004c0cf1  5e                   pop esi
// 004c0cf2  59                   pop ecx
// 004c0cf3  c20c00               ret 0xc
// standard library vector<pod8> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
