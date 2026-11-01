// from server: 100% by auto
// roc 2009-12 005d2ff0  unit: RBX::G3DPart  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005d2ff0
//
// 005d2ff0  6aff                 push -1
// 005d2ff2  68888f9400           push 0x948f88
// 005d2ff7  64a100000000         mov eax, dword ptr fs:[0]
// 005d2ffd  50                   push eax
// 005d2ffe  64892500000000       mov dword ptr fs:[0], esp
// 005d3005  83ec0c               sub esp, 0xc
// 005d3008  56                   push esi
// 005d3009  8bf1                 mov esi, ecx
// 005d300b  89742404             mov dword ptr [esp + 4], esi
// 005d300f  8b4618               mov eax, dword ptr [esi + 0x18]
// 005d3012  8b0e                 mov ecx, dword ptr [esi]
// 005d3014  8b10                 mov edx, dword ptr [eax]
// 005d3016  50                   push eax
// 005d3017  51                   push ecx
// 005d3018  52                   push edx
// 005d3019  51                   push ecx
// 005d301a  8d442418             lea eax, [esp + 0x18]
// 005d301e  50                   push eax
// 005d301f  8bce                 mov ecx, esi
// 005d3021  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 005d3029  e862f2ffff           call 0x5d2290
// 005d302e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 005d3031  51                   push ecx
// 005d3032  e823082200           call 0x7f385a
// 005d3037  8b16                 mov edx, dword ptr [esi]
// 005d3039  52                   push edx
// 005d303a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 005d3041  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 005d3048  e80d082200           call 0x7f385a
// 005d304d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005d3051  83c408               add esp, 8
// 005d3054  5e                   pop esi
// 005d3055  64890d00000000       mov dword ptr fs:[0], ecx
// 005d305c  83c418               add esp, 0x18
// 005d305f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
