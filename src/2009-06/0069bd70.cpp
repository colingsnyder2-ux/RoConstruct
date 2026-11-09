// from server: 100% by auto
// roc 2009-06 0069bd70  unit: RBX::VFlagStandService::?$FactoryProduct  size: 150 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0069bd70
//
// 0069bd70  83ec0c               sub esp, 0xc
// 0069bd73  8b442410             mov eax, dword ptr [esp + 0x10]
// 0069bd77  53                   push ebx
// 0069bd78  55                   push ebp
// 0069bd79  8bd9                 mov ebx, ecx
// 0069bd7b  8b08                 mov ecx, dword ptr [eax]
// 0069bd7d  8b6b14               mov ebp, dword ptr [ebx + 0x14]
// 0069bd80  56                   push esi
// 0069bd81  8b33                 mov esi, dword ptr [ebx]
// 0069bd83  57                   push edi
// 0069bd84  8b7d00               mov edi, dword ptr [ebp]
// 0069bd87  894c2410             mov dword ptr [esp + 0x10], ecx
// 0069bd8b  89742420             mov dword ptr [esp + 0x20], esi
// 0069bd8f  90                   nop 
// 0069bd90  85f6                 test esi, esi
// 0069bd92  7406                 je 0x69bd9a
// 0069bd94  3b742420             cmp esi, dword ptr [esp + 0x20]
// 0069bd98  7406                 je 0x69bda0
// 0069bd9a  ff15ace98900         call dword ptr [0x89e9ac]
// 0069bda0  3bfd                 cmp edi, ebp
// 0069bda2  7458                 je 0x69bdfc
// 0069bda4  85f6                 test esi, esi
// 0069bda6  7531                 jne 0x69bdd9
// 0069bda8  ff15ace98900         call dword ptr [0x89e9ac]
// 0069bdae  33c0                 xor eax, eax
// 0069bdb0  3b7814               cmp edi, dword ptr [eax + 0x14]
// 0069bdb3  7506                 jne 0x69bdbb
// 0069bdb5  ff15ace98900         call dword ptr [0x89e9ac]
// 0069bdbb  8b542410             mov edx, dword ptr [esp + 0x10]
// 0069bdbf  395708               cmp dword ptr [edi + 8], edx
// 0069bdc2  7519                 jne 0x69bddd
// 0069bdc4  57                   push edi
// 0069bdc5  56                   push esi
// 0069bdc6  8d44241c             lea eax, [esp + 0x1c]
// 0069bdca  50                   push eax
// 0069bdcb  8bcb                 mov ecx, ebx
// 0069bdcd  e85eadddff           call 0x476b30
// 0069bdd2  8b30                 mov esi, dword ptr [eax]
// 0069bdd4  8b7804               mov edi, dword ptr [eax + 4]
// 0069bdd7  ebb7                 jmp 0x69bd90
// 0069bdd9  8b06                 mov eax, dword ptr [esi]
// 0069bddb  ebd3                 jmp 0x69bdb0
// 0069bddd  85f6                 test esi, esi
// 0069bddf  7517                 jne 0x69bdf8
// 0069bde1  ff15ace98900         call dword ptr [0x89e9ac]
// 0069bde7  33c0                 xor eax, eax
// 0069bde9  3b7814               cmp edi, dword ptr [eax + 0x14]
// 0069bdec  7506                 jne 0x69bdf4
// 0069bdee  ff15ace98900         call dword ptr [0x89e9ac]
// 0069bdf4  8b3f                 mov edi, dword ptr [edi]
// 0069bdf6  eb98                 jmp 0x69bd90
// 0069bdf8  8b06                 mov eax, dword ptr [esi]
// 0069bdfa  ebed                 jmp 0x69bde9
// 0069bdfc  5f                   pop edi
// 0069bdfd  5e                   pop esi
// 0069bdfe  5d                   pop ebp
// 0069bdff  5b                   pop ebx
// 0069be00  83c40c               add esp, 0xc
// 0069be03  c20400               ret 4
// standard library list<ptr> (function ?remove@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXABQAUT@@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
