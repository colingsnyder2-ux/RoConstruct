// from server: 100% by auto
// roc 2009-06 006230b0  unit: ArchiveBinder  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006230b0
//
// 006230b0  6aff                 push -1
// 006230b2  68485e8500           push 0x855e48
// 006230b7  64a100000000         mov eax, dword ptr fs:[0]
// 006230bd  50                   push eax
// 006230be  64892500000000       mov dword ptr fs:[0], esp
// 006230c5  83ec0c               sub esp, 0xc
// 006230c8  56                   push esi
// 006230c9  8bf1                 mov esi, ecx
// 006230cb  89742404             mov dword ptr [esp + 4], esi
// 006230cf  8b4618               mov eax, dword ptr [esi + 0x18]
// 006230d2  8b0e                 mov ecx, dword ptr [esi]
// 006230d4  8b10                 mov edx, dword ptr [eax]
// 006230d6  50                   push eax
// 006230d7  51                   push ecx
// 006230d8  52                   push edx
// 006230d9  51                   push ecx
// 006230da  8d442418             lea eax, [esp + 0x18]
// 006230de  50                   push eax
// 006230df  8bce                 mov ecx, esi
// 006230e1  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 006230e9  e832fcffff           call 0x622d20
// 006230ee  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006230f1  51                   push ecx
// 006230f2  e83b590f00           call 0x718a32
// 006230f7  8b16                 mov edx, dword ptr [esi]
// 006230f9  52                   push edx
// 006230fa  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00623101  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00623108  e825590f00           call 0x718a32
// 0062310d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00623111  83c408               add esp, 8
// 00623114  5e                   pop esi
// 00623115  64890d00000000       mov dword ptr fs:[0], ecx
// 0062311c  83c418               add esp, 0x18
// 0062311f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
