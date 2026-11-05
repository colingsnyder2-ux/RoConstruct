// from server: 100% by auto
// roc 2007-08 0044a020  unit: CRobloxModule  size: 126 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0044a020
//
// 0044a020  53                   push ebx
// 0044a021  56                   push esi
// 0044a022  8bf1                 mov esi, ecx
// 0044a024  33db                 xor ebx, ebx
// 0044a026  395e10               cmp dword ptr [esi + 0x10], ebx
// 0044a029  57                   push edi
// 0044a02a  7434                 je 0x44a060
// 0044a02c  83cfff               or edi, 0xffffffff
// 0044a02f  90                   nop 
// 0044a030  8b4610               mov eax, dword ptr [esi + 0x10]
// 0044a033  3bc3                 cmp eax, ebx
// 0044a035  7424                 je 0x44a05b
// 0044a037  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0044a03a  8d4408ff             lea eax, [eax + ecx - 1]
// 0044a03e  8b4e08               mov ecx, dword ptr [esi + 8]
// 0044a041  3bc8                 cmp ecx, eax
// 0044a043  7702                 ja 0x44a047
// 0044a045  2bc1                 sub eax, ecx
// 0044a047  8b5604               mov edx, dword ptr [esi + 4]
// 0044a04a  8b0c82               mov ecx, dword ptr [edx + eax*4]
// 0044a04d  ff15ace67700         call dword ptr [0x77e6ac]
// 0044a053  017e10               add dword ptr [esi + 0x10], edi
// 0044a056  7503                 jne 0x44a05b
// 0044a058  895e0c               mov dword ptr [esi + 0xc], ebx
// 0044a05b  395e10               cmp dword ptr [esi + 0x10], ebx
// 0044a05e  75d0                 jne 0x44a030
// 0044a060  8b7e08               mov edi, dword ptr [esi + 8]
// 0044a063  3bfb                 cmp edi, ebx
// 0044a065  761d                 jbe 0x44a084
// 0044a067  8b4604               mov eax, dword ptr [esi + 4]
// 0044a06a  83ef01               sub edi, 1
// 0044a06d  391cb8               cmp dword ptr [eax + edi*4], ebx
// 0044a070  8d04b8               lea eax, [eax + edi*4]
// 0044a073  740b                 je 0x44a080
// 0044a075  8b08                 mov ecx, dword ptr [eax]
// 0044a077  51                   push ecx
// 0044a078  e8e55b1e00           call 0x62fc62
// 0044a07d  83c404               add esp, 4
// 0044a080  3bfb                 cmp edi, ebx
// 0044a082  77e3                 ja 0x44a067
// 0044a084  8b4604               mov eax, dword ptr [esi + 4]
// 0044a087  3bc3                 cmp eax, ebx
// 0044a089  7409                 je 0x44a094
// 0044a08b  50                   push eax
// 0044a08c  e8d15b1e00           call 0x62fc62
// 0044a091  83c404               add esp, 4
// 0044a094  5f                   pop edi
// 0044a095  895e04               mov dword ptr [esi + 4], ebx
// 0044a098  895e08               mov dword ptr [esi + 8], ebx
// 0044a09b  5e                   pop esi
// 0044a09c  5b                   pop ebx
// 0044a09d  c3                   ret 
// standard library deque<string> (function ?_Tidy@?$deque@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEXXZ)

// stl: deque<string>
#include <string>
typedef std::string E;
#include <deque>
template class std::deque<E>;
