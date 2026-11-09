// from server: 100% by auto
// roc 2009-06 0048aa70  unit: Ogre::FileStreamDataStream  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0048aa70
//
// 0048aa70  8b442408             mov eax, dword ptr [esp + 8]
// 0048aa74  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0048aa78  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0048aa7c  2bc1                 sub eax, ecx
// 0048aa7e  56                   push esi
// 0048aa7f  8d3410               lea esi, [eax + edx]
// 0048aa82  740d                 je 0x48aa91
// 0048aa84  50                   push eax
// 0048aa85  51                   push ecx
// 0048aa86  50                   push eax
// 0048aa87  52                   push edx
// 0048aa88  ff155ce98900         call dword ptr [0x89e95c]
// 0048aa8e  83c410               add esp, 0x10
// 0048aa91  8bc6                 mov eax, esi
// 0048aa93  5e                   pop esi
// 0048aa94  c20c00               ret 0xc
// standard library vector<char> (function ??$_Ucopy@PAD@?$vector@DV?$allocator@D@std@@@std@@IAEPADPAD00@Z)

// stl: vector<char>
typedef char E;
#include <vector>
template class std::vector<E>;
