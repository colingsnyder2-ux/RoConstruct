// from server: 100% by auto
// roc 2009-06 004fca90  unit: RBX::Network::ServerReplicator  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004fca90
//
// 004fca90  6aff                 push -1
// 004fca92  68485e8500           push 0x855e48
// 004fca97  64a100000000         mov eax, dword ptr fs:[0]
// 004fca9d  50                   push eax
// 004fca9e  64892500000000       mov dword ptr fs:[0], esp
// 004fcaa5  83ec0c               sub esp, 0xc
// 004fcaa8  56                   push esi
// 004fcaa9  8bf1                 mov esi, ecx
// 004fcaab  89742404             mov dword ptr [esp + 4], esi
// 004fcaaf  8b4618               mov eax, dword ptr [esi + 0x18]
// 004fcab2  8b0e                 mov ecx, dword ptr [esi]
// 004fcab4  8b10                 mov edx, dword ptr [eax]
// 004fcab6  50                   push eax
// 004fcab7  51                   push ecx
// 004fcab8  52                   push edx
// 004fcab9  51                   push ecx
// 004fcaba  8d442418             lea eax, [esp + 0x18]
// 004fcabe  50                   push eax
// 004fcabf  8bce                 mov ecx, esi
// 004fcac1  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 004fcac9  e8f2faffff           call 0x4fc5c0
// 004fcace  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004fcad1  51                   push ecx
// 004fcad2  e85bbf2100           call 0x718a32
// 004fcad7  8b16                 mov edx, dword ptr [esi]
// 004fcad9  52                   push edx
// 004fcada  c7461800000000       mov dword ptr [esi + 0x18], 0
// 004fcae1  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 004fcae8  e845bf2100           call 0x718a32
// 004fcaed  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004fcaf1  83c408               add esp, 8
// 004fcaf4  5e                   pop esi
// 004fcaf5  64890d00000000       mov dword ptr fs:[0], ecx
// 004fcafc  83c418               add esp, 0x18
// 004fcaff  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
