// from server: 100% by auto
// roc 2008-06 0044b7d0  unit: CRobloxApp  size: 124 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0044b7d0
//
// 0044b7d0  53                   push ebx
// 0044b7d1  56                   push esi
// 0044b7d2  8bf1                 mov esi, ecx
// 0044b7d4  33db                 xor ebx, ebx
// 0044b7d6  57                   push edi
// 0044b7d7  395e1c               cmp dword ptr [esi + 0x1c], ebx
// 0044b7da  7434                 je 0x44b810
// 0044b7dc  83cfff               or edi, 0xffffffff
// 0044b7df  90                   nop 
// 0044b7e0  8b461c               mov eax, dword ptr [esi + 0x1c]
// 0044b7e3  3bc3                 cmp eax, ebx
// 0044b7e5  7424                 je 0x44b80b
// 0044b7e7  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0044b7ea  8d4408ff             lea eax, [eax + ecx - 1]
// 0044b7ee  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 0044b7f1  3bc8                 cmp ecx, eax
// 0044b7f3  7702                 ja 0x44b7f7
// 0044b7f5  2bc1                 sub eax, ecx
// 0044b7f7  8b5610               mov edx, dword ptr [esi + 0x10]
// 0044b7fa  8b0c82               mov ecx, dword ptr [edx + eax*4]
// 0044b7fd  ff1568248000         call dword ptr [0x802468]
// 0044b803  017e1c               add dword ptr [esi + 0x1c], edi
// 0044b806  7503                 jne 0x44b80b
// 0044b808  895e18               mov dword ptr [esi + 0x18], ebx
// 0044b80b  395e1c               cmp dword ptr [esi + 0x1c], ebx
// 0044b80e  75d0                 jne 0x44b7e0
// 0044b810  8b7e14               mov edi, dword ptr [esi + 0x14]
// 0044b813  3bfb                 cmp edi, ebx
// 0044b815  761b                 jbe 0x44b832
// 0044b817  8b4610               mov eax, dword ptr [esi + 0x10]
// 0044b81a  4f                   dec edi
// 0044b81b  391cb8               cmp dword ptr [eax + edi*4], ebx
// 0044b81e  8d04b8               lea eax, [eax + edi*4]
// 0044b821  740b                 je 0x44b82e
// 0044b823  8b08                 mov ecx, dword ptr [eax]
// 0044b825  51                   push ecx
// 0044b826  e84f4e2500           call 0x6a067a
// 0044b82b  83c404               add esp, 4
// 0044b82e  3bfb                 cmp edi, ebx
// 0044b830  77e5                 ja 0x44b817
// 0044b832  8b4610               mov eax, dword ptr [esi + 0x10]
// 0044b835  3bc3                 cmp eax, ebx
// 0044b837  7409                 je 0x44b842
// 0044b839  50                   push eax
// 0044b83a  e83b4e2500           call 0x6a067a
// 0044b83f  83c404               add esp, 4
// 0044b842  5f                   pop edi
// 0044b843  895e10               mov dword ptr [esi + 0x10], ebx
// 0044b846  895e14               mov dword ptr [esi + 0x14], ebx
// 0044b849  5e                   pop esi
// 0044b84a  5b                   pop ebx
// 0044b84b  c3                   ret 
// standard library deque<string> (function ?_Tidy@?$deque@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEXXZ)

// stl: deque<string>
#include <string>
typedef std::string E;
#include <deque>
template class std::deque<E>;
