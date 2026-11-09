// from server: 100% by auto
// roc 2009-12 00711cd0  unit: RBX::InstanceLocksmith  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00711cd0
//
// 00711cd0  6aff                 push -1
// 00711cd2  68d8c59300           push 0x93c5d8
// 00711cd7  64a100000000         mov eax, dword ptr fs:[0]
// 00711cdd  50                   push eax
// 00711cde  64892500000000       mov dword ptr fs:[0], esp
// 00711ce5  51                   push ecx
// 00711ce6  56                   push esi
// 00711ce7  8bf1                 mov esi, ecx
// 00711ce9  6a04                 push 4
// 00711ceb  89742408             mov dword ptr [esp + 8], esi
// 00711cef  e86c1b0e00           call 0x7f3860
// 00711cf4  83c404               add esp, 4
// 00711cf7  85c0                 test eax, eax
// 00711cf9  7404                 je 0x711cff
// 00711cfb  8930                 mov dword ptr [eax], esi
// 00711cfd  eb02                 jmp 0x711d01
// 00711cff  33c0                 xor eax, eax
// 00711d01  8906                 mov dword ptr [esi], eax
// 00711d03  8bce                 mov ecx, esi
// 00711d05  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00711d0d  e8cef6ffff           call 0x7113e0
// 00711d12  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00711d16  894618               mov dword ptr [esi + 0x18], eax
// 00711d19  c6402901             mov byte ptr [eax + 0x29], 1
// 00711d1d  8b4618               mov eax, dword ptr [esi + 0x18]
// 00711d20  894004               mov dword ptr [eax + 4], eax
// 00711d23  8b4618               mov eax, dword ptr [esi + 0x18]
// 00711d26  8900                 mov dword ptr [eax], eax
// 00711d28  8b4618               mov eax, dword ptr [esi + 0x18]
// 00711d2b  894008               mov dword ptr [eax + 8], eax
// 00711d2e  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00711d35  8bc6                 mov eax, esi
// 00711d37  5e                   pop esi
// 00711d38  64890d00000000       mov dword ptr fs:[0], ecx
// 00711d3f  83c410               add esp, 0x10
// 00711d42  c20800               ret 8
// standard library set<string> (function ??0?$_Tree@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@std@@QAE@ABU?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@1@ABV?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@1@@Z)

// stl: set<string>
#include <string>
typedef std::string E;
#include <set>
template class std::set<E>;
