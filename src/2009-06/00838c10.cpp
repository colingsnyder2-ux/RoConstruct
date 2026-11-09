// from server: 100% by auto
// roc 2009-06 00838c10  unit: RBX::RenderNew::TextureProxy  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00838c10
//
// 00838c10  6aff                 push -1
// 00838c12  68485e8500           push 0x855e48
// 00838c17  64a100000000         mov eax, dword ptr fs:[0]
// 00838c1d  50                   push eax
// 00838c1e  64892500000000       mov dword ptr fs:[0], esp
// 00838c25  83ec0c               sub esp, 0xc
// 00838c28  56                   push esi
// 00838c29  8bf1                 mov esi, ecx
// 00838c2b  89742404             mov dword ptr [esp + 4], esi
// 00838c2f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00838c32  8b0e                 mov ecx, dword ptr [esi]
// 00838c34  8b10                 mov edx, dword ptr [eax]
// 00838c36  50                   push eax
// 00838c37  51                   push ecx
// 00838c38  52                   push edx
// 00838c39  51                   push ecx
// 00838c3a  8d442418             lea eax, [esp + 0x18]
// 00838c3e  50                   push eax
// 00838c3f  8bce                 mov ecx, esi
// 00838c41  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 00838c49  e832feffff           call 0x838a80
// 00838c4e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00838c51  51                   push ecx
// 00838c52  e8dbfdedff           call 0x718a32
// 00838c57  8b16                 mov edx, dword ptr [esi]
// 00838c59  52                   push edx
// 00838c5a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00838c61  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00838c68  e8c5fdedff           call 0x718a32
// 00838c6d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00838c71  83c408               add esp, 8
// 00838c74  5e                   pop esi
// 00838c75  64890d00000000       mov dword ptr fs:[0], ecx
// 00838c7c  83c418               add esp, 0x18
// 00838c7f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
