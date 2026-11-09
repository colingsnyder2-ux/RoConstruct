// from server: 100% by auto
// roc 2009-06 005ea2e0  unit: G3D::VVector3::?$TypedPropertyDescriptor  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005ea2e0
//
// 005ea2e0  6aff                 push -1
// 005ea2e2  68485e8500           push 0x855e48
// 005ea2e7  64a100000000         mov eax, dword ptr fs:[0]
// 005ea2ed  50                   push eax
// 005ea2ee  64892500000000       mov dword ptr fs:[0], esp
// 005ea2f5  83ec0c               sub esp, 0xc
// 005ea2f8  56                   push esi
// 005ea2f9  8bf1                 mov esi, ecx
// 005ea2fb  89742404             mov dword ptr [esp + 4], esi
// 005ea2ff  8b4618               mov eax, dword ptr [esi + 0x18]
// 005ea302  8b0e                 mov ecx, dword ptr [esi]
// 005ea304  8b10                 mov edx, dword ptr [eax]
// 005ea306  50                   push eax
// 005ea307  51                   push ecx
// 005ea308  52                   push edx
// 005ea309  51                   push ecx
// 005ea30a  8d442418             lea eax, [esp + 0x18]
// 005ea30e  50                   push eax
// 005ea30f  8bce                 mov ecx, esi
// 005ea311  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 005ea319  e80279e1ff           call 0x401c20
// 005ea31e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 005ea321  51                   push ecx
// 005ea322  e80be71200           call 0x718a32
// 005ea327  8b16                 mov edx, dword ptr [esi]
// 005ea329  52                   push edx
// 005ea32a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 005ea331  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 005ea338  e8f5e61200           call 0x718a32
// 005ea33d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005ea341  83c408               add esp, 8
// 005ea344  5e                   pop esi
// 005ea345  64890d00000000       mov dword ptr fs:[0], ecx
// 005ea34c  83c418               add esp, 0x18
// 005ea34f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
