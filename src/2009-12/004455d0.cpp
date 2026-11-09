// from server: 100% by auto
// roc 2009-12 004455d0  unit: RBX::Reflection::M::?$TypedPropertyDescriptor  size: 250 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004455d0
//
// 004455d0  6aff                 push -1
// 004455d2  68b9759300           push 0x9375b9
// 004455d7  64a100000000         mov eax, dword ptr fs:[0]
// 004455dd  50                   push eax
// 004455de  64892500000000       mov dword ptr fs:[0], esp
// 004455e5  83ec10               sub esp, 0x10
// 004455e8  53                   push ebx
// 004455e9  55                   push ebp
// 004455ea  56                   push esi
// 004455eb  57                   push edi
// 004455ec  8bf1                 mov esi, ecx
// 004455ee  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 004455f1  8b6e0c               mov ebp, dword ptr [esi + 0xc]
// 004455f4  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 004455f8  8bcb                 mov ecx, ebx
// 004455fa  2bcd                 sub ecx, ebp
// 004455fc  b893244992           mov eax, 0x92492493
// 00445601  f7e9                 imul ecx
// 00445603  03d1                 add edx, ecx
// 00445605  c1fa04               sar edx, 4
// 00445608  8bc2                 mov eax, edx
// 0044560a  c1e81f               shr eax, 0x1f
// 0044560d  03c2                 add eax, edx
// 0044560f  c744242800000000     mov dword ptr [esp + 0x28], 0
// 00445617  3bf8                 cmp edi, eax
// 00445619  7638                 jbe 0x445653
// 0044561b  3beb                 cmp ebp, ebx
// 0044561d  7606                 jbe 0x445625
// 0044561f  ff1560b79800         call dword ptr [0x98b760]
// 00445625  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00445628  2b4e0c               sub ecx, dword ptr [esi + 0xc]
// 0044562b  8b2e                 mov ebp, dword ptr [esi]
// 0044562d  8d442434             lea eax, [esp + 0x34]
// 00445631  50                   push eax
// 00445632  b893244992           mov eax, 0x92492493
// 00445637  f7e9                 imul ecx
// 00445639  03d1                 add edx, ecx
// 0044563b  c1fa04               sar edx, 4
// 0044563e  8bca                 mov ecx, edx
// 00445640  c1e91f               shr ecx, 0x1f
// 00445643  03ca                 add ecx, edx
// 00445645  2bf9                 sub edi, ecx
// 00445647  57                   push edi
// 00445648  53                   push ebx
// 00445649  55                   push ebp
// 0044564a  8bce                 mov ecx, esi
// 0044564c  e8dffbfdff           call 0x425230
// 00445651  eb50                 jmp 0x4456a3
// 00445653  734e                 jae 0x4456a3
// 00445655  3beb                 cmp ebp, ebx
// 00445657  7606                 jbe 0x44565f
// 00445659  ff1560b79800         call dword ptr [0x98b760]
// 0044565f  8b6e0c               mov ebp, dword ptr [esi + 0xc]
// 00445662  8b16                 mov edx, dword ptr [esi]
// 00445664  89542418             mov dword ptr [esp + 0x18], edx
// 00445668  3b6e10               cmp ebp, dword ptr [esi + 0x10]
// 0044566b  7606                 jbe 0x445673
// 0044566d  ff1560b79800         call dword ptr [0x98b760]
// 00445673  8b06                 mov eax, dword ptr [esi]
// 00445675  57                   push edi
// 00445676  8d4c2414             lea ecx, [esp + 0x14]
// 0044567a  89442414             mov dword ptr [esp + 0x14], eax
// 0044567e  896c2418             mov dword ptr [esp + 0x18], ebp
// 00445682  e839e4fdff           call 0x423ac0
// 00445687  8b442418             mov eax, dword ptr [esp + 0x18]
// 0044568b  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0044568f  8b542410             mov edx, dword ptr [esp + 0x10]
// 00445693  53                   push ebx
// 00445694  50                   push eax
// 00445695  51                   push ecx
// 00445696  52                   push edx
// 00445697  8d442428             lea eax, [esp + 0x28]
// 0044569b  50                   push eax
// 0044569c  8bce                 mov ecx, esi
// 0044569e  e8edfaffff           call 0x445190
// 004456a3  8d4c2434             lea ecx, [esp + 0x34]
// 004456a7  c7442428ffffffff     mov dword ptr [esp + 0x28], 0xffffffff
// 004456af  ff15e4b69800         call dword ptr [0x98b6e4]
// 004456b5  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004456b9  5f                   pop edi
// 004456ba  5e                   pop esi
// 004456bb  5d                   pop ebp
// 004456bc  5b                   pop ebx
// 004456bd  64890d00000000       mov dword ptr fs:[0], ecx
// 004456c4  83c41c               add esp, 0x1c
// 004456c7  c22000               ret 0x20
// standard library vector<string> (function ?resize@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAEXIV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
