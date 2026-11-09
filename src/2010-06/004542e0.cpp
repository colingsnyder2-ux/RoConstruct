// from server: 100% by auto
// roc 2010-06 004542e0  unit: CRobloxControlColorSelector  size: 157 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004542e0
//
// 004542e0  83ec08               sub esp, 8
// 004542e3  53                   push ebx
// 004542e4  56                   push esi
// 004542e5  8bf1                 mov esi, ecx
// 004542e7  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 004542ea  57                   push edi
// 004542eb  85db                 test ebx, ebx
// 004542ed  7504                 jne 0x4542f3
// 004542ef  33c9                 xor ecx, ecx
// 004542f1  eb15                 jmp 0x454308
// 004542f3  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 004542f6  2bcb                 sub ecx, ebx
// 004542f8  b8abaaaa2a           mov eax, 0x2aaaaaab
// 004542fd  f7e9                 imul ecx
// 004542ff  d1fa                 sar edx, 1
// 00454301  8bca                 mov ecx, edx
// 00454303  c1e91f               shr ecx, 0x1f
// 00454306  03ca                 add ecx, edx
// 00454308  8b7e10               mov edi, dword ptr [esi + 0x10]
// 0045430b  8bd7                 mov edx, edi
// 0045430d  2bd3                 sub edx, ebx
// 0045430f  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00454314  f7ea                 imul edx
// 00454316  d1fa                 sar edx, 1
// 00454318  8bc2                 mov eax, edx
// 0045431a  c1e81f               shr eax, 0x1f
// 0045431d  03c2                 add eax, edx
// 0045431f  3bc1                 cmp eax, ecx
// 00454321  7332                 jae 0x454355
// 00454323  8b542418             mov edx, dword ptr [esp + 0x18]
// 00454327  c644240c00           mov byte ptr [esp + 0xc], 0
// 0045432c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00454330  51                   push ecx
// 00454331  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00454335  52                   push edx
// 00454336  8d4608               lea eax, [esi + 8]
// 00454339  50                   push eax
// 0045433a  51                   push ecx
// 0045433b  6a01                 push 1
// 0045433d  57                   push edi
// 0045433e  e82dfaffff           call 0x453d70
// 00454343  83c418               add esp, 0x18
// 00454346  83c70c               add edi, 0xc
// 00454349  897e10               mov dword ptr [esi + 0x10], edi
// 0045434c  5f                   pop edi
// 0045434d  5e                   pop esi
// 0045434e  5b                   pop ebx
// 0045434f  83c408               add esp, 8
// 00454352  c20400               ret 4
// 00454355  3bdf                 cmp ebx, edi
// 00454357  7606                 jbe 0x45435f
// 00454359  ff150ca99e00         call dword ptr [0x9ea90c]
// 0045435f  8b542418             mov edx, dword ptr [esp + 0x18]
// 00454363  8b06                 mov eax, dword ptr [esi]
// 00454365  52                   push edx
// 00454366  57                   push edi
// 00454367  50                   push eax
// 00454368  8d442418             lea eax, [esp + 0x18]
// 0045436c  50                   push eax
// 0045436d  8bce                 mov ecx, esi
// 0045436f  e89cfeffff           call 0x454210
// 00454374  5f                   pop edi
// 00454375  5e                   pop esi
// 00454376  5b                   pop ebx
// 00454377  83c408               add esp, 8
// 0045437a  c20400               ret 4
// standard library vector<pod12> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
