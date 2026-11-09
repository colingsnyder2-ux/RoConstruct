// from server: 100% by auto
// roc 2011-06 005458d0  unit: G3D::ParseError  size: 124 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005458d0
//
// 005458d0  53                   push ebx
// 005458d1  56                   push esi
// 005458d2  8bf1                 mov esi, ecx
// 005458d4  33db                 xor ebx, ebx
// 005458d6  57                   push edi
// 005458d7  395e1c               cmp dword ptr [esi + 0x1c], ebx
// 005458da  7434                 je 0x545910
// 005458dc  83cfff               or edi, 0xffffffff
// 005458df  90                   nop 
// 005458e0  8b461c               mov eax, dword ptr [esi + 0x1c]
// 005458e3  3bc3                 cmp eax, ebx
// 005458e5  7424                 je 0x54590b
// 005458e7  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 005458ea  8d4408ff             lea eax, [eax + ecx - 1]
// 005458ee  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 005458f1  3bc8                 cmp ecx, eax
// 005458f3  7702                 ja 0x5458f7
// 005458f5  2bc1                 sub eax, ecx
// 005458f7  8b5610               mov edx, dword ptr [esi + 0x10]
// 005458fa  8b0c82               mov ecx, dword ptr [edx + eax*4]
// 005458fd  ff15d004a400         call dword ptr [0xa404d0]
// 00545903  017e1c               add dword ptr [esi + 0x1c], edi
// 00545906  7503                 jne 0x54590b
// 00545908  895e18               mov dword ptr [esi + 0x18], ebx
// 0054590b  395e1c               cmp dword ptr [esi + 0x1c], ebx
// 0054590e  75d0                 jne 0x5458e0
// 00545910  8b7e14               mov edi, dword ptr [esi + 0x14]
// 00545913  3bfb                 cmp edi, ebx
// 00545915  761b                 jbe 0x545932
// 00545917  8b4610               mov eax, dword ptr [esi + 0x10]
// 0054591a  4f                   dec edi
// 0054591b  391cb8               cmp dword ptr [eax + edi*4], ebx
// 0054591e  8d04b8               lea eax, [eax + edi*4]
// 00545921  740b                 je 0x54592e
// 00545923  8b08                 mov ecx, dword ptr [eax]
// 00545925  51                   push ecx
// 00545926  e82d472c00           call 0x80a058
// 0054592b  83c404               add esp, 4
// 0054592e  3bfb                 cmp edi, ebx
// 00545930  77e5                 ja 0x545917
// 00545932  8b4610               mov eax, dword ptr [esi + 0x10]
// 00545935  3bc3                 cmp eax, ebx
// 00545937  7409                 je 0x545942
// 00545939  50                   push eax
// 0054593a  e819472c00           call 0x80a058
// 0054593f  83c404               add esp, 4
// 00545942  5f                   pop edi
// 00545943  895e10               mov dword ptr [esi + 0x10], ebx
// 00545946  895e14               mov dword ptr [esi + 0x14], ebx
// 00545949  5e                   pop esi
// 0054594a  5b                   pop ebx
// 0054594b  c3                   ret 
// standard library deque<string> (function ?_Tidy@?$deque@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEXXZ)

// stl: deque<string>
#include <string>
typedef std::string E;
#include <deque>
template class std::deque<E>;
