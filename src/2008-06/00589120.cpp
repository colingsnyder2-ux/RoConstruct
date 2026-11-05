// from server: 100% by auto
// roc 2008-06 00589120  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00589120
//
// 00589120  6aff                 push -1
// 00589122  6828d97b00           push 0x7bd928
// 00589127  64a100000000         mov eax, dword ptr fs:[0]
// 0058912d  50                   push eax
// 0058912e  64892500000000       mov dword ptr fs:[0], esp
// 00589135  83ec0c               sub esp, 0xc
// 00589138  56                   push esi
// 00589139  8bf1                 mov esi, ecx
// 0058913b  89742404             mov dword ptr [esp + 4], esi
// 0058913f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00589142  8b0e                 mov ecx, dword ptr [esi]
// 00589144  8b10                 mov edx, dword ptr [eax]
// 00589146  50                   push eax
// 00589147  51                   push ecx
// 00589148  52                   push edx
// 00589149  51                   push ecx
// 0058914a  8d442418             lea eax, [esp + 0x18]
// 0058914e  50                   push eax
// 0058914f  8bce                 mov ecx, esi
// 00589151  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 00589159  e8b2faffff           call 0x588c10
// 0058915e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00589161  51                   push ecx
// 00589162  e813751100           call 0x6a067a
// 00589167  8b16                 mov edx, dword ptr [esi]
// 00589169  52                   push edx
// 0058916a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00589171  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00589178  e8fd741100           call 0x6a067a
// 0058917d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00589181  83c408               add esp, 8
// 00589184  5e                   pop esi
// 00589185  64890d00000000       mov dword ptr fs:[0], ecx
// 0058918c  83c418               add esp, 0x18
// 0058918f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
