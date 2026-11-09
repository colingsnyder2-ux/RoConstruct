// from server: 100% by auto
// roc 2010-06 008dd300  unit: Ogre::RbxMaterialAdapter  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008dd300
//
// 008dd300  83ec08               sub esp, 8
// 008dd303  53                   push ebx
// 008dd304  8b1d0ca99e00         mov ebx, dword ptr [0x9ea90c]
// 008dd30a  56                   push esi
// 008dd30b  8bf1                 mov esi, ecx
// 008dd30d  57                   push edi
// 008dd30e  8b7e10               mov edi, dword ptr [esi + 0x10]
// 008dd311  397e0c               cmp dword ptr [esi + 0xc], edi
// 008dd314  7602                 jbe 0x8dd318
// 008dd316  ffd3                 call ebx
// 008dd318  8b36                 mov esi, dword ptr [esi]
// 008dd31a  6aff                 push -1
// 008dd31c  8d4c2410             lea ecx, [esp + 0x10]
// 008dd320  89742410             mov dword ptr [esp + 0x10], esi
// 008dd324  897c2414             mov dword ptr [esp + 0x14], edi
// 008dd328  e8e37a0100           call 0x8f4e10
// 008dd32d  8b44240c             mov eax, dword ptr [esp + 0xc]
// 008dd331  85c0                 test eax, eax
// 008dd333  7518                 jne 0x8dd34d
// 008dd335  ffd3                 call ebx
// 008dd337  33c0                 xor eax, eax
// 008dd339  8b742410             mov esi, dword ptr [esp + 0x10]
// 008dd33d  3b7010               cmp esi, dword ptr [eax + 0x10]
// 008dd340  7202                 jb 0x8dd344
// 008dd342  ffd3                 call ebx
// 008dd344  5f                   pop edi
// 008dd345  8bc6                 mov eax, esi
// 008dd347  5e                   pop esi
// 008dd348  5b                   pop ebx
// 008dd349  83c408               add esp, 8
// 008dd34c  c3                   ret 
// 008dd34d  8b00                 mov eax, dword ptr [eax]
// 008dd34f  ebe8                 jmp 0x8dd339
// standard library vector<string> (function ?back@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAEAAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@XZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
