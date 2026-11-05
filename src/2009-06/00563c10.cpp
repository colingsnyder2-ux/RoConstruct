// from server: 100% by auto
// roc 2009-06 00563c10  unit: RBX::VBeveledBlockMesh::?$CustomizableMesh  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00563c10
//
// 00563c10  6aff                 push -1
// 00563c12  68485e8500           push 0x855e48
// 00563c17  64a100000000         mov eax, dword ptr fs:[0]
// 00563c1d  50                   push eax
// 00563c1e  64892500000000       mov dword ptr fs:[0], esp
// 00563c25  83ec0c               sub esp, 0xc
// 00563c28  56                   push esi
// 00563c29  8bf1                 mov esi, ecx
// 00563c2b  89742404             mov dword ptr [esp + 4], esi
// 00563c2f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00563c32  8b0e                 mov ecx, dword ptr [esi]
// 00563c34  8b10                 mov edx, dword ptr [eax]
// 00563c36  50                   push eax
// 00563c37  51                   push ecx
// 00563c38  52                   push edx
// 00563c39  51                   push ecx
// 00563c3a  8d442418             lea eax, [esp + 0x18]
// 00563c3e  50                   push eax
// 00563c3f  8bce                 mov ecx, esi
// 00563c41  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 00563c49  e842fdffff           call 0x563990
// 00563c4e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00563c51  51                   push ecx
// 00563c52  e8db4d1b00           call 0x718a32
// 00563c57  8b16                 mov edx, dword ptr [esi]
// 00563c59  52                   push edx
// 00563c5a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00563c61  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00563c68  e8c54d1b00           call 0x718a32
// 00563c6d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00563c71  83c408               add esp, 8
// 00563c74  5e                   pop esi
// 00563c75  64890d00000000       mov dword ptr fs:[0], ecx
// 00563c7c  83c418               add esp, 0x18
// 00563c7f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
