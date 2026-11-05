// from server: 100% by auto
// roc 2009-06 0048ac10  unit: Ogre::RbxManualResourceLoaderChain  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0048ac10
//
// 0048ac10  55                   push ebp
// 0048ac11  8b6c2408             mov ebp, dword ptr [esp + 8]
// 0048ac15  57                   push edi
// 0048ac16  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0048ac1a  8bc7                 mov eax, edi
// 0048ac1c  8bcd                 mov ecx, ebp
// 0048ac1e  85ff                 test edi, edi
// 0048ac20  7610                 jbe 0x48ac32
// 0048ac22  56                   push esi
// 0048ac23  8b742418             mov esi, dword ptr [esp + 0x18]
// 0048ac27  8a16                 mov dl, byte ptr [esi]
// 0048ac29  8811                 mov byte ptr [ecx], dl
// 0048ac2b  48                   dec eax
// 0048ac2c  41                   inc ecx
// 0048ac2d  85c0                 test eax, eax
// 0048ac2f  77f6                 ja 0x48ac27
// 0048ac31  5e                   pop esi
// 0048ac32  8d042f               lea eax, [edi + ebp]
// 0048ac35  5f                   pop edi
// 0048ac36  5d                   pop ebp
// 0048ac37  c20c00               ret 0xc
// standard library vector<char> (function ?_Ufill@?$vector@DV?$allocator@D@std@@@std@@IAEPADPADIABD@Z)

// stl: vector<char>
typedef char E;
#include <vector>
template class std::vector<E>;
