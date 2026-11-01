// from server: 100% by auto
// roc 2009-12 004b5230  unit: Ogre::RbxMaterialAdapter  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004b5230
//
// 004b5230  83ec08               sub esp, 8
// 004b5233  53                   push ebx
// 004b5234  8b1d60b79800         mov ebx, dword ptr [0x98b760]
// 004b523a  56                   push esi
// 004b523b  8bf1                 mov esi, ecx
// 004b523d  57                   push edi
// 004b523e  8b7e10               mov edi, dword ptr [esi + 0x10]
// 004b5241  397e0c               cmp dword ptr [esi + 0xc], edi
// 004b5244  7602                 jbe 0x4b5248
// 004b5246  ffd3                 call ebx
// 004b5248  8b36                 mov esi, dword ptr [esi]
// 004b524a  6aff                 push -1
// 004b524c  8d4c2410             lea ecx, [esp + 0x10]
// 004b5250  89742410             mov dword ptr [esp + 0x10], esi
// 004b5254  897c2414             mov dword ptr [esp + 0x14], edi
// 004b5258  e8f3e0ffff           call 0x4b3350
// 004b525d  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004b5261  85c0                 test eax, eax
// 004b5263  7518                 jne 0x4b527d
// 004b5265  ffd3                 call ebx
// 004b5267  33c0                 xor eax, eax
// 004b5269  8b742410             mov esi, dword ptr [esp + 0x10]
// 004b526d  3b7010               cmp esi, dword ptr [eax + 0x10]
// 004b5270  7202                 jb 0x4b5274
// 004b5272  ffd3                 call ebx
// 004b5274  5f                   pop edi
// 004b5275  8bc6                 mov eax, esi
// 004b5277  5e                   pop esi
// 004b5278  5b                   pop ebx
// 004b5279  83c408               add esp, 8
// 004b527c  c3                   ret 
// 004b527d  8b00                 mov eax, dword ptr [eax]
// 004b527f  ebe8                 jmp 0x4b5269
// standard library vector<string> (function ?back@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAEAAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@XZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
