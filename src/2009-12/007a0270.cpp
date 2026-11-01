// from server: 100% by auto
// roc 2009-12 007a0270  unit: seg_007a0000  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007a0270
//
// 007a0270  6aff                 push -1
// 007a0272  68888f9400           push 0x948f88
// 007a0277  64a100000000         mov eax, dword ptr fs:[0]
// 007a027d  50                   push eax
// 007a027e  64892500000000       mov dword ptr fs:[0], esp
// 007a0285  83ec0c               sub esp, 0xc
// 007a0288  56                   push esi
// 007a0289  8bf1                 mov esi, ecx
// 007a028b  89742404             mov dword ptr [esp + 4], esi
// 007a028f  8b4618               mov eax, dword ptr [esi + 0x18]
// 007a0292  8b0e                 mov ecx, dword ptr [esi]
// 007a0294  8b10                 mov edx, dword ptr [eax]
// 007a0296  50                   push eax
// 007a0297  51                   push ecx
// 007a0298  52                   push edx
// 007a0299  51                   push ecx
// 007a029a  8d442418             lea eax, [esp + 0x18]
// 007a029e  50                   push eax
// 007a029f  8bce                 mov ecx, esi
// 007a02a1  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 007a02a9  e8d2fdffff           call 0x7a0080
// 007a02ae  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 007a02b1  51                   push ecx
// 007a02b2  e8a3350500           call 0x7f385a
// 007a02b7  8b16                 mov edx, dword ptr [esi]
// 007a02b9  52                   push edx
// 007a02ba  c7461800000000       mov dword ptr [esi + 0x18], 0
// 007a02c1  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 007a02c8  e88d350500           call 0x7f385a
// 007a02cd  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 007a02d1  83c408               add esp, 8
// 007a02d4  5e                   pop esi
// 007a02d5  64890d00000000       mov dword ptr fs:[0], ecx
// 007a02dc  83c418               add esp, 0x18
// 007a02df  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
