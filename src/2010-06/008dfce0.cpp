// from server: 100% by auto
// roc 2010-06 008dfce0  unit: Ogre::RbxMaterialAdapter  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008dfce0
//
// 008dfce0  53                   push ebx
// 008dfce1  8b1d0ca99e00         mov ebx, dword ptr [0x9ea90c]
// 008dfce7  56                   push esi
// 008dfce8  8b31                 mov esi, dword ptr [ecx]
// 008dfcea  57                   push edi
// 008dfceb  8b7904               mov edi, dword ptr [ecx + 4]
// 008dfcee  85f6                 test esi, esi
// 008dfcf0  751b                 jne 0x8dfd0d
// 008dfcf2  ffd3                 call ebx
// 008dfcf4  33c9                 xor ecx, ecx
// 008dfcf6  8b442414             mov eax, dword ptr [esp + 0x14]
// 008dfcfa  8d0440               lea eax, [eax + eax*2]
// 008dfcfd  8d3c87               lea edi, [edi + eax*4]
// 008dfd00  3b7910               cmp edi, dword ptr [ecx + 0x10]
// 008dfd03  7713                 ja 0x8dfd18
// 008dfd05  85f6                 test esi, esi
// 008dfd07  7408                 je 0x8dfd11
// 008dfd09  8b06                 mov eax, dword ptr [esi]
// 008dfd0b  eb06                 jmp 0x8dfd13
// 008dfd0d  8b0e                 mov ecx, dword ptr [esi]
// 008dfd0f  ebe5                 jmp 0x8dfcf6
// 008dfd11  33c0                 xor eax, eax
// 008dfd13  3b780c               cmp edi, dword ptr [eax + 0xc]
// 008dfd16  7302                 jae 0x8dfd1a
// 008dfd18  ffd3                 call ebx
// 008dfd1a  8b442410             mov eax, dword ptr [esp + 0x10]
// 008dfd1e  897804               mov dword ptr [eax + 4], edi
// 008dfd21  5f                   pop edi
// 008dfd22  8930                 mov dword ptr [eax], esi
// 008dfd24  5e                   pop esi
// 008dfd25  5b                   pop ebx
// 008dfd26  c20800               ret 8
// standard library vector<pod12> (function ??H?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@std@@QBE?AV01@H@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
