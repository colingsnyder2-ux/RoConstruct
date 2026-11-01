// from server: 100% by auto
// roc 2009-12 0066aea0  unit: RBX::DataModel  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0066aea0
//
// 0066aea0  6aff                 push -1
// 0066aea2  68888f9400           push 0x948f88
// 0066aea7  64a100000000         mov eax, dword ptr fs:[0]
// 0066aead  50                   push eax
// 0066aeae  64892500000000       mov dword ptr fs:[0], esp
// 0066aeb5  83ec0c               sub esp, 0xc
// 0066aeb8  56                   push esi
// 0066aeb9  8bf1                 mov esi, ecx
// 0066aebb  89742404             mov dword ptr [esp + 4], esi
// 0066aebf  8b4618               mov eax, dword ptr [esi + 0x18]
// 0066aec2  8b0e                 mov ecx, dword ptr [esi]
// 0066aec4  8b10                 mov edx, dword ptr [eax]
// 0066aec6  50                   push eax
// 0066aec7  51                   push ecx
// 0066aec8  52                   push edx
// 0066aec9  51                   push ecx
// 0066aeca  8d442418             lea eax, [esp + 0x18]
// 0066aece  50                   push eax
// 0066aecf  8bce                 mov ecx, esi
// 0066aed1  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 0066aed9  e802f4ffff           call 0x66a2e0
// 0066aede  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0066aee1  51                   push ecx
// 0066aee2  e873891800           call 0x7f385a
// 0066aee7  8b16                 mov edx, dword ptr [esi]
// 0066aee9  52                   push edx
// 0066aeea  c7461800000000       mov dword ptr [esi + 0x18], 0
// 0066aef1  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0066aef8  e85d891800           call 0x7f385a
// 0066aefd  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0066af01  83c408               add esp, 8
// 0066af04  5e                   pop esi
// 0066af05  64890d00000000       mov dword ptr fs:[0], ecx
// 0066af0c  83c418               add esp, 0x18
// 0066af0f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
