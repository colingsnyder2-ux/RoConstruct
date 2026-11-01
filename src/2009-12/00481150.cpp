// from server: 100% by auto
// roc 2009-12 00481150  unit: RBX::AdornRbxGfx  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00481150
//
// 00481150  6aff                 push -1
// 00481152  68888f9400           push 0x948f88
// 00481157  64a100000000         mov eax, dword ptr fs:[0]
// 0048115d  50                   push eax
// 0048115e  64892500000000       mov dword ptr fs:[0], esp
// 00481165  83ec0c               sub esp, 0xc
// 00481168  56                   push esi
// 00481169  8bf1                 mov esi, ecx
// 0048116b  89742404             mov dword ptr [esp + 4], esi
// 0048116f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00481172  8b0e                 mov ecx, dword ptr [esi]
// 00481174  8b10                 mov edx, dword ptr [eax]
// 00481176  50                   push eax
// 00481177  51                   push ecx
// 00481178  52                   push edx
// 00481179  51                   push ecx
// 0048117a  8d442418             lea eax, [esp + 0x18]
// 0048117e  50                   push eax
// 0048117f  8bce                 mov ecx, esi
// 00481181  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 00481189  e812f8ffff           call 0x4809a0
// 0048118e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00481191  51                   push ecx
// 00481192  e8c3263700           call 0x7f385a
// 00481197  8b16                 mov edx, dword ptr [esi]
// 00481199  52                   push edx
// 0048119a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 004811a1  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 004811a8  e8ad263700           call 0x7f385a
// 004811ad  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004811b1  83c408               add esp, 8
// 004811b4  5e                   pop esi
// 004811b5  64890d00000000       mov dword ptr fs:[0], ecx
// 004811bc  83c418               add esp, 0x18
// 004811bf  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
