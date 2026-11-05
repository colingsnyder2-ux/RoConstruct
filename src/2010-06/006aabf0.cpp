// from server: 100% by auto
// roc 2010-06 006aabf0  unit: boost::Vthread::?$sp_counted_impl_p  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006aabf0
//
// 006aabf0  83ec08               sub esp, 8
// 006aabf3  53                   push ebx
// 006aabf4  8b1d0ca99e00         mov ebx, dword ptr [0x9ea90c]
// 006aabfa  56                   push esi
// 006aabfb  8bf1                 mov esi, ecx
// 006aabfd  57                   push edi
// 006aabfe  8b7e10               mov edi, dword ptr [esi + 0x10]
// 006aac01  397e0c               cmp dword ptr [esi + 0xc], edi
// 006aac04  7602                 jbe 0x6aac08
// 006aac06  ffd3                 call ebx
// 006aac08  8b36                 mov esi, dword ptr [esi]
// 006aac0a  6aff                 push -1
// 006aac0c  8d4c2410             lea ecx, [esp + 0x10]
// 006aac10  89742410             mov dword ptr [esp + 0x10], esi
// 006aac14  897c2414             mov dword ptr [esp + 0x14], edi
// 006aac18  e843f6ffff           call 0x6aa260
// 006aac1d  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006aac21  85c0                 test eax, eax
// 006aac23  7518                 jne 0x6aac3d
// 006aac25  ffd3                 call ebx
// 006aac27  33c0                 xor eax, eax
// 006aac29  8b742410             mov esi, dword ptr [esp + 0x10]
// 006aac2d  3b7010               cmp esi, dword ptr [eax + 0x10]
// 006aac30  7202                 jb 0x6aac34
// 006aac32  ffd3                 call ebx
// 006aac34  5f                   pop edi
// 006aac35  8bc6                 mov eax, esi
// 006aac37  5e                   pop esi
// 006aac38  5b                   pop ebx
// 006aac39  83c408               add esp, 8
// 006aac3c  c3                   ret 
// 006aac3d  8b00                 mov eax, dword ptr [eax]
// 006aac3f  ebe8                 jmp 0x6aac29
// standard library vector<string> (function ?back@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAEAAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@XZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
