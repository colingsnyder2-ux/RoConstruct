// from server: 100% by auto
// roc 2009-06 004d91f0  unit: RBX::Network::VGuidRegistryService::?$FactoryProduct  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004d91f0
//
// 004d91f0  6aff                 push -1
// 004d91f2  68485e8500           push 0x855e48
// 004d91f7  64a100000000         mov eax, dword ptr fs:[0]
// 004d91fd  50                   push eax
// 004d91fe  64892500000000       mov dword ptr fs:[0], esp
// 004d9205  83ec0c               sub esp, 0xc
// 004d9208  56                   push esi
// 004d9209  8bf1                 mov esi, ecx
// 004d920b  89742404             mov dword ptr [esp + 4], esi
// 004d920f  8b4618               mov eax, dword ptr [esi + 0x18]
// 004d9212  8b0e                 mov ecx, dword ptr [esi]
// 004d9214  8b10                 mov edx, dword ptr [eax]
// 004d9216  50                   push eax
// 004d9217  51                   push ecx
// 004d9218  52                   push edx
// 004d9219  51                   push ecx
// 004d921a  8d442418             lea eax, [esp + 0x18]
// 004d921e  50                   push eax
// 004d921f  8bce                 mov ecx, esi
// 004d9221  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 004d9229  e8e2feffff           call 0x4d9110
// 004d922e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004d9231  51                   push ecx
// 004d9232  e8fbf72300           call 0x718a32
// 004d9237  8b16                 mov edx, dword ptr [esi]
// 004d9239  52                   push edx
// 004d923a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 004d9241  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 004d9248  e8e5f72300           call 0x718a32
// 004d924d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004d9251  83c408               add esp, 8
// 004d9254  5e                   pop esi
// 004d9255  64890d00000000       mov dword ptr fs:[0], ecx
// 004d925c  83c418               add esp, 0x18
// 004d925f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
