// from server: 100% by auto
// roc 2010-06 004365b0  unit: IIHAAH::?$CMap  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004365b0
//
// 004365b0  6aff                 push -1
// 004365b2  6858a29900           push 0x99a258
// 004365b7  64a100000000         mov eax, dword ptr fs:[0]
// 004365bd  50                   push eax
// 004365be  64892500000000       mov dword ptr fs:[0], esp
// 004365c5  51                   push ecx
// 004365c6  56                   push esi
// 004365c7  8bf1                 mov esi, ecx
// 004365c9  6a04                 push 4
// 004365cb  89742408             mov dword ptr [esp + 8], esi
// 004365cf  e8cc133700           call 0x7a79a0
// 004365d4  83c404               add esp, 4
// 004365d7  85c0                 test eax, eax
// 004365d9  7404                 je 0x4365df
// 004365db  8930                 mov dword ptr [eax], esi
// 004365dd  eb02                 jmp 0x4365e1
// 004365df  33c0                 xor eax, eax
// 004365e1  8906                 mov dword ptr [esi], eax
// 004365e3  8bce                 mov ecx, esi
// 004365e5  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004365ed  e84e340d00           call 0x509a40
// 004365f2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004365f6  894618               mov dword ptr [esi + 0x18], eax
// 004365f9  c6402901             mov byte ptr [eax + 0x29], 1
// 004365fd  8b4618               mov eax, dword ptr [esi + 0x18]
// 00436600  894004               mov dword ptr [eax + 4], eax
// 00436603  8b4618               mov eax, dword ptr [esi + 0x18]
// 00436606  8900                 mov dword ptr [eax], eax
// 00436608  8b4618               mov eax, dword ptr [esi + 0x18]
// 0043660b  894008               mov dword ptr [eax + 8], eax
// 0043660e  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00436615  8bc6                 mov eax, esi
// 00436617  5e                   pop esi
// 00436618  64890d00000000       mov dword ptr fs:[0], ecx
// 0043661f  83c410               add esp, 0x10
// 00436622  c20800               ret 8
// standard library set<string> (function ??0?$_Tree@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@std@@QAE@ABU?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@1@ABV?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@1@@Z)

// stl: set<string>
#include <string>
typedef std::string E;
#include <set>
template class std::set<E>;
