// from server: 100% by auto
// roc 2009-06 00414d10  unit: CopyVerb  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00414d10
//
// 00414d10  6aff                 push -1
// 00414d12  68485e8500           push 0x855e48
// 00414d17  64a100000000         mov eax, dword ptr fs:[0]
// 00414d1d  50                   push eax
// 00414d1e  64892500000000       mov dword ptr fs:[0], esp
// 00414d25  83ec0c               sub esp, 0xc
// 00414d28  56                   push esi
// 00414d29  8bf1                 mov esi, ecx
// 00414d2b  89742404             mov dword ptr [esp + 4], esi
// 00414d2f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00414d32  8b0e                 mov ecx, dword ptr [esi]
// 00414d34  8b10                 mov edx, dword ptr [eax]
// 00414d36  50                   push eax
// 00414d37  51                   push ecx
// 00414d38  52                   push edx
// 00414d39  51                   push ecx
// 00414d3a  8d442418             lea eax, [esp + 0x18]
// 00414d3e  50                   push eax
// 00414d3f  8bce                 mov ecx, esi
// 00414d41  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 00414d49  e8a2fdffff           call 0x414af0
// 00414d4e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00414d51  51                   push ecx
// 00414d52  e8db3c3000           call 0x718a32
// 00414d57  8b16                 mov edx, dword ptr [esi]
// 00414d59  52                   push edx
// 00414d5a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00414d61  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00414d68  e8c53c3000           call 0x718a32
// 00414d6d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00414d71  83c408               add esp, 8
// 00414d74  5e                   pop esi
// 00414d75  64890d00000000       mov dword ptr fs:[0], ecx
// 00414d7c  83c418               add esp, 0x18
// 00414d7f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
