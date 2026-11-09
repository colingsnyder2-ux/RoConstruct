// from server: 100% by auto
// roc 2008-06 00439320  unit: IIHAAH::?$CMap  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00439320
//
// 00439320  83ec08               sub esp, 8
// 00439323  53                   push ebx
// 00439324  55                   push ebp
// 00439325  56                   push esi
// 00439326  8bf1                 mov esi, ecx
// 00439328  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 0043932b  57                   push edi
// 0043932c  395e0c               cmp dword ptr [esi + 0xc], ebx
// 0043932f  7606                 jbe 0x439337
// 00439331  ff1590288000         call dword ptr [0x802890]
// 00439337  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0043933a  8b2e                 mov ebp, dword ptr [esi]
// 0043933c  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 0043933f  7606                 jbe 0x439347
// 00439341  ff1590288000         call dword ptr [0x802890]
// 00439347  8b06                 mov eax, dword ptr [esi]
// 00439349  53                   push ebx
// 0043934a  55                   push ebp
// 0043934b  57                   push edi
// 0043934c  50                   push eax
// 0043934d  8d442420             lea eax, [esp + 0x20]
// 00439351  50                   push eax
// 00439352  8bce                 mov ecx, esi
// 00439354  e867ca0000           call 0x445dc0
// 00439359  5f                   pop edi
// 0043935a  5e                   pop esi
// 0043935b  5d                   pop ebp
// 0043935c  5b                   pop ebx
// 0043935d  83c408               add esp, 8
// 00439360  c3                   ret 
// standard library vector<ptr> (function ?clear@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXXZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
