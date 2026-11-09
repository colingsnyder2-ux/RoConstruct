// from server: 100% by auto
// roc 2010-06 0075add0  unit: RBX::PrismPoly  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0075add0
//
// 0075add0  6aff                 push -1
// 0075add2  68b8d19b00           push 0x9bd1b8
// 0075add7  64a100000000         mov eax, dword ptr fs:[0]
// 0075addd  50                   push eax
// 0075adde  64892500000000       mov dword ptr fs:[0], esp
// 0075ade5  83ec0c               sub esp, 0xc
// 0075ade8  56                   push esi
// 0075ade9  8bf1                 mov esi, ecx
// 0075adeb  89742404             mov dword ptr [esp + 4], esi
// 0075adef  8b4618               mov eax, dword ptr [esi + 0x18]
// 0075adf2  8b0e                 mov ecx, dword ptr [esi]
// 0075adf4  8b10                 mov edx, dword ptr [eax]
// 0075adf6  50                   push eax
// 0075adf7  51                   push ecx
// 0075adf8  52                   push edx
// 0075adf9  51                   push ecx
// 0075adfa  8d442418             lea eax, [esp + 0x18]
// 0075adfe  50                   push eax
// 0075adff  8bce                 mov ecx, esi
// 0075ae01  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 0075ae09  e8b20a0000           call 0x75b8c0
// 0075ae0e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0075ae11  51                   push ecx
// 0075ae12  e883cb0400           call 0x7a799a
// 0075ae17  8b16                 mov edx, dword ptr [esi]
// 0075ae19  52                   push edx
// 0075ae1a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 0075ae21  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0075ae28  e86dcb0400           call 0x7a799a
// 0075ae2d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0075ae31  83c408               add esp, 8
// 0075ae34  5e                   pop esi
// 0075ae35  64890d00000000       mov dword ptr fs:[0], ecx
// 0075ae3c  83c418               add esp, 0x18
// 0075ae3f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
