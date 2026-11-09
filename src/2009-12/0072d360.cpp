// from server: 100% by auto
// roc 2009-12 0072d360  unit: RBX::ThreadPool::ThreadPoolData  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0072d360
//
// 0072d360  83ec08               sub esp, 8
// 0072d363  53                   push ebx
// 0072d364  8b1d60b79800         mov ebx, dword ptr [0x98b760]
// 0072d36a  56                   push esi
// 0072d36b  8bf1                 mov esi, ecx
// 0072d36d  57                   push edi
// 0072d36e  8b7e10               mov edi, dword ptr [esi + 0x10]
// 0072d371  397e0c               cmp dword ptr [esi + 0xc], edi
// 0072d374  7602                 jbe 0x72d378
// 0072d376  ffd3                 call ebx
// 0072d378  8b36                 mov esi, dword ptr [esi]
// 0072d37a  6aff                 push -1
// 0072d37c  8d4c2410             lea ecx, [esp + 0x10]
// 0072d380  89742410             mov dword ptr [esp + 0x10], esi
// 0072d384  897c2414             mov dword ptr [esp + 0x14], edi
// 0072d388  e8c3e3ffff           call 0x72b750
// 0072d38d  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0072d391  85c0                 test eax, eax
// 0072d393  7518                 jne 0x72d3ad
// 0072d395  ffd3                 call ebx
// 0072d397  33c0                 xor eax, eax
// 0072d399  8b742410             mov esi, dword ptr [esp + 0x10]
// 0072d39d  3b7010               cmp esi, dword ptr [eax + 0x10]
// 0072d3a0  7202                 jb 0x72d3a4
// 0072d3a2  ffd3                 call ebx
// 0072d3a4  5f                   pop edi
// 0072d3a5  8bc6                 mov eax, esi
// 0072d3a7  5e                   pop esi
// 0072d3a8  5b                   pop ebx
// 0072d3a9  83c408               add esp, 8
// 0072d3ac  c3                   ret 
// 0072d3ad  8b00                 mov eax, dword ptr [eax]
// 0072d3af  ebe8                 jmp 0x72d399
// standard library vector<string> (function ?back@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAEAAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@XZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
