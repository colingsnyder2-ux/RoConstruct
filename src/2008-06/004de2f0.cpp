// from server: 100% by auto
// roc 2008-06 004de2f0  unit: RBX::RenderBase::Mesh::Level  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004de2f0
//
// 004de2f0  6aff                 push -1
// 004de2f2  6828d97b00           push 0x7bd928
// 004de2f7  64a100000000         mov eax, dword ptr fs:[0]
// 004de2fd  50                   push eax
// 004de2fe  64892500000000       mov dword ptr fs:[0], esp
// 004de305  83ec0c               sub esp, 0xc
// 004de308  56                   push esi
// 004de309  8bf1                 mov esi, ecx
// 004de30b  89742404             mov dword ptr [esp + 4], esi
// 004de30f  8b4618               mov eax, dword ptr [esi + 0x18]
// 004de312  8b0e                 mov ecx, dword ptr [esi]
// 004de314  8b10                 mov edx, dword ptr [eax]
// 004de316  50                   push eax
// 004de317  51                   push ecx
// 004de318  52                   push edx
// 004de319  51                   push ecx
// 004de31a  8d442418             lea eax, [esp + 0x18]
// 004de31e  50                   push eax
// 004de31f  8bce                 mov ecx, esi
// 004de321  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 004de329  e802fbffff           call 0x4dde30
// 004de32e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004de331  51                   push ecx
// 004de332  e843231c00           call 0x6a067a
// 004de337  8b16                 mov edx, dword ptr [esi]
// 004de339  52                   push edx
// 004de33a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 004de341  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 004de348  e82d231c00           call 0x6a067a
// 004de34d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004de351  83c408               add esp, 8
// 004de354  5e                   pop esi
// 004de355  64890d00000000       mov dword ptr fs:[0], ecx
// 004de35c  83c418               add esp, 0x18
// 004de35f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
