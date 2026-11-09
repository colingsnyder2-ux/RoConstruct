// from server: 100% by auto
// roc 2009-06 005da100  unit: RBX::ContentProvider::HashApprovalDictionary::VValue::?$sp_counted_impl_p  size: 74 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005da100
//
// 005da100  56                   push esi
// 005da101  8b742408             mov esi, dword ptr [esp + 8]
// 005da105  33c0                 xor eax, eax
// 005da107  57                   push edi
// 005da108  8bf9                 mov edi, ecx
// 005da10a  89470c               mov dword ptr [edi + 0xc], eax
// 005da10d  894710               mov dword ptr [edi + 0x10], eax
// 005da110  894714               mov dword ptr [edi + 0x14], eax
// 005da113  3bf0                 cmp esi, eax
// 005da115  7507                 jne 0x5da11e
// 005da117  5f                   pop edi
// 005da118  32c0                 xor al, al
// 005da11a  5e                   pop esi
// 005da11b  c20400               ret 4
// 005da11e  81feffffff07         cmp esi, 0x7ffffff
// 005da124  7605                 jbe 0x5da12b
// 005da126  e83562ebff           call 0x490360
// 005da12b  50                   push eax
// 005da12c  56                   push esi
// 005da12d  e87ef1ffff           call 0x5d92b0
// 005da132  c1e605               shl esi, 5
// 005da135  03f0                 add esi, eax
// 005da137  83c408               add esp, 8
// 005da13a  89470c               mov dword ptr [edi + 0xc], eax
// 005da13d  894710               mov dword ptr [edi + 0x10], eax
// 005da140  897714               mov dword ptr [edi + 0x14], esi
// 005da143  5f                   pop edi
// 005da144  b001                 mov al, 1
// 005da146  5e                   pop esi
// 005da147  c20400               ret 4
// standard library vector<pod32> (function ?_Buy@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAE_NI@Z)

// stl: vector<pod32>
struct E { int v[8]; };
#include <vector>
template class std::vector<E>;
