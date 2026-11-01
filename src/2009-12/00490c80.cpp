// from server: 100% by auto
// roc 2009-12 00490c80  unit: Ogre::RbxEntity  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00490c80
//
// 00490c80  8b442408             mov eax, dword ptr [esp + 8]
// 00490c84  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00490c88  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00490c8c  2bc1                 sub eax, ecx
// 00490c8e  56                   push esi
// 00490c8f  8d3410               lea esi, [eax + edx]
// 00490c92  740d                 je 0x490ca1
// 00490c94  50                   push eax
// 00490c95  51                   push ecx
// 00490c96  50                   push eax
// 00490c97  52                   push edx
// 00490c98  ff15c0b79800         call dword ptr [0x98b7c0]
// 00490c9e  83c410               add esp, 0x10
// 00490ca1  8bc6                 mov eax, esi
// 00490ca3  5e                   pop esi
// 00490ca4  c20c00               ret 0xc
// standard library vector<char> (function ??$_Ucopy@PAD@?$vector@DV?$allocator@D@std@@@std@@IAEPADPAD00@Z)

// stl: vector<char>
typedef char E;
#include <vector>
template class std::vector<E>;
