// from server: 100% by auto
// roc 2012-06 0046fd10  unit: CRobloxApp  size: 124 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0046fd10
//
// 0046fd10  53                   push ebx
// 0046fd11  56                   push esi
// 0046fd12  8bf1                 mov esi, ecx
// 0046fd14  33db                 xor ebx, ebx
// 0046fd16  57                   push edi
// 0046fd17  395e1c               cmp dword ptr [esi + 0x1c], ebx
// 0046fd1a  7434                 je 0x46fd50
// 0046fd1c  83cfff               or edi, 0xffffffff
// 0046fd1f  90                   nop 
// 0046fd20  8b461c               mov eax, dword ptr [esi + 0x1c]
// 0046fd23  3bc3                 cmp eax, ebx
// 0046fd25  7424                 je 0x46fd4b
// 0046fd27  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0046fd2a  8d4408ff             lea eax, [eax + ecx - 1]
// 0046fd2e  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 0046fd31  3bc8                 cmp ecx, eax
// 0046fd33  7702                 ja 0x46fd37
// 0046fd35  2bc1                 sub eax, ecx
// 0046fd37  8b5610               mov edx, dword ptr [esi + 0x10]
// 0046fd3a  8b0c82               mov ecx, dword ptr [edx + eax*4]
// 0046fd3d  ff153c26b200         call dword ptr [0xb2263c]
// 0046fd43  017e1c               add dword ptr [esi + 0x1c], edi
// 0046fd46  7503                 jne 0x46fd4b
// 0046fd48  895e18               mov dword ptr [esi + 0x18], ebx
// 0046fd4b  395e1c               cmp dword ptr [esi + 0x1c], ebx
// 0046fd4e  75d0                 jne 0x46fd20
// 0046fd50  8b7e14               mov edi, dword ptr [esi + 0x14]
// 0046fd53  3bfb                 cmp edi, ebx
// 0046fd55  761b                 jbe 0x46fd72
// 0046fd57  8b4610               mov eax, dword ptr [esi + 0x10]
// 0046fd5a  4f                   dec edi
// 0046fd5b  391cb8               cmp dword ptr [eax + edi*4], ebx
// 0046fd5e  8d04b8               lea eax, [eax + edi*4]
// 0046fd61  740b                 je 0x46fd6e
// 0046fd63  8b08                 mov ecx, dword ptr [eax]
// 0046fd65  51                   push ecx
// 0046fd66  e8a9235100           call 0x982114
// 0046fd6b  83c404               add esp, 4
// 0046fd6e  3bfb                 cmp edi, ebx
// 0046fd70  77e5                 ja 0x46fd57
// 0046fd72  8b4610               mov eax, dword ptr [esi + 0x10]
// 0046fd75  3bc3                 cmp eax, ebx
// 0046fd77  7409                 je 0x46fd82
// 0046fd79  50                   push eax
// 0046fd7a  e895235100           call 0x982114
// 0046fd7f  83c404               add esp, 4
// 0046fd82  5f                   pop edi
// 0046fd83  895e10               mov dword ptr [esi + 0x10], ebx
// 0046fd86  895e14               mov dword ptr [esi + 0x14], ebx
// 0046fd89  5e                   pop esi
// 0046fd8a  5b                   pop ebx
// 0046fd8b  c3                   ret 
// standard library deque<string> (function ?_Tidy@?$deque@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEXXZ)

// stl: deque<string>
#include <string>
typedef std::string E;
#include <deque>
template class std::deque<E>;
