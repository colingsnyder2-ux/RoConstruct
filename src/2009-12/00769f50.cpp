// from server: 100% by auto
// roc 2009-12 00769f50  unit: RBX::VInstance::?$NonFactoryProduct  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00769f50
//
// 00769f50  6aff                 push -1
// 00769f52  68888f9400           push 0x948f88
// 00769f57  64a100000000         mov eax, dword ptr fs:[0]
// 00769f5d  50                   push eax
// 00769f5e  64892500000000       mov dword ptr fs:[0], esp
// 00769f65  83ec0c               sub esp, 0xc
// 00769f68  56                   push esi
// 00769f69  8bf1                 mov esi, ecx
// 00769f6b  89742404             mov dword ptr [esp + 4], esi
// 00769f6f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00769f72  8b0e                 mov ecx, dword ptr [esi]
// 00769f74  8b10                 mov edx, dword ptr [eax]
// 00769f76  50                   push eax
// 00769f77  51                   push ecx
// 00769f78  52                   push edx
// 00769f79  51                   push ecx
// 00769f7a  8d442418             lea eax, [esp + 0x18]
// 00769f7e  50                   push eax
// 00769f7f  8bce                 mov ecx, esi
// 00769f81  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 00769f89  e8e2f4ffff           call 0x769470
// 00769f8e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00769f91  51                   push ecx
// 00769f92  e8c3980800           call 0x7f385a
// 00769f97  8b16                 mov edx, dword ptr [esi]
// 00769f99  52                   push edx
// 00769f9a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00769fa1  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00769fa8  e8ad980800           call 0x7f385a
// 00769fad  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00769fb1  83c408               add esp, 8
// 00769fb4  5e                   pop esi
// 00769fb5  64890d00000000       mov dword ptr fs:[0], ecx
// 00769fbc  83c418               add esp, 0x18
// 00769fbf  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
