// from server: 100% by auto
// roc 2009-12 0048f9b0  unit: RBX::RbxTextureProxy  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0048f9b0
//
// 0048f9b0  6aff                 push -1
// 0048f9b2  68888f9400           push 0x948f88
// 0048f9b7  64a100000000         mov eax, dword ptr fs:[0]
// 0048f9bd  50                   push eax
// 0048f9be  64892500000000       mov dword ptr fs:[0], esp
// 0048f9c5  83ec0c               sub esp, 0xc
// 0048f9c8  56                   push esi
// 0048f9c9  8bf1                 mov esi, ecx
// 0048f9cb  89742404             mov dword ptr [esp + 4], esi
// 0048f9cf  8b4618               mov eax, dword ptr [esi + 0x18]
// 0048f9d2  8b0e                 mov ecx, dword ptr [esi]
// 0048f9d4  8b10                 mov edx, dword ptr [eax]
// 0048f9d6  50                   push eax
// 0048f9d7  51                   push ecx
// 0048f9d8  52                   push edx
// 0048f9d9  51                   push ecx
// 0048f9da  8d442418             lea eax, [esp + 0x18]
// 0048f9de  50                   push eax
// 0048f9df  8bce                 mov ecx, esi
// 0048f9e1  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 0048f9e9  e832feffff           call 0x48f820
// 0048f9ee  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0048f9f1  51                   push ecx
// 0048f9f2  e8633e3600           call 0x7f385a
// 0048f9f7  8b16                 mov edx, dword ptr [esi]
// 0048f9f9  52                   push edx
// 0048f9fa  c7461800000000       mov dword ptr [esi + 0x18], 0
// 0048fa01  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0048fa08  e84d3e3600           call 0x7f385a
// 0048fa0d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0048fa11  83c408               add esp, 8
// 0048fa14  5e                   pop esi
// 0048fa15  64890d00000000       mov dword ptr fs:[0], ecx
// 0048fa1c  83c418               add esp, 0x18
// 0048fa1f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
