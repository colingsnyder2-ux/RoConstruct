// from server: 100% by auto
// roc 2007-03 0046aaa0  unit: seg_00460000  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0046aaa0
//
// 0046aaa0  51                   push ecx
// 0046aaa1  8b542410             mov edx, dword ptr [esp + 0x10]
// 0046aaa5  56                   push esi
// 0046aaa6  8b742410             mov esi, dword ptr [esp + 0x10]
// 0046aaaa  57                   push edi
// 0046aaab  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0046aaaf  c644240800           mov byte ptr [esp + 8], 0
// 0046aab4  8b442408             mov eax, dword ptr [esp + 8]
// 0046aab8  50                   push eax
// 0046aab9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0046aabd  52                   push edx
// 0046aabe  51                   push ecx
// 0046aabf  50                   push eax
// 0046aac0  56                   push esi
// 0046aac1  57                   push edi
// 0046aac2  e839feffff           call 0x46a900
// 0046aac7  8bc6                 mov eax, esi
// 0046aac9  83c418               add esp, 0x18
// 0046aacc  c1e006               shl eax, 6
// 0046aacf  03c7                 add eax, edi
// 0046aad1  5f                   pop edi
// 0046aad2  5e                   pop esi
// 0046aad3  59                   pop ecx
// 0046aad4  c20c00               ret 0xc
// standard library vector<pod64> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod64>
struct E { int v[16]; };
#include <vector>
template class std::vector<E>;
