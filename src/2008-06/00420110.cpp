// from server: 100% by auto
// roc 2008-06 00420110  unit: CInsertObjectDialog  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00420110
//
// 00420110  83ec08               sub esp, 8
// 00420113  56                   push esi
// 00420114  8bf1                 mov esi, ecx
// 00420116  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00420119  57                   push edi
// 0042011a  85c9                 test ecx, ecx
// 0042011c  7504                 jne 0x420122
// 0042011e  33c0                 xor eax, eax
// 00420120  eb08                 jmp 0x42012a
// 00420122  8b4614               mov eax, dword ptr [esi + 0x14]
// 00420125  2bc1                 sub eax, ecx
// 00420127  c1f803               sar eax, 3
// 0042012a  8b7e10               mov edi, dword ptr [esi + 0x10]
// 0042012d  8bd7                 mov edx, edi
// 0042012f  2bd1                 sub edx, ecx
// 00420131  c1fa03               sar edx, 3
// 00420134  3bd0                 cmp edx, eax
// 00420136  7331                 jae 0x420169
// 00420138  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0042013c  c644240800           mov byte ptr [esp + 8], 0
// 00420141  8b442408             mov eax, dword ptr [esp + 8]
// 00420145  50                   push eax
// 00420146  8b442418             mov eax, dword ptr [esp + 0x18]
// 0042014a  51                   push ecx
// 0042014b  8d5608               lea edx, [esi + 8]
// 0042014e  52                   push edx
// 0042014f  50                   push eax
// 00420150  6a01                 push 1
// 00420152  57                   push edi
// 00420153  e8a81fffff           call 0x412100
// 00420158  83c418               add esp, 0x18
// 0042015b  83c708               add edi, 8
// 0042015e  897e10               mov dword ptr [esi + 0x10], edi
// 00420161  5f                   pop edi
// 00420162  5e                   pop esi
// 00420163  83c408               add esp, 8
// 00420166  c20400               ret 4
// 00420169  3bcf                 cmp ecx, edi
// 0042016b  7606                 jbe 0x420173
// 0042016d  ff1590288000         call dword ptr [0x802890]
// 00420173  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00420177  8b06                 mov eax, dword ptr [esi]
// 00420179  51                   push ecx
// 0042017a  57                   push edi
// 0042017b  50                   push eax
// 0042017c  8d542414             lea edx, [esp + 0x14]
// 00420180  52                   push edx
// 00420181  8bce                 mov ecx, esi
// 00420183  e8a8feffff           call 0x420030
// 00420188  5f                   pop edi
// 00420189  5e                   pop esi
// 0042018a  83c408               add esp, 8
// 0042018d  c20400               ret 4
// standard library vector<pod8> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
