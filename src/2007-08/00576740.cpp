// from server: 100% by auto
// roc 2007-08 00576740  unit: RBX::PartInstance  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00576740
//
// 00576740  56                   push esi
// 00576741  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00576745  85f6                 test esi, esi
// 00576747  57                   push edi
// 00576748  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0057674c  8bc6                 mov eax, esi
// 0057674e  8bcf                 mov ecx, edi
// 00576750  7614                 jbe 0x576766
// 00576752  8b542414             mov edx, dword ptr [esp + 0x14]
// 00576756  53                   push ebx
// 00576757  8b1a                 mov ebx, dword ptr [edx]
// 00576759  8919                 mov dword ptr [ecx], ebx
// 0057675b  83e801               sub eax, 1
// 0057675e  83c104               add ecx, 4
// 00576761  85c0                 test eax, eax
// 00576763  77f2                 ja 0x576757
// 00576765  5b                   pop ebx
// 00576766  8d04b7               lea eax, [edi + esi*4]
// 00576769  5f                   pop edi
// 0057676a  5e                   pop esi
// 0057676b  c20c00               ret 0xc
// standard library vector<ptr> (function ?_Ufill@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEPAPAUT@@PAPAU3@IABQAU3@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
