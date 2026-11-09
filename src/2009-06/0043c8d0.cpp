// from server: 100% by auto
// roc 2009-06 0043c8d0  unit: HVCXTPPropertyGridItemEnum::?$XItem  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0043c8d0
//
// 0043c8d0  6aff                 push -1
// 0043c8d2  68485e8500           push 0x855e48
// 0043c8d7  64a100000000         mov eax, dword ptr fs:[0]
// 0043c8dd  50                   push eax
// 0043c8de  64892500000000       mov dword ptr fs:[0], esp
// 0043c8e5  83ec0c               sub esp, 0xc
// 0043c8e8  56                   push esi
// 0043c8e9  8bf1                 mov esi, ecx
// 0043c8eb  89742404             mov dword ptr [esp + 4], esi
// 0043c8ef  8b4618               mov eax, dword ptr [esi + 0x18]
// 0043c8f2  8b0e                 mov ecx, dword ptr [esi]
// 0043c8f4  8b10                 mov edx, dword ptr [eax]
// 0043c8f6  50                   push eax
// 0043c8f7  51                   push ecx
// 0043c8f8  52                   push edx
// 0043c8f9  51                   push ecx
// 0043c8fa  8d442418             lea eax, [esp + 0x18]
// 0043c8fe  50                   push eax
// 0043c8ff  8bce                 mov ecx, esi
// 0043c901  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 0043c909  e842feffff           call 0x43c750
// 0043c90e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0043c911  51                   push ecx
// 0043c912  e81bc12d00           call 0x718a32
// 0043c917  8b16                 mov edx, dword ptr [esi]
// 0043c919  52                   push edx
// 0043c91a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 0043c921  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0043c928  e805c12d00           call 0x718a32
// 0043c92d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0043c931  83c408               add esp, 8
// 0043c934  5e                   pop esi
// 0043c935  64890d00000000       mov dword ptr fs:[0], ecx
// 0043c93c  83c418               add esp, 0x18
// 0043c93f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
