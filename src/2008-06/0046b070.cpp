// from server: 100% by auto
// roc 2008-06 0046b070  unit: VCWorkspace::?$CComObject  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0046b070
//
// 0046b070  6aff                 push -1
// 0046b072  6828d97b00           push 0x7bd928
// 0046b077  64a100000000         mov eax, dword ptr fs:[0]
// 0046b07d  50                   push eax
// 0046b07e  64892500000000       mov dword ptr fs:[0], esp
// 0046b085  83ec0c               sub esp, 0xc
// 0046b088  56                   push esi
// 0046b089  8bf1                 mov esi, ecx
// 0046b08b  89742404             mov dword ptr [esp + 4], esi
// 0046b08f  8b4618               mov eax, dword ptr [esi + 0x18]
// 0046b092  8b0e                 mov ecx, dword ptr [esi]
// 0046b094  8b10                 mov edx, dword ptr [eax]
// 0046b096  50                   push eax
// 0046b097  51                   push ecx
// 0046b098  52                   push edx
// 0046b099  51                   push ecx
// 0046b09a  8d442418             lea eax, [esp + 0x18]
// 0046b09e  50                   push eax
// 0046b09f  8bce                 mov ecx, esi
// 0046b0a1  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 0046b0a9  e8e2feffff           call 0x46af90
// 0046b0ae  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0046b0b1  51                   push ecx
// 0046b0b2  e8c3552300           call 0x6a067a
// 0046b0b7  8b16                 mov edx, dword ptr [esi]
// 0046b0b9  52                   push edx
// 0046b0ba  c7461800000000       mov dword ptr [esi + 0x18], 0
// 0046b0c1  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0046b0c8  e8ad552300           call 0x6a067a
// 0046b0cd  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0046b0d1  83c408               add esp, 8
// 0046b0d4  5e                   pop esi
// 0046b0d5  64890d00000000       mov dword ptr fs:[0], ecx
// 0046b0dc  83c418               add esp, 0x18
// 0046b0df  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
