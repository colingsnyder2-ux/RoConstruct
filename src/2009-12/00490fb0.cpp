// from server: 100% by auto
// roc 2009-12 00490fb0  unit: Ogre::RbxEntity  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00490fb0
//
// 00490fb0  55                   push ebp
// 00490fb1  8b6c2408             mov ebp, dword ptr [esp + 8]
// 00490fb5  57                   push edi
// 00490fb6  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00490fba  8bc7                 mov eax, edi
// 00490fbc  8bcd                 mov ecx, ebp
// 00490fbe  85ff                 test edi, edi
// 00490fc0  7610                 jbe 0x490fd2
// 00490fc2  56                   push esi
// 00490fc3  8b742418             mov esi, dword ptr [esp + 0x18]
// 00490fc7  8a16                 mov dl, byte ptr [esi]
// 00490fc9  8811                 mov byte ptr [ecx], dl
// 00490fcb  48                   dec eax
// 00490fcc  41                   inc ecx
// 00490fcd  85c0                 test eax, eax
// 00490fcf  77f6                 ja 0x490fc7
// 00490fd1  5e                   pop esi
// 00490fd2  8d042f               lea eax, [edi + ebp]
// 00490fd5  5f                   pop edi
// 00490fd6  5d                   pop ebp
// 00490fd7  c20c00               ret 0xc
// standard library vector<char> (function ?_Ufill@?$vector@DV?$allocator@D@std@@@std@@IAEPADPADIABD@Z)

// stl: vector<char>
typedef char E;
#include <vector>
template class std::vector<E>;
