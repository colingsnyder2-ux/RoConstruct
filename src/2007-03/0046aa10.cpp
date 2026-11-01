// from server: 100% by auto
// roc 2007-03 0046aa10  unit: seg_00460000  size: 91 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0046aa10
//
// 0046aa10  83ec08               sub esp, 8
// 0046aa13  53                   push ebx
// 0046aa14  56                   push esi
// 0046aa15  57                   push edi
// 0046aa16  8bf9                 mov edi, ecx
// 0046aa18  8b7704               mov esi, dword ptr [edi + 4]
// 0046aa1b  85f6                 test esi, esi
// 0046aa1d  7412                 je 0x46aa31
// 0046aa1f  8b4f08               mov ecx, dword ptr [edi + 8]
// 0046aa22  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0046aa26  8bc1                 mov eax, ecx
// 0046aa28  2bc6                 sub eax, esi
// 0046aa2a  c1f806               sar eax, 6
// 0046aa2d  3bc3                 cmp eax, ebx
// 0046aa2f  7705                 ja 0x46aa36
// 0046aa31  e81afdffff           call 0x46a750
// 0046aa36  3bf1                 cmp esi, ecx
// 0046aa38  55                   push ebp
// 0046aa39  8b2d44e97700         mov ebp, dword ptr [0x77e944]
// 0046aa3f  7602                 jbe 0x46aa43
// 0046aa41  ffd5                 call ebp
// 0046aa43  c1e306               shl ebx, 6
// 0046aa46  89742414             mov dword ptr [esp + 0x14], esi
// 0046aa4a  03f3                 add esi, ebx
// 0046aa4c  3b7708               cmp esi, dword ptr [edi + 8]
// 0046aa4f  7705                 ja 0x46aa56
// 0046aa51  3b7704               cmp esi, dword ptr [edi + 4]
// 0046aa54  7302                 jae 0x46aa58
// 0046aa56  ffd5                 call ebp
// 0046aa58  3b7708               cmp esi, dword ptr [edi + 8]
// 0046aa5b  7202                 jb 0x46aa5f
// 0046aa5d  ffd5                 call ebp
// 0046aa5f  5d                   pop ebp
// 0046aa60  5f                   pop edi
// 0046aa61  8bc6                 mov eax, esi
// 0046aa63  5e                   pop esi
// 0046aa64  5b                   pop ebx
// 0046aa65  83c408               add esp, 8
// 0046aa68  c20400               ret 4
// standard library vector<pod64> (function ?at@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QBEABUE@@I@Z)

// stl: vector<pod64>
struct E { int v[16]; };
#include <vector>
template class std::vector<E>;
