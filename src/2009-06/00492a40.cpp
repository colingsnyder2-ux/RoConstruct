// from server: 100% by auto
// roc 2009-06 00492a40  unit: Ogre::RbxMaterialAdapter  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00492a40
//
// 00492a40  83ec08               sub esp, 8
// 00492a43  53                   push ebx
// 00492a44  8b1dace98900         mov ebx, dword ptr [0x89e9ac]
// 00492a4a  56                   push esi
// 00492a4b  8bf1                 mov esi, ecx
// 00492a4d  57                   push edi
// 00492a4e  8b7e10               mov edi, dword ptr [esi + 0x10]
// 00492a51  397e0c               cmp dword ptr [esi + 0xc], edi
// 00492a54  7602                 jbe 0x492a58
// 00492a56  ffd3                 call ebx
// 00492a58  8b36                 mov esi, dword ptr [esi]
// 00492a5a  6aff                 push -1
// 00492a5c  8d4c2410             lea ecx, [esp + 0x10]
// 00492a60  89742410             mov dword ptr [esp + 0x10], esi
// 00492a64  897c2414             mov dword ptr [esp + 0x14], edi
// 00492a68  e873e1ffff           call 0x490be0
// 00492a6d  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00492a71  85c0                 test eax, eax
// 00492a73  7518                 jne 0x492a8d
// 00492a75  ffd3                 call ebx
// 00492a77  33c0                 xor eax, eax
// 00492a79  8b742410             mov esi, dword ptr [esp + 0x10]
// 00492a7d  3b7010               cmp esi, dword ptr [eax + 0x10]
// 00492a80  7202                 jb 0x492a84
// 00492a82  ffd3                 call ebx
// 00492a84  5f                   pop edi
// 00492a85  8bc6                 mov eax, esi
// 00492a87  5e                   pop esi
// 00492a88  5b                   pop ebx
// 00492a89  83c408               add esp, 8
// 00492a8c  c3                   ret 
// 00492a8d  8b00                 mov eax, dword ptr [eax]
// 00492a8f  ebe8                 jmp 0x492a79
// standard library vector<string> (function ?back@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAEAAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@XZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
