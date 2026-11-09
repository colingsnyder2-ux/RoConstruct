// from server: 100% by auto
// roc 2009-12 006b62f0  unit: RBX::Soundscape::W4ReverbType::?$EnumDesc  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006b62f0
//
// 006b62f0  6aff                 push -1
// 006b62f2  68888f9400           push 0x948f88
// 006b62f7  64a100000000         mov eax, dword ptr fs:[0]
// 006b62fd  50                   push eax
// 006b62fe  64892500000000       mov dword ptr fs:[0], esp
// 006b6305  83ec0c               sub esp, 0xc
// 006b6308  56                   push esi
// 006b6309  8bf1                 mov esi, ecx
// 006b630b  89742404             mov dword ptr [esp + 4], esi
// 006b630f  8b4618               mov eax, dword ptr [esi + 0x18]
// 006b6312  8b0e                 mov ecx, dword ptr [esi]
// 006b6314  8b10                 mov edx, dword ptr [eax]
// 006b6316  50                   push eax
// 006b6317  51                   push ecx
// 006b6318  52                   push edx
// 006b6319  51                   push ecx
// 006b631a  8d442418             lea eax, [esp + 0x18]
// 006b631e  50                   push eax
// 006b631f  8bce                 mov ecx, esi
// 006b6321  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 006b6329  e852f8ffff           call 0x6b5b80
// 006b632e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006b6331  51                   push ecx
// 006b6332  e823d51300           call 0x7f385a
// 006b6337  8b16                 mov edx, dword ptr [esi]
// 006b6339  52                   push edx
// 006b633a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 006b6341  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 006b6348  e80dd51300           call 0x7f385a
// 006b634d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 006b6351  83c408               add esp, 8
// 006b6354  5e                   pop esi
// 006b6355  64890d00000000       mov dword ptr fs:[0], ecx
// 006b635c  83c418               add esp, 0x18
// 006b635f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
