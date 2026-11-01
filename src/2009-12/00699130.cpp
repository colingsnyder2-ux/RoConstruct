// from server: 100% by auto
// roc 2009-12 00699130  unit: RBX::Workspace  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00699130
//
// 00699130  6aff                 push -1
// 00699132  68888f9400           push 0x948f88
// 00699137  64a100000000         mov eax, dword ptr fs:[0]
// 0069913d  50                   push eax
// 0069913e  64892500000000       mov dword ptr fs:[0], esp
// 00699145  83ec0c               sub esp, 0xc
// 00699148  56                   push esi
// 00699149  8bf1                 mov esi, ecx
// 0069914b  89742404             mov dword ptr [esp + 4], esi
// 0069914f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00699152  8b0e                 mov ecx, dword ptr [esi]
// 00699154  8b10                 mov edx, dword ptr [eax]
// 00699156  50                   push eax
// 00699157  51                   push ecx
// 00699158  52                   push edx
// 00699159  51                   push ecx
// 0069915a  8d442418             lea eax, [esp + 0x18]
// 0069915e  50                   push eax
// 0069915f  8bce                 mov ecx, esi
// 00699161  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 00699169  e892f8ffff           call 0x698a00
// 0069916e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00699171  51                   push ecx
// 00699172  e8e3a61500           call 0x7f385a
// 00699177  8b16                 mov edx, dword ptr [esi]
// 00699179  52                   push edx
// 0069917a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00699181  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00699188  e8cda61500           call 0x7f385a
// 0069918d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00699191  83c408               add esp, 8
// 00699194  5e                   pop esi
// 00699195  64890d00000000       mov dword ptr fs:[0], ecx
// 0069919c  83c418               add esp, 0x18
// 0069919f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
