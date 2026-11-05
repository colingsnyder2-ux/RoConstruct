// from server: 100% by auto
// roc 2012-06 004ec730  unit: Ogre::RbxEntity  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004ec730
//
// 004ec730  55                   push ebp
// 004ec731  8b6c2408             mov ebp, dword ptr [esp + 8]
// 004ec735  57                   push edi
// 004ec736  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004ec73a  8bc7                 mov eax, edi
// 004ec73c  8bcd                 mov ecx, ebp
// 004ec73e  85ff                 test edi, edi
// 004ec740  7610                 jbe 0x4ec752
// 004ec742  56                   push esi
// 004ec743  8b742418             mov esi, dword ptr [esp + 0x18]
// 004ec747  8a16                 mov dl, byte ptr [esi]
// 004ec749  8811                 mov byte ptr [ecx], dl
// 004ec74b  48                   dec eax
// 004ec74c  41                   inc ecx
// 004ec74d  85c0                 test eax, eax
// 004ec74f  77f6                 ja 0x4ec747
// 004ec751  5e                   pop esi
// 004ec752  8d042f               lea eax, [edi + ebp]
// 004ec755  5f                   pop edi
// 004ec756  5d                   pop ebp
// 004ec757  c20c00               ret 0xc
// standard library vector<char> (function ?_Ufill@?$vector@DV?$allocator@D@std@@@std@@IAEPADPADIABD@Z)

// stl: vector<char>
typedef char E;
#include <vector>
template class std::vector<E>;
