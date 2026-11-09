// from server: 100% by auto
// roc 2009-12 00440d10  unit: HVCXTPPropertyGridItemEnum::?$XItem  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00440d10
//
// 00440d10  6aff                 push -1
// 00440d12  68888f9400           push 0x948f88
// 00440d17  64a100000000         mov eax, dword ptr fs:[0]
// 00440d1d  50                   push eax
// 00440d1e  64892500000000       mov dword ptr fs:[0], esp
// 00440d25  83ec0c               sub esp, 0xc
// 00440d28  56                   push esi
// 00440d29  8bf1                 mov esi, ecx
// 00440d2b  89742404             mov dword ptr [esp + 4], esi
// 00440d2f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00440d32  8b0e                 mov ecx, dword ptr [esi]
// 00440d34  8b10                 mov edx, dword ptr [eax]
// 00440d36  50                   push eax
// 00440d37  51                   push ecx
// 00440d38  52                   push edx
// 00440d39  51                   push ecx
// 00440d3a  8d442418             lea eax, [esp + 0x18]
// 00440d3e  50                   push eax
// 00440d3f  8bce                 mov ecx, esi
// 00440d41  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 00440d49  e842feffff           call 0x440b90
// 00440d4e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00440d51  51                   push ecx
// 00440d52  e8032b3b00           call 0x7f385a
// 00440d57  8b16                 mov edx, dword ptr [esi]
// 00440d59  52                   push edx
// 00440d5a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00440d61  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00440d68  e8ed2a3b00           call 0x7f385a
// 00440d6d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00440d71  83c408               add esp, 8
// 00440d74  5e                   pop esi
// 00440d75  64890d00000000       mov dword ptr fs:[0], ecx
// 00440d7c  83c418               add esp, 0x18
// 00440d7f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
