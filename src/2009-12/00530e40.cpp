// from server: 100% by auto
// roc 2009-12 00530e40  unit: RBX::VInstance::$$A6AXV?$shared_ptr::?$signal::Vslot::?$sp_counted_impl_p  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00530e40
//
// 00530e40  6aff                 push -1
// 00530e42  68888f9400           push 0x948f88
// 00530e47  64a100000000         mov eax, dword ptr fs:[0]
// 00530e4d  50                   push eax
// 00530e4e  64892500000000       mov dword ptr fs:[0], esp
// 00530e55  83ec0c               sub esp, 0xc
// 00530e58  56                   push esi
// 00530e59  8bf1                 mov esi, ecx
// 00530e5b  89742404             mov dword ptr [esp + 4], esi
// 00530e5f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00530e62  8b0e                 mov ecx, dword ptr [esi]
// 00530e64  8b10                 mov edx, dword ptr [eax]
// 00530e66  50                   push eax
// 00530e67  51                   push ecx
// 00530e68  52                   push edx
// 00530e69  51                   push ecx
// 00530e6a  8d442418             lea eax, [esp + 0x18]
// 00530e6e  50                   push eax
// 00530e6f  8bce                 mov ecx, esi
// 00530e71  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 00530e79  e882f5ffff           call 0x530400
// 00530e7e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00530e81  51                   push ecx
// 00530e82  e8d3292c00           call 0x7f385a
// 00530e87  8b16                 mov edx, dword ptr [esi]
// 00530e89  52                   push edx
// 00530e8a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00530e91  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00530e98  e8bd292c00           call 0x7f385a
// 00530e9d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00530ea1  83c408               add esp, 8
// 00530ea4  5e                   pop esi
// 00530ea5  64890d00000000       mov dword ptr fs:[0], ecx
// 00530eac  83c418               add esp, 0x18
// 00530eaf  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
