// from server: 100% by auto
// roc 2009-12 007b0950  unit: RBX::Block  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007b0950
//
// 007b0950  6aff                 push -1
// 007b0952  68888f9400           push 0x948f88
// 007b0957  64a100000000         mov eax, dword ptr fs:[0]
// 007b095d  50                   push eax
// 007b095e  64892500000000       mov dword ptr fs:[0], esp
// 007b0965  83ec0c               sub esp, 0xc
// 007b0968  56                   push esi
// 007b0969  8bf1                 mov esi, ecx
// 007b096b  89742404             mov dword ptr [esp + 4], esi
// 007b096f  8b4618               mov eax, dword ptr [esi + 0x18]
// 007b0972  8b0e                 mov ecx, dword ptr [esi]
// 007b0974  8b10                 mov edx, dword ptr [eax]
// 007b0976  50                   push eax
// 007b0977  51                   push ecx
// 007b0978  52                   push edx
// 007b0979  51                   push ecx
// 007b097a  8d442418             lea eax, [esp + 0x18]
// 007b097e  50                   push eax
// 007b097f  8bce                 mov ecx, esi
// 007b0981  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 007b0989  e8c2faffff           call 0x7b0450
// 007b098e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 007b0991  51                   push ecx
// 007b0992  e8c32e0400           call 0x7f385a
// 007b0997  8b16                 mov edx, dword ptr [esi]
// 007b0999  52                   push edx
// 007b099a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 007b09a1  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 007b09a8  e8ad2e0400           call 0x7f385a
// 007b09ad  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 007b09b1  83c408               add esp, 8
// 007b09b4  5e                   pop esi
// 007b09b5  64890d00000000       mov dword ptr fs:[0], ecx
// 007b09bc  83c418               add esp, 0x18
// 007b09bf  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
