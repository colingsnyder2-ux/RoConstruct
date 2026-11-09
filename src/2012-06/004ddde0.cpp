// roc 2012-06 004ddde0  unit: Ogre::VertexStreamer  size: 87 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004ddde0
//
// 004ddde0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004ddde4  83ec0c               sub esp, 0xc
// 004ddde7  85c9                 test ecx, ecx
// 004ddde9  7712                 ja 0x4dddfd
// 004dddeb  33c9                 xor ecx, ecx
// 004ddded  c1e106               shl ecx, 6
// 004dddf0  51                   push ecx
// 004dddf1  e824434a00           call 0x98211a
// 004dddf6  83c404               add esp, 4
// 004dddf9  83c40c               add esp, 0xc
// 004dddfc  c3                   ret 
// 004dddfd  83c8ff               or eax, 0xffffffff
// 004dde00  33d2                 xor edx, edx
// 004dde02  f7f1                 div ecx
// 004dde04  83f840               cmp eax, 0x40
// 004dde07  73e4                 jae 0x4ddded
// 004dde09  8d442410             lea eax, [esp + 0x10]
// 004dde0d  50                   push eax
// 004dde0e  8d4c2404             lea ecx, [esp + 4]
// 004dde12  c744241400000000     mov dword ptr [esp + 0x14], 0
// 004dde1a  ff15d029b200         call dword ptr [0xb229d0]
// 004dde20  685861cd00           push 0xcd6158
// 004dde25  8d4c2404             lea ecx, [esp + 4]
// 004dde29  51                   push ecx
// 004dde2a  c7442408942eb400     mov dword ptr [esp + 8], 0xb42e94
// 004dde32  e80d534a00           call 0x983144
// standard library vector<pod64> (function ??$_Allocate@UE@@@std@@YAPAUE@@IPAU1@@Z)

// stl: vector<pod64>
struct E { int v[16]; };
#include <vector>
template class std::vector<E>;
