// from server: 100% by auto
// roc 2009-06 0063ff10  unit: RBX::Accoutrement  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0063ff10
//
// 0063ff10  6aff                 push -1
// 0063ff12  68485e8500           push 0x855e48
// 0063ff17  64a100000000         mov eax, dword ptr fs:[0]
// 0063ff1d  50                   push eax
// 0063ff1e  64892500000000       mov dword ptr fs:[0], esp
// 0063ff25  83ec0c               sub esp, 0xc
// 0063ff28  56                   push esi
// 0063ff29  8bf1                 mov esi, ecx
// 0063ff2b  89742404             mov dword ptr [esp + 4], esi
// 0063ff2f  8b4618               mov eax, dword ptr [esi + 0x18]
// 0063ff32  8b0e                 mov ecx, dword ptr [esi]
// 0063ff34  8b10                 mov edx, dword ptr [eax]
// 0063ff36  50                   push eax
// 0063ff37  51                   push ecx
// 0063ff38  52                   push edx
// 0063ff39  51                   push ecx
// 0063ff3a  8d442418             lea eax, [esp + 0x18]
// 0063ff3e  50                   push eax
// 0063ff3f  8bce                 mov ecx, esi
// 0063ff41  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 0063ff49  e842fbffff           call 0x63fa90
// 0063ff4e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0063ff51  51                   push ecx
// 0063ff52  e8db8a0d00           call 0x718a32
// 0063ff57  8b16                 mov edx, dword ptr [esi]
// 0063ff59  52                   push edx
// 0063ff5a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 0063ff61  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0063ff68  e8c58a0d00           call 0x718a32
// 0063ff6d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0063ff71  83c408               add esp, 8
// 0063ff74  5e                   pop esi
// 0063ff75  64890d00000000       mov dword ptr fs:[0], ecx
// 0063ff7c  83c418               add esp, 0x18
// 0063ff7f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
