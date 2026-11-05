// from server: 100% by auto
// roc 2009-12 004dd5f0  unit: G3D::Shader  size: 124 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004dd5f0
//
// 004dd5f0  53                   push ebx
// 004dd5f1  56                   push esi
// 004dd5f2  8bf1                 mov esi, ecx
// 004dd5f4  33db                 xor ebx, ebx
// 004dd5f6  57                   push edi
// 004dd5f7  395e1c               cmp dword ptr [esi + 0x1c], ebx
// 004dd5fa  7434                 je 0x4dd630
// 004dd5fc  83cfff               or edi, 0xffffffff
// 004dd5ff  90                   nop 
// 004dd600  8b461c               mov eax, dword ptr [esi + 0x1c]
// 004dd603  3bc3                 cmp eax, ebx
// 004dd605  7424                 je 0x4dd62b
// 004dd607  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004dd60a  8d4408ff             lea eax, [eax + ecx - 1]
// 004dd60e  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 004dd611  3bc8                 cmp ecx, eax
// 004dd613  7702                 ja 0x4dd617
// 004dd615  2bc1                 sub eax, ecx
// 004dd617  8b5610               mov edx, dword ptr [esi + 0x10]
// 004dd61a  8b0c82               mov ecx, dword ptr [edx + eax*4]
// 004dd61d  ff15e4b69800         call dword ptr [0x98b6e4]
// 004dd623  017e1c               add dword ptr [esi + 0x1c], edi
// 004dd626  7503                 jne 0x4dd62b
// 004dd628  895e18               mov dword ptr [esi + 0x18], ebx
// 004dd62b  395e1c               cmp dword ptr [esi + 0x1c], ebx
// 004dd62e  75d0                 jne 0x4dd600
// 004dd630  8b7e14               mov edi, dword ptr [esi + 0x14]
// 004dd633  3bfb                 cmp edi, ebx
// 004dd635  761b                 jbe 0x4dd652
// 004dd637  8b4610               mov eax, dword ptr [esi + 0x10]
// 004dd63a  4f                   dec edi
// 004dd63b  391cb8               cmp dword ptr [eax + edi*4], ebx
// 004dd63e  8d04b8               lea eax, [eax + edi*4]
// 004dd641  740b                 je 0x4dd64e
// 004dd643  8b08                 mov ecx, dword ptr [eax]
// 004dd645  51                   push ecx
// 004dd646  e80f623100           call 0x7f385a
// 004dd64b  83c404               add esp, 4
// 004dd64e  3bfb                 cmp edi, ebx
// 004dd650  77e5                 ja 0x4dd637
// 004dd652  8b4610               mov eax, dword ptr [esi + 0x10]
// 004dd655  3bc3                 cmp eax, ebx
// 004dd657  7409                 je 0x4dd662
// 004dd659  50                   push eax
// 004dd65a  e8fb613100           call 0x7f385a
// 004dd65f  83c404               add esp, 4
// 004dd662  5f                   pop edi
// 004dd663  895e10               mov dword ptr [esi + 0x10], ebx
// 004dd666  895e14               mov dword ptr [esi + 0x14], ebx
// 004dd669  5e                   pop esi
// 004dd66a  5b                   pop ebx
// 004dd66b  c3                   ret 
// standard library deque<string> (function ?_Tidy@?$deque@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEXXZ)

// stl: deque<string>
#include <string>
typedef std::string E;
#include <deque>
template class std::deque<E>;
