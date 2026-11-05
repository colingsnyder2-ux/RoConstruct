// from server: 100% by auto
// roc 2012-06 004ec4c0  unit: Ogre::RbxEntity  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004ec4c0
//
// 004ec4c0  8b442408             mov eax, dword ptr [esp + 8]
// 004ec4c4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004ec4c8  8b54240c             mov edx, dword ptr [esp + 0xc]
// 004ec4cc  2bc1                 sub eax, ecx
// 004ec4ce  56                   push esi
// 004ec4cf  8d3410               lea esi, [eax + edx]
// 004ec4d2  740d                 je 0x4ec4e1
// 004ec4d4  50                   push eax
// 004ec4d5  51                   push ecx
// 004ec4d6  50                   push eax
// 004ec4d7  52                   push edx
// 004ec4d8  ff15c02ab200         call dword ptr [0xb22ac0]
// 004ec4de  83c410               add esp, 0x10
// 004ec4e1  8bc6                 mov eax, esi
// 004ec4e3  5e                   pop esi
// 004ec4e4  c20c00               ret 0xc
// standard library vector<char> (function ??$_Ucopy@PAD@?$vector@DV?$allocator@D@std@@@std@@IAEPADPAD00@Z)

// stl: vector<char>
typedef char E;
#include <vector>
template class std::vector<E>;
