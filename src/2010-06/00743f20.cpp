// from server: 100% by auto
// roc 2010-06 00743f20  unit: RBX::VHttp::?$sp_counted_impl_p  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00743f20
//
// 00743f20  6aff                 push -1
// 00743f22  6858a29900           push 0x99a258
// 00743f27  64a100000000         mov eax, dword ptr fs:[0]
// 00743f2d  50                   push eax
// 00743f2e  64892500000000       mov dword ptr fs:[0], esp
// 00743f35  51                   push ecx
// 00743f36  56                   push esi
// 00743f37  8bf1                 mov esi, ecx
// 00743f39  89742404             mov dword ptr [esp + 4], esi
// 00743f3d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00743f45  e876fcffff           call 0x743bc0
// 00743f4a  8b4614               mov eax, dword ptr [esi + 0x14]
// 00743f4d  50                   push eax
// 00743f4e  e8473a0600           call 0x7a799a
// 00743f53  8b0e                 mov ecx, dword ptr [esi]
// 00743f55  51                   push ecx
// 00743f56  c7461400000000       mov dword ptr [esi + 0x14], 0
// 00743f5d  e8383a0600           call 0x7a799a
// 00743f62  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00743f66  83c408               add esp, 8
// 00743f69  5e                   pop esi
// 00743f6a  64890d00000000       mov dword ptr fs:[0], ecx
// 00743f71  83c410               add esp, 0x10
// 00743f74  c3                   ret 
// standard library list<string> (function ??1?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
