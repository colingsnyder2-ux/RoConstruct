// from server: 100% by auto
// roc 2010-06 0044f890  unit: CRobloxApp  size: 124 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0044f890
//
// 0044f890  53                   push ebx
// 0044f891  56                   push esi
// 0044f892  8bf1                 mov esi, ecx
// 0044f894  33db                 xor ebx, ebx
// 0044f896  57                   push edi
// 0044f897  395e1c               cmp dword ptr [esi + 0x1c], ebx
// 0044f89a  7434                 je 0x44f8d0
// 0044f89c  83cfff               or edi, 0xffffffff
// 0044f89f  90                   nop 
// 0044f8a0  8b461c               mov eax, dword ptr [esi + 0x1c]
// 0044f8a3  3bc3                 cmp eax, ebx
// 0044f8a5  7424                 je 0x44f8cb
// 0044f8a7  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0044f8aa  8d4408ff             lea eax, [eax + ecx - 1]
// 0044f8ae  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 0044f8b1  3bc8                 cmp ecx, eax
// 0044f8b3  7702                 ja 0x44f8b7
// 0044f8b5  2bc1                 sub eax, ecx
// 0044f8b7  8b5610               mov edx, dword ptr [esi + 0x10]
// 0044f8ba  8b0c82               mov ecx, dword ptr [edx + eax*4]
// 0044f8bd  ff1500a49e00         call dword ptr [0x9ea400]
// 0044f8c3  017e1c               add dword ptr [esi + 0x1c], edi
// 0044f8c6  7503                 jne 0x44f8cb
// 0044f8c8  895e18               mov dword ptr [esi + 0x18], ebx
// 0044f8cb  395e1c               cmp dword ptr [esi + 0x1c], ebx
// 0044f8ce  75d0                 jne 0x44f8a0
// 0044f8d0  8b7e14               mov edi, dword ptr [esi + 0x14]
// 0044f8d3  3bfb                 cmp edi, ebx
// 0044f8d5  761b                 jbe 0x44f8f2
// 0044f8d7  8b4610               mov eax, dword ptr [esi + 0x10]
// 0044f8da  4f                   dec edi
// 0044f8db  391cb8               cmp dword ptr [eax + edi*4], ebx
// 0044f8de  8d04b8               lea eax, [eax + edi*4]
// 0044f8e1  740b                 je 0x44f8ee
// 0044f8e3  8b08                 mov ecx, dword ptr [eax]
// 0044f8e5  51                   push ecx
// 0044f8e6  e8af803500           call 0x7a799a
// 0044f8eb  83c404               add esp, 4
// 0044f8ee  3bfb                 cmp edi, ebx
// 0044f8f0  77e5                 ja 0x44f8d7
// 0044f8f2  8b4610               mov eax, dword ptr [esi + 0x10]
// 0044f8f5  3bc3                 cmp eax, ebx
// 0044f8f7  7409                 je 0x44f902
// 0044f8f9  50                   push eax
// 0044f8fa  e89b803500           call 0x7a799a
// 0044f8ff  83c404               add esp, 4
// 0044f902  5f                   pop edi
// 0044f903  895e10               mov dword ptr [esi + 0x10], ebx
// 0044f906  895e14               mov dword ptr [esi + 0x14], ebx
// 0044f909  5e                   pop esi
// 0044f90a  5b                   pop ebx
// 0044f90b  c3                   ret 
// standard library deque<string> (function ?_Tidy@?$deque@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEXXZ)

// stl: deque<string>
#include <string>
typedef std::string E;
#include <deque>
template class std::deque<E>;
