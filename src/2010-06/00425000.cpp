// from server: 100% by auto
// roc 2010-06 00425000  unit: ThreadLogManager  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00425000
//
// 00425000  56                   push esi
// 00425001  33c0                 xor eax, eax
// 00425003  57                   push edi
// 00425004  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00425008  8bf1                 mov esi, ecx
// 0042500a  89460c               mov dword ptr [esi + 0xc], eax
// 0042500d  894610               mov dword ptr [esi + 0x10], eax
// 00425010  894614               mov dword ptr [esi + 0x14], eax
// 00425013  3bf8                 cmp edi, eax
// 00425015  7507                 jne 0x42501e
// 00425017  5f                   pop edi
// 00425018  32c0                 xor al, al
// 0042501a  5e                   pop esi
// 0042501b  c20400               ret 4
// 0042501e  81ff49922409         cmp edi, 0x9249249
// 00425024  7605                 jbe 0x42502b
// 00425026  e8c5edffff           call 0x423df0
// 0042502b  50                   push eax
// 0042502c  57                   push edi
// 0042502d  e86e1f2300           call 0x656fa0
// 00425032  8d0cfd00000000       lea ecx, [edi*8]
// 00425039  2bcf                 sub ecx, edi
// 0042503b  83c408               add esp, 8
// 0042503e  8d1488               lea edx, [eax + ecx*4]
// 00425041  89460c               mov dword ptr [esi + 0xc], eax
// 00425044  894610               mov dword ptr [esi + 0x10], eax
// 00425047  5f                   pop edi
// 00425048  895614               mov dword ptr [esi + 0x14], edx
// 0042504b  b001                 mov al, 1
// 0042504d  5e                   pop esi
// 0042504e  c20400               ret 4
// standard library vector<string> (function ?_Buy@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAE_NI@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
